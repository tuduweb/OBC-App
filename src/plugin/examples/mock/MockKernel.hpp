#pragma once

#include "PluginProcessor.hpp"
#include <QDebug>

class MockKernel : public OBC::Plugin::PluginKernel
{
    public:
        explicit MockKernel() {};
        ~MockKernel() {};
        QString GetKernelName() const override
        {
            return "Mock";
        }
};

//rename to MockKernelInterface
class MockKernelInterface : public OBC::Plugin::PluginKernelInterface
{
  public:
    virtual std::unique_ptr<OBC::Plugin::PluginKernel> CreateKernel() const override
    {
        qDebug() << "Create Kernel";
        return std::make_unique<MockKernel>();
    }
    virtual QList<QString> GetKernelProtocols() const override
    {
        return { "mocktest" };
    }
};