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

Module Qt.QTransform

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QTransform

	Field qObjectPtr:Byte Ptr
	
	Function _create:QTransform(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTransform = New QTransform
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method Create:QTransform()
		qObjectPtr = bmx_qt_qtransform_create()
		Return Self
	End Method
	
	Method mapPointF(x:Double, y:Double, xp:Double Var, yp:Double Var)
		bmx_qt_qtransform_mappointf(qObjectPtr, x, y, Varptr xp, Varptr yp)
	End Method
	
	Method reset()
	End Method
	
	Method rotate:QTransform(angle:Double, axis:Int = Qt_ZAxis)
		bmx_qt_qtransform_rotate(qObjectPtr, angle, axis)
		Return Self
	End Method
	
	Method scale:QTransform(sx:Double, sy:Double)
		Return Self
	End Method
	
	Method setMatrix()
	End Method
	
	Method shear:QTransform(sh:Double, sv:Double)
	End Method

	Method Delete()
		If qObjectPtr Then
			bmx_qt_qtransform_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
End Type

