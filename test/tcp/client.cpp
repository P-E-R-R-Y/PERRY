#include <iostream>
#include "asio.hpp"

int main() {
    try {
        asio::io_context io_context;
        asio::ip::tcp::socket socket(io_context);
        socket.connect(asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 12345));
        std::cout << "Connected to server.\n";

        std::string message = "Hello, ASIO!";
        socket.write_some(asio::buffer(message));

        char response[1024];
        std::size_t length = socket.read_some(asio::buffer(response));
        std::cout << "Server response: " << std::string(response, length) << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
    }
    return 0;
}