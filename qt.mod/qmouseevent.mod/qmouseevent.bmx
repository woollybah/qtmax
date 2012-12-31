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

Module Qt.QMouseEvent

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QMouseEvent Extends QInputEvent

	Function _create:QMouseEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QMouseEvent = New QMouseEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method button:Int()
		Return bmx_qt_qmouseevent_button(qObjectPtr)
	End Method
	
	Method buttons:Int()
		Return bmx_qt_qmouseevent_buttons(qObjectPtr)
	End Method
	
	Method globalPos(x:Int Var, y:Int Var)
		bmx_qt_qmouseevent_globalpos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method globalX:Int()
		Return bmx_qt_qmouseevent_globalx(qObjectPtr)
	End Method
	
	Method globalY:Int()
		Return bmx_qt_qmouseevent_globaly(qObjectPtr)
	End Method
	
	Method pos(x:Int Var, y:Int Var)
		bmx_qt_qmouseevent_pos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method posF(x:Double Var, y:Double Var)
		bmx_qt_qmouseevent_posf(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method x:Int()
		Return bmx_qt_qmouseevent_x(qObjectPtr)
	End Method
	
	Method y:Int()
		Return bmx_qt_qmouseevent_y(qObjectPtr)
	End Method

End Type
