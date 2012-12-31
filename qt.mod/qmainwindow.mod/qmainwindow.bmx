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

Rem
bbdoc: Main application window.
End Rem
Module Qt.QMainWindow

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QMainWindow Extends QWidget

	Function CreateMainWindow:QMainWindow(parent:QWidget = Null, flags:Int = 0)
		Return New QMainWindow.Create(parent, flags)
	End Function
	
	Method Create:QMainWindow(parent:QWidget = Null, flags:Int = 0)
		If parent Then
			qObjectPtr = bmx_qt_qmainwindow_create(Self, parent.qObjectPtr, flags)
		Else
			qObjectPtr = bmx_qt_qmainwindow_create(Self, Null, flags)
		End If
		OnInit()
		Return Self
	End Method

	Method addDockWidget(area:Int, dockwidget:QDockWidget, orientation:Int = Qt_Vertical)
		bmx_qt_qmainwindow_adddockwidget(qObjectPtr, area, dockwidget.qObjectPtr, orientation)
	End Method
	
	Method addToolBarArea(area:Int, toolbar:QToolBar)
		bmx_qt_qmainwindow_addtoolbararea(qObjectPtr, area, toolbar.qObjectPtr)
	End Method
	
	Method addToolBar:QToolBar(toolbar:Object)
		If QToolBar(toolbar) Then
			Return QToolBar._find(bmx_qt_qmainwindow_addtoolbar(qObjectPtr, QToolBar(toolbar).qObjectPtr))
		Else If String(toolbar)
			Return QToolBar._find(bmx_qt_qmainwindow_addtoolbartxt(qObjectPtr, String(toolbar)))
		End If
	End Method
	
	Method addToolBarBreak(area:Int = Qt_TopToolBarArea)
		bmx_qt_qmainwindow_addtoolbarbreak(qObjectPtr, area)
	End Method
	
	Method centralWidget:QWidget()
		Return QWidget._find(bmx_qt_qmainwindow_centralwidget(qObjectPtr))
	End Method
	
	Method corner:Int(c:Int)
		Return bmx_qt_qmainwindow_corner(qObjectPtr, c)
	End Method
	
	Method createPopupMenu:QMenu()
		Return QMenu._find(bmx_qt_qmainwindow_createpopupmenu(qObjectPtr))
	End Method
	
	Method dockOptions:Int()
		Return bmx_qt_qmainwindow_dockoptions(qObjectPtr)
	End Method
	
	Method dockWidgetArea:Int(dockwidget:QDockWidget)
		Return bmx_qt_qmainwindow_dockwidgetarea(qObjectPtr, dockwidget.qObjectPtr)
	End Method
	
	Method documentMode:Int()
		Return bmx_qt_qmainwindow_documentmode(qObjectPtr)
	End Method
	
	Method iconSize(w:Int Var, h:Int Var)
		bmx_qt_qmainwindow_iconsize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method insertToolBar(before:QToolBar, toolbar:QToolBar)
		bmx_qt_qmainwindow_inserttoolbar(qObjectPtr, before.qObjectPtr, toolbar.qObjectPtr)
	End Method
	
	Method insertToolBarBreak(before:QToolBar)
		bmx_qt_qmainwindow_inserttoolbarbreak(qObjectPtr, before.qObjectPtr)
	End Method
	
	Method isAnimated:Int()
		Return bmx_qt_qmainwindow_isanimated(qObjectPtr)
	End Method
	
	Method isDockNestingEnabled:Int()
		Return bmx_qt_qmainwindow_isdocknestingenabled(qObjectPtr)
	End Method
	
	Method menuBar:QMenuBar()
		Return QMenuBar._find(bmx_qt_qmainwindow_menubar(qObjectPtr))
	End Method
	
	Method menuWidget:QWidget()
		Return QWidget._find(bmx_qt_qmainwindow_menuwidget(qObjectPtr))
	End Method
	
	Method removeDockWidget(dockwidget:QDockWidget)
		bmx_qt_qmainwindow_removedockwidget(qObjectPtr, dockwidget.qObjectPtr)
	End Method
	
	Method removeToolBar(toolbar:QToolBar)
		bmx_qt_qmainwindow_removetoolbar(qObjectPtr, toolbar.qObjectPtr)
	End Method
	
	Method removeToolBarBreak(before:QToolBar)
		bmx_qt_qmainwindow_removetoolbarbreak(qObjectPtr, before.qObjectPtr)
	End Method
	
	Method restoreDockWidget(dockwidget:QDockWidget)
		bmx_qt_qmainwindow_restoredockwidget(qObjectPtr, dockwidget.qObjectPtr)
	End Method
	
	'Method restoreState:Int(Const QByteArray & state, version:Int = 0)
	'	Return bmx_qt_qmainwindow_restorestate(qObjectPtr
	'End Method
	
	'Method saveState:Byte Ptr(Int version = 0)
	'	Return bmx_qt_qmainwindow_ (qObjectPtr
	'End Method
	
	Method setCentralWidget(widget:QWidget)
		bmx_qt_qmainwindow_setcentralwidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method setCorner(corner:Int, area:Int)
		bmx_qt_qmainwindow_setcorner(qObjectPtr, corner, area)
	End Method
	
	Method setDockOptions(options:Int)
		bmx_qt_qmainwindow_setdockoptions(qObjectPtr, options)
	End Method
	
	Method setDocumentMode(enabled:Int)
		bmx_qt_qmainwindow_setdocumentmode(qObjectPtr, enabled)
	End Method
	
	Method setIconSize(w:Int, h:Int)
		bmx_qt_qmainwindow_seticonsize(qObjectPtr, w, h)
	End Method
	
	Method setMenuBar(menuBar:QMenuBar)
		bmx_qt_qmainwindow_setmenubar(qObjectPtr, menuBar.qObjectPtr)
	End Method
	
	Method setMenuWidget(widget:QWidget)
		bmx_qt_qmainwindow_setmenuwidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method setStatusBar(statusbar:QStatusBar)
		bmx_qt_qmainwindow_setstatusbar(qObjectPtr, statusbar.qObjectPtr)
	End Method
	
	Method setTabPosition(areas:Int, tabPosition:Int)
		bmx_qt_qmainwindow_settabposition(qObjectPtr, areas, tabPosition)
	End Method
	
	Method setTabShape(tabShape:Int)
		bmx_qt_qmainwindow_settabshape(qObjectPtr, tabShape)
	End Method
	
	Method setToolButtonStyle(toolButtonStyle:Int)
		bmx_qt_qmainwindow_settoolbuttonstyle(qObjectPtr, toolButtonStyle)
	End Method
	
	Method setUnifiedTitleAndToolBarOnMac(set:Int)
		bmx_qt_qmainwindow_setunifiedtitleandtoolbaronmac(qObjectPtr, set)
	End Method
	
	Method splitDockWidget(_first:QDockWidget, _second:QDockWidget, orientation:Int)
		bmx_qt_qmainwindow_splitdockwidget(qObjectPtr, _first.qObjectPtr, _second.qObjectPtr, orientation)
	End Method
	
	Method statusBar:QStatusBar()
		Return QStatusBar._find(bmx_qt_qmainwindow_statusBar(qObjectPtr))
	End Method
	
	Method tabPosition:Int(area:Int)
		Return bmx_qt_qmainwindow_tabposition(qObjectPtr, area)
	End Method
	
	Method tabShape:Int()
		Return bmx_qt_qmainwindow_tabshape(qObjectPtr)
	End Method
	
	Method tabifiedDockWidgets:QDockWidget[](dockwidget:QDockWidget)
		' TODO
		'Return bmx_qt_qmainwindow_(qObjectPtr
	End Method
	
	Method tabifyDockWidget(_first:QDockWidget, _second:QDockWidget)
		bmx_qt_qmainwindow_tabifydockwidget(qObjectPtr, _first.qObjectPtr, _second.qObjectPtr)
	End Method
	
	Method toolBarArea:Int(toolbar:QToolBar)
		Return bmx_qt_qmainwindow_toolbararea(qObjectPtr, toolbar.qObjectPtr)
	End Method
	
	Method toolBarBreak:Int(toolbar:QToolBar)
		Return bmx_qt_qmainwindow_toolbarbreak(qObjectPtr, toolbar.qObjectPtr)
	End Method
	
	Method toolButtonStyle:Int()
		Return bmx_qt_qmainwindow_toolbuttonstyle(qObjectPtr)
	End Method
	
	Method unifiedTitleAndToolBarOnMac:Int()
		Return bmx_qt_qmainwindow_unifiedtitleandtoolbaronmac(qObjectPtr)
	End Method

	Method setAnimated(enabled:Int)
		bmx_qt_qmainwindow_setanimated(qObjectPtr, enabled)
	End Method
	
	Method setDockNestingEnabled(enabled:Int)
		bmx_qt_qmainwindow_setdocknestingenabled(qObjectPtr, enabled)
	End Method


	' DEFAULT EVENT HANDLERS
	
	' QMainWindow
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qmainwindow_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qmainwindow_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qmainwindow_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qmainwindow_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qmainwindow_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qmainwindow_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qmainwindow_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qmainwindow_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qmainwindow_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qmainwindow_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qmainwindow_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qmainwindow_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qmainwindow_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qmainwindow_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qmainwindow_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qmainwindow_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qmainwindow_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qmainwindow_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qmainwindow_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qmainwindow_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qmainwindow_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qmainwindow_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qmainwindow_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qmainwindow_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qmainwindow_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qmainwindow_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qmainwindow_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qmainwindow_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qmainwindow_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qmainwindow_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qmainwindow_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method





	' SIGNAL : iconSizeChanged
	Function _OnIconSizeChanged(obj:QMainWindow, width:Int, height:Int)
		obj._InvokeSignals("iconSizeChanged", [String(width), String(height)])
	End Function

	' SIGNAL : toolButtonStyleChanged
	Function _OnToolButtonStyleChanged(obj:QMainWindow, style:Int)
		obj._InvokeSignals("toolButtonStyleChanged", [String(style)])
	End Function

End Type
