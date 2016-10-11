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

Module Qt.QGraphicsSceneMouseEvent

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QGraphicsSceneMouseEvent Extends QGraphicsSceneEvent

	Function _create:QGraphicsSceneMouseEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QGraphicsSceneMouseEvent = New QGraphicsSceneMouseEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method button:Int()
		Return bmx_qt_qgraphicsscenemouseevent_button(qObjectPtr)
	End Method
	
	Method buttonDownPos(button:Int, x:Float Var, y:Float Var)
		bmx_qt_qgraphicsscenemouseevent_buttondownpos(qObjectPtr, button, Varptr x, Varptr y)
	End Method

	Method buttonDownScenePos(button:Int, x:Float Var, y:Float Var)
		bmx_qt_qgraphicsscenemouseevent_buttondownscenepos(qObjectPtr, button, Varptr x, Varptr y)
	End Method

	Method buttonDownScreenPos(button:Int, x:Int Var, y:Int Var)
		bmx_qt_qgraphicsscenemouseevent_buttondownscreenpos(qObjectPtr, button, Varptr x, Varptr y)
	End Method

	Method buttons:Int()
		Return bmx_qt_qgraphicsscenemouseevent_buttons(qObjectPtr)
	End Method
	
	Method lastPos(x:Float Var, y:Float Var)
		bmx_qt_qgraphicsscenemouseevent_lastpos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method lastScenePos(x:Float Var, y:Float Var)
		bmx_qt_qgraphicsscenemouseevent_lastscenepos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method lastScreenPos(x:Int Var, y:Int Var)
		bmx_qt_qgraphicsscenemouseevent_lastscreenpos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method modifiers:Int()
		Return bmx_qt_qgraphicsscenemouseevent_modifiers(qObjectPtr)
	End Method
	
	Method pos(x:Float Var, y:Float Var)
		bmx_qt_qgraphicsscenemouseevent_pos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method scenePos(x:Float Var, y:Float Var)
		bmx_qt_qgraphicsscenemouseevent_scenepos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method screenPos(x:Int Var, y:Int Var)
		bmx_qt_qgraphicsscenemouseevent_screenpos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
End Type

