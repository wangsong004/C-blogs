cmake_minimum_required(VERSION 3.0)
project(VariantExample)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable target
add_executable(VariantExample variant.cpp)

