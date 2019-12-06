#include "devicemanager.h"

DeviceManager::DeviceManager()
{
    serialPort = new SerialWrapper();
}
