#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    start(0,0),
    end(1,1),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new AstarMap(30,30);
    astar.InitAstar(map->getMap());
    path=astar.GetPath(start,end,false);
    //设置起始和结束点
    timer= new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(xytimerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->setInterval(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);



    int leftDelta = ui->pushButton->geometry().left();
    int iTitleBarHeight = ui->pushButton->geometry().bottom() + style()->pixelMetric(QStyle::PM_TitleBarHeight);
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
            painter.drawRect(leftDelta+10*i,iTitleBarHeight+10*j,10,10);
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
    int closeSize = 0;
    for(Point* data:astar.closeList){
        closeSize++;
        float i = (float)(data->F - min)/(float)range;
        int col = i *255;
        QColor color(1,119,214,col);
        painter.setBrush(color);
        int x = data->x;
        int y = data->y;
        if(map->get(x,y)==AstarMap::INT_REACHABLE)
            painter.drawRect(leftDelta+10*x,iTitleBarHeight+10*y,10,10);
        if(closeSize >size){

            return ;
        }
    }
    for(Point*data:path){
        painter.setBrush(QColor(255,150,150));
        int x = data->x;
        int y = data->y;
        painter.drawRect(leftDelta+10*x,iTitleBarHeight+10*y,10,10);
    }


}

void MainWindow::on_pushButton_clicked(bool checked)
{
    int startX = ui->startX->toPlainText().toInt();
    int startY = ui->startY->toPlainText().toInt();
    int endX = ui->endX->toPlainText().toInt();
    int endY = ui->endY->toPlainText().toInt();
    start.x = startX;
    start.y = startY;
    end.x = endX;
    end.y = endY;
    if(map->canReach(endX,endY)){

        path=astar.GetPath(start,end,false);
        size = 0;

        timer->start();
    }else{

    }
}

void MainWindow::xytimerUpDate()
{
    size++;
    this->update();
}
