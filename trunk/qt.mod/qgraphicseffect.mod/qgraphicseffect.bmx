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

Module Qt.QGraphicsEffect

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QGraphicsEffect Extends QObject

	Rem
	bbdoc: The effect is installed on a source.
	End Rem
	Const SourceAttached:Int = $1
	Rem
	bbdoc: The effect is uninstalled on a source.
	End Rem
	Const SourceDetached:Int = $2
	Rem
	bbdoc: The bounding rect of the source has changed.
	End Rem
	Const SourceBoundingRectChanged:Int = $4
	Rem
	bbdoc: The visual appearance of the source has changed.
	End Rem
	Const SourceInvalidated:Int = $8

	Rem
	bbdoc: The pixmap should not receive any additional padding.
	End Rem
	Const NoPad:Int = 0
	Rem
	bbdoc: The pixmap should be padded to ensure it has a completely transparent border.
	End Rem
	Const PadToTransparentBorder:Int = 1
	Rem
	bbdoc: The pixmap should be padded to match the effective bounding rectangle of the effect.
	End Rem
	Const PadToEffectiveBoundingRect:Int = 2

	Function _create:QGraphicsEffect(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QGraphicsEffect = New QGraphicsEffect
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QGraphicsEffect(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QGraphicsEffect = QGraphicsEffect(qfind(qObjectPtr))
			If Not widget Then
				Return QGraphicsEffect._create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Method Create:QGraphicsEffect(parent:QObject = Null)
		If parent Then
			'qObjectPtr = bmx_qt_qgraphicseffect_create(Self, parent.qObjectPtr)
		Else
			'qObjectPtr = bmx_qt_qgraphicseffect_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method OnInit()
	End Method
	
End Type

