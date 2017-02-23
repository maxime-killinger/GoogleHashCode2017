//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_ENDPOINT_H
#define GOOGLEHASHCODE2017_ENDPOINT_H

#include <vector>
#include "Latency.h"

using namespace std;

class           Endpoint {
public:
    int             id;
    int             nbCache;
    int             latency;
    vector<Latency> cacheLatency;
public:
    Endpoint(int id, int latency, int nbCache) : id(id), nbCache(nbCache), latency(latency) {}
    virtual ~Endpoint() {}
};

#endif //GOOGLEHASHCODE2017_ENDPOINT_H
