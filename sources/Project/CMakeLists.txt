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
add_subdirectory(Libraries/DynamicSwitchCore) #${CMAKE_CURRENT_BINARY_DIR}/dynamic/dynamicswitchcore)
add_subdirectory(Libraries/Raylib3) #${CMAKE_CURRENT_BINARY_DIR}/dynamic/raylib3)
add_subdirectory(Libraries/Sfml3) #${CMAKE_CURRENT_BINARY_DIR}/dynamic/raylib3)

#how to retrieve the lib create in the subdirectory

#je voudrais pouvoir creer un executable et lui donner acces a la librairie graphics3
set(SOURCE_FILES
  main_dynamic.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC igraphic3 icore system) #static
target_link_libraries(${PROJECT_NAME} PUBLIC dynamicswitchcore) #static
target_link_libraries(${PROJECT_NAME} PUBLIC raylib3) #dynamic
file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR}) #can probably use this for dynamic lib too
