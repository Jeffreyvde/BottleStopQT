#include "mixratio.h"
#include "devicemanager.h"

MixRatio::MixRatio(int ingredientID, double ratio)
{
    this->ratio = ratio;
    pump = DeviceManager::getInstance().getPump(ingredientID);
}

