##
# cmake
##

cmake_minimum_required(VERSION 3.20) # minimum cmake version
enable_language(CXX) # select languages (C, CXX (i.e. C++), CSharp (i.e. C#), CUDA, OBJC (i.e. Objective-C), OBJCXX (i.e. Objective-C++), Fortran, HIP, ISPC, Swift, ASM, ASM_NASM, ASM_MARMASM, ASM_MASM, and ASM-ATT).

##
# cxx
##

set(CMAKE_CXX_STANDARD 11) # set CXX:20 <- CMake:3.12 - should be place before add executable()
set(CMAKE_CXX_STANDARD_REQUIRED ON) # set CXX Required

set(CXX_EXTENSIONS OFF) #-std=gnu++11 instead of -std=c++11 (ON by default)

##
# project
##
 
project(a.out) # set the executable name
add_executable(a.out main.cpp) # add file to executable
