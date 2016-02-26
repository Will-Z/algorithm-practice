cmake_minimum_required(VERSION 3.3)
project(data_structure_prac)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  dijkstra.cpp)
add_executable(data_structure_prac ${SOURCE_FILES})