#Abstract-Raylib3

cmake_minimum_required(VERSION 3.24)
project(raylib3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies
set (RAYLIB_VERSION 5.0)

find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib #package name
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz #where
  )
  #prefer to use FetchContent_MakeAvailable instead of lowerLever customLogic like this FetchContent_GetProperties+FetchContent_Populate
  set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
  FetchContent_MakeAvailable(raylib)
endif()
#set shared_lib file


set(SOURCE_FILES raylib.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} igraphic3 raylib)

target_include_directories(${PROJECT_NAME} PUBLIC
  window
  graphic
  .
)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()