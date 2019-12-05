#ifndef BEVERAGE_H
#define BEVERAGE_H

//#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QObject>
#include <QApplication>
//#include <QtDebug>
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
