//
// Created by Mario on 18/12/2021.
//

#ifndef PROXY_SERVER_H
#define PROXY_SERVER_H

#include "net_common.h"
using boost::asio::ip::tcp;

namespace net{

    bool servererror(std::string errormsg, boost::system::error_code ec);

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
        void start(int port);
        void read(std::string &message);
        void write(std::string message);
    };
}


#endif //PROXY_SERVER_H
