SuperStrict

Import Qt.QUndoCommand
Import Qt.QGraphicsView

Import "scene.bmx"


Type TMoveCommand Extends QUndoCommand

	Const _Id:Int = 1234

	Field myDiagramItem:TDiagramItem
	Field myOldPosX:Float
	Field myOldPosY:Float
	Field newPosX:Float
	Field newPosY:Float

	Method CreateWithPos:TMoveCommand(item:TDiagramItem, x:Float, y:Float, parent:QUndoCommand = Null)
		Super.Create(parent)
		myDiagramItem = item
		item.pos(newPosX, newPosY)
		myOldPosX = x
		myOldPosY = y
		Return Self
	End Method

	Method undo()
		myDiagramItem.setPos(myOldPosX, myOldPosY)
		myDiagramItem.scene().update()
		setText(QObject.tr("Move " + createCommandString(myDiagramItem, newPosX, newPosY)))
	End Method
	
	Method redo()
		myDiagramItem.setPos(newPosX, newPosY)
		setText(QObject.tr("Move " + createCommandString(myDiagramItem, newPosX, newPosY)))
	End Method

	Method mergeWith:Int(command:QUndoCommand)
		Local moveCommand:TMoveCommand = TMoveCommand(command)
		Local item:TDiagramItem = moveCommand.myDiagramItem
		
		If myDiagramItem <> item Then
			Return False
		End If
		
		item.pos(newPosX, newPosY)
		setText(QObject.tr("Move " + createCommandString(myDiagramItem, newPosX, newPosY)))
		
		Return True
	End Method
	
	Method id:Int()
		Return _Id
	End Method
	
End Type

Type TDeleteCommand Extends QUndoCommand

	Field myDiagramItem:TDiagramItem
	Field myGraphicsScene:QGraphicsScene

	Method CreateWithScene:TDeleteCommand(scene:QGraphicsScene, parent:QUndoCommand = Null)
		myGraphicsScene = scene
		Super.Create(parent)
		
		Local list:QGraphicsItem[] = myGraphicsScene.selectedItems()
		list[0].setSelected(False)
		myDiagramItem = TDiagramItem(list[0])
		
		Local x:Float, y:Float
		myDiagramItem.pos(x, y)
		
		setText(QObject.tr("Delete " + createCommandString(myDiagramItem, x, y)))
		
		Return Self
	End Method
	
	Method undo()
		myGraphicsScene.addItem(myDiagramItem)
		myGraphicsScene.update()
	End Method
	
	Method redo()
		myGraphicsScene.removeItem(myDiagramItem)
	End Method

End Type

Type TAddCommand Extends QUndoCommand

	Field myDiagramItem:TDiagramItem
	Field myGraphicsScene:QGraphicsScene
	Field initialPositionX:Float
	Field initialPositionY:Float

	Method CreateWithScene:TAddCommand(addType:Int, scene:QGraphicsScene, parent:QUndoCommand = Null)
		Super.Create(parent)
		
		Global itemCount:Int = 0
		
		myGraphicsScene = scene
		myDiagramItem = New TDiagramItem.CreateItem(addType)
		initialPositionX = (itemCount * 15) Mod scene.width()
		initialPositionY = (itemCount * 15) Mod scene.height()
		scene.update()
		itemCount:+ 1
		
		setText(QObject.tr("Add " + createCommandString(myDiagramItem, initialPositionX, initialPositionY)))

		Return Self
	End Method
	
	Method undo()
		myGraphicsScene.removeItem(myDiagramItem)
		myGraphicsScene.update()
	End Method
	
	Method redo()
		myGraphicsScene.addItem(myDiagramItem)
		myDiagramItem.setPos(initialPositionX, initialPositionY)
		myGraphicsScene.clearSelection()
		myGraphicsScene.update()
	End Method

End Type

Function createCommandString:String(item:TDiagramItem, x:Float, y:Float)
	Local text:String
	If item.diagramType = TDiagramItem.Box Then
		text:+ "Box"
	Else
		text:+ "Triangle"
	End If
	text:+ " at (" + Int(x) + ", " + Int(y) + ")"
	Return text
End Function
