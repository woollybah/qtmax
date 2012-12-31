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
	' TODO
	End Method
	
	Method clear()
	' TODO
	End Method
	
	Method iconSize(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method insertSeparator:QAction(before:QAction)
	' TODO
	End Method
	
	Method insertWidget:QAction(before:QAction, widget:QWidget)
	' TODO
	End Method
	
	Method isAreaAllowed:Int(area:Int)
	' TODO
	End Method
	
	Method isFloatable:Int()
	' TODO
	End Method
	
	Method isFloating:Int()
	' TODO
	End Method
	
	Method isMovable:Int()
	' TODO
	End Method
	
	Method orientation:Int()
	' TODO
	End Method
	
	Method setAllowedAreas(areas:Int)
	' TODO
	End Method
	
	Method setFloatable(floatable:Int)
	' TODO
	End Method
	
	Method setMovable(movable:Int)
	' TODO
	End Method
	
	Method setOrientation(orientation:Int)
	' TODO
	End Method
	
	Method toggleViewAction:QAction()
	' TODO
	End Method
	
	Method toolButtonStyle:Int()
	' TODO
	End Method
	
	Method widgetForAction:QWidget(action:QAction)
	' TODO
	End Method
	
End Type

