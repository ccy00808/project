add_library(multhread SHARED "")
add_definitions(-g)
target_sources(multhread
    PRIVATE
        multhread.cpp
        rwlock.cpp
)