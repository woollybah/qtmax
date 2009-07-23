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

#ifndef BMX_QT_QWIDGET
#define BMX_QT_QWIDGET

#include "../core.mod/glue.h"
#include <QWidget>

class MaxQWidget;

extern "C" {

#include <blitz.h>

	void _qt_qwidget_QWidget__OnCustomContextMenuRequested(BBObject * handle, int x, int y);


	QWidget * bmx_qt_qwidget_create(BBObject * handle, QWidget * parent, int f);
	void bmx_qt_qwidget_hide(QWidget * widget);
	void bmx_qt_qwidget_show(QWidget * widget);
	void bmx_qt_qwidget_setlayout(QWidget * widget, QLayout * layout);
	void bmx_qt_qwidget_setwindowtitle(QWidget * widget, BBString * title);

	void bmx_qt_qwidget_showfullscreen(QWidget * widget);
	void bmx_qt_qwidget_showmaximized(QWidget * widget);
	void bmx_qt_qwidget_showminimized(QWidget * widget);
	void bmx_qt_qwidget_shownormal(QWidget * widget);
	void bmx_qt_qwidget_stackunder(QWidget * widget, QWidget * w);
	void bmx_qt_qwidget_setfixedsize(QWidget * widget, int w, int h);
	void bmx_qt_qwidget_setfixedwidth(QWidget * widget, int w);
	void bmx_qt_qwidget_setfocus(QWidget * widget, int reason);
	void bmx_qt_qwidget_close(QWidget * widget);
	void bmx_qt_qwidget_update(QWidget * widget);
	void bmx_qt_qwidget_raise(QWidget * widget);
	void bmx_qt_qwidget_repaint(QWidget * widget);
	void bmx_qt_qwidget_setdisabled(QWidget * widget, int disable);
	void bmx_qt_qwidget_setenabled(QWidget * widget, int value);
	void bmx_qt_qwidget_sethidden(QWidget * widget, int hidden);
	void bmx_qt_qwidget_setstylesheet(QWidget * widget, BBString * styleSheet);
	void bmx_qt_qwidget_setvisible(QWidget * widget, int visible);
	void bmx_qt_qwidget_setwindowmodified(QWidget * widget, int value);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQWidget : public QWidget
{
	Q_OBJECT

public:
	MaxQWidget(BBObject * handle, QWidget * parent, Qt::WindowFlags flags);
	~MaxQWidget();

private:
	BBObject * maxHandle;
};


#endif
