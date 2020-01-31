#include "serialwrapper.h"

// Setup the serial port and connect on Read Data
SerialWrapper::SerialWrapper(QObject *parent) : QObject(parent)
{
#ifdef __arm__
    setupSerialPort();
    connect(serialPort, SIGNAL(readyRead()), SLOT(onReadData()));
#endif
}

// Slot connect to ready read. Is called when you are able to handle data.
void SerialWrapper::onReadData()
{
#ifdef __arm__
    QByteArray data = serialPort->readAll();
    emit dataReady(QString::fromStdString(data.toStdString()));
#endif
}

// Debug version of on Read Data
void SerialWrapper::onReadData(QString data)
{
    emit dataReady(data);
}

// Write to the serial port
void SerialWrapper::write(const QByteArray& data)
{
#ifdef __arm__
    serialPort->write(data);
#endif
}

// Setup the default serial port
void SerialWrapper::setupSerialPort()
{
#ifdef __arm__
    serialPort = new QSerialPort();
    serialPort->setPortName("ttyUSB0");
    serialPort->open(QIODevice::ReadWrite);

    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    while(!serialPort->isOpen()) serialPort->open(QIODevice::ReadWrite);
#endif
}
