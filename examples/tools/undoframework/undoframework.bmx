SuperStrict

Framework Qt.QApplication
Import Qt.QMainWindow
Import Qt.QUndoStack
Import Qt.QUndoView
Import Qt.QMessageBox
Import BRL.PNGLoader

Import "commands.bmx"


Global app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.CreateWindow()
window.show()

app.exec()

End

Type TWindow Extends QMainWindow

	Field deleteAction:QAction
	Field addBoxAction:QAction
	Field addTriangleAction:QAction
	Field undoAction:QAction
	Field redoAction:QAction
	Field exitAction:QAction
	Field aboutAction:QAction
	
	Field fileMenu:QMenu
	Field editMenu:QMenu
	Field itemMenu:QMenu
	Field helpMenu:QMenu
	
	Field diagramScene:TDiagramScene
	Field undoStack:QUndoStack
	Field undoView:QUndoView

	Field curFile:String

	Method CreateWindow:TWindow(filename:String = Null, parent:QWidget = Null, flags:Int = 0)
		Self.curFile = filename
		Return TWindow(Super.Create(parent, flags))
	End Method

	Method OnInit()
		undoStack = New QUndoStack.Create()

		createActions()
		createMenus()
		
		createUndoView()

		diagramScene = New TDiagramScene.Create()
		Local pixmapBrush:QBrush = New QBrush.CreateWithPixmap(QPixmap.FromPixmap(LoadPixmap("images/cross.png")))
		diagramScene.setBackgroundBrush(pixmapBrush)
		diagramScene.setSceneRect(New QRectF.Create(0, 0, 500, 500))
		
		connect(diagramScene, "itemMoved", Self, "itemMoved")
		
		setWindowTitle("Undo Framework")
		Local view:QGraphicsView = New QGraphicsView.CreateWithScene(diagramScene)
		setCentralWidget(view)
		resize(700, 500)

	End Method
	
	Method createActions()
		deleteAction = New QAction.Create(tr("&Delete Item"), Self)
		deleteAction.setShortcut(tr("Del"))
		connect(deleteAction, "triggered", Self, "deleteItem")
		
		addBoxAction = New QAction.Create(tr("Add &Box"), Self)
		addBoxAction.setShortcut(tr("Ctrl+O"))
		connect(addBoxAction, "triggered", Self, "addBox")
		
		addTriangleAction = New QAction.Create(tr("Add &Triangle"), Self)
		addTriangleAction.setShortcut(tr("Ctrl+T"))
		connect(addTriangleAction, "triggered", Self, "addTriangle")
		
		undoAction = undoStack.createUndoAction(Self, tr("&Undo"))
		undoAction.setShortcut(tr("Ctrl+Z"))
		
		redoAction = undoStack.createRedoAction(Self, tr("&Redo"))
		'QList<QKeySequence> redoShortcuts
		'redoShortcuts << tr("Ctrl+Y") << tr("Shift+Ctrl+Z")
		'redoAction.setShortcuts(redoShortcuts)
		
		exitAction = New QAction.Create(tr("E&xit"), Self)
		exitAction.setShortcut(tr("Ctrl+Q"))
		connect(exitAction, "triggered", Self, "close")
		
		aboutAction = New QAction.Create(tr("&About"), Self)
		'QList<QKeySequence> aboutShortcuts
		'aboutShortcuts << tr("Ctrl+A") << tr("Ctrl+B")
		'aboutAction.setShortcuts(aboutShortcuts)
		connect(aboutAction, "triggered", Self, "about")
	End Method
	
	Method createMenus()
		fileMenu = menuBar().addMenu(tr("&File"))
		fileMenu.addAction(exitAction)
		
		editMenu = menuBar().addMenu(tr("&Edit"))
		editMenu.addAction(undoAction)
		editMenu.addAction(redoAction)
		editMenu.addSeparator()
		editMenu.addAction(deleteAction)
		connect(editMenu, "aboutToShow", Self, "itemMenuAboutToShow")
		connect(editMenu, "aboutToHide", Self, "itemMenuAboutToHide")
		
		itemMenu = menuBar().addMenu(tr("&Item"))
		itemMenu.addAction(addBoxAction)
		itemMenu.addAction(addTriangleAction)
		
		helpMenu = menuBar().addMenu(tr("&Help"))
		helpMenu.addAction(aboutAction)

	End Method
	
	Method createUndoView()
		undoView = New QUndoView.CreateWithStack(undoStack)
		undoView.setWindowTitle(tr("Command List"))
		undoView.show()
		undoView.setAttribute(Qt_WA_QuitOnClose, False)
	End Method
	
	Method deleteItem()
		If Not diagramScene.selectedItems().length Then
			Return
		End If
		
		Local deleteCommand:QUndoCommand = New TDeleteCommand.CreateWithScene(diagramScene)
		undoStack.push(deleteCommand)
	End Method
	
	Method addBox()
		Local addCommand:QUndoCommand = New TAddCommand.CreateWithScene(TDiagramItem.Box, diagramScene)
		undoStack.push(addCommand)
	End Method
	
	Method addTriangle()
		Local addCommand:QUndoCommand = New TAddCommand.CreateWithScene(TDiagramItem.Triangle, diagramScene)
		undoStack.push(addCommand)
	End Method
	
	Method about()
		QMessageBox.about(Self, tr("About Undo"), tr("The <b>Undo</b> example demonstrates how to use Qt's undo framework."))
	End Method
	
	Method itemMenuAboutToShow()
		deleteAction.setEnabled(diagramScene.selectedItems().length > 0)
	End Method
	
	Method itemMenuAboutToHide()
		deleteAction.setEnabled(True)
	End Method

	Method itemMoved(movedItem:TDiagramItem, moveStartPositionX:Float, moveStartPositionY:Float)
		undoStack.push(New TMoveCommand.CreateWithPos(movedItem, moveStartPositionX, moveStartPositionY))
 	End Method
	
End Type

