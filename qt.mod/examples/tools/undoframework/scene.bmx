SuperStrict

Import Qt.QGraphicsView
Import Qt.QGraphicsPolygonItem
Import BRL.Random

Type TDiagramScene Extends QGraphicsScene

	Field movingItem:QGraphicsItem
	Field oldPosX:Float
	Field oldPosY:Float
	
	Method Create:TDiagramScene(parent:QObject = Null)
		Return TDiagramScene(Super.Create(parent))
	End Method

	Method itemMoved(movedItem:QGraphicsItem, movedFromPositionX:Float, movedFromPositionY:Float)
		_InvokeSignals("itemMoved", [Object(movedItem), Object(String(movedFromPositionX)), Object(String(movedFromPositionY))])
	End Method

	Method mousePressEvent(event:QGraphicsSceneMouseEvent)
	End Method
	
	Method mouseReleaseEvent(event:QGraphicsSceneMouseEvent)
		If movingItem And event.button() = Qt_LeftButton Then
			Local x:Float, y:Float
			movingItem.pos(x, y)
			
			If oldPosX <> x Or oldPosY <> y Then
				itemMoved(movingItem, oldPosX, oldPosY)
			End If
			movingItem = Null
		End If
		Super.mouseReleaseEvent(event)
	End Method

End Type

Type TDiagramItem Extends QGraphicsPolygonItem

	Const Box:Int = 0
	Const Triangle:Int = 1
	
	Field diagramType:Int

	Field boxPolygon:QPolygonF
	Field trianglePolygon:QPolygonF
	
	Method CreateItem:TDiagramItem(diagramType:Int, parent:QGraphicsItem = Null)
		Self.diagramType = diagramType
		Return TDiagramItem(Super.Create(parent))
	End Method
	
	Method OnInit()
		If diagramType = Box Then
			boxPolygon = New QPolygonF.Create()
			boxPolygon.append(0, 0).append(0, 30).append(30, 30).append(30, 0).append(0, 0)
			setPolygon(boxPolygon)
		Else
			trianglePolygon = New QPolygonF.Create()
			trianglePolygon.append(15, 0).append(30, 30).append(0, 30).append(15, 0)
			setPolygon(trianglePolygon)
		End If

		Local color:QColor = New QColor.Create(Rand(0, 255), Rand(0, 255), Rand(0, 255))
		Local brush:QBrush = New QBrush.CreateWithColor(color)
		setBrush(brush)
		
		setFlag(QGraphicsItem.ItemIsSelectable)
		setFlag(QGraphicsItem.ItemIsMovable)
	End Method
	
End Type
