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

Module Qt.QDoubleSpinBox

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QDoubleSpinBox Extends QAbstractSpinBox

	Function CreateDoubleSpinBox:QDoubleSpinBox(parent:QWidget = Null)
		Return New QDoubleSpinBox.Create(parent)
	End Function
	
	Method Create:QDoubleSpinBox(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qdoublespinbox_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qdoublespinbox_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method cleanText:String()
		Return bmx_qt_qdoublespinbox_cleantext(qObjectPtr)
	End Method
	
	Method decimals:Int()
	End Method
	
	Method maximum:Double()
		Return bmx_qt_qdoublespinbox_maximum(qObjectPtr)
	End Method
	
	Method minimum:Double()
		Return bmx_qt_qdoublespinbox_minimum(qObjectPtr)
	End Method
	
	Method prefix:String()
		Return bmx_qt_qdoublespinbox_prefix(qObjectPtr)
	End Method
	
	Method setDecimals(prec:Int)
		bmx_qt_qdoublespinbox_setdecimals(qObjectPtr, prec)
	End Method
	
	Method setMaximum(value:Double)
		bmx_qt_qdoublespinbox_setmaximum(qObjectPtr, value)
	End Method
	
	Method setMinimum(value:Double)
		bmx_qt_qdoublespinbox_setminimum(qObjectPtr, value)
	End Method
	
	Method setPrefix(prefix:String)
		bmx_qt_qdoublespinbox_setprefix(qObjectPtr, prefix)
	End Method
	
	Method setRange(minimum:Double, maximum:Double)
		bmx_qt_qdoublespinbox_setrange(qObjectPtr, minimum, maximum)
	End Method
	
	Method setSingleStep(val:Double)
		bmx_qt_qdoublespinbox_setsinglestep(qObjectPtr, val)
	End Method
	
	Method setSuffix(suffix:String)
		bmx_qt_qdoublespinbox_setsuffix(qObjectPtr, suffix)
	End Method
	
	Method singleStep:Double()
		Return bmx_qt_qdoublespinbox_singlestep(qObjectPtr)
	End Method
	
	Method suffix:String()
		Return bmx_qt_qdoublespinbox_suffix(qObjectPtr)
	End Method
	
	Method value:Double()
		Return bmx_qt_qdoublespinbox_value(qObjectPtr)
	End Method
	
	' SLOT
	Method setValue(value:Double)
		bmx_qt_qdoublespinbox_setvalue(qObjectPtr, value)
	End Method


	' SIGNAL : valueChanged
	Function _OnValueChanged(obj:QDoubleSpinBox, value:Double)
		obj._InvokeSignals("valueChanged", [String(value)])
	End Function

	
End Type

