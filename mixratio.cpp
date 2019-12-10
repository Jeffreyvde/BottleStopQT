#include "mixratio.h"
#include "devicemanager.h"

MixRatio::MixRatio(QString pumpName, double ratio)
{
    this->ratio = ratio;
    pump = &DeviceManager::getInstance().getPumpFromMap(pumpName);
}

