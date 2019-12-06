#include "beverage.h"

Beverage::Beverage(QJsonObject beverageData)
{
    id = beverageData["ID"].toInt();
    name = beverageData["Name"].toString();
    costPerML = beverageData["CostPerML"].toDouble();

    QJsonArray recipe = beverageData["Recipe"].toArray();
    setRecipe(recipe);
}

void Beverage::setRecipe(QJsonArray recipe)
{
    for(int i = 0; i < recipe.size(); i++){
        QJsonObject mix = recipe[i].toObject();
        QString pumpName = mix["Name"].toString();
        double ratio = mix["Ratio"].toDouble();

        MixRatio mixRatio(pumpName, ratio);
        ratios.push_back(mixRatio);
    }
}

QString Beverage::getName()
{
    return name;
}

double Beverage::getCostPerML()
{
    return costPerML;
}

std::vector<MixRatio> Beverage::getRatios()
{
    return ratios;
}

