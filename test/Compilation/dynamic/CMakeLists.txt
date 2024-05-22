cmake_minimum_required(VERSION 3.24)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(BUILD_PATH ../)

# Dependencies
#set (RAYLIB_VERSION 5.0)
#
#find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
#if (NOT raylib_FOUND) # If there's none, fetch and build raylib
#  include(FetchContent)
#  FetchContent_Declare(
#    raylib #package name
#    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz #where
#  )
#  #prefer to use FetchContent_MakeAvailable instead of lowerLever customLogic like this FetchContent_GetProperties+FetchContent_Populate
#  set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
#  FetchContent_MakeAvailable(raylib)
#endif()

#Static
SET(STATIC_NAME static)
set(STATIC_LIB_SOURCE static/Static.cpp)
set(STATIC_LIB_INCLUDE_DIR static/)
add_library(${STATIC_NAME} STATIC ${STATIC_LIB_SOURCE})
target_include_directories(${STATIC_NAME} PUBLIC ${STATIC_LIB_INCLUDE_DIR})

#Dynamic
SET(DYNAMIC_NAME dynamic)
set(DYNAMIC_LIB_SOURCE dynamic/Dynamic.cpp)
set(DYNAMIC_LIB_INCLUDE_DIR dynamic/)
add_library(${DYNAMIC_NAME} SHARED ${DYNAMIC_LIB_SOURCE})
target_link_libraries(${DYNAMIC_NAME} PUBLIC ${STATIC_NAME})

#Project
set(SOURCE_FILES Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${STATIC_NAME})
#target_link_libraries(${PROJECT_NAME} PUBLIC ${STATIC_NAME}) #static uses

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
#if (APPLE)
#  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
#  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
#  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
#endif()