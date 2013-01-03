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

Module Qt.QGLWidget

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QGLWidget Extends QWidget

Rem
	Function CreateGLWidget:QGLWidget(format:QGLFormat = Null, parent:QWidget = Null, shareWidget:QGLWidget = Null, flags:Int = 0)
		Return New QGLWidget.Create(format, parent, shareWidget, flags)
	End Function
	
	Method Create:QGLWidget(format:QGLFormat = Null, parent:QWidget = Null, shareWidget:QGLWidget = Null, flags:Int = 0)
		If format Then
			If parent Then
				If shareWidget Then
					qObjectPtr = bmx_qt_qglwidget_create(Self, format.qObjectPtr, parent.qObjectPtr, shareWidget.qObjectPtr, flags)
				Else
					qObjectPtr = bmx_qt_qglwidget_create(Self, format.qObjectPtr, parent.qObjectPtr, Null, flags)
				End If
			Else
				If shareWidget Then
					qObjectPtr = bmx_qt_qglwidget_create(Self, format.qObjectPtr, Null, shareWidget.qObjectPtr, flags)
				Else
					qObjectPtr = bmx_qt_qglwidget_create(Self, format.qObjectPtr, Null, Null, flags)
				End If
			End If
		Else
			If parent Then
				If shareWidget Then
					qObjectPtr = bmx_qt_qglwidget_create(Self, Null, parent.qObjectPtr, shareWidget.qObjectPtr, flags)
				Else
					qObjectPtr = bmx_qt_qglwidget_create(Self, Null, parent.qObjectPtr, Null, flags)
				End If
			Else
				If shareWidget Then
					qObjectPtr = bmx_qt_qglwidget_create(Self, Null, Null, shareWidget.qObjectPtr, flags)
				Else
					qObjectPtr = bmx_qt_qglwidget_create(Self, Null, Null, Null, flags)
				End If
			End If
		End If
		OnInit()
		Return Self
	End Method

	Method doubleBuffer:Int()
		Return bmx_qt_qglwidget_doublebuffer(qObjectPtr)
	End Method
	
	Method format:QGLFormat()
		Return QGLFormat._create(bmx_qt_qglwidget_doublebuffer(qObjectPtr))
	End Method
	
	Method isSharing:Int()
		Return bmx_qt_qglwidget_issharing(qObjectPtr)
	End Method
	
	Method isValid:Int()
		Return bmx_qt_qglwidget_isvalid(qObjectPtr)
	End Method
End Rem



	' DEFAULT EVENT HANDLERS

	' QGLWidget
	Method glDraw()
		bmx_qt_qglwidget_default_gldraw(qObjectPtr)
	End Method
	
	Method glInit()
		bmx_qt_qglwidget_default_glinit(qObjectPtr)
	End Method
	
	Method initializeGL()
		bmx_qt_qglwidget_default_initializegl(qObjectPtr)
	End Method

	Method initializeOverlayGL()
		bmx_qt_qglwidget_default_initializeoverlaygl(qObjectPtr)
	End Method
	
	Method paintGL()
		bmx_qt_qglwidget_default_paintgl(qObjectPtr)
	End Method
	
	Method paintOverlayGL()
		bmx_qt_qglwidget_default_paintoverlaygl(qObjectPtr)
	End Method
	
	Method resizeGL(width:Int, height:Int)
		bmx_qt_qglwidget_default_resizegl(qObjectPtr, width, height)
	End Method
	
	Method resizeOverlayGL(width:Int, height:Int)
		bmx_qt_qglwidget_default_resizeoverlaygl(qObjectPtr, width, height)
	End Method

	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qglwidget_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qglwidget_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qglwidget_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qglwidget_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qglwidget_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qglwidget_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qglwidget_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qglwidget_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qglwidget_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qglwidget_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qglwidget_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qglwidget_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qglwidget_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qglwidget_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qglwidget_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qglwidget_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qglwidget_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qglwidget_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qglwidget_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qglwidget_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qglwidget_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qglwidget_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qglwidget_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qglwidget_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qglwidget_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qglwidget_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qglwidget_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qglwidget_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qglwidget_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qglwidget_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qglwidget_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method



	Function _glDraw(obj:QGLWidget)
		obj.glDraw()
	End Function
	
	Function _glInit(obj:QGLWidget)
		obj.glInit()
	End Function

	Function _initializeGL(obj:QGLWidget)
		obj.initializeGL()
	End Function

	Function _initializeOverlayGL(obj:QGLWidget)
		obj.initializeOverlayGL()
	End Function

	Function _paintGL(obj:QGLWidget)
		obj.paintGL()
	End Function

	Function _paintOverlayGL(obj:QGLWidget)
		obj.paintOverlayGL()
	End Function

	Function _resizeGL(obj:QGLWidget, width:Int, height:Int)
		obj.resizeGL(width, height)
	End Function

	Function _resizeOverlayGL(obj:QGLWidget, width:Int, height:Int)
		obj.resizeOverlayGL(width, height)
	End Function


End Type
