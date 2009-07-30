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

Module Qt.QRadioButton

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QRadioButton Extends QAbstractButton

	Function CreateRadioButton:QRadioButton(text:String, parent:QWidget = Null)
		Return New QRadioButton.Create(text, parent)
	End Function
	
	Method Create:QRadioButton(text:String, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qradiobutton_create(Self, text, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qradiobutton_create(Self, text, Null)
		End If
		OnInit()
		Return Self
	End Method

	' SIGNAL : clicked
	Function _OnClicked(obj:QRadioButton, checked:Int)
		obj._InvokeSignals("clicked", [String(checked)])
	End Function

	' SIGNAL : pressed
	Function _OnPressed(obj:QRadioButton, checked:Int)
		obj._InvokeSignals("pressed", Null)
	End Function

	' SIGNAL : released
	Function _OnReleased(obj:QRadioButton)
		obj._InvokeSignals("released", Null)
	End Function

	' SIGNAL : toggled
	Function _OnToggled(obj:QRadioButton, checked:Int)
		obj._InvokeSignals("toggled", [String(checked)])
	End Function

End Type

