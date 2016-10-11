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

Module Qt.QTabWidget

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QTabWidget Extends QWidget

	Rem
	bbdoc: The tabs are drawn above the pages.
	end rem
	Const Pos_North:Int = 0
	Rem
	bbdoc: The tabs are drawn below the pages.
	end rem
	Const Pos_South:Int = 1
	Rem
	bbdoc: The tabs are drawn to the left of the pages.
	end rem
	Const Pos_West:Int = 2
	Rem
	bbdoc: The tabs are drawn to the right of the pages.
	end rem
	Const Pos_East:Int = 3
	
	Rem
	bbdoc: The tabs are drawn with a rounded look. This is the default shape.
	end rem
	Const Shape_Rounded:Int = 0
	Rem
	bbdoc: The tabs are drawn with a triangular look.
	end rem
	Const Shape_Triangular:Int = 1

	Function CreateTabWidget:QTabWidget(parent:QWidget = Null)
		Return New QTabWidget.Create(parent)
	End Function
	
	Method Create:QTabWidget(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qtabwidget_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qtabwidget_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method addTab:Int(page:QWidget, label:String, icon:QIcon = Null)
		If icon Then
			Return bmx_qt_qtabwidget_addtab(qObjectPtr, page.qObjectPtr, label, icon.qObjectPtr)
		Else
			Return bmx_qt_qtabwidget_addtab(qObjectPtr, page.qObjectPtr, label, Null)
		End If
	End Method
	
	Method clear()
		bmx_qt_qtabwidget_clear(qObjectPtr)
	End Method
	
	Method cornerWidget:QWidget(corner:Int = Qt_TopRightCorner)
	' TODO
	End Method
	
	Method count:Int()
		Return bmx_qt_qtabwidget_count(qObjectPtr)
	End Method
	
	Method currentIndex:Int()
		Return bmx_qt_qtabwidget_currentindex(qObjectPtr)
	End Method
	
	Method currentWidget:QWidget()
	' TODO
	End Method
	
	Method documentMode:Int()
		Return bmx_qt_qtabwidget_documentmode(qObjectPtr)
	End Method
	
	Method elideMode:Int()
		Return bmx_qt_qtabwidget_elidemode(qObjectPtr)
	End Method
	
	Method iconSize(width:Int Var, height:Int Var)
		bmx_qt_qtabwidget_iconsize(qObjectPtr, Varptr width, Varptr height)
	End Method
	
	Method indexOf:Int(w:QWidget)
		Return bmx_qt_qtabwidget_indexof(qObjectPtr, w.qObjectPtr)
	End Method
	
	Method insertTab:Int(index:Int, page:QWidget, label:String, icon:QIcon = Null)
		If icon Then
			Return bmx_qt_qtabwidget_inserttab(qObjectPtr, index, page.qObjectPtr, label, icon.qObjectptr)
		Else
			Return bmx_qt_qtabwidget_inserttab(qObjectPtr, index, page.qObjectPtr, label, Null)
		End If
	End Method
	
	Method isMovable:Int()
		Return bmx_qt_qtabwidget_ismovable(qObjectPtr)
	End Method
	
	Method isTabEnabled:Int(index:Int)
		Return bmx_qt_qtabwidget_istabenabled(qObjectPtr, index)
	End Method
	
	Method removeTab(index:Int)
		bmx_qt_qtabwidget_removetab(qObjectPtr, index)
	End Method
	
	Method setCornerWidget(widget:QWidget, corner:Int = Qt_TopRightCorner)
		bmx_qt_qtabwidget_setcornerwidget(qObjectPtr, widget.qObjectPtr, corner)
	End Method
	
	Method setCurrentIndex(index:Int)
		bmx_qt_qtabwidget_setcurrentindex(qObjectPtr, index)
	End Method
	
	Method setCurrentWidget(widget:QWidget)
		bmx_qt_qtabwidget_setcurrentwidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method setDocumentMode(set:Int)
		bmx_qt_qtabwidget_setdocumentmode(qObjectPtr, set)
	End Method
	
	Method setElideMode(Mode:Int)
		bmx_qt_qtabwidget_setelidemode(qObjectPtr, Mode)
	End Method
	
	Method setIconSize(width:Int, height:Int)
		bmx_qt_qtabwidget_seticonsize(qObjectPtr, width, height)
	End Method
	
	Method setMovable(movable:Int)
		bmx_qt_qtabwidget_setmovable(qObjectPtr, movable)
	End Method
	
	Method setTabEnabled(index:Int, enable:Int)
		bmx_qt_qtabwidget_settabenabled(qObjectPtr, index, enable)
	End Method
	
	Method setTabIcon(index:Int, icon:QIcon)
		bmx_qt_qtabwidget_settabicon(qObjectPtr, index, icon.qObjectPtr)
	End Method
	
	Method setTabPosition(pos:Int)
		bmx_qt_qtabwidget_settabposition(qObjectPtr, pos)
	End Method
	
	Method setTabShape(shape:Int)
		bmx_qt_qtabwidget_settabshape(qObjectPtr, shape)
	End Method
	
	Method setTabText(index:Int, label:String)
		bmx_qt_qtabwidget_settabtext(qObjectPtr, index, label)
	End Method
	
	Method setTabToolTip(index:Int, tip:String)
		bmx_qt_qtabwidget_settabtooltip(qObjectPtr, index, tip)
	End Method
	
	Method setTabWhatsThis(index:Int, text:String)
		bmx_qt_qtabwidget_settabwhatsthis(qObjectPtr, index, text)
	End Method
	
	Method setTabsClosable(closeable:Int)
		bmx_qt_qtabwidget_settabsclosable(qObjectPtr, closeable)
	End Method
	
	Method setUsesScrollButtons(useButtons:Int)
		bmx_qt_qtabwidget_setusesscrollbuttons(qObjectPtr, useButtons)
	End Method
	
	Method tabBar:QTabBar()
		Return QTabBar._find(bmx_qt_qtabwidget_tabbar(qObjectPtr))
	End Method
	
	Method tabIcon:QIcon(index:Int)
		Return QIcon._create(bmx_qt_qtabwidget_tabicon(qObjectPtr, index))
	End Method
	
	Method tabPosition:Int()
		Return bmx_qt_qtabwidget_tabposition(qObjectPtr)
	End Method
	
	Method tabShape:Int()
		Return bmx_qt_qtabwidget_tabshape(qObjectPtr)
	End Method
	
	Method tabText:String(index:Int)
		Return bmx_qt_qtabwidget_tabtext(qObjectPtr, index)
	End Method
	
	Method tabToolTip:String(index:Int)
		Return bmx_qt_qtabwidget_tabtooltip(qObjectPtr, index)
	End Method
	
	Method tabWhatsThis:String(index:Int)
		Return bmx_qt_qtabwidget_tabwhatsthis(qObjectPtr, index)
	End Method
	
	Method tabsClosable:Int()
		Return bmx_qt_qtabwidget_tabsclosable(qObjectPtr)
	End Method
	
	Method usesScrollButtons:Int()
		Return bmx_qt_qtabwidget_usesscrollbuttons(qObjectPtr)
	End Method
	
	Method widget:QWidget(index:Int)
		' TODO
	End Method



	' DEFAULT EVENT HANDLERS
	
	' QTabWidget
	Method tabInserted(index:Int)
		bmx_qt_qtabwidget_default_tabinserted(qObjectPtr, index)
	End Method
	
	Method tabRemoved(index:Int)
		bmx_qt_qtabwidget_default_tabremoved(qObjectPtr, index)
	End Method
	
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qtabwidget_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qtabwidget_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qtabwidget_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qtabwidget_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qtabwidget_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qtabwidget_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qtabwidget_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qtabwidget_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qtabwidget_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qtabwidget_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qtabwidget_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qtabwidget_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qtabwidget_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qtabwidget_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qtabwidget_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qtabwidget_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qtabwidget_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qtabwidget_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qtabwidget_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qtabwidget_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qtabwidget_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qtabwidget_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qtabwidget_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qtabwidget_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qtabwidget_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qtabwidget_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qtabwidget_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qtabwidget_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qtabwidget_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qtabwidget_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qtabwidget_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method
	

	Function _tabInserted(obj:QTabWidget, index:Int)
		obj.tabInserted(index)
	End Function

	Function _tabRemoved(obj:QTabWidget, index:Int)
		obj.tabRemoved(index)
	End Function


	' SIGNAL : currentChanged
	Function _OnCurrentChanged(obj:QTabWidget, index:Int)
		obj._InvokeSignals("currentChanged", [String(index)])
	End Function

	' SIGNAL : tabCloseRequested
	Function _OnTabCloseRequested(obj:QTabWidget, index:Int)
		obj._InvokeSignals("tabCloseRequested", [String(index)])
	End Function

End Type

