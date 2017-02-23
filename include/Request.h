//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_REQUEST_H
#define GOOGLEHASHCODE2017_REQUEST_H

#include "Endpoint.h"

class           Request {
private:
    int         videoId;
    int         nbRequest;
    Endpoint    endpoint;
public:
    Request(int nbRequest, Endpoint &endpoint) : nbRequest(nbRequest), endpoint(endpoint) {}
    virtual ~Request() {}

    int getVideoId() const {
        return videoId;
    }

    int getNbRequest() const {
        return nbRequest;
    }

    Endpoint &getEndpoint() const {
        return endpoint;
    }
};

#endif //GOOGLEHASHCODE2017_REQUEST_H
