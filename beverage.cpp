#include "beverage.h"

Beverage::Beverage(QJsonObject beverageData)
{
    this->beverageData = beverageData;
    this->id = beverageData["ID"].toInt();
    this->name = beverageData["ID"].toString();
    this->costPerML = beverageData["ID"].toDouble();

    QJsonArray recipe = beverageData["Recipe"].toArray();

    for(int i = 0; i < recipe.size(); i++){
        QJsonObject mix = recipe[i].toObject();
        QString pumpName = mix["Name"].toString();
        double ratio = mix["Ratio"].toDouble();

        MixRatio mixRatio(pumpName, ratio);
        this->ratios.push_back(mixRatio);
    }

    // https://ce42bbc2-5a1b-4df2-9a4d-1043df79c491.mock.pstmn.io/singleBeverage
    // https://ce42bbc2-5a1b-4df2-9a4d-1043df79c491.mock.pstmn.io/allBeverage
//    QUrl test("https://ce42bbc2-5a1b-4df2-9a4d-1043df79c491.mock.pstmn.io/singleBeverage");

//    QNetworkRequest request(test);
//    QNetworkAccessManager nam;
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

//    QNetworkReply *reply = nam.get(request);
//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();
//    QJsonDocument data = QJsonDocument::fromJson(response_data);
//    QJsonObject json_obj = data.object();
//    QJsonArray recipe = json_obj["recipe"].toArray();


//    reply->deleteLater();

//    qDebug() << recipe[1].toObject()["Name"];


}

