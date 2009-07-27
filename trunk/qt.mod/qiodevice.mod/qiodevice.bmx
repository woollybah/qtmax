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

Module Qt.QIODevice

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QIODevice Extends QObject

	Method atEnd:Int()
	' TODO
	End Method
	
	Method bytesAvailable:Long()
	' TODO
	End Method
	
	Method bytesToWrite:Long()
	' TODO
	End Method
	
	Method canReadLine:Int()
	' TODO
	End Method
	
	Method close()
	' TODO
	End Method
	
	Method errorString:String()
	' TODO
	End Method
	
	Method GetChar:Int(c:Int Var)
	' TODO
	End Method
	
	Method isOpen:Int()
	' TODO
	End Method
	
	Method isReadable:Int()
	' TODO
	End Method
	
	Method isSequential:Int()
	' TODO
	End Method
	
	Method isTextModeEnabled:Int()
	' TODO
	End Method
	
	Method isWritable:Int()
	' TODO
	End Method
	
	Method open:Int(Mode:Int)
	' TODO
	End Method
	
	Method openMode:Int()
	' TODO
	End Method
	
	Method peek:Long(data:Byte Ptr,  maxSize:Long)
	' TODO
	End Method
	
	'QByteArray peek(maxSize:long)
	' TODO
	'end method
	
	Method pos:Long()
	' TODO
	End Method
	
	Method putChar:Int(c:Int)
	' TODO
	End Method
	
	Method read:Long(data:Byte Ptr, maxSize:Long)
	' TODO
	End Method
	
	'QByteArray read(maxSize:long)
	' TODO
	'end method
	
	'QByteArray readAll()
	' TODO
	'end method
	
	Method ReadLine:Long(data:Byte Ptr, maxSize:Long)
	' TODO
	End Method
	
	'QByteArray readLine(maxSize:long = 0)
	' TODO
	'End Method
	
	Method reset:Int()
	' TODO
	End Method
	
	Method seek:Int(pos:Long)
	' TODO
	End Method
	
	Method setTextModeEnabled(enabled:Int)
	' TODO
	End Method
	
	Method size:Long()
	' TODO
	End Method
	
	Method ungetChar(c:int)
	' TODO
	End Method
	
	Method waitForBytesWritten:Int(msecs:Int)
	' TODO
	End Method
	
	Method waitForReadyRead:Int(msecs:Int)
	' TODO
	End Method
	
	Method write:Long(data:Byte Ptr, maxSize:Long)
	' TODO
	End Method
	
	'Method write:Long(data:Byte Ptr)
	' TODO
	'End Method

End Type

