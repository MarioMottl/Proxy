//
// Created by Mario on 18/12/2021.
//

#include "client.h"

net::client::client() : socket(iocontext){

}


void net::client::connect(const std::string& host, int port){
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(host), port);
    socket.connect(endpoint,ec);
    if(!clienterror("could not connect",ec))
    {
        connected = false;
        return;
    }
    else
    {
        std::cout <<"[CLIENT] -> connected to [IP]: " << &host << " [PORT]: " << port << std::endl;
        connected = true;
    }
}


net::client::~client() {
    if (connected)
    {
        socket.close(ec);
        if(!clienterror("could not close socket",ec))
        {
            std::cout <<"[CLIENT] -> disconnected " << std::endl;
            connected = false;
        }
    }
}

void net::client::read(std::string &message) {
    if(connected){
        char buf[packetlength];
        boost::asio::read(socket, boost::asio::buffer(buf, packetlength), boost::asio::transfer_at_least(1), ec);
        //clienterror("couldn't read",ec);
        message = buf;
    }
}

void net::client::write(std::string message) {
    if(connected)
    {
        boost::asio::write(socket,boost::asio::buffer(message.c_str(),message.length()),boost::asio::transfer_at_least(1),ec);
        clienterror("couldn't write",ec);
    }
}

bool net::client::getclientstatus() {
    if(socket.is_open()) return true;
    return false;
}

bool net::clienterror(std::string errormsg, boost::system::error_code ec) {
    if(ec)
    {
        std::cout << "[CLIENT]: " << errormsg << std::endl;
        return false;
    }
    else
    {
        return true;
    }

}