#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H


#include "pump.h"
#include "beverage.h"
#include "RFID/serialwrapper.h"
#include "apiservice.h"
#include "RFID/user.h"
#include <QJsonObject>

class DeviceManager
{
public:
    static DeviceManager& getInstance()
    {
        static DeviceManager instance;
        return instance;
    }
    DeviceManager(DeviceManager const&) = delete;
    void operator=(DeviceManager const&) = delete;

    SerialWrapper* getSerialConnection();

    QString getId() const;
    std::map<int, Pump*> getPumpMap() const;
    std::vector<Beverage *> getBeverages() const;

    ApiService *getApi() const;

    Pump* getPump(int ingredientID);
    Beverage* getBeverage(int beverageIndex);

    void setId(const QString &value);
    void cancel();

    void initializeDevice();    

signals:
    void bottlePlaced();
    void bottleRemoved();

private:
    DeviceManager();

    std::map<int, Pump*> pumpMap;
    std::vector<Beverage*> beverages;
    SerialWrapper* serialConnection;

    ApiService* api;

    QString bottleID;
    User* activeUser;

};

#endif // DEVICEMANAGER_H
