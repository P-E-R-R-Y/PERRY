cmake_minimum_required(VERSION 3.17)

project(rayperry VERSION 1.0.1 DESCRIPTION "mylib description")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 3.17)
set(${CMAKE_BINARY_DIR} build/)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_BUILD_TYPE Release)

#

find_package(raylib 4.0 QUIET)

if (NOT raylib_FOUND)
  INCLUDE(FetchContent)

  FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    SET(raylib_FOUND TRUE)
  endif()
endif()

#

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

#

add_library(rayperry SHARED)

target_link_libraries(${PROJECT_NAME} raylib)

#

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/rayperry
        DESTINATION bin
        RENAME ${CMAKE_PROJECT_NAME}-rayperry)