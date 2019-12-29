#include "bottlehandler.h"

BottleHandler::BottleHandler(QObject *parent) : QObject(parent)
{
    state = new BottleState();
    connect(DeviceManager::getInstance().getSerialConnection(), SIGNAL(dataReady(QString)), this, SLOT(onDataReceived(QString)));
}

void BottleHandler::onDataReceived(QString data)
{
    qDebug() << data;
    state->handle(data);
}
