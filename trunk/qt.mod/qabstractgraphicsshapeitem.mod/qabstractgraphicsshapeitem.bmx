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

Module Qt.QAbstractGraphicsShapeItem

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QAbstractGraphicsShapeItem Extends QGraphicsItem

	Method brush:QBrush()
		Return QBrush._create(bmx_qt_qabstractgraphicsshapeitem_brush(qObjectPtr))
	End Method
	
	Method pen:QPen()
		Return QPen._create(bmx_qt_qabstractgraphicsshapeitem_pen(qObjectPtr))
	End Method

	Method setBrushStyle(style:Int)
		bmx_qt_qabstractgraphicsshapeitem_setbrushstyle(qObjectPtr, style)
	End Method
	
	Method setBrush(brush:Object)
		If QBrush(brush) Then
			bmx_qt_qabstractgraphicsshapeitem_setbrush(qObjectPtr, QBrush(brush).qObjectPtr)
		ElseIf QColor(brush) Then
			bmx_qt_qabstractgraphicsshapeitem_setbrushcolor(qObjectPtr, QColor(brush).qObjectPtr)
		End If
	End Method

	Method setPenStyle(style:Int)
		bmx_qt_qabstractgraphicsshapeitem_setpenstyle(qObjectPtr, style)
	End Method
	
	Method setPen(pen:Object)
		If QPen(pen) Then
			bmx_qt_qabstractgraphicsshapeitem_setpen(qObjectPtr, QPen(pen).qObjectPtr)
		ElseIf QColor(pen) Then
			bmx_qt_qabstractgraphicsshapeitem_setpencolor(qObjectPtr, QColor(pen).qObjectPtr)
		End If
	End Method

End Type

