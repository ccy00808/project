cmake_minimum_required(VERSION 2.8)

project(googletest)

add_definitions(-std=c++11)

add_subdirectory(test)
add_subdirectory(thirdparty/googletest-release-1.10.0)

