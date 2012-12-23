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

Import Qt.QObject
Import Qt.QEventLoop
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
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
?


Import "glue.cpp"

Extern

	Function bmx_qt_qcoreapplication_create:Byte Ptr(handle:Object)

	Function bmx_qt_qcoreapplication_addlibrarypath(path:String)
	Function bmx_qt_qcoreapplication_applicationdirpath:String()
	Function bmx_qt_qcoreapplication_applicationfilepath:String()
	Function bmx_qt_qcoreapplication_applicationname:String()
	Function bmx_qt_qcoreapplication_applicationpid(pid:Long Ptr)
	Function bmx_qt_qcoreapplication_flush()
	Function bmx_qt_qcoreapplication_translate:String(context:String, text:String, disambiguation:String, encoding:Int)

	Function bmx_qt_qcoreapplication_quit(handle:Byte Ptr)
	Function bmx_qt_qcoreapplication_processevents(handle:Byte Ptr, flags:Int)

End Extern
