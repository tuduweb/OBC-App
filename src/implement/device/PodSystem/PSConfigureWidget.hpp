#pragma once
#include "ui/widgets/interface/ConfigureBaseWidget.hpp"

#include "ui_PSConfigureWidget.h"

#include "base/interface/DeviceInterface.hpp"

//namespace Ui { class PSConfigureWidget; };

//device interface?

//mixed control class
class PSConfigureWidget : public ConfigureBaseWidget, Ui::PSConfigureWidget
{
    Q_OBJECT
public:
    PSConfigureWidget(QWidget* parent = nullptr);
    ~PSConfigureWidget();
    void ReloadUI() override;
    QJsonObject GenerateConfigObject() override;

};