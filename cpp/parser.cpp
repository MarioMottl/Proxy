//
// Created by Mario on 24/12/2021.
//

#include "parser.h"

void net::output(uint16_t port, char in, std::string& data)
{
    switch(in)
    {
        case 's':
            std::cout << "Game -> Server [" << port<< "]: " << data << std::endl;
            break;
        case 'c':
            std::cout << "Game <- Server [" << port<< "]: " << data << std::endl;
            break;
        default:
            std::cout <<" Unknown direction [" << port<< "]: " << data << std::endl;
            break;
    }
}
