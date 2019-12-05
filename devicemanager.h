#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H


class DeviceManager
{
public:
        static DeviceManager& getInstance()
        {
            static DeviceManager instance;
            return instance;
        }

private:
       DeviceManager() {}

public:
       DeviceManager(DeviceManager const&) = delete;
       void operator=(DeviceManager const&) = delete;
};

#endif // DEVICEMANAGER_H
