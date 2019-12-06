#include "serialwrapper.h"

SerialWrapper::SerialWrapper(QObject *parent) : QObject(parent)
{
    setupSerialPort();
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

void SerialWrapper::setupSerialPort()
{
    serialPort = new QSerialPort();
    serialPort->setPortName("ttyUSB0");
    serialPort->open(QIODevice::ReadWrite);

    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    while(!serialPort->isOpen()) serialPort->open(QIODevice::ReadWrite);
}
