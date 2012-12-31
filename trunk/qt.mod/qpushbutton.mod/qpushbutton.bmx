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

Module Qt.QPushButton

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QPushButton Extends QAbstractButton

	Function CreatePushButton:QPushButton(text:String, parent:QWidget = Null)
		Return New QPushButton.Create(text, parent)
	End Function
	
	Method Create:QPushButton(text:String, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qpushbutton_create(Self, text, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qpushbutton_create(Self, text, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method autoDefault:Int()
		Return bmx_qt_qpushbutton_autodefault(qObjectPtr)
	End Method
	
	Method isDefault:Int()
		Return bmx_qt_qpushbutton_isdefault(qObjectPtr)
	End Method
	
	Method isFlat:Int()
		Return bmx_qt_qpushbutton_isflat(qObjectPtr)
	End Method
	
	Method menu:QMenu()
		Return QMenu._find(bmx_qt_qpushbutton_menu(qObjectPtr))
	End Method
	
	Method setAutoDefault(value:Int)
		bmx_qt_qpushbutton_setautodefault(qObjectPtr, value)
	End Method
	
	Method setDefault(value:Int)
		bmx_qt_qpushbutton_setdefault(qObjectPtr, value)
	End Method
	
	Method setFlat(value:Int)
		bmx_qt_qpushbutton_setflat(qObjectPtr, value)
	End Method
	
	Method setMenu(menu:QMenu)
		bmx_qt_qpushbutton_setmenu(qObjectPtr, menu.qObjectPtr)
	End Method
	
	
	' DEFAULT EVENT HANDLERS
	
	' QPushButton
	' QAbstractButton
	Method checkStateSet()
		bmx_qt_qpushbutton_default_checkstateset(qObjectPtr)
	End Method

	Method hitButton:Int(x:Int, y:Int)
		Return bmx_qt_qpushbutton_default_hitbutton(qObjectPtr, x, y)
	End Method
	
	Method nextCheckState()
		bmx_qt_qpushbutton_default_nextcheckstate(qObjectPtr)
	End Method

	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qpushbutton_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qpushbutton_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qpushbutton_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qpushbutton_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qpushbutton_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qpushbutton_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qpushbutton_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qpushbutton_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qpushbutton_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qpushbutton_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qpushbutton_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qpushbutton_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qpushbutton_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qpushbutton_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qpushbutton_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qpushbutton_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qpushbutton_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qpushbutton_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qpushbutton_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qpushbutton_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qpushbutton_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qpushbutton_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qpushbutton_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qpushbutton_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qpushbutton_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qpushbutton_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qpushbutton_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qpushbutton_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qpushbutton_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qpushbutton_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qpushbutton_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method

	
	
	' SLOT
	Method showMenu()
		bmx_qt_qpushbutton_showmenu(qObjectPtr)
	End Method

	' SIGNAL : clicked
	Function _OnClicked(obj:QPushButton, checked:Int)
		obj._InvokeSignals("clicked", [String(checked)])
	End Function

	' SIGNAL : pressed
	Function _OnPressed(obj:QPushButton, checked:Int)
		obj._InvokeSignals("pressed", Null)
	End Function

	' SIGNAL : released
	Function _OnReleased(obj:QPushButton)
		obj._InvokeSignals("released", Null)
	End Function

	' SIGNAL : toggled
	Function _OnToggled(obj:QPushButton, checked:Int)
		obj._InvokeSignals("toggled", [String(checked)])
	End Function

End Type

