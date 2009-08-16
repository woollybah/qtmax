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

Module Qt.QCursor

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QCursor

	Field qObjectPtr:Byte Ptr
	
	Function _create:QCursor(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QCursor = New QCursor
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function CreateCursor:QCursor(shape:Int)
		Return New QCursor.Create(shape)
	End Function
	
	Method Create:QCursor(shape:Int)
		qObjectPtr = bmx_qt_qcursor_create(shape)
		Return Self
	End Method
	
	Method bitmap:QBitmap()
		Return QBitmap._create(bmx_qt_qcursor_bitmap(qObjectPtr))
	End Method
	
	Method hotSpot(x:Int Var, y:Int Var)
		bmx_qt_qcursor_hotspot(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method mask:QBitmap()
		Return QBitmap._create(bmx_qt_qcursor_mask(qObjectPtr))
	End Method
	
	Method pixmap:QPixmap()
		Return QPixmap._create(bmx_qt_qcursor_pixmap(qObjectPtr))
	End Method
	
	Method setShape(shape:Int)
		bmx_qt_qcursor_setshape(qObjectPtr, shape)
	End Method
	
	Method shape:Int()
		Return bmx_qt_qcursor_shape(qObjectPtr)
	End Method
	
	Function pos(x:Int Var, y:Int Var)
		bmx_qt_qcursor_pos(Varptr x, Varptr y)
	End Function
	
	Function setPos(x:Int, y:Int)
		bmx_qt_qcursor_setpos(x, y)
	End Function
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qcursor_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type