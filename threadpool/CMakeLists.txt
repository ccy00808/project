cmake_minimum_required(VERSION 3.10)
project(threadpool)

add_definitions(-std=c++11 -g)

include_directories(include)

add_subdirectory(src)