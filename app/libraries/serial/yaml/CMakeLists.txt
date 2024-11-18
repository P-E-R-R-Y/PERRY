#Abstract-Raylib3

cmake_minimum_required(VERSION 3.5...3.22)
project(yamlserial)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_OBJC_STANDARD_REQUIRED OFF)

# Dependencies
set (YAML_VERSION 0.8.0)

include(FetchContent)
FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG ${YAML_VERSION} # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)

#set shared_lib file

set(SOURCE_FILES raylib.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

#set(GLFW_USE_COCOA OFF)

target_link_libraries(${PROJECT_NAME} igraphic raylib)

target_include_directories(${PROJECT_NAME} PUBLIC
  window
  graphic
  event
  .
)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()


FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG 0.8.0 # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)
FetchContent_MakeAvailable(yaml-cpp)

set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC yaml-cpp::yaml-cpp) # The library or executable that require yaml-cpp library
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)


