#include <iostream>
#include "client.h"
#include "server.h"

int main() {
    std::string buf;
    net::server y;
    y.start(3333);
    y.write("dummer huan\n");
    y.read(buf);
    std::cout<< "[RECEIVED]: " << buf << std::endl;
    return 0;
}
