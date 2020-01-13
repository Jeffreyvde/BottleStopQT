#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fillpage.h"


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
    DeviceManager::getInstance().getBeverage(0);

    FillPage *fillPage = new FillPage();
    fillPage->show();
    this->hide();
}

// Spawn buttons
void MainWindow::spawnButtons()
{
    BeverageFactory factory("QPushButton{border: none}");

    bool spawnLeft = true;
     std::vector<Beverage*> beverages = DeviceManager::getInstance().getBeverages();
     for(uint i = 1; i < beverages.size() ; i++)
     {
         int offset = (spawnLeft) ? 0 : 1;

         ui->grid->addWidget(factory.createBeverage(*beverages[i]), i - offset, offset);
         spawnLeft = !spawnLeft;
//         connect(ui->grid->addWidget(factory.createBeverage(*beverages[i])), SIGNAL(clicked()),
//                 ui-> , SLOT(setText(*beverages[i])))

     }
}
