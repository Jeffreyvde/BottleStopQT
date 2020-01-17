#include "user.h"

User::User(int ID, QString name, float balance, Bottle* bottle)
{
    this->ID = ID;
    this->name = name;
    this->balance = balance;
    this->bottle = bottle;
}

User::User(int ID)
{
    //TODO Api request
}

User::User(QJsonObject json)
{
    bottle = new Bottle(json["bottle"].toObject());

    json = json["user"].toObject();

    ID = json["userId"].toInt();
    name = json["firstName"].toString();
    balance = json["balance"].toInt();
}

int User::getID() const
{
    return ID;
}

QString User::getName() const
{
    return name;
}

float User::getBalance() const
{
    return balance;
}

Bottle *User::getBottle() const
{
    return bottle;
}
