//
// Created by Mario on 18/12/2021.
//

#ifndef PROXY_SERVER_H
#define PROXY_SERVER_H

#include "net_common.h"
using boost::asio::ip::tcp;

namespace net{

    //Easy error handler
    bool servererror(std::string errormsg, boost::system::error_code ec);

    /*
    Class: Class for server
    Description: synchronous TCP server
    */
    class server{
    private:
        boost::asio::io_context iocontext;
        tcp::socket socket;
        boost::system::error_code ec;
        bool started = false;
        tcp::acceptor acceptor;
        size_t packetlength = 256;
        bool connected;

    public:
        server();
        ~server();

        /*
        Function : start(uint16_t port)
        Description: starts acceptor on provided port
        */
        void start(uint16_t port);

        /*
        Function : read(std::string &message)
        Description: reads from the socket
        Return: returns the message call by reference
        */
        void read(std::string &message);

        /*
        Function : write(std::string message)
        Description: writes to the socket
        */
        void write(std::string message);

        /*
        Function : getserverstatus()
        Description: Returns status of the server socket
        Return: true if socket is alive : false if socket is dead
        */
        bool getserverstatus();
    };
}


#endif //PROXY_SERVER_H
