cmake_minimum_required(VERSION 3.16)

project(motorLib C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(bupt_can REQUIRED)
find_package(Threads REQUIRED)

# Define the motorLib library
add_library(motorLib
    src/dji_board.cpp
    src/vesc_board.cpp
)

target_include_directories(motorLib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(motorLib
    PRIVATE
        -O2
)

target_link_libraries(motorLib
    PRIVATE
        bupt_can
        Threads::Threads
)

# Define the examples
add_executable(djiBoard_example
    example/dji_board_example.cpp
)

add_executable(vescBoard_example
    example/vesc_board_example.cpp
)

target_link_libraries(djiBoard_example
    PRIVATE
        motorLib
)

target_link_libraries(vescBoard_example
    PRIVATE
        motorLib
)
