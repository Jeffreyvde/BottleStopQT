#ifndef SERIALWRAPPER_H
#define SERIALWRAPPER_H

#include <QObject>
#include <QtSerialPort>
#include <QDebug>

class SerialWrapper : public QObject
{
    Q_OBJECT
public:
    explicit SerialWrapper(QObject *parent = nullptr);

 Q_SIGNALS:
void OnDataReceived(QByteArray data);

public Q_SLOTS:
void write(const QByteArray& data);

private Q_SLOTS:
void onReadData();

private:
    QSerialPort* serialPort;
    void setupSerialPort();
};

#endif // SERIALWRAPPER_H
