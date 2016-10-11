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

#ifndef MAX_QT_QSTATUSBAR
#define MAX_QT_QSTATUSBAR

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QStatusBar>

class MaxQStatusBar;

extern "C" {

#include <blitz.h>

	void _qt_qstatusbar_QStatusBar__OnMessageChanged(BBObject * handle, BBString * message);

	QStatusBar * bmx_qt_qstatusbar_create(BBObject * handle, QWidget  * parent);
	void bmx_qt_qstatusbar_addpermanentwidget(QStatusBar * sb, QWidget * widget, int stretch);
	void bmx_qt_qstatusbar_addwidget(QStatusBar * sb, QWidget * widget, int stretch);
	BBString * bmx_qt_qstatusbar_currentmessage(QStatusBar * sb);
	int bmx_qt_qstatusbar_insertpermanentwidget(QStatusBar * sb, int index, QWidget * widget, int stretch);
	int bmx_qt_qstatusbar_insertwidget(QStatusBar * sb, int index, QWidget * widget, int stretch);
	int bmx_qt_qstatusbar_issizegripenabled(QStatusBar * sb);
	void bmx_qt_qstatusbar_removewidget(QStatusBar * sb, QWidget * widget);
	void bmx_qt_qstatusbar_setsizegripenabled(QStatusBar * sb, int value);
	void bmx_qt_qstatusbar_clearmessage(QStatusBar * sb);
	void bmx_qt_qstatusbar_showmessage(QStatusBar * sb, BBString * message, int timeout);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQStatusBar : public QStatusBar
{
	Q_OBJECT
	
public:
	MaxQStatusBar(BBObject * handle, QWidget * parent);
	~MaxQStatusBar();

private:
	BBObject * maxHandle;
	
private slots:
	void onMessageChanged(const QString & message);
	void onCustomContextMenuRequested(const QPoint & pos);
};

#endif
