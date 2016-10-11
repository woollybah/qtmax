/*
  Copyright (c) 2009-2013 Bruce A Henderson
 
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

#ifndef MAX_QT_QGLFORMAT
#define MAX_QT_QGLFORMAT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QGLFormat>

class MaxQGLFormat;

extern "C" {

#include <blitz.h>

	MaxQGLFormat * bmx_qt_qglformat_create(int formatOptions, int plane);
	MaxQGLFormat * bmx_qt_qglformat_defaultformat();
	MaxQGLFormat * bmx_qt_qglformat_defaultoverlayformat();
	int bmx_qt_qglformat_hasopengl();
	int bmx_qt_qglformat_hasopengloverlays();
	int bmx_qt_qglformat_openglversionflags();
	void bmx_qt_qglformat_setdefaultformat(MaxQGLFormat * format);
	void bmx_qt_qglformat_setdefaultoverayformat(MaxQGLFormat * format);
	int bmx_qt_qglformat_accum(MaxQGLFormat * format);
	int bmx_qt_qglformat_accumbuffersize(MaxQGLFormat * format);
	int bmx_qt_qglformat_alpha(MaxQGLFormat * format);
	int bmx_qt_qglformat_alphabuffersize(MaxQGLFormat * format);
	int bmx_qt_qglformat_bluebuffersize(MaxQGLFormat * format);
	int bmx_qt_qglformat_depth(MaxQGLFormat * format);
	int bmx_qt_qglformat_depthbuffersize(MaxQGLFormat * format);
	int bmx_qt_qglformat_directrendering(MaxQGLFormat * format);
	int bmx_qt_qglformat_doublebuffer(MaxQGLFormat * format);
	int bmx_qt_qglformat_greenbuffersize(MaxQGLFormat * format);
	int bmx_qt_qglformat_hasoverlay(MaxQGLFormat * format);
	int bmx_qt_qglformat_majorversion(MaxQGLFormat * format);
	int bmx_qt_qglformat_minorversion(MaxQGLFormat * format);
	int bmx_qt_qglformat_plane(MaxQGLFormat * format);
	int bmx_qt_qglformat_profile(MaxQGLFormat * format);
	int bmx_qt_qglformat_redbuffersize(MaxQGLFormat * format);
	int bmx_qt_qglformat_rgba(MaxQGLFormat * format);
	int bmx_qt_qglformat_samplebuffers(MaxQGLFormat * format);
	int bmx_qt_qglformat_samples(MaxQGLFormat * format);
	void bmx_qt_qglformat_setaccum(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setaccumbuffersize(MaxQGLFormat * format, int size);
	void bmx_qt_qglformat_setalpha(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setalphabuffersize(MaxQGLFormat * format, int size);
	void bmx_qt_qglformat_setbluebuffersize(MaxQGLFormat * format, int size);
	void bmx_qt_qglformat_setdepth(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setdepthbuffersize(MaxQGLFormat * format, int size);
	void bmx_qt_qglformat_setdirectrendering(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setdoublebuffer(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setgreenbuffersize(MaxQGLFormat * format, int size);
	void bmx_qt_qglformat_setoption(MaxQGLFormat * format, int opt);
	void bmx_qt_qglformat_setoverlay(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setplane(MaxQGLFormat * format, int plane);
	void bmx_qt_qglformat_setprofile(MaxQGLFormat * format, int profile);
	void bmx_qt_qglformat_setredbuffersize(MaxQGLFormat * format, int size);
	void bmx_qt_qglformat_setrgba(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setsamplebuffers(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setsamples(MaxQGLFormat * format, int numSamples);
	void bmx_qt_qglformat_setstencil(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setstencilbuffersize(MaxQGLFormat * format, int size);
	void bmx_qt_qglformat_setstereo(MaxQGLFormat * format, int enable);
	void bmx_qt_qglformat_setswapinterval(MaxQGLFormat * format, int interval);
	void bmx_qt_qglformat_setversion(MaxQGLFormat * format, int major, int minor);
	int bmx_qt_qglformat_stencil(MaxQGLFormat * format);
	int bmx_qt_qglformat_stencilbuffersize(MaxQGLFormat * format);
	int bmx_qt_qglformat_stereo(MaxQGLFormat * format);
	int bmx_qt_qglformat_swapinterval(MaxQGLFormat * format);
	int bmx_qt_qglformat_testoption(MaxQGLFormat * format, int opt);
	void bmx_qt_qglformat_free(MaxQGLFormat * format);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGLFormat
{
public:
	MaxQGLFormat();
	MaxQGLFormat(const QGLFormat & f);
	~MaxQGLFormat();
	
	QGLFormat & Format();

private:
	QGLFormat format;
};

#endif
