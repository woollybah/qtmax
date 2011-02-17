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

Import "common.bmx"

Type QLineF

	Field qObjectPtr:Byte Ptr
	
	Function _Create:QLineF(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QLineF = New QLineF
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreateLine:QLineF(x1:Double, y1:Double, x2:Double, y2:Double)
		Return New QLineF.Create(x1, y1, x2, y2)
	End Function
	
	Method Create:QLineF(x1:Double, y1:Double, x2:Double, y2:Double)
		qObjectPtr = bmx_qt_qlinef_create(x1, y1, x2, y2)
		Return Self
	End Method

	Method p1(x:Double Var, y:Double Var)
		bmx_qt_qlinef_p1(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method p2(x:Double Var, y:Double Var)
		bmx_qt_qlinef_p2(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method x1:Double()
		Return bmx_qt_qlinef_x1(qObjectPtr)
	End Method
	
	Method y1:Double()
		Return bmx_qt_qlinef_y1(qObjectPtr)
	End Method
	
	Method x2:Double()
		Return bmx_qt_qlinef_x2(qObjectPtr)
	End Method
	
	Method y2:Double()
		Return bmx_qt_qlinef_y2(qObjectPtr)
	End Method
	
	Method angle:Double()
		Return bmx_qt_qlinef_angle(qObjectPtr)
	End Method
	
	Method angleTo:Double(line:QLineF)
		Return bmx_qt_qlinef_angleTo(qObjectPtr, line.qObjectPtr)
	End Method
	
	Method dx:Double()
		Return bmx_qt_qlinef_dx(qObjectPtr)
	End Method
	
	Method dy:Double()
		Return bmx_qt_qlinef_dy(qObjectPtr)
	End Method
	
	Method intersect:Int(line:QLineF, x:Double Var, y:Double Var)
		Return bmx_qt_qlinef_intersect(qObjectPtr, line.qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method isNull:Int()
		Return bmx_qt_qlinef_isnull(qObjectPtr)
	End Method
	
	Method length:Double()
		Return bmx_qt_qlinef_length(qObjectPtr)
	End Method
	
	Method normalVector:QLineF()
		Return QLineF._create(bmx_qt_qlinef_normalvector(qObjectPtr))
	End Method
	
	Method pointAt(t:Double, x:Double Var, y:Double Var)
		bmx_qt_qlinef_pointat(qObjectPtr, t, Varptr x, Varptr y)
	End Method
	
	Method setP1(x:Double, y:Double)
		bmx_qt_qlinef_setp1(qObjectPtr, x, y)
	End Method
	
	Method setP2(x:Double, y:Double)
		bmx_qt_qlinef_setp2(qObjectPtr, x, y)
	End Method
	
	Method setAngle(angle:Double)
		bmx_qt_qlinef_setangle(qObjectPtr, angle)
	End Method
	
	Method setLength(length:Double)
		bmx_qt_qlinef_setlength(qObjectPtr, length)
	End Method
	
	Method setLine(x1:Double, y1:Double, x2:Double, y2:Double)
		bmx_qt_qlinef_setline(qObjectPtr, x1, y1, x2, y2)
	End Method
	
	'Method toLine:QLine()
	' TODO
	'End Method
	
	Method translate(dx:Double, dy:Double)
		bmx_qt_qlinef_translate(qObjectPtr, dx, dy)
	End Method
	
	Method translated:QLineF(dx:Double, dy:Double)
		Return QLineF._create(bmx_qt_qlinef_translated(qObjectPtr, dx, dy))
	End Method
	
	Method unitVector:QLineF()
		Return QLineF._create(bmx_qt_qlinef_unitvector(qObjectPtr))
	End Method
	
End Type


