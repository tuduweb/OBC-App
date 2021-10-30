#pragma once

#include <QThread>

namespace OBC::core::link
{
    class SerialLink : public QThread
    {
        SerialLink() {}
        ~SerialLink() {}
    };
};