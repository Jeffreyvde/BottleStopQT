#include "devicemanager.h"
#include "pump.h"

//Constructor and destructor for the Pump class. Initializes the variables.
Pump::Pump(QString name, int powerPin, int PWMPin, int flowrate, QObject *parent) : QObject(parent)
{
    this->name = name;

    this->powerPin = powerPin;
    this->PWMPin = PWMPin;

    initializePins();

    this->flowrate = flowrate;
}

//Pump consturctor from json
Pump::Pump(QJsonObject pump, QObject *parent): QObject(parent)
{
   name = pump["pumpName"].toString();
   type = pump["pumpType"].toString();
   ID = pump["pumpId"].toInt();
   ingredientId = pump["ingredientId"].toInt();
   flowrate= pump["flowrate"].toInt();

   //TODO add PWM

   getPins();
}

Pump::~Pump(){}

//Initialize pins (power pins as OUTPUT and PWM for pwm pin)
void Pump::initializePins()
{
#ifdef __arm__
    pinMode(powerPin, OUTPUT);
    digitalWrite(powerPin, LOW);

    pinMode(PWMPin, OUTPUT);
    softPwmCreate(PWMPin, 0, maxPWM);
#endif
}

//Pumps the specific amount which is given.
void Pump::pumpAmount(int amountInML)
{
    activate();

    //Sets the calculated time to miliseconds.
    int multiplierToMilliseconds = 60 * 1000;

    //Call deactivate after the time which is needed to fill is over.
    float delay = calculateActivationTimeForAmount(amountInML) * multiplierToMilliseconds;
    qDebug() << delay;
    QTimer::singleShot(delay, this, SLOT(deactivate()));
}

//Acitvates and controls the Pump by setting its pin to HIGH, and its PWM value.
void Pump::activate()
{
    active = true;
    qDebug() << "Activate";

#ifdef __arm__
    digitalWrite(powerPin, HIGH);
    pwmWrite(PWMPin, PWM);
#endif
}

//Deactivates the Pump by setting its pin to LOW.
void Pump::deactivate()
{
    active = false;
    qDebug() << "Deactivate";
#ifdef __arm__
    digitalWrite(powerPin, LOW);
#endif

}

int Pump::getIngredientId() const
{
    return ingredientId;
}

//Sets a specific PWM to adjust the flowrate.
void Pump::setPWM(int PWM)
{
    if(PWM < 0)
        this->PWM = 0;
    else if(PWM > maxPWM)
        this->PWM = maxPWM;

    this->PWM = PWM;
#ifdef __arm__
    softPwmWrite(PWMPin, this->PWM);
#endif
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

//Returns if the pump is active
bool Pump::getActive()
{
  return active;
}

//Get the pins from the api
void Pump::getPins()
{
    QJsonArray pins = DeviceManager::getInstance().getApi()->getRequestApi("/pump/" + QString::number(ID) + "/pins").array();
    for(int i = 0; i < pins.size(); i++){
        QJsonObject pinData = pins[i].toObject()["pin"].toObject();

        QString value = pinData["pinMode"].toString();
        int pin = pinData["pinNumber"].toString().toInt();

        if(value == "PWM")
            this->PWMPin = pin;
        else if(value == "OUTPUT")
            this->powerPin = pin;
    }
    initializePins();
    qDebug() << powerPin;
}
