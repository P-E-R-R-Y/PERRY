cmake_minimum_required(VERSION 3.14)
project(gen_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
  main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
