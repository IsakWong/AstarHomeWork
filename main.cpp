#include <iostream>
#include <afxres.h>
#include "Astar.h"
#include "AstarMap.h"

using namespace std;

int main()
{

    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    AstarMap map("map.txt");
    Astar astar;
    astar.InitAstar(map.getMap());
    
    //设置起始和结束点
    Point start(1,1);
    Point end(4,14);
    //A*算法找寻路径
    list<Point *> path=astar.GetPath(start,end,false);
    //打印原始地图

    map.drawMap();

    AstarMap newMap(map);
    for(auto o : path){
        system("cls");
        newMap.setValue(o->x,o->y,map.INT_PATH);
        newMap.drawMap();
        _sleep(300);
    }

    /*
    for(auto &p:path)
        cout<<'('<<p->x<<','<<p->y<<')'<<endl;
    */
    system("pause");
    return 0;
}
