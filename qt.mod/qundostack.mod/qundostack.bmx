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

Module Qt.QUndoStack

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QUndoStack Extends QObject

	Function CreateUndoStack:QUndoStack(parent:QObject = Null)
		Return New QUndoStack.Create(parent)
	End Function
	
	Method Create:QUndoStack(parent:QObject = Null)
		If parent Then
			qObjectPtr = bmx_qt_qundostack_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qundostack_create(Self, Null)
		End If
		Return Self
	End Method

	Method beginMacro(text:String)
		bmx_qt_qundostack_beginmacro(qObjectPtr, text)
	End Method
	
	Method canRedo:Int()
		Return bmx_qt_qundostack_canredo(qObjectPtr)
	End Method
	
	Method canUndo:Int()
		Return bmx_qt_qundostack_canundo(qObjectPtr)
	End Method
	
	Method cleanIndex:Int()
		Return bmx_qt_qundostack_cleanindex(qObjectPtr)
	End Method
	
	Method clear()
		bmx_qt_qundostack_clear(qObjectPtr)
	End Method
	
	Method command:QUndoCommand(index:Int)
		Return QUndoCommand._create(bmx_qt_qundostack_command(qObjectPtr, index))
	End Method
	
	Method count:Int()
		Return bmx_qt_qundostack_count(qObjectPtr)
	End Method
	
	Method createRedoAction:QAction(parent:QObject, prefix:String = "")
		Return QAction._find(bmx_qt_qundostack_createredoaction(qObjectPtr, parent.qObjectPtr, prefix))
	End Method
	
	Method createUndoAction:QAction(parent:QObject, prefix:String = "")
		Return QAction._find(bmx_qt_qundostack_createundoaction(qObjectPtr, parent.qObjectPtr, prefix))
	End Method
	
	Method endMacro()
		bmx_qt_qundostack_endmacro(qObjectPtr)
	End Method
	
	Method index:Int()
		Return bmx_qt_qundostack_index(qObjectPtr)
	End Method
	
	Method isActive:Int()
		Return bmx_qt_qundostack_isactive(qObjectPtr)
	End Method
	
	Method isClean:Int()
		Return bmx_qt_qundostack_isclean(qObjectPtr)
	End Method
	
	Method push(cmd:QUndoCommand)
		bmx_qt_qundostack_push(qObjectPtr, cmd.qObjectPtr)
	End Method
	
	Method redoText:String()
		Return bmx_qt_qundostack_redotext(qObjectPtr)
	End Method
	
	Method setUndoLimit(limit:Int)
		bmx_qt_qundostack_setundolimit(qObjectPtr, limit)
	End Method
	
	Method text:String(idx:Int)
		Return bmx_qt_qundostack_text(qObjectPtr, idx)
	End Method
	
	Method undoLimit:Int()
		Return bmx_qt_qundostack_undolimit(qObjectPtr)
	End Method
	
	Method undoText:String()
		Return bmx_qt_qundostack_undotext(qObjectPtr)
	End Method

	Method redo()
		bmx_qt_qundostack_redo(qObjectPtr)
	End Method

	Method setActive(active:Int = True)
		bmx_qt_qundostack_setactive(qObjectPtr, active)
	End Method

	Method setClean()
		bmx_qt_qundostack_setclean(qObjectPtr)
	End Method

	Method setIndex(idx:Int)
		bmx_qt_qundostack_setindex(qObjectPtr, idx)
	End Method

	Method undo()
		bmx_qt_qundostack_undo(qObjectPtr)
	End Method
	
End Type

