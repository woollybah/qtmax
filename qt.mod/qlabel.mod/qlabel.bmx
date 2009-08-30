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

Module Qt.QLabel

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QLabel Extends QFrame

	Function CreateLabel:QLabel(text:String, parent:QWidget = Null, flags:Int = 0)
		Return New QLabel.Create(text, parent, flags)
	End Function
	
	Method Create:QLabel(text:String, parent:QWidget = Null, flags:Int = 0)
		If parent Then
			qObjectPtr = bmx_qt_qlabel_create(Self, text, parent.qObjectPtr, flags)
		Else
			qObjectPtr = bmx_qt_qlabel_create(Self, text, Null, flags)
		End If
		OnInit()
		Return Self
	End Method

	Method alignment:Int()
		Return bmx_qt_qlabel_alignment(qObjectPtr)
	End Method
	
	Method buddy:QWidget()
		Return QWidget._find(bmx_qt_qlabel_buddy(qObjectPtr))
	End Method
	
	Method hasScaledContents:Int()
		Return bmx_qt_qlabel_hasscaledcontents(qObjectPtr)
	End Method
	
	Method indent:Int()
		Return bmx_qt_qlabel_indent(qObjectPtr)
	End Method
	
	Method margin:Int()
		Return bmx_qt_qlabel_margin(qObjectPtr)
	End Method
	
	'Method movie:QMovie()
	' TODO
	'End Method
	
	Method openExternalLinks:Int()
		Return bmx_qt_qlabel_openexternallinks(qObjectPtr)
	End Method
	
	'Method picture:QPicture()
	' TODO
	'End Method
	
	Method pixmap:QPixmap()
		Return QPixmap._create(bmx_qt_qlabel_pixmap(qObjectPtr))
	End Method
	
	Method setAlignment(alignment:Int)
		bmx_qt_qlabel_setalignment(qObjectPtr, alignment)
	End Method
	
	Method setBuddy(buddy:QWidget)
		If buddy Then
			bmx_qt_qlabel_setbuddy(qObjectPtr, buddy.qObjectPtr)
		Else
			bmx_qt_qlabel_setbuddy(qObjectPtr, Null)
		End If
	End Method
	
	Method setIndent(indent:Int)
		bmx_qt_qlabel_setindent(qObjectPtr, indent)
	End Method
	
	Method setMargin(margin:Int)
		bmx_qt_qlabel_setmargin(qObjectPtr, margin)
	End Method
	
	Method setOpenExternalLinks(open:Int)
		bmx_qt_qlabel_setopenexternallinks(qObjectPtr, open)
	End Method
	
	Method setScaledContents(scaled:Int)
		bmx_qt_qlabel_setscaledcontents(qObjectPtr, scaled)
	End Method
	
	Method setTextFormat(format:Int)
		bmx_qt_qlabel_settextformat(qObjectPtr, format)
	End Method
	
	Method setTextInteractionFlags(flags:Int)
		bmx_qt_qlabel_settextinteractionflags(qObjectPtr, flags)
	End Method
	
	Method setWordWrap(value:Int)
		bmx_qt_qlabel_setwordwrap(qObjectPtr, value)
	End Method
	
	Method text:String()
		Return bmx_qt_qlabel_text(qObjectPtr)
	End Method

	Method textFormat:Int()
		Return bmx_qt_qlabel_textformat(qObjectPtr)
	End Method

	Method textInteractionFlags:Int()
		Return bmx_qt_qlabel_textinteractionflags(qObjectPtr)
	End Method

	Method wordWrap:Int()
		Return bmx_qt_qlabel_wordwrap(qObjectPtr)
	End Method

	Method clear()
		bmx_qt_qlabel_clear(qObjectPtr)
	End Method
	
	'Method setMovie(movie:QMovie)
	' TODO
	'End Method

	Method setNum(num:Int)
		bmx_qt_qlabel_setnum(qObjectPtr, num)
	End Method

	Method setNumDouble(num:Double)
		bmx_qt_qlabel_setnumdouble(qObjectPtr, num)
	End Method

	'Method setPicture(picture:QPicture)
	' TODO
	'End Method

	Method setPixmap(pixmap:QPixmap)
		bmx_qt_qlabel_setpixmap(qObjectPtr, pixmap.qObjectPtr)
	End Method

	Method setText(text:String)
		bmx_qt_qlabel_settext(qObjectPtr, text)
	End Method

	' SIGNAL : linkActivated
	Function _OnLinkActivated(obj:QLabel, text:String)
		obj._InvokeSignals("linkActivated", [text])
	End Function

	' SIGNAL : linkHovered
	Function _OnLinkHovered(obj:QLabel, text:String)
		obj._InvokeSignals("linkHovered", [text])
	End Function

End Type

