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

	Function _create:QWebDatabase(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWebDatabase = New QWebDatabase
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method displayName:String()
		Return bmx_qt_qwebdatabase_displayname(qObjectPtr)
	End Method
	
	Method expectedSize:Long()
		Local value:Long
		bmx_qt_qwebdatabase_expectedsize(qObjectPtr, Varptr value)
		Return value
	End Method
	
	Method fileName:String()
		Return bmx_qt_qwebdatabase_filename(qObjectPtr)
	End Method
	
	Method name:String()
		Return bmx_qt_qwebdatabase_name(qObjectPtr)
	End Method
	
	Method origin:QWebSecurityOrigin()
		Return QWebSecurityOrigin._create(bmx_qt_qwebdatabase_origin(qObjectPtr))
	End Method
	
	Method size:Long()
		Local value:Long
		bmx_qt_qwebdatabase_size(qObjectPtr, Varptr value)
		Return value
	End Method
	
	Method Delete()
		If qObjectPtr Then
			bmx_qt_qwebdatabase_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

End Type

Type QWebSecurityOrigin

	Field qObjectPtr:Byte Ptr

	Function _create:QWebSecurityOrigin(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWebSecurityOrigin = New QWebSecurityOrigin
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method databaseQuota:Long()
		Local value:Long
		bmx_qt_qwebsecurityorigin_databasequota(qObjectPtr, Varptr value)
		Return value
	End Method
	
	Method databaseUsage:Long()
		Local value:Long
		bmx_qt_qwebsecurityorigin_databaseusage(qObjectPtr, Varptr value)
		Return value
	End Method
	
	Method databases:QWebDatabase[]()
	' TODO
	End Method
	
	Method host:String()
		Return bmx_qt_qwebsecurityorigin_host(qObjectPtr)
	End Method
	
	Method port:Int()
		Return bmx_qt_qwebsecurityorigin_port(qObjectPtr)
	End Method
	
	Method scheme:String()
		Return bmx_qt_qwebsecurityorigin_scheme(qObjectPtr)
	End Method
	
	Method setDatabaseQuota(quota:Long)
		bmx_qt_qwebsecurityorigin_setdatabasequota(qObjectPtr, quota)
	End Method
	
	Method Delete()
		If qObjectPtr Then
			bmx_qt_qwebsecurityorigin_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
End Type

