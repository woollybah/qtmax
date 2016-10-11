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

Module Qt.QAbstractScrollArea

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"



Type QAbstractScrollArea Extends QFrame

	Method addScrollBarWidget(widget:QWidget, alignment:Int)
		bmx_qt_qabstractscrollarea_addscrollbarwidget(qObjectPtr, widget.qObjectPtr, alignment)
	End Method
	
	Method cornerWidget:QWidget()
		Return QWidget._find(bmx_qt_qabstractscrollarea_cornerwidget(qObjectPtr))
	End Method
	
	Method horizontalScrollBar:QScrollBar()
		Return QScrollBar._find(bmx_qt_qabstractscrollarea_horizontalscrollbar(qObjectPtr))
	End Method
	
	Method horizontalScrollBarPolicy:Int()
		Return bmx_qt_qabstractscrollarea_horizontalscrollbarpolicy(qObjectPtr)
	End Method
	
	Method maximumViewportSize(w:Int Var, h:Int Var)
		bmx_qt_qabstractscrollarea_maximumviewportsize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method scrollBarWidgets:QWidget[](alignment:Int)
		'Return bmx_qt_qabstractscrollarea_scrollbarwidgets(qObjectPtr)
	End Method
	
	Method setCornerWidget(widget:QWidget)
		bmx_qt_qabstractscrollarea_setcornerwidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method setHorizontalScrollBar(scrollBar:QScrollBar)
		bmx_qt_qabstractscrollarea_sethorizontalscrollbar(qObjectPtr, scrollBar.qObjectPtr)
	End Method
	
	Method setHorizontalScrollBarPolicy(policy:Int)
		bmx_qt_qabstractscrollarea_sethorizontalscrollbarpolicy(qObjectPtr, policy)
	End Method
	
	Method setVerticalScrollBar(scrollBar:QScrollBar)
		bmx_qt_qabstractscrollarea_setverticalscrollbar(qObjectPtr, scrollBar.qObjectPtr)
	End Method
	
	Method setVerticalScrollBarPolicy(policy:Int)
		bmx_qt_qabstractscrollarea_setverticalscrollbarpolicy(qObjectPtr, policy)
	End Method
	
	Method SetViewport(widget:QWidget)
		bmx_qt_qabstractscrollarea_setviewport(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method verticalScrollBar:QScrollBar()
		Return QScrollBar._find(bmx_qt_qabstractscrollarea_verticalscrollbar(qObjectPtr))
	End Method
	
	Method verticalScrollBarPolicy:Int()
		Return bmx_qt_qabstractscrollarea_verticalscrollbarpolicy(qObjectPtr)
	End Method
	
	Method viewport:QWidget() 
		Return QWidget._find(bmx_qt_qabstractscrollarea_viewport(qObjectPtr))
	End Method


	' DEFAULT EVENT HANDLERS
	
	' QAbstractScrollArea
	Method scrollContentsBy(dx:Int, dy:Int)
		bmx_qt_qabstractscrollarea_default_scrollcontentsby(qObjectPtr, dx, dy)
	End Method
	
	Method viewportEvent:Int(event:QEvent)
		Return bmx_qt_qabstractscrollarea_default_viewportevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	' QFrame
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qabstractscrollarea_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qabstractscrollarea_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qabstractscrollarea_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qabstractscrollarea_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qabstractscrollarea_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qabstractscrollarea_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qabstractscrollarea_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qabstractscrollarea_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qabstractscrollarea_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qabstractscrollarea_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qabstractscrollarea_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qabstractscrollarea_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qabstractscrollarea_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qabstractscrollarea_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qabstractscrollarea_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qabstractscrollarea_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qabstractscrollarea_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qabstractscrollarea_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qabstractscrollarea_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qabstractscrollarea_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qabstractscrollarea_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qabstractscrollarea_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qabstractscrollarea_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qabstractscrollarea_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qabstractscrollarea_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qabstractscrollarea_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qabstractscrollarea_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qabstractscrollarea_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qabstractscrollarea_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qabstractscrollarea_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qabstractscrollarea_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method



	'
	Function _scrollContentsBy(obj:QAbstractScrollArea, dx:Int, dy:Int)
		obj.scrollContentsBy(dx, dy)
	End Function

	Function _viewportEvent:Int(obj:QAbstractScrollArea, event:Byte Ptr)
		Return obj.viewportEvent(QEvent._create(event))
	End Function

End Type

