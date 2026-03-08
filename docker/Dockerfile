FROM osrf/ros:jazzy-desktop

# Install packages
RUN apt-get update && apt-get install -y --no-install-recommends \
  python3-colcon-common-extensions \
  python3-pip \
  ros-jazzy-usb-cam \
  ros-jazzy-apriltag-ros \
  ros-jazzy-image-tools \
  ros-jazzy-xacro \
  ros-jazzy-camera-calibration \
  ros-jazzy-realsense2-camera \
  ros-jazzy-tf2-ros \
  ros-jazzy-tf-transformations \
  ros-jazzy-vision-msgs \
  sudo \
  && rm -rf /var/lib/apt/lists/*

# Install rosbags for ROS1 Bag support and pupil-apriltags for Vision Tracking
RUN pip3 install --no-cache-dir \
  rosbags \
  pupil-apriltags \
  --break-system-packages

# Add a non-root user matching host's typical UID (pi/ros2 usually 1000)
ARG USERNAME=ros2
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN if getent group $USER_GID ; then \
  groupmod -n $USERNAME $(getent group $USER_GID | cut -d: -f1) ; \
  else \
  groupadd --gid $USER_GID $USERNAME ; \
  fi \
  && if getent passwd $USER_UID ; then \
  usermod -l $USERNAME -d /home/$USERNAME -m $(getent passwd $USER_UID | cut -d: -f1) ; \
  else \
  useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME ; \
  fi \
  && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
  && chmod 0440 /etc/sudoers.d/$USERNAME

# Add user to video and dialout groups for Camera & uArm access
RUN usermod -aG video,dialout $USERNAME

# Setup Entrypoint
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Setup user environment
USER $USERNAME
WORKDIR /home/$USERNAME/ros2_ws
ENV HOME=/home/$USERNAME

ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]
