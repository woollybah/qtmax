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
Import Qt.QRegion
Import Qt.QTransform
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
	Function bmx_qt_qpainterpath_create:Byte Ptr()
	Function bmx_qt_qpainterpath_free(handle:Byte Ptr)

	Function bmx_qt_qpainterpath_addellipse(handle:Byte Ptr, x:Double, y:Double, width:Double, height:Double)
	Function bmx_qt_qpainterpath_addellipsecenter(handle:Byte Ptr, cx:Double, cy:Double, rx:Double, ry:Double)
	Function bmx_qt_qpainterpath_addpath(handle:Byte Ptr, path:Byte Ptr)
	Function bmx_qt_qpainterpath_addrect(handle:Byte Ptr, x:Double, y:Double, width:Double, height:Double)
	Function bmx_qt_qpainterpath_addregion(handle:Byte Ptr, region:Byte Ptr)
	Function bmx_qt_qpainterpath_addroundedrect(handle:Byte Ptr, x:Double, y:Double, w:Double, h:Double, xRadius:Double, yRadius:Double, _mode:Int)
	Function bmx_qt_qpainterpath_addtext(handle:Byte Ptr, x:Double, y:Double, font:Byte Ptr, text:String)
	Function bmx_qt_qpainterpath_angleatpercent:Double(handle:Byte Ptr, t:Double)
	Function bmx_qt_qpainterpath_arcmoveto(handle:Byte Ptr, x:Double, y:Double, width:Double, height:Double, angle:Double)
	Function bmx_qt_qpainterpath_arcto(handle:Byte Ptr, x:Double, y:Double, width:Double, height:Double, startAngle:Double, sweepLength:Double)
	Function bmx_qt_qpainterpath_boundingrect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpainterpath_closesubpath(handle:Byte Ptr)
	Function bmx_qt_qpainterpath_connectpath(handle:Byte Ptr, path:Byte Ptr)
	Function bmx_qt_qpainterpath_contains:Int(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qpainterpath_containsrect:Int(handle:Byte Ptr, rectangle:Byte Ptr)
	Function bmx_qt_qpainterpath_containspath:Int(handle:Byte Ptr, p:Byte Ptr)
	Function bmx_qt_qpainterpath_controlpointrect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpainterpath_cubicto(handle:Byte Ptr, c1X:Double, c1Y:Double, c2X:Double, c2Y:Double, endPointX:Double, endPointY:Double)
	Function bmx_qt_qpainterpath_currentposition(handle:Byte Ptr, x:Double Ptr, y:Double Ptr)
	Function bmx_qt_qpainterpath_elementat:Byte Ptr(handle:Byte Ptr, index:Int)
	Function bmx_qt_qpainterpath_elementcount:Int(handle:Byte Ptr)
	Function bmx_qt_qpainterpath_fillrule:Int(handle:Byte Ptr)
	Function bmx_qt_qpainterpath_intersected:Byte Ptr(handle:Byte Ptr, p:Byte Ptr)
	Function bmx_qt_qpainterpath_intersects:Int(handle:Byte Ptr, p:Byte Ptr)
	Function bmx_qt_qpainterpath_isempty:Int(handle:Byte Ptr)
	Function bmx_qt_qpainterpath_length:Double(handle:Byte Ptr)
	Function bmx_qt_qpainterpath_lineto(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qpainterpath_moveto(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qpainterpath_percentatlength:Double(handle:Byte Ptr, length:Double)
	Function bmx_qt_qpainterpath_pointatpercent(handle:Byte Ptr, t:Double, x:Double Ptr, y:Double Ptr)
	Function bmx_qt_qpainterpath_quadto(handle:Byte Ptr, cx:Double, cy:Double, endPointX:Double, endPointY:Double)
	Function bmx_qt_qpainterpath_setelementpositionat(handle:Byte Ptr, index:Int, x:Double, y:Double)
	Function bmx_qt_qpainterpath_setfillrule(handle:Byte Ptr, fillRule:Int)
	Function bmx_qt_qpainterpath_simplified:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qpainterpath_slopeatpercent:Double(handle:Byte Ptr, t:Double)
	Function bmx_qt_qpainterpath_subtracted:Byte Ptr(handle:Byte Ptr, p:Byte Ptr)
	Function bmx_qt_qpainterpath_toreversed:Byte Ptr(handle:Byte Ptr)

	
End Extern
