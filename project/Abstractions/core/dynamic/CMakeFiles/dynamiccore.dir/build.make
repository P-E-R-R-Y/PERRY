# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/perrychouteau/Documents/GitHub/PERRY/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/perrychouteau/Documents/GitHub/PERRY/project

# Include any dependencies generated for this target.
include Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/compiler_depend.make

# Include the progress variables for this target.
include Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/progress.make

# Include the compile flags for this target's objects.
include Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/flags.make

Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/no_source.cpp.o: Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/flags.make
Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/no_source.cpp.o: Abstractions/core/dynamic/no_source.cpp
Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/no_source.cpp.o: Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/perrychouteau/Documents/GitHub/PERRY/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/no_source.cpp.o"
	cd /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/no_source.cpp.o -MF CMakeFiles/dynamiccore.dir/no_source.cpp.o.d -o CMakeFiles/dynamiccore.dir/no_source.cpp.o -c /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic/no_source.cpp

Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/no_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dynamiccore.dir/no_source.cpp.i"
	cd /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic/no_source.cpp > CMakeFiles/dynamiccore.dir/no_source.cpp.i

Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/no_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dynamiccore.dir/no_source.cpp.s"
	cd /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic/no_source.cpp -o CMakeFiles/dynamiccore.dir/no_source.cpp.s

# Object files for target dynamiccore
dynamiccore_OBJECTS = \
"CMakeFiles/dynamiccore.dir/no_source.cpp.o"

# External object files for target dynamiccore
dynamiccore_EXTERNAL_OBJECTS =

Abstractions/core/dynamic/libdynamiccore.a: Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/no_source.cpp.o
Abstractions/core/dynamic/libdynamiccore.a: Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/build.make
Abstractions/core/dynamic/libdynamiccore.a: Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/perrychouteau/Documents/GitHub/PERRY/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdynamiccore.a"
	cd /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic && $(CMAKE_COMMAND) -P CMakeFiles/dynamiccore.dir/cmake_clean_target.cmake
	cd /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dynamiccore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/build: Abstractions/core/dynamic/libdynamiccore.a
.PHONY : Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/build

Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/clean:
	cd /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic && $(CMAKE_COMMAND) -P CMakeFiles/dynamiccore.dir/cmake_clean.cmake
.PHONY : Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/clean

Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/depend:
	cd /Users/perrychouteau/Documents/GitHub/PERRY/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/perrychouteau/Documents/GitHub/PERRY/project /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic /Users/perrychouteau/Documents/GitHub/PERRY/project /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic /Users/perrychouteau/Documents/GitHub/PERRY/project/Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Abstractions/core/dynamic/CMakeFiles/dynamiccore.dir/depend

