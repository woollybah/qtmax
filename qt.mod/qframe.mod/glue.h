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

#ifndef MAX_QT_QFRAME
#define MAX_QT_QFRAME

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QFrame>

class MaxQFrame;

extern "C" {

#include <blitz.h>

	QFrame * bmx_qt_qframe_create(BBObject * handle, QWidget * parent, int flags);
	void bmx_qt_qframe_framerect(QFrame * frame, int * x, int * y, int * w, int * h);
	int bmx_qt_qframe_frameshadow(QFrame * frame);
	int bmx_qt_qframe_frameshape(QFrame * frame);
	int bmx_qt_qframe_framestyle(QFrame * frame);
	int bmx_qt_qframe_framewidth(QFrame * frame);
	int bmx_qt_qframe_linewidth(QFrame * frame);
	int bmx_qt_qframe_midlinewidth(QFrame * frame);
	void bmx_qt_qframe_setframerect(QFrame * frame, int x, int y, int w, int h);
	void bmx_qt_qframe_setframeshadow(QFrame * frame, int shadow);
	void bmx_qt_qframe_setframeshape(QFrame * frame, int shape);
	void bmx_qt_qframe_setframestyle(QFrame * frame, int style);
	void bmx_qt_qframe_setlinewidth(QFrame * frame, int width);
	void bmx_qt_qframe_setmidlinewidth(QFrame * frame, int width);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFrame : public QFrame
{

public:
	MaxQFrame(BBObject * handle, QWidget * parent, Qt::WindowFlags flags);
	~MaxQFrame();

private:
	BBObject * maxHandle;

protected:
	void timerEvent(QTimerEvent * event);
};

#endif

