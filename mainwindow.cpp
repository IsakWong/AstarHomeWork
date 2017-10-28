#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new AstarMap("map.txt");
    astar.InitAstar(*map);
    //设置起始和结束点
    Point start(1,1);
    Point end(5,1);
    //A*算法找寻路径
    list<Point *> path=astar.GetPath(start,end,false);

    AstarMap newMap(*map);
    for(auto o : path){
            newMap.setValue(o->x,o->y,map->INT_PATH);
    }
    setGeometry(-1,-1,20*map->getWidth(),20*map->getHeight());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);



    int iTitleBarHeight = style()->pixelMetric(QStyle::PM_TitleBarHeight);
    painter.setPen(QPen(QColor(255,255,255),0,Qt::PenStyle::NoPen));
    for(int i = 0;i<map->getWidth();i++){
        for(int j = 0;j<map->getHeight();j++){
            if(map->get(i,j) == map->INT_UNREACHABLE)
            {
                painter.setBrush(QColor(100,100,100));
            }
            if(map->get(i,j) == map->INT_REACHABLE){

                painter.setBrush(QColor(255,255,255));
            }
            painter.drawRect(10*i,iTitleBarHeight+10*j,10,10);
        }
    }
    int max = 0;
    int min = 10000;
    for(Point* data:astar.closeList){
        if(data->F>max){
            max = data->F;
        }else
        {
            if(data->F<min){
                min = data->F;
            }
        }
    }
    int range = max-min;
    for(Point* data:astar.closeList){
        float i = (float)(max - data->F)/(float)range;
        painter.setBrush(QColor(255,255*i,255));
        if(map->get(data->x,data->y)==map->INT_REACHABLE){
            painter.drawRect(10*data->x,iTitleBarHeight+10*data->y,10,10);
        }
    }
    painter.setBrush(QColor(1,119,214));
    painter.drawRect(astar.startPoint.x*10,iTitleBarHeight+astar.startPoint.y*10,10,10);
    painter.setBrush(QColor(119,119,214));
    painter.drawRect(astar.endPoint.x*10,iTitleBarHeight+astar.endPoint.y*10,10,10);

}
