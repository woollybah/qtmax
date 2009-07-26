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
Import Qt.QAbstractSpinBox
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

	Function bmx_qt_qdoublespinbox_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qdoublespinbox_cleantext:String(handle:Byte Ptr)
	Function bmx_qt_qdoublespinbox_decimals:Int(handle:Byte Ptr)
	Function bmx_qt_qdoublespinbox_maximum:Double(handle:Byte Ptr)
	Function bmx_qt_qdoublespinbox_minimum:Double(handle:Byte Ptr)
	Function bmx_qt_qdoublespinbox_prefix:String(handle:Byte Ptr)
	Function bmx_qt_qdoublespinbox_setdecimals(handle:Byte Ptr, prec:int)
	Function bmx_qt_qdoublespinbox_setmaximum(handle:Byte Ptr, value:Double)
	Function bmx_qt_qdoublespinbox_setminimum(handle:Byte Ptr, value:Double)
	Function bmx_qt_qdoublespinbox_setprefix(handle:Byte Ptr, prefix:String)
	Function bmx_qt_qdoublespinbox_setrange(handle:Byte Ptr, minimum:Double, maximum:Double)
	Function bmx_qt_qdoublespinbox_setsinglestep(handle:Byte Ptr, val:Double)
	Function bmx_qt_qdoublespinbox_setsuffix(handle:Byte Ptr, suffix:String)
	Function bmx_qt_qdoublespinbox_singlestep:Double(handle:Byte Ptr)
	Function bmx_qt_qdoublespinbox_suffix:String(handle:Byte Ptr)
	Function bmx_qt_qdoublespinbox_value:Double(handle:Byte Ptr)

	Function bmx_qt_qdoublespinbox_setvalue(handle:Byte Ptr, value:Double)

	
End Extern
