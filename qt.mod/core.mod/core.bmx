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

Module Qt.Core

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"

?macos
ModuleInfo "LD_OPTS: -L%PWD%/../lib/macos/"
?win32
ModuleInfo "LD_OPTS: -L%PWD%/../lib/win32/"
?

?macos
Import "-lQtCore.4"
?win32
Import "-lQtCore4"
?linux
Import "-lQtCore"
?


Import "qvariant.bmx"
Import "qrect.bmx"
Import "qrectf.bmx"
Import "qevent.bmx"
Import "qdatetime.bmx"
Import "common.bmx"

Type QCoreObjectPtr

	Field qObjectPtr:Byte Ptr

	Method isWidget:Int()
		Return False
	End Method
	
End Type

Type QSize

	Function scale(w:Int Var, h:Int Var, scaleW:Int, scaleH:Int, _mode:Int)
		bmx_qt_qsize_scale(Varptr w, Varptr h, scaleW, scaleH, _mode)
	End Function

End Type


Type QItemList

	Field list:TMap = New TMap
	Field lastItemId:Long
	
	Method addItem:Long(data:Object)
		Local id:Long = newItem()
		list.Insert(String(id), data)
		Return id
	End Method
	
	Method itemData:Object(itemId:Long)
		Return list.ValueForKey(String(itemId))
	End Method
	
	Method setItem(id:Long Var, data:Object)
		If Not id Then
			id = newItem()
		End If
		list.Insert(String(id), data)
	End Method
	
	Method removeItem(itemId:Long)
		list.Remove(String(itemId))
	End Method
	
	Method clear()
		list.Clear()
	End Method

	Method newItem:Long()
		lastItemId:+ 1
		Return lastItemId
	End Method

End Type
