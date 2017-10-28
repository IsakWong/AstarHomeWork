//
// Created by isak on 17-10-8.
//

#ifndef ASTARHOMEWORK_ASTARMAP_H
#define ASTARHOMEWORK_ASTARMAP_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;
typedef vector<vector<int>> MapData;

class AstarMap {
public:
    AstarMap(const string &);
    ~AstarMap();

    const static char CHAR_REACHABLE = ' ';
    const static char CHAR_UNREACHABLE = '*';
    
    int INT_REACHABLE = 0;
    int INT_UNREACHABLE = 1;
    int INT_PATH = 2;


    const int get(int x,int y);

    bool canReach(int x, int y);
    void setValue(int x,int y,int value);



    MapData &getMap() { return mMap; }

    vector<int> &operator[](int index);
    const unsigned long getWidth();

    const unsigned long getHeight();

    void drawMap();

protected:

private:
    
    
    MapData mMap;

};


#endif //ASTARHOMEWORK_ASTARMAP_H
