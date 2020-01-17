#include "bottle.h"
#include <QJsonValueRef>
#include <QJsonArray>
#include <QDebug>

Bottle::Bottle(QString ID, int sizeML)
{
    this->ID = ID;
    this->sizeML = sizeML;
}

Bottle::Bottle(QJsonObject json)
{
    ID = json["bottleId"].toString();

    QJsonArray model = json["bottleModel"].toArray();
    sizeML = model[0].toObject()["bottleSizeMl"].toInt();
    qDebug() << sizeML;
}

int Bottle::getSizeML() const
{
    return sizeML;
}
