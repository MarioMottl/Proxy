//
// Created by Mario on 18/12/2021.
//
#include "proxy.h"

net::Proxy::Proxy(std::string ip, size_t port) {
    this->p2sip = ip;
    this->port = port;
    std::thread s([&](){proxyserver();});
    std::thread c([&](){proxyclient();});

    s.join();
    c.join();
}

net::Proxy::~Proxy() {
}



void net::Proxy::proxyserver() {
    server.start(port);
    std::thread t1([&](){g2preadhandler();});
    std::thread t2([&](){g2pwritehandler();});
    t1.join();
    t2.join();
}

void net::Proxy::proxyclient() {
    client.connect(p2sip,port);
    std::thread t1([&](){p2swritehandler();});
    std::thread t2([&](){p2sreadhandler();});
    t1.join();
    t2.join();
}

void net::Proxy::p2swritehandler() {
    while(client.getclientstatus()) {
        if (!g2smsgqueue.empty())
        {
            client.write(*g2smsgqueue.begin());
            g2smsgqueue.pop_front();
        }
    }
}

void net::Proxy::g2preadhandler() {
    std::string message;
    while(server.getserverstatus())
    {
        server.read(message);
        output(server.getport(),'s',message);
        g2smsgqueue.push_back(message);
    }
}

void net::Proxy::p2sreadhandler() {
    std::string message;
    while(client.getclientstatus())
    {
        client.read(message);
        output(client.getport(),'c',message);
        s2gmsgqueue.push_back(message);
    }
}

void net::Proxy::g2pwritehandler() {
    while(server.getserverstatus())
    {
        if(!s2gmsgqueue.empty())
        {
            server.write(*s2gmsgqueue.begin());
            s2gmsgqueue.pop_front();
        }
    }
}
