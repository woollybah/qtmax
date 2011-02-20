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

Module Qt.QEasingCurve

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QEasingCurve

	Field qObjectPtr:Byte Ptr
	
	Rem
	bbdoc: Easing curve for a linear (t) function: velocity is constant.
	about: <img src="queasingcurve-linear.png" border="0" />
	End Rem
	Const Linear:Int = 0
	Rem
	bbdoc: Easing curve for a quadratic (t^2) function: accelerating from zero velocity.
	End Rem
	Const InQuad:Int = 1
	Rem
	bbdoc: Easing curve for a quadratic (t^2) function: decelerating to zero velocity.
	End Rem
	Const OutQuad:Int = 2
	Rem
	bbdoc: Easing curve for a quadratic (t^2) function: acceleration until halfway, then deceleration.
	End Rem
	Const InOutQuad:Int = 3
	Rem
	bbdoc: Easing curve for a quadratic (t^2) function: deceleration until halfway, then acceleration.
	End Rem
	Const OutInQuad:Int = 4
	Rem
	bbdoc: Easing curve for a cubic (t^3) function: accelerating from zero velocity.
	End Rem
	Const InCubic:Int = 5
	Rem
	bbdoc: Easing curve for a cubic (t^3) function: decelerating to zero velocity.
	End Rem
	Const OutCubic:Int = 6
	Rem
	bbdoc: Easing curve for a cubic (t^3) function: acceleration until halfway, then deceleration.
	End Rem
	Const InOutCubic:Int = 7
	Rem
	bbdoc: Easing curve for a cubic (t^3) function: deceleration until halfway, then acceleration.
	End Rem
	Const OutInCubic:Int = 8
	Rem
	bbdoc: Easing curve for a quartic (t^4) function: accelerating from zero velocity.
	End Rem
	Const InQuart:Int = 9
	Rem
	bbdoc: Easing curve for a quartic (t^4) function: decelerating to zero velocity.
	End Rem
	Const OutQuart:Int = 10
	Rem
	bbdoc: Easing curve for a quartic (t^4) function: acceleration until halfway, then deceleration.
	End Rem
	Const InOutQuart:Int = 11
	Rem
	bbdoc: Easing curve for a quartic (t^4) function: deceleration until halfway, then acceleration.
	End Rem
	Const OutInQuart:Int = 12
	Rem
	bbdoc: Easing curve for a quintic (t^5) easing in: accelerating from zero velocity.
	End Rem
	Const InQuint:Int = 13
	Rem
	bbdoc: Easing curve for a quintic (t^5) function: decelerating to zero velocity.
	End Rem
	Const OutQuint:Int = 14
	Rem
	bbdoc: Easing curve for a quintic (t^5) function: acceleration until halfway, then deceleration.
	End Rem
	Const InOutQuint:Int = 15
	Rem
	bbdoc: Easing curve for a quintic (t^5) function: deceleration until halfway, then acceleration.
	End Rem
	Const OutInQuint:Int = 16
	Rem
	bbdoc: Easing curve for a sinusoidal (sin(t)) function: accelerating from zero velocity.
	End Rem
	Const InSine:Int = 17
	Rem
	bbdoc: Easing curve for a sinusoidal (sin(t)) function: decelerating from zero velocity.
	End Rem
	Const OutSine:Int = 18
	Rem
	bbdoc: Easing curve for a sinusoidal (sin(t)) function: acceleration until halfway, then deceleration.
	End Rem
	Const InOutSine:Int = 19
	Rem
	bbdoc: Easing curve for a sinusoidal (sin(t)) function: deceleration until halfway, then acceleration.
	End Rem
	Const OutInSine:Int = 20
	Rem
	bbdoc: Easing curve for an exponential (2^t) function: accelerating from zero velocity.
	End Rem
	Const InExpo:Int = 21
	Rem
	bbdoc: Easing curve for an exponential (2^t) function: decelerating from zero velocity.
	End Rem
	Const OutExpo:Int = 22
	Rem
	bbdoc: Easing curve for an exponential (2^t) function: acceleration until halfway, then deceleration.
	End Rem
	Const InOutExpo:Int = 23
	Rem
	bbdoc: Easing curve for an exponential (2^t) function: deceleration until halfway, then acceleration.
	End Rem
	Const OutInExpo:Int = 24
	Rem
	bbdoc: Easing curve for a circular (sqrt(1-t^2)) function: accelerating from zero velocity.
	End Rem
	Const InCirc:Int = 25
	Rem
	bbdoc: Easing curve for a circular (sqrt(1-t^2)) function: decelerating from zero velocity.
	End Rem
	Const OutCirc:Int = 26
	Rem
	bbdoc: Easing curve for a circular (sqrt(1-t^2)) function: acceleration until halfway, then deceleration.
	End Rem
	Const InOutCirc:Int = 27
	Rem
	bbdoc: Easing curve for a circular (sqrt(1-t^2)) function: deceleration until halfway, then acceleration.
	End Rem
	Const OutInCirc:Int = 28
	Rem
	bbdoc: Easing curve for an elastic (exponentially decaying sine wave) function: accelerating from zero velocity.
	about: The peak amplitude can be set with the amplitude parameter, and the period of decay by the period parameter.
	End Rem
	Const InElastic:Int = 29
	Rem
	bbdoc: Easing curve for an elastic (exponentially decaying sine wave) function: decelerating from zero velocity.
	about: The peak amplitude can be set with the amplitude parameter, and the period of decay by the period parameter.
	End Rem
	Const OutElastic:Int = 30
	Rem
	bbdoc: Easing curve for an elastic (exponentially decaying sine wave) function: acceleration until halfway, then deceleration.
	End Rem
	Const InOutElastic:Int = 31
	Rem
	bbdoc: Easing curve for an elastic (exponentially decaying sine wave) function: deceleration until halfway, then acceleration.
	End Rem
	Const OutInElastic:Int = 32
	Rem
	bbdoc: Easing curve for a back (overshooting cubic function: (s+1)*t^3 - s*t^2) easing in: accelerating from zero velocity.
	End Rem
	Const InBack:Int = 33
	Rem
	bbdoc: Easing curve for a back (overshooting cubic function: (s+1)*t^3 - s*t^2) easing out: decelerating to zero velocity.
	End Rem
	Const OutBack:Int = 34
	Rem
	bbdoc: Easing curve for a back (overshooting cubic function: (s+1)*t^3 - s*t^2) easing in/out: acceleration until halfway, then deceleration.
	End Rem
	Const InOutBack:Int = 35
	Rem
	bbdoc: Easing curve for a back (overshooting cubic easing: (s+1)*t^3 - s*t^2) easing out/in: deceleration until halfway, then acceleration.
	End Rem
	Const OutInBack:Int = 36
	Rem
	bbdoc: Easing curve for a bounce (exponentially decaying parabolic bounce) function: accelerating from zero velocity.
	End Rem
	Const InBounce:Int = 37
	Rem
	bbdoc: Easing curve for a bounce (exponentially decaying parabolic bounce) function: decelerating from zero velocity.
	End Rem
	Const OutBounce:Int = 38
	Rem
	bbdoc: Easing curve for a bounce (exponentially decaying parabolic bounce) function easing in/out: acceleration until halfway, then deceleration.
	End Rem
	Const InOutBounce:Int = 39
	Rem
	bbdoc: Easing curve for a bounce (exponentially decaying parabolic bounce) function easing out/in: deceleration until halfway, then acceleration.
	End Rem
	Const OutInBounce:Int = 40
	
	Method Create:QEasingCurve(curveType:Int = Linear)
		qObjectPtr = bmx_qt_qeasingcurve_create(curveType)
		Return Self
	End Method
	
	Method Delete()
		If qObjectPtr Then
			bmx_qt_qeasingcurve_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

End Type
