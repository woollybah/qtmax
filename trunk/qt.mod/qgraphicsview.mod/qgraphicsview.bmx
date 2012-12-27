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

Module Qt.QGraphicsView

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QGraphicsView Extends QAbstractScrollArea

	Rem
	bbdoc: All painting is done directly onto the viewport.
	end rem
	Const CacheNone:Int = $0
	Rem
	bbdoc: The background is cached.
	about: This affects both custom backgrounds, and backgrounds based on the backgroundBrush property. When this flag
	is enabled, QGraphicsView will allocate one pixmap with the full size of the viewport.
	End Rem
	Const CacheBackground:Int = $1
	Rem
	bbdoc: Nothing happens.
	about: The mouse event is ignored.
	End Rem
	Const NoDrag:Int = 0
	Rem
	bbdoc: The cursor changes into a pointing hand, and dragging the mouse around will scroll the scrolbars.
	about: This mode works both in interactive and non-interactive mode.
	End Rem
	Const ScrollHandDrag:Int = 1
	Rem
	bbdoc: A rubber band will appear.
	about: Dragging the mouse will set the rubber band geometry, and all items covered by the rubber band are selected. This mode
	is disabled for non-interactive views.
	End Rem
	Const RubberBandDrag:Int = 2
	Rem
	bbdoc: QGraphicsView sometimes clips the painter when rendering the scene contents.
	about: This can generally improve performance (e.g., rendering only small parts of a large pixmap), and protects against rendering
	mistakes (e.g., drawing outside bounding rectangles, or outside the exposed area). In some situations, however, the painter clip
	can slow down rendering; especially when all painting is restricted to inside exposed areas. By enabling this flag, QGraphicsView
	will completely disable its implicit clipping. Note that rendering artifacts from using a semi-transparent foreground or background
	brush can occur if clipping is disabled.
	End Rem
	Const DontClipPainter:Int = $1
	Rem
	bbdoc: When rendering, QGraphicsView protects the painter state (see QPainter::save()) when rendering the background or foreground, and when rendering each item.
	about: This allows you to leave the painter in an altered state (i.e., you can call QPainter::setPen() or QPainter::setBrush() without
	restoring the state after painting). However, if the items consistently do restore the state, you should enable this flag to prevent
	QGraphicsView from doing the same.
	End Rem
	Const DontSavePainterState:Int = $2
	Rem
	bbdoc: Disables QGraphicsView's antialiasing auto-adjustment of exposed areas.
	about: Items that render antialiased lines on the boundaries of their QGraphicsItem::boundingRect() can end up rendering parts of
	the line outside. To prevent rendering artifacts, QGraphicsView expands all exposed regions by 2 pixels in all directions. If you
	enable this flag, QGraphicsView will no longer perform these adjustments, minimizing the areas that require redrawing, which
	improves performance. A common side effect is that items that do draw with antialiasing can leave painting traces behind on the
	scene as they are moved.
	End Rem
	Const DontAdjustForAntialiasing:Int = $4
	Rem
	bbdoc: No anchor, i.e. the view leaves the scene's position unchanged.
	end rem
	Const NoAnchor:Int = 0
	Rem
	bbdoc: The scene point at the center of the view is used as the anchor.
	end rem
	Const AnchorViewCenter:Int = 1
	Rem
	bbdoc: The point under the mouse is used as the anchor.
	end rem
	Const AnchorUnderMouse:Int = 2
	Rem
	bbdoc: When any visible part of the scene changes or is reexposed, QGraphicsView will update the entire viewport.
	about: This approach is fastest when QGraphicsView spends more time figuring out what to draw than it would spend drawing
	(e.g., when very many small items are repeatedly updated). This is the preferred update mode for viewports that do not support
	partial updates, such as QGLWidget, and for viewports that need to disable scroll optimization.
	End Rem
	Const FullViewportUpdate:Int = 0
	Rem
	bbdoc: QGraphicsView will determine the minimal viewport region that requires a redraw, minimizing the time spent drawing by avoiding a redraw of areas that have not changed.
	about: This is QGraphicsView's default mode. Although this approach provides the best performance in general, if there are many small
	visible changes on the scene, QGraphicsView might end up spending more time finding the minimal approach than it will spend drawing.
	End Rem
	Const MinimalViewportUpdate:Int = 1
	Rem
	bbdoc: QGraphicsView will attempt to find an optimal update mode by analyzing the areas that require a redraw.
	end rem
	Const SmartViewportUpdate:Int = 2
	Rem
	bbdoc: The bounding rectangle of all changes in the viewport will be redrawn.
	about: This mode has the advantage that QGraphicsView searches only one region for changes, minimizing time spent determining what needs
	redrawing. The disadvantage is that areas that have not changed also need to be redrawn.
	End Rem
	Const BoundingRectViewportUpdate:Int = 4
	Rem
	bbdoc: QGraphicsView will never update its viewport when the scene changes; the user is expected to control all updates.
	about: This mode disables all (potentially slow) item visibility testing in QGraphicsView, and is suitable for scenes that either
	require a fixed frame rate, or where the viewport is otherwise updated externally.
	End Rem
	Const NoViewportUpdate:Int = 3

	
	Function CreateGraphicsView:QGraphicsView(parent:QWidget = Null)
		Return New QGraphicsView.Create(parent)
	End Function

	Function CreateGraphicsViewWithScene:QGraphicsView(scene:QGraphicsScene, parent:QWidget = Null)
		Return New QGraphicsView.CreateWithScene(scene, parent)
	End Function
	
	Method Create:QGraphicsView(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicsview_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicsview_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method CreateWithScene:QGraphicsView(scene:QGraphicsScene, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicsview_createwithscene(Self, scene.qObjectPtr, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicsview_createwithscene(Self, scene.qObjectPtr, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method alignment:Int()
		Return bmx_qt_qgraphicsview_alignment(qObjectPtr)
	End Method
	
	Method backgroundBrush:QBrush()
		Return QBrush._create(bmx_qt_qgraphicsview_backgroundbrush(qObjectPtr))
	End Method
	
	Method cacheMode:Int()
		Return bmx_qt_qgraphicsview_cachemode(qObjectPtr)
	End Method
	
	Method render(painter:QPainter, target:QRectF = Null, source:QRect = Null, aspectRatioMode:Int = Qt_KeepAspectRatio)
		If target Then
			If source Then
				bmx_qt_qgraphicsview_render(qObjectPtr, painter.qObjectPtr, target.qObjectPtr, source.qObjectPtr, aspectRatioMode)
			Else
				bmx_qt_qgraphicsview_render(qObjectPtr, painter.qObjectPtr, target.qObjectPtr, Null, aspectRatioMode)
			End If
		Else
			If source Then
				bmx_qt_qgraphicsview_render(qObjectPtr, painter.qObjectPtr, Null, source.qObjectPtr, aspectRatioMode)
			Else
				bmx_qt_qgraphicsview_render(qObjectPtr, painter.qObjectPtr, Null, Null, aspectRatioMode)
			End If
		End If
	End Method
	
	Method resetCachedContent()
		bmx_qt_qgraphicsview_resetcachedcontent(qObjectPtr)
	End Method
	
	Method resetMatrix()
		bmx_qt_qgraphicsview_resetmatrix(qObjectPtr)
	End Method

	Method resetTransform()
		bmx_qt_qgraphicsview_resettransform(qObjectPtr)
	End Method

	Method scale(sx:Double, sy:Double)
		bmx_qt_qgraphicsview_scale(qObjectPtr, sx, sy)
	End Method
	
	Method scene:QGraphicsScene()
		Return QGraphicsScene._find(bmx_qt_qgraphicsview_scene(qObjectPtr))
	End Method
	
	Method sceneRect:QRectF()
		Return QRectF._create(bmx_qt_qgraphicsview_scenerect(qObjectPtr))
	End Method

	Method setAlignment(alignment:Int)
		bmx_qt_qgraphicsview_setalignment(qObjectPtr, alignment)
	End Method
	
	Method setBackgroundBrush(brush:QBrush)
		bmx_qt_qgraphicsview_setbackgroundbrush(qObjectPtr, brush.qObjectPtr)
	End Method
	
	Method setCacheMode(_mode:Int)
		bmx_qt_qgraphicsview_setcachemode(qObjectPtr, _mode)
	End Method
	
	Method setDragMode(_mode:Int)
		bmx_qt_qgraphicsview_setdragmode(qObjectPtr, _mode)
	End Method
	
	Method setForegroundBrush(brush:QBrush)
		bmx_qt_qgraphicsview_setforegroundbrush(qObjectPtr, brush.qObjectPtr)
	End Method
	
	Method setInteractive(allowed:Int)
		bmx_qt_qgraphicsview_setinteractive(qObjectPtr, allowed)
	End Method
	
	Method setMatrix(matrix:QMatrix, combine:Int = False)
		bmx_qt_qgraphicsview_setmatrix(qObjectPtr, matrix.qObjectPtr, combine)
	End Method
	
	Method setOptimizationFlag(flag:Int, enabled:Int = True)
		bmx_qt_qgraphicsview_setoptimizationflag(qObjectPtr, flag, enabled)
	End Method
	
	Method setOptimizationFlags(flags:Int)
		bmx_qt_qgraphicsview_setoptimizationflags(qObjectPtr, flags)
	End Method
	
	Method setRenderHint(hint:Int, enabled:Int = True)
		bmx_qt_qgraphicsview_setrenderhint(qObjectPtr, hint, enabled)
	End Method
	
	Method setRenderHints(hints:Int)
		bmx_qt_qgraphicsview_setrenderhints(qObjectPtr, hints)
	End Method
	
	Method setResizeAnchor(anchor:Int)
		bmx_qt_qgraphicsview_setresizeanchor(qObjectPtr, anchor)
	End Method
	
	Method setRubberBandSelectionMode(_mode:Int)
		bmx_qt_qgraphicsview_setrubberbandselectionmode(qObjectPtr, _mode)
	End Method
	
	Method setScene(scene:QGraphicsScene)
		bmx_qt_qgraphicsview_setscene(qObjectPtr, scene.qObjectPtr)
	End Method
	
	Method setSceneRectRect(rect:QRectF)
		bmx_qt_qgraphicsview_setscenerectrect(qObjectPtr, rect.qObjectPtr)
	End Method
	
	Method setSceneRect(x:Double, y:Double, w:Double, h:Double)
		bmx_qt_qgraphicsview_setscenerect(qObjectPtr, x, y, w, h)
	End Method
	
	Method SetTransform(matrix:QTransform, combine:Int = False)
		bmx_qt_qgraphicsview_settransform(qObjectPtr, matrix.qObjectPtr, combine)
	End Method
	
	Method setTransformationAnchor(anchor:Int)
		bmx_qt_qgraphicsview_settransformationanchor(qObjectPtr, anchor)
	End Method
	
	Method sizeHint(w:Int Var, h:Int Var)
		bmx_qt_qgraphicsview_sizehint(qObjectPtr, Varptr w, Varptr h)
	End Method


	' QGraphicsView
	' QAbstractScrollArea
	Method scrollContentsBy(dx:Int, dy:Int)
		bmx_qt_qgraphicsview_default_scrollcontentsby(qObjectPtr, dx, dy)
	End Method
	
	Method viewportEvent:Int(event:QEvent)
		Return bmx_qt_qgraphicsview_default_viewportevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	' QFrame
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qgraphicsview_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qgraphicsview_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qgraphicsview_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qgraphicsview_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qgraphicsview_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qgraphicsview_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qgraphicsview_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qgraphicsview_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qgraphicsview_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qgraphicsview_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qgraphicsview_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qgraphicsview_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qgraphicsview_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qgraphicsview_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qgraphicsview_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qgraphicsview_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qgraphicsview_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qgraphicsview_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qgraphicsview_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qgraphicsview_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qgraphicsview_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qgraphicsview_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qgraphicsview_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qgraphicsview_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qgraphicsview_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qgraphicsview_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qgraphicsview_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qgraphicsview_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qgraphicsview_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qgraphicsview_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qgraphicsview_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method


End Type

Type QGraphicsScene Extends QObject

	Rem
	bbdoc: The item layer.
	about: QGraphicsScene renders all items are in this layer by calling the virtual function drawItems(). The item layer is drawn
	after the background layer, but before the foreground layer.
	End Rem
	Const ItemLayer:Int = $1
	Rem
	bbdoc: The background layer.
	about: QGraphicsScene renders the scene's background in this layer by calling the virtual function drawBackground(). The
	background layer is drawn first of all layers.
	End Rem
	Const BackgroundLayer:Int = $2
	Rem
	bbdoc: The foreground layer.
	about: QGraphicsScene renders the scene's foreground in this layer by calling the virtual function drawForeground(). The foreground
	layer is drawn last of all layers.
	End Rem
	Const ForegroundLayer:Int = $4
	Rem
	bbdoc: All layers.
	about: This value represents a combination of all three layers.
	End Rem
	Const AllLayers:Int = $ffff

	Rem
	bbdoc: A Binary Space Partitioning tree is applied.
	about: All QGraphicsScene's item location algorithms are of an order close to logarithmic complexity, by making use of binary
	search. Adding, moving and removing items is logarithmic. This approach is best for static scenes (i.e., scenes where most items
	do not move).
	End Rem
	Const BspTreeIndex:Int = 0
	Rem
	bbdoc: No index is applied.
	about: Item location is of linear complexity, as all items on the scene are searched. Adding, moving and removing items, however,
	is done in constant time. This approach is ideal for dynamic scenes, where many items are added, moved or removed continuously.
	End Rem
	Const NoIndex:Int = -1

	Function _create:QGraphicsScene(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QGraphicsScene = New QGraphicsScene
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QGraphicsScene(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QGraphicsScene = QGraphicsScene(qfind(qObjectPtr))
			If Not widget Then
				Return QGraphicsScene._create(qObjectPtr)
			End If
			Return widget
		End If
	End Function
	
	Function CreateGraphicsScene:QGraphicsScene(parent:QObject = Null)
		Return New QGraphicsScene.Create(parent)
	End Function
	
	Method Create:QGraphicsScene(parent:QObject = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicsscene_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicsscene_create(Self, Null)
		End If
		Return Self
	End Method
	
	Method addItem(item:QGraphicsItem)
		item._addToScene(qObjectPtr)
		'bmx_qt_qgraphicsscene_additem(qObjectPtr, item.qObjectPtr)
	End Method
	
	Method addPixmap:QGraphicsPixmapItem(pixmap:QPixmap)
		Return QGraphicsPixmapItem._create(bmx_qt_qgraphicsscene_addpixmap(qObjectPtr, pixmap.qObjectPtr))
	End Method

	Method hasFocus:Int()
		Return bmx_qt_qgraphicsscene_hasfocus(qObjectPtr)
	End Method

	Method itemAt:QGraphicsItem(x:Double, y:Double)
		Return QGraphicsItem._find(bmx_qt_qgraphicsscene_itemat(qObjectPtr, x, y))
	End Method

	Method itemIndexMethod:Int()
		Return bmx_qt_qgraphicsscene_itemindexmethod(qObjectPtr)
	End Method

	Method itemsBoundingRect:QRectF()
		Return QRectF._create(bmx_qt_qgraphicsscene_itemsboundingrect(qObjectPtr))
	End Method

	Method mouseGrabberItem:QGraphicsItem()
		Return QGraphicsItem._find(bmx_qt_qgraphicsscene_mousegrabberitem(qObjectPtr))
	End Method

	Method palette:QPalette()
		Return QPalette._create(bmx_qt_qgraphicsscene_palette(qObjectPtr))
	End Method

	Method removeItem(item:QGraphicsItem)
		bmx_qt_qgraphicsscene_removeitem(qObjectPtr, item.qObjectPtr)
	End Method

	Method sceneRect:QRectF()
		Return QRectF._create(bmx_qt_qgraphicsscene_scenerect(qObjectPtr))
	End Method
	
	Method selectedItems:QGraphicsItem[]()
		Return bmx_qt_qgraphicsscene_selecteditems(qObjectPtr)
	End Method
	
	Function _newItems:QGraphicsItem[](size:Int)
		Return New QGraphicsItem[size]
	End Function
	
	Function _setItem(items:QGraphicsItem[], index:Int, item:Byte Ptr)
		items[index] = QGraphicsItem._find(item)
	End Function
	
	Method selectionArea:QPainterPath()
		Return QPainterPath._create(bmx_qt_qgraphicsscene_selectionarea(qObjectPtr))
	End Method
	
	Method setActiveWindow(widget:QGraphicsWidget)
		bmx_qt_qgraphicsscene_setactivewindow(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method setSceneRect(x:Double, y:Double, w:Double, h:Double)
		bmx_qt_qgraphicsscene_setscenerect(qObjectPtr, x, y, w, h)
	End Method

	Method setSceneRectRect(rect:QRectF)
		bmx_qt_qgraphicsscene_setscenerectrect(qObjectPtr, rect.qObjectPtr)
	End Method

	Method setBackgroundBrush(brush:QBrush)
		bmx_qt_qgraphicsscene_setbackgroundbrush(qObjectPtr, brush.qObjectPtr)
	End Method
	
	Method setBspTreeDepth(depth:Int)
		bmx_qt_qgraphicsscene_setbsptreedepth(qObjectPtr, depth)
	End Method
	
	Method SetFocus(focusReason:Int = Qt_OtherFocusReason )
		bmx_qt_qgraphicsscene_setfocus(qObjectPtr, focusReason)
	End Method
	
	Method setFocusItem(item:QGraphicsItem, focusReason:Int = Qt_OtherFocusReason )
		bmx_qt_qgraphicsscene_setfocusitem(qObjectPtr, item.qObjectPtr, focusReason)
	End Method
	
	Method setFont(font:QFont)
		bmx_qt_qgraphicsscene_setfont(qObjectPtr, font.qObjectPtr)
	End Method
	
	Method setForegroundBrush(brush:QBrush)
		bmx_qt_qgraphicsscene_setforegroundbrush(qObjectPtr, brush.qObjectPtr)
	End Method
	
	Method setItemIndexMethod(_method:Int)
		bmx_qt_qgraphicsscene_setitemindexmethod(qObjectPtr, _method)
	End Method
	
	Method setPalette(palette:QPalette)
		bmx_qt_qgraphicsscene_setpalette(qObjectPtr, palette.qObjectPtr)
	End Method
	
	Method setSelectionArea(path:QPainterPath, _mode:Int)
		bmx_qt_qgraphicsscene_setselectionarea(qObjectPtr, path.qObjectPtr, _mode)
	End Method
	
	Method setSortCacheEnabled(enabled:Int)
		bmx_qt_qgraphicsscene_setsortcacheenabled(qObjectPtr, enabled)
	End Method
	
	Method setStickyFocus(enabled:Int)
		bmx_qt_qgraphicsscene_setstickyfocus(qObjectPtr, enabled)
	End Method
	
	Method setStyle(style:QStyle)
		bmx_qt_qgraphicsscene_setstyle(qObjectPtr, style.qObjectPtr)
	End Method
	
	Method advance()
		bmx_qt_qgraphicsscene_advance(qObjectPtr)
	End Method
	
	Method clear()
		bmx_qt_qgraphicsscene_clear(qObjectPtr)
	End Method
	
	Method clearSelection()
		bmx_qt_qgraphicsscene_clearselection(qObjectPtr)
	End Method
	
	Method invalidate(rect:QRectF = Null, layers:Int = AllLayers)
	' TODO
	End Method

	Method update(rect:QRectF = Null)
		If rect Then
			bmx_qt_qgraphicsscene_udpate(qObjectPtr, rect.qObjectPtr)
		Else
			bmx_qt_qgraphicsscene_udpate(qObjectPtr, Null)
		End If
	End Method
	
	Method height:Double()
		Return bmx_qt_qgraphicsscene_width(qObjectPtr)
	End Method
	
	Method width:Double()
		Return bmx_qt_qgraphicsscene_height(qObjectPtr)
	End Method

	Method contextMenuEvent(contextMenuEvent:QGraphicsSceneContextMenuEvent)
		bmx_qt_qgraphicsscene_defaultcontextmenuevent(qObjectPtr, contextMenuEvent.qObjectPtr)
	End Method
	
	Function _contextMenuEvent(scene:QGraphicsScene, contextMenuEvent:Byte Ptr)
		scene.contextMenuEvent(QGraphicsSceneContextMenuEvent._create(contextMenuEvent))
	End Function
	
	Method dragEnterEvent(event:QGraphicsSceneDragDropEvent)
		bmx_qt_qgraphicsscene_defaultdragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _dragEnterEvent(scene:QGraphicsScene, event:Byte Ptr)
		scene.dragEnterEvent(QGraphicsSceneDragDropEvent._create(event))
	End Function
	
	Method dragLeaveEvent(event:QGraphicsSceneDragDropEvent)
		bmx_qt_qgraphicsscene_defaultdragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _dragLeaveEvent(scene:QGraphicsScene, event:Byte Ptr)
		scene.dragLeaveEvent(QGraphicsSceneDragDropEvent._create(event))
	End Function
	
	Method dragMoveEvent(event:QGraphicsSceneDragDropEvent)
		bmx_qt_qgraphicsscene_defaultdragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _dragMoveEvent(scene:QGraphicsScene, event:Byte Ptr)
		scene.dragMoveEvent(QGraphicsSceneDragDropEvent._create(event))
	End Function

	Method drawBackground(painter:QPainter, rect:QRectF)
		bmx_qt_qgraphicsscene_defaultdrawbackground(qObjectPtr, painter.qObjectPtr, rect.qObjectPtr)
	End Method
	
	Function _drawBackground(scene:QGraphicsScene, painter:Byte Ptr, rect:Byte Ptr)
		scene.drawBackground(QPainter._create(painter), QRectF._create(rect))
	End Function
	
	Method drawForeground(painter:QPainter, rect:QRectF)
		bmx_qt_qgraphicsscene_defaultdrawforeground(qObjectPtr, painter.qObjectPtr, rect.qObjectPtr)
	End Method
	
	Function _drawForeground(scene:QGraphicsScene, painter:Byte Ptr, rect:Byte Ptr)
		scene.drawForeground(QPainter._create(painter), QRectF._create(rect))
	End Function
	
	Method dropEvent(event:QGraphicsSceneDragDropEvent)
		bmx_qt_qgraphicsscene_defaultdropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _dropEvent(scene:QGraphicsScene, event:Byte Ptr)
		scene.dropEvent(QGraphicsSceneDragDropEvent._create(event))
	End Function
	
	Method focusInEvent(focusEvent:QFocusEvent)
		bmx_qt_qgraphicsscene_defaultfocusinevent(qObjectPtr, focusEvent.qObjectPtr)
	End Method
	
	Function _focusInEvent(scene:QGraphicsScene, focusEvent:Byte Ptr)
		scene.focusInEvent(QFocusEvent._create(focusEvent))
	End Function
	
	Method focusOutEvent(focusEvent:QFocusEvent)
		bmx_qt_qgraphicsscene_defaultfocusoutevent(qObjectPtr, focusEvent.qObjectPtr)
	End Method
	
	Function _focusOutEvent(scene:QGraphicsScene, focusEvent:Byte Ptr)
		scene.focusOutEvent(QFocusEvent._create(focusEvent))
	End Function
	
	Method helpEvent(helpEvent:QGraphicsSceneHelpEvent)
		bmx_qt_qgraphicsscene_defaulthelpevent(qObjectPtr, helpEvent.qObjectPtr)
	End Method
	
	Function _helpEvent(scene:QGraphicsScene, helpEvent:Byte Ptr)
		scene.helpEvent(QGraphicsSceneHelpEvent._create(helpEvent))
	End Function
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qgraphicsscene_defaultinputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _inputMethodEvent(scene:QGraphicsScene, event:Byte Ptr)
		scene.inputMethodEvent(QInputMethodEvent._create(event))
	End Function
	
	Method keyPressEvent(keyEvent:QKeyEvent)
		bmx_qt_qgraphicsscene_defaultkeypressevent(qObjectPtr, keyEvent.qObjectPtr)
	End Method
	
	Function _keyPressEvent(scene:QGraphicsScene, keyEvent:Byte Ptr)
		scene.keyPressEvent(QKeyEvent._create(keyEvent))
	End Function
	
	Method keyReleaseEvent(keyEvent:QKeyEvent)
		bmx_qt_qgraphicsscene_defaultkeyreleaseevent(qObjectPtr, keyEvent.qObjectPtr)
	End Method
	
	Function _keyReleaseEvent(scene:QGraphicsScene, keyEvent:Byte Ptr)
		scene.keyReleaseEvent(QKeyEvent._create(keyEvent))
	End Function
	
	Method mouseDoubleClickEvent(mouseEvent:QGraphicsSceneMouseEvent)
		bmx_qt_qgraphicsscene_defaultmousedoubleclickevent(qObjectPtr, mouseEvent.qObjectPtr)
	End Method
	
	Function _mouseDoubleClickEvent(scene:QGraphicsScene, mouseEvent:Byte Ptr)
		scene.mouseDoubleClickEvent(QGraphicsSceneMouseEvent._create(mouseEvent))
	End Function
	
	Method mouseMoveEvent(mouseEvent:QGraphicsSceneMouseEvent)
		bmx_qt_qgraphicsscene_defaultmousemoveevent(qObjectPtr, mouseEvent.qObjectPtr)
	End Method
	
	Function _mouseMoveEvent(scene:QGraphicsScene, mouseEvent:Byte Ptr)
		scene.mouseMoveEvent(QGraphicsSceneMouseEvent._create(mouseEvent))
	End Function
	
	Method mousePressEvent(mouseEvent:QGraphicsSceneMouseEvent)
		bmx_qt_qgraphicsscene_defaultmousepressevent(qObjectPtr, mouseEvent.qObjectPtr)
	End Method
	
	Function _mousePressEvent(scene:QGraphicsScene, mouseEvent:Byte Ptr)
		scene.mousePressEvent(QGraphicsSceneMouseEvent._create(mouseEvent))
	End Function
	
	Method mouseReleaseEvent(mouseEvent:QGraphicsSceneMouseEvent)
		bmx_qt_qgraphicsscene_defaultmousereleaseevent(qObjectPtr, mouseEvent.qObjectPtr)
	End Method
	
	Function _mouseReleaseEvent(scene:QGraphicsScene, mouseEvent:Byte Ptr)
		scene.mouseReleaseEvent(QGraphicsSceneMouseEvent._create(mouseEvent))
	End Function
	
	Method wheelEvent(wheelEvent:QGraphicsSceneWheelEvent)
		bmx_qt_qgraphicsscene_defaultwheelevent(qObjectPtr, wheelEvent.qObjectPtr)
	End Method
	
	Function _wheelEvent(scene:QGraphicsScene, wheelEvent:Byte Ptr)
		scene.wheelEvent(QGraphicsSceneWheelEvent._create(wheelEvent))
	End Function
	
	Method items:QGraphicsItemList()
		Return QGraphicsItemList._create(bmx_qt_qgraphicsscene_items(qObjectPtr))
	End Method
	
End Type

Type QGraphicsItemList

	Field listPtr:Byte Ptr

	Function _create:QGraphicsItemList(listPtr:Byte Ptr)
		If listPtr Then
			Local this:QGraphicsItemList = New QGraphicsItemList
			this.listPtr = listPtr
			Return this
		End If
	End Function

	Method ObjectEnumerator:QGraphicsItemListEnumerator()
		Local enum:QGraphicsItemListEnumerator = New QGraphicsItemListEnumerator
		enum.list = Self

		Return enum
	End Method

	Method size:Int()
		Return bmx_qt_qgraphicsitemlist_size(listPtr)
	End Method
	
	Method Delete()
		If listPtr Then
			bmx_qt_qgraphicsitemlist_free(listPtr)
			listPtr = Null
		End If
	End Method
	
End Type

' private
Type QGraphicsItemListEnumerator

	Field list:QGraphicsItemList

	Method HasNext:Int()
		Return bmx_qt_qgraphicsitemlist_hasnext(list.listPtr)
	End Method
	
	Method NextObject:Object()
		If HasNext() Then
			Return QGraphicsItem._find(bmx_qt_qgraphicsitemlist_nextobject(list.listPtr))
		Else
			bmx_qt_qgraphicsitemlist_reset(list.listPtr)
		End If
	End Method

End Type


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
	
	Function _create:QGraphicsItem(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QGraphicsItem = New QGraphicsItem
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QGraphicsItem(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local item:QGraphicsItem = QGraphicsItem(qgifind(qObjectPtr))
			If Not item Then
				Return QGraphicsItem._create(qObjectPtr)
			End If
			Return item
		End If
	End Function
	
	Function CreateGraphicsItem:QGraphicsItem(parent:QGraphicsItem = Null)
		Return New QGraphicsItem.CreateItem(parent)
	End Function
	
	Method CreateItem:QGraphicsItem(parent:QGraphicsItem = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicsitem_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicsitem_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method OnInit()
	End Method

	Method boundingRect:QRectF()
		Return QRectF._create(bmx_qt_qgraphicsitem_boundingrect(qObjectPtr))
	End Method
	
	Function _boundingRect:Byte Ptr(item:QGraphicsItem)
		Local rect:QRectF = item.boundingRect()
		If rect Then
			Return rect.qObjectPtr
		Else
			Return Null
		End If
	End Function
	
	Method graphicsEffect:QGraphicsEffect()
		Return QGraphicsEffect._find(bmx_qt_qgraphicsitem_graphicseffect(qObjectPtr))
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
	
	Method mapFromItem(item:QGraphicsItem, x:Double, y:Double, x1:Double Var, y1:Double Var)
		bmx_qt_qgraphicsitem_mapfromitem(qObjectPtr, item.qObjectPtr, x, y, Varptr x1, Varptr y1)
	End Method
	
	Method paint(painter:QPainter, option:QStyleOptionGraphicsItem, widget:QWidget)
	End Method
	
	Function _paint(item:QGraphicsItem, painter:Byte Ptr, option:Byte Ptr, widget:Byte Ptr)
		If widget Then
			item.paint(QPainter._create(painter), QStyleOptionGraphicsItem._create(option), QWidget._find(widget))
		Else
			item.paint(QPainter._create(painter), QStyleOptionGraphicsItem._create(option), Null)
		End If
	End Function
	
	Method pos(x:Double Var, y:Double Var)
		bmx_qt_qgraphicsitem_pos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method prepareGeometryChange()
		bmx_qt_qgraphicsitem_preparegeometrychange(qObjectPtr)
	End Method

	Method removeSceneEventFilter(filterItem:QGraphicsItem)
		bmx_qt_qgraphicsitem_removesceneeventfilter(qObjectPtr, filterItem.qObjectPtr)
	End Method
	
	Method resetTransform()
		bmx_qt_qgraphicsitem_resettransform(qObjectPtr)
	End Method
	
	Method rotate(angle:Double)
		bmx_qt_qgraphicsitem_rotate(qObjectPtr, angle)
	End Method
	
	Method scale(sx:Double, sy:Double)
		bmx_qt_qgraphicsitem_scale(qObjectPtr, sx, sy)
	End Method
	
	Method scene:QGraphicsScene()
		Return QGraphicsScene._find(bmx_qt_qgraphicsitem_scene(qObjectPtr))
	End Method
	
	Method sceneBoundingRect:QRectF()
		Return QRectF._create(bmx_qt_qgraphicsitem_sceneboundingrect(qObjectPtr))
	End Method
	
	Method scenePos(x:Double Var, y:Double Var)
		bmx_qt_qgraphicsitem_scenepos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method sceneTransform:QTransform()
		Return QTransform._create(bmx_qt_qgraphicsitem_scenetransform(qObjectPtr))
	End Method
	
	Method scroll(dx:Double, dy:Double, rect:QRectF = Null)
		If rect Then
			bmx_qt_qgraphicsitem_scroll(qObjectPtr, dx, dy, rect.qObjectPtr)
		Else
			bmx_qt_qgraphicsitem_scroll(qObjectPtr, dx, dy, Null)
		End If
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
	
	Method setGraphicsEffect(effect:QGraphicsEffect)
		bmx_qt_qgraphicsitem_setgraphicseffect(qObjectPtr, effect.qObjectPtr)
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
	
	Method update(rect:QRectF = Null)
		If rect Then
			bmx_qt_qgraphicsitem_update(qObjectPtr, rect.qObjectPtr)
		Else
			bmx_qt_qgraphicsitem_update(qObjectPtr, Null)
		End If
	End Method
	
	Function _Free()
	End Function


	Method contextMenuEvent(contextMenuEvent:QGraphicsSceneContextMenuEvent)
		bmx_qt_qgraphicsitem_defaultcontextmenuevent(qObjectPtr, contextMenuEvent.qObjectPtr)
	End Method
	
	Function _contextMenuEvent(item:QGraphicsItem, contextMenuEvent:Byte Ptr)
		item.contextMenuEvent(QGraphicsSceneContextMenuEvent._create(contextMenuEvent))
	End Function
	
	Method dragEnterEvent(event:QGraphicsSceneDragDropEvent)
		bmx_qt_qgraphicsitem_defaultdragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _dragEnterEvent(item:QGraphicsItem, event:Byte Ptr)
		item.dragEnterEvent(QGraphicsSceneDragDropEvent._create(event))
	End Function
	
	Method dragLeaveEvent(event:QGraphicsSceneDragDropEvent)
		bmx_qt_qgraphicsitem_defaultdragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _dragLeaveEvent(item:QGraphicsItem, event:Byte Ptr)
		item.dragLeaveEvent(QGraphicsSceneDragDropEvent._create(event))
	End Function
	
	Method dragMoveEvent(event:QGraphicsSceneDragDropEvent)
		bmx_qt_qgraphicsitem_defaultdragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _dragMoveEvent(item:QGraphicsItem, event:Byte Ptr)
		item.dragMoveEvent(QGraphicsSceneDragDropEvent._create(event))
	End Function

	Method dropEvent(event:QGraphicsSceneDragDropEvent)
		bmx_qt_qgraphicsitem_defaultdropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _dropEvent(item:QGraphicsItem, event:Byte Ptr)
		item.dropEvent(QGraphicsSceneDragDropEvent._create(event))
	End Function
	
	Method focusInEvent(focusEvent:QFocusEvent)
		bmx_qt_qgraphicsitem_defaultfocusinevent(qObjectPtr, focusEvent.qObjectPtr)
	End Method
	
	Function _focusInEvent(item:QGraphicsItem, focusEvent:Byte Ptr)
		item.focusInEvent(QFocusEvent._create(focusEvent))
	End Function
	
	Method focusOutEvent(focusEvent:QFocusEvent)
		bmx_qt_qgraphicsitem_defaultfocusoutevent(qObjectPtr, focusEvent.qObjectPtr)
	End Method
	
	Function _focusOutEvent(item:QGraphicsItem, focusEvent:Byte Ptr)
		item.focusOutEvent(QFocusEvent._create(focusEvent))
	End Function
	
	Method hoverEnterEvent(hoverEvent:QGraphicsSceneHoverEvent)
		bmx_qt_qgraphicsitem_defaulthoverenterevent(qObjectPtr, hoverEvent.qObjectPtr)
	End Method
	
	Function _hoverEnterEvent(item:QGraphicsItem, hoverEvent:Byte Ptr)
		item.hoverEnterEvent(QGraphicsSceneHoverEvent._create(hoverEvent))
	End Function
	
	Method hoverLeaveEvent(hoverEvent:QGraphicsSceneHoverEvent)
		bmx_qt_qgraphicsitem_defaulthoverleaveevent(qObjectPtr, hoverEvent.qObjectPtr)
	End Method
	
	Function _hoverLeaveEvent(item:QGraphicsItem, hoverEvent:Byte Ptr)
		item.hoverLeaveEvent(QGraphicsSceneHoverEvent._create(hoverEvent))
	End Function
	
	Method hoverMoveEvent(hoverEvent:QGraphicsSceneHoverEvent)
		bmx_qt_qgraphicsitem_defaulthovermoveevent(qObjectPtr, hoverEvent.qObjectPtr)
	End Method
	
	Function _hoverMoveEvent(item:QGraphicsItem, hoverEvent:Byte Ptr)
		item.hoverMoveEvent(QGraphicsSceneHoverEvent._create(hoverEvent))
	End Function
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qgraphicsitem_defaultinputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _inputMethodEvent(item:QGraphicsItem, event:Byte Ptr)
		item.inputMethodEvent(QInputMethodEvent._create(event))
	End Function
	
	Method keyPressEvent(keyEvent:QKeyEvent)
		bmx_qt_qgraphicsitem_defaultkeypressevent(qObjectPtr, keyEvent.qObjectPtr)
	End Method
	
	Function _keyPressEvent(item:QGraphicsItem, keyEvent:Byte Ptr)
		item.keyPressEvent(QKeyEvent._create(keyEvent))
	End Function
	
	Method keyReleaseEvent(keyEvent:QKeyEvent)
		bmx_qt_qgraphicsitem_defaultkeyreleaseevent(qObjectPtr, keyEvent.qObjectPtr)
	End Method
	
	Function _keyReleaseEvent(item:QGraphicsItem, keyEvent:Byte Ptr)
		item.keyReleaseEvent(QKeyEvent._create(keyEvent))
	End Function
	
	Method mouseDoubleClickEvent(mouseEvent:QGraphicsSceneMouseEvent)
		bmx_qt_qgraphicsitem_defaultmousedoubleclickevent(qObjectPtr, mouseEvent.qObjectPtr)
	End Method
	
	Function _mouseDoubleClickEvent(item:QGraphicsItem, mouseEvent:Byte Ptr)
		item.mouseDoubleClickEvent(QGraphicsSceneMouseEvent._create(mouseEvent))
	End Function
	
	Method mouseMoveEvent(mouseEvent:QGraphicsSceneMouseEvent)
		bmx_qt_qgraphicsitem_defaultmousemoveevent(qObjectPtr, mouseEvent.qObjectPtr)
	End Method
	
	Function _mouseMoveEvent(item:QGraphicsItem, mouseEvent:Byte Ptr)
		item.mouseMoveEvent(QGraphicsSceneMouseEvent._create(mouseEvent))
	End Function
	
	Method mousePressEvent(mouseEvent:QGraphicsSceneMouseEvent)
		bmx_qt_qgraphicsitem_defaultmousepressevent(qObjectPtr, mouseEvent.qObjectPtr)
	End Method
	
	Function _mousePressEvent(item:QGraphicsItem, mouseEvent:Byte Ptr)
		item.mousePressEvent(QGraphicsSceneMouseEvent._create(mouseEvent))
	End Function
	
	Method mouseReleaseEvent(mouseEvent:QGraphicsSceneMouseEvent)
		bmx_qt_qgraphicsitem_defaultmousereleaseevent(qObjectPtr, mouseEvent.qObjectPtr)
	End Method
	
	Function _mouseReleaseEvent(item:QGraphicsItem, mouseEvent:Byte Ptr)
		item.mouseReleaseEvent(QGraphicsSceneMouseEvent._create(mouseEvent))
	End Function

	Method sceneEvent(event:QEvent)
		bmx_qt_qgraphicsitem_defaultsceneevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _sceneEvent(item:QGraphicsItem, event:Byte Ptr)
		item.sceneEvent(QEvent._create(event))
	End Function

	Method sceneEventFilter(watched:QGraphicsItem, event:QEvent)
		bmx_qt_qgraphicsitem_defaultsceneeventfilter(qObjectPtr, watched.qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _sceneEventFilter(item:QGraphicsItem, watched:Byte Ptr, event:Byte Ptr)
		item.sceneEventFilter(QGraphicsItem._find(watched), QEvent._create(event))
	End Function

	Method wheelEvent(wheelEvent:QGraphicsSceneWheelEvent)
		bmx_qt_qgraphicsitem_defaultwheelevent(qObjectPtr, wheelEvent.qObjectPtr)
	End Method
	
	Function _wheelEvent(item:QGraphicsItem, wheelEvent:Byte Ptr)
		item.wheelEvent(QGraphicsSceneWheelEvent._create(wheelEvent))
	End Function


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

Type QGraphicsWidget Extends QGraphicsObjectItem


End Type


Type QGraphicsPixmapItem Extends QGraphicsItem

	Rem
	bbdoc: The shape is determined by calling QPixmap::mask().
	about: This shape includes only the opaque pixels of the pixmap. Because the shape is more complex, however,
	it can be slower than the other modes, and uses more memory.
	End Rem
	Const MaskShape:Int = 0
	Rem
	bbdoc: The shape is determined by tracing the outline of the pixmap.
	about: This is the fastest shape mode, but it does not take into account any transparent areas on the pixmap.
	End Rem
	Const BoundingRectShape:Int = 1
	Rem
	bbdoc: The shape is determine by calling QPixmap::createHeuristicMask().
	about: The performance and memory consumption is similar to MaskShape.
	End Rem
	Const HeuristicMaskShape:Int = 2

	Function _create:QGraphicsPixmapItem(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QGraphicsPixmapItem = New QGraphicsPixmapItem
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreatePixmapItem:QGraphicsPixmapItem(pixmap:QPixmap, parent:QGraphicsItem = Null)
		Return New QGraphicsPixmapItem.Create(pixmap, parent)
	End Function

	Method Create:QGraphicsPixmapItem(pixmap:QPixmap, parent:QGraphicsItem = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicspixmapitem_create(Self, pixmap.qObjectPtr, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicspixmapitem_create(Self, pixmap.qObjectPtr, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method offset(x:Double Var, y:Double Var)
	End Method	
	
	Method pixmap:QPixmap()
	End Method
	
	Method setOffset(x:Double, y:Double)
	End Method
	
	Method setPixmap(pixmap:QPixmap)
	End Method
	
	Method setShapeMode(_mode:Int)
	End Method
	
	Method shapeMode:Int()
	End Method
	
	Method transformationMode:Int()
	End Method
	
End Type



Extern
	Function bmx_qt_qgraphicsscene_selecteditems:QGraphicsItem[](handle:Byte Ptr)
End Extern

