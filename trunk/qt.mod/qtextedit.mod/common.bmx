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
Import Qt.QAbstractScrollArea
Import Qt.QMenu
Import Qt.QFont
Import Qt.QTextDocument
Import Qt.QPrinter
Import Qt.QColor
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

	' QTextEdit
	' QAbstractScrollArea
	Function bmx_qt_qtextedit_default_scrollcontentsby(handle:Byte Ptr, dx:Int, dy:Int)
	Function bmx_qt_qtextedit_default_viewportevent:Int(handle:Byte Ptr, event:Byte Ptr)	
	' QFrame
	' QWidget
	Function bmx_qt_qtextedit_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_focusnextchild:Int(handle:Byte Ptr)
	Function bmx_qt_qtextedit_default_focusnextprevchild:Int(handle:Byte Ptr, _next:Int)
	Function bmx_qt_qtextedit_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_focuspreviouschild:Int(handle:Byte Ptr)
	Function bmx_qt_qtextedit_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)
	' QObject
	Function bmx_qt_qtextedit_default_event:Int(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtextedit_default_timerevent(handle:Byte Ptr, event:Byte Ptr)



	Function bmx_qt_qtextedit_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qtextedit_setreadonly(handle:Byte Ptr, value:Int)

	Function bmx_qt_qtextedit_append(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextedit_clear(handle:Byte Ptr)
	Function bmx_qt_qtextedit_copy(handle:Byte Ptr)
	Function bmx_qt_qtextedit_cut(handle:Byte Ptr)
	Function bmx_qt_qtextedit_inserthtml(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextedit_insertplaintext(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextedit_paste(handle:Byte Ptr)
	Function bmx_qt_qtextedit_redo(handle:Byte Ptr)
	Function bmx_qt_qtextedit_scrolltoanchor(handle:Byte Ptr, name:String)
	Function bmx_qt_qtextedit_selectall(handle:Byte Ptr)
	Function bmx_qt_qtextedit_setalignment(handle:Byte Ptr, a:Int)
	Function bmx_qt_qtextedit_setcurrentfont(handle:Byte Ptr, f:Byte Ptr)
	Function bmx_qt_qtextedit_setfontfamily(handle:Byte Ptr, fontFamily:String)
	Function bmx_qt_qtextedit_setfontitalic(handle:Byte Ptr, italic:Int)
	Function bmx_qt_qtextedit_setfontpointsize(handle:Byte Ptr, s:Double)
	Function bmx_qt_qtextedit_setfontunderline(handle:Byte Ptr, underline:Int)
	Function bmx_qt_qtextedit_setfontweight(handle:Byte Ptr, weight:Int)
	Function bmx_qt_qtextedit_sethtml(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextedit_setplaintext(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextedit_settext(handle:Byte Ptr, text:String)
	Function bmx_qt_qtextedit_settextbackgroundcolor(handle:Byte Ptr, c:Byte Ptr)
	Function bmx_qt_qtextedit_settextcolor(handle:Byte Ptr, c:Byte Ptr)
	Function bmx_qt_qtextedit_undo(handle:Byte Ptr)
	Function bmx_qt_qtextedit_zoomin(handle:Byte Ptr, _range:Int)
	Function bmx_qt_qtextedit_zoomout(handle:Byte Ptr, _range:Int)
	Function bmx_qt_qtextedit_setacceptrichtext(handle:Byte Ptr, accept:Int)
	Function bmx_qt_qtextedit_setautoformatting(handle:Byte Ptr, features:Int)
	Function bmx_qt_qtextedit_setcursorwidth(handle:Byte Ptr, width:Int)
	Function bmx_qt_qtextedit_setdocumenttitle(handle:Byte Ptr, title:String)
	Function bmx_qt_qtextedit_setlinewrapcolumnorwidth(handle:Byte Ptr, w:Int)
	Function bmx_qt_qtextedit_setlinewrapmode(handle:Byte Ptr, Mode:Int)

	Function bmx_qt_qtextedit_tohtml:String(handle:Byte Ptr)
	Function bmx_qt_qtextedit_toplaintext:String(handle:Byte Ptr)
	Function bmx_qt_qtextedit_document:Byte Ptr(handle:Byte Ptr)

End Extern
