#include <QCoreApplication>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QElapsedTimer>
#include "serialwrapper.h"

SerialWrapper* serialPort;

QSerialPort* setupSerialPort();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    serialPort = new SerialWrapper(setupSerialPort());

    return a.exec();
}

QSerialPort* setupSerialPort()
{
    QSerialPort* serial = new QSerialPort();
    serial->setPortName("ttyUSB0");
    serial->open(QIODevice::ReadWrite);

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    while(!serial->isOpen()) serial->open(QIODevice::ReadWrite);
    return serial;
}
