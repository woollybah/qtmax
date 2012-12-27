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
Import Qt.QWidget
Import Qt.QMenu
Import Qt.QValidator
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

	' QLineEdit
	' QWidget
	Function bmx_qt_qlineedit_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_focusnextchild:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_default_focusnextprevchild:Int(handle:Byte Ptr, _next:Int)
	Function bmx_qt_qlineedit_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_focuspreviouschild:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)
	' QObject
	Function bmx_qt_qlineedit_default_event:Int(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qlineedit_default_timerevent(handle:Byte Ptr, event:Byte Ptr)



	Function bmx_qt_qlineedit_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qlineedit_setreadonly(handle:Byte Ptr, value:Int)
	Function bmx_qt_qlineedit_text:String(handle:Byte Ptr)

	Function bmx_qt_qlineedit_clear(handle:Byte Ptr)
	Function bmx_qt_qlineedit_copy(handle:Byte Ptr)
	Function bmx_qt_qlineedit_cut(handle:Byte Ptr)
	Function bmx_qt_qlineedit_paste(handle:Byte Ptr)
	Function bmx_qt_qlineedit_redo(handle:Byte Ptr)
	Function bmx_qt_qlineedit_selectall(handle:Byte Ptr)
	Function bmx_qt_qlineedit_settext(handle:Byte Ptr, text:String)

	Function bmx_qt_qlineedit_undo(handle:Byte Ptr)
	
	Function bmx_qt_qlineedit_alignment:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_backspace(handle:Byte Ptr)
	Function bmx_qt_qlineedit_cursorbackward(handle:Byte Ptr, mark:Int, steps:Int)
	Function bmx_qt_qlineedit_cursorforward(handle:Byte Ptr, mark:Int, steps:Int)
	Function bmx_qt_qlineedit_cursorposition:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_cursorpositionat:Int(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qlineedit_cursorwordbackward(handle:Byte Ptr, mark:Int)
	Function bmx_qt_qlineedit_cursorwordforward(handle:Byte Ptr, mark:Int)
	Function bmx_qt_qlineedit_del(handle:Byte Ptr)
	Function bmx_qt_qlineedit_deselect(handle:Byte Ptr)
	Function bmx_qt_qlineedit_displaytext:String(handle:Byte Ptr)
	Function bmx_qt_qlineedit_dragenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_echomode:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_toend(handle:Byte Ptr, mark:Int)
	Function bmx_qt_qlineedit_gettextmargins(handle:Byte Ptr, _left:Int Ptr, _top:Int Ptr, _right:Int Ptr, _bottom:Int Ptr)
	Function bmx_qt_qlineedit_hasacceptableinput:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_hasframe:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_hasselectedtext:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_home(handle:Byte Ptr, mark:Int)
	Function bmx_qt_qlineedit_inputmask:String(handle:Byte Ptr)
	Function bmx_qt_qlineedit_insert(handle:Byte Ptr, newText:String)
	Function bmx_qt_qlineedit_ismodified:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_isreadonly:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_isredoavailable:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_isundoavailable:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_maxlength:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_minimumsizehint(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qlineedit_selectedtext:String(handle:Byte Ptr)
	Function bmx_qt_qlineedit_selectionstar:Int(handle:Byte Ptr)
	Function bmx_qt_qlineedit_setalignment(handle:Byte Ptr, flag:Int)
	Function bmx_qt_qlineedit_setcursorposition(handle:Byte Ptr, pos:Int)
	Function bmx_qt_qlineedit_setdragenabled(handle:Byte Ptr, b:Int)
	Function bmx_qt_qlineedit_setechomode(handle:Byte Ptr, Mode:Int)
	Function bmx_qt_qlineedit_setframe(handle:Byte Ptr, frame:Int)
	Function bmx_qt_qlineedit_setinputmask(handle:Byte Ptr, inputMask:String)
	Function bmx_qt_qlineedit_setmaxlength(handle:Byte Ptr, length:Int)
	Function bmx_qt_qlineedit_setmodified(handle:Byte Ptr, value:Int)
	Function bmx_qt_qlineedit_setselection(handle:Byte Ptr, start:Int, length:Int)
	Function bmx_qt_qlineedit_settextmargins(handle:Byte Ptr, _left:Int, _top:Int, _right:Int, _bottom:Int)
	Function bmx_qt_qlineedit_sizehint(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)

	Function bmx_qt_qlineedit_setvalidator(handle:Byte Ptr, v:Byte Ptr)

End Extern
