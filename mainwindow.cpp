#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pump.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            QPushButton *button=new QPushButton();
            button->setText(QString::number(i*j));
            ui->grid->addWidget(button, i, j);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

