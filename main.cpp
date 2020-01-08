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

    bottle = new BottleHandler();
    DeviceManager::getInstance().initializeDevice();
    MainWindow w;
    w.show();

    return a.exec();
}


