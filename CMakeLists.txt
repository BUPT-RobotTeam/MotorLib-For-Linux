cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_C_COMPILER "/usr/bin/gcc")

project(motorLib C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")

add_subdirectory(third_party/bupt_can_node)
include_directories(third_party/bupt_can_node/inc)
include_directories(inc)

set(
    MOTOR_LIB_SRC
    src/dji_driver.cpp
)

set(
    MOTOR_LIB_INC
    inc/dji_driver.h
)
