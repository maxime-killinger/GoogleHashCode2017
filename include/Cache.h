//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_CACHE_H
#define GOOGLEHASHCODE2017_CACHE_H

#include "Video.h"

using namespace std;

class               Cache {
public:
    int             id;
    vector<Video>   videos;
public:
    Cache(int id) : id(id) {}
    virtual ~Cache() {}
};

#endif //GOOGLEHASHCODE2017_CACHE_H
