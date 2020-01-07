#include "mixratio.h"
#include "devicemanager.h"

MixRatio::MixRatio(int pumpID, double ratio)
{
    this->ratio = ratio;
    pump = DeviceManager::getInstance().getPump(pumpID);
}

