add_library(src STATIC "")

target_sources(src
    PRIVATE
        charclass.cpp
        flyweightpxy.cpp
        theme.cpp
)