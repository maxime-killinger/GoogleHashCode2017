//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_REQUEST_H
#define GOOGLEHASHCODE2017_REQUEST_H

#include "Endpoint.h"

class           Request {
public:
    int         videoId;
    int         nbRequest;
    Endpoint    endpoint;
public:
    Request(int nbRequest, Endpoint &endpoint) : nbRequest(nbRequest), endpoint(endpoint) {}
    virtual ~Request() {}
};

#endif //GOOGLEHASHCODE2017_REQUEST_H
