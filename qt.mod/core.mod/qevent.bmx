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

Rem
bbdoc: The base type of all event types.
about: Event objects contain event parameters.
<p>
Qt's main event loop (QCoreApplication::exec()) fetches native window system events from the event queue, translates them into QEvents,
and sends the translated events to QObjects.
</p>
<p>
In general, events come from the underlying window system (spontaneous() returns true), but it is also possible to manually send events
using QCoreApplication::sendEvent() and QCoreApplication::postEvent() (spontaneous() returns false).
</p>
<p>
QObjects receive events by having their QObject::event() function called. The function can be reimplemented in subclasses to
customize event handling and add additional event types; QWidget::event() is a notable example. By default, events are dispatched
to event handlers like QObject::timerEvent() and QWidget::mouseMoveEvent(). QObject::installEventFilter() allows an object to
intercept events destined for another object.
</p>
<p>
The basic QEvent contains only an event type parameter and an "accept" flag. The accept flag set with accept(), and cleared with
ignore(). It is set by default, but don't rely on this as subclasses may choose to clear it in their constructor.
</p>
<p>
Subclasses of QEvent contain additional parameters that describe the particular event.
</p>
End Rem
Type QEvent

	Field qObjectPtr:Byte Ptr

	Function _create:QEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QEvent = New QEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method accept()
		bmx_qt_qevent_accept(qObjectPtr)
	End Method
	
	Method ignore()
		bmx_qt_qevent_ignore(qObjectPtr)
	End Method
	
	Method isAccepted:Int()
		Return bmx_qt_qevent_isaccepted(qObjectPtr)
	End Method
	
	Method setAccepted(accepted:Int)
		bmx_qt_qevent_setaccepted(qObjectPtr, accepted)
	End Method
	
	Method spontaneous:Int()
		Return bmx_qt_qevent_spontaneous(qObjectPtr)
	End Method
	
	Method getType:Int()
		Return bmx_qt_qevent_gettype(qObjectPtr)
	End Method

End Type
