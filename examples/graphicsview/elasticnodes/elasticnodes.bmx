SuperStrict

Framework Qt.QApplication
Import Qt.QGraphicsView
Import Qt.QStyleOptionGraphicsItem

Import BRL.LinkedList

Local app:QApplication = New QApplication.Create()

Local widget:TGraphWidget = New TGraphWidget.Create()
widget.show()

app.exec()

End

Type TGraphWidget Extends QGraphicsView

	Field timerId:Int
	Field centerNode:TNode
	
	Method Create:TGraphWidget(parent:QWidget = Null)
		Return TGraphWidget(Super._Create(parent))
	End Method
	
	Method OnInit()
		Local scene:QGraphicsScene = New QGraphicsScene.Create(Self)
		scene.setItemIndexMethod(QGraphicsScene.NoIndex)
		scene.setSceneRect(-200, -200, 400, 400)
		setScene(scene)
		setCacheMode(CacheBackground)
		setViewportUpdateMode(BoundingRectViewportUpdate)
		setRenderHint(QPainter.Antialiasing)
		setTransformationAnchor(AnchorUnderMouse)
		setResizeAnchor(AnchorViewCenter)

		Local node1:TNode = New TNode.Create(Self)
		Local node2:TNode = New TNode.Create(Self)
		Local node3:TNode = New TNode.Create(Self)
		Local node4:TNode = New TNode.Create(Self)
		centerNode = New TNode.Create(Self)
		Local node6:TNode = New TNode.Create(Self)
		Local node7:TNode = New TNode.Create(Self)
		Local node8:TNode = New TNode.Create(Self)
		Local node9:TNode = New TNode.Create(Self)
		scene.addItem(node1)
		scene.addItem(node2)
		scene.addItem(node3)
		scene.addItem(node4)
		scene.addItem(centerNode)
		scene.addItem(node6)
		scene.addItem(node7)
		scene.addItem(node8)
		scene.addItem(node9)
		scene.addItem(New TEdge.Create(node1, node2))
		scene.addItem(New TEdge.Create(node2, node3))
		scene.addItem(New TEdge.Create(node2, centerNode))
		scene.addItem(New TEdge.Create(node3, node6))
		scene.addItem(New TEdge.Create(node4, node1))
		scene.addItem(New TEdge.Create(node4, centerNode))
		scene.addItem(New TEdge.Create(centerNode, node6))
		scene.addItem(New TEdge.Create(centerNode, node8))
		scene.addItem(New TEdge.Create(node6, node9))
		scene.addItem(New TEdge.Create(node7, node4))
		scene.addItem(New TEdge.Create(node8, node7))
		scene.addItem(New TEdge.Create(node9, node8))
		
		node1.setPos(-50, -50)
		node2.setPos(0, -50)
		node3.setPos(50, -50)
		node4.setPos(-50, 0)
		centerNode.setPos(0, 0)
		node6.setPos(50, 0)
		node7.setPos(-50, 50)
		node8.setPos(0, 50)
		node9.setPos(50, 50)
		
		scale(0.8, 0.8)
		setMinimumSize(400, 400)
		setWindowTitle(tr("Elastic Nodes"))
	End Method

	Method itemMoved()
		If Not timerId Then
	         	timerId = startTimer(1000 / 25)
		End If
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
	End Method
	
	Method timerEvent(event:QTimerEvent)
		Local nodes:TList = New TList
		
		For Local node:TNode = EachIn scene().items()
			node.calculateForces()
			nodes.AddLast(node)
		Next
		
		Local itemsMoved:Int = False
		For node:TNode = EachIn nodes
			If node.advance() Then
				itemsMoved = True
			End If
		Next
		
		If Not itemsMoved Then
			killTimer(timerId)
			timerId = 0
		End If
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		scaleView(2.0 ^ (-event.delta() / 240.0))
	End Method
	
	Method drawBackground(painter:QPainter, rect:QRectF)
		' Shadow
		Local sceneRect:QRectF = Self.sceneRect()
		Local rightShadow:QRectF = New QRectF.Create(sceneRect.Right(), sceneRect.top() + 5, 5, sceneRect.height())
		Local bottomShadow:QRectF = New QRectF.Create(sceneRect.Left() + 5, sceneRect.bottom(), sceneRect.width(), 5)
		If rightShadow.intersects(rect) Or rightShadow.contains(rect) Then
			painter.fillRect(rightShadow, Qt_darkGray)
		End If
		If bottomShadow.intersects(rect) Or bottomShadow.contains(rect) Then
			painter.fillRect(bottomShadow, Qt_darkGray)
		End If
		
		' Fill
		Local gradient:QLinearGradient = New QLinearGradient.Create(sceneRect.topLeft(), sceneRect.bottomRight())
		gradient.setColorAt(0, Qt_white)
		gradient.setColorAt(1, Qt_lightGray)
		painter.fillRect(rect.intersect(sceneRect), gradient)
		painter.setBrush(Qt_NoBrush)
		painter.DrawRect(sceneRect)
		
		' Text
		Local textRect:QRectF = New QRectF.Create(sceneRect.Left() + 4, sceneRect.top() + 4, sceneRect.width() - 4, sceneRect.height() - 4)
		Local message:String = tr("Click and drag the nodes around, and zoom with the mouse wheel or the '+' and '-' keys")
		
		Local font:QFont = painter.font()
		font.setBold(True)
		font.setPointSize(14)
		painter.setFont(font)
		painter.setPen(Qt_lightGray)
		painter.DrawText(textRect.translated(2, 2), message)
		painter.setPen(Qt_black)
		painter.DrawText(textRect, message)
	End Method
	
	Method scaleView(scaleFactor:Float)
		Local factor:Double = matrix().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width()
		If factor < 0.07 Or factor > 100 Then
			Return
		End If
		
		scale(scaleFactor, scaleFactor)
	End Method

End Type


Type TNode Extends QGraphicsItem

	Field edgeList:TList = New TList
	Field newPosX:Float, newPosY:Float
	Field graph:TGraphWidget

	Method CreateItem:TNode(parent:QGraphicsItem = Null)
		Return TNode(Super.CreateItem(parent))
	End Method

	'QVariant itemChange(GraphicsItemChange change, Const QVariant &value);

	Method mousePressEvent(event:QGraphicsSceneMouseEvent)
		update()
		Super.mousePressEvent(event)
	End Method
	
	Method mouseReleaseEvent(event:QGraphicsSceneMouseEvent)
		update()
		Super.mouseReleaseEvent(event)
	End Method

	Method boundingRect:QRectF()
		Local adjust:Float = 2
		Return New QRectF.Create(-10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust)
 	End Method
	
	Method shape:QPainterPath()
		Local path:QPainterPath = New QPainterPath.Create()
		path.addEllipse(-10, -10, 20, 20)
		Return path
	End Method
	
	Method paint(painter:QPainter, option:QStyleOptionGraphicsItem, widget:QWidget)
		painter.setPenStyle(Qt_NoPen)
		painter.setBrushColor(New QColor.CreateWithGlobalColor(Qt_darkGray))
		painter.drawEllipse(-7, -7, 20, 20)
		
		Local gradient:QRadialGradient = New QRadialGradient.Create(-3, -3, 10)
		If (option.getState() & QStyle.State_Sunken) Then
			gradient.setCenter(3, 3)
			gradient.setFocalPoint(3, 3)
			gradient.setColorAt(1, New QColor.CreateWithGlobalColor(Qt_yellow).lighter(120))
			gradient.setColorAt(0, New QColor.CreateWithGlobalColor(Qt_darkYellow).lighter(120))
		Else
			gradient.setColorAt(0, New QColor.CreateWithGlobalColor(Qt_yellow))
			gradient.setColorAt(1, New QColor.CreateWithGlobalColor(Qt_darkYellow))
		End If
		painter.setBrush(New QBrush.CreateWithGradient(gradient))
		painter.setPen(New QPen.CreateWithAttributes(New QBrush.CreateWithGlobalColor(Qt_black), 0))
		painter.drawEllipse(-10, -10, 20, 20)
	End Method

	Method calculateForces()
		If Not scene() Or scene().mouseGrabberItem() = Self Then
			pos(newPosX, newPosY)
			Return
		End If
		
		' Sum up all forces pushing this item away
		Local xvel:Float = 0
		Local yvel:Float = 0
		Local x1:Float, y1:Float
		For Local node:TNode = EachIn scene().items()
			mapFromItem(node, 0, 0, x1, y1)
			Local line:QLineF = New QLineF.Create(x1, y1, 0, 0)
			Local dx:Float = line.dx()
			Local dy:Float = line.dy()
			Local  l:Double = 2.0 * (dx * dx + dy * dy)
			If l > 0 Then
				xvel :+ (dx * 150.0) / l
				yvel :+ (dy * 150.0) / l
			End If
		Next
		
		' Now subtract all forces pulling items together
		Local weight:Double = (edgeList.count() + 1) * 10
		Local posX:Float, posY:Float
		For Local edge:TEdge = EachIn edgeList
			If edge.sourceNode() = Self Then
				mapFromItem(edge.destNode(), 0, 0, posX, posY)
			Else
				mapFromItem(edge.sourceNode(), 0, 0, posX, posY)
			End If
			xvel :+ posX / weight
			yvel :+ posY / weight
		Next
		
		If Abs(xvel) < 0.1 And Abs(yvel) < 0.1 Then
			xvel = 0
			yvel = 0
		End If
		
		Local sceneRect:QRectF = scene().sceneRect()
		'newPos = pos() + QPointF(xvel, yvel);
		'newPos.setX(qMin(qMax(newPos.x(), sceneRect.Left() + 10), sceneRect.Right() - 10));
		'newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));

	End Method
	
	Method advance:Int()
		Local x:Float, y:Float
		pos(x, y)
		
		If newPosX = x And newPosY = y Then
			Return False
		End If
	
		setPos(newPosX, newPosY)
		Return True
	End Method

	Method addEdge(edge:TEdge)
		edgeList.AddLast(edge)
		edge.adjust()
	End Method
	
	Method edges:TList()
		Return edgeList
	End Method

End Type


Type TEdge Extends QGraphicsItem

	Field source:TNode
	Field dest:TNode
	
	Field sourcePointX:Float, sourcePointY:Float
	Field destPointX:Float, destPointY:Float
	Field arrowSize:Float

	Method boundingRect:QRectF()
		If Not source Or Not dest Then
			Return Null
		End If
		
		Local penWidth:Float = 1
		Local extra:Float = (penWidth + arrowSize) / 2.0
		
		Return New QRectF.Create(sourcePointX, sourcePointY, destPointX - sourcePointX, ..
			destPointY - sourcePointY).normalized().adjusted(-extra, -extra, extra, extra)
	End Method
	
	Method paint(painter:QPainter, option:QStyleOptionGraphicsItem, widget:QWidget)
	End Method

	Method sourceNode:TNode()
		Return source
	End Method
	
	Method setSourceNode(node:TNode)
		source = node
		adjust()
	End Method
	
	Method destNode:TNode()
		Return dest
	End Method
	
	Method setDestNode(node:TNode)
		dest = node
		adjust()
	End Method
	
	Method adjust()
		If Not source Or Not dest Then
			Return
		End If
		
		Local x1:Float, y1:Float, x2:Float, y2:Float
		mapFromItem(source, 0, 0, x1, y1)
		mapFromItem(dest, 0, 0, x2, y2)
		Local line:QLineF = New QLineF.Create(x1, y1, x2, y2)
		Local length:Float = line.length()
		
		prepareGeometryChange()
		
		If length > 20.0 Then
			Local edgeOffsetX:Float = (line.dx() * 10) / length
			Local edgeOffsetY:Float = (line.dy() * 10) / length
			
			line.p1(x1, y1)
			sourcePointX = x1 + edgeOffsetX
			sourcePointY = y1 + edgeOffsetY
			
			line.p2(x2, y2)
			destPointX = x2 - edgeOffsetX
			destPointY = y2 - edgeOffsetY
		Else
			line.p1(x1, y1)
			sourcePointX = x1
			sourcePointY = y1
			destPointX = x1
			destPointY = y1
		End If
	End Method

End Type
