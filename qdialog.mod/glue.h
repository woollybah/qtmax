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

#ifndef MAX_QT_QDIALOG
#define MAX_QT_QDIALOG

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QDialog>

class MaxQDialog;

extern "C" {

#include <blitz.h>

	void _qt_qdialog_QDialog__OnAccepted(BBObject * handle);
	void _qt_qdialog_QDialog__OnFinished(BBObject * handle, int result);
	void _qt_qdialog_QDialog__OnRejected(BBObject * handle);

	QDialog * bmx_qt_qdialog_create(BBObject * handle, QWidget * parent, int flags);
	int bmx_qt_qdialog_issizegripenabled(QDialog * dialog);
	int bmx_qt_qdialog_result(QDialog * dialog);
	void bmx_qt_qdialog_setmodal(QDialog * dialog, int modal);
	void bmx_qt_qdialog_setresult(QDialog * dialog, int i);
	void bmx_qt_qdialog_setsizegripenabled(QDialog * dialog, int value);
	void bmx_qt_qdialog_accept(QDialog * dialog);
	void bmx_qt_qdialog_done(QDialog * dialog, int r);
	int bmx_qt_qdialog_exec(QDialog * dialog);
	void bmx_qt_qdialog_open(QDialog * dialog);
	void bmx_qt_qdialog_reject(QDialog * dialog);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQDialog : public QDialog
{
	Q_OBJECT
	
public:
	MaxQDialog(BBObject * handle, QWidget * parent, Qt::WindowFlags flags);
	~MaxQDialog();

private:
	BBObject * maxHandle;

private slots:
	void onAccepted();
	void onFinished(int result);
	void onRejected();
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	void timerEvent(QTimerEvent * event);
};

#endif
