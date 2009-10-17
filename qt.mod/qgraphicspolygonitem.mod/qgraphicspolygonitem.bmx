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

Module Qt.QGraphicsPolygonItem

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QGraphicsPolygonItem Extends QAbstractGraphicsShapeItem

	Function CreatePolygonItem:QGraphicsPolygonItem(parent:QGraphicsItem = Null)
		Return New QGraphicsPolygonItem.Create(parent)
	End Function

	Method Create:QGraphicsPolygonItem(parent:QGraphicsItem = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicspolygonitem_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicspolygonitem_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method CreateWithPolygon:QGraphicsPolygonItem(polygon:QPolygonF, parent:QGraphicsItem = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicspolygonitem_createwithpoly(Self, polygon.qObjectPtr, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicspolygonitem_createwithpoly(Self, polygon.qObjectPtr, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method fillRule:Int()
		Return bmx_qt_qgraphicspolygonitem_fillrule(qObjectPtr)
	End Method
	
	Method polygon:QPolygonF()
		Return QPolygonF._create(bmx_qt_qgraphicspolygonitem_polygon(qObjectPtr))
	End Method
	
	Method setFillRule(rule:Int)
		bmx_qt_qgraphicspolygonitem_setfillrule(qObjectPtr, rule)
	End Method
	
	Method setPolygon(polygon:QPolygonF)
		bmx_qt_qgraphicspolygonitem_setpolygon(qObjectPtr, polygon.qObjectPtr)
	End Method
	
End Type
