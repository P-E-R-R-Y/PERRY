cmake_minimum_required(VERSION 3.24)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(OpenGL REQUIRED)
#find_package(GLEW 2.0 REQUIRED)
find_package(GLUT REQUIRED)

include(FetchContent)

set(GLFW_VERSION "3.4")
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        "${GLFW_VERSION}"
    )
FetchContent_MakeAvailable(glfw)

set(SOURCE_FILES Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC GLUT::GLUT glfw)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework CoreVideo")
endif()
