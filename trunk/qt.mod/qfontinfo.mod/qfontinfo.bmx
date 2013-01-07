' Copyright (c) 2009-2013 Bruce A Henderson
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

Module Qt.QFontInfo

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QFontInfo

	Field qObjectPtr:Byte Ptr
	
	Function _create:QFontInfo(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QFontInfo = New QFontInfo
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreateFontInfo:QFontInfo(font:Qfont)
	End Function
	
	Method Create:QFontInfo(font:QFont)
		qObjectPtr = bmx_qt_qfontinfo_create(font.qObjectPtr)
		Return Self
	End Method
	
	Method bold:Int()
		Return bmx_qt_qfontinfo_bold(qObjectPtr)
	End Method
	
	Method exactMatch:Int()
		Return bmx_qt_qfontinfo_exactmatch(qObjectPtr)
	End Method
	
	Method family:String()
		Return bmx_qt_qfontinfo_family(qObjectPtr)
	End Method
	
	Method fixedPitch:Int()
		Return bmx_qt_qfontinfo_fixedpitch(qObjectPtr)
	End Method
	
	Method italic:Int()
		Return bmx_qt_qfontinfo_italic(qObjectPtr)
	End Method
	
	Method pixelSize:Int()
		Return bmx_qt_qfontinfo_pixelsize(qObjectPtr)
	End Method
	
	Method pointSize:Int()
		Return bmx_qt_qfontinfo_pointsize(qObjectPtr)
	End Method
	
	Method pointSizeF:Double()
		Return bmx_qt_qfontinfo_pointsizef(qObjectPtr)
	End Method
	
	Method rawMode:Int()
		Return bmx_qt_qfontinfo_rawmode(qObjectPtr)
	End Method
	
	Method style:Int()
		Return bmx_qt_qfontinfo_style(qObjectPtr)
	End Method
	
	Method styleHint:Int()
		Return bmx_qt_qfontinfo_stylehint(qObjectPtr)
	End Method
	
	Method styleName:String()
		Return bmx_qt_qfontinfo_stylename(qObjectPtr)
	End Method
	
	Method weight:Int()
		Return bmx_qt_qfontinfo_weight(qObjectPtr)
	End Method
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qfontinfo_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type

