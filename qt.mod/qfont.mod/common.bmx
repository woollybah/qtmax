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

	Function bmx_qt_qfont_create:Byte Ptr(family:String, pointSize:Int, weight:Int, italic:Int)
	Function bmx_qt_qfont_bold:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_capitalization:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_defaultfamily:String(handle:Byte Ptr)
	Function bmx_qt_qfont_exactmatch:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_family:String(handle:Byte Ptr)
	Function bmx_qt_qfont_fixedpitch:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_fromstring:Int(handle:Byte Ptr, description:String)
	Function bmx_qt_qfont_iscopyof:Int(handle:Byte Ptr, f:Byte Ptr)
	Function bmx_qt_qfont_italic:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_kerning:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_key:String(handle:Byte Ptr)
	Function bmx_qt_qfont_lastresortfamily:String(handle:Byte Ptr)
	Function bmx_qt_qfont_lastresortfont:String(handle:Byte Ptr)
	Function bmx_qt_qfont_letterspacing:Double(handle:Byte Ptr)
	Function bmx_qt_qfont_letterspacingtype:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_overline:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_pixelsize:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_pointsize:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_pointsizef:Double(handle:Byte Ptr)
	Function bmx_qt_qfont_rawmode:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_rawname:String(handle:Byte Ptr)
	Function bmx_qt_qfont_resolve:Byte Ptr(handle:Byte Ptr, other:Byte Ptr)
	Function bmx_qt_qfont_setbold(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qfont_setcapitalization(handle:Byte Ptr, caps:Int)
	Function bmx_qt_qfont_setfamily(handle:Byte Ptr, family:String)
	Function bmx_qt_qfont_setfixedpitch(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qfont_setitalic(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qfont_setkerning(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qfont_setletterspacing(handle:Byte Ptr, _type:Int, spacing:Double)
	Function bmx_qt_qfont_setoverline(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qfont_setpixelsize(handle:Byte Ptr, pixelSize:Int)
	Function bmx_qt_qfont_setpointsize(handle:Byte Ptr, pointSize:Int)
	Function bmx_qt_qfont_setpointsizef(handle:Byte Ptr, pointSize:Double)
	Function bmx_qt_qfont_setrawmode(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qfont_setrawname(handle:Byte Ptr, name:String)
	Function bmx_qt_qfont_setstretch(handle:Byte Ptr, factor:Int)
	Function bmx_qt_qfont_setstrikeout(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qfont_setstyle(handle:Byte Ptr, style:Int)
	Function bmx_qt_qfont_setstylehint(handle:Byte Ptr, hint:Int, strategy:Int)
	Function bmx_qt_qfont_setstylestrategy(handle:Byte Ptr, s:Int)
	Function bmx_qt_qfont_setunderline(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qfont_setweight(handle:Byte Ptr, weight:Int)
	Function bmx_qt_qfont_setwordspacing(handle:Byte Ptr, spacing:Double)
	Function bmx_qt_qfont_stretch:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_strikeout:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_style:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_stylehint:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_stylestrategy:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_tostring:String(handle:Byte Ptr)
	Function bmx_qt_qfont_underline:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_weight:Int(handle:Byte Ptr)
	Function bmx_qt_qfont_wordspacing:Double(handle:Byte Ptr)
	Function bmx_qt_qfont_free(handle:Byte Ptr)

End Extern
