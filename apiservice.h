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

    QJsonDocument getApi(QString extension);


private:
    QString baseURL;

    QNetworkAccessManager* instance;

};

#endif // APISERVICE_H
