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
Import Qt.QCursor
Import Qt.QPainterPath
Import Qt.QObject
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

	Function bmx_qt_qgraphicsitem_isselected:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_isundermouse:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_isvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_isvisibleto:Int(handle:Byte Ptr, parent:Byte Ptr)
	Function bmx_qt_qgraphicsitem_iswidget:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_iswindow:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_setacceptdrops(handle:Byte Ptr, on:Int)
	Function bmx_qt_qgraphicsitem_setaccepthoverevents(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicsitem_setacceptedmousebuttons(handle:Byte Ptr, buttons:Int)
	Function bmx_qt_qgraphicsitem_setboundingregiongranularity(handle:Byte Ptr, granularity:Double)
	Function bmx_qt_qgraphicsitem_setcachemode(handle:Byte Ptr, _mode:Int, w:Int, h:Int)
	Function bmx_qt_qgraphicsitem_setcursor(handle:Byte Ptr, cursor:Byte Ptr)
	Function bmx_qt_qgraphicsitem_setdata(handle:Byte Ptr, key:Int, value:Object)
	Function bmx_qt_qgraphicsitem_setenabled(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicsitem_setflag(handle:Byte Ptr, flag:Int, enabled:Int)
	Function bmx_qt_qgraphicsitem_setflags(handle:Byte Ptr, flags:Int)
	Function bmx_qt_qgraphicsitem_setfocus(handle:Byte Ptr, focusReason:Int)
	Function bmx_qt_qgraphicsitem_setgroup(handle:Byte Ptr, group:Byte Ptr)
	Function bmx_qt_qgraphicsitem_sethandleschildevents(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicsitem_setopacity(handle:Byte Ptr, opacity:Double)
	Function bmx_qt_qgraphicsitem_setparentitem(handle:Byte Ptr, parent:Byte Ptr)
	Function bmx_qt_qgraphicsitem_setpos(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qgraphicsitem_setselected(handle:Byte Ptr, selected:Int)
	Function bmx_qt_qgraphicsitem_settooltip(handle:Byte Ptr, toolTip:String)
	Function bmx_qt_qgraphicsitem_settransform(handle:Byte Ptr, matrix:Byte Ptr, combine:Int)
	Function bmx_qt_qgraphicsitem_setvisible(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qgraphicsitem_setzvalue(handle:Byte Ptr, z:Double)
	Function bmx_qt_qgraphicsitem_boundingrect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_addtoscene(handle:Byte Ptr, scene:Byte Ptr)

End Extern
