#include "pump.h"

Pump::Pump(QString name, int powerPin, int PWMPin, int flowrate)
{
    this->name = name;
    this->powerPin = powerPin;
    pinMode(powerPin, OUTPUT);

    this->PWMPin = PWMPin;
     pinMode(PWMPin, OUTPUT);

    this->flowrate = flowrate;
}
Pump::~Pump(){}

void Pump::activate()
{

}

void Pump::activate(int amountInML)
{

}

void Pump::deactivate()
{

}

void Pump::setPWM(int PWM)
{
    this->PWM = PWM;
}
