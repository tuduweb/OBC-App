#include "MockPlugin.hpp"

#include "kernel.hpp"

bool MockPlugin::InitializePlugin(const QString &, const QJsonObject &)
{

    // MockKernelInterface* pluginIns = new MockKernelInterface;
    // auto kernel = pluginIns->CreateKernel();

    // qDebug() << kernel->GetKernelName();


    kernelInterface = std::make_shared<MockKernelInterface>();

    qDebug() << "hello Initalize Mock Plugin";
    return true;
}
