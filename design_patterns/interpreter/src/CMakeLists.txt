add_library(context SHARED "")

target_sources(context
    PRIVATE
        context.cpp
        expression.cpp
)