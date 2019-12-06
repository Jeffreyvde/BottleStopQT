#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include "mainwindow.h"
#include "serialwrapper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


