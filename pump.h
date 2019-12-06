#ifndef PUMP_H
#define PUMP_H

#include <qstring.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <QObject>

//Define the variables, methods and libraries of the Pump class.
class Pump : public QObject
{
    Q_OBJECT
public:
    explicit Pump(QString name, int powerPin, int PWMPin, int flowrate, QObject *parent = nullptr);

public:
    ~Pump();

public:
    QString name;   //Name of the pump.

    void pumpAmount(int amountInML);
    void activate();
    void setPWM(int PWM);

    bool isActivte();

public slots:
    void deactivate();

private:
    int PWM;        //PWM for the pumps.
    int powerPin;   //Powerpin of the pump.
    int PWMPin;     //PWM pin of the pump.
    int flowrate;   //Flowrate in ML/minute.

    bool active;

    const int maxPWM = 100;

    float calculateFlowrate();
    float calculateActivationTimeForAmount(int amountInML);
};

#endif // PUMP_H
