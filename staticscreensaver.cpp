#include "staticscreensaver.h"
#include "ui_staticscreensaver.h"

StaticScreensaver::StaticScreensaver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StaticScreensaver)
{
    ui->setupUi(this);
}

StaticScreensaver::~StaticScreensaver()
{
    delete ui;
}
