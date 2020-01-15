#include "staticscreensaver.h"
#include "ui_staticscreensaver.h"
#include <QFontDatabase>

StaticScreensaver::StaticScreensaver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StaticScreensaver)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/CustomFonts/CustomFonts/BEBAS.ttf");
    ui->label->setFont(QFont("BEBAS", 74, QFont::Normal, false));
}

StaticScreensaver::~StaticScreensaver()
{
    delete ui;
}
