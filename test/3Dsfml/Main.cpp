#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#include "Quaternion.hpp"

class Camera {
    public:
        Camera(sf::Vector3f position, sf::Vector3f center, uint fov) : position(position), center(center), fov(fov) {}
        ~Camera() = default;
    public:
        sf::Vector3f position = {0, 0, 0};        
        sf::Vector3f center = {0, 0, 0};
        uint fov = 60;
};

class Cube {
    public:
        std::vector<sf::Vector3f> meshes = {
            {-1, 1, 1}, // left top back
            {1, 1, 1}, // right top back
            {1, -1, 1}, // right bottom back
            {-1, -1, 1}, // left bottom back
            //
            {-1, 1, -1}, // left top front
            {1, 1, -1}, // right top front
            {1, -1, -1}, // right bottom front
            {-1, -1, -1}, // left bottom front

            {2, -1, -1},
            {2, 2, -1},
            {-2, 2, 2},
            {-3, 3, 3},
            {-4, 4, 4},
        };

    void rotate(sf::Vector3f angle, sf::Vector3f center = {0, 0, 0}) {
        for (int i = 0; i < meshes.size(); i++) {
            std::array<double, 3> p = {meshes[i].x, meshes[i].y, meshes[i].z};
            std::array<double, 3> a = {angle.x, angle.y, angle.z};
            std::array<double, 3> cor = {center.x, center.y, center.z};
            std::array<double, 3> result = Quaternion::rotate(p, a, cor);
            meshes[i].x = result[0];
            meshes[i].y = result[1];
            meshes[i].z = result[2];
        }
    }

};

void rotateQuaternion(Cube &c, sf::Vector3f angle, sf::Vector3f center = {0, 0, 0}) {
    auto& cube = c.meshes;

    for (int i = 0; i < cube.size(); i++) {
        std::array<double, 3> p = {cube[i].x, cube[i].y, cube[i].z};
        std::array<double, 3> a = {angle.x, angle.y, angle.z};
        std::array<double, 3> cor = {center.x, center.y, center.z};
        std::array<double, 3> result = Quaternion::rotate(p, a, cor);
        cube[i].x = result[0];
        cube[i].y = result[1];
        cube[i].z = result[2];
    }
}

void drawCube(sf::RenderWindow &window, Camera cam, Cube &c){
    sf::Vector2u size = {800, 500};
    sf::Vector2u center = sf::Vector2u(size.x / 2, size.y / 2);
    float fovy = 60;
    auto cube = c.meshes;

    float mult = 50;
            
    //draw
    for (int i = 0; i < 4; i++) {
        sf::Vertex line [] = {
            sf::Vertex(sf::Vector2f(cube[i].x, cube[i].y)),
            sf::Vertex(sf::Vector2f(cube[(i + 1) % 4].x, cube[(i + 1) % 4].y))
        };
        line[0].position.x = line[0].position.x * mult + center.x;
        line[0].position.y = line[0].position.y * mult + center.y;
        line[1].position.x = line[1].position.x * mult + center.x;
        line[1].position.y = line[1].position.y * mult + center.y;

        window.draw(line, 2, sf::Lines);
    }
    for (int i = 0; i < 4; i++) {
        sf::Vertex line [] = {
            sf::Vertex(sf::Vector2f(cube[i].x, cube[i].y)),
            sf::Vertex(sf::Vector2f(cube[i + 4].x, cube[i + 4].y))
        };
        line[0].position.x = line[0].position.x * mult + center.x;
        line[0].position.y = line[0].position.y * mult + center.y;
        line[1].position.x = line[1].position.x * mult + center.x;
            line[1].position.y = line[1].position.y * mult + center.y;
        
            window.draw(line, 2, sf::Lines);
        }
    for (int i = 0; i < 4; i++) {
            sf::Vertex line [] = {
                sf::Vertex(sf::Vector2f(cube[i + 4].x, cube[i + 4].y)),
                sf::Vertex(sf::Vector2f(cube[((i + 1) % 4) + 4].x, cube[((i + 1) % 4) + 4].y))
            };
            line[0].position.x = line[0].position.x * mult + center.x;
            line[0].position.y = line[0].position.y * mult + center.y;
            line[1].position.x = line[1].position.x * mult + center.x;
            line[1].position.y = line[1].position.y * mult + center.y;
            
        window.draw(line, 2, sf::Lines);
    }
    //draw points
    for (int i = 0; i < cube.size(); i++) {
        sf::CircleShape point(4);
        point.setPosition(cube[i].x * mult + center.x - 4, cube[i].y * mult + center.y - 4);
        window.draw(point);
    }
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    Cube c;
    sf::Clock clock;
    Camera camera({1, 1, 1}, {0, 0, 0}, 60);

    clock.restart();
    uint fps = 240;
    int i = 0;

    // run the program as long as the window is open
    while (window.isOpen()) {
        if (clock.getElapsedTime().asMilliseconds() < 1000 / (fps + 1)) {
            //std::this_thread::sleep_for(std::chrono::milliseconds(1000 / (fps + 1) - clock.getElapsedTime().asMilliseconds()));
            i++;
        } else {
            std::cout << i << std::endl;
            i = 0;
            clock.restart();
        }
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        c.rotate({0.1, 0.1, 0.1});

        drawCube(window, camera, c);

        // end the current frame
        window.display();
    }
    return 0;
}