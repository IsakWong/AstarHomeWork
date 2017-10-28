#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Astar.h"
#include "AstarMap.h"
#include <QPainter>
#include <QApplication>

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

private:
    AstarMap* map;
    Ui::MainWindow *ui;
    Astar astar;

};

#endif // MAINWINDOW_H
