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
    int                         i = 0;
    int                         idVideo, idEndpoint, nbReq;
    string                      token;
    string                      buff;

    while (getline(file, buff)) {
        istringstream iss(buff);
        i = 0;
        while (getline(iss, token, ' ')) {
            if (i == 0) {
                idVideo = atoi(token.c_str());
            }
            if (i == 1) {
                idEndpoint = atoi(token.c_str());
            }
            if (i == 2) {
                nbReq = atoi(token.c_str());
            }
            i++;
        }
        Request request(idVideo, nbReq, hash.endpoints[idEndpoint]);
        hash.videos[idVideo].req.push_back(request);
    }
}

int getInfos(Hash &hash) {
    ifstream                    file("../GoogleFiles/trending_today.in", ios::in);
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
    getRequests(hash, file);
    int i = 0;
    while (i < hash.nbCaches) {
        Cache   cache(i);
        hash.cache.push_back(cache);
        i++;
    }
    file.close();
    return (0);
}

void myAlgo(Hash &hash) {
    int i = 0;
    int k;
    int j;
    bool full;

    while (i < hash.videos.size()) {
        k = 0;
        while (k < hash.videos[i].req.size()) {
            j = 0;
            full = false;
            while (j < hash.videos[i].req[k].endpoint.nbCache) {
                if (!full && hash.cache[hash.videos[i].req[k].endpoint.cacheLatency[j].idCache].size >= hash.videos[i].size) {
                    hash.cache[hash.videos[i].req[k].endpoint.cacheLatency[j].idCache].videos.push_back(hash.videos[i]);
                    full = true;
                }
                j++;
            }
            k++;
        }
        i++;
    }
}

int main() {
    Hash        hash;
    int i, j;
    ofstream fichier("trendin_today.out", ios::out | ios::trunc);

    getInfos(hash);
    myAlgo(hash);
    fichier << hash.nbCaches << endl;
    i = 0;
    while (i < hash.cache.size()) {
        j = 0;
        fichier << hash.cache[i].id;
        while (j < hash.cache[i].videos.size()) {
            fichier << " ";
            fichier << hash.cache[i].videos[j].id;
            j++;
        }
        fichier << endl;
        i++;
    }
    return (0);
}