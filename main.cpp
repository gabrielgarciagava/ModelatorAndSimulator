#include <QtGui/QApplication>
#include "Mainwindow.h"
#include <tempo.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
