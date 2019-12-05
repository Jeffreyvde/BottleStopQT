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

class Beverage//: public QObject
{

//Q_OBJECT
//    QJsonDocument * json;


public:
    Beverage(QString id, QString name);
    QString id;
    QString name;
    float costPerML;
    int size;
    std::vector<MixRatio> ratios;


};

#endif // BEVERAGE_H
