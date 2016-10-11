' Copyright (c) 2009-2013 Bruce A Henderson
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

Module Qt.QCalendarWidget

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QCalendarWidget Extends QWidget

	Rem
	bbdoc: The header displays a single letter abbreviation for day names (e.g. M for Monday).
	end rem
	Const SingleLetterDayNames:Int = 1
	Rem
	bbdoc: The header displays a short abbreviation for day names (e.g. Mon for Monday).
	end rem
	Const ShortDayNames:Int = 2
	Rem
	bbdoc: The header displays complete day names (e.g. Monday).
	end rem
	Const LongDayNames:Int = 3
	Rem
	bbdoc: The header is hidden.
	end rem
	Const NoHorizontalHeader:Int = 0
	Rem
	bbdoc: Dates cannot be selected.
	end rem
	Const NoSelection:Int = 0
	Rem
	bbdoc: Single dates can be selected.
	end rem
	Const SingleSelection:Int = 1
	Rem
	bbdoc: The header displays ISO week numbers as described by QDate::weekNumber().
	end rem
	Const ISOWeekNumbers:Int = 1
	Rem
	bbdoc: The header is hidden.
	end rem
	Const NoVerticalHeader:Int = 0

	
	Function __create:QCalendarWidget(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QCalendarWidget = New QCalendarWidget
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QCalendarWidget(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QCalendarWidget = QCalendarWidget(qfind(qObjectPtr))
			If Not widget Then
				Return QCalendarWidget.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function
	
	Function CreateCalendarWidget:QCalendarWidget(parent:QWidget = Null)
		Return New QCalendarWidget.Create(parent)
	End Function
	
	Method Create:QCalendarWidget(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qcalendarwidget_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qcalendarwidget_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method dateEditAcceptDelay:Int()
		Return bmx_qt_qcalendarwidget_dateeditacceptdelay(qObjectPtr)
	End Method
	
	Method dateTextFormat:QTextCharFormat(date:QDate)
		Return QTextCharFormat._create(bmx_qt_qcalendarwidget_datetextformat(qObjectPtr, date.qObjectPtr))
	End Method
	
	Method firstDayOfWeek:Int()
		Return bmx_qt_qcalendarwidget_firstdayofweek(qObjectPtr)
	End Method
	
	Method headerTextFormat:QTextCharFormat()
		Return QTextCharFormat._create(bmx_qt_qcalendarwidget_headertextformat(qObjectPtr))
	End Method
	
	Method horizontalHeaderFormat:Int()
		Return bmx_qt_qcalendarwidget_horizontalheaderformat(qObjectPtr)
	End Method
	
	Method isDateEditEnabled:Int()
		Return bmx_qt_qcalendarwidget_isdateeditenabled(qObjectPtr)
	End Method
	
	Method isGridVisible:Int()
		Return bmx_qt_qcalendarwidget_isgridvisible(qObjectPtr)
	End Method
	
	Method isNavigationBarVisible:Int()
		Return bmx_qt_qcalendarwidget_isnavigationbarvisible(qObjectPtr)
	End Method
	
	Method maximumDate:QDate()
		Return QDate._create(bmx_qt_qcalendarwidget_maximumdate(qObjectPtr))
	End Method
	
	Method minimumDate:QDate()
		Return QDate._create(bmx_qt_qcalendarwidget_minimumdate(qObjectPtr))
	End Method
	
	Method monthShown:Int()
		Return bmx_qt_qcalendarwidget_monthshown(qObjectPtr)
	End Method
	
	Method selectedDate:QDate()
		Return QDate._create(bmx_qt_qcalendarwidget_selecteddate(qObjectPtr))
	End Method
	
	Method selectionMode:Int()
		Return bmx_qt_qcalendarwidget_selectionmode(qObjectPtr)
	End Method
	
	Method setDateEditAcceptDelay(_delay:Int)
		bmx_qt_qcalendarwidget_setdateeditacceptdelay(qObjectPtr, _delay)
	End Method
	
	Method setDateEditEnabled(enable:Int)
		bmx_qt_qcalendarwidget_setdateeditenabled(qObjectPtr, enable)
	End Method
	
	Method setDateTextFormat(date:QDate, format:QTextCharFormat)
		bmx_qt_qcalendarwidget_setdatetextformat(qObjectPtr, date.qObjectPtr, format.qObjectPtr)
	End Method
	
	Method setFirstDayOfWeek(dayOfWeek:Int)
		bmx_qt_qcalendarwidget_setfirstdayofweek(qObjectPtr, dayOfWeek)
	End Method
	
	Method setHeaderTextFormat(format:QTextCharFormat)
		bmx_qt_qcalendarwidget_setheadertextformat(qObjectPtr, format.qObjectPtr)
	End Method
	
	Method setHorizontalHeaderFormat(format:Int)
		bmx_qt_qcalendarwidget_sethorizontalheaderformat(qObjectPtr, format)
	End Method
	
	Method setMaximumDate(date:QDate)
		bmx_qt_qcalendarwidget_setmaximumdate(qObjectPtr, date.qObjectPtr)
	End Method
	
	Method setMinimumDate(date:QDate)
		bmx_qt_qcalendarwidget_setminimumdate(qObjectPtr, date.qObjectPtr)
	End Method
	
	Method setSelectionMode(_mode:Int)
		bmx_qt_qcalendarwidget_setselectionmode(qObjectPtr, _mode)
	End Method
	
	Method setVerticalHeaderFormat(format:Int)
		bmx_qt_qcalendarwidget_setverticalheaderformat(qObjectPtr, format)
	End Method
	
	Method setWeekdayTextFormat(dayOfWeek:Int, format:QTextCharFormat)
		bmx_qt_qcalendarwidget_setweekdaytextformat(qObjectPtr, dayOfWeek, format.qObjectPtr)
	End Method
	
	Method verticalHeaderFormat:Int()
		Return bmx_qt_qcalendarwidget_verticalheaderformat(qObjectPtr)
	End Method
	
	Method weekdayTextFormat:QTextCharFormat(dayOfWeek:Int)
		Return QTextCharFormat._create(bmx_qt_qcalendarwidget_weekdaytextformat(qObjectPtr, dayOfWeek))
	End Method
	
	Method yearShown:Int() 
		Return bmx_qt_qcalendarwidget_yearshown(qObjectPtr)
	End Method
	
	Method setCurrentPage(year:Int, Month:Int)
		bmx_qt_qcalendarwidget_setcurrentpage(qObjectPtr, year, Month)
	End Method
	
	Method setDateRange(_min:QDate, _max:QDate)
		bmx_qt_qcalendarwidget_setdaterange(qObjectPtr, _min.qObjectPtr, _max.qObjectPtr)
	End Method
	
	Method setGridVisible(show:Int)
		bmx_qt_qcalendarwidget_setgridvisible(qObjectPtr, show)
	End Method
	
	Method setNavigationBarVisible(visible:Int)
		bmx_qt_qcalendarwidget_setnavigationbarvisible(qObjectPtr, visible)
	End Method
	
	Method setSelectedDate(date:QDate)
		bmx_qt_qcalendarwidget_setselecteddate(qObjectPtr, date.qObjectPtr)
	End Method
	
	Method showNextMonth()
		bmx_qt_qcalendarwidget_shownextmonth(qObjectPtr)
	End Method
	
	Method showNextYear()
		bmx_qt_qcalendarwidget_shownextyear(qObjectPtr)
	End Method
	
	Method showPreviousMonth()
		bmx_qt_qcalendarwidget_showpreviousmonth(qObjectPtr)
	End Method
	
	Method showPreviousYear()
		bmx_qt_qcalendarwidget_showpreviousyear(qObjectPtr)
	End Method
	
	Method showSelectedDate()
		bmx_qt_qcalendarwidget_showselecteddate(qObjectPtr)
	End Method
	
	Method showToday()
		bmx_qt_qcalendarwidget_showtoday(qObjectPtr)
	End Method


	' SIGNAL : activated
	Function _OnActivated(obj:QCalendarWidget, date:QDate)
		obj._InvokeSignals("activated", [date])
	End Function

	' SIGNAL : clicked
	Function _OnClicked(obj:QCalendarWidget, date:QDate)
		obj._InvokeSignals("clicked", [date])
	End Function

	' SIGNAL : currentPageChanged
	Function _OnCurrentPageChanged(obj:QCalendarWidget, year:Int, _month:Int)
		obj._InvokeSignals("currentPageChanged", [String(year), String(_month)])
	End Function

	' SIGNAL : selectionChanged
	Function _OnSelectionChanged(obj:QCalendarWidget)
		obj._InvokeSignals("selectionChanged", Null)
	End Function

End Type
