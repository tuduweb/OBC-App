#include "PSConfigureWidget.hpp"

#include "PodSystemDevice.hpp"

#include <qDebug>

PSConfigureWidget::PSConfigureWidget(QWidget* parent) : ConfigureBaseWidget(parent) {
    setupUi(this);

    this->ReloadUI();

}

PSConfigureWidget::~PSConfigureWidget()
{
    qDebug() << "destory PS Configure Widget" << this;
}

void PSConfigureWidget::ReloadUI()
{
    //QStringList deviceList = PodSystemDevice::
    //获取deviceList

    QStringList deviceList{};
    deviceList.append("cu.usbmodem0001A00000011");
    deviceList.append("tty.usbmodem0001A00000011");
    deviceList.append("ssh.usbmodem0001A00000011");

    deviceComboBox->addItems(deviceList);
}

QJsonObject PSConfigureWidget::GenerateConfigObject()
{
    return QJsonObject{
        {"deviceName" , "cu.usbmodem0001A00000011"}
    };
}