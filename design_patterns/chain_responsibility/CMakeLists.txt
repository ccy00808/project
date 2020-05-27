cmake_minimum_required(VERSION 2.8)

project(chain)

add_executable(chain "")

add_definitions(-std=c++11 -g)
include_directories(include)

add_subdirectory(src)

target_sources(chain
    PRIVATE
        main.cpp
)

target_link_libraries(chain
    PRIVATE
        handler
)