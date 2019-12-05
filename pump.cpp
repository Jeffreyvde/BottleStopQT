#include "pump.h"
#include <QTimer>

//Constructor and destructor for the Pump class. Initializes the variables.
Pump::Pump(QString name, int powerPin, int PWMPin, int flowrate, QObject *parent) : QObject(parent)
{
    this->name = name;

    this->powerPin = powerPin;
    pinMode(powerPin, OUTPUT);

    this->PWMPin = PWMPin;
    pinMode(PWMPin, OUTPUT);
    softPwmCreate(PWMPin, 0, maxPWM);

    this->flowrate = flowrate;
}
Pump::~Pump(){}

//Pumps the specific amount which is given.
void Pump::pumpAmount(int amountInML)
{


    calculateFlowrate();
    activate();

    //Sets the calculated time to miliseconds.
    int multiplierToMilliseconds = 60 * 1000;

    //Call deactivate after the time which is needed to fill is over.
    float delay = calculateActivationTimeForAmount(amountInML) * multiplierToMilliseconds;
    QTimer::singleShot(delay, this, SLOT(deactivate()));
}

//Acitvates and controls the Pump by setting its pin to HIGH, and its PWM value.
void Pump::activate()
{
    isActive = true;

    digitalWrite(powerPin, HIGH);
    pwmWrite(PWMPin, PWM);
}

//Deactivates the Pump by setting its pin to LOW.
void Pump::deactivate()
{
    isActive = false;
    digitalWrite(powerPin, LOW);
}

//Sets a specific PWM to adjust the flowrate.
void Pump::setPWM(int PWM)
{
    if(PWM < 0)
        this->PWM = 0;
    else if(PWM > maxPWM)
        this->PWM = maxPWM;

    this->PWM = PWM;
    softPwmWrite(PWMPin, this->PWM);
}

//Calculates the activation time based on amount and pump flowrate.
float Pump::calculateActivationTimeForAmount(int amountInML)
{
    return amountInML / calculateFlowrate();
}

//Calculates a custom flowrate needed for the amount of liquid to pump.
float Pump::calculateFlowrate()
{
    float flowrateMultiplier = PWM / 100;
    return flowrate * flowrateMultiplier;
}
