#Abstract-Sdl3

cmake_minimum_required(VERSION 3.24)
project(sdlgraphic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        SDL
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.30.12
)
FetchContent_MakeAvailable(SDL)

include(FetchContent)
FetchContent_Declare(
        SDL2_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-2.8.4
)
FetchContent_MakeAvailable(SDL2_image)

#FetchContent_Declare(
#    Freetype
#    GIT_REPOSITORY https://gitlab.freedesktop.org/freetype/freetype.git
#    GIT_TAG VER-2-11-0
#)
#FetchContent_MakeAvailable(Freetype)

#if (Freetype_FOUND)
#    message(STATUS "Freetype found")
#    message(STATUS "Freetype include dir: ${FREETYPE_INCLUDE_DIRS}")
#    message(STATUS "Freetype library: ${FREETYPE_LIBRARIES}")
#else()
#    message(FATAL_ERROR "Freetype not found")
#endif()

#FetchContent_Declare(
#    SDL2_ttf
#    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
#    GIT_TAG release-2.24.0
#)
#FetchContent_MakeAvailable(SDL2_ttf)

FetchContent_Declare(
    SDL2_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG release-2.8.0
)
FetchContent_MakeAvailable(SDL2_mixer)

set(SOURCE_FILES sdl.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

if (APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            MACOSX_RPATH 1
            INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
            )
    set_target_properties(${PROJECT_NAME} PROPERTIES
            INSTALL_RPATH_USE_LINK_PATH TRUE
        )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE igraphic SDL2::SDL2 SDL2_image SDL2_mixer) #SDL2_ttf freetype)

target_include_directories(${PROJECT_NAME} PUBLIC
  window
  graphic
  event
  audio
  .
)
