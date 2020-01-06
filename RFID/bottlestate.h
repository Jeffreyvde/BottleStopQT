#ifndef BOTTLESTATE_H
#define BOTTLESTATE_H

#include <QString>
#include "devicemanager.h"


enum BottleStates { Scanning = 0, Connected = 1, Canceling = 2};

class BottleState
{
public:
    BottleState();

    void handle(QString data);

private:

    void handle();
    BottleStates state;

    QString serialData;
    void addData(QString data);

    void listen();
    void cancel();

    const QString cancelRequest = "Cancel";
    const int idLength = 8;

};

#endif // BOTTLESTATE_H
