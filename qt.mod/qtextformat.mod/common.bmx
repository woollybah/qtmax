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
Import Qt.QBrush
Import Qt.QPen
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

	Function bmx_qt_textformat_background:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_textformat_boolproperty:Int(handle:Byte Ptr, propertyId:Int)
	Function bmx_qt_textformat_brushproperty:Byte Ptr(handle:Byte Ptr, propertyId:Int)
	Function bmx_qt_textformat_clearbackground(handle:Byte Ptr)
	Function bmx_qt_textformat_clearforeground(handle:Byte Ptr)
	Function bmx_qt_textformat_clearproperty(handle:Byte Ptr, propertyId:Int)
	Function bmx_qt_textformat_colorProperty:Byte Ptr(handle:Byte Ptr, propertyId:Int)
	Function bmx_qt_textformat_doubleproperty:Double(handle:Byte Ptr, propertyId:Int)
	Function bmx_qt_textformat_foreground:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_textformat_hasproperty:Int(handle:Byte Ptr, propertyId:Int)
	Function bmx_qt_textformat_intproperty:Int(handle:Byte Ptr, propertyId:Int)
	Function bmx_qt_textformat_isblockformat:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_ischarformat:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_isframeformat:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_isimageformat:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_islistformat:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_istablecellformat:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_istableformat:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_isvalid:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_layoutdirection:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_merge(handle:Byte Ptr, other:Byte Ptr)
	Function bmx_qt_textformat_objectindex:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_objecttype:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_penproperty:Byte Ptr(handle:Byte Ptr, propertyId:Int)
	Function bmx_qt_textformat_propertycount:Int(handle:Byte Ptr)
	Function bmx_qt_textformat_setbackground(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qtextformat_setforeground(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_textformat_setlayoutdirection(handle:Byte Ptr, direction:Int)
	Function bmx_qt_textformat_setobjectindex(handle:Byte Ptr, index:Int)
	Function bmx_qt_textformat_setobjecttype(handle:Byte Ptr, _type:Int)
	Function bmx_qt_textformat_stringproperty:String(handle:Byte Ptr, propertyId:Int)


End Extern
