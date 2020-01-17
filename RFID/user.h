#ifndef USER_H
#define USER_H

#include <QString>
#include "bottle.h"

class User
{
public:
    User(int ID, QString name, float balance, Bottle* bottle);
    User(int ID);
    User(QJsonObject json);

    int getID() const;
    QString getName() const;
    float getBalance() const;
    Bottle *getBottle() const;

    bool pay(float amount);


private:
    int ID;
    QString name;
    float balance;
    Bottle* bottle;
};

#endif // USER_H
