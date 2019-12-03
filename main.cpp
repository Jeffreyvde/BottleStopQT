#include "mainwindow.h"
#include <QApplication>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    wiringPiSetup();

    w.show();

    return a.exec();
}
