#include <iostream>
#include "client.h"


int main() {
    std::string buf;
    net::client x;
    x.connect("127.0.0.1",3333);
    x.write("huan");
    x.read(buf);
    std::cout<< "[AUSGABE] " << buf<< std::endl;
    return 0;
}
