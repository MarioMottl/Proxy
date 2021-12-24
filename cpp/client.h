//
// Created by Mario on 18/12/2021.
//

#ifndef PROXY_CLIENT_H
#define PROXY_CLIENT_H

#include "net_common.h"

using boost::asio::ip::tcp;


namespace net
{
    //Easy error handler
    bool clienterror(std::string errormsg, boost::system::error_code ec);

    /*
    Class: Class for client
    Description: synchronous TCP client
    */
    class client{

    private:

        boost::asio::io_context iocontext;
        tcp::socket socket;
        boost::system::error_code ec;
        bool connected;
        int packetlength = 256;

    public:

        client();
        ~client();
        
        /*
        Function : connect(const std::string& host, int port)
        Description: connects to provided host,port
        */
        void connect(const std::string& host, int port);

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
        Function : getclientstatus()
        Description: Returns status of the client socket
        Return: true if socket is alive : false if socket is dead
        */
        bool getclientstatus();

        /*
        Function : getport()
        Description: Returns port of the socket
        Return: port
        */
        uint16_t getport();

    };
}

#endif //PROXY_CLIENT_H
