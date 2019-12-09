#include "beverage.h"

// Initialize id, name, cost per milliliter and set recipe
Beverage::Beverage(QJsonObject beverageData)
{
    id = beverageData["ID"].toInt();
    name = beverageData["Name"].toString();
    costPerML = beverageData["CostPerML"].toDouble();

    QJsonArray recipe = beverageData["Recipe"].toArray();
    ratios.reserve(2);
    setRecipe(recipe);
}

// Initialize beverage recipe(mix)
void Beverage::setRecipe(QJsonArray recipe)
{
    for(int i = 0; i < recipe.size(); i++){
        QJsonObject mix = recipe[i].toObject();
        QString pumpName = mix["Name"].toString();
        double ratio = mix["Ratio"].toDouble();

        MixRatio mixRatio(pumpName, ratio);
        ratios.emplace_back(mixRatio);
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
std::vector<MixRatio> Beverage::getRatios()
{
    return ratios;
}

