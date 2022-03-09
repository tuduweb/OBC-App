#pragma once
#include "base/interface/DeviceInterface.hpp"

#include "qdebug.h"

#include "implement/device/PodSystem/PSConfigureWidget.hpp"

class PodSystemDevice : public DeviceInterface{
    Q_OBJECT

public:
    PodSystemDevice();
    int DeviceInit() override;
    int DeviceDeinit() override;

    // QWidget* configureWidget() const { return _configureWidget; }
    // QWidget* controlWidget() const { return _controlWidget; };

    virtual std::unique_ptr<ConfigureBaseWidget> createConfigureWidget() const override
    {
        return std::make_unique<PSConfigureWidget>();
    }

signals:
    void FrameArrived(const QImage& frame);
    void DataArrived(const QByteArray& data);

// protected:
//     ConfigureBaseWidget* _configureWidget;
//     ControlBaseWidget* _controlWidget;

};