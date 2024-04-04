#!/bin/sh

# CREATE LIBRARIES

## sfml

### LINUX
#g++ -shared -fPIC -o libsfml.so Sfml/sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
### OSX ?
# ?
#g++ -shared -fPIC -o libsfml.so Sfml/sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
### WINDOWS
# ?

## Raylib
### LINUX
# g++ -shared -fPIC -o libraylib.so Raylib/raylib.cpp -lraylib -lGL -lm -lpthread -lrt -lX11 -std=c++20
## OSX
g++ -shared -fPIC -o libraylib.so Raylib/raylib.cpp -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL Raylib/libraylib.a -std=c++20
## WINDOWS

# MOVE LIBRARIES
mv lib*.so Shared/

# create the executable
g++ main.cpp -ldl -g3 --std=c++20

# run the executable
./a.out