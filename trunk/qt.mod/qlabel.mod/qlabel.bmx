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
	End Method
	
	Method buddy:QWidget()
	End Method
	
	Method hasScaledContents:Int()
	End Method
	
	Method indent:Int()
	End Method
	
	Method margin:Int()
	End Method
	
	'Method movie:QMovie()
	'End Method
	
	Method openExternalLinks:Int()
	End Method
	
	'Method picture:QPicture()
	'End Method
	
	'Method pixmap:QPixmap()
	'End Method
	
	Method setAlignment(alignment:Int)
	End Method
	
	Method setBuddy(buddy:QWidget)
	End Method
	
	Method setIndent(indent:Int)
	End Method
	
	Method setMargin(margin:Int)
	End Method
	
	Method setOpenExternalLinks(open:Int)
	End Method
	
	Method setScaledContents(scaled:Int)
	End Method
	
	Method setTextFormat(format:Int)
	End Method
	
	Method setTextInteractionFlags(flags:Int)
	End Method
	
	Method setWordWrap(on:Int)
	End Method
	
	Method text:String()
	End Method
	

End Type

