//
// Created by Mario on 18/12/2021.
//

#ifndef PROXY_CLIENT_H
#define PROXY_CLIENT_H

#include "net_common.h"

using boost::asio::ip::tcp;

namespace net
{
    bool clienterror(std::string errormsg, boost::system::error_code ec);


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
        void connect(const std::string& host, int port);
        void read(std::string &message);
        void write(std::string message);
    };
}

#endif //PROXY_CLIENT_H
