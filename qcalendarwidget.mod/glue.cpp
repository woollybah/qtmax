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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQCalendarWidget::MaxQCalendarWidget(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QCalendarWidget(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(activated(const QDate &)), SLOT(onActivated(const QDate &)));
	connect(this, SIGNAL(clicked(const QDate &)), SLOT(onClicked(const QDate &)));
	connect(this, SIGNAL(currentPageChanged(int, int)), SLOT(onCurrentPageChanged(int, int)));
	connect(this, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint & )), SLOT(onCustomContextMenuRequested(const QPoint & )));
}

MaxQCalendarWidget::~MaxQCalendarWidget()
{
	qunbind(this);
}

void MaxQCalendarWidget::onActivated(const QDate & date) {
	_qt_qcalendarwidget_QCalendarWidget__OnActivated(maxHandle, new MaxQDate(date));
}

void MaxQCalendarWidget::onClicked(const QDate & date) {
	_qt_qcalendarwidget_QCalendarWidget__OnClicked(maxHandle, new MaxQDate(date));
}

void MaxQCalendarWidget::onCurrentPageChanged(int year, int month) {
	_qt_qcalendarwidget_QCalendarWidget__OnCurrentPageChanged(maxHandle, year, month);
}

void MaxQCalendarWidget::onSelectionChanged() {
	_qt_qcalendarwidget_QCalendarWidget__OnSelectionChanged(maxHandle);
}

void MaxQCalendarWidget::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

void MaxQCalendarWidget::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

QCalendarWidget * bmx_qt_qcalendarwidget_create(BBObject * handle, QWidget * parent) {
	return new MaxQCalendarWidget(handle, parent);
}

int bmx_qt_qcalendarwidget_dateeditacceptdelay(QCalendarWidget * widget) {
	return widget->dateEditAcceptDelay();
}

MaxQTextCharFormat * bmx_qt_qcalendarwidget_datetextformat(QCalendarWidget * widget, MaxQDate * date) {
	return new MaxQTextCharFormat(widget->dateTextFormat(date->Date()));
}

int bmx_qt_qcalendarwidget_firstdayofweek(QCalendarWidget * widget) {
	return widget->firstDayOfWeek();
}

MaxQTextCharFormat * bmx_qt_qcalendarwidget_headertextformat(QCalendarWidget * widget) {
	return new MaxQTextCharFormat(widget->headerTextFormat());
}

int bmx_qt_qcalendarwidget_horizontalheaderformat(QCalendarWidget * widget) {
	return widget->horizontalHeaderFormat();
}

int bmx_qt_qcalendarwidget_isdateeditenabled(QCalendarWidget * widget) {
	return static_cast<int>(widget->isDateEditEnabled());
}

int bmx_qt_qcalendarwidget_isgridvisible(QCalendarWidget * widget) {
	return static_cast<int>(widget->isGridVisible());
}

int bmx_qt_qcalendarwidget_isnavigationbarvisible(QCalendarWidget * widget) {
	return static_cast<int>(widget->isNavigationBarVisible());
}

MaxQDate * bmx_qt_qcalendarwidget_maximumdate(QCalendarWidget * widget) {
	return new MaxQDate(widget->maximumDate());
}

MaxQDate * bmx_qt_qcalendarwidget_minimumdate(QCalendarWidget * widget) {
	return new MaxQDate(widget->minimumDate());
}

int bmx_qt_qcalendarwidget_monthshown(QCalendarWidget * widget) {
	return widget->monthShown();
}

MaxQDate * bmx_qt_qcalendarwidget_selecteddate(QCalendarWidget * widget) {
	return new MaxQDate(widget->selectedDate());
}

int bmx_qt_qcalendarwidget_selectionmode(QCalendarWidget * widget) {
	return widget->selectionMode();
}

void bmx_qt_qcalendarwidget_setdateeditacceptdelay(QCalendarWidget * widget, int delay) {
	widget->setDateEditAcceptDelay(delay);
}

void bmx_qt_qcalendarwidget_setdateeditenabled(QCalendarWidget * widget, int enable) {
	widget->setDateEditEnabled(static_cast<bool>(enable));
}

void bmx_qt_qcalendarwidget_setdatetextformat(QCalendarWidget * widget, MaxQDate * date, MaxQTextCharFormat * format) {
	widget->setDateTextFormat(date->Date(), format->Format());
}

void bmx_qt_qcalendarwidget_setfirstdayofweek(QCalendarWidget * widget, int dayOfWeek) {
	widget->setFirstDayOfWeek((Qt::DayOfWeek)dayOfWeek);
}

void bmx_qt_qcalendarwidget_setheadertextformat(QCalendarWidget * widget, MaxQTextCharFormat * format) {
	widget->setHeaderTextFormat(format->Format());
}

void bmx_qt_qcalendarwidget_sethorizontalheaderformat(QCalendarWidget * widget, int format) {
	widget->setHorizontalHeaderFormat((QCalendarWidget::HorizontalHeaderFormat)format);
}

void bmx_qt_qcalendarwidget_setmaximumdate(QCalendarWidget * widget, MaxQDate * date) {
	widget->setMaximumDate(date->Date());
}

void bmx_qt_qcalendarwidget_setminimumdate(QCalendarWidget * widget, MaxQDate * date) {
	widget->setMinimumDate(date->Date());
}

void bmx_qt_qcalendarwidget_setselectionmode(QCalendarWidget * widget, int _mode) {
	widget->setSelectionMode((QCalendarWidget::SelectionMode)_mode);
}

void bmx_qt_qcalendarwidget_setverticalheaderformat(QCalendarWidget * widget, int format) {
	widget->setVerticalHeaderFormat((QCalendarWidget::VerticalHeaderFormat)format);
}

void bmx_qt_qcalendarwidget_setweekdaytextformat(QCalendarWidget * widget, int dayOfWeek, MaxQTextCharFormat * format) {
	widget->setWeekdayTextFormat((Qt::DayOfWeek)dayOfWeek, format->Format());
}

int bmx_qt_qcalendarwidget_verticalheaderformat(QCalendarWidget * widget) {
	return widget->verticalHeaderFormat();
}

MaxQTextCharFormat * bmx_qt_qcalendarwidget_weekdaytextformat(QCalendarWidget * widget, int dayOfWeek) {
	return new MaxQTextCharFormat(widget->weekdayTextFormat((Qt::DayOfWeek)dayOfWeek));
}

int bmx_qt_qcalendarwidget_yearshown(QCalendarWidget * widget) {
	return widget->yearShown();
}

void bmx_qt_qcalendarwidget_setcurrentpage(QCalendarWidget * widget, int year, int month) {
	widget->setCurrentPage(year, month);
}

void bmx_qt_qcalendarwidget_setdaterange(QCalendarWidget * widget, MaxQDate * _min, MaxQDate * _max) {
	widget->setDateRange(_min->Date(), _max->Date());
}

void bmx_qt_qcalendarwidget_setgridvisible(QCalendarWidget * widget, int show) {
	widget->setGridVisible(show);
}

void bmx_qt_qcalendarwidget_setnavigationbarvisible(QCalendarWidget * widget, int visible) {
	widget->setNavigationBarVisible(visible);
}

void bmx_qt_qcalendarwidget_setselecteddate(QCalendarWidget * widget, MaxQDate * date) {
	widget->setSelectedDate(date->Date());
}

void bmx_qt_qcalendarwidget_shownextmonth(QCalendarWidget * widget) {
	widget->showNextMonth();
}

void bmx_qt_qcalendarwidget_shownextyear(QCalendarWidget * widget) {
	widget->showNextYear();
}

void bmx_qt_qcalendarwidget_showpreviousmonth(QCalendarWidget * widget) {
	widget->showPreviousMonth();
}

void bmx_qt_qcalendarwidget_showpreviousyear(QCalendarWidget * widget) {
	widget->showPreviousYear();
}

void bmx_qt_qcalendarwidget_showselecteddate(QCalendarWidget * widget) {
	widget->showSelectedDate();
}

void bmx_qt_qcalendarwidget_showtoday(QCalendarWidget * widget) {
	widget->showToday();
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
