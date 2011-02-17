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

Module Qt.QButtonGroup

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QButtonGroup Extends QObject

	Function CreateButtonGroup:QButtonGroup(parent:QObject = Null)
		Return New QButtonGroup.Create(parent)
	End Function
	
	Method Create:QButtonGroup(parent:QObject = Null)
		If parent Then
			qObjectPtr = bmx_qt_qbuttongroup_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qbuttongroup_create(Self, Null)
		End If
		Return Self
	End Method
	
	Method addButton(button:QAbstractButton, id:Int = -1)
		bmx_qt_qbuttongroup_addbutton(qObjectPtr, button.qObjectPtr, id)
	End Method
	
	Method button:QAbstractButton(id:Int)
		Return QAbstractButton._find(bmx_qt_qbuttongroup_button(qObjectPtr, id))
	End Method
	
	Method buttons:QAbstractButton[]()
		'bmx_qt_qbuttongroup_buttons(qObjectPtr)
	End Method
	
	Method checkedButton:QAbstractButton()
		Return QAbstractButton._find(bmx_qt_qbuttongroup_checkedbutton(qObjectPtr))
	End Method
	
	Method checkedId:Int()
		Return bmx_qt_qbuttongroup_checkedid(qObjectPtr)
	End Method
	
	Method exclusive:Int()
		Return bmx_qt_qbuttongroup_exclusive(qObjectPtr)
	End Method
	
	Method id:Int(button:QAbstractButton)
		Return bmx_qt_qbuttongroup_id(qObjectPtr, button.qObjectPtr)
	End Method
	
	Method removeButton(button:QAbstractButton)
		bmx_qt_qbuttongroup_removebutton(qObjectPtr, button.qObjectPtr)
	End Method
	
	Method setExclusive(value:Int)
		bmx_qt_qbuttongroup_setexclusive(qObjectPtr, value)
	End Method
	
	Method setId(button:QAbstractButton, id:Int)
		bmx_qt_qbuttongroup_setid(qObjectPtr, button.qObjectPtr, id)
	End Method
	
	' SIGNAL : buttonClicked
	Function _OnButtonClicked(obj:QButtonGroup, button:Byte Ptr)
		obj._InvokeSignals("buttonClicked", [QAbstractButton._find(button)])
	End Function

	' SIGNAL : buttonPressed
	Function _OnButtonPressed(obj:QButtonGroup, button:Byte Ptr)
		obj._InvokeSignals("buttonPressed", [QAbstractButton._find(button)])
	End Function

	' SIGNAL : buttonReleased
	Function _OnButtonReleased(obj:QButtonGroup, button:Byte Ptr)
		obj._InvokeSignals("buttonReleased", [QAbstractButton._find(button)])
	End Function

End Type

