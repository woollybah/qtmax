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

	Function bmx_qt_qabstractslider_hastracking:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_invertedappearance:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_invertedcontrols:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_issliderdown:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_maximum:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_minimum:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_orientation:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_pagestep:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_setinvertedappearance(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractslider_setinvertedcontrols(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractslider_setmaximum(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractslider_setminimum(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractslider_setpagestep(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractslider_setrange(handle:Byte Ptr, minimum:Int, maximum:Int)
	Function bmx_qt_qabstractslider_setsinglestep(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractslider_setsliderdown(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractslider_setsliderposition(handle:Byte Ptr, value:Int)
	Function bmx_qt_qabstractslider_settracking(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qabstractslider_singlestep:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_sliderposition:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_triggeraction(handle:Byte Ptr, sliderAction:Int)
	Function bmx_qt_qabstractslider_value:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractslider_setorientation(handle:Byte Ptr, orientation:Int)
	Function bmx_qt_qabstractslider_setvalue(handle:Byte Ptr, value:Int)

End Extern
