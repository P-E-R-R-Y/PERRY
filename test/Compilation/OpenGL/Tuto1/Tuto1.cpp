// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace gl {
    class Window {
        public:
            Window(): isReady(false) {
                // Initialise GLFW
                glewExperimental = true; // Needed for core profile
                if (!glfwInit())
                {
                    fprintf(stderr, "Failed to initialize GLFW\n");
                    return;
                }

                glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
                glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
                glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
                glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
                glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

                    // Open a window and create its OpenGL context
                window = glfwCreateWindow(1024, 768, "OpenGl", NULL, NULL);
                if (window == NULL)
                {
                    fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
                    glfwTerminate();
                    return;
                }
                glfwMakeContextCurrent(window); // Initialize GLEW
                glewExperimental = true;        // Needed in core profile
                if (glewInit() != GLEW_OK)
                {
                    fprintf(stderr, "Failed to initialize GLEW\n");
                    return;
                }

                // Ensure we can capture the escape key being pressed below
                glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
                isReady = true;
            }
            
            ~Window() {
            }

            bool isOpen() {
                return isReady;
            }

            bool shouldClose() {
                return (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(window) == 1);
            }

            void clear() {
                // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
                glClear(GL_COLOR_BUFFER_BIT);
            }

            void draw() {
                // Draw nothing, see you in tutorial 2 !        
            }

            void swapBuffers() {
                // Swap buffers
                glfwSwapBuffers(window);
                glfwPollEvents();                
            }
        private:
            GLFWwindow *window; // (In the accompanying source code, this variable is global for simplicity)
            bool isReady;
    };

}

int main()
{
    gl::Window window = gl::Window();

    while(!window.shouldClose()) {
        window.clear();
        window.swapBuffers();

    }
}