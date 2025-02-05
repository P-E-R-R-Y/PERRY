cmake_minimum_required(VERSION 3.10)
project(gen_test)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
