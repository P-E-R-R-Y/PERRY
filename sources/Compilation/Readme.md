# Tutorial Steps

[cmake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

## Step 1 - A Basics Starting Point

### Ex 0 - CMake Command (need Ex 1)

- [x] mkdir build
- [x] cmake ../
- [x] cmake --build .
- [x] ./project name

### Ex 1 - Building a Basic Project

- [x] add_executable()
- [x] cmake_minimum_required()
- [x] project()


### Ex 2 - Specifying the C++ Standard

# Project steps 

## Linux

[ ] - simple - .c
[ ] - simple - .c/.h
[x] - simple - CPP
[x] - simple - .cpp/.hpp
[ ] - static library - .a
[ ] - dynamic library - .so
[ ] - install library from outside (sfml/raylib/..)

##  Mac

[ ] - static library - .a
[ ] - dynamic library - .dylib
[ ] - install library from outside (sfml/raylib/..)

##  Windows

[ ] - static library - .lib
[ ] - dynamic library - .dll
[ ] - install library from outside (sfml/raylib/..)

## Libraries
| Status             | Distribution | Static sfx | Dynamic sfx | pfx |
|--------------------|--------------|------------|-------------|-----|
| :white_check_mark: | Linux        | .a         | .so         | lib |
|                    | MacOS        | .a         | .dylib      | lib |
|                    | Windows      | .lib       | .dll        | n/a |
|                    | FreeBSD      | .a         | .so         | lib |
