//
// Created by Mario on 18/12/2021.
//

#include "server.h"

net::server::server() : socket(iocontext), acceptor(iocontext){}

net::server::~server() {
    socket.close();
    acceptor.close();
}

void net::server::start(int port) {
    boost::asio::ip::tcp::endpoint endpoint(tcp::v4(), port);
    acceptor.open(endpoint.protocol());
    acceptor.bind(endpoint);
    acceptor.listen(boost::asio::socket_base::max_connections);
    acceptor.accept(socket);
    connected = true;
    std::cout << "[SERVER] client connected:  "<< socket.remote_endpoint() << std::endl;
}

bool net::servererror(std::string errormsg, boost::system::error_code ec) {
    if (ec)
    {
        std::cout << "[SERVER]: " << errormsg << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}

void net::server::read(std::string &message) {
    if(connected){
        char buf[packetlength];
        boost::asio::read(socket, boost::asio::buffer(buf, packetlength), boost::asio::transfer_at_least(1), ec);
        servererror("couldn't read",ec);
        message = buf;
    }
}

void net::server::write(std::string message) {
    if(connected)
    {
        boost::asio::write(socket,boost::asio::buffer(message.c_str(),message.length()),boost::asio::transfer_all(),ec);
        servererror("couldn't write",ec);
    }
}
