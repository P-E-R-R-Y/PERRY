cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 17)

set(SFML_VERSION "2.6.1")

include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)

FetchContent_MakeAvailable(sfml)

#FetchContent_GetProperties(sfml)
#if(NOT sfml_POPULATED)
#    FetchContent_Populate(sfml)
#    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
#endif()

set(SOURCE_FILES Main.cpp)

add_compile_definitions(_HAS_AUTO_PTR_ETC=1)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-audio
    sfml-graphics
    sfml-system
    sfml-window
)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)