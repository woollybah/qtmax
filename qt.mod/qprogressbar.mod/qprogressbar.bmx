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

Module Qt.QProgressBar

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QProgressBar Extends QWidget

	Function CreateProgressBar:QProgressBar(parent:QWidget = Null)
		Return New QProgressBar.Create(parent)
	End Function
	
	Method Create:QProgressBar(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qprogressbar_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qprogressbar_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method alignment:Int()
		Return bmx_qt_qprogressbar_alignment(qObjectPtr)
	End Method
	
	Method format:String()
		Return bmx_qt_qprogressbar_format(qObjectPtr)
	End Method
	
	Method invertedAppearance:Int()
		Return bmx_qt_qprogressbar_invertedappearance(qObjectPtr)
	End Method
	
	Method isTextVisible:Int()
		Return bmx_qt_qprogressbar_istextvisible(qObjectPtr)
	End Method
	
	Method maximum:Int()
		Return bmx_qt_qprogressbar_maximum(qObjectPtr)
	End Method
	
	Method minimum:Int()
		Return bmx_qt_qprogressbar_minimum(qObjectPtr)
	End Method
	
	Method orientation:Int()
		Return bmx_qt_qprogressbar_orientation(qObjectPtr)
	End Method
	
	Method setAlignment(alignment:Int)
		bmx_qt_qprogressbar_setalignment(qObjectPtr, alignment)
	End Method
	
	Method setFormat(format:String)
		bmx_qt_qprogressbar_setformat(qObjectPtr, format)
	End Method
	
	Method setInvertedAppearance(invert:Int)
		bmx_qt_qprogressbar_setinvertedappearance(qObjectPtr, invert)
	End Method
	
	Method setTextDirection(textDirection:Int)
		bmx_qt_qprogressbar_settextdirection(qObjectPtr, textDirection)
	End Method
	
	Method setTextVisible(visible:Int)
		bmx_qt_qprogressbar_settextvisible(qObjectPtr, visible)
	End Method
	
	Method text:String()
		Return bmx_qt_qprogressbar_text(qObjectPtr)
	End Method
	
	Method textDirection:Int()
		Return bmx_qt_qprogressbar_textdirection(qObjectPtr)
	End Method
	
	Method value:Int()
		Return bmx_qt_qprogressbar_value(qObjectPtr)
	End Method
	
	Method reset()
		bmx_qt_qprogressbar_reset(qObjectPtr)
	End Method
	
	Method setMaximum(maximum:Int)
		bmx_qt_qprogressbar_setmaximum(qObjectPtr, maximum)
	End Method
	
	Method setMinimum(minimum:Int)
		bmx_qt_qprogressbar_setminimum(qObjectPtr, minimum)
	End Method
	
	Method setOrientation(orientation:Int)
		bmx_qt_qprogressbar_setorientation(qObjectPtr, orientation)
	End Method
	
	Method setRange(minimum:Int, maximum:Int)
		bmx_qt_qprogressbar_setrange(qObjectPtr, minimum, maximum)
	End Method
	
	Method setValue(value:Int)
		bmx_qt_qprogressbar_setvalue(qObjectPtr, value)
	End Method



	' DEFAULT EVENT HANDLERS
	
	' QProgressBar
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qprogressbar_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qprogressbar_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qprogressbar_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qprogressbar_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qprogressbar_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qprogressbar_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qprogressbar_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qprogressbar_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qprogressbar_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qprogressbar_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qprogressbar_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qprogressbar_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qprogressbar_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qprogressbar_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qprogressbar_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qprogressbar_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qprogressbar_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qprogressbar_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qprogressbar_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qprogressbar_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qprogressbar_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qprogressbar_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qprogressbar_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qprogressbar_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qprogressbar_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qprogressbar_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qprogressbar_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qprogressbar_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qprogressbar_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qprogressbar_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qprogressbar_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method



	' SIGNAL : valueChanged
	Function _OnValueChanged(obj:QProgressBar, value:Int)
		obj._InvokeSignals("valueChanged", [String(value)])
	End Function
	
End Type
