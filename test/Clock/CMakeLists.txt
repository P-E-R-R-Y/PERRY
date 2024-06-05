#MAIN

cmake_minimum_required(VERSION 3.14)
project(app)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
  a.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})