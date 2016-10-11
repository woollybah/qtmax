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

Module Qt.QFile

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QFile Extends QIODevice

	Field owner:Int

	Rem
	bbdoc: No options.
	End Rem
	Const MM_NoOptions:Int = 0

	Rem
	bbdoc: The file is readable by the owner of the file.
	end rem
	Const ReadOwner:Int = $4000
	Rem
	bbdoc: The file is writable by the owner of the file.
	end rem
	Const WriteOwner:Int = $2000
	Rem
	bbdoc: The file is executable by the owner of the file.
	end rem
	Const ExeOwner:Int = $1000
	Rem
	bbdoc: The file is readable by the user.
	end rem
	Const ReadUser:Int = $0400
	Rem
	bbdoc: The file is writable by the user.
	end rem
	Const WriteUser:Int = $0200
	Rem
	bbdoc: The file is executable by the user.
	end rem
	Const ExeUser:Int = $0100
	Rem
	bbdoc: The file is readable by the group.
	end rem
	Const ReadGroup:Int = $0040
	Rem
	bbdoc: The file is writable by the group.
	end rem
	Const WriteGroup:Int = $0020
	Rem
	bbdoc: The file is executable by the group.
	end rem
	Const ExeGroup:Int = $0010
	Rem
	bbdoc: The file is readable by anyone.
	end rem
	Const ReadOther:Int = $0004
	Rem
	bbdoc: The file is writable by anyone.
	end rem
	Const WriteOther:Int = $0002
	Rem
	bbdoc: The file is executable by anyone.
	end rem
	Const ExeOther:Int = $0001

	Function _create:QFile(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QFile = New QFile
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function CreateFile:QFile(name:String)
		Return New QFile.Create(name)
	End Function
	
	Method Create:QFile(name:String)
		qObjectPtr = bmx_qt_qfile_create(Self, name)
		owner = True
		Return Self
	End Method
	
	Method atEnd:Int()
		Return bmx_qt_qfile_atend(qObjectPtr)
	End Method
	
	Method close()
		bmx_qt_qfile_close(qObjectPtr)
	End Method
	
	Method copy:Int(newName:String)
		Return bmx_qt_qfile_copy(qObjectPtr, newName)
	End Method
	
	Method error:Int()
		Return bmx_qt_qfile_error(qObjectPtr)
	End Method
	
	Method exists:Int()
		Return bmx_qt_qfile_exists(qObjectPtr)
	End Method
	
	Method fileName:String()
		Return bmx_qt_qfile_filename(qObjectPtr)
	End Method
	
	Method flush:Int()
		Return bmx_qt_qfile_flush(qObjectPtr)
	End Method
	
	Method handle:Int()
		Return bmx_qt_qfile_handle(qObjectPtr)
	End Method
	
	Method isSequential:Int()
		Return bmx_qt_qfile_issequential(qObjectPtr)
	End Method
	
	Method link:Int(linkName:String)
		Return bmx_qt_qfile_link(qObjectPtr, linkName)
	End Method
	
	Method map:Byte Ptr(offset:Long, size:Long, flags:Int = MM_NoOptions)
		Return bmx_qt_qfile_map(qObjectPtr, offset, size, flags)
	End Method
	
	Method open:Int(Mode:Int)
		Return bmx_qt_qfile_open(qObjectPtr, Mode)
	End Method
	
	Method openHandle:Int(handle:Int, Mode:Int)
		Return bmx_qt_qfile_openhandle(qObjectPtr, handle, Mode)
	End Method
	
	Method permissions:Int()
		Return bmx_qt_qfile_permissions(qObjectPtr)
	End Method
	
	Method remove:Int()
		Return bmx_qt_qfile_remove(qObjectPtr)
	End Method
	
	Method rename:Int(newName:String)
		Return bmx_qt_qfile_rename(qObjectPtr, newName)
	End Method
	
	Method resize:Int(sz:Long)
		Return bmx_qt_qfile_resize(qObjectPtr, sz)
	End Method
	
	Method setFileName(name:String)
		bmx_qt_qfile_setfilename(qObjectPtr, name)
	End Method
	
	Method setPermissions:Int(permissions:Int)
		Return bmx_qt_qfile_setpermissions(qObjectPtr, permissions)
	End Method
	
	Method size:Long()
		Local s:Long
		bmx_qt_qfile_size(qObjectPtr, Varptr s)
		Return s
	End Method
	
	Method symLinkTarget:String()
		Return bmx_qt_qfile_symlinktarget(qObjectPtr)
	End Method
	
	Method unmap:Int(address:Byte Ptr)
		Return bmx_qt_qfile_unmap(qObjectPtr, address)
	End Method
	
	Method unsetError()
		bmx_qt_qfile_unseterror(qObjectPtr)
	End Method

	Method Free()
		If qObjectPtr And owner Then
			bmx_qt_qfile_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

	Method Delete()
		Free()
	End Method
	
End Type

