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
Import Qt.QPainter
Import Qt.QPalette
Import Qt.QStyle
Import Qt.QGraphicsSceneContextMenuEvent
Import Qt.QGraphicsSceneDragDropEvent
Import Qt.QGraphicsSceneHelpEvent
Import Qt.QGraphicsSceneMouseEvent
Import Qt.QGraphicsSceneWheelEvent
Import Qt.QCursor
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
	Function bmx_qt_qgraphicsview_createwithscene:Byte Ptr(handle:Object, scene:Byte Ptr, parent:Byte Ptr)
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
	Function bmx_qt_qgraphicsview_render(handle:Byte Ptr, painter:Byte Ptr, target:Byte Ptr, source:Byte Ptr, aspectRatioMode:Int)

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
	Function bmx_qt_qgraphicsscene_setbackgroundbrush(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qgraphicsscene_setbsptreedepth(handle:Byte Ptr, depth:Int)
	Function bmx_qt_qgraphicsscene_setfocus(handle:Byte Ptr, focusReason:Int)
	Function bmx_qt_qgraphicsscene_setfocusitem(handle:Byte Ptr, item:Byte Ptr, focusReason:Int)
	Function bmx_qt_qgraphicsscene_setfont(handle:Byte Ptr, font:Byte Ptr)
	Function bmx_qt_qgraphicsscene_setforegroundbrush(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_qt_qgraphicsscene_setitemindexmethod(handle:Byte Ptr, _method:Int)
	Function bmx_qt_qgraphicsscene_setpalette(handle:Byte Ptr, palette:Byte Ptr)
	Function bmx_qt_qgraphicsscene_setselectionarea(handle:Byte Ptr, path:Byte Ptr, _mode:Int)
	Function bmx_qt_qgraphicsscene_setsortcacheenabled(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicsscene_setstickyfocus(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicsscene_setstyle(handle:Byte Ptr, style:Byte Ptr)
	Function bmx_qt_qgraphicsscene_scenerect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_selectionarea:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_setactivewindow(handle:Byte Ptr, widget:Byte Ptr)
	Function bmx_qt_qgraphicsscene_width:Float(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_height:Float(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_udpate(handle:Byte Ptr, rect:Byte Ptr)
	Function bmx_qt_qgraphicsscene_hasfocus:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_itemat:Byte Ptr(handle:Byte Ptr, x:Float, y:Float)
	Function bmx_qt_qgraphicsscene_itemindexmethod:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_itemsboundingrect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_mousegrabberitem:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_palette:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsscene_removeitem(handle:Byte Ptr, item:Byte Ptr)

	Function bmx_qt_qgraphicsscene_defaultdrawbackground(handle:Byte Ptr, painter:Byte Ptr, rect:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultdrawforeground(handle:Byte Ptr, painter:Byte Ptr, rect:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultcontextmenuevent(handle:Byte Ptr, contextMenuEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultdragenterevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultdragleaveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultdragmoveevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultdropevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultfocusinevent(handle:Byte Ptr, focusEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultfocusoutevent(handle:Byte Ptr, focusEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaulthelpevent(handle:Byte Ptr, helpEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultinputmethodevent(handle:Byte Ptr, event:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultkeypressevent(handle:Byte Ptr, keyEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultkeyreleaseevent(handle:Byte Ptr, keyEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultmousedoubleclickevent(handle:Byte Ptr, mouseEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultmousemoveevent(handle:Byte Ptr, mouseEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultmousepressevent(handle:Byte Ptr, mouseEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultmousereleaseevent(handle:Byte Ptr, mouseEvent:Byte Ptr)
	Function bmx_qt_qgraphicsscene_defaultwheelevent(handle:Byte Ptr, wheelEvent:Byte Ptr)

	
	Function qgifind:Object(item:Byte Ptr)

	Function bmx_qt_qgraphicsitem_isselected:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_isundermouse:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_isvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_isvisibleto:Int(handle:Byte Ptr, parent:Byte Ptr)
	Function bmx_qt_qgraphicsitem_iswidget:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_iswindow:Int(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_setacceptdrops(handle:Byte Ptr, on:Int)
	Function bmx_qt_qgraphicsitem_setaccepthoverevents(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicsitem_setacceptedmousebuttons(handle:Byte Ptr, buttons:Int)
	Function bmx_qt_qgraphicsitem_setboundingregiongranularity(handle:Byte Ptr, granularity:Double)
	Function bmx_qt_qgraphicsitem_setcachemode(handle:Byte Ptr, _mode:Int, w:Int, h:Int)
	Function bmx_qt_qgraphicsitem_setcursor(handle:Byte Ptr, cursor:Byte Ptr)
	Function bmx_qt_qgraphicsitem_setdata(handle:Byte Ptr, key:Int, value:Object)
	Function bmx_qt_qgraphicsitem_setenabled(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicsitem_setflag(handle:Byte Ptr, flag:Int, enabled:Int)
	Function bmx_qt_qgraphicsitem_setflags(handle:Byte Ptr, flags:Int)
	Function bmx_qt_qgraphicsitem_setfocus(handle:Byte Ptr, focusReason:Int)
	Function bmx_qt_qgraphicsitem_setgroup(handle:Byte Ptr, group:Byte Ptr)
	Function bmx_qt_qgraphicsitem_sethandleschildevents(handle:Byte Ptr, enabled:Int)
	Function bmx_qt_qgraphicsitem_setopacity(handle:Byte Ptr, opacity:Double)
	Function bmx_qt_qgraphicsitem_setparentitem(handle:Byte Ptr, parent:Byte Ptr)
	Function bmx_qt_qgraphicsitem_setpos(handle:Byte Ptr, x:Double, y:Double)
	Function bmx_qt_qgraphicsitem_setselected(handle:Byte Ptr, selected:Int)
	Function bmx_qt_qgraphicsitem_settooltip(handle:Byte Ptr, toolTip:String)
	Function bmx_qt_qgraphicsitem_settransform(handle:Byte Ptr, matrix:Byte Ptr, combine:Int)
	Function bmx_qt_qgraphicsitem_setvisible(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qgraphicsitem_setzvalue(handle:Byte Ptr, z:Double)
	Function bmx_qt_qgraphicsitem_boundingrect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_addtoscene(handle:Byte Ptr, scene:Byte Ptr)
	Function bmx_qt_qgraphicsitem_pos(handle:Byte Ptr, x:Float Ptr, y:Float Ptr)
	Function bmx_qt_qgraphicsitem_removesceneeventfilter(handle:Byte Ptr, filterItem:Byte Ptr)
	Function bmx_qt_qgraphicsitem_resettransform(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_rotate(handle:Byte Ptr, angle:Float)
	Function bmx_qt_qgraphicsitem_scale(handle:Byte Ptr, sx:Float, sy:Float)
	Function bmx_qt_qgraphicsitem_scene:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_sceneboundingrect:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_scenepos(handle:Byte Ptr, x:Float Ptr, y:Float Ptr)
	Function bmx_qt_qgraphicsitem_scenetransform:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qgraphicsitem_scroll(handle:Byte Ptr, dx:Float, dy:Float, rect:Byte Ptr)

End Extern
