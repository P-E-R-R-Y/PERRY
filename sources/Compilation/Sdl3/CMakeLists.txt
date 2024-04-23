cmake_minimum_required(VERSION 3.24)
project(app)

set(CMAKE_CXX_STANDARD 17)

#set(SDL_VERSION "2.30.2")

find_package(SDL3 QUIET)
if(NOT SDL3_FOUND)
        include(FetchContent)
        FetchContent_Declare(
                SDL
                GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
                GIT_TAG prerelease-3.1.1
        #        GIT_SHALLOW TRUE
        #        GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable(SDL)
endif()

set(SOURCE_FILES Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL3::SDL3)
#target_compile_options(${PROJECT_NAME} -Wall)
