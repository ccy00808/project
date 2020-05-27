cmake_minimum_required(VERSION 2.8)

project(flyweight)

add_definitions(-std=c++11)

add_executable(main "")

include_directories(include)

add_subdirectory(src)

target_sources(main
    PRIVATE
        main.cpp
)

target_link_libraries(main
    PRIVATE
        src
)