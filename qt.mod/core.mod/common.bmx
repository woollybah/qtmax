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

Import "consts.bmx"

Import "glue.cpp"

Extern

	Function qfind:Object(handle:Byte Ptr)

	Function bmx_qt_qurl_create:Byte Ptr(url:String)
	Function bmx_qt_qurl_free(handle:Byte Ptr)

	Function bmx_qt_qrect_create:Byte Ptr(x:Int, y:Int, w:Int, h:Int)
	Function bmx_qt_qrect_free(handle:Byte Ptr)
	Function bmx_qt_qrect_adjust(handle:Byte Ptr, dx1:Int, dy1:Int, dx2:Int, dy2:Int)
	Function bmx_qt_qrect_adjusted:Byte Ptr(handle:Byte Ptr, dx1:Int, dy1:Int, dx2:Int, dy2:Int)
	Function bmx_qt_qrect_bottom:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_bottomleft(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_bottomright(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_center(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_contains:Int(handle:Byte Ptr, x:Int, y:Int, proper:Int)
	Function bmx_qt_qrect_containsrect:Int(handle:Byte Ptr, rectangle:Byte Ptr, proper:Int)
	Function bmx_qt_qrect_getcoords(handle:Byte Ptr, x1:Int Ptr, y1:Int Ptr, x2:Int Ptr, y2:Int Ptr)
	Function bmx_qt_qrect_getrect(handle:Byte Ptr, x:Int Ptr, y:Int Ptr, width:Int Ptr, height:Int Ptr)
	Function bmx_qt_qrect_height:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_intersected:Byte Ptr(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrect_intersects:Int(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrect_isempty:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_isnull:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_isvalid:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_left:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_movebottom(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_movebottomleft(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_movebottomright(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_movecenter(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_moveleft(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_moveright(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_moveto(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_movetop(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_movetopleft(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_movetopright(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_normalized:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qrect_right:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_setbottom(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_setbottomleft(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_setbottomright(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_setcoords(handle:Byte Ptr, x1:Int, y1:Int, x2:Int, y2:Int)
	Function bmx_qt_qrect_setheight(handle:Byte Ptr, height:Int)
	Function bmx_qt_qrect_setleft(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_setrect(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int)
	Function bmx_qt_qrect_setright(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_setsize(handle:Byte Ptr, w:Int, h:Int)
	Function bmx_qt_qrect_settop(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_settopleft(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_settopright(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qrect_setwidth(handle:Byte Ptr, width:Int)
	Function bmx_qt_qrect_setx(handle:Byte Ptr, x:Int)
	Function bmx_qt_qrect_sety(handle:Byte Ptr, y:Int)
	Function bmx_qt_qrect_size(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qrect_top:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_topleft(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_topright(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_qt_qrect_translate(handle:Byte Ptr, dx:Int, dy:Int)
	Function bmx_qt_qrect_translated:Byte Ptr(handle:Byte Ptr, dx:Int, dy:Int)
	Function bmx_qt_qrect_united:Byte Ptr(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qrect_width:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_x:Int(handle:Byte Ptr)
	Function bmx_qt_qrect_y:Int(handle:Byte Ptr)

End Extern
