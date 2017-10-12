//
// Created by isak on 17-10-8.
//

#include <sstream>
#include <iostream>
#include <afxres.h>
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


bool AstarMap::canReach(int x, int y) {
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

void AstarMap::drawMap() {
    HANDLE hOut;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    for(const auto & row : mMap){
        for(auto col : row){
            if(col == INT_UNREACHABLE){
                SetConsoleTextAttribute(hOut,FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE );
                cout<<'o';
            }else{
                if(col == INT_PATH){
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED);
                    cout<<'+';
                }else{
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE );
                    cout<<' ';
                }
            }

        }
        cout<<endl;
    }
}

void AstarMap::setValue(int x, int y, int value) {
    mMap[x][y] = value;
}
