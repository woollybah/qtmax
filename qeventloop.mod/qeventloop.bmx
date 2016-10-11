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

Module Qt.QEventLoop

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QEventLoop Extends QObject

	Rem
	bbdoc: All events.
	about: Note that DeferredDelete events are processed specially. 
	End Rem
	Const AllEvents:Int = $00

	Rem
	bbdoc: Do not process user input events, such as ButtonPress and KeyPress.
	about: Note that the events are not discarded; they will be delivered the next time processEvents() is called without the ExcludeUserInputEvents flag.
	End Rem
	Const ExcludeUserInputEvents:Int = $01

	Rem
	bbdoc: Do not process socket notifier events.
	about: Note that the events are not discarded; they will be delivered the next time processEvents() is called without the ExcludeSocketNotifiers flag.
	End Rem
	Const ExcludeSocketNotifiers:Int = $02

	Rem
	bbdoc: Wait for events if no pending events are available.
	End Rem
	Const WaitForMoreEvents:Int = $04

	Function CreateEventLoop:QEventLoop(parent:QObject = Null)
		Return New QEventLoop.Create(parent)
	End Function
	
	Method Create:QEventLoop(parent:QObject = Null)
		If parent Then
			qObjectPtr = bmx_qt_qeventloop_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qeventloop_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method OnInit()
	End Method
	
	Method exec:Int(flags:Int = AllEvents)
		Return bmx_qt_qeventloop_exec(qObjectPtr, flags)
	End Method
	
	Method exitLoop(returnCode:Int = 0 )
		bmx_qt_qeventloop_exit(qObjectPtr, returnCode)
	End Method
	
	Method isRunning:Int()
		Return bmx_qt_qeventloop_isrunning(qObjectPtr)
	End Method
	
	Method processEvents:Int(flags:Int = AllEvents)
		Return bmx_qt_qeventloop_processevents(qObjectPtr, flags)
	End Method
	
	Method processEventsTime(flags:Int, maxTime:Int)
		bmx_qt_qeventloop_processeventstime(qObjectPtr, flags, maxTime)
	End Method
	
	Method wakeUp()
		bmx_qt_qeventloop_wakeup(qObjectPtr)
	End Method
	
	Method quit()
		bmx_qt_qeventloop_quit(qObjectPtr)
	End Method

End Type


