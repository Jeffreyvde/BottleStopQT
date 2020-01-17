#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>
#include "mainwindow.h"
#include "staticscreensaver.h"

class UIManager : public QObject
{
    Q_OBJECT
public:
    static UIManager& getInstance()
    {
        static UIManager instance;
        return instance;
    }
    UIManager(UIManager const&) = delete;
    void operator=(UIManager const&) = delete;

public slots:
    void onBottlePlaced();
    void onBottleRemoved();

private:
    explicit UIManager(QObject *parent = nullptr);

    MainWindow mainWindow;
    StaticScreensaver screenSaver;
};

#endif // UIMANAGER_H
