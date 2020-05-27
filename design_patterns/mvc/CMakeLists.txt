cmake_minimum_required(VERSION 2.8)

project(mvc)

add_executable(main "")

include_directories(include)

target_sources(main
    PRIVATE
        main.cpp
)

add_subdirectory(src)

target_link_libraries(main
    PRIVATE
        srcpp
)