#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>
#include "mainwindow.h"
#include "staticscreensaver.h"

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
    StaticScreensaver screenSaver;
};

#endif // UIMANAGER_H
