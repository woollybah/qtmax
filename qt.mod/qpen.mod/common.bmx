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
Import Qt.QBrush
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

	Function bmx_qt_qpen_create:Byte Ptr(style:Int)
	Function bmx_qt_qpen_createwithattributes:Byte Ptr(brush:Byte Ptr, width:Double, style:Int, cap:Int, join:Int)
	Function bmx_qt_qpen_createwithglobalcolor:Byte Ptr(color:Int)
	Function bmx_qt_qpen_brush:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpen_capstyle:Int(handle:Byte Ptr)
	Function bmx_qt_qpen_color:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpen_dashoffset:Double(handle:Byte Ptr)
	Function bmx_qt_qpen_dashpattern:Double[](handle:Byte Ptr)
	Function bmx_qt_qpen_iscosmetic:Int(handle:Byte Ptr)
	Function bmx_qt_qpen_issolid:Int(handle:Byte Ptr)
	Function bmx_qt_qpen_joinstyle:Int(handle:Byte Ptr)
	Function bmx_qt_qpen_miterlimit:Double(handle:Byte Ptr)
	Function bmx_qt_qpen_setbrush(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qpen_setcapstyle(handle:Byte Ptr, style:Int)
	Function bmx_qt_qpen_setcolor(handle:Byte Ptr, color:Byte Ptr)
	Function bmx_qt_qpen_setcosmetic(handle:Byte Ptr, cosmetic:Int)
	Function bmx_qt_qpen_setdashoffset(handle:Byte Ptr, offset:Double)
	Function bmx_qt_qpen_setdashpattern(handle:Byte Ptr, pattern:Double[])
	Function bmx_qt_qpen_setjoinstyle(handle:Byte Ptr, style:Int)
	Function bmx_qt_qpen_setmiterlimit(handle:Byte Ptr, limit:Double)
	Function bmx_qt_qpen_setstyle(handle:Byte Ptr, style:Int)
	Function bmx_qt_qpen_setwidth(handle:Byte Ptr, width:Int)
	Function bmx_qt_qpen_setwidthf(handle:Byte Ptr, width:Double)
	Function bmx_qt_qpen_style:Int(handle:Byte Ptr)
	Function bmx_qt_qpen_width:Int(handle:Byte Ptr)
	Function bmx_qt_qpen_widthf:Double(handle:Byte Ptr)
	Function bmx_qt_qpen_free(handle:Byte Ptr)

End Extern
