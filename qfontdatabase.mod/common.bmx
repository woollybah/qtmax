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
Import Qt.QFontInfo
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

	Function bmx_qt_qfontdatabase_create:Byte Ptr()
	Function bmx_qt_qfontdatabase_bold:Int(handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_families:String[](handle:Byte Ptr, writingSystem:Int)
	Function bmx_qt_qfontdatabase_font:Byte Ptr(handle:Byte Ptr, family:String, style:String, pointSize:Int)
	Function bmx_qt_qfontdatabase_isbitmapscalable:Int(handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_isfixedpitch:Int(handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_isscalable:Int(handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_issmoothlyscalable:Int(handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_italic:Int(handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_pointsizes:Int[](handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_smoothsizes:Int[](handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_stylestring:String(handle:Byte Ptr, font:Byte Ptr)
	Function bmx_qt_qfontdatabase_stylestringinfo:String(handle:Byte Ptr, fontInfo:Byte Ptr)
	Function bmx_qt_qfontdatabase_styles:String[](handle:Byte Ptr, family:String)
	Function bmx_qt_qfontdatabase_weight:Int(handle:Byte Ptr, family:String, style:String)
	Function bmx_qt_qfontdatabase_writingsystems:Int[](handle:Byte Ptr, family:String)
	Function bmx_qt_qfontdatabase_addapplicationfont:Int(fileName:String)
	Function bmx_qt_qfontdatabase_applicationfontfamilies:String[](id:Int)
	Function bmx_qt_qfontdatabase_removeallapplicationfonts:Int()
	Function bmx_qt_qfontdatabase_removeapplicationfont:Int(id:Int)
	Function bmx_qt_qfontdatabase_standardsizes:Int[]()
	Function bmx_qt_qfontdatabase_supportsthreadedfontrendering:Int()
	Function bmx_qt_qfontdatabase_writingsystemname:String(writingSystem:Int)
	Function bmx_qt_qfontdatabase_writingsystemsample:String(writingSystem:Int)
	Function bmx_qt_qfontdatabase_free(handle:Byte Ptr)

End Extern
