#MAIN

cmake_minimum_required(VERSION 3.14)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Interfaces
add_subdirectory(Interfaces/core)
add_subdirectory(Interfaces/graphic)
add_subdirectory(Interfaces/system)

##Static
add_subdirectory(Abstractions/core/dynamic)
add_subdirectory(Abstractions/engine/dynamicswitchengine)

##Shared
list(APPEND CMAKE_SOURCE_SHARED_LIBS Raylib Sfml Sdl)
list(APPEND CMAKE_BIN_SHARED_LIBS raylibgraphic sfmlgraphic sdlgraphic)

foreach(folder IN LISTS CMAKE_SOURCE_SHARED_LIBS)
  add_subdirectory(Abstractions/graphic/${folder})
endforeach()

#SET_LIBRARY
#if (WIN32)
#  set(STATIC_EXTENTION ".lib")
#  set(SHARED_EXTENTION ".dll")
#elseif(APPLE)
#  set(STATIC_EXTENTION ".a")
#  set(SHARED_EXTENTION ".dylib")
#elseif (UNIX)
#  set(STATIC_EXTENTION ".a")
#  set(SHARED_EXTENTION ".so")
#else ()
#  message(FATAL_ERROR "OS not supported")
#endif()

#je voudrais pouvoir creer un executable et lui donner acces a la librairie graphics3
set(SOURCE_FILES
  main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#Link static libraries
target_link_libraries(${PROJECT_NAME} PUBLIC system)
target_link_libraries(${PROJECT_NAME} PUBLIC igraphic icore)
target_link_libraries(${PROJECT_NAME} PUBLIC dynamiccore dynamicswitchengine)

#Assets & More
file(COPY Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) 

MAKE_DIRECTORY(${CMAKE_BINARY_DIR}/Shared)
#create two list for the shared_lib: sources and the binary.
foreach(folder bin IN ZIP_LISTS CMAKE_SOURCE_SHARED_LIBS CMAKE_BIN_SHARED_LIBS)
  message(${folder} " : " ${bin})
  #set(GLFW_USE_COCOA OFF)
  if (EXISTS ${CMAKE_SOURCE_DIR}/Abstractions/graphic/${folder})
    message("-------------------------------------------------------------Shared folder found")
    #prebuild remove the shared folder
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${bin}> ${CMAKE_BINARY_DIR}/Shared)
  else ()
    message(FATAL_ERROR "-------------------------------------------------------------Shared folder not found")
  endif()
endforeach()