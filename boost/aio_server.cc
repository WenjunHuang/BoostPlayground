//
// Created by HUANG WEN JUN on 2020/2/26.
//
#include <boost/asio.hpp>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

using boost::asio::ip::tcp;

std::string makeDaytimeString() {
    auto now = std::time(nullptr);
    return std::ctime(&now);
}

class TcpConnection : public std::enable_shared_from_this<TcpConnection> {
  public:
    explicit TcpConnection(boost::asio::io_context& ioContext)
        : socket_{ioContext} {}

    void handleWrite(const boost::system::error_code&, size_t) {}

    void start() {
        message_ = makeDaytimeString();
        std::cout << "Connection accepted" << std::endl;
        std::cout << message_ << std::endl;
        boost::asio::async_write(socket_, boost::asio::buffer(message_),
                                 [self=shared_from_this()](auto& error, auto bytesTransferred) {});
    }

    tcp::socket& socket() { return socket_; }

  private:
    tcp::socket socket_;
    std::string message_;
};

class TcpServer {
  public:
    TcpServer(boost::asio::io_context& ioContext)
        : io_context_{ioContext}, acceptor_{ioContext,
                                            tcp::endpoint(tcp::v4(), 1313)} {
        startAccept();
    }

  private:
    void startAccept() {
        auto newConnection = std::make_shared<TcpConnection>(io_context_);
        acceptor_.async_accept(newConnection->socket(), [=](auto& error) {
            if (!error)
                newConnection->start();
            startAccept();
        });
    }

    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
};

int main() {
    try {
        boost::asio::io_context ioContext;
        TcpServer server{ioContext};
        ioContext.run();
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
}