//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_ENDPOINT_H
#define GOOGLEHASHCODE2017_ENDPOINT_H

#include <vector>
#include "Latency.h"

using namespace std;

class           Endpoint {
private:
    int             id;
    int             nbCache;
    int             latency;
    vector<Latency> cacheLatency;
public:
    Endpoint(int id, int nbCache, int latency) : id(id), nbCache(nbCache), latency(latency) {}
    virtual ~Endpoint() {}

    int getId() const {
        return id;
    }

    int getNbCache() const {
        return nbCache;
    }

    int getLatency() const {
        return latency;
    }

    vector<Latency> &getCacheLatency() const {
        return cacheLatency;
    }
};

#endif //GOOGLEHASHCODE2017_ENDPOINT_H
