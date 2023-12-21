cmake_minimum_required(VERSION 3.10)
project(Simulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(Simulation
    src/main.cpp
    src/universe/universe.cpp
    src/visualizer/visualizer.cpp
    # Add other source files if any
)

target_include_directories(Simulation PRIVATE src)
