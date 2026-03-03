#include <functional>
#include <memory>
#include <thread>
#include <string>
#include <map>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "uarm_interfaces/action/pick_and_place.hpp"
#include "uarm_interfaces/action/drive_to_pose.hpp"

#include "swiftpro/msg/position.hpp"
#include "swiftpro/msg/status.hpp"
#include "swiftpro/msg/swiftpro_state.hpp"

using namespace std::placeholders;

struct Pose {
  double x;
  double y;
  double z;
};

class ArmControllerNode : public rclcpp::Node
{
public:
  using PickAndPlace = uarm_interfaces::action::PickAndPlace;
  using GoalHandlePickAndPlace = rclcpp_action::ServerGoalHandle<PickAndPlace>;

  using DriveToPose = uarm_interfaces::action::DriveToPose;
  using GoalHandleDriveToPose = rclcpp_action::ServerGoalHandle<DriveToPose>;

  ArmControllerNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions().allow_undeclared_parameters(true).automatically_declare_parameters_from_overrides(true))
  : Node("arm_controller_node", options)
  {
    // Because we automatically declared parameters from overrides, 
    // we must check if they exist before declaring default values.
    if (!this->has_parameter("hover_z_offset")) {
      this->declare_parameter<double>("hover_z_offset", 10.0);
    }
    if (!this->has_parameter("target_z_base")) {
      this->declare_parameter<double>("target_z_base", 0.0);
    }

    // Print all parameters to see what is actually getting loaded
    auto all_params = this->list_parameters({}, 10).names;
    for (const auto & name : all_params) {
      RCLCPP_INFO(this->get_logger(), "Found parameter: %s", name.c_str());
    }

    // Load poses from params dynamically
    auto param_names = this->list_parameters({"poses"}, 10).names;
    for (const auto & name : param_names) {
      if (name.find(".x") != std::string::npos) {
        std::string pose_name = name.substr(6, name.find(".x") - 6);
        if (poses_.find(pose_name) == poses_.end()) {
          if (!this->has_parameter("poses." + pose_name + ".x")) {
            this->declare_parameter<double>("poses." + pose_name + ".x", 150.0);
          }
          if (!this->has_parameter("poses." + pose_name + ".y")) {
            this->declare_parameter<double>("poses." + pose_name + ".y", 0.0);
          }
          if (!this->has_parameter("poses." + pose_name + ".z")) {
            this->declare_parameter<double>("poses." + pose_name + ".z", 50.0);
          }

          auto get_as_double = [this](const std::string& name) -> double {
            auto param = this->get_parameter(name);
            if (param.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER) {
              return static_cast<double>(param.as_int());
            } else {
              return param.as_double();
            }
          };

          Pose p;
          p.x = get_as_double("poses." + pose_name + ".x");
          p.y = get_as_double("poses." + pose_name + ".y");
          p.z = get_as_double("poses." + pose_name + ".z");
          poses_[pose_name] = p;
          RCLCPP_INFO(this->get_logger(), "Loaded pose '%s': X=%.1f, Y=%.1f, Z=%.1f", pose_name.c_str(), p.x, p.y, p.z);
        }
      }
    }

    // Publishers
    pos_pub_ = this->create_publisher<swiftpro::msg::Position>("/position_write_topic", 10);
    pump_pub_ = this->create_publisher<swiftpro::msg::Status>("/pump_topic", 10);

    // Subscriber
    state_sub_ = this->create_subscription<swiftpro::msg::SwiftproState>(
      "/SwiftproState_topic", 10, std::bind(&ArmControllerNode::state_callback, this, _1));

    // Action Servers
    action_server_pick_place_ = rclcpp_action::create_server<PickAndPlace>(
      this,
      "pick_and_place",
      std::bind(&ArmControllerNode::handle_goal_pick_place, this, _1, _2),
      std::bind(&ArmControllerNode::handle_cancel_pick_place, this, _1),
      std::bind(&ArmControllerNode::handle_accepted_pick_place, this, _1));

    action_server_drive_pose_ = rclcpp_action::create_server<DriveToPose>(
      this,
      "drive_to_pose",
      std::bind(&ArmControllerNode::handle_goal_drive_pose, this, _1, _2),
      std::bind(&ArmControllerNode::handle_cancel_drive_pose, this, _1),
      std::bind(&ArmControllerNode::handle_accepted_drive_pose, this, _1));

    RCLCPP_INFO(this->get_logger(), "Arm Controller Node started");
  }

private:
  // State variables
  uint8_t limit_switch_ = 0;
  double current_z_ = 150.0;
  std::map<std::string, Pose> poses_;

  // ROS 2 components
  rclcpp::Publisher<swiftpro::msg::Position>::SharedPtr pos_pub_;
  rclcpp::Publisher<swiftpro::msg::Status>::SharedPtr pump_pub_;
  rclcpp::Subscription<swiftpro::msg::SwiftproState>::SharedPtr state_sub_;

  rclcpp_action::Server<PickAndPlace>::SharedPtr action_server_pick_place_;
  rclcpp_action::Server<DriveToPose>::SharedPtr action_server_drive_pose_;

  void state_callback(const swiftpro::msg::SwiftproState::SharedPtr msg)
  {
    limit_switch_ = msg->limit_switch;
    current_z_ = msg->z;
  }

  void move_arm(double x, double y, double z)
  {
    auto msg = swiftpro::msg::Position();
    msg.x = x;
    msg.y = y;
    msg.z = z;
    pos_pub_->publish(msg);
  }

  void set_pump(bool state)
  {
    auto msg = swiftpro::msg::Status();
    msg.status = state ? 1 : 0;
    pump_pub_->publish(msg);
  }

  // ============== DriveToPose Action ==============

  rclcpp_action::GoalResponse handle_goal_drive_pose(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const DriveToPose::Goal> goal)
  {
    (void)uuid;
    if (poses_.find(goal->pose_name) == poses_.end()) {
      RCLCPP_ERROR(this->get_logger(), "Goal rejected: Pose '%s' not found.", goal->pose_name.c_str());
      return rclcpp_action::GoalResponse::REJECT;
    }
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel_drive_pose(
    const std::shared_ptr<GoalHandleDriveToPose> goal_handle)
  {
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted_drive_pose(const std::shared_ptr<GoalHandleDriveToPose> goal_handle)
  {
    std::thread{std::bind(&ArmControllerNode::execute_drive_pose, this, _1), goal_handle}.detach();
  }

  void execute_drive_pose(const std::shared_ptr<GoalHandleDriveToPose> goal_handle)
  {
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<DriveToPose::Feedback>();
    auto result = std::make_shared<DriveToPose::Result>();

    Pose p = poses_[goal->pose_name];
    
    feedback->current_state = "Moving to " + goal->pose_name;
    goal_handle->publish_feedback(feedback);
    
    RCLCPP_INFO(this->get_logger(), "Moving to pose '%s': X=%.1f, Y=%.1f, Z=%.1f", goal->pose_name.c_str(), p.x, p.y, p.z);
    move_arm(p.x, p.y, p.z);
    
    // Wait for movement
    rclcpp::Rate rate(10);
    for (int i = 0; i < 20; ++i) { // Give it 2 seconds
      if (goal_handle->is_canceling()) {
        result->success = false;
        result->message = "Canceled";
        goal_handle->canceled(result);
        return;
      }
      rate.sleep();
    }

    result->success = true;
    result->message = "Successfully reached " + goal->pose_name;
    goal_handle->succeed(result);
  }

  // ============== PickAndPlace Action ==============

  rclcpp_action::GoalResponse handle_goal_pick_place(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const PickAndPlace::Goal> goal)
  {
    (void)uuid;
    (void)goal;
    // We could add safety checks for goal coordinates here
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel_pick_place(
    const std::shared_ptr<GoalHandlePickAndPlace> goal_handle)
  {
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted_pick_place(const std::shared_ptr<GoalHandlePickAndPlace> goal_handle)
  {
    std::thread{std::bind(&ArmControllerNode::execute_pick_place, this, _1), goal_handle}.detach();
  }

  void execute_pick_place(const std::shared_ptr<GoalHandlePickAndPlace> goal_handle)
  {
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<PickAndPlace::Feedback>();
    auto result = std::make_shared<PickAndPlace::Result>();

    double hover_z_offset = this->get_parameter("hover_z_offset").as_double();
    double target_z_base = this->get_parameter("target_z_base").as_double();
    rclcpp::Rate loop_rate(10); // 10 Hz

    auto publish_feedback = [&](const std::string& state) {
      feedback->current_state = state;
      goal_handle->publish_feedback(feedback);
      RCLCPP_INFO(this->get_logger(), "%s", state.c_str());
    };

    // 1. Move to Pick Hover
    publish_feedback("Moving to Pick Hover");
    double pick_hover_z = goal->pick_z + hover_z_offset;
    move_arm(goal->pick_x, goal->pick_y, pick_hover_z);
    for(int i=0; i<20; i++) { if(!rclcpp::ok() || goal_handle->is_canceling()) { cancel_goal(goal_handle, result); return; } loop_rate.sleep(); }

    // 2. Descend to Pick
    publish_feedback("Descending to Pick");
    double current_target_z = pick_hover_z;
    bool switch_triggered = false;
    while (rclcpp::ok()) {
      if (goal_handle->is_canceling()) { cancel_goal(goal_handle, result); return; }
      if (limit_switch_ == 1) {
        switch_triggered = true;
        break;
      }
      current_target_z -= 2.0;
      if (current_target_z < target_z_base) {
        break;
      }
      move_arm(goal->pick_x, goal->pick_y, current_target_z);
      loop_rate.sleep();
    }

    // 3. Pump ON
    publish_feedback("Activating Pump");
    set_pump(true);
    for(int i=0; i<10; i++) { if(!rclcpp::ok() || goal_handle->is_canceling()) { set_pump(false); cancel_goal(goal_handle, result); return; } loop_rate.sleep(); }

    // 4. Move to Pick Hover
    publish_feedback("Retracting to Pick Hover");
    move_arm(goal->pick_x, goal->pick_y, pick_hover_z);
    for(int i=0; i<15; i++) { if(!rclcpp::ok() || goal_handle->is_canceling()) { set_pump(false); cancel_goal(goal_handle, result); return; } loop_rate.sleep(); }

    // 5. Move to Place Hover
    publish_feedback("Moving to Place Hover");
    double place_hover_z = goal->place_z + hover_z_offset;
    move_arm(goal->place_x, goal->place_y, place_hover_z);
    for(int i=0; i<20; i++) { if(!rclcpp::ok() || goal_handle->is_canceling()) { set_pump(false); cancel_goal(goal_handle, result); return; } loop_rate.sleep(); }

    // 6. Descend to Place
    publish_feedback("Descending to Place");
    current_target_z = place_hover_z;
    switch_triggered = false;
    while (rclcpp::ok()) {
      if (goal_handle->is_canceling()) { set_pump(false); cancel_goal(goal_handle, result); return; }
      if (limit_switch_ == 1) {
        switch_triggered = true;
        break;
      }
      current_target_z -= 2.0;
      if (current_target_z < target_z_base) {
        break;
      }
      move_arm(goal->place_x, goal->place_y, current_target_z);
      loop_rate.sleep();
    }

    // 7. Pump OFF
    publish_feedback("Deactivating Pump");
    set_pump(false);
    for(int i=0; i<10; i++) { if(!rclcpp::ok() || goal_handle->is_canceling()) { cancel_goal(goal_handle, result); return; } loop_rate.sleep(); }

    // 8. Move to Place Hover
    publish_feedback("Retracting to Place Hover");
    move_arm(goal->place_x, goal->place_y, place_hover_z);
    for(int i=0; i<15; i++) { if(!rclcpp::ok() || goal_handle->is_canceling()) { cancel_goal(goal_handle, result); return; } loop_rate.sleep(); }

    result->success = true;
    result->message = "Pick and Place Completed";
    goal_handle->succeed(result);
  }

  void cancel_goal(const std::shared_ptr<GoalHandlePickAndPlace> goal_handle, std::shared_ptr<PickAndPlace::Result> result) {
    result->success = false;
    result->message = "Action Canceled";
    goal_handle->canceled(result);
  }

};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ArmControllerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
