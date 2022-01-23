#include "RTSPCameraStream.hpp"

RTSPCameraStream::RTSPCameraStream() : rtspThread(nullptr)
{
    qDebug() << "hello stream";

}

RTSPCameraStream::~RTSPCameraStream() {
    rtspThread->exit();
}

int RTSPCameraStream::StreamInit()
{

    qDebug() << "new RTSPThread";
    rtspThread = new RTSPThread(this);
    connect(rtspThread, &RTSPThread::NewFrameArrived, this, &RTSPCameraStream::FrameReceived);
    return 0;
}

int RTSPCameraStream::StreamStart()
{
    rtspThread->start();
    return 0;
}