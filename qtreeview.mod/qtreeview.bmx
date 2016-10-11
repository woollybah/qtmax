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

Module Qt.QTreeView

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QTreeView Extends QAbstractItemView

	Function CreateTreeView:QTreeView(parent:QWidget = Null)
		Return New QTreeView.Create(parent)
	End Function
	
	Method Create:QTreeView(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qtreeview_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qtreeview_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method allColumnsShowFocus:Int()
		Return bmx_qt_qtreeview_allcolumnsshowfocus(qObjectPtr)
	End Method
	
	Method autoExpandDelay:Int()
		Return bmx_qt_qtreeview_autoexpanddelay(qObjectPtr)
	End Method
	
	Method columnAt:Int(x:Int)
		Return bmx_qt_qtreeview_columnat(qObjectPtr, x)
	End Method
	
	Method columnViewportPosition:Int(column:Int)
		Return bmx_qt_qtreeview_columnviewportposition(qObjectPtr, column)
	End Method
	
	Method columnWidth:Int(column:Int)
		Return bmx_qt_qtreeview_columnwidth(qObjectPtr, column)
	End Method
	
	Method expandsOnDoubleClick:Int()
		Return bmx_qt_qtreeview_expandsondoubleclick(qObjectPtr)
	End Method
	
	Method header:QHeaderView()
		Return QHeaderView._find(bmx_qt_qtreeview_header(qObjectPtr))
	End Method
	
	Method indentation:Int()
		Return bmx_qt_qtreeview_indentation(qObjectPtr)
	End Method
	
	Method indexAbove:QModelIndex(index:QModelIndex)
		Return QModelIndex._create(bmx_qt_qtreeview_indexabove(qObjectPtr, index.qObjectPtr))
	End Method
	
	Method indexAt:QModelIndex(x:Int, y:Int)
		Return QModelIndex._create(bmx_qt_qtreeview_indexat(qObjectPtr, x, y))
	End Method
	
	Method indexBelow:QModelIndex(index:QModelIndex)
		Return QModelIndex._create(bmx_qt_qtreeview_indexbelow(qObjectPtr, index.qObjectPtr))
	End Method
	
	Method isAnimated:Int()
		Return bmx_qt_qtreeview_isanimated(qObjectPtr)
	End Method
	
	Method isColumnHidden:Int(column:Int)
		Return bmx_qt_qtreeview_iscolumnhidden(qObjectPtr, column)
	End Method
	
	Method isExpanded:Int(index:QModelIndex)
		Return bmx_qt_qtreeview_isexpanded(qObjectPtr, index.qObjectPtr)
	End Method
	
	Method isFirstColumnSpanned:Int(row:Int, parent:QModelIndex)
		Return bmx_qt_qtreeview_isfirstcolumnspanned(qObjectPtr, row, parent.qObjectPtr)
	End Method
	
	Method isHeaderHidden:Int()
		Return bmx_qt_qtreeview_isheaderhidden(qObjectPtr)
	End Method
	
	Method isRowHidden:Int(row:Int, parent:QModelIndex)
		Return bmx_qt_qtreeview_isrowhidden(qObjectPtr, row, parent.qObjectPtr)
	End Method
	
	Method isSortingEnabled:Int()
		Return bmx_qt_qtreeview_issortingenabled(qObjectPtr)
	End Method
	
	Method itemsExpandable:Int()
		Return bmx_qt_qtreeview_itemsexpandable(qObjectPtr)
	End Method
	
	Method rootIsDecorated:Int()
		Return bmx_qt_qtreeview_rootisdecorated(qObjectPtr)
	End Method
	
	Method setAllColumnsShowFocus(enable:Int)
		bmx_qt_qtreeview_setallcolumnsshowfocus(qObjectPtr, enable)
	End Method
	
	Method setAnimated(enable:Int)
		bmx_qt_qtreeview_setanimated(qObjectPtr, enable)
	End Method
	
	Method setAutoExpandDelay(_delay:Int)
		bmx_qt_qtreeview_setautoexpanddelay(qObjectPtr, _delay)
	End Method
	
	Method setColumnHidden(column:Int, hide:Int)
		bmx_qt_qtreeview_setcolumnhidden(qObjectPtr, column, hide)
	End Method
	
	Method setColumnWidth(column:Int, width:Int)
		bmx_qt_qtreeview_setcolumnwidth(qObjectPtr, column, width)
	End Method
	
	Method setExpanded(index:QModelIndex, expanded:Int)
		bmx_qt_qtreeview_setexpanded(qObjectPtr, index.qObjectPtr, expanded)
	End Method
	
	Method setExpandsOnDoubleClick(enable:Int)
		bmx_qt_qtreeview_setexpandsondoubleclick(qObjectPtr, enable)
	End Method
	
	Method setFirstColumnSpanned(row:Int, parent:QModelIndex, span:Int)
		bmx_qt_qtreeview_setfirstcolumnspanned(qObjectPtr, row, parent.qObjectPtr, span)
	End Method
	
	Method setHeader(header:QHeaderView)
		bmx_qt_qtreeview_setheader(qObjectPtr, header.qObjectPtr)
	End Method
	
	Method setHeaderHidden(hide:Int)
		bmx_qt_qtreeview_setheaderhidden(qObjectPtr, hide)
	End Method
	
	Method setIndentation(i:Int)
		bmx_qt_qtreeview_setindentation(qObjectPtr, i)
	End Method
	
	Method setItemsExpandable(enable:Int)
		bmx_qt_qtreeview_setitemsexpandable(qObjectPtr, enable)
	End Method
	
	Method setRootIsDecorated(show:Int)
		bmx_qt_qtreeview_setrootisdecorated(qObjectPtr, show)
	End Method
	
	Method setRowHidden(row:Int, parent:QModelIndex, hide:Int)
		bmx_qt_qtreeview_setrowhidden(qObjectPtr, row, parent.qObjectPtr, hide)
	End Method
	
	Method setSortingEnabled(enable:Int)
		bmx_qt_qtreeview_setsortingenabled(qObjectPtr, enable)
	End Method
	
	Method setUniformRowHeights(uniform:Int)
		bmx_qt_qtreeview_setuniformrowheights(qObjectPtr, uniform)
	End Method
	
	Method setWordWrap(on:Int)
		bmx_qt_qtreeview_setwordwrap(qObjectPtr, on)
	End Method
	
	Method sortByColumn(column:Int, order:Int)
		bmx_qt_qtreeview_sortbycolumn(qObjectPtr, column, order)
	End Method
	
	Method uniformRowHeights:Int()
		Return bmx_qt_qtreeview_uniformrowheights(qObjectPtr)
	End Method
	
	Method wordWrap:Int()
		Return bmx_qt_qtreeview_wordwrap(qObjectPtr)
	End Method
	
	Method collapse(index:QModelIndex)
		bmx_qt_qtreeview_collapse(qObjectPtr, index.qObjectPtr)
	End Method
	
	Method collapseAll()
		bmx_qt_qtreeview_collapseall(qObjectPtr)
	End Method
	
	Method expand(index:QModelIndex)
		bmx_qt_qtreeview_expand(qObjectPtr, index.qObjectPtr)
	End Method
	
	Method expandAll()
		bmx_qt_qtreeview_expandall(qObjectPtr)
	End Method
	
	Method expandToDepth(depth:Int)
		bmx_qt_qtreeview_expandtodepth(qObjectPtr, depth)
	End Method
	
	Method hideColumn(column:Int)
		bmx_qt_qtreeview_hidecolumn(qObjectPtr, column)
	End Method
	
	Method resizeColumnToContents(column:Int)
		bmx_qt_qtreeview_resizecolumntocontents(qObjectPtr, column)
	End Method
	
	Method showColumn(column:Int)
		bmx_qt_qtreeview_showcolumn(qObjectPtr, column)
	End Method



	' DEFAULT EVENT HANDLERS
	
	' QTreeView
	' QAbstractItemView
	' QAbstractScrollArea
	Method scrollContentsBy(dx:Int, dy:Int)
		bmx_qt_qtreeview_default_scrollcontentsby(qObjectPtr, dx, dy)
	End Method
	
	Method viewportEvent:Int(event:QEvent)
		Return bmx_qt_qtreeview_default_viewportevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	' QFrame
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qtreeview_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qtreeview_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qtreeview_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qtreeview_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qtreeview_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qtreeview_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qtreeview_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qtreeview_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qtreeview_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qtreeview_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qtreeview_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qtreeview_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qtreeview_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qtreeview_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qtreeview_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qtreeview_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qtreeview_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qtreeview_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qtreeview_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qtreeview_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qtreeview_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qtreeview_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qtreeview_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qtreeview_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qtreeview_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qtreeview_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qtreeview_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qtreeview_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qtreeview_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qtreeview_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qtreeview_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method


	' SIGNAL : collapsed
	Function _OnCollapsed(obj:QAbstractItemView, index:Byte Ptr)
		obj._InvokeSignals("collapsed", [QModelIndex._create(index)])
	End Function

	' SIGNAL : expanded
	Function _OnExpanded(obj:QAbstractItemView, index:Byte Ptr)
		obj._InvokeSignals("expanded", [QModelIndex._create(index)])
	End Function


End Type

