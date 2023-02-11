cmake_minimum_required(VERSION 3.24)
project(parellele)

set(CMAKE_CXX_STANDARD 17)

add_executable(parellele OmpTrace.cpp)
