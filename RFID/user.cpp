#include "user.h"

User::User(QString ID, QString name, float balance, Bottle* bottle)
{
    this->ID = ID;
    this->name = name;
    this->balance = balance;
    this->bottle = bottle;
}

User::User(QString ID)
{
    //TODO Api request
}

QString User::getID() const
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
