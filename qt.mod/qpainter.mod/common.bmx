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
Import Qt.QFont
Import Qt.QImage
Import Qt.QFontInfo
Import Qt.QFontMetrics
Import Qt.QWidget
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

	Function bmx_qt_qpainter_create:Byte Ptr(device:Byte Ptr)
	Function bmx_qt_qpainter_createwithwidget:Byte Ptr(device:Byte Ptr)
	Function bmx_qt_qpainter_free(handle:Byte Ptr)
	Function bmx_qt_qpainter_begin:Int(handle:Byte Ptr, device:Byte Ptr)
	Function bmx_qt_qpainter_end:Int(handle:Byte Ptr)
	Function bmx_qt_qpainter_resetmatrix(handle:Byte Ptr)
	Function bmx_qt_qpainter_resettransform(handle:Byte Ptr)
	Function bmx_qt_qpainter_restore(handle:Byte Ptr)
	Function bmx_qt_qpainter_rotate(handle:Byte Ptr, angle:Double)
	Function bmx_qt_qpainter_save(handle:Byte Ptr)
	Function bmx_qt_qpainter_scale(handle:Byte Ptr, sx:Double, sy:Double)
	Function bmx_qt_qpainter_setbrush(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qpainter_setbrushcolor(handle:Byte Ptr, color:Byte Ptr)
	Function bmx_qt_qpainter_drawconvexpolygon(handle:Byte Ptr, points:Int[])
	Function bmx_qt_qpainter_drawconvexpolygond(handle:Byte Ptr, points:Double[])
	Function bmx_qt_qpainter_drawellipse(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int)
	Function bmx_qt_qpainter_drawellipsecenter(handle:Byte Ptr, cx:Int, cy:Int, rx:Int, ry:Int)
	Function bmx_qt_qpainter_drawellipsecenterd(handle:Byte Ptr, cx:Double, cy:Double, rx:Double, ry:Double)
	Function bmx_qt_qpainter_drawline(handle:Byte Ptr, x1:Int, y1:Int, x2:Int, y2:Int)
	Function bmx_qt_qpainter_drawlined(handle:Byte Ptr, x1:Double, y1:Double, x2:Double, y2:Double)
	Function bmx_qt_qpainter_setpencolor(handle:Byte Ptr, color:Byte Ptr)
	Function bmx_qt_qpainter_setpenstyle(handle:Byte Ptr, style:Int)
	Function bmx_qt_qpainter_translate(handle:Byte Ptr, dx:Double, dy:Double)
	Function bmx_qt_qpainter_setrenderhint(handle:Byte Ptr, hint:Int, on:Int)
	Function bmx_qt_qpainter_setbrushgradient(handle:Byte Ptr, gradient:Byte Ptr)
	Function bmx_qt_qpainter_fillrect(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int, style:Int)
	Function bmx_qt_qpainter_fillrectrect(handle:Byte Ptr, rectangle:Byte Ptr, style:Int)
	Function bmx_qt_qpainter_fillrectbrush(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int, brush:Byte Ptr)
	Function bmx_qt_qpainter_fillrectrectbrush(handle:Byte Ptr, rectangle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qpainter_fillpath(handle:Byte Ptr, path:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qpainter_drawrectrect(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qpainter_drawrect(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int)
	Function bmx_qt_qpainter_drawtext(handle:Byte Ptr, x:Int, y:Int, text:String)
	Function bmx_qt_qpainter_fillrectcolor(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int, color:Byte Ptr)
	Function bmx_qt_qpainter_drawtiledpixmaprectf(handle:Byte Ptr, rectangle:Byte Ptr, pixmap:Byte Ptr, posX:Double, posY:Double)
	Function bmx_qt_qpainter_drawtiledpixmaprect(handle:Byte Ptr, rectangle:Byte Ptr, pixmap:Byte Ptr, posX:Int, posY:Int)
	Function bmx_qt_qpainter_drawtiledpixmap(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int, pixmap:Byte Ptr, sx:Int, sy:Int)
	Function bmx_qt_qpainter_drawimage(handle:Byte Ptr, x:Int, y:Int, image:Byte Ptr)
	Function bmx_qt_qpainter_setcliprect(handle:Byte Ptr, x:Int, y:Int, width:Int, height:Int, operation:Int)
	Function bmx_qt_qpainter_setfont(handle:Byte Ptr, font:Byte Ptr)
	Function bmx_qt_qpainter_setclipping(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qpainter_setcompositionmode(handle:Byte Ptr, _mode:Int)
	Function bmx_qt_qpainter_setopacity(handle:Byte Ptr, opacity:Double)

End Extern
