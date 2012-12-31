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
Import Qt.QAbstractItemModel
Import Qt.QStyleOptionViewItem
Import Qt.QPainter
Import Qt.QHelpEvent
Import Qt.QItemSelectionModel
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

	' QAbstractItemView
	' QAbstractScrollArea
	Function bmx_qt_qabstractitemview_default_scrollcontentsby(handle:Byte Ptr, dx:Int, dy:Int)
	Function bmx_qt_qabstractitemview_default_viewportevent:Int(handle:Byte Ptr, event:Byte Ptr)	
	' QFrame
	' QWidget
	Function bmx_qt_qabstractitemview_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_focusnextchild:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_focusnextprevchild:Int(handle:Byte Ptr, _next:Int)
	Function bmx_qt_qabstractitemview_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_focuspreviouschild:Int(handle:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)
	' QObject
	Function bmx_qt_qabstractitemview_default_event:Int(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qabstractitemview_default_timerevent(handle:Byte Ptr, event:Byte Ptr)



	Function bmx_qt_qabstractitemview_setmodel(handle:Byte Ptr, model:Byte Ptr)
	Function bmx_qt_qabstractitemview_clearselection(handle:Byte Ptr)
	Function bmx_qt_qabstractitemview_scrollto(handle:Byte Ptr, index:Byte Ptr, hint:Int)
	Function bmx_qt_qabstractitemview_scrolltobottom(handle:Byte Ptr)
	Function bmx_qt_qabstractitemview_scrolltotop(handle:Byte Ptr)
	Function bmx_qt_qabstractitemview_selectall(handle:Byte Ptr)
	Function bmx_qt_qabstractitemview_setcurrentindex(handle:Byte Ptr, index:Byte Ptr)
	Function bmx_qt_qabstractitemview_update(handle:Byte Ptr, index:Byte Ptr)
	Function bmx_qt_qabstractitemview_setselectionmodel(handle:Byte Ptr, model:Byte Ptr)
	Function bmx_qt_qabstractitemview_setselectionmode(handle:Byte Ptr, Mode:Int)

End Extern
