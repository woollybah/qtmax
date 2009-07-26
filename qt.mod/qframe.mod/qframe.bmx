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

Module Qt.QFrame

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"



Type QFrame Extends QWidget

	Rem
	bbdoc: The frame and contents appear level with the surroundings.
	about: Draws using the palette QPalette::WindowText color (without any 3D effect)
	End Rem
	Const Shadow_Plain:Int = $0010
	Rem
	bbdoc: The frame and contents appear raised.
	about: Draws a 3D raised line using the light and dark colors of the current color group
	End Rem
	Const Shadow_Raised:Int = $0020
	Rem
	bbdoc: The frame and contents appear sunken.
	about: Draws a 3D sunken line using the light and dark colors of the current color group
	End Rem
	Const Shadow_Sunken:Int = $0030
	
	Rem
	bbdoc: QFrame draws nothing.
	End Rem
	Const Shape_NoFrame:Int = 0
	Rem
	bbdoc: QFrame draws a box around its contents.
	End Rem
	Const Shape_Box:Int = $0001
	Rem
	bbdoc: QFrame draws a panel to make the contents appear raised or sunken.
	End Rem
	Const Shape_Panel:Int = $0002
	Rem
	bbdoc: Draws a rectangular panel with a look that depends on the current GUI style.
	about: It can be raised or sunken.
	End Rem
	Const Shape_StyledPanel:Int = $0006
	Rem
	bbdoc: QFrame draws a horizontal line that frames nothing (useful as separator).
	End Rem
	Const Shape_HLine:Int = $0004
	Rem
	bbdoc: QFrame draws a vertical line that frames nothing (useful as separator).
	End Rem
	Const Shape_VLine:Int = $0005
	Rem
	bbdoc: Draws a rectangular panel that can be raised or sunken like those in Windows 95.
	about: Specifying this shape sets the line width to 2 pixels. WinPanel is provided for compatibility. For GUI style independence we recommend
	using StyledPanel instead.
	End Rem
	Const Shape_WinPanel:Int = $0003
	
	Rem
	bbdoc: The Shadow part of frameStyle().
	End Rem
	Const Shadow_Mask:Int = $00F0
	Rem
	bbdoc: The Shape part of frameStyle().
	End Rem
	Const Shape_Mask:Int = $000F

	Function CreateFrame:QFrame(parent:QWidget = Null, flags:Int = 0)
		Return New QFrame._Create(parent, flags)
	End Function

	Method _Create:QFrame(parent:QWidget = Null, flags:Int = 0)
		If parent Then
			qObjectPtr = bmx_qt_qframe_create(Self, parent.qObjectPtr, flags)
		Else
			qObjectPtr = bmx_qt_qframe_create(Self, Null, flags)
		End If
		OnInit()
		Return Self
	End Method
	
	Method frameRect(x:Int Var, y:Int Var, w:Int Var, h:Int Var)
		bmx_qt_qframe_framerect(qObjectPtr, Varptr x, Varptr y, Varptr w, Varptr h)
	End Method


	'Method frameRectRect:QRect()
	'	Return QRect._create(bmx_qt_qframe_framerectrect(qObjectPtr)
	'End Method
	
	Method frameShadow:Int()
		Return bmx_qt_qframe_frameshadow(qObjectPtr)
	End Method
	
	Method frameShape:Int()
		Return bmx_qt_qframe_frameshape(qObjectPtr)
	End Method
	
	Method frameStyle:Int()
		Return bmx_qt_qframe_framestyle(qObjectPtr)
	End Method
	
	Method frameWidth:Int()
		Return bmx_qt_qframe_framewidth(qObjectPtr)
	End Method
	
	Method lineWidth:Int()
		Return bmx_qt_qframe_linewidth(qObjectPtr)
	End Method
	
	Method midLineWidth:Int()
		Return bmx_qt_qframe_midlinewidth(qObjectPtr)
	End Method
	
	Method setFrameRect(x:Int, y:Int, w:Int, h:Int)
		bmx_qt_qframe_setframerect(qObjectPtr, x, y, w, h)
	End Method
	
	'Method setFrameRectRect(rect:QRect)
	'	bmx_qt_qframe_setframerectrect(qObjectPtr, rect.qObjectPtr)
	'End Method
	
	Method setFrameShadow(shadow:Int)
		bmx_qt_qframe_setframeshadow(qObjectPtr, shadow)
	End Method
	
	Method setFrameShape(shape:Int)
		bmx_qt_qframe_setframeshape(qObjectPtr, shape)
	End Method
	
	Method setFrameStyle(style:Int)
		bmx_qt_qframe_setframestyle(qObjectPtr, style)
	End Method
	
	Method SetLineWidth(width:Int)
		bmx_qt_qframe_setlinewidth(qObjectPtr, width)
	End Method
	
	Method setMidLineWidth(width:Int)
		bmx_qt_qframe_setmidlinewidth(qObjectPtr, width)
	End Method

	
End Type

