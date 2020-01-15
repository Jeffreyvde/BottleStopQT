#ifndef BOTTLE_H
#define BOTTLE_H

#include <QString>
#include <QJsonObject>

class Bottle
{
public:
    Bottle(QString ID, int sizeML);
    Bottle(QJsonObject json);

    int getSizeML() const;

private:
    QString ID;
    int sizeML;

};

#endif // BOTTLE_H
