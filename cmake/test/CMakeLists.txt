add_executable(test "")

target_sources(test
    PRIVATE
        test.cpp
)

set_target_properties(test PROPERTIES VERSION 1.2 SOVERSION 1)

set_target_properties(test PROPERTIES OUTPUT_NAME "test1")

get_target_property(OUTPUT_VALUE test OUTPUT_NAME)

message(STATUS "this is val OUTPUT_NAME:"${OUTPUT_VALUE})

include_directories(../func)

target_link_libraries(test
    PRIVATE
        hello
        gtest_main
)

enable_testing()

add_test(
    NAME test
    COMMAND $<TARGET_FILE:test>
)

install(TARGETS test
    RUNTIME DESTINATION /usr
)