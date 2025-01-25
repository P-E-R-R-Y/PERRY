cmake_minimum_required(VERSION 3.10)
project(app)

## ----------- CMAKE -----------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## ----------- Executable -----------
set(SOURCE_FILES
  main.cpp
)

## ----------- Subdirectory CMake -----------
add_subdirectory(ecs)

## ----------- Executable -----------
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

## ----------- Library -----------
target_link_libraries(${PROJECT_NAME} PUBLIC ecs)

## ----------- Include -----------
target_include_directories(${PROJECT_NAME} PUBLIC
  include
)

## ----------- Compile Options -----------
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
