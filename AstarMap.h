//
// Created by isak on 17-10-8.
//

#ifndef ASTARHOMEWORK_ASTARMAP_H
#define ASTARHOMEWORK_ASTARMAP_H

#include <string>
#include <fstream>
#include <vector>
#include <QtGlobal>
#include <QTime>

using namespace std;
typedef vector<vector<int>> MapData;

class AstarMap {
public:
    AstarMap(const string &);
    AstarMap(int width,int height);
    ~AstarMap();

    const static char CHAR_REACHABLE = ' ';
    const static char CHAR_UNREACHABLE = '*';
    
    const static int INT_REACHABLE = 0;
    const static int INT_UNREACHABLE = 1;
    const static int INT_PATH = 2;


    const int get(int x,int y);

    bool canReach(int x, int y);
    void setValue(int x,int y,int value);


    void openAdoor(int x1,int y1,int x2,int y2);

    void createMaze(int x,int y,int width,int height);

    MapData &getMap() { return mMap; }

    const unsigned long getWidth();

    const unsigned long getHeight();

    void drawMap();

protected:

private:
    
    
    MapData mMap;

};


#endif //ASTARHOMEWORK_ASTARMAP_H
