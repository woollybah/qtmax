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

Module Qt.QWebDatabase

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QWebDatabase

	Field qObjectPtr:Byte Ptr

	Method displayName:String()
	' TODO
	End Method
	
	Method expectedSize:Long()
	' TODO
	End Method
	
	Method fileName:String()
	' TODO
	End Method
	
	Method name:String()
	' TODO
	End Method
	
	Method origin:QWebSecurityOrigin()
	' TODO
	End Method
	
	Method size:Long()
	' TODO
	End Method

End Type

Type QWebSecurityOrigin

	Field qObjectPtr:Byte Ptr

	Method databaseQuota:Long()
	' TODO
	End Method
	
	Method databaseUsage:Long()
	' TODO
	End Method
	
	Method databases:QWebDatabase[]()
	' TODO
	End Method
	
	Method host:String()
	' TODO
	End Method
	
	Method port:Int()
	' TODO
	End Method
	
	Method scheme:String()
	' TODO
	End Method
	
	Method setDatabaseQuota(quota:Long)
	' TODO
	End Method
	
End Type

