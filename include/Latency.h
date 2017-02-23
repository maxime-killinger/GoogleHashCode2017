//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_LATENCY_H
#define GOOGLEHASHCODE2017_LATENCY_H

class           Latency {
public:
    int         idCache;
    int         latency;
public:
    Latency(int idCache, int latency) : idCache(idCache), latency(latency) {}
    virtual ~Latency() {}
};

#endif //GOOGLEHASHCODE2017_LATENCY_H
