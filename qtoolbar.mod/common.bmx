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

	Function bmx_qt_qtoolbar_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qtoolbar_addwidget(handle:Byte Ptr, widget:Byte Ptr)
	Function bmx_qt_qtoolbar_allowedareas:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbar_clear(handle:Byte Ptr)
	Function bmx_qt_qtoolbar_iconsize(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qtoolbar_isareaallowed:Int(handle:Byte Ptr, area:Int)
	Function bmx_qt_qtoolbar_isfloatable:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbar_isfloating:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbar_ismovable:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbar_orientation:Int(handle:Byte Ptr)
	Function bmx_qt_qtoolbar_setallowedareas(handle:Byte Ptr, areas:Int)
	Function bmx_qt_qtoolbar_setfloatable(handle:Byte Ptr, floatable:Int)
	Function bmx_qt_qtoolbar_setmovable(handle:Byte Ptr, movable:Int)
	Function bmx_qt_qtoolbar_setorientation(handle:Byte Ptr, orientation:Int)
	Function bmx_qt_qtoolbar_toolbuttonstyle:Int(handle:Byte Ptr)

End Extern
