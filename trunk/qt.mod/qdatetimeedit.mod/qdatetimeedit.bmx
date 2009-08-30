' Copyright (c) 2009 Bruce A Henderson
' 
' Permission is hereby granted, free of charge, to any person obtaining a copy
' of this software and associated documentation files (the "Software"), to deal
' in the Software without restriction, including without limitation the rights
' to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
' copies of the Software, and to permit persons to whom the Software is
' furnished to do so, subject to the following conditions:
' 
' The above copyright notice and this permission notice shall be included in
' all copies or substantial portions of the Software.
' 
' THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
' IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
' FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
' AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
' LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
' OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
' THE SOFTWARE.
' 
SuperStrict

Module Qt.QDateTimeEdit

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QDateTimeEdit Extends QAbstractSpinBox

	Function CreateDateTimeEdit:QDateTimeEdit(parent:QWidget = Null)
		Return New QDateTimeEdit.Create(parent)
	End Function
	
	Method Create:QDateTimeEdit(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qdatetimeedit_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qdatetimeedit_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method calendarPopup:Int()
		Return bmx_qt_qdatetimeedit_calendarpopoup(qObjectPtr)
	End Method
	
	Method calendarWidget:QCalendarWidget()
		Return QCalendarWidget._find(bmx_qt_qdatetimeedit_calendarwidget(qObjectPtr))
	End Method
	
	Method clearMaximumDate()
		bmx_qt_qdatetimeedit_clearmaximumdate(qObjectPtr)
	End Method
	
	Method clearMaximumDateTime()
		bmx_qt_qdatetimeedit_clearmaximumdatetime(qObjectPtr)
	End Method
	
	Method clearMaximumTime()
		bmx_qt_qdatetimeedit_clearmaximumtime(qObjectPtr)
	End Method
	
	Method clearMinimumDate()
		bmx_qt_qdatetimeedit_clearminimumdate(qObjectPtr)
	End Method
	
	Method clearMinimumDateTime()
		bmx_qt_qdatetimeedit_clearminimumdatetime(qObjectPtr)
	End Method
	
	Method clearMinimumTime()
		bmx_qt_qdatetimeedit_clearminimumtime(qObjectPtr)
	End Method
	
	Method currentSection:Int()
		Return bmx_qt_qdatetimeedit_currentsection(qObjectPtr)
	End Method
	
	Method currentSectionIndex:Int()
		Return bmx_qt_qdatetimeedit_currentsectionindex(qObjectPtr)
	End Method
	
	Method date:QDate()
		Return QDate._create(bmx_qt_qdatetimeedit_date(qObjectPtr))
	End Method
	
	Method dateTime:QDateTime()
		Return QDateTime._create(bmx_qt_qdatetimeedit_datetime(qObjectPtr))
	End Method
	
	Method displayFormat:String()
		Return bmx_qt_qdatetimeedit_displayformat(qObjectPtr)
	End Method
	
	Method displayedSections:Int()
		Return bmx_qt_qdatetimeedit_displayedsections(qObjectPtr)
	End Method
	
	Method maximumDate:QDate()
		Return QDate._create(bmx_qt_qdatetimeedit_maximumdate(qObjectPtr))
	End Method
	
	Method maximumDateTime:QDateTime()
		Return QDateTime._create(bmx_qt_qdatetimeedit_maximumdatetime(qObjectPtr))
	End Method
	
	Method maximumTime:QTime()
		Return QTime._create(bmx_qt_qdatetimeedit_maximumtime(qObjectPtr))
	End Method
	
	Method minimumDate:QDate()
		Return QDate._create(bmx_qt_qdatetimeedit_minimumdate(qObjectPtr))
	End Method
	
	Method minimumDateTime:QDateTime()
		Return QDateTime._create(bmx_qt_qdatetimeedit_minimumdatetime(qObjectPtr))
	End Method
	
	Method minimumTime:QTime()
		Return QTime._create(bmx_qt_qdatetimeedit_minimumtime(qObjectPtr))
	End Method
	
	Method sectionAt:Int(index:Int)
		Return bmx_qt_qdatetimeedit_sectionat(qObjectPtr, index)
	End Method
	
	Method sectionCount:Int()
		Return bmx_qt_qdatetimeedit_sectioncount(qObjectPtr)
	End Method
	
	Method sectionText:String(section:Int)
		Return bmx_qt_qdatetimeedit_sectiontext(qObjectPtr, section)
	End Method
	
	Method setCalendarPopup(enable:Int)
		bmx_qt_qdatetimeedit_setcalendarpopup(qObjectPtr, enable)
	End Method
	
	Method setCalendarWidget(calendarWidget:QCalendarWidget)
		bmx_qt_qdatetimeedit_setcalendarwidget(qObjectPtr, calendarWidget.qObjectPtr)
	End Method
	
	Method setCurrentSection(section:Int)
		bmx_qt_qdatetimeedit_setcurrentsection(qObjectPtr, section)
	End Method
	
	Method setCurrentSectionIndex(index:Int)
		bmx_qt_qdatetimeedit_setcurrentsectionindex(qObjectPtr, index)
	End Method
	
	Method setDateRange(_min:QDate, _max:QDate)
		bmx_qt_qdatetimeedit_setdaterange(qObjectPtr, _min.qObjectPtr, _max.qObjectPtr)
	End Method
	
	Method setDateTimeRange(_min:QDateTime, _max:QDateTime)
		bmx_qt_qdatetimeedit_setdatetimerange(qObjectPtr, _min.qObjectPtr, _max.qObjectPtr)
	End Method
	
	Method setDisplayFormat(format:String)
		bmx_qt_qdatetimeedit_setdisplayformat(qObjectPtr, format)
	End Method
	
	Method setMaximumDate(_max:QDate)
		bmx_qt_qdatetimeedit_setmaximumdate(qObjectPtr, _max.qObjectPtr)
	End Method
	
	Method setMaximumDateTime(dt:QDateTime)
		bmx_qt_qdatetimeedit_setmaximumdatetime(qObjectPtr, dt.qObjectPtr)
	End Method
	
	Method setMaximumTime(_max:QTime)
		bmx_qt_qdatetimeedit_setmaximumtime(qObjectPtr, _max.qObjectPtr)
	End Method
	
	Method setMinimumDate(_min:QDate)
		bmx_qt_qdatetimeedit_setminimumdate(qObjectPtr, _min.qObjectPtr)
	End Method
	
	Method setMinimumDateTime(dt:QDateTime)
		bmx_qt_qdatetimeedit_setminimumdatetime(qObjectPtr, dt.qObjectPtr)
	End Method
	
	Method setMinimumTime(_min:QTime)
		bmx_qt_qdatetimeedit_setminimumtime(qObjectPtr, _min.qObjectPtr)
	End Method
	
	Method setSelectedSection(section:Int)
		bmx_qt_qdatetimeedit_setselectedsection(qObjectPtr, section)
	End Method
	
	Method setTimeRange(_min:QTime, _max:QTime)
		bmx_qt_qdatetimeedit_settimerange(qObjectPtr, _min.qObjectPtr, _max.qObjectPtr)
	End Method
	
	Method setTimeSpec(spec:Int)
		bmx_qt_qdatetimeedit_settimespec(qObjectPtr, spec)
	End Method
	
	Method time:QTime()
		Return QTime._create(bmx_qt_qdatetimeedit_time(qObjectPtr))
	End Method
	
	Method timeSpec:Int()
		Return bmx_qt_qdatetimeedit_timespec(qObjectPtr)
	End Method
	
	Method setDate(date:QDate)
		bmx_qt_qdatetimeedit_setdate(qObjectPtr, date.qObjectPtr)
	End Method
	
	Method setDateTime(dateTime:QDateTime)
		bmx_qt_qdatetimeedit_setdatetime(qObjectPtr, dateTime.qObjectPtr)
	End Method
	
	Method setTime(time:QTime)
		bmx_qt_qdatetimeedit_settime(qObjectPtr, time.qObjectPtr)
	End Method
	
	' SIGNAL : dateChanged
	Function _OnDateChanged(obj:QDateTimeEdit, date:Byte Ptr)
		obj._InvokeSignals("dateChanged", [QDate._create(date)])
	End Function

	' SIGNAL : dateTimeChanged
	Function _OnDateTimeChanged(obj:QDateTimeEdit, datetime:Byte Ptr)
		obj._InvokeSignals("dateTimeChanged", [QDateTime._create(datetime)])
	End Function

	' SIGNAL : timeChanged
	Function _OnTimeChanged(obj:QDateTimeEdit, time:Byte Ptr)
		obj._InvokeSignals("timeChanged", [QTime._create(time)])
	End Function

End Type

