#ifndef PUMP_H
#define PUMP_H

#include <qstring.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <QObject>

class Pump : public QObject
{
    Q_OBJECT
public:
    explicit Pump(QString name, int powerPin, int PWMPin, int flowrate, QObject *parent = nullptr);

public:
    ~Pump();

public:
    QString name;

    int PWM;

    void pumpAmount(int amountInML);
    void activate();
    void deactivate();
    void setPWM(int PWM);

private:
    int powerPin;
    int PWMPin;
    int flowrate;

    const int maxPWM = 100;

    float calculateFlowrate();
    float calculateActivationTimeForAmount(int amountInML);

};

#endif // PUMP_H
