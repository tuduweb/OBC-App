#include "w_MainWindow.hpp"

#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    qDebug() << "show show show";
}