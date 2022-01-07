#pragma once
#include "ui/OBCPlatformApplication.hpp"
namespace OBC
{
    class OBCWidgetApplication : public OBCPlatformApplication
    {
        Q_OBJECT
        public:
            explicit OBCWidgetApplication(int &argc, char *argv[]) : OBCPlatformApplication(argc, argv) {};

        private:
            OBCExitReason runOBCInternal() override {
                return (OBCExitReason) exec();
            };
            void terminateUIInternal() override {/*quit ui*/};

    };
};

#ifdef OBCApplication
#undef OBCApplication
#endif
#define OBCApplication OBCWidgetApplication

#define ObWidgetApplication static_cast<OBCWidgetApplication *>(qApp)
