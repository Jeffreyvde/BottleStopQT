#ifndef USER_H
#define USER_H

#include <QString>
#include "bottle.h"

class User
{
public:
    User(QString ID, QString name, float balance, Bottle* bottle);
    User(QString ID);

    QString getID() const;
    QString getName() const;
    float getBalance() const;
    Bottle *getBottle() const;

    bool pay(float amount);


private:
    QString ID;
    QString name;
    float balance;
    Bottle* bottle;
};

#endif // USER_H
