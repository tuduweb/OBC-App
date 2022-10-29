#include "FrameDisplayGLWidget.hpp"

void FrameOpenGLWidget::initializeGL()
{
	m_render->initialize();
}


void FrameOpenGLWidget::paintGL()
{
	m_render->render(frame.bits(), frame.width(), frame.height());

	m_fpsCounter.refreshFPS();
}
