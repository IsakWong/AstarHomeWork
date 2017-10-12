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
        vector<int> lineData;
        char *p = buffer;
        while (*p) {
            if(*p == CHAR_REACHABLE)
                lineData.push_back(INT_REACHABLE);
            else 
                lineData.push_back(INT_UNREACHABLE);
            p++;
        }
        mMap.push_back(lineData);
    }

}


const bool AstarMap::canReach(int x, int y) {
    if (mMap[x][y] == INT_REACHABLE) {
        return true;
    } else {
        return false;
    }
}

const unsigned long AstarMap::getWidth() {
    if (!mMap.empty()) {
        return mMap[0].size();
    }
    return 0;

}

const unsigned long AstarMap::getHeight() {

    return mMap.size();
}

const int AstarMap::get(int x, int y) {
    return mMap[x][y];
}

AstarMap::~AstarMap() {
    
}
