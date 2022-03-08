#include "PodSystemDevice.hpp"

#include "core/stream/camera/RTSPCameraStream.hpp"
#include "core/stream/data/SerialDataStream.hpp"

PodSystemDevice::PodSystemDevice()
{
    //
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
        //
        connect(serialIns, &SerialDataStream::DataReceived, this, &PodSystemDevice::DataArrived);
        serialIns->StreamInit();
        serialIns->StreamStart();
    }

    return 0;
}

int PodSystemDevice::DeviceDeinit()
{
    return 0;
}
