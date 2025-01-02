#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#include "Quaternion.hpp"
#include "Object.hpp"
#include "Camera.hpp"
#include "Matrice.hpp"
#include "Vector3f.hpp"
#include "Trigo.hpp"

#include <cmath> // For M_PI

void DrawPoint(sf::RenderWindow& window, const sf::Vector3f& point, Camera& camera) {
    //!make the camera the origin
    sf::Vector3f relativePosition = point - camera.getPosition();

    std::cout << "relativePosition: " << relativePosition.x << " " << relativePosition.y << " " << relativePosition.z << std::endl;


    //!rotate the object
    sf::Vector3f relativeRotatedPosition = camera.getQuaternion().conjugate().rotate(relativePosition);

    if (relativeRotatedPosition.z >= 0) {
        return; //skip drawing points that are behind the camera
    }

    //Don't need to move the object back to its original position because the camera is the origin for perspective projection
    sf::Vector3f rotatedPosition = relativeRotatedPosition;
    std::cout << "points: " << rotatedPosition.x << " " << rotatedPosition.y << " " << rotatedPosition.z << std::endl;
    //!perspective projection
    sf::Vector2f screen = window.getView().getSize();

    Matrice<float> projection = perspectiveProjection<float>(camera.getFov(), screen.x / screen.y);
    Matrice<float> vtom = Matrice<float>({{rotatedPosition.x}, {rotatedPosition.y}, {rotatedPosition.z}, {1.f}});
    Matrice<float> res = projection * vtom;
    //!homogeneous division// convert to normalized device coordinates
    float x_ndc = res(0, 0) / res(3, 0);
    float y_ndc = res(1, 0) / res(3, 0);

    if (x_ndc < -1 || x_ndc > 1 || y_ndc < -1 || y_ndc > 1) {
        return; //skip drawing points that are outside the screen
    }

    //NDC to screen coordinates
    float screenX = (x_ndc + 1.0f) * 0.5f * screen.x;
    float screenY = (1.0f - y_ndc) * 0.5f * screen.y;
    
    // Draw the point
    sf::CircleShape circle(1);
    circle.setPosition(screenX, screenY);
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(1);
    window.draw(circle);

    return;
}

void DrawObject(sf::RenderWindow& window, Object& object, Camera& camera) {
    // Rotate the object based on the inverse of the camera quaternion
    //Quaternion inverse = camera.getQuaternion().conjugate();

    for (sf::Vector3f point : object.getVertices()) {
        //draw
        DrawPoint(window, point, camera);
    }
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Clock clock;
    Object object;
    Camera camera = Camera({0, 0, 2}, {0, 0, 0}, 90);

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
        std::cout << "==========================================" << std::endl;
        std::cout << "----- w:" << camera.getQuaternion().w << " x: " << camera.getQuaternion().x << " y: " << camera.getQuaternion().y << " z: " << camera.getQuaternion().z << std::endl;
        camera.rotateY(degreestoRadians(1 / 60.f));

        window.display();
    }
    return 0;
}