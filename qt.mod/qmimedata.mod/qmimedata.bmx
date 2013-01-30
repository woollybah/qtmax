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

Module Qt.QMimeData

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QMimeData Extends QObject

	Function _create:QMimeData(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QMimeData = New QMimeData
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QMimeData(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local data:QMimeData = QMimeData(qfind(qObjectPtr))
			If Not data Then
				Return QMimeData._create(qObjectPtr)
			End If
			Return data
		End If
	End Function

	Method clear()
	End Method
	
	Method colorData:QColor()
	End Method
	
	Method formats:String[]()
	End Method
	
	Method hasColor:Int()
	End Method
	
	Method hasFormat:Int(mimeType:String)
	End Method

	'Method data:QByteArray()
	' TODO
	'End Method
	
	Method hasHtml:Int()
	' TODO
	End Method
	
	Method hasImage:Int()
	' TODO
	End Method
	
	Method hasText:Int()
	' TODO
	End Method
	
	Method hasUrls:Int()
		Return bmx_qt_qmimedata_hasurls(qObjectPtr)
	End Method
	
	Method html:String()
	' TODO
	End Method
	
	Method imageData:QImage()
	' TODO
	End Method
	
	Method removeFormat(mimeType:String)
	' TODO
	End Method
	
	Method setColorData(color:QColor)
	' TODO
	End Method
	
	'Method setData(mimeType, data:QByteArray)
	' TODO
	'End Method
	
	Method setHtml(html:String)
	' TODO
	End Method
	
	Method setImageData(image:QImage)
	' TODO
	End Method
	
	Method setText(text:String)
	' TODO
	End Method
	
	Method setUrls(urls:String[])
	' TODO
	End Method
	
	Method text:String()
	' TODO
	End Method
	
	Method urls:QUrl[]()
		Return bmx_qt_qmimedata_urls(qObjectPtr)
	End Method

End Type

