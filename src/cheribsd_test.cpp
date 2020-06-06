// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// This is a very simple test to demonstrate that ros2 can build and run on CheriBSD

#include <memory>
#include "minimal_composition/publisher_node.hpp"
#include "minimal_composition/subscriber_node.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  std::cout << "TEST START" << std::endl;
  rclcpp::init(argc, argv);
  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  /* shared pointers appear to be creating a problem with jemalloc when they
  are cleaned up at the rclcpp: shutdown() call or at the end of the function.

  leave them out for now, as simply running rclcpp::init() is a sufficient
  initial test that the ROS2 libraries compiled and an application will run */

  auto publisher_node = std::make_shared<PublisherNode>();
  // auto subscriber_node = std::make_shared<SubscriberNode>(options);
  // exec.add_node(publisher_node);
  // exec.add_node(subscriber_node);
  // for (int i = 0; i < 20; ++i) {
  //   exec.spin_once();
  // }

  rclcpp::shutdown();
  std::cout << "TEST COMPLETE" << std::endl;
  return 0;
}