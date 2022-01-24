#pragma once
#include "base/interface/DeviceInterface.hpp"

#include "qdebug.h"

class MVCAMDevice : public DeviceInterface{
public:
    MVCAMDevice();
    int DeviceInit() override;
    int DeviceDeinit() override;

};