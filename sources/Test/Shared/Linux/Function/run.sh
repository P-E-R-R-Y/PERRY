g++ -shared -fPIC -o libshared.so shared.cpp
g++ main.cpp -ldl
./a.out