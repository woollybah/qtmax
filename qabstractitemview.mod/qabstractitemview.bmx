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

Module Qt.QAbstractItemView

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QAbstractItemView Extends QAbstractScrollArea

	Rem
	bbdoc: Scroll to ensure that the item is visible.
	End Rem
	Const Hint_EnsureVisible:Int = 0
	Rem
	bbdoc: Scroll to position the item at the top of the viewport.
	End Rem
	Const Hint_PositionAtTop:Int = 1
	Rem
	bbdoc: Scroll to position the item at the bottom of the viewport.
	End Rem
	Const Hint_PositionAtBottom:Int = 2
	Rem
	bbdoc: Scroll to position the item at the center of the viewport.
	End Rem
	Const Hint_PositionAtCenter:Int = 3
	
	Rem
	bbdoc: When the user selects an item, any already-selected item becomes unselected, and the user cannot unselect the selected item by clicking on it.
	End Rem
	Const Mode_SingleSelection:Int = 1
	Rem
	bbdoc: When the user selects an item in the usual way, the selection is cleared and the new item selected.
	about: However, if the user presses the Shift key while clicking on an item, all items between the current item
	and the clicked item are selected or unselected, depending on the state of the clicked item.
	End Rem
	Const Mode_ContiguousSelection:Int = 4
	Rem
	bbdoc: When the user selects an item in the usual way, the selection is cleared and the new item selected.
	about: However, if the user presses the Ctrl key when clicking on an item, the clicked item gets toggled and all other
	items are left untouched. If the user presses the Shift key while clicking on an item, all items between the current
	item and the clicked item are selected or unselected, depending on the state of the clicked item. Multiple items can be
	selected by dragging the mouse over them.
	End Rem
	Const Mode_ExtendedSelection:Int = 3
	Rem
	bbdoc: When the user selects an item in the usual way, the selection status of that item is toggled and the other items are left alone.
	about: Multiple items can be toggled by dragging the mouse over them.
	End Rem
	Const Mode_MultiSelection:Int = 2
	Rem
	bbdoc: Items cannot be selected.
	End Rem
	Const Mode_NoSelection:Int = 0
	
	
	
	Rem
	bbdoc: Deselects all selected items.
	about: The current index will not be changed.
	End Rem
	Method clearSelection()
		bmx_qt_qabstractitemview_clearselection(qObjectPtr)
	End Method
	
	Method currentIndex:QModelIndex()
		Return QModelIndex._create(bmx_qt_qabstractitemview_currentindex(qObjectPtr))
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method scrollTo(index:QModelIndex, hint:Int = Hint_EnsureVisible)
		bmx_qt_qabstractitemview_scrollto(qObjectPtr, index.qObjectPtr, hint)
	End Method
	
	Rem
	bbdoc: Scrolls the view to the bottom.
	End Rem
	Method scrollToBottom()
		bmx_qt_qabstractitemview_scrolltobottom(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Scrolls the view to the top.
	End Rem
	Method scrollToTop()
		bmx_qt_qabstractitemview_scrolltotop(qObjectPtr)
	End Method
	
	Rem
	bbdoc: Selects all items in the view.
	about: This method will use the selection behavior set on the view when selecting.
	End Rem
	Method selectAll()
		bmx_qt_qabstractitemview_selectall(qObjectPtr)
	End Method

	Rem
	bbdoc: Sets the current item to be the item at index.
	about: Unless the current selection mode is NoSelection, the item is also be selected.
	Note that this method also updates the starting position for any new selections the user performs.
	End Rem
	Method setCurrentIndex(index:QModelIndex)
		bmx_qt_qabstractitemview_setcurrentindex(qObjectPtr, index.qObjectPtr)
	End Method

	Rem
	bbdoc: 
	End Rem
	Method setModel(model:QAbstractItemModel)
		bmx_qt_qabstractitemview_setmodel(qObjectPtr, model.qObjectPtr)
	End Method
	
	Rem
	bbdoc: Sets which selection mode the view operates in.
	End Rem
	Method setSelectionMode(Mode:Int)
		bmx_qt_qabstractitemview_setselectionmode(qObjectPtr, Mode)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method setSelectionModel(model:QItemSelectionModel)
		bmx_qt_qabstractitemview_setselectionmodel(qObjectPtr, model.qObjectPtr)
	End Method
	
	Rem
	bbdoc: Updates the area occupied by the given index.
	End Rem
	Method updateView(index:QModelIndex)
		bmx_qt_qabstractitemview_update(qObjectPtr, index.qObjectPtr)
	End Method


	' DEFAULT EVENT HANDLERS
	
	' QAbstractItemView
	' QAbstractScrollArea
	Method scrollContentsBy(dx:Int, dy:Int)
		bmx_qt_qabstractitemview_default_scrollcontentsby(qObjectPtr, dx, dy)
	End Method
	
	Method viewportEvent:Int(event:QEvent)
		Return bmx_qt_qabstractitemview_default_viewportevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	' QFrame
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qabstractitemview_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qabstractitemview_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qabstractitemview_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qabstractitemview_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qabstractitemview_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qabstractitemview_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qabstractitemview_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qabstractitemview_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qabstractitemview_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qabstractitemview_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qabstractitemview_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qabstractitemview_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qabstractitemview_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qabstractitemview_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qabstractitemview_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qabstractitemview_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qabstractitemview_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qabstractitemview_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qabstractitemview_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qabstractitemview_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qabstractitemview_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qabstractitemview_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qabstractitemview_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qabstractitemview_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qabstractitemview_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qabstractitemview_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qabstractitemview_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qabstractitemview_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qabstractitemview_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qabstractitemview_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qabstractitemview_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method




	' SIGNAL : activated
	Function _OnActivated(obj:QAbstractItemView, index:Byte Ptr)
		obj._InvokeSignals("activated", [QModelIndex._create(index)])
	End Function

	' SIGNAL : clicked
	Function _OnClicked(obj:QAbstractItemView, index:Byte Ptr)
		obj._InvokeSignals("clicked", [QModelIndex._create(index)])
	End Function

	' SIGNAL : doubleClicked
	Function _OnDoubleClicked(obj:QAbstractItemView, index:Byte Ptr)
		obj._InvokeSignals("doubleClicked", [QModelIndex._create(index)])
	End Function

	' SIGNAL : entered
	Function _OnEntered(obj:QAbstractItemView, index:Byte Ptr)
		obj._InvokeSignals("entered", [QModelIndex._create(index)])
	End Function

	' SIGNAL : pressed
	Function _OnPressed(obj:QAbstractItemView, index:Byte Ptr)
		obj._InvokeSignals("pressed", [QModelIndex._create(index)])
	End Function

	' SIGNAL : viewportEntered
	Function _OnViewportEntered(obj:QAbstractItemView)
		obj._InvokeSignals("viewportEntered", Null)
	End Function


End Type

Type QAbstractItemDelegate Extends QObject

	Method createEditorQWidget(parent:QWidget, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	
	Method editorEvent:Int(event:QEvent, model:QAbstractItemModel, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	
	Method paint(painter:QPainter, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	
	Method setEditorData(editor:QWidget, index:QModelIndex)
	End Method
	
	Method setModelData(editor:QWidget, model:QAbstractItemModel, index:QModelIndex)
	End Method
	
	Method sizeHint(option:QStyleOptionViewItem, index:QModelIndex, w:Int Var, h:Int Var)
	End Method
	
	Method updateEditorGeometry(editor:QWidget, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	

	Method helpEvent:Int(event:QHelpEvent, view:QAbstractItemView, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	
End Type

