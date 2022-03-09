#include "PodSystemDevice.hpp"

#include "core/stream/camera/RTSPCameraStream.hpp"
#include "core/stream/data/SerialDataStream.hpp"



PodSystemDevice::PodSystemDevice()
{
    _configureWidget = new PSConfigureWidget();
}

int PodSystemDevice::DeviceInit()
{
    //_streamInstances
    {
        StreamInterface* rtspIns = new RTSPCameraStream();
        _streamInstances.push_back(rtspIns);

        //rtspThread -> StreamIns -> Device -> output
        connect(rtspIns, &RTSPCameraStream::FrameReceived, this, &PodSystemDevice::FrameArrived);

        rtspIns->StreamInit();
        rtspIns->StreamStart();
    }

    {
        SerialDataStream* serialIns = new SerialDataStream();
        _streamInstances.push_back(serialIns);
        //根据streamType 绑定不同的channel
        //serialThread -> streamIns -> Device -> output
        connect(serialIns, &SerialDataStream::DataReceived, this, &PodSystemDevice::DataArrived);
        serialIns->StreamInit();
        serialIns->StreamStart();
    }

    //根据streamType能力 导出设备总能力

    return 0;
}

int PodSystemDevice::DeviceDeinit()
{
    return 0;
}
