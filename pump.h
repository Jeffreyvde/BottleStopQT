#ifndef PUMP_H
#define PUMP_H

#include <qstring.h>
#include <QObject>
#include <QTimer>
#include <QJsonObject>

#ifdef __arm__
#include <wiringPi.h>
#include <softPwm.h>
#endif

//Define the variables, methods and libraries of the Pump class.
class Pump : public QObject
{
    Q_OBJECT
public:
    explicit Pump(QString name, int powerPin, int PWMPin, int flowrate, QObject *parent = nullptr);
    explicit Pump(QJsonObject pump, QObject *parent = nullptr);

    ~Pump();

    void pumpAmount(int amountInML);
    void activate();
    void setPWM(int PWM);

    bool getActive();

    int getIngredientId() const;

public slots:
    void deactivate();

private:
    const int maxPWM = 100;
    int PWM = maxPWM;        //PWM for the pumps.
    int powerPin;   //Powerpin of the pump.
    int PWMPin;     //PWM pin of the pump.
    int flowrate;   //Flowrate in ML/minute.

    int ingredientId; //The specific ingredient
    int ID;



    QString name;   //Name of the pump.
    QString type;   //Type of the pump

    bool active;    //Pump active status.


    float calculateFlowrate();
    float calculateActivationTimeForAmount(int amountInML);

    void getPins();
    void initializePins();

};

#endif // PUMP_H
