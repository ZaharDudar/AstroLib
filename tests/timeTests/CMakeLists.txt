add_executable( time_tests
                operands.cpp)

target_link_libraries(time_tests PRIVATE AstroLib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(time_tests)
add_test(NAME TimeTest COMMAND time_tests)