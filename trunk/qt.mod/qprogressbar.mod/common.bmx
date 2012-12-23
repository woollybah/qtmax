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

	Function bmx_qt_qprogressbar_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qprogressbar_alignment:Int(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_format:String(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_invertedappearance:Int(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_istextvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_maximum:Int(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_minimum:Int(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_orientation:Int(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_setalignment(handle:Byte Ptr, alignment:Int)
	Function bmx_qt_qprogressbar_setformat(handle:Byte Ptr, format:String)
	Function bmx_qt_qprogressbar_setinvertedappearance(handle:Byte Ptr, invert:Int)
	Function bmx_qt_qprogressbar_settextdirection(handle:Byte Ptr, textDirection:Int)
	Function bmx_qt_qprogressbar_settextvisible(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qprogressbar_text:String(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_textdirection:Int(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_value:Int(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_reset(handle:Byte Ptr)
	Function bmx_qt_qprogressbar_setmaximum(handle:Byte Ptr, maximum:Int)
	Function bmx_qt_qprogressbar_setminimum(handle:Byte Ptr, minimum:Int)
	Function bmx_qt_qprogressbar_setorientation(handle:Byte Ptr, orientation:Int)
	Function bmx_qt_qprogressbar_setrange(handle:Byte Ptr, minimum:Int, maximum:Int)
	Function bmx_qt_qprogressbar_setvalue(handle:Byte Ptr, value:Int)

End Extern
