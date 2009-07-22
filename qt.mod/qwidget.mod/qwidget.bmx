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

	Method OnInit()
	End Method
	
	Method hide()
		bmx_qt_qwidget_hide(qObjectPtr)
	End Method
	
	Method show()
		bmx_qt_qwidget_show(qObjectPtr)
	End Method
	
	Method showFullScreen()
	End Method
	
	Method showMaximized()
	End Method
	
	Method showMinimized()
	End Method
	
	Method showNormal()
	End Method
	
	Method stackUnder(w:QWidget)
	End Method
	
	Method setLayout(layout:QLayout)
		bmx_qt_qwidget_setlayout(qObjectPtr, layout.qObjectPtr)
	End Method
	
	Method setWindowTitle(title:String)
		bmx_qt_qwidget_setwindowtitle(qObjectPtr, title)
	End Method
	
End Type

Type QLayout Extends QObject

End Type

