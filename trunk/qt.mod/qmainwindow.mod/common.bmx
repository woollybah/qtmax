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
Import Qt.QDockWidget
Import Qt.QToolBar
Import Qt.QMenu
Import Qt.QMenuBar
Import Qt.QStatusBar
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

	' QMainWindow
	' QWidget
	Function bmx_qt_qmainwindow_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_focusnextchild:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_default_focusnextprevchild:Int(handle:Byte Ptr, _next:Int)
	Function bmx_qt_qmainwindow_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_focuspreviouschild:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)
	' QObject
	Function bmx_qt_qmainwindow_default_event:Int(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qmainwindow_default_timerevent(handle:Byte Ptr, event:Byte Ptr)



	Function bmx_qt_qmainwindow_create:Byte Ptr(handle:Object, parent:Byte Ptr, flags:Int)

	Function bmx_qt_qmainwindow_adddockwidget(handle:Byte Ptr, area:Int, dockwidget:Byte Ptr, orientation:Int)
	Function bmx_qt_qmainwindow_addtoolbararea(handle:Byte Ptr, area:Int, toolbar:Byte Ptr)
	Function bmx_qt_qmainwindow_addtoolbar:Byte Ptr(handle:Byte Ptr, toolbar:Byte Ptr)
	Function bmx_qt_qmainwindow_addtoolbartxt:Byte Ptr(handle:Byte Ptr, toolbar:String)
	Function bmx_qt_qmainwindow_addtoolbarbreak(handle:Byte Ptr, area:Int)
	Function bmx_qt_qmainwindow_centralwidget:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_corner:Int(handle:Byte Ptr, c:Int)
	Function bmx_qt_qmainwindow_createpopupmenu:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_dockoptions:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_dockwidgetarea:Int(handle:Byte Ptr, dockwidget:Byte Ptr)
	Function bmx_qt_qmainwindow_documentmode:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_iconsize(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qmainwindow_inserttoolbar(handle:Byte Ptr, before:Byte Ptr, toolbar:Byte Ptr)
	Function bmx_qt_qmainwindow_inserttoolbarbreak(handle:Byte Ptr, before:Byte Ptr)
	Function bmx_qt_qmainwindow_isanimated:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_isdocknestingenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_menubar:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_menuwidget:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_removedockwidget(handle:Byte Ptr, dockwidget:Byte Ptr)
	Function bmx_qt_qmainwindow_removetoolbar(handle:Byte Ptr, toolbar:Byte Ptr)
	Function bmx_qt_qmainwindow_removetoolbarbreak(handle:Byte Ptr, before:Byte Ptr)
	Function bmx_qt_qmainwindow_restoredockwidget(handle:Byte Ptr, dockwidget:Byte Ptr)
	Function bmx_qt_qmainwindow_setcentralwidget(handle:Byte Ptr, widget:Byte Ptr)
	Function bmx_qt_qmainwindow_setcorner(handle:Byte Ptr, corner:Int, area:Int)
	Function bmx_qt_qmainwindow_setdockoptions(handle:Byte Ptr, options:Int)
	Function bmx_qt_qmainwindow_setdocumentmode(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qmainwindow_seticonsize(handle:Byte Ptr, w:Int, h:Int)
	Function bmx_qt_qmainwindow_setmenubar(handle:Byte Ptr, menuBar:Byte Ptr)
	Function bmx_qt_qmainwindow_setmenuwidget(handle:Byte Ptr, menuBar:Byte Ptr)
	Function bmx_qt_qmainwindow_setstatusbar(handle:Byte Ptr, statusbar:Byte Ptr)
	Function bmx_qt_qmainwindow_settabposition(handle:Byte Ptr, areas:Int, tabPosition:Int)
	Function bmx_qt_qmainwindow_settabshape(handle:Byte Ptr, tabShape:Int)
	Function bmx_qt_qmainwindow_settoolbuttonstyle(handle:Byte Ptr, toolButtonStyle:Int)
	Function bmx_qt_qmainwindow_setunifiedtitleandtoolbaronmac(handle:Byte Ptr, set:Int)
	Function bmx_qt_qmainwindow_splitdockwidget(handle:Byte Ptr, _first:Byte Ptr, _second:Byte Ptr, orientation:Int)
	Function bmx_qt_qmainwindow_statusBar:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_tabposition:Int(handle:Byte Ptr, area:Int)
	Function bmx_qt_qmainwindow_tabshape:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_tabifydockwidget(handle:Byte Ptr, _first:Byte Ptr, _second:Byte Ptr)
	Function bmx_qt_qmainwindow_toolbararea:Int(handle:Byte Ptr, toolbar:Byte Ptr)
	Function bmx_qt_qmainwindow_toolbarbreak:Int(handle:Byte Ptr, toolbar:Byte Ptr)
	Function bmx_qt_qmainwindow_toolbuttonstyle:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_unifiedtitleandtoolbaronmac:Int(handle:Byte Ptr)
	Function bmx_qt_qmainwindow_setanimated(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qmainwindow_setdocknestingenabled(handle:Byte Ptr, enabled:Int)
	
End Extern
