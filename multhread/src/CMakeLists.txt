add_library(multhread SHARED "")
target_sources(multhread
    PRIVATE
        multhread.cpp
        rwlock.cpp
)