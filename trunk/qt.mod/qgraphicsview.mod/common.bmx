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
Import Qt.QAbstractScrollArea
Import Qt.QBrush
Import Qt.QGraphicsItem
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

	Function bmx_qt_qgraphicsview_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qgraphicsview_setalignment(handle:Byte Ptr, alignment:Int)
	Function bmx_qt_qgraphicsview_setbackgroundbrush(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qgraphicsview_setcachemode(handle:Byte Ptr, _mode:Int)
	Function bmx_qt_qgraphicsview_setdragmode(handle:Byte Ptr, _mode:Int)
	Function bmx_qt_qgraphicsview_setforegroundbrush(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qgraphicsview_setinteractive(handle:Byte Ptr, allowed:Int)
	Function bmx_qt_qgraphicsview_setmatrix(handle:Byte Ptr, matrix:Byte Ptr, combine:Int)
	Function bmx_qt_qgraphicsview_setoptimizationflag(handle:Byte Ptr, flag:Int, enabled:Int)
	Function bmx_qt_qgraphicsview_setoptimizationflags(handle:Byte Ptr, flags:Int)
	Function bmx_qt_qgraphicsview_setrenderhint(handle:Byte Ptr, hint:Int, enabled:Int)
	Function bmx_qt_qgraphicsview_setrenderhints(handle:Byte Ptr, hints:Int)
	Function bmx_qt_qgraphicsview_setresizeanchor(handle:Byte Ptr, anchor:Int)
	Function bmx_qt_qgraphicsview_setrubberbandselectionmode(handle:Byte Ptr, _mode:Int)
	Function bmx_qt_qgraphicsview_setscene(handle:Byte Ptr, scene:Byte Ptr)
	Function bmx_qt_qgraphicsview_setscenerectrect(handle:Byte Ptr, rect:Byte Ptr)
	Function bmx_qt_qgraphicsview_setscenerect(handle:Byte Ptr, x:Double, y:Double, w:Double, h:Double)
	Function bmx_qt_qgraphicsview_settransform(handle:Byte Ptr, matrix:Byte Ptr, combine:Int)
	Function bmx_qt_qgraphicsview_settransformationanchor(handle:Byte Ptr, anchor:Int)
	Function bmx_qt_qgraphicsview_scale(handle:Byte Ptr, sx:Double, sy:Double)
	Function bmx_qt_qgraphicsview_scene:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsview_scenerect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsview_resetcachedcontent(handle:Byte Ptr)
	Function bmx_qt_qgraphicsview_resetmatrix(handle:Byte Ptr)
	Function bmx_qt_qgraphicsview_resettransform(handle:Byte Ptr)
	Function bmx_qt_qgraphicsview_alignment:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsview_backgroundbrush:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsview_cachemode:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsview_sizehint(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)

	Function bmx_qt_qgraphicsview_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsview_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)

	Function bmx_qt_qgraphicsscene_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_setscenerect(handle:Byte Ptr, rect:Byte Ptr)
	Function bmx_qt_qgraphicsscene_advance(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_clear(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_clearselection(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_additem(handle:Byte Ptr, item:Byte Ptr)

End Extern
