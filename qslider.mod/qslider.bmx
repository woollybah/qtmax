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

Module Qt.QSlider

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QSlider Extends QAbstractSlider

	Rem
	bbdoc: Do not draw any tick marks.
	end rem
	Const NoTicks:Int = 0
	Rem
	bbdoc: Draw tick marks on both sides of the groove.
	end rem
	Const TicksBothSides:Int = 3
	Rem
	bbdoc: Draw tick marks above the (horizontal) slider
	end rem
	Const TicksAbove:Int = 1
	Rem
	bbdoc: Draw tick marks below the (horizontal) slider
	end rem
	Const TicksBelow:Int = 2
	Rem
	bbdoc: Draw tick marks to the left of the (vertical) slider
	end rem
	Const TicksLeft:Int = TicksAbove
	Rem
	bbdoc: Draw tick marks to the right of the (vertical) slider
	end rem
	Const TicksRight:Int = TicksBelow

	Function CreateSlider:QSlider(orientation:Int, parent:QWidget = Null)
		Return New QSlider.Create(orientation, parent)
	End Function
	
	Method Create:QSlider(orientation:Int, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qslider_create(Self, orientation, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qslider_create(Self, orientation, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method setTickInterval(interval:Int)
		bmx_qt_qslider_settickinterval(qObjectPtr, interval)
	End Method
	
	Method setTickPosition(position:Int)
		bmx_qt_qslider_settickposition(qObjectPtr, position)
	End Method
	
	Method tickInterval:Int()
		Return bmx_qt_qslider_tickinterval(qObjectPtr)
	End Method
	
	Method tickPosition:Int()
		Return bmx_qt_qslider_tickposition(qObjectPtr)
	End Method

End Type

