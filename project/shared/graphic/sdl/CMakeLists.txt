#Abstract-Sdl3

cmake_minimum_required(VERSION 3.24)
project(sdlgraphic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        SDL
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.30.12
)
FetchContent_MakeAvailable(SDL)

FetchContent_Declare(
    SDL2_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG release-2.24.0
)
FetchContent_MakeAvailable(SDL2_ttf)


include(FetchContent)
FetchContent_Declare(
        SDL2_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-2.8.4
)
FetchContent_MakeAvailable(SDL2_image)


FetchContent_Declare(
    SDL2_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG release-2.8.0
)
FetchContent_MakeAvailable(SDL2_mixer)

set(SOURCE_FILES sdl.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE igraphic SDL2::SDL2 SDL2_ttf SDL2_image SDL2_mixer)

target_include_directories(${PROJECT_NAME} PUBLIC
  window
  graphic
  event
  audio
  .
)
