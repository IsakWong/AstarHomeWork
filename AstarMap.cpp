//
// Created by isak on 17-10-8.
//

#include <sstream>
#include <iostream>
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
        if(lineData.empty())
            break;
        mMap.push_back(lineData);
    }
}


bool AstarMap::canReach(int x, int y) {
    if (mMap[x][y] == INT_REACHABLE) {
        return true;
    } else {
        return false;
    }
}

const unsigned long AstarMap::getWidth() {
    if (!mMap.empty()) {
        return mMap[0].size() -1;
    }
    return 0;

}

const unsigned long AstarMap::getHeight() {

    return mMap.size()-1;
}

const int AstarMap::get(int x, int y) {
    return mMap[y][x];
}

AstarMap::~AstarMap() {
    
}

void AstarMap::drawMap() {

}

void AstarMap::setValue(int x, int y, int value) {
    mMap[x][y] = value;
}

vector<int> &AstarMap::operator[](int index)
{
    return mMap[index];
}
