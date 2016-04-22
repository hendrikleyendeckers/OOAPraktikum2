cmake_minimum_required(VERSION 3.5)
project(OOAPraktikum2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PriorityQueue.h QueueException.h)
add_executable(OOAPraktikum2 ${SOURCE_FILES})