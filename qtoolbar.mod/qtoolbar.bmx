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

Module Qt.QToolBar

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: A movable panel that contains a set of controls.
End Rem
Type QToolBar Extends QWidget

	Function CreateToolBar:QToolBar(parent:QWidget = Null)
		Return New QToolBar.Create(parent)
	End Function
	
	Method Create:QToolBar(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qtoolbar_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qtoolbar_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Function __create:QToolBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QToolBar = New QToolBar
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QToolBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QToolBar = QToolBar(qfind(qObjectPtr))
			If Not widget Then
				Return QToolBar.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function
	
	Method actionAt:QAction(x:Int, y:Int)
	' TODO
	End Method
	
	Method addActionText:QAction(text:String)
	' TODO
	End Method
	
	Method addActionIcon:QAction(icon:QIcon, text:String)
	' TODO
	End Method
	
	Method addWidget(widget:QWidget)
		bmx_qt_qtoolbar_addwidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method allowedAreas:Int()
		Return bmx_qt_qtoolbar_allowedareas(qObjectPtr)
	End Method
	
	Method clear()
		bmx_qt_qtoolbar_clear(qObjectPtr)
	End Method
	
	Method iconSize(w:Int Var, h:Int Var)
		bmx_qt_qtoolbar_iconsize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method insertSeparator:QAction(before:QAction)
	' TODO
	End Method
	
	Method insertWidget:QAction(before:QAction, widget:QWidget)
	' TODO
	End Method
	
	Method isAreaAllowed:Int(area:Int)
		Return bmx_qt_qtoolbar_isareaallowed(qObjectPtr, area)
	End Method
	
	Method isFloatable:Int()
		Return bmx_qt_qtoolbar_isfloatable(qObjectPtr)
	End Method
	
	Method isFloating:Int()
		Return bmx_qt_qtoolbar_isfloating(qObjectPtr)
	End Method
	
	Method isMovable:Int()
		Return bmx_qt_qtoolbar_ismovable(qObjectPtr)
	End Method
	
	Method orientation:Int()
		Return bmx_qt_qtoolbar_orientation(qObjectPtr)
	End Method
	
	Method setAllowedAreas(areas:Int)
		bmx_qt_qtoolbar_setallowedareas(qObjectPtr, areas)
	End Method
	
	Method setFloatable(floatable:Int)
		bmx_qt_qtoolbar_setfloatable(qObjectPtr, floatable)
	End Method
	
	Method setMovable(movable:Int)
		bmx_qt_qtoolbar_setmovable(qObjectPtr, movable)
	End Method
	
	Method setOrientation(orientation:Int)
		bmx_qt_qtoolbar_setorientation(qObjectPtr, orientation)
	End Method
	
	Method toggleViewAction:QAction()
	' TODO
	End Method
	
	Method toolButtonStyle:Int()
		Return bmx_qt_qtoolbar_toolbuttonstyle(qObjectPtr)
	End Method
	
	Method widgetForAction:QWidget(action:QAction)
	' TODO
	End Method



	' SIGNAL : actionTriggered
	Function _OnActionTriggered(obj:QToolBar, action:Byte Ptr)
		obj._InvokeSignals("actionTriggered", [QAction._find(action)])
	End Function

	' SIGNAL : allowedAreasChanged
	Function _OnAllowedAreasChanged(obj:QToolBar, allowedAreas:Int)
		obj._InvokeSignals("allowedAreasChanged", [String(allowedAreas)])
	End Function

	' SIGNAL : iconSizeChanged
	Function _OnIconSizeChanged(obj:QToolBar, width:Int, height:Int)
		obj._InvokeSignals("iconSizeChanged", [String(width), String(height)])
	End Function

	' SIGNAL : movableChanged
	Function _OnMovableChanged(obj:QToolBar, movable:Int)
		obj._InvokeSignals("movableChanged", [String(movable)])
	End Function

	' SIGNAL : orientationChanged
	Function _OnOrientationChanged(obj:QToolBar, orientation:Int)
		obj._InvokeSignals("orientationChanged", [String(orientation)])
	End Function

	' SIGNAL : toolButtonStyleChanged
	Function _OnToolButtonStyleChanged(obj:QToolBar, toolButtonStyle:Int)
		obj._InvokeSignals("toolButtonStyleChanged", [String(toolButtonStyle)])
	End Function

	' SIGNAL : topLevelChanged
	Function _OnTopLevelChanged(obj:QToolBar, topLevel:Int)
		obj._InvokeSignals("topLevelChanged", [String(topLevel)])
	End Function

	' SIGNAL : visibilityChanged
	Function _OnVisibilityChanged(obj:QToolBar, visible:Int)
		obj._InvokeSignals("visibilityChanged", [String(visible)])
	End Function

End Type

