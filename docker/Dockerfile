FROM osrf/ros:jazzy-desktop

# Install packages
RUN apt-get update && apt-get install -y --no-install-recommends \
    python3-colcon-common-extensions \
    ros-jazzy-usb-cam \
    ros-jazzy-apriltag-ros \
    ros-jazzy-image-tools \
    ros-jazzy-xacro \
    ros-jazzy-camera-calibration \
    ros-jazzy-tf2-ros \
    ros-jazzy-tf-transformations \
    sudo \
    && rm -rf /var/lib/apt/lists/*

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

# Setup user environment
USER $USERNAME
WORKDIR /home/$USERNAME/ros2_ws
ENV HOME=/home/$USERNAME

# Create a setup script to automatically source ROS and workspace on entry
RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
RUN echo "if [ -f /home/$USERNAME/ros2_ws/install/setup.bash ]; then source /home/$USERNAME/ros2_ws/install/setup.bash; fi" >> ~/.bashrc

CMD ["bash"]
