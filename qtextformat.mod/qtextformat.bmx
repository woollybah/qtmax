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

Module Qt.QTextFormat

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QTextFormat

	Field qObjectPtr:Byte Ptr

	Function _create:QTextFormat(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextFormat = New QTextFormat
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Method background:QBrush()
		Return QBrush._create(bmx_qt_textformat_background(qObjectPtr))
	End Method

	Method boolProperty:Int(propertyId:Int)
		Return bmx_qt_textformat_boolproperty(qObjectPtr, propertyId)
	End Method

	Method brushProperty:QBrush(propertyId:Int)
		Return QBrush._create(bmx_qt_textformat_brushproperty(qObjectPtr, propertyId))
	End Method

	Method clearBackground()
		bmx_qt_textformat_clearbackground(qObjectPtr)
	End Method

	Method clearForeground()
		bmx_qt_textformat_clearforeground(qObjectPtr)
	End Method

	Method clearProperty(propertyId:Int)
		bmx_qt_textformat_clearproperty(qObjectPtr, propertyId)
	End Method

	Method colorProperty:QColor(propertyId:Int)
		Return QColor._create(bmx_qt_textformat_colorProperty(qObjectPtr, propertyId))
	End Method

	Method doubleProperty:Double(propertyId:Int)
		Return bmx_qt_textformat_doubleproperty(qObjectPtr, propertyId)
	End Method

	Method foreground:QBrush()
		Return QBrush._create(bmx_qt_textformat_foreground(qObjectPtr))
	End Method

	Method hasProperty:Int(propertyId:Int)
		Return bmx_qt_textformat_hasproperty(qObjectPtr, propertyId)
	End Method

	Method intProperty:Int(propertyId:Int)
		Return bmx_qt_textformat_intproperty(qObjectPtr, propertyId)
	End Method

	Method isBlockFormat:Int()
		Return bmx_qt_textformat_isblockformat(qObjectPtr)
	End Method

	Method isCharFormat:Int()
		Return bmx_qt_textformat_ischarformat(qObjectPtr)
	End Method

	Method isFrameFormat:Int()
		Return bmx_qt_textformat_isframeformat(qObjectPtr)
	End Method

	Method isImageFormat:Int()
		Return bmx_qt_textformat_isimageformat(qObjectPtr)
	End Method

	Method isListFormat:Int()
		Return bmx_qt_textformat_islistformat(qObjectPtr)
	End Method

	Method isTableCellFormat:Int()
		Return bmx_qt_textformat_istablecellformat(qObjectPtr)
	End Method

	Method isTableFormat:Int()
		Return bmx_qt_textformat_istableformat(qObjectPtr)
	End Method

	Method isValid:Int()
		Return bmx_qt_textformat_isvalid(qObjectPtr)
	End Method

	Method layoutDirection:Int()
		Return bmx_qt_textformat_layoutdirection(qObjectPtr)
	End Method

	'Method lengthProperty:QTextLength(propertyId:Int)
	' TODO
	'End Method

	'Method QVector<QTextLength> lengthVectorProperty(propertyId:Int)
	' TODO
	'End Method

	Method merge(other:QTextFormat)
		bmx_qt_textformat_merge(qObjectPtr, other.qObjectPtr)
	End Method

	Method objectIndex:Int()
		Return bmx_qt_textformat_objectindex(qObjectPtr)
	End Method

	Method objectType:Int()
		Return bmx_qt_textformat_objecttype(qObjectPtr)
	End Method

	Method penProperty:QPen(propertyId:Int)
		Return QPen._create(bmx_qt_textformat_penproperty(qObjectPtr, propertyId))
	End Method

	'Method QMap<Int, QVariant> properties()
	' TODO
	'End Method

	'Method QVariant property(propertyId:Int)
	' TODO
	'End Method

	Method propertyCount:Int()
		Return bmx_qt_textformat_propertycount(qObjectPtr)
	End Method

	Method setBackground(brush:QBrush)
		bmx_qt_textformat_setbackground(qObjectPtr, brush.qObjectPtr)
	End Method

	Method setForeground(brush:QBrush)
		bmx_qt_qtextformat_setforeground(qObjectPtr, brush.qObjectPtr)
	End Method

	Method setLayoutDirection(direction:Int)
		bmx_qt_textformat_setlayoutdirection(qObjectPtr, direction)
	End Method

	Method setObjectIndex(index:Int)
		bmx_qt_textformat_setobjectindex(qObjectPtr, index)
	End Method

	Method setObjectType(_type:Int)
		bmx_qt_textformat_setobjecttype(qObjectPtr, _type)
	End Method

	'Method setProperty(propertyId:Int, value:QVariant)
	' TODO
	'End Method

	'Method setProperty(propertyId:Int, QVector<QTextLength> & value)
	' TODO
	'End Method

	Method stringProperty:String(propertyId:Int)
		Return bmx_qt_textformat_stringproperty(qObjectPtr, propertyId)
	End Method

End Type


