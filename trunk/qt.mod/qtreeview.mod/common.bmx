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
Import Qt.QAbstractItemView
Import Qt.QHeaderView
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

	' QTreeView
	' QAbstractItemView
	' QAbstractScrollArea
	Function bmx_qt_qtreeview_default_scrollcontentsby(handle:Byte Ptr, dx:Int, dy:Int)
	Function bmx_qt_qtreeview_default_viewportevent:Int(handle:Byte Ptr, event:Byte Ptr)	
	' QFrame
	' QWidget
	Function bmx_qt_qtreeview_default_actionevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_changeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_closeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_contextmenuevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_dragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_dragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_dragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_dropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_enterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_focusinevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_focusnextchild:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_default_focusnextprevchild:Int(handle:Byte Ptr, _next:Int)
	Function bmx_qt_qtreeview_default_focusoutevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_focuspreviouschild:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_default_hideevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_inputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_keypressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_keyreleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_leaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_mousedoubleclickevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_mousemoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_mousepressevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_mousereleaseevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_moveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_paintevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_resizeevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_showevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_tabletevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_wheelevent(handle:Byte Ptr, event:Byte Ptr)
	' QObject
	Function bmx_qt_qtreeview_default_event:Int(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qtreeview_default_timerevent(handle:Byte Ptr, event:Byte Ptr)


	Function bmx_qt_qtreeview_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qtreeview_allcolumnsshowfocus:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_autoexpanddelay:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_columnat:Int(handle:Byte Ptr, x:Int)
	Function bmx_qt_qtreeview_columnviewportposition:Int(handle:Byte Ptr, column:Int)
	Function bmx_qt_qtreeview_columnwidth:Int(handle:Byte Ptr, column:Int)
	Function bmx_qt_qtreeview_expandsondoubleclick:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_header:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qtreeview_indentation:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_indexabove:Byte Ptr(handle:Byte Ptr, index:Byte Ptr)
	Function bmx_qt_qtreeview_indexbelow:Byte Ptr(handle:Byte Ptr, index:Byte Ptr)
	Function bmx_qt_qtreeview_isanimated:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_iscolumnhidden:Int(handle:Byte Ptr, column:Int)
	Function bmx_qt_qtreeview_isexpanded:Int(handle:Byte Ptr, index:Byte Ptr)
	Function bmx_qt_qtreeview_isfirstcolumnspanned:Int(handle:Byte Ptr, row:Int, parent:Byte Ptr)
	Function bmx_qt_qtreeview_isheaderhidden:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_isrowhidden:Int(handle:Byte Ptr, row:Int, parent:Byte Ptr)
	Function bmx_qt_qtreeview_issortingenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_itemsexpandable:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_rootisdecorated:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_setallcolumnsshowfocus(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qtreeview_setanimated(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qtreeview_setautoexpanddelay(handle:Byte Ptr, _delay:Int)
	Function bmx_qt_qtreeview_setcolumnhidden(handle:Byte Ptr, column:Int, hide:Int)
	Function bmx_qt_qtreeview_setcolumnwidth(handle:Byte Ptr, column:Int, width:Int)
	Function bmx_qt_qtreeview_setexpanded(handle:Byte Ptr, index:Byte Ptr, expanded:Int)
	Function bmx_qt_qtreeview_setexpandsondoubleclick(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qtreeview_setfirstcolumnspanned(handle:Byte Ptr, row:Int, parent:Byte Ptr, span:Int)
	Function bmx_qt_qtreeview_setheader(handle:Byte Ptr, header:Byte Ptr)
	Function bmx_qt_qtreeview_setheaderhidden(handle:Byte Ptr, hide:Int)
	Function bmx_qt_qtreeview_setindentation(handle:Byte Ptr, i:Int)
	Function bmx_qt_qtreeview_setitemsexpandable(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qtreeview_setrootisdecorated(handle:Byte Ptr, show:Int)
	Function bmx_qt_qtreeview_setrowhidden(handle:Byte Ptr, row:Int, parent:Byte Ptr, hide:Int)
	Function bmx_qt_qtreeview_setsortingenabled(handle:Byte Ptr, enable:Int)
	Function bmx_qt_qtreeview_setuniformrowheights(handle:Byte Ptr, uniform:Int)
	Function bmx_qt_qtreeview_setwordwrap(handle:Byte Ptr, on:Int)
	Function bmx_qt_qtreeview_sortbycolumn(handle:Byte Ptr, column:Int, order:Int)
	Function bmx_qt_qtreeview_uniformrowheights:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_wordwrap:Int(handle:Byte Ptr)
	Function bmx_qt_qtreeview_collapse(handle:Byte Ptr, index:Byte Ptr)
	Function bmx_qt_qtreeview_collapseall(handle:Byte Ptr)
	Function bmx_qt_qtreeview_expand(handle:Byte Ptr, index:Byte Ptr)
	Function bmx_qt_qtreeview_expandall(handle:Byte Ptr)
	Function bmx_qt_qtreeview_expandtodepth(handle:Byte Ptr, depth:Int)
	Function bmx_qt_qtreeview_hidecolumn(handle:Byte Ptr, column:Int)
	Function bmx_qt_qtreeview_resizecolumntocontents(handle:Byte Ptr, column:Int)
	Function bmx_qt_qtreeview_showcolumn(handle:Byte Ptr, column:Int)

End Extern


