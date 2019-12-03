#ifndef PUMP_H
#define PUMP_H

#include <qstring.h>
#include <wiringPi.h>

class Pump
{
public:
    Pump(QString name, int powerPin, int PWMPin, int flowrate);
    ~Pump();

public:
    QString name;

    int PWM;

    void activate();
    void activate(int amountInML);
    void deactivate();
    void setPWM(int PWM);

private:
    int powerPin;
    int PWMPin;
    int flowrate;
};

#endif // PUMP_H
