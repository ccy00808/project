cmake_minimum_required(VERSION 2.8)

project(cmd)

add_executable(light "")

add_definitions(-std=c++11 -g)

include_directories(include)

add_subdirectory(src)

target_sources(light
    PRIVATE
        main.cpp
)

target_link_libraries(light
    PRIVATE
        lightcmd
)
