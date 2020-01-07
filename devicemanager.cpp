#include "devicemanager.h"

//Initialize the devicemanager. This happens when the singelton is first called.
DeviceManager::DeviceManager()
{
    serialConnection = new SerialWrapper();
    api = new ApiService("https://bottlestopapi.azurewebsites.net");
    QJsonArray json = api->getApi("/machine/availability/rRksBrcCH9SjyyKR3UhgsKZQbPE5tMJJ").array();
    foreach (const QJsonValue & value, json)
    {
        QJsonObject obj = value.toObject();
        beverages.push_back(new Beverage(obj["beverage"].toObject()));
    }
}

//Getter for the entire beverage map
std::vector<Beverage*> DeviceManager::getBeverages() const
{
    return beverages;
}

//Getter for the entire pump map
std::vector<Pump*> DeviceManager::getPumps() const
{
    return pumps;
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

//Get a pump
Pump* DeviceManager::getPump(int pumpIndex)
{
    return pumps[pumpIndex];
}
