#include <iostream>
#include <fstream>
#include <sstream>
#include "include/hash.h"

using namespace std;

void getFirstLine(Hash &hash, string buff) {
    int                         i = 0;
    string                      token;

    istringstream               iss(buff);
    while (getline(iss, token, ' '))
    {
        if (i == 0)
            hash.nbVideos = atoi(token.c_str());
        if (i == 1)
            hash.nbEndpoints = atoi(token.c_str());
        if (i == 2)
            hash.nbRequests = atoi(token.c_str());
        if (i == 3)
            hash.nbCaches = atoi(token.c_str());
        if (i == 4)
            hash.cacheCapacity = atoi(token.c_str());
        i++;
    }
}

void    getVideos(Hash &hash, string buff) {
    int                         i = 0;
    string                      token;

    istringstream               iss(buff);
    while (getline(iss, token, ' '))
    {
        Video   video(i, atoi(token.c_str()));
        hash.videos.push_back(video);
        i++;
    }
}

void    getCacheLatency(Endpoint &endpoint, ifstream &file) {
    int                         k = 0;
    int                         lat, idCache, i;
    string                      token;
    string                      buff;

    while (k < endpoint.nbCache) {
        getline(file, buff);
        istringstream iss(buff);
        i = 0;
        while (getline(iss, token, ' ')) {
            if (i == 0) {
                idCache = atoi(token.c_str());
            }
            if (i == 1) {
                lat = atoi(token.c_str());
            }
            i++;
        }
        Latency     latency(idCache, lat);
        endpoint.cacheLatency.push_back(latency);
        k++;
    }
}

void    getEndpoints(Hash &hash, ifstream &file) {
    int                         k = 0;
    int                         latency, nbCache, i;
    string                      token;
    string                      buff;

    while (k < hash.nbEndpoints) {
        getline(file, buff);
        istringstream iss(buff);
        i = 0;
        while (getline(iss, token, ' ')) {
            if (i == 0) {
                latency = atoi(token.c_str());
            }
            if (i == 1) {
                nbCache = atoi(token.c_str());
            }
            i++;
        }
        Endpoint    endpoint(k, latency, nbCache);
        getCacheLatency(endpoint, file);
        hash.endpoints.push_back(endpoint);
        k++;
    }
}

void    getRequests(Hash &hash, ifstream &file) {
    int                         k = 0;
    int                         latency, nbCache, i;
    string                      token;
    string                      buff;

    while (k < hash.nbEndpoints) {
        getline(file, buff);
        istringstream iss(buff);
        i = 0;
        while (getline(iss, token, ' ')) {
            if (i == 0) {
                latency = atoi(token.c_str());
            }
            if (i == 1) {
                nbCache = atoi(token.c_str());
            }
            i++;
        }
        Endpoint    endpoint(k, latency, nbCache);
        getCacheLatency(endpoint, file);
        hash.endpoints.push_back(endpoint);
        k++;
    }
}

int getInfos(Hash &hash) {
    ifstream                    file("../GoogleFiles/kittens.in", ios::in);
    string                      buff;

    if (!file) {
        cout << "Error opening file" << endl;
        return (1);
    }
    getline(file, buff);
    getFirstLine(hash, buff);
    getline(file, buff);
    getVideos(hash, buff);
    getEndpoints(hash, file);
    //getRequests(hash, file);
    file.close();
    return (0);
}

int main() {
    Hash        hash;

    getInfos(hash);
    cout << hash.cacheCapacity << endl;
    cout << hash.videos[1].id << ": " << hash.videos[1].size << " mb" << endl;
    cout << hash.endpoints[0].latency << " " << hash.endpoints[0].nbCache << endl;
    cout << hash.endpoints[0].cacheLatency[0].idCache << " " << hash.endpoints[0].cacheLatency[0].latency << endl;
    return (0);
}