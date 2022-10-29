#ifndef YUVRENDER_H
#define YUVRENDER_H
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class YUVRender : public QOpenGLFunctions
{
public:
    YUVRender() = default;
    YUVRender(const YUVRender&) = delete;
    void initialize();
    void render(uchar*yuy2Ptr, int w, int h);

private:
    QOpenGLShaderProgram program;
	GLuint idYUYV;
    QOpenGLBuffer vbo;
};

#endif // NV12RENDER_H
