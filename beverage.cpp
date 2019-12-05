#include "beverage.h"

Beverage::Beverage(QString id, QString name)
{

    // https://ce42bbc2-5a1b-4df2-9a4d-1043df79c491.mock.pstmn.io/singleBeverage
    // https://ce42bbc2-5a1b-4df2-9a4d-1043df79c491.mock.pstmn.io/allBeverage
    QUrl test("https://ce42bbc2-5a1b-4df2-9a4d-1043df79c491.mock.pstmn.io/singleBeverage");

    QNetworkRequest request(test);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager nam;


    QNetworkReply *reply = nam.get(request);
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();
    QJsonDocument data = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = data.object();
    QJsonArray recipe = json_obj["recipe"].toArray();

//    QVariantMap obj_map = json_obj.toVariantMap();
//    QVariantList recipe_list = obj_map["recipe"].toList();



    reply->deleteLater();

    qDebug() << recipe[0].toObject()["Name"];



    this->id = id;
    this->name = name;




//    float costPerML;
//    int size;
//    std::vector<MixRatio> ratios;

}

