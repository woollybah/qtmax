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

Import Qt.Core
Import Qt.QObject
Import Qt.QUndoCommand
Import Qt.QWidget
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
Import "../src/include/QtGui/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qundostack_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qundostack_beginmacro(handle:Byte Ptr, text:String)
	Function bmx_qt_qundostack_canredo:Int(handle:Byte Ptr)
	Function bmx_qt_qundostack_canundo:Int(handle:Byte Ptr)
	Function bmx_qt_qundostack_cleanindex:Int(handle:Byte Ptr)
	Function bmx_qt_qundostack_clear(handle:Byte Ptr)
	Function bmx_qt_qundostack_command:Byte Ptr(handle:Byte Ptr, index:Int)
	Function bmx_qt_qundostack_count:Int(handle:Byte Ptr)
	Function bmx_qt_qundostack_createredoaction:Byte Ptr(handle:Byte Ptr, parent:Byte Ptr, prefix:String)
	Function bmx_qt_qundostack_createundoaction:Byte Ptr(handle:Byte Ptr, parent:Byte Ptr, prefix:String)
	Function bmx_qt_qundostack_endmacro(handle:Byte Ptr)
	Function bmx_qt_qundostack_index:Int(handle:Byte Ptr)
	Function bmx_qt_qundostack_isactive:Int(handle:Byte Ptr)
	Function bmx_qt_qundostack_isclean:Int(handle:Byte Ptr)
	Function bmx_qt_qundostack_push(handle:Byte Ptr, cmd:Byte Ptr)
	Function bmx_qt_qundostack_redotext:String(handle:Byte Ptr)
	Function bmx_qt_qundostack_setundolimit(handle:Byte Ptr, limit:Int)
	Function bmx_qt_qundostack_text:String(handle:Byte Ptr, idx:Int)
	Function bmx_qt_qundostack_undolimit:Int(handle:Byte Ptr)
	Function bmx_qt_qundostack_undotext:String(handle:Byte Ptr)
	Function bmx_qt_qundostack_redo(handle:Byte Ptr)
	Function bmx_qt_qundostack_setactive(handle:Byte Ptr, active:Int)
	Function bmx_qt_qundostack_setclean(handle:Byte Ptr)
	Function bmx_qt_qundostack_setindex(handle:Byte Ptr, idx:Int)
	Function bmx_qt_qundostack_undo(handle:Byte Ptr)

End Extern
