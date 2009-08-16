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

Module Qt.QGraphicsItem

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QGraphicsItem

	Field qObjectPtr:Byte Ptr

	Rem
	bbdoc: The default; all item caching is disabled.
	about: paint() is called every time the item needs redrawing.
	End Rem
	Const NoCache:Int = 0
	Rem
	bbdoc: Caching is enabled for the item's logical (local) coordinate system.
	about: QGraphicsItem creates an off-screen pixel buffer with a configurable size / resolution that you can pass
	to setCacheMode(). Rendering quality will typically degrade, depending on the resolution of the cache and the item
	transformation. The first time the item is redrawn, it will render itself into the cache, and the cache is then reused
	for every subsequent expose. The cache is also reused as the item is transformed. To adjust the resolution of the cache,
	you can call setCacheMode() again.
	End Rem
	Const ItemCoordinateCache:Int = 1
	Rem
	bbdoc: Caching is enabled at the paint device level, in device coordinates.
	about: This mode is for items that can move, but are not rotated, scaled or sheared. If the item is transformed directly or
	indirectly, the cache will be regenerated automatically. Unlike ItemCoordinateCacheMode, DeviceCoordinateCache always renders
	at maximum quality.
	End Rem
	Const DeviceCoordinateCache:Int = 2
	Rem
	bbdoc: The item's enabled state changes.
	about: If the item is presently enabled, it will become disabled, and vice verca. The value argument is the new enabled state
	(i.e., true or false). Do not call setEnabled() in itemChange() as this notification is delivered. Instead, you can return the
	new state from itemChange().
	End Rem
	Const ItemEnabledChange:Int = 3
	Rem
	bbdoc: The item's enabled state has changed.
	about: The value argument is the new enabled state (i.e., true or false). Do not call setEnabled() in itemChange() as this
	notification is delivered. The return value is ignored.
	End Rem
	Const ItemEnabledHasChanged:Int = 13
	Rem
	bbdoc: The item's affine transformation matrix is changing.
	about: This value is obsolete; you can use ItemTransformChange instead.
	End Rem
	Const ItemMatrixChange:Int = 1
	Rem
	bbdoc: The item's position changes.
	about: This notification is only sent when the item's local position changes, relative to its parent, has changed (i.e., as a result
	of calling setPos() or moveBy()). The value argument is the new position (i.e., a QPointF). You can call pos() to get the original
	position. Do not call setPos() or moveBy() in itemChange() as this notification is delivered; instead, you can return the new,
	adjusted position from itemChange(). After this notification, QGraphicsItem immediately sends the ItemPositionHasChanged notification
	if the position changed.End Remem
	Const ItemPositionChange:Int = 0
	Rem
	bbdoc: The item's position has changed.
	about: This notification is only sent after the item's local position, relative to its parent, has changed. The value argument is the
	new position (the same as pos()), and QGraphicsItem ignores the return value for this notification (i.e., a read-only notification).
	End Rem
	Const ItemPositionHasChanged:Int = 9
	Rem
	bbdoc: The item's transformation matrix changes.
	about: This notification is only sent when the item's local transformation matrix changes (i.e., as a result of calling setTransform(),
	or one of the convenience transformation functions, such as rotate()). The value argument is the new matrix (i.e., a QTransform); to get
	the old matrix, call transform(). Do not call setTransform() or any of the transformation convenience functions in itemChange() as this
	notification is delivered; instead, you can return the new matrix from itemChange().
	End Rem
	Const ItemTransformChange:Int = 8
	Rem
	bbdoc: The item's transformation matrix has changed.
	about: This notification is only sent after the item's local trasformation matrix has changed. The value argument is the new matrix
	(same as transform()), and QGraphicsItem ignores the return value for this notification (i.e., a read-only notification).
	End Rem
	Const ItemTransformHasChanged:Int = 10
	Rem
	bbdoc: The item's selected state changes.
	about: If the item is presently selected, it will become unselected, and vice verca. The value argument is the new selected state
	(i.e., true or false). Do not call setSelected() in itemChange() as this notification is delivered(); instead, you can return the new
	selected state from itemChange().
	End Rem
	Const ItemSelectedChange:Int = 4
	Rem
	bbdoc: The item's selected state has changed.
	about: The value argument is the new selected state (i.e., true or false). Do not call setSelected() in itemChange() as this notification
	is delivered. The return value is ignored.
	End Rem
	Const ItemSelectedHasChanged:Int = 14
	Rem
	bbdoc: The item's visible state changes.
	about: If the item is presently visible, it will become invisible, and vice verca. The value argument is the new visible state (i.e.,
	true or false). Do not call setVisible() in itemChange() as this notification is delivered; instead, you can return the new visible state
	from itemChange().
	End Rem
	Const ItemVisibleChange:Int = 2
	Rem
	bbdoc: The item's visible state has changed.
	about: The value argument is the new visible state (i.e., true or false). Do not call setVisible() in itemChange() as this notification
	is delivered. The return value is ignored.
	End Rem
	Const ItemVisibleHasChanged:Int = 12
	Rem
	bbdoc: The item's parent changes.
	about: The value argument is the new parent item (i.e., a QGraphicsItem pointer). Do not call setParentItem() in itemChange() as this
	notification is delivered; instead, you can return the new parent from itemChange().
	End Rem
	Const ItemParentChange:Int = 5
	Rem
	bbdoc: The item's parent has changed.
	about: The value argument is the new parent (i.e., a pointer to a QGraphicsItem). Do not call setParentItem() in itemChange() as this
	notification is delivered. The return value is ignored.
	End Rem
	Const ItemParentHasChanged:Int = 15
	Rem
	bbdoc: A child is added to this item.
	about: The value argument is the new child item (i.e., a QGraphicsItem pointer). Do not pass this item to any item's setParentItem()
	function as this notification is delivered. The return value is unused; you cannot adjust anything in this notification. Note that the
	new child might not be fully constructed when this notification is sent; calling pure virtual functions on the child can lead to a crash.
	End Rem
	Const ItemChildAddedChange:Int = 6
	Rem
	bbdoc: A child is removed from this item.
	about: The value argument is the child item that is about to be removed (i.e., a QGraphicsItem pointer). The return value is unused;
	you cannot adjust anything in this notification.
	End Rem
	Const ItemChildRemovedChange:Int = 7
	Rem
	bbdoc: The item is moved to a new scene.
	about: This notification is also sent when the item is added to its initial scene, and when it is removed. The value argument is the
	new scene (i.e., a QGraphicsScene pointer), or a null pointer if the item is removed from a scene. Do not override this change by
	passing this item to QGraphicsScene::addItem() as this notification is delivered; instead, you can return the new scene from itemChange().
	Use this feature with caution; objecting to a scene change can quickly lead to unwanted recursion.
	End Rem
	Const ItemSceneChange:Int = 11
	Rem
	bbdoc: The item's scene has changed.
	about: The value argument is the new scene (i.e., a pointer to a QGraphicsScene). Do not call setScene() in itemChange() as this
	notification is delivered. The return value is ignored.
	End Rem
	Const ItemSceneHasChanged:Int = 16
	Rem
	bbdoc: The item's cursor changes.
	about: The value argument is the new cursor (i.e., a QCursor). Do not call setCursor() in itemChange() as this notification is delivered.
	Instead, you can return a new cursor from itemChange().
	End Rem
	Const ItemCursorChange:Int = 17
	Rem
	bbdoc: The item's cursor has changed.
	about: The value argument is the new cursor (i.e., a QCursor). Do not call setCursor() as this notification is delivered. The return
	value is ignored.
	End Rem
	Const ItemCursorHasChanged:Int = 18
	Rem
	bbdoc: The item's tooltip changes.
	about: The value argument is the new tooltip (i.e., a QToolTip). Do not call setToolTip() in itemChange() as this notification is
	delivered. Instead, you can return a new tooltip from itemChange().
	End Rem
	Const ItemToolTipChange:Int = 19
	Rem
	bbdoc: The item's tooltip has changed.
	about: The value argument is the new tooltip (i.e., a QToolTip). Do not call setToolTip() as this notification is delivered.
	The return value is ignored.
	End Rem
	Const ItemToolTipHasChanged:Int = 20
	Rem
	bbdoc: The item's flags change.
	about: The value argument is the new flags (i.e., a quint32). Do not call setFlags() in itemChange() as this notification is
	delivered. Instead, you can return the new flags from itemChange().
	End Rem
	Const ItemFlagsChange:Int = 21
	Rem
	bbdoc: The item's flags have changed.
	about: The value argument is the new flags (i.e., a quint32). Do not call setFlags() in itemChange() as this notification is
	delivered. The return value is ignored.
	End Rem
	Const ItemFlagsHaveChanged:Int = 22
	Rem
	bbdoc: The item's Z-value changes.
	about: The value argument is the new Z-value (i.e., a double). Do not call setZValue() in itemChange() as this notification is
	delivered. Instead, you can return a new Z-value from itemChange().
	End Rem
	Const ItemZValueChange:Int = 23
	Rem
	bbdoc: The item's Z-value has changed.
	about: The value argument is the new Z-value (i.e., a double). Do not call setZValue() as this notification is delivered. The
	return value is ignored.
	End Rem
	Const ItemZValueHasChanged:Int = 24
	Rem
	bbdoc: The item's opacity changes.
	about: The value argument is the new opacity (i.e., a double). Do not call setOpacity() in itemChange() as this notification is
	delivered. Instead, you can return a new opacity from itemChange().
	End Rem
	Const ItemOpacityChange:Int = 25
	Rem
	bbdoc: The item's opacity has changed.
	about: The value argument is the new opacity (i.e., a double). Do not call setOpacity() as this notification is delivered. The
	return value is ignored.
	End Rem
	Const ItemOpacityHasChanged:Int = 26
	Rem
	bbdoc: The item supports interactive movement using the mouse.
	about: By clicking on the item and then dragging, the item will move together with the mouse cursor. If the item has children,
	all children are also moved. If the item is part of a selection, all selected items are also moved. This feature is provided as
	a convenience through the base implementation of QGraphicsItem's mouse event handlers.
	End Rem
	Const ItemIsMovable:Int = $1
	Rem
	bbdoc: The item supports selection.
	about: Enabling this feature will enable setSelected() to toggle selection for the item. It will also let the item be selected
	automatically as a result of calling QGraphicsScene::setSelectionArea(), by clicking on an item, or by using rubber band selection
	in QGraphicsView.
	End Rem
	Const ItemIsSelectable:Int = $2
	Rem
	bbdoc: The item supports keyboard input focus (i.e., it is an input item).
	about: Enabling this flag will allow the item to accept focus, which again allows the delivery of key events to keyPressEvent()
	and keyReleaseEvent().
	End Rem
	Const ItemIsFocusable:Int = $4
	Rem
	bbdoc: The item clips to its own shape.
	about: The item cannot draw or receive mouse, tablet, drag and drop or hover events outside ts shape. It is disabled by default.
	This behavior is enforced by QGraphicsView::drawItems() or QGraphicsScene::drawItems(). This flag was introduced in Qt 4.3.
	End Rem
	Const ItemClipsToShape:Int = $8
	Rem
	bbdoc: The item clips the painting of all its descendants to its own shape.
	about: Items that are either direct or indirect children of this item cannot draw outside this item's shape. By default, this
	flag is disabled; children can draw anywhere. This behavior is enforced by QGraphicsView::drawItems() or QGraphicsScene::drawItems().
	This flag was introduced in Qt 4.3.
	End Rem
	Const ItemClipsChildrenToShape:Int = $10
	Rem
	bbdoc: The item ignores inherited transformations (i.e., its position is still anchored to its parent, but the parent or view rotation, zoom or shear transformations are ignored).
	about: This flag is useful for keeping text label items horizontal and unscaled, so they will still be readable if the view is
	transformed. When set, the item's view geometry and scene geometry will be maintained separately. You must call deviceTransform()
	to map coordinates and detect collisions in the view. By default, this flag is disabled. This flag was introduced in Qt 4.3. Note:
	With this flag set you can still scale the item itself, and that scale transformation will influence the item's children.
	End Rem
	Const ItemIgnoresTransformations:Int = $20
	Rem
	bbdoc: The item ignores its parent's opacity.
	about: The item's effective opacity is the same as its own; it does not combine with the parent's opacity. This flags allows
	your item to keep its absolute opacity even if the parent is semitransparent. This flag was introduced in Qt 4.5.
	End Rem
	Const ItemIgnoresParentOpacity:Int = $40
	Rem
	bbdoc: The item doesn't propagate its opacity to its children.
	about: This flag allows you to create a semitransparent item that does not affect the opacity of its children. This flag was
	introduced in Qt 4.5.
	End Rem
	Const ItemDoesntPropagateOpacityToChildren:Int = $80
	Rem
	bbdoc: The item is stacked behind its parent.
	about: By default, child items are stacked on top of the parent item. But setting this flag, the child will be stacked behind it.
	This flag is useful for drop shadow effects and for decoration objects that follow the parent item's geometry without drawing on top of it.
	End Rem
	Const ItemStacksBehindParent:Int = $100

	Method boundingRect:QRectF()
		Return QRectF._create(bmx_qt_qgraphicsitem_boundingrect(qObjectPtr))
	End Method
	
	Method isSelected:Int()
		Return bmx_qt_qgraphicsitem_isselected(qObjectPtr)
	End Method
	
	Method isUnderMouse:Int()
		Return bmx_qt_qgraphicsitem_isundermouse(qObjectPtr)
	End Method
	
	Method isVisible:Int()
		Return bmx_qt_qgraphicsitem_isvisible(qObjectPtr)
	End Method
	
	Method isVisibleTo:Int(parent:QGraphicsItem)
		Return bmx_qt_qgraphicsitem_isvisibleto(qObjectPtr, parent.qObjectPtr)
	End Method
	
	Method isWidget:Int()
		Return bmx_qt_qgraphicsitem_iswidget(qObjectPtr)
	End Method
	
	Method isWindow:Int()
		Return bmx_qt_qgraphicsitem_iswindow(qObjectPtr)
	End Method

	Method setAcceptDrops(on:Int)
		bmx_qt_qgraphicsitem_setacceptdrops(qObjectPtr, on)
	End Method
	
	Method setAcceptHoverEvents(enabled:Int)
		bmx_qt_qgraphicsitem_setaccepthoverevents(qObjectPtr, enabled)
	End Method
	
	Method setAcceptedMouseButtons(buttons:Int)
		bmx_qt_qgraphicsitem_setacceptedmousebuttons(qObjectPtr, buttons)
	End Method
	
	Method setBoundingRegionGranularity(granularity:Double)
		bmx_qt_qgraphicsitem_setboundingregiongranularity(qObjectPtr, granularity)
	End Method
	
	Method setCacheMode(_mode:Int, w:Int = 0, h:Int = 0)
		bmx_qt_qgraphicsitem_setcachemode(qObjectPtr, _mode, w, h)
	End Method
	
	Method setCursor(cursor:QCursor)
		bmx_qt_qgraphicsitem_setcursor(qObjectPtr, cursor.qObjectPtr)
	End Method
	
	Method setData(key:Int, value:Object)
		bmx_qt_qgraphicsitem_setdata(qObjectPtr, key, value)
	End Method
	
	Method setEnabled(enabled:Int)
		bmx_qt_qgraphicsitem_setenabled(qObjectPtr, enabled)
	End Method
	
	Method setFlag(flag:Int, enabled:Int = True)
		bmx_qt_qgraphicsitem_setflag(qObjectPtr, flag, enabled)
	End Method
	
	Method setFlags(flags:Int)
		bmx_qt_qgraphicsitem_setflags(qObjectPtr, flags)
	End Method
	
	Method SetFocus(focusReason:Int = Qt_OtherFocusReason)
		bmx_qt_qgraphicsitem_setfocus(qObjectPtr, focusReason)
	End Method
	
	Method setGroup(group:QGraphicsItemGroup)
		bmx_qt_qgraphicsitem_setgroup(qObjectPtr, group.qObjectPtr)
	End Method
	
	Method setHandlesChildEvents(enabled:Int)
		bmx_qt_qgraphicsitem_sethandleschildevents(qObjectPtr, enabled)
	End Method
	
	Method setOpacity(opacity:Double)
		bmx_qt_qgraphicsitem_setopacity(qObjectPtr, opacity)
	End Method
	
	Method setParentItem(parent:QGraphicsItem)
		bmx_qt_qgraphicsitem_setparentitem(qObjectPtr, parent.qObjectPtr)
	End Method
	
	Method setPos(x:Double, y:Double)
		bmx_qt_qgraphicsitem_setpos(qObjectPtr, x, y)
	End Method
	
	Method setSelected(selected:Int)
		bmx_qt_qgraphicsitem_setselected(qObjectPtr, selected)
	End Method
	
	Method setToolTip(toolTip:String)
		bmx_qt_qgraphicsitem_settooltip(qObjectPtr, toolTip)
	End Method
	
	Method SetTransform(matrix:QTransform, combine:Int = False)
		bmx_qt_qgraphicsitem_settransform(qObjectPtr, matrix.qObjectPtr, combine)
	End Method
	
	Method setVisible(visible:Int)
		bmx_qt_qgraphicsitem_setvisible(qObjectPtr, visible)
	End Method
	
	Method setZValue(z:Double)
		bmx_qt_qgraphicsitem_setzvalue(qObjectPtr, z)
	End Method
	
	Method _addToScene(scene:Byte Ptr)
		bmx_qt_qgraphicsitem_addtoscene(qObjectPtr, scene)
	End Method
	
End Type


Type QGraphicsObjectItem Extends QGraphicsItem

	Field myObject:QObject

	Method castToObject:QObject()
		If Not myObject Then
			myObject = New QObject
			myObject.qObjectPtr = qObjectPtr
		End If
		Return myObject
	End Method

End Type

Type QGraphicsItemGroup Extends QGraphicsItem

End Type

