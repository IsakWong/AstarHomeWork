//
// Created by isak on 17-10-8.
//

#include <sstream>
#include "AstarMap.h"

AstarMap::AstarMap(const string &mapPath) {
    fstream inputMap(mapPath, ios::in);
    char buffer[256];
    while (!inputMap.eof()) {
        inputMap.getline(buffer, 256);
        vector<char> *lineData = new vector<char>();
        char *p = buffer;
        int i = 10;
        while (*p) {
            lineData->push_back(*p);
            p++;
        }
        mMap.push_back(lineData);
    }

}


const bool AstarMap::canReach(int x, int y) {
    if (mMap[x]->operator[](y) == REACHABLE) {
        return true;
    } else {
        return false;
    }
}

const unsigned long AstarMap::getWidth() {
    if (!mMap.empty()) {
        return mMap[0]->size();
    }
    return 0;

}

const unsigned long AstarMap::getHeight() {

    return mMap.size();
}

const char AstarMap::get(int x, int y) {
    return mMap.operator[](x)->operator[](y);
}

AstarMap::~AstarMap() {
    for(int i =0;i<mMap.size();i++){
        delete mMap[i];
    }
}
