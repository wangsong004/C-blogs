# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(CBlogs)

# Set global properties for the solution, such as the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Traverse all folders in the `C-blogs` directory and add them as subprojects
file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_SOURCE_DIR} */)

foreach(SUBDIR ${SUBDIRECTORIES})
    # Check if the subdirectory contains a CMakeLists.txt file
    if(EXISTS "${CMAKE_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt")
        # Add the subdirectory as a project
        add_subdirectory(${SUBDIR})
    endif()
endforeach()

