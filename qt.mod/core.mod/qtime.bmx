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

Import "common.bmx"

Type QTime

	Field qObjectPtr:Byte Ptr
	
	Function _create:QTime(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTime = New QTime
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Method elapsed:Int()
		Return bmx_qt_qtime_elapsed(qObjectPtr)
	End Method
	
	Method hour:Int()
		Return bmx_qt_qtime_hour(qObjectPtr)
	End Method
	
	Method isNull:Int()
		Return bmx_qt_qtime_isnull(qObjectPtr)
	End Method
	
	Method isValid:Int()
		Return bmx_qt_qtime_isvalid(qObjectPtr)
	End Method
	
	Method minute:Int()
		Return bmx_qt_qtime_minute(qObjectPtr)
	End Method
	
	Method msec:Int()
		Return bmx_qt_qtime_msec(qObjectPtr)
	End Method
	
	Method msecsTo:Int(t:QTime)
		Return bmx_qt_qtime_msecsto(qObjectPtr, t.qObjectPtr)
	End Method
	
	Method restart()
		bmx_qt_qtime_restart(qObjectPtr)
	End Method
	
	Method Second:Int()
		Return bmx_qt_qtime_second(qObjectPtr)
	End Method
	
	Method secsTo:Int(t:QTime)
		Return bmx_qt_qtime_secsto(qObjectPtr, t.qObjectPtr)
	End Method
	
	Method setHMS:Int(h:Int, m:Int, s:Int, ms:Int = 0)
		Return bmx_qt_qtime_sethms(qObjectPtr, h, m, s, ms)
	End Method
	
	Method start()
		bmx_qt_qtime_start(qObjectPtr)
	End Method
	
	Function CurrentTime:QTime()
		Return QTime._create(bmx_qt_qtime_currenttime())
	End Function
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qtime_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type

