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
Import Qt.QBrush
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

	Function bmx_qt_qpalette_alternatebase:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_base:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_brighttext:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_brushforgroup:Byte Ptr(handle:Byte Ptr, group:Int, role:Int)
	Function bmx_qt_qpalette_brush:Byte Ptr(handle:Byte Ptr, role:Int)
	Function bmx_qt_qpalette_button:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_buttontext:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_cachekey(handle:Byte Ptr, key:Long Ptr)
	Function bmx_qt_qpalette_colorforgroup:Byte Ptr(handle:Byte Ptr, group:Int, role:Int)
	Function bmx_qt_qpalette_color:Byte Ptr(handle:Byte Ptr, role:Int)
	Function bmx_qt_qpalette_currentcolorgroup:Int(handle:Byte Ptr)
	Function bmx_qt_qpalette_dark:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_highlight:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_highlightedtext:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_isbrushset:Int(handle:Byte Ptr, cg:Int, cr:Int)
	Function bmx_qt_qpalette_iscopyof:Int(handle:Byte Ptr, p:Byte Ptr)
	Function bmx_qt_qpalette_isequal:Int(handle:Byte Ptr, cg1:Int, cg2:Int)
	Function bmx_qt_qpalette_light:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_link:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_linkvisited:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_mid:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_midlight:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_resolve:Byte Ptr(handle:Byte Ptr, other:Byte Ptr)
	Function bmx_qt_qpalette_setbrush(handle:Byte Ptr, role:Int, brush:Byte Ptr)
	Function bmx_qt_qpalette_setbrushforgroup(handle:Byte Ptr, group:Int, role:Int, brush:Byte Ptr)
	Function bmx_qt_qpalette_setcolorforgroup(handle:Byte Ptr, group:Int, role:Int, color:Byte Ptr)
	Function bmx_qt_qpalette_setcolor(handle:Byte Ptr, role:Int, color:Byte Ptr)
	Function bmx_qt_qpalette_setcolorgroup(handle:Byte Ptr, cg:Int, windowText:Byte Ptr, button:Byte Ptr, light:Byte Ptr, dark:Byte Ptr, Mid:Byte Ptr, text:Byte Ptr, brightText:Byte Ptr, base:Byte Ptr, window:Byte Ptr)
	Function bmx_qt_qpalette_setcurrentcolorgroup(handle:Byte Ptr, cg:Int)
	Function bmx_qt_qpalette_shadow:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_text:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_tooltipbase:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_tooltiptext:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_window:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpalette_windowtext:Byte Ptr(handle:Byte Ptr)

End Extern
