#ifndef BOTTLE_H
#define BOTTLE_H

#include <QString>

class Bottle
{
public:
    Bottle(QString ID, int sizeML);

    int getSizeML() const;

private:
    QString ID;
    int sizeML;
};

#endif // BOTTLE_H
