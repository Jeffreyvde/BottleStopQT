#include "apiservice.h"

ApiService::ApiService(QString baseURL)
{
    this->baseURL = baseURL;
    this->instance = new QNetworkAccessManager();
}

//Call the specific api
QJsonDocument ApiService::getRequestApi(QString extension)
{
    QUrl url(baseURL + extension);
    QNetworkRequest request(url);

    QNetworkReply *reply = instance->get(request);

    return readAll(reply);
}

QJsonDocument ApiService::postRequestApi(QString extension, QJsonObject body)
{
    QUrl url(baseURL + extension);
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = instance->post(request, QJsonDocument(body).toJson());

    return readAll(reply);
}

QJsonDocument ApiService::deleteRequestApi(QString extension)
{
    QUrl url(baseURL + extension);
    QNetworkRequest request(url);

    QNetworkReply *reply = instance->deleteResource(request);

    return readAll(reply);
}

QJsonDocument ApiService::readAll(QNetworkReply *reply)
{
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();
    reply->deleteLater();

    return QJsonDocument::fromJson(response_data);
}
