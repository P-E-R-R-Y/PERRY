#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#include "Quaternion.hpp"

class Camera {
    private:
        std::array<double, 3> crossProduct(const std::array<double, 3>& A, const std::array<double, 3>& B) {
            return {
                A[1] * B[2] - A[2] * B[1],
                A[2] * B[0] - A[0] * B[2],
                A[0] * B[1] - A[1] * B[0]
            };
        }

        // Function to calculate the normalized direction vector
        std::array<double, 3> calculateDirection(const std::array<double, 3>& position, const std::array<double, 3>& target) {
            std::array<double, 3> direction = {
                target[0] - position[0],
                target[1] - position[1],
                target[2] - position[2]
            };

            // Normalize the direction vector
            double magnitude = std::sqrt(direction[0] * direction[0] +
                                        direction[1] * direction[1] +
                                        direction[2] * direction[2]);
            if (magnitude == 0.0) {
                throw std::invalid_argument("Position and target cannot be the same.");
            }

            return {direction[0] / magnitude, direction[1] / magnitude, direction[2] / magnitude};
        }

        // Function to calculate Euler angles (yaw and pitch)
        std::array<double, 3> calculateEulerAngles(const std::array<double, 3>& direction, const std::array<double, 3>& up = {0, 1, 0}) {
            // Yaw: rotation about the Y-axis
            double yaw = std::atan2(direction[0], direction[2]);

            // Pitch: rotation about the X-axis
            double pitch = std::asin(-direction[1]);

            // Roll: rotation about the Z-axis
             std::array<double, 3> rightVector = crossProduct(up, direction);
            double roll = std::atan2(rightVector[1], rightVector[0]);
            


            return {yaw, pitch, roll};
        }
    public:
        Camera(sf::Vector3f position, sf::Vector3f center, uint fov) : position(position), center(center), quaternion(0, 0, 0, 0), fov(fov) {
            const auto tmpDirection = calculateDirection({position.x, position.y, position.z}, {center.x, center.y, center.z});
            direction = {static_cast<float>(tmpDirection[0]), static_cast<float>(tmpDirection[1]), static_cast<float>(tmpDirection[2])};

            const auto tmpAngle = calculateEulerAngles({direction.x, direction.y, direction.z});
            eulerAngle = {static_cast<float>(tmpAngle[0] * 180.0f / M_PI), static_cast<float>(tmpAngle[1] * 180.0f / M_PI), static_cast<float>(tmpAngle[2] * 180.0f / M_PI)};
            std::cout << eulerAngle.x << " " << eulerAngle.y << " " << eulerAngle.z << std::endl;

            quaternion = Quaternion::fromEulerAngles(eulerAngle.x, eulerAngle.y, 90);
        }
        ~Camera() = default;
    public:
        sf::Vector3f position;
        sf::Vector3f center;
        
        sf::Vector3f direction;
        sf::Vector3f eulerAngle = {0.0f, 0.0f, 0.0f};
        Quaternion quaternion;

        uint fov = 400;
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

    void rotate(Quaternion q) {
        for (int i = 0; i < meshes.size(); i++) {
            std::array<double, 3> p = {meshes[i].x, meshes[i].y, meshes[i].z};
            std::array<double, 3> result = q.rotatePoint(p);
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
        
    auto cube = c.meshes;

    for (int i = 0; i < cube.size(); i++) {
            std::array<double, 3> result = cam.quaternion.rotatePoint({cube[i].x, cube[i].y, cube[i].z});
            cube[i].x = result[0];
            cube[i].y = result[1];
            cube[i].z = result[2];
        }

    //float mult = 50;

    std::vector<sf::Vector2f> copy;

    for (int i = 0; i < cube.size(); i++) {
        copy.push_back({(cube[i].x * 50) / (cam.fov + (cube[i].z * 50)) * cam.fov, (cube[i].y * 50) / (cam.fov + (cube[i].z * 50)) * cam.fov });
    }

    //draw
    for (int i = 0; i < 4; i++) {
        sf::Vertex line [] = {
            sf::Vertex(sf::Vector2f(copy[i].x, copy[i].y)),
            sf::Vertex(sf::Vector2f(copy[(i + 1) % 4].x, copy[(i + 1) % 4].y))
        };
        line[0].position.x = line[0].position.x + center.x;
        line[0].position.y = line[0].position.y + center.y;
        line[1].position.x = line[1].position.x + center.x;
        line[1].position.y = line[1].position.y + center.y;

        window.draw(line, 2, sf::Lines);
    }
    
    for (int i = 0; i < 4; i++) {
        sf::Vertex line [] = {
            sf::Vertex(sf::Vector2f(copy[i].x, copy[i].y)),
            sf::Vertex(sf::Vector2f(copy[i + 4].x, copy[i + 4].y))
        };
        line[0].position.x = line[0].position.x + center.x;
        line[0].position.y = line[0].position.y + center.y;
        line[1].position.x = line[1].position.x + center.x;
        line[1].position.y = line[1].position.y + center.y;
        
        window.draw(line, 2, sf::Lines);
    }
    for (int i = 0; i < 4; i++) {
        sf::Vertex line [] = {
            sf::Vertex(sf::Vector2f(copy[i + 4].x, copy[i + 4].y)),
            sf::Vertex(sf::Vector2f(copy[((i + 1) % 4) + 4].x, copy[((i + 1) % 4) + 4].y))
        };
        line[0].position.x = line[0].position.x + center.x;
        line[0].position.y = line[0].position.y + center.y;
        line[1].position.x = line[1].position.x + center.x;
        line[1].position.y = line[1].position.y + center.y;
            
        window.draw(line, 2, sf::Lines);
    }
    //draw points
    for (int i = 0; i < copy.size(); i++) {
        sf::CircleShape point(4);
        point.setPosition(copy[i].x + center.x - 4, copy[i].y + center.y - 4);
        window.draw(point);
    }
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    Cube c;
    sf::Clock clock;
    Camera camera({8, 0, 8}, {0, 0, 0}, 200);

    clock.restart();
    uint fps = 60;
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

        //c.rotate({0, 0.1, 0.1});

        drawCube(window, camera, c);

        // end the current frame
        window.display();
    }
    return 0;
}