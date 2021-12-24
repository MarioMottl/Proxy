cmake_minimum_required(VERSION 3.21)
project(Proxy)

set(CMAKE_CXX_STANDARD 20)
include_directories(C:\\boost_1_78_0)
link_directories( C:\\boost_1_78_0\\stage\\lib)
add_executable(Proxy main.cpp server.cpp client.cpp server.h client.h proxy.h proxy.cpp net_common.h parser.h parser.cpp)
