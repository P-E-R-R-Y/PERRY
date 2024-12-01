#Abstract-Raylib3

cmake_minimum_required(VERSION 3.24)
project(raylibgraphic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES snake.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

#set(GLFW_USE_COCOA OFF)

target_link_libraries(${PROJECT_NAME} icore )

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