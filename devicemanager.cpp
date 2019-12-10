#include "devicemanager.h"

//Initialize the devicemanager. This happens when the singelton is first called.
DeviceManager::DeviceManager()
{
    serialPort = new SerialWrapper();
}

Pump& DeviceManager::getPumpFromMap(QString key)
{
    return pumpMap[key];
}
