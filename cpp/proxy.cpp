//
// Created by Mario on 18/12/2021.
//
#include "proxy.h"

net::Proxy::Proxy(std::string p2sip, size_t port) {
    std::thread s([&](){proxyserver();});
    std::thread c([&](){proxyclient();});

    s.join();
    c.join();
}

net::Proxy::~Proxy() {
}



void net::Proxy::proxyserver() {
    server.start(port);
    std::thread t1([&](){g2phandler();});

    t1.join();
}

void net::Proxy::proxyclient() {
    client.connect(p2sip,port);
    std::thread t1([&](){p2shandler();});

    t1.join();
}

void net::Proxy::p2shandler() {
    while(client.getclientstatus())
    {
        if(!msgqueue.empty())
        {
            client.write(*msgqueue.begin());
            msgqueue.pop_front();
        }
    }
}

void net::Proxy::g2phandler() {
    std::string message;
    while(server.getserverstatus())
    {
        server.read(message);
        msgqueue.push_back(message);
    }
}
