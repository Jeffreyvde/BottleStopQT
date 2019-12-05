#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include "mainwindow.h"
#include "serialwrapper.h"

QSerialPort* setupSerialPort();
SerialWrapper* serialPort;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
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
