#pragma once

#define OBC_PLUGIN_INTERFACE_VERSION 1
#include "PluginBase.hpp"

#include <QJsonObject>

namespace OBC::Plugin
{

    class PluginKernelInterface;
    class ObInterface;

    class ObInterface
    {
    public:
        //当前版本
        const int ObPluginInterfaceVersion = OBC_PLUGIN_INTERFACE_VERSION;
        virtual ~ObInterface() = default;
        //virtual const QvPluginMetadata GetMetadata() const = 0;
        virtual bool InitializePlugin(const QString &, const QJsonObject &) = 0;
    
        virtual std::shared_ptr<PluginKernelInterface> GetKernel() const final
        {
            return kernelInterface;
        }

    protected:
        explicit ObInterface() {};
        QJsonObject settings;
        std::shared_ptr<PluginKernelInterface> kernelInterface;
    
    };
};


#define DECLARE_PLUGIN_INSTANCE(CLASS) inline CLASS *CLASS##Instance

QT_BEGIN_NAMESPACE
#define ObInterface_IID "com.github.tuduweb.ObPluginInterface"
Q_DECLARE_INTERFACE(OBC::Plugin::ObInterface, ObInterface_IID)
QT_END_NAMESPACE