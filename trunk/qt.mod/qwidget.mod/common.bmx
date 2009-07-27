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
Import Qt.QObject
Import Qt.QLocale
Import Qt.QRegion
Import Qt.QPaintEvent
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

	Function bmx_qt_qwidget_create:Byte Ptr(handle:Object, parent:Byte Ptr, flags:Int)
	Function bmx_qt_qwidget_hide(handle:Byte Ptr)
	Function bmx_qt_qwidget_show(handle:Byte Ptr)
	Function bmx_qt_qwidget_setlayout(handle:Byte Ptr, layout:Byte Ptr)
	Function bmx_qt_qwidget_setwindowtitle(handle:Byte Ptr, title:String)

	Function bmx_qt_qwidget_showfullscreen(handle:Byte Ptr)
	Function bmx_qt_qwidget_showmaximized(handle:Byte Ptr)
	Function bmx_qt_qwidget_showminimized(handle:Byte Ptr)
	Function bmx_qt_qwidget_shownormal(handle:Byte Ptr)
	Function bmx_qt_qwidget_stackunder(handle:Byte Ptr, w:Byte Ptr)
	Function bmx_qt_qwidget_setfixedsize(handle:Byte Ptr, w:Int, h:Int)
	Function bmx_qt_qwidget_setfixedwidth(handle:Byte Ptr, w:Int)
	Function bmx_qt_qwidget_setfocus(handle:Byte Ptr, reason:Int)
	Function bmx_qt_qwidget_close(handle:Byte Ptr)
	Function bmx_qt_qwidget_update(handle:Byte Ptr)
	Function bmx_qt_qwidget_raise(handle:Byte Ptr)
	Function bmx_qt_qwidget_repaint(handle:Byte Ptr)
	Function bmx_qt_qwidget_setdisabled(handle:Byte Ptr, disable:Int)
	Function bmx_qt_qwidget_setenabled(handle:Byte Ptr, value:Int)
	Function bmx_qt_qwidget_sethidden(handle:Byte Ptr, hidden:Int)
	Function bmx_qt_qwidget_setstylesheet(handle:Byte Ptr, styleSheet:String)
	Function bmx_qt_qwidget_setvisible(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qwidget_setwindowmodified(handle:Byte Ptr, value:Int)
	Function bmx_qt_qwidget_resize(handle:Byte Ptr, w:Int, h:Int)

End Extern

