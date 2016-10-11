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

Module Qt.QDockWidget

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QDockWidget Extends QWidget

	Rem
	bbdoc: The dock widget can be closed. On some systems the dock widget always has a close button when it's floating (for example on MacOS 10.5).
	end rem
	Const DockWidgetClosable:Int = $01
	Rem
	bbdoc: The dock widget can be moved between docks by the user.
	end rem
	Const DockWidgetMovable:Int = $02
	Rem
	bbdoc: The dock widget can be detached from the main window, and floated as an independent window.
	end rem
	Const DockWidgetFloatable:Int = $04
	Rem
	bbdoc: The dock widget displays a vertical title bar on its left side. This can be used to increase the amount of vertical space in a QMainWindow.
	end rem
	Const DockWidgetVerticalTitleBar:Int = $08
	Rem
	bbdoc: The dock widget cannot be closed, moved, or floated.
	end rem
	Const NoDockWidgetFeatures:Int = $00

	Function CreateDockWidget:QDockWidget(title:String, parent:QWidget = Null, flags:Int = 0)
		Return New QDockWidget.Create(title, parent, flags)
	End Function

	Method Create:QDockWidget(title:String, parent:QWidget = Null, flags:Int = 0)
		If parent Then
			'qObjectPtr = bmx_qt_qdockwidget_create(Self, title, parent.qObjectPtr, flags)
		Else
			'qObjectPtr = bmx_qt_qdockwidget_create(Self, title, Null, flags)
		End If
		OnInit()
		Return Self
	End Method
	
	Method allowedAreas:Int()
	' TODO
	End Method
	
	Method features:Int()
	' TODO
	End Method
	
	Method isAreaAllowed:Int(area:Int)
	' TODO
	End Method
	
	Method isFloating:Int()
	' TODO
	End Method
	
	Method setAllowedAreas(areas:Int)
	' TODO
	End Method
	
	Method setFeatures(features:Int)
	' TODO
	End Method
	
	Method setFloating(floating:Int)
	' TODO
	End Method
	
	Method setTitleBarWidget(widget:QWidget)
	' TODO
	End Method
	
	Method setWidget(widget:QWidget)
	' TODO
	End Method
	
	Method titleBarWidget:QWidget()
	' TODO
	End Method
	
	Method toggleViewAction:QAction()
	' TODO
	End Method
	
	Method widget:QWidget()
	' TODO
	End Method

End Type

