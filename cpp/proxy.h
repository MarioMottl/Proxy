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

        inline static server server;
        inline static client client;
        inline static std::string p2sip;
        inline static uint16_t port;
        inline static std::deque<std::string> g2smsgqueue;
        inline static std::deque<std::string> s2gmsgqueue;
        static void p2swritehandler();
        static void g2preadhandler();
        static void p2sreadhandler();
        static void g2pwritehandler();

    public:
        Proxy(std::string ip, size_t port);
        ~Proxy();
        static void proxyserver();
        static void proxyclient();

    };
}

#endif //PROXY_PROXY_H
