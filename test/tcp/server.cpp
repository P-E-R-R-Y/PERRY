#include <asio.hpp>
#include <iostream>
#include <memory>

using asio::ip::tcp;

void handle_client(asio::ip::tcp::socket socket) {
    try {
        char data[1024];
        while (true) {
            std::size_t length = socket.read_some(asio::buffer(data));
            std::cout << "Received: " << std::string(data, length) << std::endl;
            asio::write(socket, asio::buffer(data, length)); // Echo back
        }
    } catch (std::exception& e) {
        std::cerr << "Client disconnected: " << e.what() << std::endl;
    }
}

int main() {
    try {
        asio::io_context io_context;
        asio::ip::tcp::acceptor acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 12345));
        std::cout << "Server listening on port 12345...\n";

        while (true) {
            asio::ip::tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::cout << "Client connected!\n";
            std::thread(handle_client, std::move(socket)).detach();
        }
    } catch (std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }
    return 0;
}