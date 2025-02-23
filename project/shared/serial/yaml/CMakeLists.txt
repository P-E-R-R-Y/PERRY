cmake_minimum_required(VERSION 3.5...3.22)
project(yamlserial)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_OBJC_STANDARD_REQUIRED OFF)

# Dependencies
set(YAML_VERSION 0.8.0)

include(FetchContent)
FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG ${YAML_VERSION} # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)
FetchContent_MakeAvailable(yaml-cpp)

set(SOURCE_FILES yaml.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} iserial yaml-cpp::yaml-cpp) # The library require iserial and yaml-cpp library

target_include_directories(${PROJECT_NAME} PUBLIC .)