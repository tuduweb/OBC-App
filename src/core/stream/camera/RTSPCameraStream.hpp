#pragma once

#include "base/OBCBaseHeader.hpp"
#include "base/interface/StreamInterface.hpp"
#include "qdebug.h"

#include "3rdparty/OBC-data-ffmpeg/src/RTSPThread.hpp"

class RTSPCameraStream : public StreamInterface
{
    public:
        RTSPCameraStream();
        ~RTSPCameraStream();

        int StreamInit() override;
        int StreamStart() override;
    public:
        RTSPThread* rtspThread;
};