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

Module Qt.QFileInfo

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QFileInfo

	Field qObjectPtr:Byte Ptr
	
	Function CreateFileInfo:QFileInfo(file:Object)
		Return New QFileInfo.Create(file)
	End Function
	
	Method Create:QFileInfo(file:Object)
		If String(file) Then
			qObjectPtr = bmx_qt_qfileinfo_create(String(file))
		ElseIf QFile(file) Then
			qObjectPtr = bmx_qt_qfileinfo_createfile(QFile(file).qObjectPtr)
		Else ' empty string?
			qObjectPtr = bmx_qt_qfileinfo_create("")
		End If
		Return Self
	End Method
	
	Method absoluteFilePath:String()
		Return bmx_qt_qfileinfo_absolutefilepath(qObjectPtr)
	End Method
	
	Method absolutePath:String()
		Return bmx_qt_qfileinfo_absolutepath(qObjectPtr)
	End Method
	
	Method baseName:String()
		Return bmx_qt_qfileinfo_basename(qObjectPtr)
	End Method
	
	Method bundleName:String()
		Return bmx_qt_qfileinfo_bundlename(qObjectPtr)
	End Method
	
	Method caching:Int()
		Return bmx_qt_qfileinfo_caching(qObjectPtr)
	End Method
	
	Method canonicalFilePath:String()
		Return bmx_qt_qfileinfo_canonicalfilepath(qObjectPtr)
	End Method
	
	Method canonicalPath:String()
		Return bmx_qt_qfileinfo_canonicalpath(qObjectPtr)
	End Method
	
	Method completeBaseName:String()
		Return bmx_qt_qfileinfo_completebasename(qObjectPtr)
	End Method
	
	Method completeSuffix:String()
		Return bmx_qt_qfileinfo_completesuffix(qObjectPtr)
	End Method
	
	'Method created:QDateTime()
	'	Return QDateTime._create(bmx_qt_qfileinfo_created(qObjectPtr))
	'End Method
	
	'Method dir:QDir()
	'	Return QDir._create(bmx_qt_qfileinfo_dir(qObjectPtr))
	'End Method
	
	Method exists:Int()
		Return bmx_qt_qfileinfo_exists(qObjectPtr)
	End Method
	
	Method fileName:String()
		Return bmx_qt_qfileinfo_filename(qObjectPtr)
	End Method
	
	Method filePath:String()
		Return bmx_qt_qfileinfo_filepath(qObjectPtr)
	End Method
	
	Method group:String()
		Return bmx_qt_qfileinfo_group(qObjectPtr)
	End Method
	
	Method groupId:Int()
		Return bmx_qt_qfileinfo_groupid(qObjectPtr)
	End Method
	
	Method isAbsolute:Int()
		Return bmx_qt_qfileinfo_isabsolute(qObjectPtr)
	End Method
	
	Method isBundle:Int()
		Return bmx_qt_qfileinfo_isbundle(qObjectPtr)
	End Method
	
	Method isDir:Int()
		Return bmx_qt_qfileinfo_isdir(qObjectPtr)
	End Method
	
	Method isExecutable:Int()
		Return bmx_qt_qfileinfo_isexecutable(qObjectPtr)
	End Method
	
	Method isFile:Int()
		Return bmx_qt_qfileinfo_isfile(qObjectPtr)
	End Method
	
	Method isHidden:Int()
		Return bmx_qt_qfileinfo_ishidden(qObjectPtr)
	End Method
	
	Method isReadable:Int()
		Return bmx_qt_qfileinfo_isreadable(qObjectPtr)
	End Method
	
	Method isRelative:Int()
		Return bmx_qt_qfileinfo_isrelative(qObjectPtr)
	End Method
	
	Method isRoot:Int()
		Return bmx_qt_qfileinfo_isroot(qObjectPtr)
	End Method
	
	Method isSymLink:Int()
		Return bmx_qt_qfileinfo_issymlink(qObjectPtr)
	End Method
	
	Method isWritable:Int()
		Return bmx_qt_qfileinfo_iswritable(qObjectPtr)
	End Method
	

	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qfileinfo_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type
