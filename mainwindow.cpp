#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pump.h"

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



    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            QPushButton *button=new QPushButton();
            QPixmap pixmap(":/beverages/Beverages/Sprite.png");
            QIcon ButtonIcon(pixmap);
            button->setIcon(ButtonIcon);
            button->setFixedSize(pixmap.rect().size());
            button->setIconSize(pixmap.rect().size());
            button->setStyleSheet("QPushButton{border: none}");
            ui->grid->addWidget(button, i, j);
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
