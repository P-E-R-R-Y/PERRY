#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#include "Quaternion.hpp"
#include "Object.hpp"
#include "Camera.hpp"
#include "Matrice.hpp"
#include "Vector3f.hpp"

void DrawPoint(sf::RenderWindow& window, const sf::Vector3f& point, Camera& camera) {
    //make the camera the origin
    sf::Vector3f relativePosition = point - camera.getPosition();

    //rotate the object
    sf::Vector3f relativeRotatedPosition = camera.getQuaternion().conjugate().rotate(relativePosition);

    //Don't need to move the object back to its original position because the camera is the origin for perspective projection
    sf::Vector3f rotatedPosition = relativeRotatedPosition;

    //perspective projection
    Matrice<float> projection = perspectiveProjection<float>(camera.getFov(), 800.0 / 600.0);


//todo calculate the projection of the point
//    std::array<float, 4> homogenCoord = {point.x, point.y, point.z, 1.f};
//    std::array<float, 4> result;
//
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            result[i] += projection[i][j] * homogenCoord[j];
//        }
//    }
//    
//    Matrice<float> res = projection * vtom<float>(rotatedPosition);
}

void DrawObject(sf:: RenderWindow& window, Object& object, Camera& camera) {
    // Rotate the object based on the inverse of the camera quaternion
    Quaternion inverse = camera.getQuaternion().conjugate();

    //make the camera the origin
    sf::Vector3f relativePosition = object.getPosition() - camera.getPosition();

    //rotate the object
    sf::Vector3f relativeRotatedPosition = inverse.rotate(relativePosition);

    //move the object back to its original position
    sf::Vector3f rotatedPosition = relativeRotatedPosition + camera.getPosition();

    // Draw the object
    for (sf::Vector3f point : object.getVertices()) {
        DrawPoint(window, point, camera);
    }
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Clock clock;
    Object object;
    Camera camera = Camera({0, 0, 0}, {0, 0, -1}, 90);

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
        window.clear(sf::Color::Black);

        DrawObject(window, object, camera);

        window.display();
    }
    return 0;
}