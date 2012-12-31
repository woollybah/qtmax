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
Import Qt.QIcon
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
Import "../src/include/QtWebKit/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
Import "/usr/include/qt4/QtWebKit/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qwebhistory_back(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_backitem:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_cangoback:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_cangoforward:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_clear(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_count:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_currentitem:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_currentitemindex:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_forward(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_forwarditem:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_gotoitem(handle:Byte Ptr, item:Byte Ptr)
	Function bmx_qt_qwebhistory_itemat:Byte Ptr(handle:Byte Ptr, index:Int)
	Function bmx_qt_qwebhistory_maximumitemcount:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhistory_setmaximumitemcount(handle:Byte Ptr, count:Int)
	Function bmx_qt_qwebhistory_free(handle:Byte Ptr)

	Function bmx_qt_qwebhistoryitem_free(handle:Byte Ptr)
	Function bmx_qt_qwebhistoryitem_icon:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhistoryitem_isvalid:Int(handle:Byte Ptr)
	Function bmx_qt_qwebhistoryitem_lastvisited:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhistoryitem_originalurl:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwebhistoryitem_title:String(handle:Byte Ptr)
	Function bmx_qt_qwebhistoryitem_url:Byte Ptr(handle:Byte Ptr)

End Extern
