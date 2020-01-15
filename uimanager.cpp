#include "uimanager.h"
#include "RFID/bottlesignals.h"

UIManager::UIManager(QObject *parent) : QObject(parent)
{
    mainWindow.show();

    BottleSignals* signal = DeviceManager::getInstance().getBottleSingals();

    connect(signal, SIGNAL(bottlePlaced()), SLOT(onBottlePlaced()));
    connect(signal, SIGNAL(bottleRemoved()), SLOT(onBottleRemoved()));
}

void UIManager::onBottlePlaced()
{
    qDebug() << "Add";
}

void UIManager::onBottleRemoved()
{
    qDebug() << "Removed";
}
