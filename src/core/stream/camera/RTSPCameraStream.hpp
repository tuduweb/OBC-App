#pragma once

#include "base/OBCBaseHeader.hpp"
#include "base/interface/StreamInterface.hpp"
#include "qdebug.h"

class RTSPCameraStream : public StreamInterface
{
    public:
        RTSPCameraStream() { qDebug() << "hello stream"; };
        ~RTSPCameraStream() {};

        int StreamInit() { return 0; };
};