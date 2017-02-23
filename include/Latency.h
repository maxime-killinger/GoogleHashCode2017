//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_LATENCY_H
#define GOOGLEHASHCODE2017_LATENCY_H

class           Latency {
private:
    int         idCache;
    int         latency;
public:
    Latency(int idCache, int latency) : idCache(idCache), latency(latency) {}
    virtual ~Latency() {}

    int getIdCache() const {
        return idCache;
    }

    int getLatency() const {
        return latency;
    }
};

#endif //GOOGLEHASHCODE2017_LATENCY_H
