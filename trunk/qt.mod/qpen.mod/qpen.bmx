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

Module Qt.QPen

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QPen

	Field qObjectPtr:Byte Ptr

	Function _create:QPen(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QPen = New QPen
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function CreatePen:QPen(style:Int)
		Return New QPen.Create(style)
	End Function
	
	Method Create:QPen(style:Int)
		qObjectPtr = bmx_qt_qpen_create(style)
		Return Self
	End Method
	
	Method CreateWithAttributes:QPen(brush:QBrush, width:Double, style:Int = Qt_SolidLine, cap:Int = Qt_SquareCap, join:Int = Qt_BevelJoin)
		qObjectPtr = bmx_qt_qpen_createwithattributes(brush.qObjectPtr, width, style, cap, join)
		Return Self
	End Method

	Method brush:QBrush()
		Return QBrush._create(bmx_qt_qpen_brush(qObjectPtr))
	End Method
	
	Method capStyle:Int()
		Return bmx_qt_qpen_capstyle(qObjectPtr)
	End Method
	
	Method color:QColor()
		Return QColor._create(bmx_qt_qpen_color(qObjectPtr))
	End Method
	
	Method dashOffset:Double()
		Return bmx_qt_qpen_dashoffset(qObjectPtr)
	End Method
	
	Method dashPattern:Double[]()
		Return bmx_qt_qpen_dashpattern(qObjectPtr)
	End Method
	
	Method isCosmetic:Int()
		Return bmx_qt_qpen_iscosmetic(qObjectPtr)
	End Method
	
	Method isSolid:Int()
		Return bmx_qt_qpen_issolid(qObjectPtr)
	End Method
	
	Method joinStyle:Int()
		Return bmx_qt_qpen_joinstyle(qObjectPtr)
	End Method
	
	Method miterLimit:Double()
		Return bmx_qt_qpen_miterlimit(qObjectPtr)
	End Method
	
	Method setBrush(brush:QBrush)
		bmx_qt_qpen_setbrush(qObjectPtr, brush.qObjectPtr)
	End Method
	
	Method setCapStyle(style:Int)
		bmx_qt_qpen_setcapstyle(qObjectPtr, style)
	End Method
	
	Method SetColor(color:QColor)
		bmx_qt_qpen_setcolor(qObjectPtr, color.qObjectPtr)
	End Method
	
	Method setCosmetic(cosmetic:Int)
		bmx_qt_qpen_setcosmetic(qObjectPtr, cosmetic)
	End Method
	
	Method setDashOffset(offset:Double)
		bmx_qt_qpen_setdashoffset(qObjectPtr, offset)
	End Method
	
	Method setDashPattern(pattern:Double[])
		bmx_qt_qpen_setdashpattern(qObjectPtr, pattern)
	End Method
	
	Method setJoinStyle(style:Int)
		bmx_qt_qpen_setjoinstyle(qObjectPtr, style)
	End Method
	
	Method setMiterLimit(limit:Double)
		bmx_qt_qpen_setmiterlimit(qObjectPtr, limit)
	End Method
	
	Method setStyle(style:Int)
		bmx_qt_qpen_setstyle(qObjectPtr, style)
	End Method
	
	Method setWidth(width:Int)
		bmx_qt_qpen_setwidth(qObjectPtr, width)
	End Method
	
	Method setWidthF(width:Double)
		bmx_qt_qpen_setwidthf(qObjectPtr, width)
	End Method
	
	Method style:Int()
		Return bmx_qt_qpen_style(qObjectPtr)
	End Method
	
	Method width:Int()
		Return bmx_qt_qpen_width(qObjectPtr)
	End Method
	
	Method widthF:Double()
		Return bmx_qt_qpen_widthf(qObjectPtr)
	End Method

	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qpen_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type

