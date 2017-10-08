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
    
    const static int INT_REACHABLE = 0;
    const static int INT_UNREACHABLE = 1;     


    const int get(int x,int y);

    const bool canReach(int x, int y);


    MapData &getMap() { return mMap; }

    const unsigned long getWidth();

    const unsigned long getHeight();

protected:

private:
    
    
    MapData mMap;

};


#endif //ASTARHOMEWORK_ASTARMAP_H
