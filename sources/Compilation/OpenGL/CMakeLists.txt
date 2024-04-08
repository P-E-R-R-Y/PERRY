
cmake_minimum_required(VERSION 3.14)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)

#findpackage or fetch
FetchContent_Declare(
  glew
  GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
  GIT_TAG        origin/master
)
FetchContent_MakeAvailable(glew)

FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        origin/master
    )
FetchContent_MakeAvailable(glfw)

set(SOURCE_FILES Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} glfw glew)

if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
  target_link_libraries(${PROJECT_NAME} "-framework GLUT")
  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${PROJECT_NAME} "-framework CoreVideo")
endif()