#include "serialwrapper.h"

SerialWrapper::SerialWrapper(QSerialPort* serialPort, QObject *parent) : QObject(parent)
{
    this->serialPort = serialPort;
    connect(serialPort, SIGNAL(readyRead()), SLOT(onReadData()));
}

void SerialWrapper::onReadData()
{
    QByteArray data = serialPort->readAll();
    qDebug() << data;
    OnDataReceived(data);
}

void SerialWrapper::write(const QByteArray& data){
    serialPort->write(data);
}
