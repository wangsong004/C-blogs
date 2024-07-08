cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(BindExample)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加源文件到可执行目标
add_executable(BindExample bind.cpp)
