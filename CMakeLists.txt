cmake_minimum_required(VERSION 3.6)
project(GoogleHashCode2017)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/hash.h include/Video.h include/Request.h include/Endpoint.h include/Latency.h include/Cache.h)
add_executable(GoogleHashCode2017 ${SOURCE_FILES})