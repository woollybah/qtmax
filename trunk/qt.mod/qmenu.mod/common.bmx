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
Import "/usr/include/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
Import "/usr/include/QtGui/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_qt_qmenu_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qmenu_createwithtitle:Byte Ptr(handle:Object, title:String, parent:Byte Ptr)
	Function bmx_qt_qmenu_free(handle:Byte Ptr)

	Function bmx_qt_qmenu_actionat:Byte Ptr(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qmenu_actiongeometry:Byte Ptr(handle:Byte Ptr, act:Byte Ptr)
	Function bmx_qt_qmenu_activeaction:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmenu_addaction(handle:Byte Ptr, action:Byte Ptr)
	Function bmx_qt_qmenu_addactiontxt:Byte Ptr(handle:Byte Ptr, action:String)
	Function bmx_qt_qmenu_addmenuaction:Byte Ptr(handle:Byte Ptr, menu:Byte Ptr)
	Function bmx_qt_qmenu_addmenu:Byte Ptr(handle:Byte Ptr, title:String)
	Function bmx_qt_qmenu_addseparator:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmenu_clear(handle:Byte Ptr)
	Function bmx_qt_qmenu_defaultaction:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmenu_exec:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmenu_execaction:Byte Ptr(handle:Byte Ptr, x:Int, y:Int, action:Byte Ptr)
	Function bmx_qt_qmenu_hidetearoffmenu(handle:Byte Ptr)
	Function bmx_qt_qmenu_insertmenu:Byte Ptr(handle:Byte Ptr, before:Byte Ptr, menu:Byte Ptr)
	Function bmx_qt_qmenu_insertseparator:Byte Ptr(handle:Byte Ptr, before:Byte Ptr)
	Function bmx_qt_qmenu_isempty:Int(handle:Byte Ptr)
	Function bmx_qt_qmenu_istearoffenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qmenu_istearoffmenuvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qmenu_menuaction:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qmenu_popup(handle:Byte Ptr, x:Int, y:Int, atAction:Byte Ptr)
	Function bmx_qt_qmenu_separatorscollapsible:Int(handle:Byte Ptr)
	Function bmx_qt_qmenu_setactiveaction(handle:Byte Ptr, act:Byte Ptr)
	Function bmx_qt_qmenu_setdefaultaction(handle:Byte Ptr, act:Byte Ptr)
	'Function bmx_qt_qmenu_seticon(handle:Byte Ptr, icon:Byte Ptr)
	Function bmx_qt_qmenu_setseparatorscollapsible(handle:Byte Ptr, collapse:Int)
	Function bmx_qt_qmenu_settearoffenabled(handle:Byte Ptr, value:Int)
	Function bmx_qt_qmenu_settitle(handle:Byte Ptr, title:String)
	Function bmx_qt_qmenu_title:String(handle:Byte Ptr)

End Extern
