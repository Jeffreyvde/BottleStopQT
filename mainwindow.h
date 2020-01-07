#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QScroller>
#include "pump.h"
#include "beveragefactory.h"
#include "beverage.h"
#include "devicemanager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_waterButton_clicked();

private:
    Ui::MainWindow *ui;

    void spawnButtons();

};

#endif // MAINWINDOW_H
