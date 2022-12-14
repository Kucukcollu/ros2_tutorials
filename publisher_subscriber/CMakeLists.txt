cmake_minimum_required(VERSION 3.5)
project(publisher_subscriber)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

set(dependencies
  rclcpp
  rclpy
  std_msgs
)

# talker
add_executable(talker src/publisher.cpp)
ament_target_dependencies(talker ${dependencies})

# listener
add_executable(listener src/subscriber.cpp)
ament_target_dependencies(listener ${dependencies})

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

ament_package()
