#include "SerialDataStream.hpp"

SerialDataStream::SerialDataStream()
{
    _serialThread = new SerialThread(this);
}

SerialDataStream::~SerialDataStream()
{
    //
}

int SerialDataStream::StreamInit()
{
    return 0;
}

int SerialDataStream::StreamStart()
{
    return 0;
}
