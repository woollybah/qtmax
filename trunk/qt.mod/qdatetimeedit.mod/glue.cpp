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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQDateTimeEdit::MaxQDateTimeEdit(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QDateTimeEdit(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(dateChanged(const QDate &)), SLOT(onDateChanged(const QDate &)));
	connect(this, SIGNAL(dateTimeChanged(const QDateTime &)), SLOT(onDateTimeChanged(const QDateTime &)));
	connect(this, SIGNAL(timeChanged(const QTime &)), SLOT(onTimeChanged(const QTime &)));
	connect(this, SIGNAL(editingFinished()), SLOT(onEditingFinished()));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQDateTimeEdit::~MaxQDateTimeEdit()
{
	qunbind(this);
}

void MaxQDateTimeEdit::onDateChanged(const QDate & date) {
	_qt_qdatetimeedit_QDateTimeEdit__OnDateChanged(maxHandle, new MaxQDate(date));
}

void MaxQDateTimeEdit::onDateTimeChanged(const QDateTime & datetime) {
	_qt_qdatetimeedit_QDateTimeEdit__OnDateTimeChanged(maxHandle, new MaxQDateTime(datetime));
}

void MaxQDateTimeEdit::onTimeChanged(const QTime & time) {
	_qt_qdatetimeedit_QDateTimeEdit__OnTimeChanged(maxHandle, new MaxQTime(time));
}

void MaxQDateTimeEdit::onEditingFinished() {
	_qt_qabstractspinbox_QAbstractSpinBox__OnEditingFinished(maxHandle);
}

void MaxQDateTimeEdit::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

// *********************************************

QDateTimeEdit * bmx_qt_qdatetimeedit_create(BBObject * handle, QWidget * parent) {
	return new MaxQDateTimeEdit(handle, parent);
}

int bmx_qt_qdatetimeedit_calendarpopoup(QDateTimeEdit * edit) {
	return static_cast<int>(edit->calendarPopup());
}

QCalendarWidget * bmx_qt_qdatetimeedit_calendarwidget(QDateTimeEdit * edit) {
	return edit->calendarWidget();
}

void bmx_qt_qdatetimeedit_clearmaximumdate(QDateTimeEdit * edit) {
	edit->clearMaximumDate();
}

void bmx_qt_qdatetimeedit_clearmaximumdatetime(QDateTimeEdit * edit) {
	edit->clearMaximumDateTime();
}

void bmx_qt_qdatetimeedit_clearmaximumtime(QDateTimeEdit * edit) {
	edit->clearMaximumTime();
}

void bmx_qt_qdatetimeedit_clearminimumdate(QDateTimeEdit * edit) {
	edit->clearMinimumDate();
}

void bmx_qt_qdatetimeedit_clearminimumdatetime(QDateTimeEdit * edit) {
	edit->clearMinimumDateTime();
}

void bmx_qt_qdatetimeedit_clearminimumtime(QDateTimeEdit * edit) {
	edit->clearMinimumTime();
}

int bmx_qt_qdatetimeedit_currentsection(QDateTimeEdit * edit) {
	return edit->currentSection();
}

int bmx_qt_qdatetimeedit_currentsectionindex(QDateTimeEdit * edit) {
	return edit->currentSectionIndex();
}

MaxQDate * bmx_qt_qdatetimeedit_date(QDateTimeEdit * edit) {
	return new MaxQDate(edit->date());
}

MaxQDateTime * bmx_qt_qdatetimeedit_datetime(QDateTimeEdit * edit) {
	return new MaxQDateTime(edit->dateTime());
}

BBString * bmx_qt_qdatetimeedit_displayformat(QDateTimeEdit * edit) {
	return bbStringFromQString(edit->displayFormat());
}

int bmx_qt_qdatetimeedit_displayedsections(QDateTimeEdit * edit) {
	return edit->displayedSections();
}

MaxQDate * bmx_qt_qdatetimeedit_maximumdate(QDateTimeEdit * edit) {
	return new MaxQDate(edit->maximumDate());
}

MaxQDateTime * bmx_qt_qdatetimeedit_maximumdatetime(QDateTimeEdit * edit) {
	return new MaxQDateTime(edit->maximumDateTime());
}

MaxQTime * bmx_qt_qdatetimeedit_maximumtime(QDateTimeEdit * edit) {
	return new MaxQTime(edit->maximumTime());
}

MaxQDate * bmx_qt_qdatetimeedit_minimumdate(QDateTimeEdit * edit) {
	return new MaxQDate(edit->minimumDate());
}

MaxQDateTime * bmx_qt_qdatetimeedit_minimumdatetime(QDateTimeEdit * edit) {
	return new MaxQDateTime(edit->minimumDateTime());
}

MaxQTime * bmx_qt_qdatetimeedit_minimumtime(QDateTimeEdit * edit) {
	return new MaxQTime(edit->minimumTime());
}

int bmx_qt_qdatetimeedit_sectionat(QDateTimeEdit * edit, int index) {
	return edit->sectionAt(index);
}

int bmx_qt_qdatetimeedit_sectioncount(QDateTimeEdit * edit) {
	return edit->sectionCount();
}

BBString * bmx_qt_qdatetimeedit_sectiontext(QDateTimeEdit * edit, int section) {
	return bbStringFromQString(edit->sectionText((QDateTimeEdit::Section)section));
}

void bmx_qt_qdatetimeedit_setcalendarpopup(QDateTimeEdit * edit, int enable) {
	edit->setCalendarPopup(static_cast<bool>(enable));
}

void bmx_qt_qdatetimeedit_setcalendarwidget(QDateTimeEdit * edit, QCalendarWidget * calendarWidget) {
	edit->setCalendarWidget(calendarWidget);
}

void bmx_qt_qdatetimeedit_setcurrentsection(QDateTimeEdit * edit, int section) {
	edit->setCurrentSection((QDateTimeEdit::Section)section);
}

void bmx_qt_qdatetimeedit_setcurrentsectionindex(QDateTimeEdit * edit, int index) {
	edit->setCurrentSectionIndex(index);
}

void bmx_qt_qdatetimeedit_setdaterange(QDateTimeEdit * edit, MaxQDate * _min, MaxQDate * _max) {
	edit->setDateRange(_min->Date(), _max->Date());
}

void bmx_qt_qdatetimeedit_setdatetimerange(QDateTimeEdit * edit, MaxQDateTime * _min, MaxQDateTime * _max) {
	edit->setDateTimeRange(_min->DateTime(), _max->DateTime());
}

void bmx_qt_qdatetimeedit_setdisplayformat(QDateTimeEdit * edit, BBString * format) {
	edit->setDisplayFormat(qStringFromBBString(format));
}

void bmx_qt_qdatetimeedit_setmaximumdate(QDateTimeEdit * edit, MaxQDate * _max) {
	edit->setMaximumDate(_max->Date());
}

void bmx_qt_qdatetimeedit_setmaximumdatetime(QDateTimeEdit * edit, MaxQDateTime * dt) {
	edit->setMaximumDateTime(dt->DateTime());
}

void bmx_qt_qdatetimeedit_setmaximumtime(QDateTimeEdit * edit, MaxQTime * _max) {
	edit->setMaximumTime(_max->Time());
}

void bmx_qt_qdatetimeedit_setminimumdate(QDateTimeEdit * edit, MaxQDate * _min) {
	edit->setMinimumDate(_min->Date());
}

void bmx_qt_qdatetimeedit_setminimumdatetime(QDateTimeEdit * edit, MaxQDateTime * dt) {
	edit->setMinimumDateTime(dt->DateTime());
}

void bmx_qt_qdatetimeedit_setminimumtime(QDateTimeEdit * edit, MaxQTime * _min) {
	edit->setMinimumTime(_min->Time());
}

void bmx_qt_qdatetimeedit_setselectedsection(QDateTimeEdit * edit, int section) {
	edit->setSelectedSection((QDateTimeEdit::Section)section);
}

void bmx_qt_qdatetimeedit_settimerange(QDateTimeEdit * edit, MaxQTime * _min, MaxQTime * _max) {
	edit->setTimeRange(_min->Time(), _max->Time());
}

void bmx_qt_qdatetimeedit_settimespec(QDateTimeEdit * edit, int spec) {
	edit->setTimeSpec((Qt::TimeSpec)spec);
}

MaxQTime * bmx_qt_qdatetimeedit_time(QDateTimeEdit * edit) {
	return new MaxQTime(edit->time());
}

int bmx_qt_qdatetimeedit_timespec(QDateTimeEdit * edit) {
	return edit->timeSpec();
}

void bmx_qt_qdatetimeedit_setdate(QDateTimeEdit * edit, MaxQDate * date) {
	edit->setDate(date->Date());
}

void bmx_qt_qdatetimeedit_setdatetime(QDateTimeEdit * edit, MaxQDateTime * dateTime) {
	edit->setDateTime(dateTime->DateTime());
}

void bmx_qt_qdatetimeedit_settime(QDateTimeEdit * edit, MaxQTime * time) {
	edit->setTime(time->Time());
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
