#ifndef FILLPAGE_H
#define FILLPAGE_H

#include <QDialog>
#include <QPixmap>
//#include "mainwindow.h"
#include "RFID/user.h"
#include "beverage.h"
#include "devicemanager.h"

namespace Ui {
class FillPage;
}

class FillPage : public QDialog
{
    Q_OBJECT

public:
    explicit FillPage(QWidget *parent = nullptr);
    ~FillPage();


    void setBeverage(Beverage *value);

private slots:
    void on_backBtn_clicked();

    void on_favoriteBtn_clicked();

private:
    Ui::FillPage *ui;
    //MainWindow *mainWindow;

    bool favoriteStatusCheck(QString uid, QString bid);
    void changeFavBackground(bool value);

    Beverage* beverage;

    QString uid;
    QString bid;
    bool isFavorite;

};

#endif // FILLPAGE_H
