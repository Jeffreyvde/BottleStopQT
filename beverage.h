#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QApplication>
#include "mixratio.h"

class Beverage
{
public:
    Beverage(QJsonObject beverageData);
    Beverage(int id, QString name, QString url, double costPerML);

    QString getName();
    double getCostPerML();
    std::vector<MixRatio> getRatios();

    QString getUrl() const;

private:
    int id;
    QString name;
    QString url;
    double costPerML;
    std::vector<MixRatio> ratios;

    void setRecipe(QJsonArray recipe);
};

#endif // BEVERAGE_H

