//
// Created by Mario on 18/12/2021.
//

#ifndef PROXY_PROXY_H
#define PROXY_PROXY_H

#include "net_common.h"

#include "server.h"
#include "client.h"

namespace net{

    /*
    Class: Class for proxy
    Description: Proxy
    */
    class Proxy{
    private:

        inline static server server;
        inline static client client;
        //Real gameserver ip address
        inline static std::string p2sip;
        //game communication port
        inline static uint16_t port;

        /*
        Messagequeue for the communication
            client -> server
        */
        inline static std::deque<std::string> g2smsgqueue;

        /*
        Messagequeue for the communication
            client <- server
        */
        inline static std::deque<std::string> s2gmsgqueue;

        /*
        Read/write handler for the communication
            client -> server
            client <- server
        */
        static void p2swritehandler();
        static void g2preadhandler();
        static void p2sreadhandler();
        static void g2pwritehandler();

        /*
        Thread function to start server / client
        */
        static void proxyserver();
        static void proxyclient();

    public:

        /*
        Function : Proxy(std::string ip, size_t port)
        Description: starts TCP server/client on provided port / ip
            client -> server = g2smsgqueue
            client <- server = s2gmsgqueue
        */
        Proxy(std::string ip, size_t port);


        ~Proxy();

    };
}

#endif //PROXY_PROXY_H
