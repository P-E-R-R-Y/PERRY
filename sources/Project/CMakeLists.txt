cmake_minimum_required(VERSION 3.14)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#I would like to call graphics3 cmake file

add_subdirectory(Interfaces/graphic3)
#include(Interface/graphic3/CMakeLists.txt)

#how to retrieve the lib create in the subdirectory


#je voudrais pouvoir creer un executable et lui donner acces a la librairie graphics3
set(SOURCE_FILES
  main-copy.cpp
)

add_executable(app ${SOURCE_FILES})
target_link_libraries(app PUBLIC graphic3)

