#include "w_MainWindow.hpp"

#include "qdebug.h"

#include "ui/widgets/widgets/NormalDisplayWidget.hpp"

#include "core/stream/camera/RTSPCameraStream.hpp"

#include "ui/widgets/widgets/FrameDisplayWidget.hpp"
#include "ui/widgets/widgets/FrameDisplayGLWidget.hpp"

#include "base/interface/DeviceInterface.hpp"

#include "implement/device/mvcam/MVCAMDevice.hpp"

#include "implement/device/PodSystem/PodSystemDevice.hpp"

#include "core/stream/data/SerialDataStream.hpp"

#include "3rdparty/OBC-data-ffmpeg/src/RTSPThread.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    setupUi(this);
    qDebug() << "show show show";

    //OBC::ui::NormalDisplayWidget* display = new OBC::ui::NormalDisplayWidget;
    //videoWidgetLayout->addWidget(display);

    PodSystemDevice* podSystem = new PodSystemDevice();
    _device = podSystem;

#define DISPLAY_WIDGET FrameDisplayGLWidget

    DISPLAY_WIDGET* frameDisplayWidget = new DISPLAY_WIDGET();
    videoWidgetLayout->addWidget(frameDisplayWidget);

    // RTSPCameraStream* rtspStream = new RTSPCameraStream();
    // connect(rtspStream, &RTSPCameraStream::FrameReceived, frameDisplayWidget, &FrameDisplayWidget::OnFrameReceived);
    // rtspStream->StreamInit();
    // rtspStream->StreamStart();

    //connect(podSystem, &PodSystemDevice::FrameArrived, frameDisplayWidget, &FrameDisplayGLWidget::OnFrameReceived);
    //podSystem->DeviceInit();

    MVCAMDevice* device = new MVCAMDevice();


    SerialDataStream* serialStream = new SerialDataStream();
    serialStream->StreamStart();


    RTSPThread* rtspThread = new RTSPThread(this);

    rtspThread->setUrl("rtsp://");

    //connect(rtspThread, &RTSPThread::NewFrameArrived, this, [](const QImage& image) {
    //    qDebug() << image;
    //    }
    //    );

    connect(rtspThread, &RTSPThread::NewFrameArrived, frameDisplayWidget, &DISPLAY_WIDGET::OnFrameReceived);


    rtspThread->start();


}

#include "ui/widgets/editors/w_RemoteEditor.hpp"

void MainWindow::on_remotes_btn_clicked()
{
    //RemoteEditor w(QJsonObject{}, this);
    RemoteEditor w(_device, this);
    //RemoteObject object;_device

    QJsonObject conf = w.OpenEditor();//其实没有返回数据的吧..
}

void MainWindow::on_remoteStart_btn_clicked()
{
    //
    //_device->
    // link device to other models
}
