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

Module Qt.QDial

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QDial Extends QAbstractSlider

	Function CreateDial:QDial(parent:QWidget = Null)
		Return New QDial.Create(parent)
	End Function
	
	Method Create:QDial(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qdial_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qdial_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method notchSize:Int()
		Return bmx_qt_qdial_notchsize(qObjectPtr)
	End Method
	
	Method notchTarget:Double()
		Return bmx_qt_qdial_notchtarget(qObjectPtr)
	End Method
	
	Method notchesVisible:Int()
		Return bmx_qt_qdial_notchesvisible(qObjectPtr)
	End Method
	
	Method setNotchTarget(target:Double)
		bmx_qt_qdial_setnotchtarget(qObjectPtr, target)
	End Method
	
	Method wrapping:Int()	
		Return bmx_qt_qdial_wrapping(qObjectPtr)
	End Method

	Method setNotchesVisible(visible:Int)
		bmx_qt_qdial_setnotchesvisible(qObjectPtr, visible)
	End Method

	Method setWrapping(on:Int)
		bmx_qt_qdial_setwrapping(qObjectPtr, on)
	End Method

End Type

