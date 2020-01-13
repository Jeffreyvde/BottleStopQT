#include "fillpage.h"
#include "ui_fillpage.h"

FillPage::FillPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FillPage)
{
    ui->setupUi(this);
}

FillPage::~FillPage()
{
    delete ui;
}

void FillPage::on_backBtn_clicked()
{
    mainWindow->show();
    this->close();
}

void FillPage::on_favoriteBtn_clicked()
{

}
