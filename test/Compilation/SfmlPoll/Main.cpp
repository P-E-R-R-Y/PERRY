#include <SFML/Graphics.hpp>
#include <iostream>

class Keyboard {
    public:
        Keyboard(sf::Event &event) : _event(event) {}

        ~Keyboard() {
        }

        bool isKeyDown(sf::Keyboard::Key key) const {
            return sf::Keyboard::isKeyPressed(key);
        }

    private:
        sf::Event &_event;
};

class Event
{
    public:
        Event() {}
        ~Event() {}

    private:
        sf::Event _event;
};

class Mouse {
    public:
        Mouse(sf::Event &event) : _event(event) {}

        ~Mouse() {
        }

        bool isButtonDown() const {
            return sf::Mouse::isButtonPressed(sf::Mouse::Left);
        }

    private:
        sf::Event &_event;
};

class Window {
    public:
        Window() {
            _window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");
        }

        ~Window() {
            delete _window;
        }

        bool isOpen() {
            return _window->isOpen();
        }

        bool shouldClose() {
            return _event.type == sf::Event::Closed;
        }

        void close() {
            _window->close();
        }

        bool pollEvent(Event &event) {
            return _window->pollEvent(_event);
        }

        void clear() {
            _window->clear(sf::Color::Black);
        }


        void display() {
            _window->display();
        }

        Keyboard getKeyboard() {
            return  Keyboard(_event);
        }

        Mouse getMouse() {
            return Mouse(_event);
        }

    private:
        sf::RenderWindow *_window;
        sf::Event _event;
};

int main()
{x
    // create the window
    Window window;
    Keyboard keyboard = window.getKeyboard();
    Mouse mouse = window.getMouse();


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent())
        {
            // "close requested" event: we close the window
            if (window.shouldClose())
                window.close();
            if (keyboard.isKeyDown(sf::Keyboard::Space))
                std::cout << "SPACE" << std::endl;
        }
        std::cout << "GAME_LOOP" << std::endl;

        // clear the window with black color
        window.clear();

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}