#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uimanager.h"

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

   spawnButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_waterButton_clicked()
{
        Beverage* beverage = DeviceManager::getInstance().getBeverage(0);
        pumpBeverage(beverage);
}

// Spawn buttons
void MainWindow::spawnButtons()
{
    BeverageFactory factory("QPushButton{border: none}");

    bool spawnLeft = true;
    std::vector<Beverage*> beverages = DeviceManager::getInstance().getBeverages();
    int offset = 0;


    for(uint i = 1; i < beverages.size() ; i++)
    {
        offset = (spawnLeft) ? 0 : 1;
        QPushButton* button = factory.createBeverage(*beverages[i]);

        connect(button, &QPushButton::clicked, [=] { pumpBeverage(beverages[i]); });

        ui->grid->addWidget(button, i - offset, offset);
        spawnLeft = !spawnLeft;
    }
}

//Pump a beverage
void MainWindow::pumpBeverage(Beverage *beverage)
{
    beverage->mix(DeviceManager::getInstance().getActiveUser()->getBottle()->getSizeML());
   // beverage->mix(200);
    UIManager::getInstance().onBottleRemoved();
}
