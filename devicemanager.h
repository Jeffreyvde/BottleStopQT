#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H


#include "pump.h"
#include "beverage.h"
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
    Pump* getPumpFromMap(QString key);

    QString getId() const;
    void setId(const QString &value);
    std::map<QString, Pump *> getPumpMap() const;

private:
    DeviceManager();

    std::map<QString, Pump*> pumpMap;
    std::map<QString, Beverage*> beverageMap;
    SerialWrapper* serialConnection;

    QString bottleID;

public:
    DeviceManager(DeviceManager const&) = delete;
    void operator=(DeviceManager const&) = delete;
};

#endif // DEVICEMANAGER_H
