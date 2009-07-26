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

Module Qt.QComboBox

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QComboBox Extends QWidget

	Function CreateComboBox:QComboBox(parent:QWidget = Null)
		Return New QComboBox.Create(parent)
	End Function
	
	Method Create:QComboBox(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qcombobox_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qcombobox_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method addItem(text:String, userData:Object = Null)
		bmx_qt_qcombobox_addItem(qObjectPtr, text, userData)
	End Method
	
	Method addItems(texts:String[])
		bmx_qt_qcombobox_addItems(qObjectPtr, texts)
	End Method
	
	' SIGNAL : activated
	Function _OnActivated(obj:QComboBox, index:Int)
		obj._InvokeSignals("activated", [String(index)])
	End Function

	' SIGNAL : currentIndexChanged
	Function _OnCurrentIndexChanged(obj:QComboBox, index:Int)
		obj._InvokeSignals("currentIndexChanged", [String(index)])
	End Function

	' SIGNAL : editTextChanged
	Function _OnEditTextChanged(obj:QComboBox, text:String)
		obj._InvokeSignals("editTextChanged", [text])
	End Function

	' SIGNAL : highlighted
	Function _OnHighlighted(obj:QComboBox, index:Int)
		obj._InvokeSignals("highlighted", [String(index)])
	End Function

End Type

