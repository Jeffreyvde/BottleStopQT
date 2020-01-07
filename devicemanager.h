#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H


#include "pump.h"
#include "beverage.h"
#include "RFID/serialwrapper.h"
#include "apiservice.h"
#include <QJsonObject>

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

    QString getId() const;
    void setId(const QString &value);
    std::vector<Pump *> getPumps() const;
    std::vector<Beverage *> getBeverages() const;

    Pump* getPump(int pumpIndex);

private:
    DeviceManager();

    std::vector<Pump*> pumps;
    std::vector<Beverage*> beverages;
    SerialWrapper* serialConnection;

    ApiService* api;

    QString bottleID;

public:
    DeviceManager(DeviceManager const&) = delete;
    void operator=(DeviceManager const&) = delete;
};

#endif // DEVICEMANAGER_H
