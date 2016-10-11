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

Import "common.bmx"


Type QUrl

	Field qObjectPtr:Byte Ptr

	Function CreateUrl:QUrl(url:String = "")
		Return New QUrl.Create(url)
	End Function

	Method Create:QUrl(url:String = "")
		qObjectPtr = bmx_qt_qurl_create(url)
		Return Self
	End Method

	Function _create:QUrl(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QUrl = New QUrl
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Method toString:String()
		Return bmx_qt_qurl_tostring(qObjectPtr)
	End Method

	Method Free()
		If qObjectPtr Then
			bmx_qt_qurl_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

	Function _newArray:QUrl[](size:Int)
		Return New QUrl[size]
	End Function
	
	Function _setArray(arr:QUrl[], index:Int, url:Byte Ptr)
		arr[index] = _create(url)
	End Function

	Method Delete()
		Free()
	End Method
	
End Type


