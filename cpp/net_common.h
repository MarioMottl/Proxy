//
// Created by Mario on 19/12/2021.
//

#ifndef PROXY_NET_COMMON_H
#define PROXY_NET_COMMON_H

#pragma once

#include <memory>
#include <thread>
#include <mutex>
#include <deque>
#include <optional>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdint>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>
#include <boost/array.hpp>

#endif //PROXY_NET_COMMON_H
