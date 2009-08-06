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

Module Qt.QBoxLayout

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QBoxLayout Extends QLayout

	Rem
	bbdoc: Horizontal from left to right.
	end rem
	Const LeftToRight:Int = 0
	Rem
	bbdoc: Horizontal from right to left.
	end rem
	Const RightToLeft:Int = 1
	Rem
	bbdoc: Vertical from top to bottom.
	end rem
	Const TopToBottom:Int = 2
	Rem
	bbdoc: Vertical from bottom to top.
	end rem
	Const BottomToTop:Int = 3
	
	Function CreateBoxLayout:QBoxLayout(parent:QWidget = Null)
		Return New QBoxLayout.Create(parent)
	End Function

	Method Create:QBoxLayout(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qboxlayout_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qboxlayout_create(Self, Null)
		End If
		Return Self
	End Method
	
	Method CreateLayout:QBoxLayout(dir:Int, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qboxlayout_createlayout(Self, dir, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qboxlayout_createlayout(Self, dir, Null)
		End If
		Return Self
	End Method
	
	Method addWidget(widget:QWidget, stretch:Int = 0, alignment:Int = 0)
		bmx_qt_qboxlayout_addwidget(qObjectPtr, widget.qObjectPtr, stretch, alignment)
	End Method
	
	Method addStretch(stretch:Int = 0)
		bmx_qt_qboxlayout_addstretch(qObjectPtr, stretch)
	End Method
	
End Type

