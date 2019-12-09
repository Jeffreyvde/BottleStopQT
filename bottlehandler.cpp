#include "bottlehandler.h"

BottleHandler::BottleHandler(QObject *parent) : QObject(parent)
{
    connect(DeviceManager::getInstance().getSerialConnection(), SIGNAL(dataReady()), this, SLOT(onDataReceived()));
}

void BottleHandler::onDataReceived()
{
    //qDebug() << data;
    qDebug() << "test";
}
