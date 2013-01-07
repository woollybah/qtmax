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
Import Qt.QWidget
Import Qt.QTextCharFormat
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

	Function bmx_qt_qcalendarwidget_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qcalendarwidget_dateeditacceptdelay:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_datetextformat:Byte Ptr(handle:Byte Ptr, date:Byte Ptr)
	Function bmx_qt_qcalendarwidget_firstdayofweek:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_headertextformat:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_horizontalheaderformat:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_isdateeditenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_isgridvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_isnavigationbarvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_maximumdate:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_minimumdate:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_monthshown:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_selecteddate:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_selectionmode:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_setdateeditacceptdelay(handle:Byte Ptr, _delay:Int)
	Function bmx_qt_qcalendarwidget_setdateeditenabled(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qcalendarwidget_setdatetextformat(handle:Byte Ptr, date:Byte Ptr, format:Byte Ptr)
	Function bmx_qt_qcalendarwidget_setfirstdayofweek(handle:Byte Ptr, dayOfWeek:Int)
	Function bmx_qt_qcalendarwidget_setheadertextformat(handle:Byte Ptr, format:Byte Ptr)
	Function bmx_qt_qcalendarwidget_sethorizontalheaderformat(handle:Byte Ptr, format:Int)
	Function bmx_qt_qcalendarwidget_setmaximumdate(handle:Byte Ptr, date:Byte Ptr)
	Function bmx_qt_qcalendarwidget_setminimumdate(handle:Byte Ptr, date:Byte Ptr)
	Function bmx_qt_qcalendarwidget_setselectionmode(handle:Byte Ptr, _mode:Int)
	Function bmx_qt_qcalendarwidget_setverticalheaderformat(handle:Byte Ptr, format:Int)
	Function bmx_qt_qcalendarwidget_setweekdaytextformat(handle:Byte Ptr, dayOfWeek:Int, format:Byte Ptr)
	Function bmx_qt_qcalendarwidget_verticalheaderformat:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_weekdaytextformat:Byte Ptr(handle:Byte Ptr, dayOfWeek:Int)
	Function bmx_qt_qcalendarwidget_yearshown:Int(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_setcurrentpage(handle:Byte Ptr, year:Int, Month:Int)
	Function bmx_qt_qcalendarwidget_setdaterange(handle:Byte Ptr, _min:Byte Ptr, _max:Byte Ptr)
	Function bmx_qt_qcalendarwidget_setgridvisible(handle:Byte Ptr, show:Int)
	Function bmx_qt_qcalendarwidget_setnavigationbarvisible(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qcalendarwidget_setselecteddate(handle:Byte Ptr, date:Byte Ptr)
	Function bmx_qt_qcalendarwidget_shownextmonth(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_shownextyear(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_showpreviousmonth(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_showpreviousyear(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_showselecteddate(handle:Byte Ptr)
	Function bmx_qt_qcalendarwidget_showtoday(handle:Byte Ptr)

	
End Extern
