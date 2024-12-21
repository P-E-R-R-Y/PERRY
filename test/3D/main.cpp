/*#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#include "Quaternion.hpp"

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

        drawMesh(window, camera, c);
        // end the current frame
        window.display();
    }
    return 0;
}*/

#include <stdio.h>

// Function for weak perspective projection
void weak_perspective_projection(
    float x, float y, float z, 
    float fov, float window_width, float window_height, 
    float *screen_x, float *screen_y
) {
    float epsilon = 0.0001f; // Small value to avoid division by zero

    // Weak perspective projection
    float x_proj = fov * x / (z + fov + epsilon);
    float y_proj = fov * y / (z + fov + epsilon);

    // Map to screen space
    *screen_x = (window_width / 2.0f) + x_proj * (window_width / 2.0f);
    *screen_y = (window_height / 2.0f) - y_proj * (window_height / 2.0f);
}

int main() {
    // Parameters
    float fov = 400.0f;
    float window_width = 800.0f;
    float window_height = 600.0f;

    // Test points
    float points[2][3] = {
        {0.0f, 0.0f, 0.0f},  // Origin
        {1.0f, 1.0f, 1.0f}   // Positive diagonal
    };

    // Iterate through points and project them
    for (int i = 0; i < 2; i++) {
        float screen_x, screen_y;
        weak_perspective_projection(
            points[i][0], points[i][1], points[i][2],
            fov, window_width, window_height,
            &screen_x, &screen_y
        );
        printf("3D Point (%f, %f, %f) => Screen Point (%f, %f)\n",
               points[i][0], points[i][1], points[i][2], screen_x, screen_y);
    }

    return 0;
}