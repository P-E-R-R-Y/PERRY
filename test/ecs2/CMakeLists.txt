cmake_minimum_required(VERSION 3.10)
project(app)

## ----------- CMAKE -----------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## ----------- Executable -----------
set(SOURCE_FILES
  main.cpp

)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

## ----------- Include -----------
target_include_directories(${PROJECT_NAME} PUBLIC
  .
)

## ----------- Compile Options -----------
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
