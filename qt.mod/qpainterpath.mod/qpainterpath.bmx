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

Module Qt.QPainterPath

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QPainterPath

	Field qObjectPtr:Byte Ptr
	
	Function _create:QPainterPath(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QPainterPath = New QPainterPath
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreatePainterPath:QPainterPath()
		Return New QPainterPath.Create()
	End Function
	
	Method Create:QPainterPath()
		qObjectPtr = bmx_qt_qpainterpath_create()
		Return Self
	End Method

	Method addEllipse(x:Double, y:Double, width:Double, height:Double)
		bmx_qt_qpainterpath_addellipse(qObjectPtr, x, y, width, height)
	End Method
	
	Method addEllipseCenter(cx:Double, cy:Double, rx:Double, ry:Double)
		bmx_qt_qpainterpath_addellipsecenter(qObjectPtr, cx, cy, rx, ry)
	End Method
	
	Method addPath(path:QPainterPath)
		bmx_qt_qpainterpath_addpath(qObjectPtr, path.qObjectPtr)
	End Method
	
	'Method addPolygon(polygon:QPolygonF)
	'	bmx_qt_qpainterpath_addpolygon(qObjectPtr, polygon.qObjectPtr)
	'End Method
	
	Method addRect(x:Double, y:Double, width:Double, height:Double)
		bmx_qt_qpainterpath_addrect(qObjectPtr, x, y, width, height)
	End Method
	
	Method addRegion(region:QRegion)
		bmx_qt_qpainterpath_addregion(qObjectPtr, region.qObjectPtr)
	End Method
	
	Method addRoundedRect(x:Double, y:Double, w:Double, h:Double, xRadius:Double, yRadius:Double, _mode:Int = Qt_AbsoluteSize)
		bmx_qt_qpainterpath_addroundedrect(qObjectPtr, x, y, w, h, xRadius, yRadius, _mode)
	End Method
	
	Method addText(x:Double, y:Double, font:QFont, text:String)
		bmx_qt_qpainterpath_addtext(qObjectPtr, x, y, font.qObjectPtr, text)
	End Method
	
	Method angleAtPercent:Double(t:Double)
		Return bmx_qt_qpainterpath_angleatpercent(qObjectPtr, t)
	End Method
	
	Method arcMoveTo(x:Double, y:Double, width:Double, height:Double, angle:Double)
		bmx_qt_qpainterpath_arcmoveto(qObjectPtr, x, y, width, height, angle)
	End Method
	
	Method arcTo(x:Double, y:Double, width:Double, height:Double, startAngle:Double, sweepLength:Double)
		bmx_qt_qpainterpath_arcto(qObjectPtr, x, y, width, height, startAngle, sweepLength)
	End Method
	
	Method boundingRect:QRectF()
		Return QRectF._create(bmx_qt_qpainterpath_boundingrect(qObjectPtr))
	End Method
	
	Method closeSubpath()
		bmx_qt_qpainterpath_closesubpath(qObjectPtr)
	End Method
	
	Method connectPath(path:QPainterPath)
		bmx_qt_qpainterpath_connectpath(qObjectPtr, path.qObjectPtr)
	End Method
	
	Method contains:Int(x:Double, y:Double)
		Return bmx_qt_qpainterpath_contains(qObjectPtr, x, y)
	End Method
	
	Method containsRect:Int(rectangle:QRectF)
		Return bmx_qt_qpainterpath_containsrect(qObjectPtr, rectangle.qObjectPtr)
	End Method
	
	Method containsPath:Int(p:QPainterPath)
		Return bmx_qt_qpainterpath_containspath(qObjectPtr, p.qObjectPtr)
	End Method
	
	Method controlPointRect:QRectF()
		Return QRectF._create(bmx_qt_qpainterpath_controlpointrect(qObjectPtr))
	End Method
	
	Method cubicTo(c1X:Double, c1Y:Double, c2X:Double, c2Y:Double, endPointX:Double, endPointY:Double)
		bmx_qt_qpainterpath_cubicto(qObjectPtr, c1X, c1Y, c2X, c2Y, endPointX, endPointY)
	End Method
	
	Method currentPosition(x:Double Var, y:Double Var)
		bmx_qt_qpainterpath_currentposition(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method elementAt:Element(index:Int)
		Return Element._create(bmx_qt_qpainterpath_elementat(qObjectPtr, index))
	End Method
	
	Method elementCount:Int()
		Return bmx_qt_qpainterpath_elementcount(qObjectPtr)
	End Method
	
	Method fillRule:Int()
		Return bmx_qt_qpainterpath_fillrule(qObjectPtr)
	End Method
	
	Method intersected:QPainterPath(p:QPainterPath)
		Return QPainterPath._create(bmx_qt_qpainterpath_intersected(qObjectPtr, p.qObjectPtr))
	End Method
	
	Method intersects:Int(p:QPainterPath)
		Return bmx_qt_qpainterpath_intersects(qObjectPtr, p.qObjectPtr)
	End Method
	
	Method isEmpty:Int()
		Return bmx_qt_qpainterpath_isempty(qObjectPtr)
	End Method
	
	Method length:Double()
		Return bmx_qt_qpainterpath_length(qObjectPtr)
	End Method
	
	Method lineTo(x:Double, y:Double)
		bmx_qt_qpainterpath_lineto(qObjectPtr, x, y)
	End Method
	
	Method moveTo(x:Double, y:Double)
		bmx_qt_qpainterpath_moveto(qObjectPtr, x, y)
	End Method
	
	Method percentAtLength:Double(length:Double)
		Return bmx_qt_qpainterpath_percentatlength(qObjectPtr, length)
	End Method
	
	Method pointAtPercent(t:Double, x:Double Var, y:Double Var)
		bmx_qt_qpainterpath_pointatpercent(qObjectPtr, t, Varptr x, Varptr y)
	End Method
	
	Method quadTo(cx:Double, cy:Double, endPointX:Double, endPointY:Double)
		bmx_qt_qpainterpath_quadto(qObjectPtr, cx, cy, endPointX, endPointY)
	End Method
	
	Method setElementPositionAt(index:Int, x:Double, y:Double)
		bmx_qt_qpainterpath_setelementpositionat(qObjectPtr, index, x, y)
	End Method
	
	Method setFillRule(fillRule:Int)
		bmx_qt_qpainterpath_setfillrule(qObjectPtr, fillRule)
	End Method
	
	Method simplified:QPainterPath()
		Return QPainterPath._create(bmx_qt_qpainterpath_simplified(qObjectPtr))
	End Method
	
	Method slopeAtPercent:Double(t:Double)
		Return bmx_qt_qpainterpath_slopeatpercent(qObjectPtr, t)
	End Method
	
	Method subtracted:QPainterPath(p:QPainterPath)
		Return QPainterPath._create(bmx_qt_qpainterpath_subtracted(qObjectPtr, p.qObjectPtr))
	End Method
	
	'Method toFillPolygon:QPolygonF(matrix:QTransform)
	'	Return QPolygonF._create(bmx_qt_qpainterpath_tofillpolygon(qObjectPtr, matrix.qObjectPtr))
	'End Method
	
	'Method toFillPolygonMatrix:QPolygonF(matrix:QMatrix = Null)
	'	If matrix Then
	'		Return QPolygonF._create(bmx_qt_qpainterpath_tofillpolygonmatrix(qObjectPtr, matrix.qObjectPtr))
	'	Else
	'		Return QPolygonF._create(bmx_qt_qpainterpath_tofillpolygonmatrix(qObjectPtr, Null))
	'	End If
	'End Method
	
	'QList<QPolygonF> toFillPolygons(matrix:QTransform)
	'	bmx_qt_qpainterpath_(qObjectPtr)
	'End Method
	
	'QList<QPolygonF> toFillPolygonsMatrix(matrix:QMatrix = Null)
	'	bmx_qt_qpainterpath_(qObjectPtr)
	'End Method
	
	Method toReversed:QPainterPath()
		Return QPainterPath._create(bmx_qt_qpainterpath_toreversed(qObjectPtr))
	End Method

	Method Free()
		If qObjectPtr Then
			bmx_qt_qpainterpath_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type

Type Element
	Field qObjectPtr:Byte Ptr

	Function _create:Element(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:Element = New Element
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
End Type

Type QMatrix

	Field qObjectPtr:Byte Ptr

	Function _create:QMatrix(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QMatrix = New QMatrix
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

