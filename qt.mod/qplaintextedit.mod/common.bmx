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
Import Qt.QTextDocument
Import Qt.QMenu
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


	' QPlainTextEdit
	' QAbstractScrollArea
	Function bmx_qt_qplaintextedit_default_scrollcontentsby(handle:Byte Ptr, dx:Int, dy:Int)
	Function bmx_qt_qplaintextedit_default_viewportevent:Int(handle:Byte Ptr, event:Byte Ptr)	
	' QFrame
	' QWidget
	Function bmx_qt_qplaintextedit_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_focusnextchild:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_focusnextprevchild:Int(handle:Byte Ptr, _next:Int)
	Function bmx_qt_qplaintextedit_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_focuspreviouschild:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)
	' QObject
	Function bmx_qt_qplaintextedit_default_event:Int(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qplaintextedit_default_timerevent(handle:Byte Ptr, event:Byte Ptr)



	Function bmx_qt_qplaintextedit_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qplaintextedit_anchorat:String(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qplaintextedit_backgroundvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_blockcount:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_canpaste:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_centeronscroll:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_currentcharformat:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_cursorforposition:Byte Ptr(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qplaintextedit_cursorrectcursor(handle:Byte Ptr, cursor:Byte Ptr, x:Int Ptr, y:Int Ptr, width:Int Ptr, height:Int Ptr)
	Function bmx_qt_qplaintextedit_cursorrect(handle:Byte Ptr, x:Int Ptr, y:Int Ptr, width:Int Ptr, height:Int Ptr)
	Function bmx_qt_qplaintextedit_cursorwidth:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_documenttitle:String(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_ensurecursorvisible(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_find:Int(handle:Byte Ptr, expr:String, options:Int)
	Function bmx_qt_qplaintextedit_isreadonly:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_isundoredoenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_linewrapmode:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_maximumblockcount:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_mergecurrentcharformat(handle:Byte Ptr, modifier:Byte Ptr)
	Function bmx_qt_qplaintextedit_movecursor(handle:Byte Ptr, operation:Int, Mode:Int)
	Function bmx_qt_qplaintextedit_overwritemode:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_setbackgroundvisible(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qplaintextedit_setcenteronscrol(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qplaintextedit_setcurrentcharformat(handle:Byte Ptr, format:Byte Ptr)
	Function bmx_qt_qplaintextedit_setcursorwidth(handle:Byte Ptr, width:Int)
	Function bmx_qt_qplaintextedit_setdocument(handle:Byte Ptr, document:Byte Ptr)
	Function bmx_qt_qplaintextedit_setdocumenttitle(handle:Byte Ptr, title:String)
	Function bmx_qt_qplaintextedit_setlinewrapmode(handle:Byte Ptr, Mode:Int)
	Function bmx_qt_qplaintextedit_setmaximumblockcount(handle:Byte Ptr, maximum:Int)
	Function bmx_qt_qplaintextedit_setoverwritemode(handle:Byte Ptr, overwrite:Int)
	Function bmx_qt_qplaintextedit_setreadonly(handle:Byte Ptr, ro:Int)
	Function bmx_qt_qplaintextedit_settabchangesfocus(handle:Byte Ptr, value:Int)
	Function bmx_qt_qplaintextedit_settabstopwidth(handle:Byte Ptr, width:Int)
	Function bmx_qt_qplaintextedit_settextcursor(handle:Byte Ptr, cursor:Byte Ptr)
	Function bmx_qt_qplaintextedit_settextinteractionflags(handle:Byte Ptr, flags:Int)
	Function bmx_qt_qplaintextedit_setundoredoenabled(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qplaintextedit_setwordwrapmode(handle:Byte Ptr, policy:Int)
	Function bmx_qt_qplaintextedit_tabchangesfocus:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_tabstopwidth:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_textcursor:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_textinteractionflags:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_toplaintext:String(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_wordwrapmode:Int(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_appendhtml(handle:Byte Ptr, html:String)
	Function bmx_qt_qplaintextedit_appendplaintext(handle:Byte Ptr, text:String)
	Function bmx_qt_qplaintextedit_centercursor(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_clear(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_copy(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_cut(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_insertplaintext(handle:Byte Ptr, text:String)
	Function bmx_qt_qplaintextedit_paste(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_redo(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_selectall(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_setplaintext(handle:Byte Ptr, text:String)
	Function bmx_qt_qplaintextedit_undo(handle:Byte Ptr)
	Function bmx_qt_qplaintextedit_setviewportmargins(handle:Byte Ptr, _left:Int, _top:Int, _right:Int, _bottom:Int)

End Extern
