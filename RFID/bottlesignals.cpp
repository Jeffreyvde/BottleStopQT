#include "bottlesignals.h"
#include "devicemanager.h"

BottleSignals::BottleSignals(QObject *parent) : QObject(parent)
{}

//Emits the signal for placebottle
void BottleSignals::placeBottle(QString ID)
{
   if(DeviceManager::getInstance().setUser(ID))
   {
       qDebug() << "Connected";
       emit bottlePlaced();
   }
   else
   {
       qDebug() << "Failed";
   }
}

// Emits the signal for removebottle
void BottleSignals::removeBottle()
{
    for (auto const& mapIndex : DeviceManager::getInstance().getPumpMap())
    {
        mapIndex.second->deactivate();
    }
    emit bottleRemoved();
}
