#ifndef BEVERAGE_H
#define BEVERAGE_H

//#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
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

    QString getName();
    double getCostPerML();
    std::vector<MixRatio> getRatios();

private:
    int id;
    QString name;
    double costPerML;
    std::vector<MixRatio> ratios;

    void setRecipe(QJsonArray recipe);
};

#endif // BEVERAGE_H

