#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>
#include "mainwindow.h"

class UIManager : public QObject
{
    Q_OBJECT
public:
    explicit UIManager(QObject *parent = nullptr);

public slots:
    void onBottlePlaced();
    void onBottleRemoved();

private:
    MainWindow mainWindow;
};

#endif // UIMANAGER_H
