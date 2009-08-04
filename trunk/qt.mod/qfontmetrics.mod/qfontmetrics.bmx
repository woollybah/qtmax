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

Module Qt.QFontMetrics

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QFontMetrics

	Field qObjectPtr:Byte Ptr
	
	Function _create:QFontMetrics(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QFontMetrics = New QFontMetrics
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreateFontMetrics:QFontMetrics(font:QFont)
		Return New QFontMetrics.Create(font)
	End Function
	
	Method Create:QFontMetrics(font:QFont)
		qObjectPtr = bmx_qt_qfontmetrics_create(font.qObjectPtr)
		Return Self
	End Method
	
	Method ascent:Int()
		Return bmx_qt_qfontmetrics_ascent(qObjectPtr)
	End Method

	Method averageCharWidth:Int()
		Return bmx_qt_qfontmetrics_averagecharwidth(qObjectPtr)
	End Method

	Method boundingRect:QRect(text:String)
		Return QRect._create(bmx_qt_qfontmetrics_boundingrect(qObjectPtr, text))
	End Method

	Method Free()
		If qObjectPtr Then
			bmx_qt_qfontmetrics_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type
