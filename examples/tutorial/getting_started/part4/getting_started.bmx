SuperStrict

Framework Qt.QApplication
Import Qt.QTextEdit
Import Qt.QMainWindow

Local app:QApplication = New QApplication.Create()

Local notepad:TNotepad = New TNotepad.Create()
notepad.show()

app.exec()

End

Type TNotepad Extends QMainWindow

	Field textEdit:QTextEdit

	Field openAction:QAction
	Field saveAction:QAction
	Field exitAction:QAction

	Field fileMenu:QMenu
	
	
	Method Create:TNotepad(parent:QWidget = Null, flags:Int = 0)
		Return TNotepad(Super.Create(parent, flags))
	End Method

	Method OnInit()

		openAction = New QAction.Create(tr("&Open"), Self)
		saveAction = New QAction.Create(tr("&Save"), Self)
		exitAction = New QAction.Create(tr("E&xit"), Self)
		
		connect(openAction, "triggered", Self, "open")
		connect(saveAction, "triggered", Self, "save")
		connect(exitAction, "triggered", qApp, "quit")

		fileMenu = menuBar().addMenu(tr("&File"))
		fileMenu.addAction(openAction)
		fileMenu.addAction(saveAction)
		fileMenu.addSeparator()
		fileMenu.addAction(exitAction)

		textEdit = New QTextEdit.Create()
		setCentralWidget(textEdit)

		setWindowTitle(tr("Notepad"))
		
	End Method
	
	Method open()
	End Method
	
	Method save()
	End Method
	
End Type
