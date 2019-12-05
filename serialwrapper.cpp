#include "serialwrapper.h"

SerialWrapper::SerialWrapper(QSerialPort* serialPort, QObject *parent) : QObject(parent)
{
    this->serialPort = serialPort;
    connect(serialPort, SIGNAL(readyRead()), SLOT(onReadyRead()));
}

void SerialWrapper::onReadyRead(){

}

void SerialWrapper::write(const QByteArray& data){
    serialPort->write(data);
}
