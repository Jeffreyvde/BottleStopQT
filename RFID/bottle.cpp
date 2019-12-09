#include "bottle.h"

Bottle::Bottle(QString ID, int sizeML)
{
    this->ID = ID;
    this->sizeML = sizeML;
}

int Bottle::getSizeML() const
{
    return sizeML;
}
