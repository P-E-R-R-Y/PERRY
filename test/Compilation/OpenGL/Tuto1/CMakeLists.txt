
cmake_minimum_required(VERSION 3.16)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

#findpackage or fetch
find_package(GLEW 2.0 REQUIRED)

#set(GLEW_VERSION 2.2.0)
#FetchContent_Declare(
#  glew
#  GIT_REPOSITORY https://github.com/Perlmint/glew-cmake
#  GIT_TAG        "glew-${GLEW_VERSION}"
#)
#FetchContent_MakeAvailable(glew)

set(GLFW_VERSION "3.4")
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        "${GLFW_VERSION}"
    )
FetchContent_MakeAvailable(glfw)

set(SOURCE_FILES Tuto1.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC GLEW::GLEW glfw)

if(APPLE)
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
endif()

