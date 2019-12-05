#include "pump.h"
#include <QTimer>

//Constructor and destructor for the Pump class. Initializes the variables.
Pump::Pump(QString name, int powerPin, int PWMPin, int flowrate, QObject *parent) : QObject(parent)
{
    //Name of the pump.
    this->name = name;

    //Powerpin of the pump
    this->powerPin = powerPin;
    pinMode(powerPin, OUTPUT);

    //Pwm pin of the pump.
    this->PWMPin = PWMPin;
    softPwmCreate(PWMPin, 0, maxPWM);

    //Flowrate in ML/minute.
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
    digitalWrite(powerPin, HIGH);
    pwmWrite(PWMPin, PWM);
}

//Deactivates the Pump by setting its pin to LOW.
void Pump::deactivate()
{
    digitalWrite(powerPin, LOW);
}

//Sets a specific PWM to adjust the flowrate.
void Pump::setPWM(int PWM)
{
    this->PWM = PWM;
    softPwmWrite(PWMPin, PWM);
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
