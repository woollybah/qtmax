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
Import Qt.QGraphicsView
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
Import "../src/include/QtSvg/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
Import "/usr/include/qt4/QtSvg/*.h"
?

?macos
Import "-lQtSvg.4"
?win32
Import "-lQtSvg4"
?linux
Import "-lQtSvg"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qgraphicssvgitem_create:Byte Ptr(handle:Object, filename:String, parent:Byte Ptr)

	Function bmx_qt_qgraphicssvgitem_isselected:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_isundermouse:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_isvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_isvisibleto:Int(handle:Byte Ptr, parent:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_iswidget:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_iswindow:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_setacceptdrops(handle:Byte Ptr, on:Int)
	Function bmx_qt_qgraphicssvgitem_setaccepthoverevents(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicssvgitem_setacceptedmousebuttons(handle:Byte Ptr, buttons:Int)
	Function bmx_qt_qgraphicssvgitem_setboundingregiongranularity(handle:Byte Ptr, granularity:Double)
	Function bmx_qt_qgraphicssvgitem_setcachemode(handle:Byte Ptr, _mode:Int, w:Int, h:Int)
	Function bmx_qt_qgraphicssvgitem_setcursor(handle:Byte Ptr, cursor:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_setdata(handle:Byte Ptr, key:Int, value:Object)
	Function bmx_qt_qgraphicssvgitem_setenabled(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicssvgitem_setflag(handle:Byte Ptr, flag:Int, enabled:Int)
	Function bmx_qt_qgraphicssvgitem_setflags(handle:Byte Ptr, flags:Int)
	Function bmx_qt_qgraphicssvgitem_setfocus(handle:Byte Ptr, focusReason:Int)
	Function bmx_qt_qgraphicssvgitem_setgroup(handle:Byte Ptr, group:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_sethandleschildevents(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicssvgitem_setopacity(handle:Byte Ptr, opacity:Double)
	Function bmx_qt_qgraphicssvgitem_setparentitem(handle:Byte Ptr, parent:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_setpos(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qgraphicssvgitem_setselected(handle:Byte Ptr, selected:Int)
	Function bmx_qt_qgraphicssvgitem_settooltip(handle:Byte Ptr, toolTip:String)
	Function bmx_qt_qgraphicssvgitem_settransform(handle:Byte Ptr, matrix:Byte Ptr, combine:Int)
	Function bmx_qt_qgraphicssvgitem_setvisible(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qgraphicssvgitem_setzvalue(handle:Byte Ptr, z:Double)
	Function bmx_qt_qgraphicssvgitem_boundingrect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicssvgitem_addtoscene(handle:Byte Ptr, scene:Byte Ptr)
	
End Extern
