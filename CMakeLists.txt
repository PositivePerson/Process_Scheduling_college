cmake_minimum_required(VERSION 3.24)
project(FCFS)

set(CMAKE_CXX_STANDARD 17)

add_executable(FCFS main.cpp Process.cpp Process.h generator.h fetchData.h)
