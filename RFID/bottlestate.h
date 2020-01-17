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


    void connecting();
    void listen();
    void cancel();

    QString getSerial(QString strting);

    const QString cancelRequest = "Cancel";
    const QString idRequest = "ID";

    const char start = '$', end = '=', split = ':';



};

#endif // BOTTLESTATE_H
