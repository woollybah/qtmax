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

Module Qt.QUndoCommand

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QUndoCommand

	Field qObjectPtr:Byte Ptr

	Function _create:QUndoCommand(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QUndoCommand = QUndoCommand(bmx_qt_qundocommand_obj(qObjectPtr))
			
			If Not this Then
				this = New QUndoCommand
				this.qObjectPtr = qObjectPtr
			End If

			Return this
		End If
	End Function
	
	Function CreateUndoCommand:QUndoCommand(parent:QUndoCommand = Null)
		Return New QUndoCommand.Create(parent)
	End Function
	
	Method Create:QUndoCommand(parent:QUndoCommand = Null)
		If parent Then
			qObjectPtr = bmx_qt_qundocommand_new(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qundocommand_new(Self, Null)
		End If
		Return Self
	End Method

	Method child:QUndoCommand(index:Int)
		Return QUndoCommand._create(bmx_qt_qundocommand_child(qObjectPtr, index))
	End Method
	
	Method childCount:Int()
		Return bmx_qt_qundocommand_childcount(qObjectPtr)
	End Method
	
	Method id:Int()
		Return bmx_qt_qundocommand_id_default(qObjectPtr)
	End Method
	
	Function _id:Int(cmd:QUndoCommand)
		Return cmd.id()
	End Function
	
	Method mergeWith:Int(command:QUndoCommand)
		Return bmx_qt_qundocommand_mergewith_default(qObjectPtr, command.qObjectPtr)
	End Method
	
	Function _mergeWith:Int(cmd:QUndoCommand, command:Byte Ptr)
		Return cmd.mergeWith(QUndoCommand._create(command))
	End Function
	
	Method redo()
	End Method

	Function _redo(cmd:QUndoCommand)
		cmd.redo()
	End Function

	Method setText(text:String)
		bmx_qt_qundocommand_settext(qObjectPtr, text)
	End Method

	Method text:String()
		Return bmx_qt_qundocommand_text(qObjectPtr)
	End Method

	Method undo()
	End Method

	Function _undo(cmd:QUndoCommand)
		cmd.undo()
	End Function
	
End Type

