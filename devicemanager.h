#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "RFID/serialwrapper.h"

class DeviceManager
{
public:
        static DeviceManager& getInstance()
        {
            static DeviceManager instance;
            return instance;
        }

public:
       SerialWrapper* getSerialConnection();


private:
       DeviceManager();

       //pumps: std::map<string, Pump>;
       //beverages std::map<string, Beverage>;
       SerialWrapper* serialConnection;



public:
       DeviceManager(DeviceManager const&) = delete;
       void operator=(DeviceManager const&) = delete;
};

#endif // DEVICEMANAGER_H
