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

Module Qt.QScrollBar

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QScrollBar Extends QAbstractSlider

	Function CreateScrollBar:QScrollBar(orientation:Int, parent:QWidget = Null)
		Return New QScrollBar.Create(orientation, parent)
	End Function
	
	Method Create:QScrollBar(orientation:Int, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qscrollbar_create(Self, orientation, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qscrollbar_create(Self, orientation, Null)
		End If
		OnInit()
		Return Self
	End Method

	Function __create:QScrollBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QScrollBar = New QScrollBar
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QScrollBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QScrollBar = QScrollBar(qfind(qObjectPtr))
			If Not widget Then
				Return QScrollBar.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

End Type

