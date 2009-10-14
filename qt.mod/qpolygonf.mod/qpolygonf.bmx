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

Module Qt.QPolygonF

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QPolygonF

	Field qObjectPtr:Byte Ptr
	
	Function _create:QPolygonF(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QPolygonF = New QPolygonF
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function createPolygon:QPolygonF()
		Return New QPolygonF.Create()
	End Function
	
	Method Create:QPolygonF()
		qObjectPtr = bmx_qt_qpolygonf_create()
		Return Self
	End Method
	
	Method append(x:Float, y:Float)
		bmx_qt_qpolygonf_append(qObjectPtr, x, y)
	End Method
	
	Method at(index:Int, x:Float Var, y:Float Var)
		bmx_qt_qpolygonf_at(qObjectPtr, index, Varptr x, Varptr y)
	End Method
	
	Method boundingRect:QRectF()
	' TODO
	End Method
	
	Method clear()
		bmx_qt_qpolygonf_clear(qObjectPtr)
	End Method
	
	Method containsPoint:Int(x:Float, y:Float, fillRule:Int)
		Return bmx_qt_qpolygonf_containspoint(qObjectPtr, x, y, fillRule)
	End Method
	
	Method intersected:QPolygonF(r:QPolygonF)
		Return QPolygonF._create(bmx_qt_qpolygonf_intersected(qObjectPtr, r.qObjectPtr))
	End Method
	
	Method isClosed:Int()
		Return bmx_qt_qpolygonf_isclosed(qObjectPtr)
	End Method
	
	Method isEmpty:Int()
		Return bmx_qt_qpolygonf_isempty(qObjectPtr)
	End Method

	Method prepend(x:Float, y:Float)
		bmx_qt_qpolygonf_prepend(qObjectPtr, x, y)
	End Method

	Method size:Int()
		Return bmx_qt_qpolygonf_size(qObjectPtr)
	End Method
	
	Method subtracted:QPolygonF(r:QPolygonF)
		Return QPolygonF._create(bmx_qt_qpolygonf_subtracted(qObjectPtr, r.qObjectPtr))
	End Method
	
	'Method toPolygon:QPolygon()
	'End Method

	Method translate(dx:Float, dy:Float)
		bmx_qt_qpolygonf_translate(qObjectPtr, dx, dy)
	End Method
	
	Method united:QPolygonF(r:QPolygonF)
		Return QPolygonF._create(bmx_qt_qpolygonf_united(qObjectPtr, r.qObjectPtr))
	End Method

	Method Delete()
		If qObjectPtr Then
			bmx_qt_qpolygonf_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
End Type


