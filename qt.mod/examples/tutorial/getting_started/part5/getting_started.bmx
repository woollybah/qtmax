SuperStrict

Framework Qt.QApplication
Import Qt.QTextEdit
Import Qt.QMainWindow
Import Qt.QFile
Import Qt.QTextStream
Import Qt.QFileDialog
Import Qt.QMessageBox

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
		Local fileName:String = QFileDialog.getOpenFileName(Self, tr("Open File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"))

		If fileName Then
			Local file:QFile = New QFile.Create(fileName)
			If Not file.open(QIODevice.ReadOnly) Then
				QMessageBox.critical(Self, tr("Error"), tr("Could not open file"))
				Return
			End If
			Local in:QTextStream = New QTextStream.Create(file)
			textEdit.setText(in.readAll())
			file.close()
		End If
		
	End Method

	Method save()
		Local fileName:String = QFileDialog.getSaveFileName(Self, tr("Save File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"))
		
		If fileName Then
			Local file:QFile = New QFile.Create(fileName)
			If Not file.open(QIODevice.WriteOnly) Then
				' error message
			Else
				Local stream:QTextStream = New QTextStream.Create(file)
				stream.WriteString(textEdit.toPlainText())
				stream.flush()
				file.close()
			End If
		End If
	End Method
	
End Type
