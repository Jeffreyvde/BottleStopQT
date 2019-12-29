#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap(":/beverages/Beverages/Water.png");
    QIcon ButtonIcon(pixmap);
    ui->waterButton->setIcon(ButtonIcon);
    ui->waterButton->setIconSize(pixmap.rect().size());

   ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);


   Beverage beverage(0,"Sprite", ":/beverages/Beverages/Sprite.png", 0);
   BeverageFactory factory("QPushButton{border: none}");

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            ui->grid->addWidget(factory.createBeverage(beverage), i, j);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_waterButton_clicked()
{

}
