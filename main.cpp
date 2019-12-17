#include <QApplication>
#include "mainwindow.h"
#include "RFID/bottlehandler.h"
#include "devicemanager.h"

#ifdef __arm__
    #include <wiringPi.h>
#endif

BottleHandler* bottle;

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

#ifdef __arm__
    wiringPiSetup();
#endif

    MainWindow w;
    w.show();
    bottle = new BottleHandler();

    return a.exec();
}


