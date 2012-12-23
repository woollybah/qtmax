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

Module Qt.QColorDialog

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QColorDialog Extends QDialog


	Function GetColorWithOptions:QColor(initial:QColor, parent:QWidget, title:String, options:Int = 0 )
		Return QColor._Create(bmx_qt_qcolordialog_getcolorwithoptions(initial.qObjectPtr, parent.qObjectPtr, title, options))
	End Function
	
	Function GetColor:QColor(initial:QColor = Null, parent:QWidget = Null )
		If initial Then
			If parent Then
				Return QColor._Create(bmx_qt_qcolordialog_getcolor(initial.qObjectPtr, parent.qObjectPtr))
			Else
				Return QColor._Create(bmx_qt_qcolordialog_getcolor(initial.qObjectPtr, Null))
			End If
		Else
			If parent Then
				Return QColor._Create(bmx_qt_qcolordialog_getcolor(Null, parent.qObjectPtr))
			Else
				Return QColor._Create(bmx_qt_qcolordialog_getcolor(Null, Null))
			End If
		End If
	End Function

End Type
