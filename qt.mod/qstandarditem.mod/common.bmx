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
Import Qt.QIcon
Import Qt.QBrush
Import Qt.QAbstractItemModel
Import BRL.Blitz
Import BRL.LinkedList
Import BRL.Map


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

	Function bmx_qt_qstandarditem_create:Byte Ptr(handle:Object)
	Function bmx_qt_qstandarditem_casttoobj:Object(o:Byte Ptr)


	Function bmx_qt_qstandarditem_accessibledescription:String(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_accessibletext:String(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_appendrow(handle:Byte Ptr, item:Byte Ptr)
	Function bmx_qt_qstandarditem_checkstate:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_column:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_columncount:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_data:Object(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_flags:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_haschildren:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_insertrow(handle:Byte Ptr, row:Int, item:Byte Ptr)
	Function bmx_qt_qstandarditem_insertrows(handle:Byte Ptr, row:Int, count:Int)
	Function bmx_qt_qstandarditem_ischeckable:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_isdragenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_isdropenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_iseditable:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_isenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_isselectable:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_istristate:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_removecolumn(handle:Byte Ptr, column:Int)
	Function bmx_qt_qstandarditem_removecolumns(handle:Byte Ptr, column:Int, count:Int)
	Function bmx_qt_qstandarditem_removerow(handle:Byte Ptr, row:Int)
	Function bmx_qt_qstandarditem_removerows(handle:Byte Ptr, row:Int, count:Int)
	Function bmx_qt_qstandarditem_row:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_rowcount:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_setaccessibledescription(handle:Byte Ptr, accessibleDescription:String)
	Function bmx_qt_qstandarditem_setaccessibletext(handle:Byte Ptr, accessibleText:String)
	Function bmx_qt_qstandarditem_setcheckstate(handle:Byte Ptr, state:Int)
	Function bmx_qt_qstandarditem_setcheckable(handle:Byte Ptr, checkable:Int)
	Function bmx_qt_qstandarditem_setchildrc(handle:Byte Ptr, row:Int, column:Int, item:Byte Ptr)
	Function bmx_qt_qstandarditem_setchild(handle:Byte Ptr, row:Int, item:Byte Ptr)
	Function bmx_qt_qstandarditem_setcolumncount(handle:Byte Ptr, columns:Int)
	Function bmx_qt_qstandarditem_setdata(handle:Byte Ptr, value:Object)
	Function bmx_qt_qstandarditem_setdragenabled(handle:Byte Ptr, dragEnabled:Int)
	Function bmx_qt_qstandarditem_setdropenabled(handle:Byte Ptr, dropEnabled:Int)
	Function bmx_qt_qstandarditem_seteditable(handle:Byte Ptr, editable:Int)
	Function bmx_qt_qstandarditem_setenabled(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qstandarditem_setflags(handle:Byte Ptr, flags:Int)
	Function bmx_qt_qstandarditem_setrowcount(handle:Byte Ptr, rows:Int)
	Function bmx_qt_qstandarditem_setselectable(handle:Byte Ptr, selectable:Int)
	Function bmx_qt_qstandarditem_setsizehint(handle:Byte Ptr, width:Int, height:Int)
	Function bmx_qt_qstandarditem_setstatustip(handle:Byte Ptr, statustip:String)
	Function bmx_qt_qstandarditem_settext(handle:Byte Ptr, text:String)
	Function bmx_qt_qstandarditem_settextalignment(handle:Byte Ptr, alignment:Int)
	Function bmx_qt_qstandarditem_settooltip(handle:Byte Ptr, toolTip:String)
	Function bmx_qt_qstandarditem_settristate(handle:Byte Ptr, tristate:Int)
	Function bmx_qt_qstandarditem_setwhatsthis(handle:Byte Ptr, whatsThis:String)
	Function bmx_qt_qstandarditem_statustip:String(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_text:String(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_textalignment:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_tooltip:String(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_type:Int(handle:Byte Ptr)
	Function bmx_qt_qstandarditem_whatsthis:String(handle:Byte Ptr)

End Extern
