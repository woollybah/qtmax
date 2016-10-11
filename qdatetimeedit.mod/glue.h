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

#ifndef MAX_QT_QDATETIMEEDIT
#define MAX_QT_QDATETIMEEDIT

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractspinbox.mod/glue.h"
#include <QtCore>
#include <QDateTimeEdit>

class MaxQDateTimeEdit;

extern "C" {

#include <blitz.h>

	void _qt_qdatetimeedit_QDateTimeEdit__OnDateChanged(BBObject * handle, MaxQDate * date);
	void _qt_qdatetimeedit_QDateTimeEdit__OnDateTimeChanged(BBObject * handle, MaxQDateTime * datetime);
	void _qt_qdatetimeedit_QDateTimeEdit__OnTimeChanged(BBObject * handle, MaxQTime * time);

	QDateTimeEdit * bmx_qt_qdatetimeedit_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qdatetimeedit_calendarpopoup(QDateTimeEdit * edit);
	QCalendarWidget * bmx_qt_qdatetimeedit_calendarwidget(QDateTimeEdit * edit);
	void bmx_qt_qdatetimeedit_clearmaximumdate(QDateTimeEdit * edit);
	void bmx_qt_qdatetimeedit_clearmaximumdatetime(QDateTimeEdit * edit);
	void bmx_qt_qdatetimeedit_clearmaximumtime(QDateTimeEdit * edit);
	void bmx_qt_qdatetimeedit_clearminimumdate(QDateTimeEdit * edit);
	void bmx_qt_qdatetimeedit_clearminimumdatetime(QDateTimeEdit * edit);
	void bmx_qt_qdatetimeedit_clearminimumtime(QDateTimeEdit * edit);
	int bmx_qt_qdatetimeedit_currentsection(QDateTimeEdit * edit);
	int bmx_qt_qdatetimeedit_currentsectionindex(QDateTimeEdit * edit);
	MaxQDate * bmx_qt_qdatetimeedit_date(QDateTimeEdit * edit);
	MaxQDateTime * bmx_qt_qdatetimeedit_datetime(QDateTimeEdit * edit);
	BBString * bmx_qt_qdatetimeedit_displayformat(QDateTimeEdit * edit);
	int bmx_qt_qdatetimeedit_displayedsections(QDateTimeEdit * edit);
	MaxQDate * bmx_qt_qdatetimeedit_maximumdate(QDateTimeEdit * edit);
	MaxQDateTime * bmx_qt_qdatetimeedit_maximumdatetime(QDateTimeEdit * edit);
	MaxQTime * bmx_qt_qdatetimeedit_maximumtime(QDateTimeEdit * edit);
	MaxQDate * bmx_qt_qdatetimeedit_minimumdate(QDateTimeEdit * edit);
	MaxQDateTime * bmx_qt_qdatetimeedit_minimumdatetime(QDateTimeEdit * edit);
	MaxQTime * bmx_qt_qdatetimeedit_minimumtime(QDateTimeEdit * edit);
	int bmx_qt_qdatetimeedit_sectionat(QDateTimeEdit * edit, int index);
	int bmx_qt_qdatetimeedit_sectioncount(QDateTimeEdit * edit);
	BBString * bmx_qt_qdatetimeedit_sectiontext(QDateTimeEdit * edit, int section);
	void bmx_qt_qdatetimeedit_setcalendarpopup(QDateTimeEdit * edit, int enable);
	void bmx_qt_qdatetimeedit_setcalendarwidget(QDateTimeEdit * edit, QCalendarWidget * calendarWidget);
	void bmx_qt_qdatetimeedit_setcurrentsection(QDateTimeEdit * edit, int section);
	void bmx_qt_qdatetimeedit_setcurrentsectionindex(QDateTimeEdit * edit, int index);
	void bmx_qt_qdatetimeedit_setdaterange(QDateTimeEdit * edit, MaxQDate * _min, MaxQDate * _max);
	void bmx_qt_qdatetimeedit_setdatetimerange(QDateTimeEdit * edit, MaxQDateTime * _min, MaxQDateTime * _max);
	void bmx_qt_qdatetimeedit_setdisplayformat(QDateTimeEdit * edit, BBString * format);
	void bmx_qt_qdatetimeedit_setmaximumdate(QDateTimeEdit * edit, MaxQDate * _max);
	void bmx_qt_qdatetimeedit_setmaximumdatetime(QDateTimeEdit * edit, MaxQDateTime * dt);
	void bmx_qt_qdatetimeedit_setmaximumtime(QDateTimeEdit * edit, MaxQTime * _max);
	void bmx_qt_qdatetimeedit_setminimumdate(QDateTimeEdit * edit, MaxQDate * _min);
	void bmx_qt_qdatetimeedit_setminimumdatetime(QDateTimeEdit * edit, MaxQDateTime * dt);
	void bmx_qt_qdatetimeedit_setminimumtime(QDateTimeEdit * edit, MaxQTime * _min);
	void bmx_qt_qdatetimeedit_setselectedsection(QDateTimeEdit * edit, int section);
	void bmx_qt_qdatetimeedit_settimerange(QDateTimeEdit * edit, MaxQTime * _min, MaxQTime * _max);
	void bmx_qt_qdatetimeedit_settimespec(QDateTimeEdit * edit, int spec);
	MaxQTime * bmx_qt_qdatetimeedit_time(QDateTimeEdit * edit);
	int bmx_qt_qdatetimeedit_timespec(QDateTimeEdit * edit);
	void bmx_qt_qdatetimeedit_setdate(QDateTimeEdit * edit, MaxQDate * date);
	void bmx_qt_qdatetimeedit_setdatetime(QDateTimeEdit * edit, MaxQDateTime * dateTime);
	void bmx_qt_qdatetimeedit_settime(QDateTimeEdit * edit, MaxQTime * time);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQDateTimeEdit : public QDateTimeEdit
{
	Q_OBJECT

public:
	MaxQDateTimeEdit(BBObject * handle, QWidget * parent);
	~MaxQDateTimeEdit();

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
