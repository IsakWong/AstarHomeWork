cmake_minimum_required(VERSION 3.8)
project(AstarHomeWork)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AstarMap.h AstarMap.cpp Astar.h Astar.cpp )
add_executable(AstarHomeWork ${SOURCE_FILES})