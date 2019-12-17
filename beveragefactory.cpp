#include "beveragefactory.h"

BeverageFactory::BeverageFactory(QString style)
{
    this->style = style;
}

QPushButton* BeverageFactory::createBeverage(Beverage beverage)
{
    QPushButton *button=new QPushButton();
    QPixmap pixmap(beverage.getUrl());
    QIcon ButtonIcon(pixmap);
    button->setIcon(ButtonIcon);
    button->setFixedSize(pixmap.rect().size());
    button->setIconSize(pixmap.rect().size());
    button->setStyleSheet(style);
    return button;
}

