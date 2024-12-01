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
  #serial/json
  #serial/yaml
)

list(APPEND CMAKE_BIN_SHARED
  raylibgraphic 
  sfmlgraphic
  sdlgraphic
  #jsonserial
  # yamlserial
)

## ----------- Subdirectory CMake -----------

#interfaces
foreach(folder IN LISTS CMAKE_SOURCE_INTERFACE)
  add_subdirectory(interfaces/${folder})
endforeach()
#libraries
foreach(folder IN LISTS CMAKE_SOURCE_STATIC)
  add_subdirectory(libraries/${folder})
endforeach()
#modules
foreach(folder IN LISTS CMAKE_SOURCE_SHARED)
  add_subdirectory(modules/${folder})
endforeach()

## ----------- Executable -----------
set(SOURCE_FILES 
  main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

## ----------- Linking -----------

#interfaces
foreach(bin IN LISTS CMAKE_BIN_INTERFACE)
  target_link_libraries(${PROJECT_NAME} PUBLIC ${bin})
endforeach()

#libraries
foreach(bin IN LISTS CMAKE_BIN_STATIC)
  target_link_libraries(${PROJECT_NAME} PUBLIC ${bin})
endforeach()

#modules
MAKE_DIRECTORY(${CMAKE_BINARY_DIR}/shared)
foreach(folder bin IN ZIP_LISTS CMAKE_SOURCE_SHARED CMAKE_BIN_SHARED)
  message(${folder} " : " ${bin})
  if (EXISTS ${CMAKE_SOURCE_DIR}/modules/${folder})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${bin}> ${CMAKE_BINARY_DIR}/shared)
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