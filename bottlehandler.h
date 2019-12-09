#ifndef BOTTLEHANDLER_H
#define BOTTLEHANDLER_H

#include <QObject>
#include "devicemanager.h"
#include "serialwrapper.h"

//TODO: Fill required data

class BottleHandler : public QObject
{
    Q_OBJECT
public:
    explicit BottleHandler(QObject *parent = nullptr);

signals:

public slots:
    void onDataReceived(QString data);
};

#endif // BOTTLEHANDLER_H
