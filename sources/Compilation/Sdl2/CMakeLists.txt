cmake_minimum_required(VERSION 3.24)
project(app)

set(CMAKE_CXX_STANDARD 17)

#set(SDL_VERSION "2.30.2")

find_package(SDL2 QUIET)
if(NOT SDL2_FOUND)
        include(FetchContent)
        FetchContent_Declare(
                SDL
                GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
                GIT_TAG release-2.30.1
        #        GIT_SHALLOW TRUE
        #        GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable(SDL)
endif()

set(SOURCE_FILES Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
#target_compile_options(${PROJECT_NAME} -Wall)
