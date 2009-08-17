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
	
	Method Create:QGraphicsView(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgraphicsview_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgraphicsview_create(Self, Null)
		End If
		OnInit
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

	Method paintEvent(event:QPaintEvent)
		bmx_qt_qgraphicsview_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Rem
	bbdoc: 
	End Rem
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qgraphicsview_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Rem
	bbdoc: 
	End Rem
	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qgraphicsview_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Rem
	bbdoc: 
	End Rem
	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qgraphicsview_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Rem
	bbdoc: 
	End Rem
	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qgraphicsview_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

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
	
	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qgraphicsview_default_focusoutevent(qObjectPtr, event.qObjectPtr)
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
	
	Method moveEvent(event:QMoveEvent)
		bmx_qt_qgraphicsview_default_moveevent(qObjectPtr, event.qObjectPtr)
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

	Method setSceneRect(rect:QRectF)
		bmx_qt_qgraphicsscene_setscenerect(qObjectPtr, rect.qObjectPtr)
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
	' TODO
	End Method

End Type
