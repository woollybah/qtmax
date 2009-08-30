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

Module Qt.QDialog

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QDialog Extends QWidget

	Function CreateDialog:QDialog(parent:QWidget = Null, flags:Int = 0)
		Return New QDialog.Create(parent, flags)
	End Function
	
	Method Create:QDialog(parent:QWidget = Null, flags:Int = 0)
		If parent Then
			qObjectPtr = bmx_qt_qdialog_create(Self, parent.qObjectPtr, flags)
		Else
			qObjectPtr = bmx_qt_qdialog_create(Self, Null, flags)
		End If
		OnInit()
		Return Self
	End Method

	Method isSizeGripEnabled:Int()
		Return bmx_qt_qdialog_issizegripenabled(qObjectPtr)
	End Method
	
	Method result:Int()
		Return bmx_qt_qdialog_result(qObjectPtr)
	End Method
	
	Method setModal(modal:Int)
		bmx_qt_qdialog_setmodal(qObjectPtr, modal)
	End Method
	
	Method setResult(i:Int)
		bmx_qt_qdialog_setresult(qObjectPtr, i)
	End Method
	
	Method setSizeGripEnabled(value:Int)
		bmx_qt_qdialog_setsizegripenabled(qObjectPtr, value)
	End Method
	
	Method accept()
		bmx_qt_qdialog_accept(qObjectPtr)
	End Method
	
	Method done(r:Int)
		bmx_qt_qdialog_done(qObjectPtr, r)
	End Method
	
	Method exec:Int()
		Return bmx_qt_qdialog_exec(qObjectPtr)
	End Method
	
	Method open()
		bmx_qt_qdialog_open(qObjectPtr)
	End Method
	
	Method reject() 
		bmx_qt_qdialog_reject(qObjectPtr)
	End Method

	' SIGNAL : accepted
	Function _OnAccepted(obj:QDialog)
		obj._InvokeSignals("accepted", Null)
	End Function

	' SIGNAL : finished
	Function _OnFinished(obj:QDialog, result:Int)
		obj._InvokeSignals("finished", [String(result)])
	End Function

	' SIGNAL : rejected
	Function _OnRejected(obj:QDialog)
		obj._InvokeSignals("rejected", Null)
	End Function

End Type

