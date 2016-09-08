cmake_minimum_required(VERSION 3.3)
project(poj)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES AhoCorasickautomation.cpp)
add_executable(AhoCorasickautomation ${SOURCE_FILES})