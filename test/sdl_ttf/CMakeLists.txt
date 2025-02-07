cmake_minimum_required(VERSION 3.14) 
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
  main.cpp
)

add_subdirectory(graphic)
add_subdirectory(shared)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
  igraphic
  sharedsdl
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ./
)

## ----------- Copy Assets -----------
if (EXISTS ${CMAKE_SOURCE_DIR}/assets)
  message("Copying assets")
  file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) 
endif()
