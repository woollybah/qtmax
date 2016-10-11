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
Import Qt.QPixmap
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

	Function bmx_qt_qcursor_create:Byte Ptr(shape:Int)
	Function bmx_qt_qcursor_free(handle:Byte Ptr)
	Function bmx_qt_qcursor_bitmap:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qcursor_hotspot(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qcursor_mask:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qcursor_pixmap:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qcursor_setshape(handle:Byte Ptr, shape:Int)
	Function bmx_qt_qcursor_shape:Int(handle:Byte Ptr)
	Function bmx_qt_qcursor_pos(x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qcursor_setpos(x:Int, y:Int)

End Extern
