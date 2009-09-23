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

Module Qt.QFontComboBox

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QFontComboBox Extends QComboBox

	Function CreateFontComboBox:QFontComboBox(parent:QWidget = Null)
		Return New QFontComboBox.Create(parent)
	End Function
	
	Method Create:QFontComboBox(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qfontcombobox_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qfontcombobox_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method currentFont:QFont()
		Return QFont._create(bmx_qt_qfontcombobox_currentfont(qObjectPtr))
	End Method
	
	Method fontFilters:Int()
		Return bmx_qt_qfontcombobox_fontfilters(qObjectPtr)
	End Method
	
	Method setFontFilters(filters:Int)
		bmx_qt_qfontcombobox_setfontfilters(qObjectPtr, filters)
	End Method
	
	Method setWritingSystem(script:Int)
		bmx_qt_qfontcombobox_setwritingsystem(qObjectPtr, script)
	End Method
	
	Method writingSystem:Int()
		Return bmx_qt_qfontcombobox_writingsystem(qObjectPtr)
	End Method

	Method setCurrentFont(font:QFont)
		bmx_qt_qfontcombobox_setcurrentfont(qObjectPtr, font.qObjectPtr)
	End Method

	' SIGNAL : currentFontChanged
	Function _OnCurrentFontChanged(obj:QFontComboBox, font:QFont)
		obj._InvokeSignals("currentFontChanged", [font])
	End Function

End Type

