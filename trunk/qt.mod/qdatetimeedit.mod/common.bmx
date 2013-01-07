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

Import Qt.Core
Import Qt.QAbstractSpinBox
Import Qt.QCalendarWidget
Import BRL.Blitz


' headers :-)
?win32
Import "../lib/win32/include/*.h"
?macos
Import "../lib/macos/include/*.h"
?Not linux
Import "../src/include/*.h"
Import "../src/include/Qt/*.h"
Import "../src/include/QtCore/*.h"
Import "../src/include/QtGui/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
Import "/usr/include/QtGui/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qdatetimeedit_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qdatetimeedit_calendarpopoup:Int(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_calendarwidget:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_clearmaximumdate(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_clearmaximumdatetime(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_clearmaximumtime(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_clearminimumdate(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_clearminimumdatetime(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_clearminimumtime(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_currentsection:Int(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_currentsectionindex:Int(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_date:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_datetime:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_displayformat:String(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_displayedsections:Int(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_maximumdate:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_maximumdatetime:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_maximumtime:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_minimumdate:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_minimumdatetime:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_minimumtime:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_sectionat:Int(handle:Byte Ptr, index:Int)
	Function bmx_qt_qdatetimeedit_sectioncount:Int(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_sectiontext:String(handle:Byte Ptr, section:Int)
	Function bmx_qt_qdatetimeedit_setcalendarpopup(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qdatetimeedit_setcalendarwidget(handle:Byte Ptr, calendarWidget:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setcurrentsection(handle:Byte Ptr, section:Int)
	Function bmx_qt_qdatetimeedit_setcurrentsectionindex(handle:Byte Ptr, index:Int)
	Function bmx_qt_qdatetimeedit_setdaterange(handle:Byte Ptr, _min:Byte Ptr, _max:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setdatetimerange(handle:Byte Ptr, _min:Byte Ptr, _max:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setdisplayformat(handle:Byte Ptr, format:String)
	Function bmx_qt_qdatetimeedit_setmaximumdate(handle:Byte Ptr, _max:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setmaximumdatetime(handle:Byte Ptr, dt:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setmaximumtime(handle:Byte Ptr, _max:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setminimumdate(handle:Byte Ptr, _min:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setminimumdatetime(handle:Byte Ptr, dt:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setminimumtime(handle:Byte Ptr, _min:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setselectedsection(handle:Byte Ptr, section:Int)
	Function bmx_qt_qdatetimeedit_settimerange(handle:Byte Ptr, _min:Byte Ptr, _max:Byte Ptr)
	Function bmx_qt_qdatetimeedit_settimespec(handle:Byte Ptr, spec:Int)
	Function bmx_qt_qdatetimeedit_time:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_timespec:Int(handle:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setdate(handle:Byte Ptr, date:Byte Ptr)
	Function bmx_qt_qdatetimeedit_setdatetime(handle:Byte Ptr, dateTime:Byte Ptr)
	Function bmx_qt_qdatetimeedit_settime(handle:Byte Ptr, time:Byte Ptr)
	
End Extern
