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

Module Qt.QTimer

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QTimer Extends QObject

	Field _terminateOnShot:Int

	Function CreateTimer:QTimer(parent:QObject = Null)
		Return New Qtimer.Create(parent)
	End Function
	
	Method Create:QTimer(parent:QObject = Null)
		If parent Then
			qObjectPtr = bmx_qt_qtimer_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qtimer_create(Self, Null)
		End If
		Return Self
	End Method

	Method interval:Int()
		Return bmx_qt_qtimer_interval(qObjectPtr)
	End Method
	
	Method isActive:Int()
		Return bmx_qt_qtimer_isactive(qObjectPtr)
	End Method
	
	Method isSingleShot:Int()
		Return bmx_qt_qtimer_issingleshot(qObjectPtr)
	End Method
	
	Method setInterval(msec:Int)
		bmx_qt_qtimer_setinterval(qObjectPtr, msec)
	End Method
	
	Method setSingleShot(value:Int)
		bmx_qt_qtimer_setsingleshot(qObjectPtr, value)
	End Method
	
	Method timerId:Int()
		Return bmx_qt_qtimer_timerid(qObjectPtr)
	End Method
	
	Method start(msec:Int = 0)
		bmx_qt_qtimer_start(qObjectPtr, msec)
	End Method
	
	Method stop()
		bmx_qt_qtimer_stop(qObjectPtr)
	End Method
	
	Method Free()
		Super.Free()
		If qObjectPtr Then
			bmx_qt_qtimer_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Function singleShot(msec:Int, receiver:QObject, member:String)
		Local timer:QTimer = New QTimer.Create()
		timer.setSingleShot(True)
		connect(timer, "timeout", receiver, member)
		timer.start(msec)
	End Function

	' SIGNAL : timeout
	Function _OnTimeout(obj:QTimer)
		obj._InvokeSignals("timeout", Null)
		If obj._terminateOnShot Then
			obj.Free()
		End If
	End Function

End Type
