#pragma once
#include "base/interface/DisplayInterface.hpp"

#include "qdebug.h"

#include <QImage>
#include <QResizeEvent>

#include <QOpenGLWidget>

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>


#include "yuvrender.hpp"
#include "rgbrender.hpp"
#include <QTimer>
class FrameOpenGLWidget : public QOpenGLWidget{

public:
	FrameOpenGLWidget() {
		m_render = new RGBRender;

		QImage frametmp;
		frametmp.load("C:/Users/bin/Desktop/1234.jpeg");
		
		frame = frametmp;

		qDebug() << frame.format();


		QTimer *fpsTimer = new QTimer;
		connect(fpsTimer, &QTimer::timeout, this, [&]() {
			qDebug() << "fps:" << m_fpsCounter.m_value;
			});

		fpsTimer->start(100);

	}

	~FrameOpenGLWidget() {
		deleteLater();
		delete m_render;
		m_render = nullptr;
	}
public slots:
	void RenderLater(const QImage& image) {
		frame = image;
		update();
	}

protected:
	void initializeGL() override;
	void paintGL() override;
	//void mouseMoveEvent(QMouseEvent* event) override;

private:
	//QOpenGLShaderProgram* program;

	//QOpenGLVertexArrayObject vao;
	//QOpenGLBuffer vbo;

	FPSCounter m_fpsCounter;

private:
	RGBRender* m_render;

	QImage frame;

	QVector<int> m_renderTime;
};

#include <QVBoxLayout>

class FrameDisplayGLWidget : public DisplayInterface
{
public:
	FrameDisplayGLWidget() {
		qDebug() << "hello" << this;
		QVBoxLayout* layout = new QVBoxLayout;

		setLayout(layout);

		glWidget = new FrameOpenGLWidget;

		layout->addWidget(glWidget);
	}

	~FrameDisplayGLWidget() {
		delete glWidget;
		glWidget = nullptr;
	}

public slots:
	void OnFrameReceived(const QImage& _frame) { glWidget->RenderLater(_frame); };

private:
	FrameOpenGLWidget *glWidget;
	QImage frame;
};