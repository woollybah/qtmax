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

Module Qt.QGraphicsBlurEffect

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QGraphicsBlurEffect Extends QGraphicsEffect

	Rem
	bbdoc: Indicates that rendering performance is the most important factor, at the potential cost of lower quality.
	End Rem
	Const PerformanceHint:Int = $0
	Rem
	bbdoc: Indicates that rendering quality is the most important factor, at the potential cost of lower performance.
	End Rem
	Const QualityHint:Int = $1
	Rem
	bbdoc: Indicates that the blur radius is going to be animated, hinting that the implementation can keep a cache of blurred verisons of the source.
	about: Do not use this hint if the source is going to be dynamically changing.
	End Rem
	Const AnimationHint:Int = $2

	Function CreateGraphicsBlurEffect:QGraphicsBlurEffect(parent:QObject = Null)
		Return New QGraphicsBlurEffect.Create(parent)
	End Function

	Rem
	bbdoc: 
	End Rem
	Method Create:QGraphicsBlurEffect(parent:QObject = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicsblureffect_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicsblureffect_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method blurHints:Int()
		Return bmx_qt_qgraphicsblureffect_blurhints(qObjectPtr)
	End Method
	
	Method blurRadius:Double()
		Return bmx_qt_qgraphicsblureffect_blurradius(qObjectPtr)
	End Method
	
	Method setBlurHints(hints:Int)
		bmx_qt_qgraphicsblureffect_setblurhints(qObjectPtr, hints)
	End Method
	
	Method setBlurRadius(radius:Double)
		bmx_qt_qgraphicsblureffect_setblurradius(qObjectPtr, radius)
	End Method
	
	Method draw(painter:QPainter)
		bmx_qt_qgraphicsblureffect_default_draw(qObjectPtr, painter.qObjectPtr)
	End Method
	
	Function _draw(obj:QGraphicsBlurEffect, painter:Byte Ptr)
		obj.draw(QPainter._create(painter))
	End Function
	
	Method boundingRect:QRectF()
		Return QRectF._create(bmx_qt_qgraphicsblureffect_default_boundingrect(qObjectPtr))
	End Method
	
	Function _boundingRect:Byte Ptr(obj:QGraphicsBlurEffect)
		Return obj.boundingRect().qObjectPtr
	End Function

	' SIGNAL : blurHintsChanged
	Function _OnBlurHintsChanged(obj:QGraphicsBlurEffect, hints:Int)
		obj._InvokeSignals("blurHintsChanged", [String(hints)])
	End Function

	' SIGNAL : blurRadiusChanged
	Function _OnBlurRadiusChanged(obj:QGraphicsBlurEffect, radius:Double)
		obj._InvokeSignals("blurRadiusChanged", [String(radius)])
	End Function

	' SIGNAL : enabledChanged
	Function _OnEnabledChanged(obj:QGraphicsBlurEffect, enabled:Int)
		obj._InvokeSignals("enabledChanged", [String(enabled)])
	End Function
	
End Type

