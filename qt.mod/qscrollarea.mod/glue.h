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

#ifndef MAX_QT_QSCROLLAREA
#define MAX_QT_QSCROLLAREA

#include "../core.mod/glue.h"
#include <QtCore>
#include <QScrollArea>

class MaxQScrollArea;

extern "C" {

#include <blitz.h>

	QScrollArea * bmx_qt_qscrollarea_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qscrollarea_alignment(QScrollArea * sa);
	void bmx_qt_qscrollarea_ensurevisible(QScrollArea * sa, int x, int y, int xmargin, int ymargin);
	void bmx_qt_qscrollarea_ensurewidgetvisible(QScrollArea * sa, QWidget * childWidget, int xmargin, int ymargin);
	void bmx_qt_qscrollarea_setalignment(QScrollArea * sa, int alignment);
	void bmx_qt_qscrollarea_setwidget(QScrollArea * sa, QWidget * widget);
	void bmx_qt_qscrollarea_setwidgetresizable(QScrollArea * sa, int resizable);
	QWidget * bmx_qt_qscrollarea_takewidget(QScrollArea * sa);
	QWidget * bmx_qt_qscrollarea_widget(QScrollArea * sa);
	int bmx_qt_qscrollarea_widgetresizable(QScrollArea * sa);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQScrollArea : public QScrollArea
{
public:
	MaxQScrollArea(BBObject * handle, QWidget * parent);
	~MaxQScrollArea();

private:
	BBObject * maxHandle;
};

#endif
