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

Module Qt.QUndoView

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QUndoView Extends QListView

	Function CreateUndoView:QUndoView(parent:QWidget = Null)
		Return New QUndoView.Create(parent)
	End Function
	
	Method Create:QUndoView(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qundoview_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qundoview_create(Self, Null)
		End If
		Return Self
	End Method
	
	Method CreateWithStack:QUndoView(stack:QUndoStack, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qundoview_createwithstack(Self, stack.qObjectPtr, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qundoview_createwithstack(Self, stack.qObjectPtr, Null)
		End If
		Return Self
	End Method

	Method CreateWithGroup:QUndoView(group:QUndoGroup, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qundoview_createwithgroup(Self, group.qObjectPtr, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qundoview_createwithgroup(Self, group.qObjectPtr, Null)
		End If
		Return Self
	End Method

End Type

