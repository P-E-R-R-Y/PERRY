
cmake_minimum_required(VERSION 3.14)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

if(WIN32)
    set(GUI_TYPE WIN32)
elseif(APPLE)
    set(GUI_TYPE MACOSX_BUNDLE)
else()
    set(GUI_TYPE)
endif()

include(FetchContent)

#findpackage or fetch
find_package(GLEW 2.0 REQUIRED)
#FetchContent_Declare(
#  glew
#  GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
#  GIT_TAG        origin/master
#)
#FetchContent_MakeAvailable(glew)

set(GLFW_VERSION "3.4")
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        "${GLFW_VERSION}"
    )
FetchContent_MakeAvailable(glfw)

set(SOURCE_FILES Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC GLEW::GLEW glfw OpenGL::GL)  #${GLFW3_LIBRARY})

if(APPLE)
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
endif()
