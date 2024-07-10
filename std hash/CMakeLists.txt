cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HashExample)

# Add an executable
add_executable(HashExample hash_example.cpp)

# Set the C++ standard
set_target_properties(HashExample PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
