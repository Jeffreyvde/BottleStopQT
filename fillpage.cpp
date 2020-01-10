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
