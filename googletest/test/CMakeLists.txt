add_executable(googletest test.cpp)

target_link_libraries(googletest
    PRIVATE
        gtest_main
        mockcpp
)

enable_testing()

add_test(
    NAME googletest
    COMMAND $<TARGET_FILE:googletest>
)