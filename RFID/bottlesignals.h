#ifndef BOTTLESIGNALS_H
#define BOTTLESIGNALS_H

#include <QObject>

class BottleSignals : public QObject
{
    Q_OBJECT
public:
    explicit BottleSignals(QObject *parent = nullptr);

    void placeBottle(QString ID);
    void removeBottle();

signals:
    void bottlePlaced();
    void bottleRemoved();
};

#endif // BOTTLESIGNALS_H
