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
    serialPort = new SerialWrapper();

    return a.exec();
}


