#include "serialwrapper.h"

//Setup the serial port and connect on Read Data
SerialWrapper::SerialWrapper(QObject *parent) : QObject(parent)
{
    setupSerialPort();
    connect(serialPort, SIGNAL(readyRead()), SLOT(onReadData()));
}

//Slot connect to ready read. Is called when you are able to handle data.
void SerialWrapper::onReadData()
{
    QByteArray data = serialPort->readAll();
    emit dataReady();
    qDebug() << data;
}

//Write to the serial port
void SerialWrapper::write(const QByteArray& data){
    serialPort->write(data);
}

//Setup the default serial port
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
