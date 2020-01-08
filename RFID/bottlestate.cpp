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
    if(data.contains('\n'))
        handle();

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

//Listen if the received data is an id or cancel event
void BottleState::listen()
{
    //Remove /r and /ne2
    serialData.chop(2);


    if(serialData.length() == idLength)
    {
        qDebug() << "Connected";
        state = Connected;
        DeviceManager::getInstance().setId(serialData);
    }
    else if(serialData == cancelRequest)
    {
        state = Canceling;
        handle();
    }
    serialData = "";
}

//Cancel all pumps
void BottleState::cancel()
{
    for (auto const& mapIndex : DeviceManager::getInstance().getPumpMap())
    {
        mapIndex.second->deactivate();
    }
    qDebug() << "Cancel";
    state = Scanning;
}
