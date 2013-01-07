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

Import Qt.Core
Import Qt.QIODevice
Import BRL.Blitz


' headers :-)
?win32
Import "../lib/win32/include/*.h"
?macos
Import "../lib/macos/include/*.h"
?Not linux
Import "../src/include/*.h"
Import "../src/include/Qt/*.h"
Import "../src/include/QtCore/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/QtCore/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qfile_create:Byte Ptr(handle:Object, name:String)
	Function bmx_qt_qfile_free(handle:Byte Ptr)

	Function bmx_qt_qfile_atend:Int(handle:Byte Ptr)
	Function bmx_qt_qfile_close(handle:Byte Ptr)
	Function bmx_qt_qfile_copy:Int(handle:Byte Ptr, newName:String)
	Function bmx_qt_qfile_error:Int(handle:Byte Ptr)
	Function bmx_qt_qfile_exists:Int(handle:Byte Ptr)
	Function bmx_qt_qfile_filename:String(handle:Byte Ptr)
	Function bmx_qt_qfile_flush:Int(handle:Byte Ptr)
	Function bmx_qt_qfile_handle:Int(handle:Byte Ptr)
	Function bmx_qt_qfile_issequential:Int(handle:Byte Ptr)
	Function bmx_qt_qfile_link:Int(handle:Byte Ptr, linkName:String)
	Function bmx_qt_qfile_map:Byte Ptr(handle:Byte Ptr, offset:Long, size:Long, flags:Int)
	Function bmx_qt_qfile_open:Int(handle:Byte Ptr, Mode:Int)
	Function bmx_qt_qfile_openhandle:Int(handle:Byte Ptr, h:Int, Mode:Int)
	Function bmx_qt_qfile_permissions:Int(handle:Byte Ptr)
	Function bmx_qt_qfile_remove:Int(handle:Byte Ptr)
	Function bmx_qt_qfile_rename:Int(handle:Byte Ptr, newName:String)
	Function bmx_qt_qfile_resize:Int(handle:Byte Ptr, sz:Long)
	Function bmx_qt_qfile_setfilename(handle:Byte Ptr, name:String)
	Function bmx_qt_qfile_setpermissions:Int(handle:Byte Ptr, permissions:Int)
	Function bmx_qt_qfile_size(handle:Byte Ptr, s:Long Ptr)
	Function bmx_qt_qfile_symlinktarget:String(handle:Byte Ptr)
	Function bmx_qt_qfile_unmap:Int(handle:Byte Ptr, address:Byte Ptr)
	Function bmx_qt_qfile_unseterror(handle:Byte Ptr)


End Extern
