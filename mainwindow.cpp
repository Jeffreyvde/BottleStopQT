#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pump.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Pump waterPump("Water Pomp", 0, 0, 0);
    Pump sirupPump1("Sirup Pump 1", 0, 0, 0);
    Pump waterPump2("Sirup Pump 2", 0, 0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
