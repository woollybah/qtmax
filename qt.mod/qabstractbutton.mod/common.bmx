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
Import Qt.QWidget
Import Qt.QPainter
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

	Function bmx_qt_qabstractbutton_autoexclusive:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_autorepeat:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_autorepeatdelay:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_autorepeatinterval:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_group:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_iconsize(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qabstractbutton_ischeckable:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_ischecked:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_isdown:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_setautoexclusive(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractbutton_setautorepeat(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractbutton_setautorepeatdelay(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractbutton_setautorepeatinterval(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractbutton_setcheckable(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractbutton_setdown(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractbutton_settext(handle:Byte Ptr, text:String)
	Function bmx_qt_qabstractbutton_text:String(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_animateclick(handle:Byte Ptr, msec:Int)
	Function bmx_qt_qabstractbutton_click(handle:Byte Ptr)
	Function bmx_qt_qabstractbutton_setchecked(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractbutton_seticonsize(handle:Byte Ptr, w:Int, h:Int)
	Function bmx_qt_qabstractbutton_toggle(handle:Byte Ptr)

End Extern
