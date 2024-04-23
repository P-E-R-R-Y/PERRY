#MAIN

cmake_minimum_required(VERSION 3.14)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#Interfaces
add_subdirectory(Interfaces/core) #${CMAKE_CURRENT_BINARY_DIR}/static/core)
add_subdirectory(Interfaces/graphic3) #${CMAKE_CURRENT_BINARY_DIR}/static/graphic3)
add_subdirectory(Interfaces/system) #${CMAKE_CURRENT_BINARY_DIR}/static/graphic3)

#Libraries
##Static
add_subdirectory(Libraries/DynamicSwitchCore) #${CMAKE_CURRENT_BINARY_DIR}/dynamic/dynamicswitchcore)
##Shared
add_subdirectory(Libraries/Raylib3) #${CMAKE_CURRENT_BINARY_DIR}/dynamic/raylib3)
add_subdirectory(Libraries/Sfml3) #${CMAKE_CURRENT_BINARY_DIR}/dynamic/raylib3)

#SET_LIBRARY
#move lib.(Shared) to root of bin
if (WIN32)
  set(STATIC_EXTENTION ".lib")
  set(SHARED_EXTENTION ".dll")
elseif(APPLE)
  set(STATIC_EXTENTION ".a")
  set(SHARED_EXTENTION ".dylib")
elseif (UNIX)
  set(STATIC_EXTENTION ".a")
  set(SHARED_EXTENTION ".so")
else ()
  message(FATAL_ERROR "OS not supported")
endif()

#je voudrais pouvoir creer un executable et lui donner acces a la librairie graphics3
set(SOURCE_FILES
  main_dynamic.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#Link static libraries
target_link_libraries(${PROJECT_NAME} PUBLIC system)
target_link_libraries(${PROJECT_NAME} PUBLIC igraphic3 icore)
target_link_libraries(${PROJECT_NAME} PUBLIC dynamicswitchcore)

#Assets & More
file(COPY Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) 
#file(COPY Shared DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#Work only work after the first build how to copy the file after subdirectory build

#add_custom_target(copy_shared_libraries DEPENDS raylib3 sfml3)
#set(CMAKE_SOURCE_SHARED_LIBS Raylib3 Sfml3)
MAKE_DIRECTORY(${CMAKE_BINARY_DIR}/Shared)
#create two list for the shared_lib: sources and the binary.
list(APPEND CMAKE_SOURCE_SHARED_LIBS Raylib3 Sfml3)
list(APPEND CMAKE_BIN_SHARED_LIBS raylib3 sfml3)
foreach(folder bin IN ZIP_LISTS CMAKE_SOURCE_SHARED_LIBS CMAKE_BIN_SHARED_LIBS)
  message(${folder} " : " ${bin})
  if (EXISTS ${CMAKE_SOURCE_DIR}/Libraries/${folder})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${bin}> ${CMAKE_BINARY_DIR}/Shared)
  endif()
endforeach()