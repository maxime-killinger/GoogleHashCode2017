#include <iostream>
#include <fstream>
#include <sstream>
#include "include/Hash.h"

#define PATH_FILE_IN "./GoogleFiles/trending_today.in"
#define PATH_FILE_OUT "./trending_today.out"

using namespace std;

void                            getFirstLine(Hash &hash, string buff) {
    string                      token;
    istringstream               iss(buff);

    for (int i = 0; getline(iss, token, ' '); i++)
        (i == 0) ? hash.nbVideos = atoi(token.c_str()) :
        (i == 1) ? hash.nbEndpoints = atoi(token.c_str()) :
        (i == 2) ? hash.nbRequests = atoi(token.c_str()) :
        (i == 3) ? hash.nbCaches = atoi(token.c_str()) :
        (i == 4) ? hash.cacheCapacity = atoi(token.c_str()) : 0;
}

void                            getVideos(Hash &hash, string buff) {
    string                      token;
    istringstream               iss(buff);

    for (int i = 0; getline(iss, token, ' '); i++) {
        Video                   video(i, atoi(token.c_str()));

        hash.videos.push_back(video);
    }
}

void                            getCacheLatency(Endpoint &endpoint, ifstream &file) {
    int                         lat, idCache;
    string                      token;
    string                      buff;

    for (int k = 0; k < endpoint.nbCache; k++) {
        getline(file, buff);
        istringstream           iss(buff);

        for (int i = 0; getline(iss, token, ' '); i++)
            (i == 0) ? idCache = atoi(token.c_str()) :
            (i == 1) ? lat = atoi(token.c_str()) : 0;

        Latency                 latency(idCache, lat);
        endpoint.cacheLatency.push_back(latency);
    }
}

void                            getEndpoints(Hash &hash, ifstream &file) {
    int                         latency, nbCache;
    string                      token;
    string                      buff;

    for (int k = 0; k < hash.nbEndpoints; k++) {
        getline(file, buff);
        istringstream           iss(buff);

        for (int i = 0; getline(iss, token, ' '); i++)
            (i == 0) ? latency = atoi(token.c_str()) :
            (i == 1) ? nbCache = atoi(token.c_str()) : 0;

        Endpoint                endpoint(k, latency, nbCache);

        getCacheLatency(endpoint, file);
        hash.endpoints.push_back(endpoint);
    }
}

void    getRequests(Hash &hash, ifstream &file) {
    int                         idVideo, idEndpoint, nbReq;
    string                      token;
    string                      buff;

    while (getline(file, buff)) {
        istringstream           iss(buff);

        for (int i = 0; getline(iss, token, ' '); i++)
            (i == 0) ? idVideo = atoi(token.c_str()) :
            (i == 1) ? idEndpoint = atoi(token.c_str()) :
            (i == 2) ? nbReq = atoi(token.c_str()) : 0;

        Request                 request(idVideo, nbReq, hash.endpoints[idEndpoint]);

        hash.videos[idVideo].req.push_back(request);
    }
}

int                             getInfos(Hash &hash) {
    ifstream                    file(PATH_FILE_IN, ios::in);
    string                      buff;

    if (!file) {
        cout << "Error opening file" << endl;
        return (-1);
    }

    getline(file, buff);
    getFirstLine(hash, buff);
    getline(file, buff);
    getVideos(hash, buff);
    getEndpoints(hash, file);
    getRequests(hash, file);

    for (int i = 0; i < hash.nbCaches; i++) {
        Cache                   cache(i);

        hash.cache.push_back(cache);
    }

    file.close();
    return (0);
}

void                            myAlgo(Hash &hash) {

    for (int i = 0; i < hash.videos.size(); i++) {

        for (int k = 0; k < hash.videos[i].req.size(); k++) {
            bool                full = false;

            for (int j = 0; j < hash.videos[i].req[k].endpoint.nbCache; j++) {

                if (!full && hash.cache[hash.videos[i].req[k].endpoint.cacheLatency[j].idCache].size >= hash.videos[i].size) {
                    hash.cache[hash.videos[i].req[k].endpoint.cacheLatency[j].idCache].videos.push_back(hash.videos[i]);
                    full = true;
                }
            }
        }
    }
}

void                            display(Hash hash)
{
    ofstream                    file(PATH_FILE_OUT, ios::out | ios::trunc);

    file << hash.nbCaches << endl;

    for (int i = 0; i < hash.cache.size(); i++) {
        file << hash.cache[i].id;

        for (int j = 0; j < hash.cache[i].videos.size(); j++)
            file << " " << hash.cache[i].videos[j].id;

        file << endl;
    }
}

int                             main() {
    Hash                        hash;

    getInfos(hash);
    myAlgo(hash);
    display(hash);
    return (0);
}
