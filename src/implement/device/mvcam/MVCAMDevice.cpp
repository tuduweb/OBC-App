#include "MVCAMDevice.hpp"

MVCAMDevice::MVCAMDevice() {
    qDebug() << "hello mvcam";
}

int MVCAMDevice::DeviceInit()
{
    return 0;
}

int MVCAMDevice::DeviceDeinit()
{
    return 0;
}