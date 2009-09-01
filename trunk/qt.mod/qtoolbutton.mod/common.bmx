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

Import Qt.Core
Import Qt.QAbstractButton
Import Qt.QMenu
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
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qtoolbutton_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qtoolbutton_arrowtype:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbutton_autoraise:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbutton_defaultaction:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtoolbutton_menu:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtoolbutton_popupmode:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbutton_setarrowtype(handle:Byte Ptr, arrow:Int)
	Function bmx_qt_qtoolbutton_setautoraise(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qtoolbutton_setmenu(handle:Byte Ptr, menu:Byte Ptr)
	Function bmx_qt_qtoolbutton_setpopupmode(handle:Byte Ptr, _mode:Int)
	Function bmx_qt_qtoolbutton_toolbuttonstyle:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbutton_setdefaultaction(handle:Byte Ptr, action:Byte Ptr)
	Function bmx_qt_qtoolbutton_settoolbuttonstyle(handle:Byte Ptr, style:Int)
	Function bmx_qt_qtoolbutton_showmenu(handle:Byte Ptr)


End Extern
