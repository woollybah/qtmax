SuperStrict

Framework Qt.QApplication
Import Qt.QWidget
Import Qt.QLabel
Import Qt.QLineEdit
Import Qt.QTextEdit
Import Qt.QGridLayout
Import Qt.QPushButton
Import Qt.QVBoxLayout

Import BRL.Map

Local app:QApplication = New QApplication.Create()

Local addressBook:TAddressBook = New TAddressbook.Create()
addressBook.show()

app.exec()

End

Type TAddressbook Extends QWidget

	Field nameLine:QLineEdit
	Field addressText:QTextEdit

	Field addButton:QPushButton
	Field submitButton:QPushButton
	Field cancelButton:QPushButton
	
	Field contacts:TMap = New TMap
	Field oldName:String
	Field oldAddress:String
	
	Method Create:TAddressbook()
		Return TAddressbook(Super._Create())
	End Method

	Method OnInit()
		Local nameLabel:QLabel = New QLabel.Create(tr("Name:"))
		nameLine = New QLineEdit.Create()
		nameLine.setReadOnly(True)
		
		Local addressLabel:QLabel = New QLabel.Create(tr("Address:"))
		addressText = New QTextEdit.Create()
		addressText.setReadOnly(True)
		
		addButton = New QPushButton.Create(tr("&Add"))
		addButton.show()
		submitButton = New QPushButton.Create(tr("&Submit"))
		submitButton.hide()
		cancelButton = New QPushButton.Create(tr("&Cancel"))
		cancelButton.hide()
		
		connect(addButton, "clicked", Self, "addContact")
		connect(submitButton, "clicked", Self, "submitContact")
		connect(cancelButton, "clicked", Self, "cancel")
		
		Local buttonLayout:QVBoxLayout = New QVBoxLayout.Create()
		buttonLayout.addWidget(addButton, Qt_AlignTop)
		buttonLayout.addWidget(submitButton)
		buttonLayout.addWidget(cancelButton)
		buttonLayout.addStretch()
		
		Local mainLayout:QGridLayout = New QGridLayout.Create()
		mainLayout.addWidget(nameLabel, 0, 0)
		mainLayout.addWidget(nameLine, 0, 1)
		mainLayout.addWidget(addressLabel, 1, 0, Qt_AlignTop)
		mainLayout.addWidget(addressText, 1, 1)
		mainLayout.addLayout(buttonLayout, 1, 2)
		
		setLayout(mainLayout)
		setWindowTitle(tr("Simple Address Book"))
		
	End Method

	Method addContact()
		oldName = nameLine.text()
		oldAddress = addressText.toPlainText()

		nameLine.clear()
		addressText.clear()
		
		nameLine.setReadOnly(False)
		nameLine.SetFocus(Qt_OtherFocusReason)
		addressText.setReadOnly(False)
		
		addButton.setEnabled(False)
		submitButton.show()
		cancelButton.show()
	End Method
	
	Method submitContact()
		Local name:String = nameLine.text()
		Local address:String = addressText.toPlainText()
		
		If Not name Or Not address Then
			QMessageBox.information(Self, tr("Empty Field"), tr("Please enter a name and address."))
			Return
		End If
		
		If Not contacts.Contains(name) Then
			contacts.insert(name, address)
			QMessageBox.information(Self, tr("Add Successful"), tr_arg(tr("~q%1~q has been added to your address book."), [name]))
		Else
			QMessageBox.information(Self, tr("Add Unsuccessful"), tr_arg(tr("Sorry, ~q%1~q is already in your address book."), [name]))
			Return
		End If


		If contacts.IsEmpty() Then
			nameLine.clear()
			addressText.clear()
		End If
		
		nameLine.setReadOnly(True)
		addressText.setReadOnly(True)
		addButton.setEnabled(True)
		submitButton.hide()
		cancelButton.hide()
	End Method
	
	Method cancel()
		nameLine.setText(oldName)
		nameLine.setReadOnly(True)
		
		addressText.setText(oldAddress)
		addressText.setReadOnly(True)
		
		addButton.setEnabled(True)
		submitButton.hide()
		cancelButton.hide()
	End Method
	
End Type

