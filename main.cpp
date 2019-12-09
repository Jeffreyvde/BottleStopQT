#include <QApplication>
#include <wiringPi.h>
#include "mainwindow.h"
#include "bottlehandler.h"
#include "devicemanager.h"

BottleHandler* bottle;

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

    wiringPiSetup();

    MainWindow w;
    w.show();
    bottle = new BottleHandler();

    return a.exec();
}


