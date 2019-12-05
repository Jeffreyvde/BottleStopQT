#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pump.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Instances of the pump class with parameters (name, powerPin, PWMPin, flowrate).
    waterPump = new Pump("Water Pump", 0, 0, 0);
    waterPump->setPWM(100);
    sirupPump1 = new Pump("Sirup Pump 1", 0, 0, 0);
    sirupPump1->setPWM(100);
    sirupPump2 = new Pump("Sirup Pump 2", 0, 0, 0);
    sirupPump2->setPWM(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

