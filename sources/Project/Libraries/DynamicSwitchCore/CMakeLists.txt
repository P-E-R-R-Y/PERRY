#Abstract-Core

cmake_minimum_required(VERSION 3.14)
project(dynamicswitchcore)

set(CMAKE_CXX_STANDARD 20)

#set shared_lib file
set(RAYLIB3_SOURCE_FILES 
  raylib.cpp
)

add_library(${PROJECT_NAME} STATIC no_source.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC icore igraphic3)

target_include_directories(${PROJECT_NAME} PUBLIC
  .
)