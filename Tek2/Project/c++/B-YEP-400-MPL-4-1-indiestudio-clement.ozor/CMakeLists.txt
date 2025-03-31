cmake_minimum_required(VERSION 3.17)

project(bomberman)

find_package(raylib REQUIRED)

include_directories(inc)

add_subdirectory(src)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} raylib)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/..")
