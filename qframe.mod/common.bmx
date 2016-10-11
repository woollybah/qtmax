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

	' QFrame
	' QWidget
	Function bmx_qt_qframe_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_focusnextchild:Int(handle:Byte Ptr)
	Function bmx_qt_qframe_default_focusnextprevchild:Int(handle:Byte Ptr, _next:Int)
	Function bmx_qt_qframe_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_focuspreviouschild:Int(handle:Byte Ptr)
	Function bmx_qt_qframe_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)
	' QObject
	Function bmx_qt_qframe_default_event:Int(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qframe_default_timerevent(handle:Byte Ptr, event:Byte Ptr)



	Function bmx_qt_qframe_create:Byte Ptr(handle:Object, parent:Byte Ptr, flags:Int)
	Function bmx_qt_qframe_framerect(handle:Byte Ptr, x:Int Ptr, y:Int Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qframe_frameshadow:Int(handle:Byte Ptr)
	Function bmx_qt_qframe_frameshape:Int(handle:Byte Ptr)
	Function bmx_qt_qframe_framestyle:Int(handle:Byte Ptr)
	Function bmx_qt_qframe_framewidth:Int(handle:Byte Ptr)
	Function bmx_qt_qframe_linewidth:Int(handle:Byte Ptr)
	Function bmx_qt_qframe_midlinewidth:Int(handle:Byte Ptr)
	Function bmx_qt_qframe_setframerect(handle:Byte Ptr, x:Int, y:Int, w:Int, h:Int)
	Function bmx_qt_qframe_setframeshadow(handle:Byte Ptr, shadow:Int)
	Function bmx_qt_qframe_setframeshape(handle:Byte Ptr, shape:Int)
	Function bmx_qt_qframe_setframestyle(handle:Byte Ptr, style:Int)
	Function bmx_qt_qframe_setlinewidth(handle:Byte Ptr, width:Int)
	Function bmx_qt_qframe_setmidlinewidth(handle:Byte Ptr, width:Int)

End Extern
