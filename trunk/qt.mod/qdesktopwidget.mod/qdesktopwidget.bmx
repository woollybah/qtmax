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

Module Qt.QDesktopWidget

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: Provides access to screen information on multi-head systems.
End Rem
Type QDesktopWidget Extends QWidget

	Function __create:QDesktopWidget(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QDesktopWidget = New QDesktopWidget
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QDesktopWidget(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QDesktopWidget = QDesktopWidget(qfind(qObjectPtr))
			If Not widget Then
				Return QDesktopWidget.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Rem
	bbdoc: Returns the available geometry of the screen with index @screen.
	about: What is available will be subrect of screenGeometry() based on what the platform decides is available
	(for example excludes the dock and menu bar on Mac OS X, or the task bar on Windows). The default screen is used
	if @screen is -1.
	End Rem
	Method availableGeometry:QRect(screen:Int = -1)
		Return QRect._create(bmx_qt_qdesktopwidget_availablegeometry(qObjectPtr, screen))
	End Method
	
	Rem
	bbdoc: Returns the available geometry of the screen which contains @widget.
	End Rem
	Method availableGeometryWidget:QRect(widget:QWidget)
		Return QRect._create(bmx_qt_qdesktopwidget_availablegeometrywidget(qObjectPtr, widget.qObjectPtr))
	End Method
	
	Rem
	bbdoc: Returns the available geometry of the screen which contains the point @x, @y..
	End Rem
	Method availableGeometryXY:QRect(x:Int, y:Int)
		Return QRect._create(bmx_qt_qdesktopwidget_availablegeometryxy(qObjectPtr, x, y))
	End Method
	
	Rem
	bbdoc: Returns true if the system manages the available screens in a virtual desktop; otherwise returns false.
	about: For virtual desktops, screen() will always return the same widget. The size of the virtual desktop is
	the size of this desktop widget.
	End Rem
	Method isVirtualDesktop:Int()
		Return bmx_qt_qdesktopwidget_isvirtualdesktop(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns the number of available screens.
	End Rem
	Method numScreens:Int()
		Return bmx_qt_qdesktopwidget_numscreens(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns the index of the primary screen.
	End Rem
	Method primaryScreen:Int()
		Return bmx_qt_qdesktopwidget_primaryscreen(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns a widget that represents the screen with index @screen (a value of -1 means the default screen).
	about: If the system uses a virtual desktop, the returned widget will have the geometry of the entire
	virtual desktop; i.e., bounding every screen.
	End Rem
	Method screen:QWidget(screen:Int = -1)
		Return QWidget._find(bmx_qt_qdesktopwidget_screen(qObjectPtr, screen))
	End Method
	
	Rem
	bbdoc: Returns the geometry of the screen with index screen.
	about: The default screen is used if screen is -1.
	End Rem
	Method screenGeometry:QRect(screen:Int = -1)
		Return QRect._create(bmx_qt_qdesktopwidget_screengeometry(qObjectPtr, screen))
	End Method
	
	Rem
	bbdoc: Returns the geometry of the screen which contains widget.
	End Rem
	Method screenGeometryWidget:QRect(widget:QWidget)
		Return QRect._create(bmx_qt_qdesktopwidget_screengeometrywidget(qObjectPtr, widget.qObjectPtr))
	End Method
	
	Rem
	bbdoc: Returns the geometry of the screen which contains point @x, @y..
	End Rem
	Method screenGeometryXY:QRect(x:Int, y:Int)
		Return QRect._create(bmx_qt_qdesktopwidget_screengeometryxy(qObjectPtr, x, y))
	End Method
	
	Rem
	bbdoc: Returns the index of the screen that contains the largest part of @widget, or -1 if the widget not on a screen.
	End Rem
	Method screenNumber:Int(widget:QWidget = Null)
		If widget Then
			Return bmx_qt_qdesktopwidget_screennumber(qObjectPtr, widget.qObjectPtr)
		Else
			Return bmx_qt_qdesktopwidget_screennumber(qObjectPtr, Null)
		End If
	End Method
	
	Rem
	bbdoc: Returns the index of the screen that contains the point, or the screen which is the shortest distance from the point @x, @y.
	End Rem
	Method screenNumberXY:Int(x:Int, y:Int)
		Return bmx_qt_qdesktopwidget_screennumberxy(qObjectPtr, x, y)
	End Method

	' SIGNAL : resized
	Function _OnResized(obj:QDesktopWidget, screen:Int)
		obj._InvokeSignals("resized", [String(screen)])
	End Function

	' SIGNAL : workAreaResized
	Function _OnWorkAreaResized(obj:QDesktopWidget, screen:Int)
		obj._InvokeSignals("workAreaResized", [String(screen)])
	End Function

End Type

