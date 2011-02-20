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

Module Qt.QAbstractAnimation

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QAbstractAnimation Extends QObject

	Rem
	bbdoc: The animation will not be deleted when stopped.
	End Rem
	Const KeepWhenStopped:Int = 0
	Rem
	bbdoc: The animation will be automatically deleted when stopped.
	End Rem
	Const DeleteWhenStopped:Int = 1

	Rem
	bbdoc: The animation is not running.
	about: This is the initial state of QAbstractAnimation, and the state QAbstractAnimation reenters when finished.
	The current time remain unchanged until either setCurrentTime() is called, or the animation is started by calling start().
	End Rem
	Const Stopped:Int = 0
	Rem
	bbdoc: The animation is paused (i.e., temporarily suspended). Calling resume() will resume animation activity.
	End Rem
	Const Paused:Int = 1
	Rem
	bbdoc: The animation is running.
	about: While control is in the event loop, QAbstractAnimation will update its current time at regular intervals,
	calling updateCurrentTime() when appropriate.
	End Rem
	Const Running:Int = 2

	Method setDuration(value:Int)
	End Method

	Method duration:Int()
	End Method
	
	Method pause()
		bmx_qt_qabstractanimation_pause(qObjectPtr)
	End Method
	
	Method resume()
		bmx_qt_qabstractanimation_resume(qObjectPtr)
	End Method
	
	Method state:Int()
		Return bmx_qt_qabstractanimation_state(qObjectPtr)
	End Method
	
	Method start(policy:Int = KeepWhenStopped)
		bmx_qt_qabstractanimation_start(qObjectPtr, policy)
	End Method
	
	Method stop()
		bmx_qt_qabstractanimation_stop(qObjectPtr)
	End Method
	
End Type
