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

#ifndef MAX_QT_QPROGRESSBAR
#define MAX_QT_QPROGRESSBAR

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QProgressBar>

class MaxQProgressBar;

extern "C" {

#include <blitz.h>

	void _qt_qprogressbar_QProgressBar__OnValueChanged(BBObject * , int value);
	
	QProgressBar * bmx_qt_qprogressbar_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qprogressbar_alignment(QProgressBar * bar);
	BBString * bmx_qt_qprogressbar_format(QProgressBar * bar);
	int bmx_qt_qprogressbar_invertedappearance(QProgressBar * bar);
	int bmx_qt_qprogressbar_istextvisible(QProgressBar * bar);
	int bmx_qt_qprogressbar_maximum(QProgressBar * bar);
	int bmx_qt_qprogressbar_minimum(QProgressBar * bar);
	int bmx_qt_qprogressbar_orientation(QProgressBar * handle);
	void bmx_qt_qprogressbar_setalignment(QProgressBar * handle, int alignment);
	void bmx_qt_qprogressbar_setformat(QProgressBar * handle, BBString * format);
	void bmx_qt_qprogressbar_setinvertedappearance(QProgressBar * handle, int invert);
	void bmx_qt_qprogressbar_settextdirection(QProgressBar * handle, int textDirection);
	void bmx_qt_qprogressbar_settextvisible(QProgressBar * handle, int visible);
	BBString * bmx_qt_qprogressbar_text(QProgressBar * handle);
	int bmx_qt_qprogressbar_textdirection(QProgressBar * handle);
	int bmx_qt_qprogressbar_value(QProgressBar * handle);
	void bmx_qt_qprogressbar_reset(QProgressBar * handle);
	void bmx_qt_qprogressbar_setmaximum(QProgressBar * handle, int maximum);
	void bmx_qt_qprogressbar_setminimum(QProgressBar * handle, int minimum);
	void bmx_qt_qprogressbar_setorientation(QProgressBar * handle, int orientation);
	void bmx_qt_qprogressbar_setrange(QProgressBar * handle, int minimum, int maximum);
	void bmx_qt_qprogressbar_setvalue(QProgressBar * handle, int value);

	QProgressBar::Direction bmx_qt_getprogressbardirection(int dir);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQProgressBar : public QProgressBar
{

	Q_OBJECT

public:
	MaxQProgressBar(BBObject * handle, QWidget * parent);
	~MaxQProgressBar();

private:
	BBObject * maxHandle;

private slots:
	void onValueChanged(int value);
	void onCustomContextMenuRequested(const QPoint & pos);

};

#endif
