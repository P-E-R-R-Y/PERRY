cmake_minimum_required(VERSION 3.5...3.22)
project(app)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG 0.8.0 # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)
FetchContent_MakeAvailable(yaml-cpp)

#FetchContent_Declare(
#  pugixml
#  GIT_REPOSITORY http:://github.com/zeux/pugixml.git
#  GIT_TAG v1.14
#)
#FetchContent_MakeAvailable(pugixml)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)



set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC yaml-cpp::yaml-cpp nlohmann_json::nlohmann_json) # The library or executable that require yaml-cpp library
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)

