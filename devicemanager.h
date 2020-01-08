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

    SerialWrapper* getSerialConnection();

    QString getId() const;
    void setId(const QString &value);
    std::map<int, Pump*> getPumpMap() const;
    std::vector<Beverage *> getBeverages() const;

    ApiService *getApi() const;

    Pump* getPump(int ingredientID);
    Beverage* getBeverage(int beverageIndex);


    void initializeDevice();

    DeviceManager(DeviceManager const&) = delete;
    void operator=(DeviceManager const&) = delete;

private:
    DeviceManager();

    std::map<int, Pump*> pumpMap;
    std::vector<Beverage*> beverages;
    SerialWrapper* serialConnection;

    ApiService* api;

    QString bottleID;

};

#endif // DEVICEMANAGER_H
