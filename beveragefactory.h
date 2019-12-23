#ifndef BEVERAGEFACTORY_H
#define BEVERAGEFACTORY_H

#include <QPushButton>
#include "beverage.h"

class BeverageFactory
{
public:
    BeverageFactory(QString style);

    QPushButton* createBeverage(Beverage Beverages);

private:
    QString style;
};

#endif // BEVERAGEFACTORY_H
