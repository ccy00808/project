cmake_minimum_required(VERSION 2.8)

project(interpreter)

add_executable(main "")

include_directories(include)

add_definitions(-std=c++11 -g)

add_subdirectory(src)

target_sources(main
    PRIVATE
        main.cpp
)

target_link_libraries(main
    PRIVATE
        context
)