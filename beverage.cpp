#include "beverage.h"
#include "devicemanager.h"

// Initialize id, name, cost per milliliter and set recipe
Beverage::Beverage(QJsonObject beverageData)
{
    id = beverageData["beverageId"].toInt();
    name = beverageData["beverageName"].toString();
    costPerML = beverageData["beveragePrice"].toDouble();

    url = beverageData["beverageImage"].toString();
    getRecipe();
}

Beverage::Beverage(int id, QString name, QString url, double costPerML)
{
    this->id = id;
    this->name = name;
    this->url = url;
    this->costPerML = costPerML;
}

// Initialize beverage recipe(mix)
void Beverage::getRecipe()
{
    QJsonArray ingredients = DeviceManager::getInstance().getApi()->callApi("/beverage/" + QString::number(id) + "/recipe").array();

    for(int i = 0; i < ingredients.size(); i++){
        QJsonObject mix = ingredients[i].toObject();

        MixRatio* mixRatio = new MixRatio(mix["ingredientId"].toInt(), mix["ratio"].toDouble());
        ratios.push_back(mixRatio);
    }
}

// Return beverage name
QString Beverage::getName()
{
    return name;
}

// Return beverage cost per milliliter
double Beverage::getCostPerML()
{
    return costPerML;
}

// Return all available recipe(mix) for beverage
std::vector<MixRatio*> Beverage::getRatios()
{
    return ratios;
}

QString Beverage::getUrl() const
{
    return url;
}

