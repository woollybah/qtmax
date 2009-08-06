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

Module Qt.QAbstractSlider

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QAbstractSlider Extends QWidget

	Const SliderNoAction:Int = 0
	Const SliderSingleStepAdd:Int = 1
	Const SliderSingleStepSub:Int = 2
	Const SliderPageStepAdd:Int = 3
	Const SliderPageStepSub:Int = 4
	Const SliderToMinimum:Int = 5
	Const SliderToMaximum:Int = 6
	Const SliderMove:Int = 7
	
	Method hasTracking:Int()
		Return bmx_qt_qabstractslider_hastracking(qObjectPtr)
	End Method
	
	Method invertedAppearance:Int()
		Return bmx_qt_qabstractslider_invertedappearance(qObjectPtr)
	End Method
	
	Method invertedControls:Int()
		Return bmx_qt_qabstractslider_invertedcontrols(qObjectPtr)
	End Method
	
	Method isSliderDown:Int()
		Return bmx_qt_qabstractslider_issliderdown(qObjectPtr)
	End Method
	
	Method maximum:Int()
		Return bmx_qt_qabstractslider_maximum(qObjectPtr)
	End Method
	
	Method minimum:Int()
		Return bmx_qt_qabstractslider_minimum(qObjectPtr)
	End Method
	
	Method orientation:Int()
		Return bmx_qt_qabstractslider_orientation(qObjectPtr)
	End Method
	
	Method pageStep:Int()
		Return bmx_qt_qabstractslider_pagestep(qObjectPtr)
	End Method
	
	Method setInvertedAppearance(value:Int)
		bmx_qt_qabstractslider_setinvertedappearance(qObjectPtr, value)
	End Method
	
	Method setInvertedControls(value:Int)
		bmx_qt_qabstractslider_setinvertedcontrols(qObjectPtr, value)
	End Method
	
	Method setMaximum(value:Int)
		bmx_qt_qabstractslider_setmaximum(qObjectPtr, value)
	End Method
	
	Method setMinimum(value:Int)
		bmx_qt_qabstractslider_setminimum(qObjectPtr, value)
	End Method
	
	Method setPageStep(value:Int)
		bmx_qt_qabstractslider_setpagestep(qObjectPtr, value)
	End Method
	
	Method setRange(minimum:Int, maximum:Int)
		bmx_qt_qabstractslider_setrange(qObjectPtr, minimum, maximum)
	End Method
	
	Method setSingleStep(value:Int)
		bmx_qt_qabstractslider_setsinglestep(qObjectPtr, value)
	End Method
	
	Method setSliderDown(value:Int)
		bmx_qt_qabstractslider_setsliderdown(qObjectPtr, value)
	End Method
	
	Method setSliderPosition(value:Int)
		bmx_qt_qabstractslider_setsliderposition(qObjectPtr, value)
	End Method
	
	Method setTracking(enable:Int)
		bmx_qt_qabstractslider_settracking(qObjectPtr, enable)
	End Method
	
	Method singleStep:Int()
		Return bmx_qt_qabstractslider_singlestep(qObjectPtr)
	End Method
	
	Method sliderPosition:Int()
		Return bmx_qt_qabstractslider_sliderposition(qObjectPtr)
	End Method
	
	Method triggerAction(sliderAction:Int)
		bmx_qt_qabstractslider_triggeraction(qObjectPtr, sliderAction)
	End Method
	
	Method value:Int()
		Return bmx_qt_qabstractslider_value(qObjectPtr)
	End Method
	
	Method setOrientation(orientation:Int)
		bmx_qt_qabstractslider_setorientation(qObjectPtr, orientation)
	End Method
	
	Method setValue(value:Int)
		bmx_qt_qabstractslider_setvalue(qObjectPtr, value)
	End Method

	' SIGNAL : actionTriggered
	Function _OnActionTriggered(obj:QAbstractSlider, action:Int)
		obj._InvokeSignals("actionTriggered", [String(action)])
	End Function

	' SIGNAL : rangeChanged
	Function _OnRangeChanged(obj:QAbstractSlider, _min:Int, _max:Int)
		obj._InvokeSignals("rangeChanged", [String(_min), String(_max)])
	End Function

	' SIGNAL : sliderMoved
	Function _OnSliderMoved(obj:QAbstractSlider, value:Int)
		obj._InvokeSignals("sliderMoved", [String(value)])
	End Function

	' SIGNAL : sliderPressed
	Function _OnSliderPressed(obj:QAbstractSlider)
		obj._InvokeSignals("sliderPressed", Null)
	End Function

	' SIGNAL : sliderReleased
	Function _OnSliderReleased(obj:QAbstractSlider)
		obj._InvokeSignals("sliderReleased", Null)
	End Function

	' SIGNAL : valueChanged
	Function _OnValueChanged(obj:QAbstractSlider, value:Int)
		obj._InvokeSignals("valueChanged", [String(value)])
	End Function

End Type
