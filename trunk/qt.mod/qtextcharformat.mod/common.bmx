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
Import Qt.QTextFormat
Import Qt.QPen
Import Qt.QColor
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
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qtextcharformat_create:Byte Ptr()
	Function bmx_qt_qtextcharformat_free(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_anchorhref:String(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_anchornames:String[](handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_font:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontcapitalization:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontfamily:String(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontfixedpitch:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontitalic:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontkerning:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontletterspacing:Double(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontoverline:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontpointsize:Double(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontstrikeout:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontstylehint:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontstylestrategy:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontunderline:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontweight:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_fontwordspacing:Double(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_isanchor:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_isvalid:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_setanchor(handle:Byte Ptr, anchor:Int)
	Function bmx_qt_qtextcharformat_setanchorhref(handle:Byte Ptr, value:String)
	Function bmx_qt_qtextcharformat_setanchornames(handle:Byte Ptr, names:String[])
	Function bmx_qt_qtextcharformat_setfont(handle:Byte Ptr, font:Byte Ptr)
	Function bmx_qt_qtextcharformat_setfontcapitalization(handle:Byte Ptr, capitalization:Int)
	Function bmx_qt_qtextcharformat_setfontfamily(handle:Byte Ptr, family:String)
	Function bmx_qt_qtextcharformat_setfontfixedpitch(handle:Byte Ptr, fixedpitch:Int)
	Function bmx_qt_qtextcharformat_setfontitalic(handle:Byte Ptr, italic:Int)
	Function bmx_qt_qtextcharformat_setfontkerning(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qtextcharformat_setfontletterspacing(handle:Byte Ptr, spacing:Double)
	Function bmx_qt_qtextcharformat_setfontoverline(handle:Byte Ptr, overline:Int)
	Function bmx_qt_qtextcharformat_setfontpointsize(handle:Byte Ptr, size:Double)
	Function bmx_qt_qtextcharformat_setfontstrikeout(handle:Byte Ptr, strikeOut:Int)
	Function bmx_qt_qtextcharformat_setfontstylehint(handle:Byte Ptr, hint:Int, strategy:Int)
	Function bmx_qt_qtextcharformat_setfontstylestrategy(handle:Byte Ptr, strategy:Int)
	Function bmx_qt_qtextcharformat_setfontunderline(handle:Byte Ptr, underline:Int)
	Function bmx_qt_qtextcharformat_setfontweight(handle:Byte Ptr, weight:Int)
	Function bmx_qt_qtextcharformat_setfontwordspacing(handle:Byte Ptr, spacing:Double)
	Function bmx_qt_qtextcharformat_settextoutline(handle:Byte Ptr, pen:Byte Ptr)
	Function bmx_qt_qtextcharformat_settooltip(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextcharformat_setunderlinecolor(handle:Byte Ptr, color:Byte Ptr)
	Function bmx_qt_qtextcharformat_setunderlinestyle(handle:Byte Ptr, style:Int)
	Function bmx_qt_qtextcharformat_setverticalalignment(handle:Byte Ptr, alignment:Int)
	Function bmx_qt_qtextcharformat_textoutline:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_tooltip:String(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_underlinecolor:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_underlinestyle:Int(handle:Byte Ptr)
	Function bmx_qt_qtextcharformat_verticalalignment:Int(handle:Byte Ptr)

	Function bmx_qt_qtextcharformat_setforeground(handle:Byte Ptr, brush:Byte Ptr)

End Extern
