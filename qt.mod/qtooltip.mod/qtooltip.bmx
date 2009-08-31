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

Module Qt.QToolTip

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QToolTip

	Function font:QFont()
		Return QFont._create(bmx_qt_qtooltip_font())
	End Function

	Function hideText()
		bmx_qt_qtooltip_hidetext()
	End Function

	Function isVisible:Int()
		Return bmx_qt_qtooltip_isvisible()
	End Function

	Function palette:QPalette()
		Return QPalette._create(bmx_qt_qtooltip_palette())
	End Function

	Function setFont(font:QFont)
		bmx_qt_qtooltip_setfont(font.qObjectPtr)
	End Function

	Function setPalette(palette:QPalette)
		bmx_qt_qtooltip_setpalette(palette.qObjectPtr)
	End Function

	Function showText(x:Int, y:Int, text:String, w:QWidget = Null, rect:QRect = Null)
		If w Then
			If rect Then
				bmx_qt_qtooltip_showtext(x, y, text, w.qObjectPtr, rect.qObjectPtr)
			Else
				bmx_qt_qtooltip_showtext(x, y, text, w.qObjectPtr, Null)
			End If
		Else
			If Not rect Then
				bmx_qt_qtooltip_showtext(x, y, text, Null, Null)
			Else
				Assert True, "widget required with rect"
			End If
		End If
	End Function

End Type
