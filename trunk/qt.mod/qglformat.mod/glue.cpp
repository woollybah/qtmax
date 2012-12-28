/*
  Copyright (c) 2009 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQGLFormat::MaxQGLFormat()
	: format()
{
}

MaxQGLFormat::MaxQGLFormat(const QGLFormat & f)
	: format(f)
{
}

MaxQGLFormat::~MaxQGLFormat()
{
}

QGLFormat & MaxQGLFormat::Format() {
	return format;
}


// *********************************************

QGL::FormatOptions bmx_qt_formatOptionsFromInt(int o) {
	QGL::FormatOptions options;

	if (o & 0x0001) options |= QGL::DoubleBuffer;
	if (o & 0x0002) options |= QGL::DepthBuffer;
	if (o & 0x0004) options |= QGL::Rgba;
	if (o & 0x0008) options |= QGL::AlphaChannel;
	if (o & 0x0010) options |= QGL::AccumBuffer;
	if (o & 0x0020) options |= QGL::StencilBuffer;
	if (o & 0x0040) options |= QGL::StereoBuffers;
	if (o & 0x0080) options |= QGL::DirectRendering;
	if (o & 0x0100) options |= QGL::HasOverlay;
	if (o & 0x0200) options |= QGL::SampleBuffers;
	if (o & 0x0400) options |= QGL::DeprecatedFunctions;
	
	if (o & 0x0010000) options |= QGL::SingleBuffer;
	if (o & 0x0020000) options |= QGL::NoDepthBuffer;
	if (o & 0x0040000) options |= QGL::ColorIndex;
	if (o & 0x0080000) options |= QGL::NoAlphaChannel;
	if (o & 0x0100000) options |= QGL::NoAccumBuffer;
	if (o & 0x0200000) options |= QGL::NoStencilBuffer;
	if (o & 0x0400000) options |= QGL::NoStereoBuffers;
	if (o & 0x0800000) options |= QGL::IndirectRendering;
	if (o & 0x1000000) options |= QGL::NoOverlay;
	if (o & 0x2000000) options |= QGL::NoSampleBuffers;
	if (o & 0x4000000) options |= QGL::NoDeprecatedFunctions;

	return options;
}

QGLFormat::OpenGLVersionFlags bmx_qt_openglVersionFromInt(int v) {
	QGLFormat::OpenGLVersionFlags version;
	
	if (v & 0x0000000) version |= QGLFormat::OpenGL_Version_None;
	if (v & 0x0000001) version |= QGLFormat::OpenGL_Version_1_1;
	if (v & 0x0000002) version |= QGLFormat::OpenGL_Version_1_2;
	if (v & 0x0000004) version |= QGLFormat::OpenGL_Version_1_3;
	if (v & 0x0000008) version |= QGLFormat::OpenGL_Version_1_4;
	if (v & 0x0000010) version |= QGLFormat::OpenGL_Version_1_5;
	if (v & 0x0000020) version |= QGLFormat::OpenGL_Version_2_0;
	if (v & 0x0000040) version |= QGLFormat::OpenGL_Version_2_1;
	if (v & 0x0001000) version |= QGLFormat::OpenGL_Version_3_0;
	if (v & 0x0002000) version |= QGLFormat::OpenGL_Version_3_1;
	if (v & 0x0004000) version |= QGLFormat::OpenGL_Version_3_2;
	if (v & 0x0008000) version |= QGLFormat::OpenGL_Version_3_3;
	if (v & 0x0010000) version |= QGLFormat::OpenGL_Version_4_0;
	if (v & 0x0000100) version |= QGLFormat::OpenGL_ES_CommonLite_Version_1_0;
	if (v & 0x0000080) version |= QGLFormat::OpenGL_ES_Common_Version_1_0;
	if (v & 0x0000400) version |= QGLFormat::OpenGL_ES_CommonLite_Version_1_1;
	if (v & 0x0000200) version |= QGLFormat::OpenGL_ES_Common_Version_1_1;
	if (v & 0x0000800) version |= QGLFormat::OpenGL_ES_Version_2_0;
	
	return version;
}

QGLFormat::OpenGLContextProfile bmx_qt_openglContextProfileFromInt(int p) {
	switch (p) {
		case 0:
			return QGLFormat::NoProfile;
		case 1:
			return QGLFormat::CoreProfile;
		case 2:
			return QGLFormat::CompatibilityProfile;
	}
	
	return QGLFormat::NoProfile;
}


MaxQGLFormat * bmx_qt_qglformat_create(int formatOptions, int plane) {
	QGLFormat f(bmx_qt_formatOptionsFromInt(formatOptions), plane);
	return new MaxQGLFormat(f);
}

MaxQGLFormat * bmx_qt_qglformat_defaultformat() {
	return new MaxQGLFormat(QGLFormat::defaultFormat());
}

MaxQGLFormat * bmx_qt_qglformat_defaultoverlayformat() {
	return new MaxQGLFormat(QGLFormat::defaultOverlayFormat());
}

int bmx_qt_qglformat_hasopengl() {
	return static_cast<int>(QGLFormat::hasOpenGL());
}

int bmx_qt_qglformat_hasopengloverlays() {
	return static_cast<int>(QGLFormat::hasOpenGLOverlays());
}

int bmx_qt_qglformat_openglversionflags() {
	return static_cast<int>(QGLFormat::openGLVersionFlags());
}

void bmx_qt_qglformat_setdefaultformat(MaxQGLFormat * format) {
	QGLFormat::setDefaultFormat(format->Format());
}

void bmx_qt_qglformat_setdefaultoverayformat(MaxQGLFormat * format) {
	QGLFormat::setDefaultOverlayFormat(format->Format());
}

int bmx_qt_qglformat_accum(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().accum());
}

int bmx_qt_qglformat_accumbuffersize(MaxQGLFormat * format) {
	return format->Format().accumBufferSize();
}

int bmx_qt_qglformat_alpha(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().alpha());
}

int bmx_qt_qglformat_alphabuffersize(MaxQGLFormat * format) {
	return format->Format().alphaBufferSize();
}

int bmx_qt_qglformat_bluebuffersize(MaxQGLFormat * format) {
	return format->Format().blueBufferSize();
}

int bmx_qt_qglformat_depth(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().depth());
}

int bmx_qt_qglformat_depthbuffersize(MaxQGLFormat * format) {
	return format->Format().depthBufferSize();
}

int bmx_qt_qglformat_directrendering(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().directRendering());
}

int bmx_qt_qglformat_doublebuffer(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().doubleBuffer());
}

int bmx_qt_qglformat_greenbuffersize(MaxQGLFormat * format) {
	return format->Format().greenBufferSize();
}

int bmx_qt_qglformat_hasoverlay(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().hasOverlay());
}

int bmx_qt_qglformat_majorversion(MaxQGLFormat * format) {
	return format->Format().majorVersion();
}

int bmx_qt_qglformat_minorversion(MaxQGLFormat * format) {
	return format->Format().minorVersion();
}

int bmx_qt_qglformat_plane(MaxQGLFormat * format) {
	return format->Format().plane();
}

int bmx_qt_qglformat_profile(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().profile());
}

int bmx_qt_qglformat_redbuffersize(MaxQGLFormat * format) {
	return format->Format().redBufferSize();
}

int bmx_qt_qglformat_rgba(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().rgba());
}

int bmx_qt_qglformat_samplebuffers(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().sampleBuffers());
}

int bmx_qt_qglformat_samples(MaxQGLFormat * format) {
	return format->Format().samples();
}

void bmx_qt_qglformat_setaccum(MaxQGLFormat * format, int enable) {
	format->Format().setAccum(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setaccumbuffersize(MaxQGLFormat * format, int size) {
	format->Format().setAccumBufferSize(size);
}

void bmx_qt_qglformat_setalpha(MaxQGLFormat * format, int enable) {
	format->Format().setAlpha(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setalphabuffersize(MaxQGLFormat * format, int size) {
	format->Format().setAlphaBufferSize(size);
}

void bmx_qt_qglformat_setbluebuffersize(MaxQGLFormat * format, int size) {
	format->Format().setBlueBufferSize(size);
}

void bmx_qt_qglformat_setdepth(MaxQGLFormat * format, int enable) {
	format->Format().setDepth(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setdepthbuffersize(MaxQGLFormat * format, int size) {
	format->Format().setDepthBufferSize(size);
}

void bmx_qt_qglformat_setdirectrendering(MaxQGLFormat * format, int enable) {
	format->Format().setDirectRendering(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setdoublebuffer(MaxQGLFormat * format, int enable) {
	format->Format().setDoubleBuffer(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setgreenbuffersize(MaxQGLFormat * format, int size) {
	format->Format().setGreenBufferSize(size);
}

void bmx_qt_qglformat_setoption(MaxQGLFormat * format, int opt) {
	format->Format().setOption(bmx_qt_formatOptionsFromInt(opt));
}

void bmx_qt_qglformat_setoverlay(MaxQGLFormat * format, int enable) {
	format->Format().setOverlay(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setplane(MaxQGLFormat * format, int plane) {
	format->Format().setPlane(plane);
}

void bmx_qt_qglformat_setprofile(MaxQGLFormat * format, int profile) {
	format->Format().setProfile(bmx_qt_openglContextProfileFromInt(profile));
}

void bmx_qt_qglformat_setredbuffersize(MaxQGLFormat * format, int size) {
	format->Format().setRedBufferSize(size);
}

void bmx_qt_qglformat_setrgba(MaxQGLFormat * format, int enable) {
	format->Format().setRgba(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setsamplebuffers(MaxQGLFormat * format, int enable) {
	format->Format().setSampleBuffers(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setsamples(MaxQGLFormat * format, int numSamples) {
	format->Format().setSamples(numSamples);
}

void bmx_qt_qglformat_setstencil(MaxQGLFormat * format, int enable) {
	format->Format().setStencil(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setstencilbuffersize(MaxQGLFormat * format, int size) {
	format->Format().setStencilBufferSize(size);
}

void bmx_qt_qglformat_setstereo(MaxQGLFormat * format, int enable) {
	format->Format().setStereo(static_cast<bool>(enable));
}

void bmx_qt_qglformat_setswapinterval(MaxQGLFormat * format, int interval) {
	format->Format().setSwapInterval(interval);
}

void bmx_qt_qglformat_setversion(MaxQGLFormat * format, int major, int minor) {
	format->Format().setVersion(major, minor);
}

int bmx_qt_qglformat_stencil(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().stencil());
}

int bmx_qt_qglformat_stencilbuffersize(MaxQGLFormat * format) {
	return format->Format().stencilBufferSize();
}

int bmx_qt_qglformat_stereo(MaxQGLFormat * format) {
	return static_cast<int>(format->Format().stereo());
}

int bmx_qt_qglformat_swapinterval(MaxQGLFormat * format) {
	return format->Format().swapInterval();
}

int bmx_qt_qglformat_testoption(MaxQGLFormat * format, int opt) {
	return static_cast<int>(format->Format().accum());
}

void bmx_qt_qglformat_free(MaxQGLFormat * format) {
	delete format;
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
