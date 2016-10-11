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

Module Qt.QGroupBox

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: Provides a group box frame with a title.
End Rem
Type QGroupBox Extends QWidget

	Function CreateGroupBox:QGroupBox(title:String, parent:QWidget = Null)
		Return New QGroupBox.Create(title, parent)
	End Function
	
	Method Create:QGroupBox(title:String, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgroupbox_create(Self, title, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgroupbox_create(Self, title, Null)
		End If
		
		OnInit()
		Return Self
	End Method

	Method alignment:Int()
		Return bmx_qt_qgroupbox_alignment(qObjectPtr)
	End Method
	
	Method isCheckable:Int()
		Return bmx_qt_qgroupbox_ischeckable(qObjectPtr)
	End Method
	
	Method isChecked:Int()
		Return bmx_qt_qgroupbox_ischecked(qObjectPtr)
	End Method
	
	Method isFlat:Int()
		Return bmx_qt_qgroupbox_isflat(qObjectPtr)
	End Method
	
	Method setAlignment(alignment:Int)
		bmx_qt_qgroupbox_setalignment(qObjectPtr, alignment)
	End Method
	
	Method setCheckable(checkable:Int)
		bmx_qt_qgroupbox_setcheckable(qObjectPtr, checkable)
	End Method
	
	Method setFlat(flat:Int)
		bmx_qt_qgroupbox_setflat(qObjectPtr, flat)
	End Method
	
	Method setTitle(title:String)
		bmx_qt_qgroupbox_settitle(qObjectPtr, title)
	End Method
	
	Method title:String()
		Return bmx_qt_qgroupbox_title(qObjectPtr)
	End Method
	
	Method setChecked(checked:Int)
		bmx_qt_qgroupbox_setchecked(qObjectPtr, checked)
	End Method

	' SIGNAL : clicked
	Function _OnClicked(obj:QGroupBox, checked:Int)
		obj._InvokeSignals("clicked", [String(checked)])
	End Function

	' SIGNAL : toggled
	Function _OnToggled(obj:QGroupBox, checked:Int)
		obj._InvokeSignals("toggled", [String(checked)])
	End Function

End Type

