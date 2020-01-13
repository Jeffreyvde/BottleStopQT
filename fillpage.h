#ifndef FILLPAGE_H
#define FILLPAGE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class FillPage;
}

class FillPage : public QDialog
{
    Q_OBJECT

public:
    explicit FillPage(QWidget *parent = nullptr);
    ~FillPage();
    Ui::FillPage *ui;

private slots:
    void on_backBtn_clicked();

    void on_favoriteBtn_clicked();

private:
//    Ui::FillPage *ui;
    MainWindow *mainWindow;
};

#endif // FILLPAGE_H
