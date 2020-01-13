#include "devicemanager.h"

//Initialize the devicemanager. This happens when the singelton is first called.
DeviceManager::DeviceManager()
{
    serialConnection = new SerialWrapper();
    api = new ApiService("https://bottlestopapi.azurewebsites.net");
}

// Intitalize the device
void DeviceManager::initializeDevice()
{
    QJsonArray json = api->getRequestApi("/machine/availability/rRksBrcCH9SjyyKR3UhgsKZQbPE5tMJJ").array();
    foreach (const QJsonValue & value, json)
    {
        QJsonObject obj = value.toObject();

        Pump* pump = new Pump(obj["pump"].toObject());
        pumpMap.insert(std::pair<int, Pump*>(pump->getIngredientId(), pump));

        beverages.push_back(new Beverage(obj["beverage"].toObject()));
    }
}

//Getter for the api service
ApiService *DeviceManager::getApi() const
{
    return api;
}

//Getter for the entire beverage map
std::vector<Beverage*> DeviceManager::getBeverages() const
{
    return beverages;
}

//Getter for the entire pump map
 std::map<int, Pump*> DeviceManager::getPumpMap() const
{
    return pumpMap;
}

 //Getter for ID
QString DeviceManager::getId() const
{
    return bottleID;
}

//Getter for serial connection
SerialWrapper* DeviceManager::getSerialConnection()
{
    return serialConnection;
}

//Get a pump
Pump* DeviceManager::getPump(int pumpIndex)
{
    return pumpMap[pumpIndex];
}

//Get a beverage
Beverage* DeviceManager::getBeverage(int beverageIndex)
{
    return beverages[beverageIndex];
}

//Setter for ID
void DeviceManager::setId(const QString &value)
{
    bottleID = value;
    emit bottlePlaced();
}

//Cancel event for the device
void DeviceManager::cancel()
{
    for (auto const& mapIndex : getPumpMap())
    {
         mapIndex.second->deactivate();
    }
    emit cancelReceived();
}

