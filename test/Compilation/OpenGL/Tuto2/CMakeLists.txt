
cmake_minimum_required(VERSION 3.16)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(BUILD_UTILS ON)
#set(CMAKE_INSTALL_PREFIX ON)

#if(WIN32)
#    set(GUI_TYPE WIN32)
#elseif(APPLE)
#    set(GUI_TYPE MACOSX_BUNDLE)
#else()
#    set(GUI_TYPE)
#endif()

include(FetchContent)

#findpackage or fetch
find_package(GLEW 2.0 REQUIRED)
find_package(glm REQUIRED)

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

set(glm_DIR <installation prefix>/lib/cmake/glm) # if necessary
find_package(glm REQUIRED)

file(COPY SimpleVertexShader.vertexshader DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY SimpleFragmentShader.fragmentshader DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


set(SOURCE_FILES Tuto2.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC GLEW::GLEW glfw glm::glm)

if(APPLE)
target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
endif()

