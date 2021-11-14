#include "MockGUI.hpp"

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>

namespace OBC::Plugin{

    MockPluginSettingsWidget::MockPluginSettingsWidget(QWidget *parent) : OBC::Plugin::ObPluginSettingsWidget(parent)
    {
        qDebug() << "hello plugin gui : mock plugin";
        QLabel* label = new QLabel("hello world!", this);
        QHBoxLayout* layout = new QHBoxLayout;
        setLayout(layout);
        layout->addWidget(label);
    }
};