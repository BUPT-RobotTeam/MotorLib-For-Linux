cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_C_COMPILER "/usr/bin/gcc")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(motorLib C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2")

add_subdirectory(third_party/bupt_can_node)
include_directories(third_party/bupt_can_node/inc)
include_directories(inc)

set(
    MOTOR_LIB_SRC
    src/dji_board.cpp
)

set(
    MOTOR_LIB_INC
    inc/dji_board.h
)

set(
    MOTOR_LIB_EXAMPLE
    example/dji_board_example.cpp
)

add_library(motorLib STATIC ${MOTOR_LIB_SRC} ${MOTOR_LIB_INC})
target_link_libraries(motorLib bupt_can)

add_executable(motorLibExample ${MOTOR_LIB_EXAMPLE})
target_link_libraries(motorLibExample motorLib)
