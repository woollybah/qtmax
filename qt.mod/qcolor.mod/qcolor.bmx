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

Module Qt.QColor

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QColor

	Field qObjectPtr:Byte Ptr
	

	Function _Create:QColor(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QColor = New QColor
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Method Create:QColor(r:Int, g:Int, b:Int, a:Int = 255)
		qObjectPtr = bmx_qt_qcolor_create(r, g, b, a)
		Return Self
	End Method
	
	Method CreateWithGlobalColor:QColor(color:Int)
		qObjectPtr = bmx_qt_qcolor_createwithglobalcolor(color)
		Return Self
	End Method
	
	Method lighter:QColor(factor:Int = 150)
		Return QColor._create(bmx_qt_qcolor_lighter(qObjectPtr, factor))
	End Method
	

	Method Free()
		If qObjectPtr Then
			bmx_qt_qcolor_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type

