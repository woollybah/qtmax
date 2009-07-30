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

Rem
bbdoc: The base of all user interface objects.
End Rem
Module Qt.QWidget

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"

?macos
ModuleInfo "LD_OPTS: -L%PWD%/../lib/macos/"
?win32
ModuleInfo "LD_OPTS: -L%PWD%/../lib/win32/"
?

?macos
Import "-lQtGui.4"
?win32
Import "-lQtGui4"
?linux
Import "-lQtGui"
?

Import "common.bmx"


Type QWidget Extends QObject

	Function CreateWidget:QWidget(parent:QWidget = Null, flags:Int = 0)
		Return New QWidget._Create(parent, flags)
	End Function
	
	Method _Create:QWidget(parent:QWidget = Null, flags:Int = 0)
		If parent Then
			qObjectPtr = bmx_qt_qwidget_create(Self, parent.qObjectPtr, flags)
		Else
			qObjectPtr = bmx_qt_qwidget_create(Self, Null, flags)
		End If
		OnInit()
		Return Self
	End Method
	
	Function __create:QWidget(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWidget = New QWidget
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QWidget(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QWidget = QWidget(qfind(qObjectPtr))
			If Not widget Then
				Return QWidget.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Method OnInit()
	End Method
	
	Method addAction:QAction(action:Object)
		If QAction(action) Then
			bmx_qt_qwidget_addaction(qObjectPtr, QAction(action).qObjectPtr)
			Return QAction(action)
		End If
	End Method

	Method frameGeometry:QRect()
		Return QRect._create(bmx_qt_qwidget_framegeometry(qObjectPtr))
	End Method
	
	Method frameSize(w:Int Var, h:Int Var)
		bmx_qt_qwidget_framesize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method geometry:QRect()
		Return QRect._create(bmx_qt_qwidget_geometry(qObjectPtr))
	End Method
	
	Method hasEditFocus:Int()
	' TODO
	End Method
	
	Method hasFocus:Int()
	' TODO
	End Method
	
	Method hasMouseTracking:Int()
	' TODO
	End Method
	
	Method height:Int()
		Return bmx_qt_qwidget_height(qObjectPtr)
	End Method
	
	Method heightForWidth:Int(w:Int)
	' TODO
	End Method

	'Method inputContext:QInputContext()
	' TODO
	'End Method
	
	'Method inputMethodQuery:QVariant(query:Int)
	' TODO
	'End Method

	'Method insertAction(before:QAction, action:QAction)
	' TODO
	'End Method

	'Method insertActions(before:QAction, actions:QAction([])
	' TODO
	'End Method

	Method isActiveWindow:Int()
	' TODO
	End Method
	
	Method isAncestorOf:Int(child:QWidget)
	' TODO
	End Method
	
	Method isEnabled:Int()
	' TODO
	End Method
	
	Method isEnabledTo:Int(ancestor:QWidget)
	' TODO
	End Method
	
	Method isFullScreen:Int()
	' TODO
	End Method
	
	Method isHidden:Int()
	' TODO
	End Method
	
	Method isMaximized:Int()
	' TODO
	End Method
	
	Method isMinimized:Int()
	' TODO
	End Method
	
	Method isModal:Int()
	' TODO
	End Method
	
	Method isVisible:Int()
	' TODO
	End Method
	
	Method isVisibleTo:Int(ancestor:QWidget)
	' TODO
	End Method
	
	Method isWindow:Int()
	' TODO
	End Method
	
	Method isWindowModified:Int()
	' TODO
	End Method


	Method layout:QLayout()
	' TODO
	End Method
	
	Method layoutDirection:Int()
	' TODO
	End Method
	
	Method locale:QLocale()
	' TODO
	End Method
	
	Method macCGHandle:Byte Ptr()
	' TODO
	End Method
	
	Method macQDHandle:Byte Ptr()
	' TODO
	End Method
	
	Method mapFrom(parent:QWidget, x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapFromGlobal(x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapFromParent(x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapTo(parent:QWidget, x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapToGlobal(x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapToParent(x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mask:QRegion()
	' TODO
	End Method
	
	Method maximumHeight:Int()
	' TODO
	End Method
	
	Method maximumSize(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method maximumWidth:Int()
	' TODO
	End Method
	
	Method minimumHeight:Int()
	' TODO
	End Method
	
	Method minimumSize(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	' overridable
	Method minimumSizeHint(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method minimumWidth:Int()
	' TODO
	End Method
	
	Method move(x:Int, y:Int)
		bmx_qt_qwidget_move(qObjectPtr, x, y)
	End Method
	
	Method nativeParentWidget:QWidget()
	' TODO
	End Method
	
	Method nextInFocusChain:QWidget()
	' TODO
	End Method
	
	
	
	Method resize(w:Int, h:Int)
		bmx_qt_qwidget_resize(qObjectPtr, w, h)
	End Method
	
	Method setAttribute(attribute:Int)
		bmx_qt_qwidget_setattribute(qObjectPtr, attribute)
	End Method
	
	Method setContextMenuPolicy(policy:Int)
		bmx_qt_qwidget_setcontextmenupolicy(qObjectPtr, policy)
	End Method
	
	Method stackUnder(w:QWidget)
		bmx_qt_qwidget_stackunder(qObjectPtr, w.qObjectPtr)
	End Method

	Method setFixedSize(w:Int, h:Int)
		bmx_qt_qwidget_setfixedsize(qObjectPtr, w, h)
	End Method
	
	Method setFixedWidth(w:Int)
		bmx_qt_qwidget_setfixedwidth(qObjectPtr, w)
	End Method
	
	Method setLayout(layout:QLayout)
		bmx_qt_qwidget_setlayout(qObjectPtr, layout.qObjectPtr)
	End Method
	
	Method setToolTip(text:String)
		bmx_qt_qwidget_settooltip(qObjectPtr, text)
	End Method
	
	Method whatsThis:String()
	' TODO
	End Method
	
	Method width:Int()
		Return bmx_qt_qwidget_width(qObjectPtr)
	End Method
	
	Method winId:Int()
	' TODO
	End Method
	
	Method window:QWidget()
	' TODO
	End Method
	
	Method windowFilePath:String()
	' TODO
	End Method
	
	Method windowFlags:Int()
	' TODO
	End Method
	
	Method windowIcon:QIcon()
	' TODO
	End Method
	
	Method windowIconText:String()
	' TODO
	End Method
	
	Method windowModality:Int()
	' TODO
	End Method
	
	Method windowOpacity:Double()
	' TODO
	End Method
	
	Method windowRole:String()
	' TODO
	End Method
	
	Method windowState:Int()
	' TODO
	End Method
	
	'Method windowSurface:QWindowSurface()
	' TODO
	'End Method
	
	Method windowTitle:String()
	' TODO
	End Method
	
	Method windowType:Int()
	' TODO
	End Method
	
	Method x:Int()
	' TODO
	End Method
	
	Method y:Int()
	' TODO
	End Method
	

	' SLOTS
	
	Method close()
		bmx_qt_qwidget_close(qObjectPtr)
	End Method

	Method hide()
		bmx_qt_qwidget_hide(qObjectPtr)
	End Method

	Method raise()
		bmx_qt_qwidget_raise(qObjectPtr)
	End Method
	
	Method repaint()
		bmx_qt_qwidget_repaint(qObjectPtr)
	End Method
	
	Method setDisabled(disable:Int)
		bmx_qt_qwidget_setdisabled(qObjectPtr, disable)
	End Method
	
	Method setEnabled(value:Int)
		bmx_qt_qwidget_setenabled(qObjectPtr, value)
	End Method
	
	Method SetFocus(reason:Int = Qt_OtherFocusReason)
		bmx_qt_qwidget_setfocus(qObjectPtr, reason)
	End Method
	
	Method setHidden(hidden:Int)
		bmx_qt_qwidget_sethidden(qObjectPtr, hidden)
	End Method
	
	Method setStyleSheet(styleSheet:String)
		bmx_qt_qwidget_setstylesheet(qObjectPtr, styleSheet)
	End Method
	
	Method setVisible(visible:Int)
		bmx_qt_qwidget_setvisible(qObjectPtr, visible)
	End Method
	
	Method setWindowModified(value:Int)
		bmx_qt_qwidget_setwindowmodified(qObjectPtr, value)
	End Method
	

	Method setWindowTitle(title:String)
		bmx_qt_qwidget_setwindowtitle(qObjectPtr, title)
	End Method

	Method show()
		bmx_qt_qwidget_show(qObjectPtr)
	End Method
	
	Method showFullScreen()
		bmx_qt_qwidget_showfullscreen(qObjectPtr)
	End Method
	
	Method showMaximized()
		bmx_qt_qwidget_showmaximized(qObjectPtr)
	End Method
	
	Method showMinimized()
		bmx_qt_qwidget_showminimized(qObjectPtr)
	End Method
	
	Method showNormal()
		bmx_qt_qwidget_shownormal(qObjectPtr)
	End Method
	
	Method update()
		bmx_qt_qwidget_update(qObjectPtr)
	End Method



	Rem
	bbdoc: 
	End Rem
	Method paintEvent(event:QPaintEvent)
	End Method
	
	Function _OnPaintEvent(obj:QWidget, event:Byte Ptr, painter:Object)
		obj._painter = painter
		obj.paintEvent(QPaintEvent._create(event))
	End Function
	
	Rem
	bbdoc: 
	End Rem
	Method mouseDoubleClickEvent(event:QMouseEvent)
	End Method

	Function _OnMouseDoubleClickEvent(obj:QWidget, event:Byte Ptr)
		obj.mouseMoveEvent(QMouseEvent._create(event))
	End Function

	Rem
	bbdoc: 
	End Rem
	Method mouseMoveEvent(event:QMouseEvent)
	End Method

	Function _OnMouseMoveEvent(obj:QWidget, event:Byte Ptr)
		obj.mouseMoveEvent(QMouseEvent._create(event))
	End Function

	Rem
	bbdoc: 
	End Rem
	Method mousePressEvent(event:QMouseEvent)
	End Method

	Function _OnMousePressEvent(obj:QWidget, event:Byte Ptr)
		obj.mousePressEvent(QMouseEvent._create(event))
	End Function

	Rem
	bbdoc: 
	End Rem
	Method mouseReleseEvent(event:QMouseEvent)
	End Method

	Function _OnMouseReleseEvent(obj:QWidget, event:Byte Ptr)
		obj.mouseReleseEvent(QMouseEvent._create(event))
	End Function
	
	' SIGNAL : customContextMenuRequested
	Function _OnCustomContextMenuRequested(obj:QWidget, x:Int, y:Int)
		obj._InvokeSignals("customContextMenuRequested", [String(x), String(y)])
	End Function

	Field _painter:Object
	
	Method getPainter:Object()
		Return _painter
	End Method
	
End Type

Type QLayout Extends QObject

End Type

Type QLayoutItem

	Field qObjectPtr:Byte Ptr

	Method alignment:Int()
	End Method
	
	Method controlTypes:Int()
	End Method
	
	Method expandingDirections:Int()
	End Method
	
	Method geometry:QRect()
	End Method
	
	Method hasHeightForWidth:Int()
	End Method
	
	Method heightForWidth:Int(w:Int)
	End Method
	
	Method invalidate()
	End Method
	
	Method isEmpty:Int()
	End Method
	
	Method layout:QLayout()
	End Method
	
	Method maximumSize(w:Int Var, h:Int Var)
	End Method
	
	Method minimumHeightForWidth:Int(w:Int)
	End Method
	
	Method minimumSize(w:Int Var, h:Int Var)
	End Method
	
	Method setAlignment(alignment:Int)
	End Method
	
	Method setGeometry(r:QRect)
	End Method
	
	Method sizeHint(w:Int Var, h:Int Var)
	End Method
	
	Method spacerItem:QSpacerItem()
	End Method
	
	Method widget:QWidget()
	End Method
	
	
End Type

Type QSpacerItem Extends QLayoutItem

End Type

Type QWidgetItem Extends QLayoutItem

End Type


Type QAction Extends QObject

	Function _create:QAction(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QAction = New QAction
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QAction(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QAction = QAction(qfind(qObjectPtr))
			If Not widget Then
				Return QAction._create(qObjectPtr)
			End If
			Return widget
		End If
	End Function
	
	Function CreateAction:QAction(text:String, parent:QObject)
		Return New QAction.Create(text, parent)
	End Function
	
	Method Create:QAction(text:String, parent:QObject)
		qObjectPtr = bmx_qt_qaction_create(Self, text, parent.qObjectPtr)
		Return Self
	End Method
	
	Method setShortcut(sequence:String)
		bmx_qt_qaction_setshortcut(qObjectPtr, sequence)
	End Method
	
	' SIGNAL : changed
	Function _OnChanged(obj:QAction)
		obj._InvokeSignals("changed", Null)
	End Function

	' SIGNAL : hovered
	Function _OnHovered(obj:QAction)
		obj._InvokeSignals("hovered", Null)
	End Function

	' SIGNAL : toggled
	Function _OnToggled(obj:QAction, checked:Int)
		obj._InvokeSignals("toggled", [String(checked)])
	End Function

	' SIGNAL : triggered
	Function _OnTriggered(obj:QAction, checked:Int)
		obj._InvokeSignals("triggered", [String(checked)])
	End Function

End Type


