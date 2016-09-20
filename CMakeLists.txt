cmake_minimum_required(VERSION 3.6)
project(Assignment_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES GameOfLife.cpp GameOfLife.h main.cpp main.h)
add_executable(Assignment_2 ${SOURCE_FILES})