#Abstract-Raylib3

cmake_minimum_required(VERSION 3.24)
project(glutgraphic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_OBJC_STANDARD_REQUIRED OFF)

# Dependencies
set (GLUT_VERSION 5.0)

find_package(glut ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT glut_FOUND) # If there's none, fetch and build raylib
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

#set(GLFW_USE_COCOA OFF)

target_link_libraries(${PROJECT_NAME} igraphic raylib)

target_include_directories(${PROJECT_NAME} PUBLIC
  window
  graphic
  event
  .
)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()