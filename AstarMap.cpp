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
            lineData.push_back(int(INT_REACHABLE));
        }
        mMap.push_back(lineData);
    }
    for(int i = 0;i<width;i++){
        mMap[0][i] = INT_UNREACHABLE;
        mMap[height-1][i] = INT_UNREACHABLE;
    }
    for(int j = 0;j<height;j++)
    {
        mMap[j][0] = INT_UNREACHABLE;
        mMap[j][height-1] = INT_UNREACHABLE;
    }
    createMaze(1,1,width-2,height-2);
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

void AstarMap::createMaze(int x, int y, int width, int height)
{
    int xPos, yPos;

            if (height <= 2 || width <= 2)
                return;

            //横着画线，在偶数位置画线
            xPos=y+1+qrand()%(height-1);
            for (int i = x; i < x + width; i++) {
                //mMap[xPos][i] = INT_UNREACHABLE;
            }

            //竖着画一条线，在偶数位置画线
            yPos=x+qrand()%(width-1);
            for (int i = y; i < y + height; i++) {
                //mMap[i][yPos] = INT_UNREACHABLE;
            }

            //随机开三扇门，左侧墙壁为1，逆时针旋转
            int isClosed = qrand()%4;
            switch (isClosed)
            {
            case 0:
                openAdoor(xPos + 1, yPos, x + height - 1, yPos);// 2
                openAdoor(xPos, yPos + 1, xPos, y + width - 1);// 3
                openAdoor(x, yPos, xPos - 1, yPos);// 4
                break;
            case 1:
                openAdoor(xPos, yPos + 1, xPos, y + width - 1);// 3
                openAdoor(x, yPos, xPos - 1, yPos);// 4
                openAdoor(xPos, y, xPos, yPos - 1);// 1
                break;
            case 2:
                openAdoor(x, yPos, xPos - 1, yPos);// 4
                openAdoor(xPos, y, xPos, yPos - 1);// 1
                openAdoor(xPos + 1, yPos, x + height - 1, yPos);// 2
                break;
            case 3:
                openAdoor(xPos, y, xPos, yPos - 1);// 1
                openAdoor(xPos + 1, yPos, x + height - 1, yPos);// 2
                openAdoor(xPos, yPos + 1, xPos, y + width - 1);// 3
                break;
            default:
                break;
            }

            // 左上角
            createMaze(x, y, xPos - x, yPos - y);
            // 右上角
            createMaze(x, yPos + 1, xPos - x, width - yPos + y - 1);
            // 左下角
            createMaze(xPos + 1, y, height - xPos + x - 1, yPos - y);
            // 右下角
            createMaze(xPos + 1, yPos + 1, height - xPos + x - 1, width - yPos + y - 1);
}
