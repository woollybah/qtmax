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

#ifndef MAX_QT_QDATEEDIT
#define MAX_QT_QDATEEDIT

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractspinbox.mod/glue.h"
#include "../qdatetimeedit.mod/glue.h"
#include <QtCore>
#include <QDateEdit>

class MaxQDateEdit;

extern "C" {

#include <blitz.h>

	QDateEdit * bmx_qt_qdateedit_create(BBObject * handle, QWidget * parent);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQDateEdit : public QDateEdit
{
	Q_OBJECT

public:
	MaxQDateEdit(BBObject * handle, QWidget * parent);
	~MaxQDateEdit();

private:
	BBObject * maxHandle;
	
private slots:
	void onDateChanged(const QDate & date);
	void onDateTimeChanged(const QDateTime & datetime);
	void onTimeChanged(const QTime & time);
	void onEditingFinished();
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	void timerEvent(QTimerEvent * event);
};

#endif
