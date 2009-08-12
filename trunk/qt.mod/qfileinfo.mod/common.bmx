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
Import Qt.QFile
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

	Function bmx_qt_qfileinfo_create:Byte Ptr(file:String)
	Function bmx_qt_qfileinfo_createfile:Byte Ptr(file:Byte Ptr)
	Function bmx_qt_qfileinfo_free(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_absolutefilepath:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_absolutepath:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_basename:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_bundlename:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_caching:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_canonicalfilepath:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_canonicalpath:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_completebasename:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_completesuffix:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_exists:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_filename:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_filepath:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_group:String(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_groupid:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_isabsolute:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_isbundle:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_isdir:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_isexecutable:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_isfile:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_ishidden:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_isreadable:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_isrelative:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_isroot:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_issymlink:Int(handle:Byte Ptr)
	Function bmx_qt_qfileinfo_iswritable:Int(handle:Byte Ptr)


End Extern
