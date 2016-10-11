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

Module Qt.QTextStream

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QTextStream

	Field qObjectPtr:Byte Ptr
	
	Function CreateTextStream:QTextStream(device:QIODevice)
		Return New QTextStream.Create(device)
	End Function
	
	Method Create:QTextStream(device:QIODevice)
		qObjectPtr = bmx_qt_qtextstream_create(device.qObjectPtr)
		Return Self
	End Method

	Method atEnd:Int()
	' TODO
	End Method
	
	Method autoDetectUnicode:Int()
	' TODO
	End Method

	Method fieldAlignment:Int()
	' TODO
	End Method
	
	Method fieldWidth:Int()
	' TODO
	End Method
	
	Method flush()
		bmx_qt_qtextstream_flush(qObjectPtr)
	End Method
	
	Method generateByteOrderMark:Int()
	' TODO
	End Method
	
	Method integerBase:Int()
	' TODO
	End Method
	
	Method locale:QLocale()
	' TODO
	End Method
	
	Method numberFlags:Int()
	' TODO
	End Method
	
	Method padChar:QChar()
	' TODO
	End Method
	
	Method pos:Long()
	' TODO
	End Method
	
	Method read:String(maxlen:Long)
	' TODO
	End Method
	
	Method readAll:String()
		Return bmx_qt_qtextstream_readall(qObjectPtr)
	End Method
	
	Method WriteString(text:String)
		bmx_qt_qtextstream_writestring(qObjectPtr, text)
	End Method
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qtextstream_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type