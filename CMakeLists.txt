cmake_minimum_required(VERSION 3.20)
project(AstrolLib)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_TESTS_ASTROLIB OFF)

add_subdirectory(src)

if(${BUILD_TESTS_ASTROLIB})
    enable_testing()
    add_subdirectory(tests) 
endif()