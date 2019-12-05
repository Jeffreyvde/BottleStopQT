#ifndef SERIALWRAPPER_H
#define SERIALWRAPPER_H

#include <QObject>
#include <QtSerialPort>

class SerialWrapper : public QObject
{
    Q_OBJECT
public:
    explicit SerialWrapper(QSerialPort *serialPort, QObject *parent = nullptr);

 Q_SIGNALS:
void OnDataReceived(int value);

public Q_SLOTS:
void write(const QByteArray& data);

private Q_SLOTS:
void onReadyRead();

private:
    QSerialPort* serialPort;
};

#endif // SERIALWRAPPER_H
