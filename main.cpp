#include <QApplication>
#include "mainwindow.h"
#include "RFID/bottlehandler.h"
#include "devicemanager.h"
#include "uimanager.h"

#ifdef __arm__
    #include <wiringPi.h>
#endif

BottleHandler* bottle;
UIManager* manager;

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

#ifdef __arm__
    wiringPiSetup();
#endif

    bottle = new BottleHandler();
    DeviceManager::getInstance().initializeDevice();
    manager = new UIManager();
    return a.exec();
}


