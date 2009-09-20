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

#ifndef MAX_QT_QCALENDARWIDGET
#define MAX_QT_QCALENDARWIDGET

#include "../core.mod/glue.h"
#include "../qtextcharformat.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QCalendarWidget>

class MaxQCalendarWidget;

extern "C" {

#include <blitz.h>

	void _qt_qcalendarwidget_QCalendarWidget__OnActivated(BBObject * handle, MaxQDate * date);
	void _qt_qcalendarwidget_QCalendarWidget__OnClicked(BBObject * handle, MaxQDate * date);
	void _qt_qcalendarwidget_QCalendarWidget__OnCurrentPageChanged(BBObject * handle, int year, int month);
	void _qt_qcalendarwidget_QCalendarWidget__OnSelectionChanged(BBObject * handle);

	QCalendarWidget * bmx_qt_qcalendarwidget_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qcalendarwidget_dateeditacceptdelay(QCalendarWidget * widget);
	MaxQTextCharFormat * bmx_qt_qcalendarwidget_datetextformat(QCalendarWidget * widget, MaxQDate * date);
	int bmx_qt_qcalendarwidget_firstdayofweek(QCalendarWidget * widget);
	MaxQTextCharFormat * bmx_qt_qcalendarwidget_headertextformat(QCalendarWidget * widget);
	int bmx_qt_qcalendarwidget_horizontalheaderformat(QCalendarWidget * widget);
	int bmx_qt_qcalendarwidget_isdateeditenabled(QCalendarWidget * widget);
	int bmx_qt_qcalendarwidget_isgridvisible(QCalendarWidget * widget);
	int bmx_qt_qcalendarwidget_isnavigationbarvisible(QCalendarWidget * widget);
	MaxQDate * bmx_qt_qcalendarwidget_maximumdate(QCalendarWidget * widget);
	MaxQDate * bmx_qt_qcalendarwidget_minimumdate(QCalendarWidget * widget);
	int bmx_qt_qcalendarwidget_monthshown(QCalendarWidget * widget);
	MaxQDate * bmx_qt_qcalendarwidget_selecteddate(QCalendarWidget * widget);
	int bmx_qt_qcalendarwidget_selectionmode(QCalendarWidget * widget);
	void bmx_qt_qcalendarwidget_setdateeditacceptdelay(QCalendarWidget * widget, int delay);
	void bmx_qt_qcalendarwidget_setdateeditenabled(QCalendarWidget * widget, int enable);
	void bmx_qt_qcalendarwidget_setdatetextformat(QCalendarWidget * widget, MaxQDate * date, MaxQTextCharFormat * format);
	void bmx_qt_qcalendarwidget_setfirstdayofweek(QCalendarWidget * widget, int dayOfWeek);
	void bmx_qt_qcalendarwidget_setheadertextformat(QCalendarWidget * widget, MaxQTextCharFormat * format);
	void bmx_qt_qcalendarwidget_sethorizontalheaderformat(QCalendarWidget * widget, int format);
	void bmx_qt_qcalendarwidget_setmaximumdate(QCalendarWidget * widget, MaxQDate * date);
	void bmx_qt_qcalendarwidget_setminimumdate(QCalendarWidget * widget, MaxQDate * date);
	void bmx_qt_qcalendarwidget_setselectionmode(QCalendarWidget * widget, int _mode);
	void bmx_qt_qcalendarwidget_setverticalheaderformat(QCalendarWidget * widget, int format);
	void bmx_qt_qcalendarwidget_setweekdaytextformat(QCalendarWidget * widget, int dayOfWeek, MaxQTextCharFormat * format);
	int bmx_qt_qcalendarwidget_verticalheaderformat(QCalendarWidget * widget);
	MaxQTextCharFormat * bmx_qt_qcalendarwidget_weekdaytextformat(QCalendarWidget * widget, int dayOfWeek);
	int bmx_qt_qcalendarwidget_yearshown(QCalendarWidget * widget);
	void bmx_qt_qcalendarwidget_setcurrentpage(QCalendarWidget * widget, int year, int month);
	void bmx_qt_qcalendarwidget_setdaterange(QCalendarWidget * widget, MaxQDate * _min, MaxQDate * _max);
	void bmx_qt_qcalendarwidget_setgridvisible(QCalendarWidget * widget, int show);
	void bmx_qt_qcalendarwidget_setnavigationbarvisible(QCalendarWidget * widget, int visible);
	void bmx_qt_qcalendarwidget_setselecteddate(QCalendarWidget * widget, MaxQDate * date);
	void bmx_qt_qcalendarwidget_shownextmonth(QCalendarWidget * widget);
	void bmx_qt_qcalendarwidget_shownextyear(QCalendarWidget * widget);
	void bmx_qt_qcalendarwidget_showpreviousmonth(QCalendarWidget * widget);
	void bmx_qt_qcalendarwidget_showpreviousyear(QCalendarWidget * widget);
	void bmx_qt_qcalendarwidget_showselecteddate(QCalendarWidget * widget);
	void bmx_qt_qcalendarwidget_showtoday(QCalendarWidget * widget);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQCalendarWidget : public QCalendarWidget
{
	Q_OBJECT
	
public:
	MaxQCalendarWidget(BBObject * handle, QWidget * parent);
	~MaxQCalendarWidget();

private:
	BBObject * maxHandle;
	
private slots:
	void onActivated(const QDate & date);
	void onClicked(const QDate & date);
	void onCurrentPageChanged(int year, int month);
	void onSelectionChanged();
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	void timerEvent(QTimerEvent * event);
};

#endif
