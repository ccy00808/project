cmake_minimum_required(VERSION 2.8)

project(timewheel)

add_executable(main "")
add_definitions(-std=c++11 -g)
include_directories(include)

target_sources(main
    PRIVATE
        main.cpp
)

add_subdirectory(src)

target_link_libraries(main
    PRIVATE
        timew
)