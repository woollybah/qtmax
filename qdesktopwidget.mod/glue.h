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

#ifndef MAX_QT_QDESKTOPWIDGET
#define MAX_QT_QDESKTOPWIDGET

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QDesktopWidget>

class MaxQDesktopWidget;

extern "C" {

#include <blitz.h>

	BBObject * _qt_qdesktopwidget_QDesktopWidget___create(QDesktopWidget * widget);

	void _qt_qdesktopwidget_QDesktopWidget__OnResized(BBObject * handle, int screen);
	void _qt_qdesktopwidget_QDesktopWidget__OnWorkAreaResized(BBObject * handle, int screen);

	MaxQRect * bmx_qt_qdesktopwidget_availablegeometry(QDesktopWidget * dw, int screen);
	MaxQRect * bmx_qt_qdesktopwidget_availablegeometrywidget(QDesktopWidget * dw, QWidget * widget);
	MaxQRect * bmx_qt_qdesktopwidget_availablegeometryxy(QDesktopWidget * dw, int x, int y);
	int bmx_qt_qdesktopwidget_isvirtualdesktop(QDesktopWidget * dw);
	int bmx_qt_qdesktopwidget_numscreens(QDesktopWidget * dw);
	int bmx_qt_qdesktopwidget_primaryscreen(QDesktopWidget * dw);
	QWidget * bmx_qt_qdesktopwidget_screen(QDesktopWidget * dw, int screen);
	MaxQRect * bmx_qt_qdesktopwidget_screengeometry(QDesktopWidget * dw, int screen);
	MaxQRect * bmx_qt_qdesktopwidget_screengeometrywidget(QDesktopWidget * dw, QWidget * widget);
	MaxQRect * bmx_qt_qdesktopwidget_screengeometryxy(QDesktopWidget * dw, int x, int y);
	int bmx_qt_qdesktopwidget_screennumber(QDesktopWidget * dw, QWidget * widget);
	int bmx_qt_qdesktopwidget_screennumberxy(QDesktopWidget * dw, int x, int y);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQDesktopWidget : public MaxQObjectWrapper
{
	Q_OBJECT

public:
	MaxQDesktopWidget(BBObject * handle, QDesktopWidget * w);
	MaxQDesktopWidget(QDesktopWidget * w);
	
	QDesktopWidget * Widget();
	
	static void link(QDesktopWidget * a);
	
	~MaxQDesktopWidget();

private:
	void doConnections();
	QDesktopWidget * widget;
	
private slots:
	void onResized(int screen);
	void onWorkAreaResized(int screen);
	void onCustomContextMenuRequested(const QPoint & pos);

};

#endif
