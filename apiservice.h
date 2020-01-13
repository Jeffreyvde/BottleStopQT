#ifndef APISERVICE_H
#define APISERVICE_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QApplication>

class ApiService
{
public:
    ApiService(QString baseURL);

    QJsonDocument getRequestApi(QString extension);
    QJsonDocument postRequestApi(QString extension, QJsonObject body);
    QJsonDocument deleteRequestApi(QString extension);

private:
    QJsonDocument readAll(QNetworkReply *reply);

    QString baseURL;

    QNetworkAccessManager* instance;

};

#endif // APISERVICE_H
