#include <iostream>
#include "Astar.h"
#include "AstarMap.h"
using namespace std;

int main()
{
    //初始化地图，用二维矩阵代表地图，1表示障碍物，0表示可通
    /*vector<vector<int>> maze={
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,1,0,1,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,1,1,1},
        {1,1,1,0,0,0,0,0,1,1,0,1},
        {1,1,0,1,0,0,0,0,0,0,0,1},
        {1,0,1,0,0,0,0,1,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
    };*/
    
    AstarMap map("map.txt");
    
    Astar astar;
    astar.InitAstar(map.getMap());
    
    //设置起始和结束点
    Point start(1,1);
    Point end(4,14);
    //A*算法找寻路径
    list<Point *> path=astar.GetPath(start,end,false);
    //打印原始地图
    MapData &oldMap = map.getMap();

    for(const auto & row : oldMap){
        for(auto col : row){
            if(col == map.INT_UNREACHABLE){
                cout<<'o';
            }else
                cout<<' ';
        }
        cout<<endl;
    }
    for(auto o : path){
        map.getMap()[o->x][o->y] = '2';
        for(const auto & row : oldMap){
            for(auto col : row){
                if(col == map.INT_UNREACHABLE){
                    cout<<'o';
                }else{
                    if(col == '2'){
                        cout<<'+';
                    }else{
                        cout<<' ';
                    }
                }

            }
            cout<<endl;
        }
        _sleep(300);
        system("cls");

    }

    //保存路径
    //打印
    for(auto &p:path)
        cout<<'('<<p->x<<','<<p->y<<')'<<endl;
    
    system("pause");
    return 0;
}
