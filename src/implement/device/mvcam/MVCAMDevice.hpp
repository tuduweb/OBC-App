#pragma once
#include "base/interface/DeviceInterface.hpp"

#include "qdebug.h"

#include "implement/device/PodSystem/PSConfigureWidget.hpp"

class MVCAMDevice : public DeviceInterface{
public:
    MVCAMDevice();
    int DeviceInit() override;
    int DeviceDeinit() override;

    virtual std::unique_ptr<ConfigureBaseWidget> createConfigureWidget() const override
    {
        return std::make_unique<PSConfigureWidget>();
    }

};