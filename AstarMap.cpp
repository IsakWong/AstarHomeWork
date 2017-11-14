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
                lineData.push_back(int(INT_REACHABLE));
            else 
                lineData.push_back(int(INT_UNREACHABLE));
            p++;
        }
        if(lineData.empty()){

        }else
        {
            mMap.push_back(lineData);
        }
    }

}

AstarMap::AstarMap(int width, int height)
{
    qsrand(1);
    for(int j = 0;j<height;j++)
    {
        vector<int> lineData;
        for(int i = 0;i<width;i++)
        {
            lineData.push_back(int(INT_UNREACHABLE));
        }
        mMap.push_back(lineData);
    }
    
    createMaze(0, 0, width, height);
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
    return mMap[y][x];
}

AstarMap::~AstarMap() {
    
}

void AstarMap::drawMap() {

}

void AstarMap::setValue(int x, int y, int value) {
    mMap[x][y] = value;
}

void AstarMap::openAdoor(int x1, int y1, int x2, int y2)
{
    int pos;
           if (x1 == x2) {
               pos = y1 + int((y2 - y1 )/2+ 1)*2;//在奇数位置开门
               mMap[x1][pos] = INT_REACHABLE;
           } else if (y1 == y2) {
               pos = x1 + int((x2 - x1 )/2+ 1)*2;
               mMap[pos][y1] = INT_REACHABLE;
           } else {

           }
}

void AstarMap::createMaze(size_t Xlefttop, size_t Ylefttop, size_t length, size_t width)
{
    if(length < 0 || width < 0)
        return;
    if(length <= 2 || width <= 2){
        for(int x = Xlefttop; x < Xlefttop + length; ++x){
            for(int y = Ylefttop; y < Ylefttop + width; ++y){
                setValue(x, y, INT_REACHABLE);
            }
        }
    }else{
        size_t Xwall = Xlefttop + length / 2 - 1;
        size_t lenSquareLeft = length/2;
        size_t lenSquareRight = length - lenSquareLeft;
        size_t Ywall = Ylefttop + width / 2 - 1;
        size_t widSquareUp = width / 2;
        size_t widSquareDown = width - widSquareUp;
         
        
        if(widSquareUp > 2){
            setValue(Xwall, Ylefttop + widSquareUp / 2, INT_REACHABLE)
        }else{
            setValue(Xwall, Ylefttop, INT_REACHABLE)
        }
        if(widSquareDown > 2){
            setValue(Xwall, Ylefttop + widSquareUp + widSquareDown / 2, INT_REACHABLE)
        }else{
            setValue(Xwall, int y, Ylefttop + widSquareUp)
        }
        if(lenSquareLeft > 2){
            setValue(Xlefttop + lenSquareLeft / 2, Ywall, INT_REACHABLE);
        }else{
            setValue(Xlefttop, Ywall, INT_REACHABLE);
        }
        if(lenSquareRight > 2){
            setValue(Xlefttop + lenSquareLeft + lenSquareRight / 2, Ywall, INT_REACHABLE);
        }else{
            setValue(Xlefttop + lenSquareLeft, Ywall, INT_REACHABLE);
        }
                
        createMaze(Xlefttop, Ylefttop, lenSquareLeft-1, widSquareUp-1);
        createMaze(Xlefttop + lenSquareLeft, Ylefttop, lenSquareRight, widSquareUp-1);
        createMaze(Xlefttop, Ylefttop + widSquareUp, lenSquareLeft-1, widSquareDown);
        createMaze(Xlefttop + lenSquareLeft, Ylefttop + widSquareUp, lenSquareRight, widSquareDown);
    }
}
