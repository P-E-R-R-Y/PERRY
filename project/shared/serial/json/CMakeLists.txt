cmake_minimum_required(VERSION 3.5...3.22)
project(jsonserial)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_OBJC_STANDARD_REQUIRED OFF)

# Dependencies
set(JSON_VERSION v3.11.3)

include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG ${JSON_VERSION}
)
FetchContent_MakeAvailable(json)

set(SOURCE_FILES json.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} iserial nlohmann_json::nlohmann_json) # The library or executable that require yaml-cpp library

target_include_directories(${PROJECT_NAME} PUBLIC .)
