#!/bin/bash

# create the sfml library

g++ -shared -fPIC -o libsfml.so Sfml/sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system

# create the executable

g++ main.cpp -ldl

# run the executable

./a.out