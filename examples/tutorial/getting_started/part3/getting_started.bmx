SuperStrict

Framework Qt.QApplication
Import Qt.QTextEdit
Import Qt.QPushButton
Import Qt.QVBoxLayout
Import Qt.QMessageBox

Local app:QApplication = New QApplication.Create()

Local notepad:TNotepad = New TNotepad.Create()
notepad.show()

app.exec()

End

Type TNotepad Extends QWidget

	Field textEdit:QTextEdit
	Field quitButton:QPushButton
	
	Method Create:TNotepad()
		Return TNotepad(Super._Create())
	End Method

	Method OnInit()
		textEdit = New QTextEdit.Create()
		quitButton = New QPushButton.Create(tr("Quit"))
		
		connect(quitButton, "clicked", Self, "quit")
		
		Local layout:QVBoxLayout = New QVBoxLayout.Create()
		layout.addWidget(textEdit)
		layout.addWidget(quitButton)
		
		setLayout(layout)
		
		setWindowTitle(tr("Notepad"))
		
	End Method
	
	Method quit()
		Local messageBox:QMessageBox = New QMessageBox.Create()
		messageBox.setWindowTitle(tr("Notepad"))
		messageBox.setText(tr("Do you really want to quit?"))
		messageBox.setStandardButtons(QMessageBox.Button_Yes | QMessageBox.Button_No)
		messageBox.setDefaultButtonType(QMessageBox.Button_No)
		
		If messageBox.exec() = QMessageBox.Button_Yes Then
			qApp.quit()
		End If
	End Method

End Type


