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

Module Qt.QGradient

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QGradient

	Field qObjectPtr:Byte Ptr

	Rem
	bbdoc: This is the default mode.
	about: The gradient coordinates are specified logical space just like the object coordinates.
	end rem
	Const LogicalMode:Int = 0
	Rem
	bbdoc: In this mode the gradient coordinates are relative to the bounding rectangle of the paint device, with (0,0) in the top left corner, and (1,1) in the bottom right corner of the paint device.
	end rem
	Const StretchToDeviceMode:Int = 1
	Rem
	bbdoc: In this mode the gradient coordinates are relative to the bounding rectangle of the object being drawn, with (0,0) in the top left corner, and (1,1) in the bottom right corner of the object's bounding rectangle.
	end rem
	Const ObjectBoundingMode:Int = 2
	Rem
	bbdoc: The area is filled with the closest stop color. This is the default.
	end rem
	Const PadSpread:Int = 0
	Rem
	bbdoc: The gradient is repeated outside the gradient area.
	end rem
	Const RepeatSpread:Int = 2
	Rem
	bbdoc: The gradient is reflected outside the gradient area.
	end rem
	Const ReflectSpread:Int = 1
	Rem
	bbdoc: Interpolates colors between start and end points (#QLinearGradient).
	End Rem
	Const LinearGradient:Int = 0
	Rem
	bbdoc: Interpolate colors between a focal point and end points on a circle surrounding it (#QRadialGradient).
	End Rem
	Const RadialGradient:Int = 1
	Rem
	bbdoc: Interpolate colors around a center point (#QConicalGradient).
	End Rem
	Const ConicalGradient:Int = 2
	Rem
	bbdoc: No gradient is used.
	end rem
	Const NoGradient:Int = 3

	Method coordinateMode:Int()
	' TODO
	End Method
	
	Method setColorAt(position:Double, color:QColor)
		bmx_qt_qgradient_setcolorat(qObjectPtr, position, color.qObjectPtr)
	End Method
	
	Method setCoordinateMode(Mode:Int)
	' TODO
	End Method
	
	Method setSpread(spread:Int)
	' TODO
	End Method
	
	Method setStops(stopPoints:QGradientStop[])
	' TODO
	End Method
	
	Method spread:Int()
	' TODO
	End Method
	
	Method stops:QGradientStop[]()
	' TODO
	End Method
	
	Method getType:Int()
	' TODO
	End Method

End Type

Type QConicalGradient Extends QGradient
	
	Function CreateConicalGradient:QConicalGradient(cx:Double, cy:Double, angle:Double)
	End Function
	
	Method Create:QConicalGradient(cx:Double, cy:Double, angle:Double)
	End Method

	Method angle:Double()
	' TODO
	End Method
	
	Method center(x:Double Var, y:Double Var)
	' TODO
	End Method
	
	Method setAngle(angle:Double)
	' TODO
	End Method
	
	Method setCenter(x:Double, y:Double)
	' TODO
	End Method

End Type

Type QLinearGradient Extends QGradient

	Function CreateLinearGradient:QLinearGradient(x1:Double, y1:Double, x2:Double, y2:Double)
	End Function
	
	Method Create:QLinearGradient(x1:Double, y1:Double, x2:Double, y2:Double)
	End Method

	Method finalStop(x:Double Var, y:Double Var) 
	' TODO
	End Method
	
	Method setFinalStop(x:Double, y:Double)
	' TODO
	End Method
	
	Method setStart(x:Double, y:Double)
	' TODO
	End Method
	
	Method start(x:Double Var, y:Double Var) 
	' TODO
	End Method

End Type

Type QRadialGradient Extends QGradient

	Function CreateRadialGradient:QRadialGradient(cx:Double, cy:Double, radius:Double, fx:Double, fy:Double)
		Return New QRadialGradient.Create(cx, cy, radius, fx, fy)
	End Function
	
	Method Create:QRadialGradient(cx:Double, cy:Double, radius:Double, fx:Double, fy:Double)
		qObjectPtr = bmx_qt_qradialgradient_create(cx, cy, radius, fx, fy)
		Return Self
	End Method
	
	Method center(x:Double Var, y:Double Var)
		bmx_qt_qradialgradient_center(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method focalPoint(x:Double Var, y:Double Var)
		bmx_qt_qradialgradient_focalpoint(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method radius:Double()
		Return bmx_qt_qradialgradient_radius(qObjectPtr)
	End Method
	
	Method setCenter(x:Double, y:Double)
		bmx_qt_qradialgradient_setcenter(qObjectPtr, x, y)
	End Method
	
	Method setFocalPoint(x:Double, y:Double)
		bmx_qt_qradialgradient_setfocalpoint(qObjectPtr, x, y)
	End Method
	
	Method setRadius(radius:Double)
		bmx_qt_qradialgradient_setradius(qObjectPtr, radius)
	End Method
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qradialgradient_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type

Type QGradientStop

	Field position:Double
	Field color:QColor

End Type

