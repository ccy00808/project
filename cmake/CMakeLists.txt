cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)

project(cmake)

add_subdirectory(func)
add_subdirectory(test)
add_subdirectory(third_party/googletest-release-1.10.0)