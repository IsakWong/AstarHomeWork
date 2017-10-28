#include <iostream>

#include <QApplication>

#include "Astar.h"
#include "AstarMap.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    /*
    for(auto &p:path)
        cout<<'('<<p->x<<','<<p->y<<')'<<endl;
    */
    return a.exec();
}
