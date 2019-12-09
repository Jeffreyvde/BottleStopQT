#include <QApplication>
#include <wiringPi.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

    wiringPiSetup();

    MainWindow w;
    w.show();

    return a.exec();
}


