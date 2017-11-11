#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    start(1,1),
    end(5,14),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new AstarMap(30,30);
    astar.InitAstar(map->getMap());
    //设置起始和结束点
    path=astar.GetPath(start,end,false);

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
    int max = astar.closeList.front()->F;
    int min = astar.closeList.front()->F;
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
        float i = (float)(data->F - min)/(float)range;
        int col = i *255;
        QColor color(1,119,214,col);
        painter.setBrush(color);
        int x = data->x;
        int y = data->y;
        if(map->get(x,y)==AstarMap::INT_REACHABLE)
            painter.drawRect(10*x,iTitleBarHeight+10*y,10,10);

    }
    /*
    for(Point*data:path){
        painter.setBrush(QColor(255,150,150));
        int x = data->x;
        int y = data->y;
        painter.drawRect(10*x,iTitleBarHeight+10*y,10,10);
    }*/

}
