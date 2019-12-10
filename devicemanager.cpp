#include "devicemanager.h"

//Initialize the devicemanager. This happens when the singelton is first called.
DeviceManager::DeviceManager()
{
    serialConnection = new SerialWrapper();
}

SerialWrapper* DeviceManager::getSerialConnection()
{
    return serialConnection;
}
