#include "devicemanager.h"

//Initialize the devicemanager. This happens when the singelton is first called.
DeviceManager::DeviceManager()
{
    serialConnection = new SerialWrapper();
}

//Getter for the entire pump map
std::map<QString, Pump *> DeviceManager::getPumpMap() const
{
    return pumpMap;
}
//Getter for ID
QString DeviceManager::getId() const
{
    return bottleID;
}

//Setter for ID
void DeviceManager::setId(const QString &value)
{
    bottleID = value;
}

//Getter for serial connection
SerialWrapper* DeviceManager::getSerialConnection()
{
    return serialConnection;
}

//Get for pump map
Pump* DeviceManager::getPumpFromMap(QString key)
{
    return pumpMap[key];
}
