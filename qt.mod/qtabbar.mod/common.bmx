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
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qtabbar_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qtabbar_addtab:Int(handle:Byte Ptr, text:String, icon:Byte Ptr)
	Function bmx_qt_qtabbar_count:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_currentindex:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_documentmode:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_drawbase:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_elidemode:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_expanding:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_iconsize(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qtabbar_inserttab:Int(handle:Byte Ptr, index:Int, text:String, icon:Byte Ptr)
	Function bmx_qt_qtabbar_ismovable:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_istabenabled:Int(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabbar_movetab(handle:Byte Ptr, _from:Int, _to:Int)
	Function bmx_qt_qtabbar_removetab(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabbar_selectionbehavioronremove:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_setdocumentmode(handle:Byte Ptr, set:Int)
	Function bmx_qt_qtabbar_setdrawbase(handle:Byte Ptr, drawTheBase:Int)
	Function bmx_qt_qtabbar_setelidemode(handle:Byte Ptr, _mode:Int)
	Function bmx_qt_qtabbar_setexpanding(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qtabbar_seticonsize(handle:Byte Ptr, w:Int, h:Int)
	Function bmx_qt_qtabbar_setmovable(handle:Byte Ptr, movable:Int)
	Function bmx_qt_qtabbar_setselectionbehaviouronremove(handle:Byte Ptr, behavior:Int)
	Function bmx_qt_qtabbar_setshape(handle:Byte Ptr, shape:Int)
	Function bmx_qt_qtabbar_settabbutton(handle:Byte Ptr, index:Int, position:Int, widget:Byte Ptr)
	Function bmx_qt_qtabbar_settabdata(handle:Byte Ptr, index:Int, data:Long)
	Function bmx_qt_qtabbar_settabenabled(handle:Byte Ptr, index:Int, enabled:Int)
	Function bmx_qt_qtabbar_settabicon(handle:Byte Ptr, index:Int, icon:Byte Ptr)
	Function bmx_qt_qtabbar_settabtext(handle:Byte Ptr, index:Int, text:String)
	Function bmx_qt_qtabbar_settabtextcolor(handle:Byte Ptr, index:Int, color:Byte Ptr)
	Function bmx_qt_qtabbar_settabtooltip(handle:Byte Ptr, index:Int, tip:String)
	Function bmx_qt_qtabbar_settabwhatsthis(handle:Byte Ptr, index:Int, text:String)
	Function bmx_qt_qtabbar_settabsclosable(handle:Byte Ptr, closable:Int)
	Function bmx_qt_qtabbar_setusesscrollbuttons(handle:Byte Ptr, useButtons:Int)
	Function bmx_qt_qtabbar_shape:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_tabat:Int(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qtabbar_tabbutton:Byte Ptr(handle:Byte Ptr, index:Int, position:Int)
	Function bmx_qt_qtabbar_tabdata(handle:Byte Ptr, index:Int, id:Long Ptr)
	Function bmx_qt_qtabbar_tabicon:Byte Ptr(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabbar_tabrect:Byte Ptr(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabbar_tabtext:String(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabbar_tabtextcolor:Byte Ptr(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabbar_tabtooltip:String(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabbar_tabwhatsthis:String(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabbar_tabsclosable:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_usesscrollbuttons:Int(handle:Byte Ptr)
	Function bmx_qt_qtabbar_setcurrentindex(handle:Byte Ptr, index:Int)

End Extern
