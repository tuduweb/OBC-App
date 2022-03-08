#pragma once
#include "base/interface/DeviceInterface.hpp"

#include "qdebug.h"

class PodSystemDevice : public DeviceInterface{
    Q_OBJECT

public:
    PodSystemDevice();
    int DeviceInit() override;
    int DeviceDeinit() override;

signals:
    void FrameArrived(const QImage& frame);
    void DataArrived(const QByteArray& data);

};