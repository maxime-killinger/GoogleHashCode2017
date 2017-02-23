//
// Created by guillaume on 23/02/17.
//

#ifndef GOOGLEHASHCODE2017_VIDEO_H
#define GOOGLEHASHCODE2017_VIDEO_H

#include <vector>
#include "Request.h"

using namespace std;

class               Video {
private:
    int             id;
    int             size;
    vector<Request> req;
public:
    Video(int size) : size(size) {}
    virtual ~Video() {}
};

#endif //GOOGLEHASHCODE2017_VIDEO_H
