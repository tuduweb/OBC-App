#include <iostream>
#include <QDebug>

#include "utils/OBCHelpers.hpp"

#include <QApplication>

#include <QWidget>

#include <QSerialPort>
#include <QSerialPortInfo>

#include "core/handler/ConfigHandler.hpp"

#include "core/link/SerialLink.hpp"

//#include "plugin/examples/mock/kernel.hpp"

#include "plugin/examples/mock/MockPlugin.hpp"

int main(int argc, char *argv[])
{
    std::cout << "hello world!" << std::endl;
    qDebug() << "hello QT5!";

    qDebug() << Base64Encode("hello world");

    //如果你的应用程序是无界面的，直接使用QCoreApplication即可，如果是gui相关，但没有使用widgets模块的就使用QGuiApplication，否则使用QApplication。
    QApplication app(argc, argv);

    ConfigHandler* configHandler = new ConfigHandler;

    qDebug() << "ConfigHandler : " << configHandler;

    QWidget w;
    w.resize(500,400);
    w.show();

    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    for(const auto& item : portList) {
        qDebug() << "PortName : " << item.portName();
        qDebug() << "Description : " << item.description();
        qDebug() << "Manufacturer : " << item.manufacturer();
    }

    delete configHandler;

    // MockKernelInterface* pluginIns = new MockKernelInterface;
    // auto kernel = pluginIns->CreateKernel();

    // qDebug() << kernel->GetKernelName();

    MockPlugin* plugin = new MockPlugin;
    plugin->InitializePlugin("settings", QJsonObject{});

    return app.exec();
}
