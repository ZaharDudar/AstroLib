add_library(${PROJECT_NAME} INTERFACE)
message("Astrolib include dir " ${PROJECT_NAME} " " ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})