cmake_minimum_required(VERSION 3.5...3.22)
project(lpi)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC .)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
