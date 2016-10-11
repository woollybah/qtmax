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

Module Qt.QStatusBar

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QStatusBar Extends QWidget

	Function CreateStatusBar:QStatusBar(parent:QWidget = Null)
	End Function
	
	Method Create:QStatusBar(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qstatusbar_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qstatusbar_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Function __create:QStatusBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QStatusBar = New QStatusBar
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QStatusBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QStatusBar = QStatusBar(qfind(qObjectPtr))
			If Not widget Then
				Return QStatusBar.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Method addPermanentWidget(widget:QWidget, stretch:Int = 0)
		bmx_qt_qstatusbar_addpermanentwidget(qObjectPtr, widget.qObjectPtr, stretch)
	End Method
	
	Method addWidget(widget:QWidget, stretch:Int = 0)
		bmx_qt_qstatusbar_addwidget(qObjectPtr, widget.qObjectPtr, stretch)
	End Method
	
	Method currentMessage:String()
		Return bmx_qt_qstatusbar_currentmessage(qObjectPtr)
	End Method
	
	Method insertPermanentWidget:Int(index:Int, widget:QWidget, stretch:Int = 0)
		bmx_qt_qstatusbar_insertpermanentwidget(qObjectPtr, index, widget.qObjectPtr, stretch)
	End Method
	
	Method insertWidget:Int(index:Int, widget:QWidget, stretch:Int = 0)
		Return bmx_qt_qstatusbar_insertwidget(qObjectPtr, index, widget.qObjectPtr, stretch)
	End Method
	
	Method isSizeGripEnabled:Int()
		Return bmx_qt_qstatusbar_issizegripenabled(qObjectPtr)
	End Method
	
	Method removeWidget(widget:QWidget)
		bmx_qt_qstatusbar_removewidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method setSizeGripEnabled(value:Int)
		bmx_qt_qstatusbar_setsizegripenabled(qObjectPtr, value)
	End Method

	Method clearMessage()
		bmx_qt_qstatusbar_clearmessage(qObjectPtr)
	End Method
	
	Method showMessage(message:String, timeout:Int = 0)
		bmx_qt_qstatusbar_showmessage(qObjectPtr, message, timeout)
	End Method

	' SIGNAL : messageChanged
	Function _OnMessageChanged(obj:QStatusBar, message:String)
		obj._InvokeSignals("messageChanged", [message])
	End Function

End Type

