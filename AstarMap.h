//
// Created by isak on 17-10-8.
//

#ifndef ASTARHOMEWORK_ASTARMAP_H
#define ASTARHOMEWORK_ASTARMAP_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;
typedef vector<vector<char> *> MapData;

class AstarMap {
public:
    AstarMap(const string &);
    ~AstarMap();

    const static char REACHABLE = ' ';
    const static char UNREACHABLE = '*';


    const char get(int x,int y);

    const bool canReach(int x, int y);


    MapData &getMap() { return mMap; }

    const unsigned long getWidth();

    const unsigned long getHeight();

protected:

private:
    MapData mMap;

};


#endif //ASTARHOMEWORK_ASTARMAP_H
