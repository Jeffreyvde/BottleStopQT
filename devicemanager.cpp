#include "devicemanager.h"

//Initialize the devicemanager. This happens when the singelton is first called.
DeviceManager::DeviceManager()
{
    serialPort = new SerialWrapper();
}
