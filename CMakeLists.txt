cmake_minimum_required(VERSION 2.8)

project(circle_queue)

set(circle_queue_src main.cpp circle_queue.cpp AutoTest.cpp)
set(circle_queue_hdr head.hpp circle_queue.hpp AutoTest.hpp)

add_executable(${PROJECT_NAME} ${circle_queue_src} ${circle_queue_hdr})