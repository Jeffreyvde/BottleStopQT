#ifndef STATICSCREENSAVER_H
#define STATICSCREENSAVER_H

#include <QMainWindow>

namespace Ui {
class StaticScreensaver;
}

class StaticScreensaver : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaticScreensaver(QWidget *parent = 0);
    ~StaticScreensaver();

private:
    Ui::StaticScreensaver *ui;
};

#endif // STATICSCREENSAVER_H
