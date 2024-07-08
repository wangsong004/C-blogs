cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(OpenMPReduction VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenMP
find_package(OpenMP REQUIRED)

# Add the executable
add_executable(openmp_reduction openmp_reduction.cpp)

# Link OpenMP
target_link_libraries(openmp_reduction PUBLIC OpenMP::OpenMP_CXX)
