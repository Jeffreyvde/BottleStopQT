#include "bottlehandler.h"

BottleHandler::BottleHandler(QObject *parent) : QObject(parent)
{
    connect(DeviceManager::getInstance().getSerialConnection(), SIGNAL(dataReady(QString)), this, SLOT(onDataReceived(QString)));
}

void BottleHandler::onDataReceived(QString data)
{
    qDebug() << data;
    //qDebug() << "test";
}
