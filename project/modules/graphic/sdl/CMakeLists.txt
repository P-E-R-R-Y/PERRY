#Abstract-Sdl3

cmake_minimum_required(VERSION 3.24)
project(sdlgraphic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_OBJC_STANDARD_REQUIRED OFF)

#set(SDL_SHARED ON CACHE BOOL "" FORCE)

#find_package(SDL2 QUIET)
#if(NOT SDL2_FOUND)
include(FetchContent)
#  set(SDL_SHARED TRUE CACHE BOOL "Build a SDL shared library (if available)")
#  set(SDL_STATIC OFF CACHE BOOL "Build a SDL static library (if available)")
FetchContent_Declare(
        SDL
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.30.1
#          GIT_SHALLOW TRUE
#          GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL)
#endif()

#find_package(SDL2_IMAGE QUIET)
#if(NOT SDL2_IMAGE_FOUND)
include(FetchContent)
#  set(SDL_SHARED TRUE CACHE BOOL "Build a SDL shared library (if available)")
#  set(SDL_STATIC OFF CACHE BOOL "Build a SDL static library (if available)")
FetchContent_Declare(
        SDL2_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-2.8.2
#          GIT_SHALLOW TRUE
#          GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL2_image)
#endif()

set(SOURCE_FILES sdl.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE igraphic SDL2::SDL2 SDL2_image) #)#SDL2::SDL2main)

target_include_directories(${PROJECT_NAME} PUBLIC
  window
  graphic
  .
)