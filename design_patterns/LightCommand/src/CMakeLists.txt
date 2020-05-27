add_library(lightcmd STATIC "")

target_sources(lightcmd
    PRIVATE
        command.cpp
        invoker.cpp
        receiver.cpp
)