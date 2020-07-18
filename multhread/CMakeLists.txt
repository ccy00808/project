cmake_minimum_required(VERSION 2.8)

project(main)

add_executable(main "")
add_definitions(-std=c++11 -g)
include_directories(include)
add_subdirectory(src)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

target_sources(main
    PRIVATE
        main.cpp
)

target_link_libraries(main
    PRIVATE
        multhread
)