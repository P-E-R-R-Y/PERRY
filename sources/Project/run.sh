#!/bin/sh

# CREATE LIBRARIES

# sfml
g++ -shared -fPIC -o libsfml.so Sfml/sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
# raylib
g++ -shared -fPIC -o libraylib.so Raylib/raylib.cpp -lraylib -lGL -lm -lpthread -lrt -lX11
# move to folder
mv lib*.so Libraries/

# create the executable
g++ main.cpp -ldl

# run the executable
./a.out -l raylib