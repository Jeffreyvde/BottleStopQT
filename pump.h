#ifndef PUMP_H
#define PUMP_H

#include <qstring.h>

class Pump
{
public:
    Pump(QString name, int powerPin, int PMWPin, int flowrate);
    ~Pump();

public:
    QString name;

    int PWM;

    void activate();
    void activate(float amountInML);
    void deactivate();
    void setPWM(int PWM);

private:
    int powerPin;
    int PMWPin;
    int flowrate;
};

#endif // PUMP_H
