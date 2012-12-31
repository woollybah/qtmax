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

Module Qt.QFontDialog

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QFontDialog Extends QDialog

	Function getFont:QFont(ok:Int Var, parent:QWidget = Null)
		If parent Then
			Return QFont._create(bmx_qt_qfontdialog_getfont(Varptr ok, parent.qObjectPtr))
		Else
			Return QFont._create(bmx_qt_qfontdialog_getfont(Varptr ok, Null))
		End If
	End Function
	
	Function getFontWithInitial:QFont(ok:Int Var, initial:QFont, parent:QWidget = Null)
		If parent Then
			Return QFont._create(bmx_qt_qfontdialog_getfontwithinitial(Varptr ok, initial.qObjectPtr, parent.qObjectPtr))
		Else
			Return QFont._create(bmx_qt_qfontdialog_getfontwithinitial(Varptr ok, initial.qObjectPtr, Null))
		End If
	End Function

	Function getFontWithOptions:QFont(ok:Int Var, initial:QFont, parent:QWidget, title:String, options:Int)
		Return QFont._create(bmx_qt_qfontdialog_getfontwithoptions(Varptr ok, initial.qObjectPtr, parent.qObjectPtr, title, options))
	End Function
	
End Type
