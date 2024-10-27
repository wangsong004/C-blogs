# Set the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(SetIntersectionExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable target
add_executable(SetIntersectionExample setIntersection.cpp)
