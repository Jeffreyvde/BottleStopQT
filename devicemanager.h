#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "serialwrapper.h"
#include "pump.h"
#include "beverage.h"


class DeviceManager
{
public:
    static DeviceManager& getInstance()
    {
        static DeviceManager instance;
        return instance;
    }

public:
    Pump& getPumpFromMap(QString key);

private:
    DeviceManager();
    std::map<QString, Pump> pumpMap;
    std::map<QString, Beverage> beverageMap;
    SerialWrapper* serialPort;

public:
    DeviceManager(DeviceManager const&) = delete;
    void operator=(DeviceManager const&) = delete;
};

#endif // DEVICEMANAGER_H
