//
// Created by Mario on 18/12/2021.
//

#ifndef PROXY_PROXY_H
#define PROXY_PROXY_H

#include "net_common.h"

#include "server.h"
#include "client.h"

namespace net{


    class Proxy{
    private:

        static server server;
        static client client;
        static std::string p2sip;
        static uint16_t port;
        static std::deque<std::string> msgqueue;
        static void p2shandler();
        static void g2phandler();

    public:
        Proxy(std::string p2sip, size_t port);
        ~Proxy();
        static void proxyserver();
        static void proxyclient();

    };
}

#endif //PROXY_PROXY_H
