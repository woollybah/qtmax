SuperStrict

Framework Qt.QApplication
Import Qt.QMainWindow
Import Qt.QMenu
Import Qt.QLabel
Import Qt.QVBoxLayout
Import Qt.QTextEdit
Import Qt.QMessageBox
Import Qt.QFile
Import Qt.QTextStream
Import BRL.RamStream
Import BRL.PngLoader

Incbin "images/copy.png"
Incbin "images/save.png"
Incbin "images/cut.png"
Incbin "images/new.png"
Incbin "images/open.png"
Incbin "images/paste.png"

Global app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.CreateWindow()
window.show()

app.exec()

End

Type TWindow Extends QMainWindow

	Field textEdit:QTextEdit
	Field curFile:String
	Field isUntitled:Int
	
	Field fileMenu:QMenu
	Field editMenu:QMenu
	Field helpMenu:QMenu
	Field fileToolBar:QToolBar
	Field editToolBar:QToolBar
	Field newAct:QAction
	Field openAct:QAction
	Field saveAct:QAction
	Field saveAsAct:QAction
	Field closeAct:QAction
	Field exitAct:QAction
	Field cutAct:QAction
	Field copyAct:QAction
	Field pasteAct:QAction
	Field aboutAct:QAction
	Field aboutQtAct:QAction
	
	Method CreateWindow:TWindow(filename:String = Null, parent:QWidget = Null, flags:Int = 0)
		Self.curFile = filename
		Return TWindow(Super.Create(parent, flags))
	End Method

	Method OnInit()
		setAttribute(WA_DeleteOnClose)
		
		isUntitled = True
		
		textEdit = New QTextEdit.Create()
		setCentralWidget(textEdit)
		
		createActions()
		createMenus()
		createToolBars()
		createStatusBar()
		
		readSettings()
		
		connect(textEdit.document(), "contentsChanged", Self, "documentWasModified")
		
		setUnifiedTitleAndToolBarOnMac(True)

		
		If Not curFile Then
			setCurrentFile("")
		Else
			loadFile(curFile)
		End If
	End Method

	Method createActions()
		newAct = New QAction.CreateWithIcon(New QIcon.Create("incbin::images/new.png"), tr("&New"), Self)
		newAct.setShortcuts(QKeySequence.Key_New)
		newAct.setStatusTip(tr("Create a new file"))
		connect(newAct, "triggered", Self, "newFile")
		
		openAct = New QAction.CreateWithIcon(New QIcon.Create("Incbin::images/open.png"), tr("&Open..."), Self)
		openAct.setShortcuts(QKeySequence.Key_Open)
		openAct.setStatusTip(tr("Open an existing file"))
		connect(openAct,"triggered", Self, "open")
		
		saveAct = New QAction.CreateWithIcon(New QIcon.Create("Incbin::images/save.png"), tr("&Save"), Self)
		saveAct.setShortcuts(QKeySequence.Key_Save)
		saveAct.setStatusTip(tr("Save the document To disk"))
		connect(saveAct, "triggered", Self, "save")
		
		saveAsAct = New QAction.Create(tr("Save &As..."), Self)
		saveAsAct.setShortcuts(QKeySequence.Key_SaveAs)
		saveAsAct.setStatusTip(tr("Save the document under a New name"))
		connect(saveAsAct, "triggered", Self, "saveAs")
		
		closeAct = New QAction.Create(tr("&Close"), Self)
		closeAct.setShortcut(tr("Ctrl+W"))
		closeAct.setStatusTip(tr("Close Self window"))
		connect(closeAct, "triggered", Self, "close")
		
		exitAct = New QAction.Create(tr("E&xit"), Self)
		exitAct.setShortcut(tr("Ctrl+Q"))
		exitAct.setStatusTip(tr("Exit the application"))
		connect(exitAct, "triggered", app, "closeAllWindows")
		
		cutAct = New QAction.CreateWithIcon(New QIcon.Create("Incbin::images/cut.png"), tr("Cu&t"), Self)
		cutAct.setShortcuts(QKeySequence.Key_Cut)
		cutAct.setStatusTip(tr("Cut the Current selection's contents to the clipboard"))
		connect(cutAct, "triggered", textEdit, "cut")
		
		copyAct = New QAction.CreateWithIcon(New QIcon.Create("Incbin::images/copy.png"), tr("&Copy"), Self)
		copyAct.setShortcuts(QKeySequence.Key_Copy)
		copyAct.setStatusTip(tr("Copy the Current selection's contents to the clipboard"))
		connect(copyAct, "triggered", textEdit, "copy")
		
		pasteAct = New QAction.CreateWithIcon(New QIcon.Create("Incbin::images/paste.png"), tr("&Paste"), Self)
		pasteAct.setShortcuts(QKeySequence.Key_Paste)
		pasteAct.setStatusTip(tr("Paste the clipboard's contents into the current selection"))
		connect(pasteAct, "triggered", textEdit, "paste")
		
		aboutAct = New QAction.Create(tr("&About"), Self)
		aboutAct.setStatusTip(tr("Show the application's About box"))
		connect(aboutAct, "triggered", Self, "about")
		
		aboutQtAct = New QAction.Create(tr("About &Qt"), Self)
		aboutQtAct.setStatusTip(tr("Show the Qt library's About box"))
		connect(aboutQtAct, "triggered", app, "aboutQt")
		
		cutAct.setEnabled(False)
		copyAct.setEnabled(False)
		connect(textEdit,"copyAvailable", cutAct, "setEnabled")
		connect(textEdit, "copyAvailable", copyAct, "setEnabled")
	End Method
	
	Method createMenus()
		fileMenu = menuBar().addMenu(tr("&File"))
		fileMenu.addAction(newAct)
		fileMenu.addAction(openAct)
		fileMenu.addAction(saveAct)
		fileMenu.addAction(saveAsAct)
		fileMenu.addSeparator()
		fileMenu.addAction(closeAct)
		fileMenu.addAction(exitAct)
		
		editMenu = menuBar().addMenu(tr("&Edit"))
		editMenu.addAction(cutAct)
		editMenu.addAction(copyAct)
		editMenu.addAction(pasteAct)
		
		menuBar().addSeparator()
		
		helpMenu = menuBar().addMenu(tr("&Help"))
		helpMenu.addAction(aboutAct)
		helpMenu.addAction(aboutQtAct)
	End Method
	
	Method createToolBars()
		fileToolBar = addToolBar(tr("File"))
		fileToolBar.addAction(newAct)
		fileToolBar.addAction(openAct)
		fileToolBar.addAction(saveAct)
		
		editToolBar = addToolBar(tr("Edit"))
		editToolBar.addAction(cutAct)
		editToolBar.addAction(copyAct)
		editToolBar.addAction(pasteAct)
	End Method
	
	Method createStatusBar()
		statusBar().showMessage(tr("Ready"))
	End Method
	
	Method readSettings()
	End Method
	
	Method writeSettings()
	End Method
	
	Method maybeSave:Int()
			If textEdit.document().isModified() Then
			Local ret:Int = QMessageBox.warning(Self, tr("SDI"), tr("The document has been modified.~n" + ..
				"Do you want to save your changes?"), QMessageBox.Button_Save | QMessageBox.Button_Discard | QMessageBox.Button_Cancel)
			If ret = QMessageBox.Button_Save Then
				Return save()
			ElseIf ret = QMessageBox.Button_Cancel Then
				Return False
			End If
		End If
		Return True
	End Method
	
	Method loadFile(fileName:String)
		Local file:QFile = New QFile.Create(fileName)
		If Not file.open(QFile.ReadOnly | QFile.Text) Then
			QMessageBox.warning(Self, tr("SDI"), tr("Cannot read file " + fileName + ":~n" + file.errorString() + "."))
			Return
		End If
		
		Local in:QTextStream = New QTextStream.Create(file)
		QApplication.setOverrideCursor(New QCursor.Create(Qt_WaitCursor))
		textEdit.setPlainText(in.readAll())
		QApplication.restoreOverrideCursor()
		
		setCurrentFile(fileName)
		statusBar().showMessage(tr("File loaded"), 2000)
		
		file.Free()
	End Method
	
	Method saveFile:Int(fileName:String)
	End Method
	
	Method setCurrentFile(fileName:String)
	End Method
	
	Method strippedName:String(fullFileName:String)
	End Method
	
	Method findMainWindow:TWindow(fileName:String)
	End Method
	

	Method newFile()
		Local other:TWindow = New TWindow.CreateWindow()
		other.move(x() + 40, y() + 40)
		other.show()
	End Method
		
	Method open()
	End Method
		
	Method save:Int()
	End Method
		
	Method saveAs:Int()
	End Method
		
	Method about()
		QMessageBox.about(Self, tr("About SDI"), tr("The <b>SDI</b> example demonstrates how to write single document interface applications using Qt."))
	End Method
		
	Method documentWasModified()
		setWindowModified(True)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		If maybeSave() Then
			writeSettings()
			event.accept()
		Else
			event.ignore()
		End If
	End Method
	
End Type

