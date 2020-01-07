#include "apiservice.h"

ApiService::ApiService(QString baseURL)
{
    this->baseURL = baseURL;
    this->instance = new QNetworkAccessManager();
}

//Call the specific api
QJsonDocument ApiService::getApi(QString extension)
{
    QUrl url(baseURL + extension);
    QNetworkRequest request(url);

    QNetworkReply *reply = instance->get(request);
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();
    return QJsonDocument::fromJson(response_data);
}
