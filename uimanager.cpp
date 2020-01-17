#include "uimanager.h"
#include "RFID/bottlesignals.h"

UIManager::UIManager(QObject *parent) : QObject(parent)
{
    screenSaver.show();

    BottleSignals* signal = DeviceManager::getInstance().getBottleSingals();

    connect(signal, SIGNAL(bottlePlaced()), SLOT(onBottlePlaced()));
    connect(signal, SIGNAL(bottleRemoved()), SLOT(onBottleRemoved()));
}

void UIManager::onBottlePlaced()
{
    qDebug() << "Add";
    screenSaver.hide();
    mainWindow.show();
}

void UIManager::onBottleRemoved()
{
    qDebug() << "Removed";
    screenSaver.show();
    mainWindow.hide();
}
