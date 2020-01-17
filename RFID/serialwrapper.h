#ifndef SERIALWRAPPER_H
#define SERIALWRAPPER_H

#include <QObject>
#include <QDebug>

#ifdef __arm__
    #include <QtSerialPort>
#endif

class SerialWrapper : public QObject
{
    Q_OBJECT
public:
    explicit SerialWrapper(QObject *parent = nullptr);

signals:
    void dataReady(QString data); //Event when data is received

public:
    void write(const QByteArray& data);

private slots:
    void onReadData();

private:
#ifdef __arm__
    QSerialPort* serialPort;
#endif
    void setupSerialPort();
};

#endif // SERIALWRAPPER_H
