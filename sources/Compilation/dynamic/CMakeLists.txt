cmake_minimum_required(VERSION 3.24)
project(app)

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

#Static
set(STATIC_LIB_SOURCE_FILES Static.cpp)
add_library(libraylib STATIC Static.CPP)

#Dynamic
set(DYNAMIC_LIB_SOURCE_FILES Dynamic.cpp)
add_library(libraylib SHARED)
sources/Project/Library/RaylibG3/raylib.cpp






#Project
set(SOURCE_FILES Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(GLBall mylib)
# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()