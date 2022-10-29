#include "YUVRender.hpp"
#include <QOpenGLTexture>
#include <QDebug>

void YUVRender::initialize()
{
	//Y0U0Y1V0
	initializeOpenGLFunctions();
	//顶点着色器源码
	const char* vsrc = "attribute vec4 vertexIn; \
        attribute vec2 textureIn; \
        varying vec2 textureOut;  \
        void main(void)           \
        {                         \
            gl_Position = vertexIn; \
            textureOut = textureIn; \
        }";

	/**
	* tex r g b a
	*	  y u y v
	**/
	//gl_TexCoord[0] -> textureOut
	const char* fsrc =
		"varying mediump vec2 textureOut;\n"
		"uniform sampler2D tex;\n"

		"uniform float texl_w;\n"
		"uniform float tex_h;\n"
		"uniform float tex_w;\n"

		"void main(void)\n"
		"{\n"
		"   float y, u, v;"
		"	vec3 yuv; \n"
		"	vec3 rgb; \n"
		"	vec2 xy = vec2(textureOut.xy);\n"
		"	vec4 luma_chroma;"
		"   float xcoord = floor(xy.x * tex_w);"
		"   float ycoord = floor(xy.y * tex_h);"

		"if (mod(xcoord, 2.0) == 0.0) {"
		"   luma_chroma = texture2D(tex, xy);"
		"   y = luma_chroma.r;"
		"} else {"
		"   luma_chroma = texture2D(tex, vec2(xy.x - texl_w, xy.y));"
		"   y = luma_chroma.b;"
		"}"
		"u = luma_chroma.g - 0.5;"
		"v = luma_chroma.a - 0.5;"

		"   y = (255.0 / 219.0) * (y - (16.0 / 255.0));"
		"   u = (255.0 / 224.0) * u;"
		"   v = (255.0 / 224.0) * v;"

		"	yuv.x = y; \n"
		"	yuv.y = u; \n"
		"	yuv.z = v; \n"
		"	rgb = mat3( 1,       1,         1, \n"
		"0,       -0.39465,  2.03211, \n"
		"1.13983, -0.58060,  0) * yuv; \n"
		"gl_FragColor = vec4(rgb, 1); \n"
		"}\n";

	program.addCacheableShaderFromSourceCode(QOpenGLShader::Vertex, vsrc);
	program.addCacheableShaderFromSourceCode(QOpenGLShader::Fragment, fsrc);
	program.link();

	GLfloat points[]{
		-1.0f, 1.0f,
		 1.0f, 1.0f,
		 1.0f, -1.0f,
		-1.0f, -1.0f,

		0.0f,0.0f,
		1.0f,0.0f,
		1.0f,1.0f,
		0.0f,1.0f
	};

	vbo.create();
	vbo.bind();
	vbo.allocate(points, sizeof(points));

	GLuint ids[1];
	glGenTextures(1, ids);
	idYUYV = ids[0];
}

// yuy2
void YUVRender::render(uchar* yuy2Ptr, int w, int h)
{
    if (!yuy2Ptr)return;

	glClearColor(0.5f, 0.5f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);

	program.bind();
	vbo.bind();
	program.enableAttributeArray("vertexIn");
	program.enableAttributeArray("textureIn");

	//被attribute修饰的变量是只能在vertex shader中使用的变量。attribute表示一些顶点的数据比如：顶点坐标，法线，纹理坐标，顶点颜色等。
	//location, type, offset, tupleSize, 一个顶底的所有字节数
	program.setAttributeBuffer("vertexIn", GL_FLOAT, 0, 2, 2 * sizeof(GLfloat));
	program.setAttributeBuffer("textureIn", GL_FLOAT, 2 * 4 * sizeof(GLfloat), 2, 2 * sizeof(GLfloat));

	/******************************************************************************************************************************/
	//测试：激活纹理，绑定到创建的opengl纹理
	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, idYUYV);
	//y0uy1v -> 行数/2 高度不变
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w >> 1, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, yuy2Ptr);
	//    glTexImage2D(GL_TEXTURE_2D,0,GL_RG,w >> 1,h >> 1,0,GL_RG,GL_UNSIGNED_BYTE,nv12Ptr + w*h);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	/******************************************************************************************************************************/



	//一致变量（Uniform Variables）
	//一致变量。在着色器执行期间一致变量的值是不变的。与const常量不同的是，这个值在编译时期是未知的是由着色器外部初始化的。一致变量在顶点着色器和片段着色器之间是共享的。它也只能在全局范围进行声明。
	program.setUniformValue("tex", 1);
	//texl_w
	int m_frameWidth = 1920, m_frameHeight = 1080;
	program.setUniformValue("tex_w", m_frameWidth);
	program.setUniformValue("tex1_w", GLfloat(1.0 / m_frameWidth));
	program.setUniformValue("tex_h", m_frameHeight);

	glDrawArrays(GL_QUADS, 0, 4);
	program.disableAttributeArray("vertexIn");
	program.disableAttributeArray("textureIn");

	////解绑//自己尝试添加的
	//glBindTexture(GL_TEXTURE_2D, 0);

	program.release();
}



/**
 * GL_NEAREST和GL_LINEAR

前者表示“使用纹理中坐标最接近的一个像素的颜色作为需要绘制的像素颜色”，

后者表示“使用纹理中坐标最接近的若干个颜色，通过加权平均算法得到需要绘制的像素颜色”。

前者只经过简单比较，需要运算较少，可能速度较快，

后者需要经过加权平均计算，其中涉及除法运算，可能速度较慢（但如果有专门的处理硬件，也可能两者速度相同）。

从视觉效果上看，前者效果较差，在一些情况下锯齿现象明显，后者效果会较好（但如果纹理图象本身比较大，则两者在视觉效果上就会比较接近）。
**/
