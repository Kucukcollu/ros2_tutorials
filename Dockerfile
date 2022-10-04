FROM ros:foxy-ros-base

LABEL project="ROS2 Foxy Docker for learning ROS2"
LABEL version="0.0.1"
LABEL maintainer="Ali Aydin Kucukcollu <kucukcollu@outlook.com>"

ENV NVIDIA_VISIBLE_DEVICES \
    ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES \
    ${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

# update and upgrade container
RUN apt-get update && \
    apt-get upgrade -y

# install ubuntu depends
RUN apt-get update -y && \
    apt-get install \
    openssh-server \
    openssh-client \
    htop \
    tmux \
    nano \
    vim \
    wget \
    unzip -y && \
    rm -rf /var/lib/apt/lists/*

# install ROS depends
RUN apt-get update && \
    apt-get install -y \
    ros-foxy-rviz2

RUN mkdir -p /root/catkin_ws/src && \
    cd /root/catkin_ws && \
    colcon build

WORKDIR /root/root/catkin_ws