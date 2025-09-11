cmake_minimum_required(VERSION 3.20)
project(AstrolLib)

option(BUILD_TESTS_ASTROLIB OFF)

add_subdirectory(src)

if(${BUILD_TESTS_ASTROLIB})
    add_subdirectory(tests) 
endif()