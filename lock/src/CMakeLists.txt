add_library(lock STATIC "")

target_sources(lock
    PRIVATE
        rwlock.cpp
)