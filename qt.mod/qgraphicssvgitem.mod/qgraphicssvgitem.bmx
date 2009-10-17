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

Module Qt.QGraphicsSvgItem

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QGraphicsSvgItem Extends QGraphicsObjectItem

	Function CreateSvgItem:QGraphicsSvgItem(filename:String, parent:QGraphicsItem = Null)
		Return New QGraphicsSvgItem.Create(filename, parent)
	End Function

	Method Create:QGraphicsSvgItem(filename:String, parent:QGraphicsItem = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicssvgitem_create(Self, filename, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicssvgitem_create(Self, filename, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method boundingRect:QRectF()
		Return QRectF._create(bmx_qt_qgraphicssvgitem_boundingrect(qObjectPtr))
	End Method
	
	Method isSelected:Int()
		Return bmx_qt_qgraphicssvgitem_isselected(qObjectPtr)
	End Method
	
	Method isUnderMouse:Int()
		Return bmx_qt_qgraphicssvgitem_isundermouse(qObjectPtr)
	End Method
	
	Method isVisible:Int()
		Return bmx_qt_qgraphicssvgitem_isvisible(qObjectPtr)
	End Method
	
	Method isVisibleTo:Int(parent:QGraphicsItem)
		Return bmx_qt_qgraphicssvgitem_isvisibleto(qObjectPtr, parent.qObjectPtr)
	End Method
	
	Method isWidget:Int()
		Return bmx_qt_qgraphicssvgitem_iswidget(qObjectPtr)
	End Method
	
	Method isWindow:Int()
		Return bmx_qt_qgraphicssvgitem_iswindow(qObjectPtr)
	End Method

	Method setAcceptDrops(on:Int)
		bmx_qt_qgraphicssvgitem_setacceptdrops(qObjectPtr, on)
	End Method
	
	Method setAcceptHoverEvents(enabled:Int)
		bmx_qt_qgraphicssvgitem_setaccepthoverevents(qObjectPtr, enabled)
	End Method
	
	Method setAcceptedMouseButtons(buttons:Int)
		bmx_qt_qgraphicssvgitem_setacceptedmousebuttons(qObjectPtr, buttons)
	End Method
	
	Method setBoundingRegionGranularity(granularity:Double)
		bmx_qt_qgraphicssvgitem_setboundingregiongranularity(qObjectPtr, granularity)
	End Method
	
	Method setCacheMode(_mode:Int, w:Int = 0, h:Int = 0)
		bmx_qt_qgraphicssvgitem_setcachemode(qObjectPtr, _mode, w, h)
	End Method
	
	Method setCursor(cursor:QCursor)
		bmx_qt_qgraphicssvgitem_setcursor(qObjectPtr, cursor.qObjectPtr)
	End Method
	
	Method setData(key:Int, value:Object)
		bmx_qt_qgraphicssvgitem_setdata(qObjectPtr, key, value)
	End Method
	
	Method setEnabled(enabled:Int)
		bmx_qt_qgraphicssvgitem_setenabled(qObjectPtr, enabled)
	End Method
	
	Method setFlag(flag:Int, enabled:Int = True)
		bmx_qt_qgraphicssvgitem_setflag(qObjectPtr, flag, enabled)
	End Method
	
	Method setFlags(flags:Int)
		bmx_qt_qgraphicssvgitem_setflags(qObjectPtr, flags)
	End Method
	
	Method SetFocus(focusReason:Int = Qt_OtherFocusReason)
		bmx_qt_qgraphicssvgitem_setfocus(qObjectPtr, focusReason)
	End Method
	
	Method setGroup(group:QGraphicsItemGroup)
		bmx_qt_qgraphicssvgitem_setgroup(qObjectPtr, group.qObjectPtr)
	End Method
	
	Method setHandlesChildEvents(enabled:Int)
		bmx_qt_qgraphicssvgitem_sethandleschildevents(qObjectPtr, enabled)
	End Method
	
	Method setOpacity(opacity:Double)
		bmx_qt_qgraphicssvgitem_setopacity(qObjectPtr, opacity)
	End Method
	
	Method setParentItem(parent:QGraphicsItem)
		bmx_qt_qgraphicssvgitem_setparentitem(qObjectPtr, parent.qObjectPtr)
	End Method
	
	Method setPos(x:Double, y:Double)
		bmx_qt_qgraphicssvgitem_setpos(qObjectPtr, x, y)
	End Method
	
	Method setSelected(selected:Int)
		bmx_qt_qgraphicssvgitem_setselected(qObjectPtr, selected)
	End Method
	
	Method setToolTip(toolTip:String)
		bmx_qt_qgraphicssvgitem_settooltip(qObjectPtr, toolTip)
	End Method
	
	Method SetTransform(matrix:QTransform, combine:Int = False)
		bmx_qt_qgraphicssvgitem_settransform(qObjectPtr, matrix.qObjectPtr, combine)
	End Method
	
	Method setVisible(visible:Int)
		bmx_qt_qgraphicssvgitem_setvisible(qObjectPtr, visible)
	End Method
	
	Method setZValue(z:Double)
		bmx_qt_qgraphicssvgitem_setzvalue(qObjectPtr, z)
	End Method


	Method _addToScene(scene:Byte Ptr)
		bmx_qt_qgraphicssvgitem_addtoscene(qObjectPtr, scene)
	End Method
	
End Type
