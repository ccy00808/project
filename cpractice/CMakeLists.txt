cmake_minimum_required(VERSION 2.8)

project(cpractice)

add_executable(main "")

include_directories(include)
add_subdirectory(src)


add_definitions(-std=c++11)

target_sources(main
    PRIVATE
        main.cpp
)

target_link_libraries(main
    PRIVATE
        test
)