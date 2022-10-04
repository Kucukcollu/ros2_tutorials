## ros2_tutorials

#### Cheatsheet of ROS2 Foxy

```bash
# source ROS Foxy
$ source /opt/ros/foxy/setup.bash

# create workspace
$ mkdir -p ~/ros2_ws/src

# install workspace deps
$ rosdep install --from-paths src --ignore-src -r -y

# learn ros2 keywords
$ ros2
...
...

# create package
# option 1
$ ros2 pkg create publisher_subscriber --dependencies rclcpp rclpy std_msgs

# option 2
$ ros2 pkg create --build-type ament_cmake srv_server_client --dependencies rclcpp rclpy std_msgs

# option 3
$ ros2 pkg create --build-type ament_cmake --node-name action_node action_server_client --dependencies rclcpp rclpy std_msgs

# Build package or packages

# build workspace
$ colcon build

# build a specific package in the workspace
$ colcon build --packages-select <package_name>

# to clean workspace
$ cd ~/ros2_ws

# delete these 3 folders and build again 
$ rm -rf build/ log/ install/ && colcon build


```
