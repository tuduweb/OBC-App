#pragma once
#include "base/interface/DisplayInterface.hpp"

#include "qdebug.h"

#include <QImage>
#include <QResizeEvent>

class FrameDisplayWidget : public DisplayInterface
{
public:
    FrameDisplayWidget() {
        sourceSize = QSize(400, 300);
        sourceScale = sourceSize.width() * 1.0 / sourceSize.height();
        qDebug() << "hello" << this;
        this->show(); update();
        };

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    
    void ResizeUI();
    void ResizeUI(const QSize& oldSize, const QSize& newSize);

public slots:
    void OnReceivedFrame(const QImage& _frame) override { frame = _frame; };

protected:
	QSize sourceSize;
	QSize renderSize;
	QRect renderRect;
	double scale;
	double sourceScale;

private:
    QImage frame;
};