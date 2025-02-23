#Abstract-Sfml3

cmake_minimum_required(VERSION 3.10)
project(sfmlgraphic)

set(CMAKE_CXX_STANDARD 17)

set(SFML_VERSION "2.6.1")

#FetchContent_GetProperties(sfml)
#if(NOT sfml_POPULATED)
#    FetchContent_Populate(sfml)
#    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
#endif()

include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)
FetchContent_MakeAvailable(sfml)

set(SOURCE_FILES sfml.cpp)

add_compile_definitions(_HAS_AUTO_PTR_ETC=1)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} igraphic 
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio)

target_include_directories(${PROJECT_NAME} PUBLIC
  window
  graphic
  event
  audio
  .
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)