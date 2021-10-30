#pragma once
#include <QThread>

namespace OBC::core::link{

	class LinkInterface : public QThread
	{
        Q_OBJECT

    public:
        LinkInterface() {}
        ~LinkInterface() {}

        bool isConnected() const { return false; }
        
    };

};
