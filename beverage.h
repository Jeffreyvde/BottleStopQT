#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <QJsonDocument>
#include <QJsonArray>
#include "mixratio.h"

class Beverage
{
public:
    Beverage(QJsonObject beverageData);
    Beverage(int id, QString name, QString url, double costPerML);

    QString getName();
    double getCostPerML();
    std::vector<MixRatio*> getRatios();
    QString getUrl() const;

    void mix(int amountInML);

    int getId() const;

private:
    int id;
    QString name;
    QString url;
    double costPerML;
    std::vector<MixRatio*> ratios;

    void getRecipe();
};


#endif // BEVERAGE_H

