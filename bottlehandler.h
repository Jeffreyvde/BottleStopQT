#ifndef BOTTLEHANDLER_H
#define BOTTLEHANDLER_H

#include <QObject>

class BottleHandler : public QObject
{
    Q_OBJECT
public:
    explicit BottleHandler(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BOTTLEHANDLER_H