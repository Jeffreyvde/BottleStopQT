#include "bottlestate.h"

BottleState::BottleState()
{
    state = Scanning;
}

//Handle internal state
void BottleState::handle()
{
    switch (state)
    {
        case Scanning:
            connecting();
            break;
        case Connected:
            listen();
            break;
        case Canceling:
            cancel();
            break;
    }
}

//Handle serial data
void BottleState::handle(QString data)
{
    addData(data);
    if(serialData.contains(start) && serialData.contains(end))
    {
        serialData = getSerial(serialData);
        qDebug() << serialData;
        handle();
        serialData = "";
    }

}

//Add data to the serial data
void BottleState::addData(QString data)
{
    if(serialData.length() > 0)
        serialData += data;
    else
    {
        serialData = data;
    }
}

// Check if the data received is an ID
void BottleState::connecting()
{
    if(!serialData.contains(split))
    {
        return;
    }
    int splitIndex = serialData.indexOf(split);

    QString request = serialData.mid(0, splitIndex);
    QString value = serialData.mid(splitIndex + 1, serialData.length() - splitIndex);

    if(request == idRequest)
    {
        state = Connected;
        DeviceManager::getInstance().getBottleSingals()->placeBottle(value);
        qDebug() << "Connected";
    }

}

// Listen if the received data is an id or cancel event
void BottleState::listen()
{   if(serialData == cancelRequest)
    {
        qDebug() << "Cancelling";
        state = Canceling;
        handle();
    }
}

// Cancel all pumps
void BottleState::cancel()
{
    qDebug() << "Cancelled";
    DeviceManager::getInstance().getBottleSingals()->removeBottle();
    state = Scanning;
}

// Remove start and end chars
QString BottleState::getSerial(QString serial)
{
    int startPos = serial.indexOf(start) + 1;
    int endPos = serial.indexOf(end);
    int length = endPos - startPos;
    return serial.mid(startPos, length);
}
