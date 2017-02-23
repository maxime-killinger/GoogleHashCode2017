//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_HASH_H
#define GOOGLEHASHCODE2017_HASH_H

#include <vector>
#include "Video.h"
#include "Cache.h"

using namespace std;

class                   Hash {
public:
    int                 cacheCapacity;
    vector<Video>       videos;
    vector<Cache>       cache;
    vector<Endpoint>    endpoints;
public:
    Hash() {}
    virtual ~Hash() {}

};

#endif //GOOGLEHASHCODE2017_HASH_H
