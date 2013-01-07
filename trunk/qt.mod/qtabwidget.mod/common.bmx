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

	' QTabWidget
	Function bmx_qt_qtabwidget_default_tabinserted(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabwidget_default_tabremoved(handle:Byte Ptr, index:Int)	
	' QWidget
	Function bmx_qt_qtabwidget_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_focusnextchild:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_default_focusnextprevchild:Int(handle:Byte Ptr, _next:Int)
	Function bmx_qt_qtabwidget_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_focuspreviouschild:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)
	' QObject
	Function bmx_qt_qtabwidget_default_event:Int(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtabwidget_default_timerevent(handle:Byte Ptr, event:Byte Ptr)


	Function bmx_qt_qtabwidget_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qtabwidget_addtab:Int(handle:Byte Ptr, page:Byte Ptr, label:String, icon:Byte Ptr)
	Function bmx_qt_qtabwidget_clear(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_count:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_currentindex:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_documentmode:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_elidemode:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_iconsize(handle:Byte Ptr, width:Int Ptr, height:Int Ptr)
	Function bmx_qt_qtabwidget_indexof:Int(handle:Byte Ptr, w:Byte Ptr)
	Function bmx_qt_qtabwidget_inserttab:Int(handle:Byte Ptr, index:Int, page:Byte Ptr, label:String, icon:Byte Ptr)
	Function bmx_qt_qtabwidget_ismovable:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_istabenabled:Int(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabwidget_removetab(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabwidget_setcornerwidget(handle:Byte Ptr, widget:Byte Ptr, corner:Int)
	Function bmx_qt_qtabwidget_setdocumentmode(handle:Byte Ptr, set:Int)
	Function bmx_qt_qtabwidget_setelidemode(handle:Byte Ptr, Mode:Int)
	Function bmx_qt_qtabwidget_seticonsize(handle:Byte Ptr, width:Int, height:Int)
	Function bmx_qt_qtabwidget_setmovable(handle:Byte Ptr, movable:Int)
	Function bmx_qt_qtabwidget_settabenabled(handle:Byte Ptr, index:Int, enable:Int)
	Function bmx_qt_qtabwidget_settabicon(handle:Byte Ptr, index:Int, icon:Byte Ptr)
	Function bmx_qt_qtabwidget_settabposition(handle:Byte Ptr, pos:Int)
	Function bmx_qt_qtabwidget_settabshape(handle:Byte Ptr, shape:Int)
	Function bmx_qt_qtabwidget_settabtext(handle:Byte Ptr, index:Int, label:String)
	Function bmx_qt_qtabwidget_settabtooltip(handle:Byte Ptr, index:Int, tip:String)
	Function bmx_qt_qtabwidget_settabwhatsthis(handle:Byte Ptr, index:Int, text:String)
	Function bmx_qt_qtabwidget_settabsclosable(handle:Byte Ptr, closeable:Int)
	Function bmx_qt_qtabwidget_setusesscrollbuttons(handle:Byte Ptr, useButtons:Int)
	Function bmx_qt_qtabwidget_tabicon:Byte Ptr(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabwidget_tabposition:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_tabshape:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_tabtext:String(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabwidget_tabtooltip:String(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabwidget_tabwhatsthis:String(handle:Byte Ptr, index:Int)
	Function bmx_qt_qtabwidget_tabsclosable:Int(handle:Byte Ptr)
	Function bmx_qt_qtabwidget_usesscrollbuttons:Int(handle:Byte Ptr)

End Extern
