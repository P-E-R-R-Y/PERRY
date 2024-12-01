#Abstract-Raylib3

cmake_minimum_required(VERSION 3.24)
project(dynamiccore)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES snake.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} icore)

target_include_directories(${PROJECT_NAME} PUBLIC
  .
)