#Abstract-Core

cmake_minimum_required(VERSION 3.14)
project(dynamicswitchengine)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC no_source.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC dynamiccore)

target_include_directories(${PROJECT_NAME} PUBLIC
  .
)