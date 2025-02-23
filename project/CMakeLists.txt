cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------- Libraries -----------

#Interfaces
list(APPEND CMAKE_SOURCE_INTERFACE core graphic serial)
list(APPEND CMAKE_BIN_INTERFACE icore igraphic iserial)
#Static
list(APPEND CMAKE_SOURCE_STATIC system maths finder)
list(APPEND CMAKE_BIN_STATIC system maths finder)
#Shared
list(APPEND CMAKE_SOURCE_SHARED 
  graphic/raylib
  graphic/sfml
  graphic/sdl

  serial/json
  serial/yaml

  core/ecs
)

list(APPEND CMAKE_BIN_SHARED
  raylibgraphic 
  sfmlgraphic
  sdlgraphic

  jsonserial
  yamlserial

  ecs
)

## ----------- Subdirectory CMake -----------

#interfaces
foreach(folder IN LISTS CMAKE_SOURCE_INTERFACE)
  add_subdirectory(interfaces/${folder})
endforeach()
#libraries
foreach(folder IN LISTS CMAKE_SOURCE_STATIC)
  add_subdirectory(static/${folder})
endforeach()
#modules
foreach(folder IN LISTS CMAKE_SOURCE_SHARED)
  add_subdirectory(shared/${folder})
endforeach()

## ----------- Executable -----------
set(SOURCE_FILES 
  main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

## ----------- Include -----------

target_include_directories(${PROJECT_NAME} PUBLIC
  include
)

## ----------- Linking -----------

#interfaces
foreach(bin IN LISTS CMAKE_BIN_INTERFACE)
  target_link_libraries(${PROJECT_NAME} PUBLIC ${bin})
endforeach()

#libraries
foreach(bin IN LISTS CMAKE_BIN_STATIC)
  target_link_libraries(${PROJECT_NAME} PUBLIC ${bin})
endforeach()

target_link_libraries(${PROJECT_NAME} PUBLIC ecs)

#modules
set(SHARED_DIR ${CMAKE_BINARY_DIR}/shared)

file(MAKE_DIRECTORY ${SHARED_DIR})

add_custom_target(copy_shared ALL
#  COMMAND ${CMAKE_COMMAND} -E echo "Clearing shared directory..."
#  COMMAND ${CMAKE_COMMAND} -E remove_directory ${SHARED_DIR}  # Delete the shared directory
  COMMAND ${CMAKE_COMMAND} -E echo "Recreating shared directory..."
  COMMAND ${CMAKE_COMMAND} -E make_directory ${SHARED_DIR}   # Recreate the shared directory
)

foreach(folder bin IN ZIP_LISTS CMAKE_SOURCE_SHARED CMAKE_BIN_SHARED)
  message(${folder} " : " ${bin})
  if (EXISTS ${CMAKE_SOURCE_DIR}/shared/${folder})
    add_custom_command(TARGET copy_shared
      COMMAND ${CMAKE_COMMAND} -E echo "Copying" ${bin} "to shared directory..."
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${bin}> ${SHARED_DIR})
  else ()
    message(${folder} " not found")
  endif()
endforeach()

## ----------- Copy Assets -----------
if (EXISTS ${CMAKE_SOURCE_DIR}/assets)
  message("Copying assets")
  file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) 
endif()

## ----------- Compile Options -----------
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)