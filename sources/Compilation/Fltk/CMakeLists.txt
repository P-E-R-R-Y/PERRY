
cmake_minimum_required(VERSION 3.14)
project(app)

set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)
if(UNIX AND NOT APPLE) 
    set(OPTION_USE_PANGO ON CACHE BOOL " " FORCE)
endif()

include(FetchContent)

FetchContent_Declare(FLTK
    GIT_REPOSITORY https://github.com/fltk/fltk
)
FetchContent_MakeAvailable(FLTK)

if(WIN32)
    set(GUI_TYPE WIN32)
elseif(APPLE)
    set(GUI_TYPE MACOSX_BUNDLE)
else()
    set(GUI_TYPE)
endif()

set(SOURCE_FILES Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES}) #add ${GUI_TYPE} between {PROJECT_NAME} & ${SOURCE_FILES} To create executable in app.app/Content/GUI_TYPE
target_include_directories(${PROJECT_NAME} PRIVATE ${fltk_SOURCE_DIR} ${fltk_BINARY_DIR}) # needed for visual studio
target_link_libraries(${PROJECT_NAME} PRIVATE fltk) # if needed: fltk_gl fltk_images fltk_png fltk_jpeg fltk_z 

if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
endif()