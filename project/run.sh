#!/bin/sh

# CREATE LIBRARIES

if [[ "$OSTYPE" == "linux-gnu"* ]]; then #Linux
  ## SFML
  g++ -shared -fPIC -o libsfml.so Sfml/sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
  ## Raylib
  g++ -shared -fPIC -o libraylib.so Library/Raylib/raylib.cpp -lraylib -lGL -lm -lpthread -lrt -lX11 -std=c++20

elif [[ "$OSTYPE" == "darwin"* ]]; then #Macos
  g++ -shared -fPIC -o libraylib.so Libraries/RaylibG3/raylib.cpp -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL Libraries/RaylibG3/libraylib.a -std=c++20
fi

# MOVE LIBRARIES
mv lib*.so Shared/

# create the executable

# DYNAMIC
g++ main_dynamic.cpp -ldl -g3 --std=c++20


# STATIC

# RAYLIB (-L Raylib -lraylib)
#g++ main_raylib.cpp -ldl -g3 --std=c++20  -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL Library/RaylibG3/libraylib.a -std=c++20

# (SDL2) (-L Raylib -lraylib) -lSDL2 (-I/Library/Frameworks/SDL2.framework/Headers)
#g++ main_sdl2.cpp  -ldl -g3 --std=c++20 -framework SDL2 -framework Cocoa -F/Library/Frameworks -framework SDL2 -std=c++20

# run the executable
./a.out