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

Module Qt.QGraphicsSceneWheelEvent

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QGraphicsSceneWheelEvent Extends QGraphicsSceneEvent

	Function _create:QGraphicsSceneWheelEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QGraphicsSceneWheelEvent = New QGraphicsSceneWheelEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method buttons:Int()
		Return bmx_qt_qgraphicsscenewheelevent_buttons(qObjectPtr)
	End Method
	
	Method delta:Int()
		Return bmx_qt_qgraphicsscenewheelevent_delta(qObjectPtr)
	End Method
	
	Method modifiers:Int()
		Return bmx_qt_qgraphicsscenewheelevent_modifiers(qObjectPtr)
	End Method
	
	Method orientation:Int()
		Return bmx_qt_qgraphicsscenewheelevent_orientation(qObjectPtr)
	End Method
	
	Method pos(x:Float Var, y:Float Var)
		bmx_qt_qgraphicsscenewheelevent_pos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method scenePos(x:Float Var, y:Float Var)
		bmx_qt_qgraphicsscenewheelevent_scenepos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method screenPos(x:Int Var, y:Int Var)
		bmx_qt_qgraphicsscenewheelevent_screenpos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
End Type

