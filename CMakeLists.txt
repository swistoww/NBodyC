cmake_minimum_required(VERSION 3.5)
project(NBody)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c readData.c readData.h printData.c printData.h)
add_executable(NBody ${SOURCE_FILES})