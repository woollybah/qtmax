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
Import Qt.QFont
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

	Function bmx_qt_qfontmetrics_create:Byte Ptr(font:Byte Ptr)
	Function bmx_qt_qfontmetrics_ascent:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_averagecharwidth:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_boundingrect:Byte Ptr(handle:Byte Ptr, text:String)
	Function bmx_qt_qfontmetrics_free(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_descent:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_elidedtext:String(handle:Byte Ptr, text:String, _mode:Int, width:Int, flags:Int)
	Function bmx_qt_qfontmetrics_height:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_infont:Int(handle:Byte Ptr, ch:Int)
	Function bmx_qt_qfontmetrics_leading:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_leftbearing:Int(handle:Byte Ptr, ch:Int)
	Function bmx_qt_qfontmetrics_linespacing:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_linewidth:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_maxwidth:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_minleftbearing:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_minrightbearing:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_overlinepos:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_rightbearing:Int(handle:Byte Ptr, ch:Int)
	Function bmx_qt_qfontmetrics_size(handle:Byte Ptr, flags:Int, text:String, tabArray:Int[], w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qfontmetrics_strikeoutpos:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_tightboundingrect:Byte Ptr(handle:Byte Ptr, text:String)
	Function bmx_qt_qfontmetrics_underlinepos:Int(handle:Byte Ptr)
	Function bmx_qt_qfontmetrics_width:Int(handle:Byte Ptr, text:String, length:Int)
	Function bmx_qt_qfontmetrics_xheight:Int(handle:Byte Ptr)


End Extern

