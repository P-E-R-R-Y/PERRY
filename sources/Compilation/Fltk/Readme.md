

[[fltk/fltk] Provide easier instructions for modern CMake (#164)	- Mohammed Alyousef	- Nov 23, 2020](https://www.fltk.org/newsgroups.php?gfltk.issues+v:1627
)
``` 	
Hello
I noticed there was some changes in the cmake readme. For more modern cmake (later than 3.14 which was released on March 2019, and we're currently at version 3.19), the easiest way to create a cmake project is to use the FetchContent module:

cmake_minimum_required(VERSION 3.14)
project(app)

include(FetchContent)

set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)
if(UNIX AND NOT APPLE) 
    set(OPTION_USE_PANGO ON CACHE BOOL " " FORCE)
endif()

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

add_executable(main ${GUI_TYPE} main.cpp)
target_include_directories(main PRIVATE ${fltk_SOURCE_DIR} ${fltk_BINARY_DIR}) # needed for visual studio
target_link_libraries(main PRIVATE fltk) # if needed: fltk_gl fltk_images fltk_png fltk_jpeg fltk_z 

if(APPLE)
    target_link_libraries(main PRIVATE "-framework Cocoa")
endif()
The above should work for Windows, MacOS and Linux.
Creating a static library using fltk will require adding more to the target_link_libraries depending on the platform.

Comments are owned by the poster. All other content is copyright 1998-2024 by Bill Spitzak and others. This project is hosted by The FLTK Team. Please report site problems to 'erco@seriss.com'.
```