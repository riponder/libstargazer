cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
rosbuild_init()

rosbuild_add_library(StarGazer StarGazer.cpp serial_port.cpp )
rosbuild_add_executable(learn_stargazer_map learn_stargazer_map.cpp)

target_link_libraries(learn_stargazer_map StarGazer serial)
rosbuild_link_boost(learn_stargazer_map program_options)