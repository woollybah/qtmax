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

#ifndef MAX_QT_QSTACKEDWIDGET
#define MAX_QT_QSTACKEDWIDGET

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QStackedWidget>

class MaxQStackedWidget;

extern "C" {

#include <blitz.h>

	void _qt_qstackedwidget_QStackedWidget__OnCurrentChanged(BBObject * handle, int index);
	void _qt_qstackedwidget_QStackedWidget__OnWidgetRemoved(BBObject * handle, int index);

	QStackedWidget * bmx_qt_qstackedwidget_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qstackedwidget_addwidget(QStackedWidget * sw, QWidget * widget);
	int bmx_qt_qstackedwidget_count(QStackedWidget * sw);
	int bmx_qt_qstackedwidget_currentindex(QStackedWidget * sw);
	QWidget * bmx_qt_qstackedwidget_currentwidget(QStackedWidget * sw);
	int bmx_qt_qstackedwidget_indexof(QStackedWidget * sw, QWidget * widget);
	int bmx_qt_qstackedwidget_insertwidget(QStackedWidget * sw, int index, QWidget * widget);
	void bmx_qt_qstackedwidget_removewidget(QStackedWidget * sw, QWidget * widget);
	QWidget * bmx_qt_qstackedwidget_widget(QStackedWidget * sw, int index);
	void bmx_qt_qstackedwidget_setcurrentindex(QStackedWidget * sw, int index);
	void bmx_qt_qstackedwidget_setcurrentwidget(QStackedWidget * sw, QWidget * widget);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQStackedWidget : public QStackedWidget
{
	Q_OBJECT
	
public:
	MaxQStackedWidget(BBObject * handle, QWidget * parent);
	~MaxQStackedWidget();

private:
	BBObject * maxHandle;
	
private slots:
	void onCurrentChanged(int index);
	void onWidgetRemoved(int index);
	void onCustomContextMenuRequested(const QPoint & pos);
};

#endif
