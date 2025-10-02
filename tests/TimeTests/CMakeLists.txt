file(GLOB_RECURSE TESTS_FILES test_*.cpp)


include(GoogleTest)
foreach (TEST_FILE IN LISTS TESTS_FILES)
    get_filename_component(FILE_NAME ${TEST_FILE} NAME_WE)
    add_executable(${FILE_NAME} ${TEST_FILE})

    target_link_libraries(${FILE_NAME} PRIVATE ${PROJECT_NAME} GTest::gtest_main sofa)
    gtest_discover_tests(${FILE_NAME})
endforeach()
