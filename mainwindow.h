#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Astar.h"
#include "AstarMap.h"
#include <QPainter>
#include <QApplication>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent* event);
    int size = 0;
    QTimer* timer ;

private slots:
    void on_pushButton_clicked(bool checked);
    void xytimerUpDate();

private:
    AstarMap* map;
    Ui::MainWindow *ui;
    Astar astar;
    Point start;
    Point end;
    //A*算法找寻路径
    list<Point *> path;

};

#endif // MAINWINDOW_H
