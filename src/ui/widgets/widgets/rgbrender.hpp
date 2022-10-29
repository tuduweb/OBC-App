#pragma once

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class RGBRender : public QOpenGLFunctions
{
public:
    RGBRender() = default;
    RGBRender(const RGBRender&) = delete;
    void initialize();
    void render(uchar*yuy2Ptr, int w, int h);

private:
    QOpenGLShaderProgram program;
	GLuint idYUYV;
    QOpenGLBuffer vbo;
};

