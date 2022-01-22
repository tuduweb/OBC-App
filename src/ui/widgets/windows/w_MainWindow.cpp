#include "w_MainWindow.hpp"

#include "qdebug.h"

#include "ui/widgets/widgets/NormalDisplayWidget.hpp"

#include "core/stream/camera/RTSPCameraStream.hpp"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    qDebug() << "show show show";

    OBC::ui::NormalDisplayWidget* display = new OBC::ui::NormalDisplayWidget;
    videoWidgetLayout->addWidget(display);

    RTSPCameraStream* camera = new RTSPCameraStream();
}

#include "ui/widgets/editors/w_RemoteEditor.hpp"

void MainWindow::on_remotes_btn_clicked()
{
	RemoteEditor w(QJsonObject{}, this);
	//RemoteObject object;

    w.OpenEditor();//其实没有返回数据的吧..
}
