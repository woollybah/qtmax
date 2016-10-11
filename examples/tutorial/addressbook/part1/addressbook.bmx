SuperStrict

Framework Qt.QApplication
Import Qt.QWidget
Import Qt.QLabel
Import Qt.QLineEdit
Import Qt.QTextEdit
Import Qt.QGridLayout

Local app:QApplication = New QApplication.Create()

Local addressBook:TAddressBook = New TAddressbook.Create()
addressBook.show()

app.exec()

End

Type TAddressbook Extends QWidget

	Field nameLine:QLineEdit
	Field addressText:QTextEdit
	
	Method Create:TAddressbook()
		Return TAddressbook(Super._Create())
	End Method

	Method OnInit()
		Local nameLabel:QLabel = New QLabel.Create(tr("Name:"))
		nameLine = New QLineEdit.Create()
		
		Local addressLabel:QLabel = New QLabel.Create(tr("Address:"))
		addressText = New QTextEdit.Create()
		
		Local mainLayout:QGridLayout = New QGridLayout.Create()
		mainLayout.addWidget(nameLabel, 0, 0)
		mainLayout.addWidget(nameLine, 0, 1)
		mainLayout.addWidget(addressLabel, 1, 0, Qt_AlignTop)
		mainLayout.addWidget(addressText, 1, 1)
		
		setLayout(mainLayout)
		setWindowTitle(tr("Simple Address Book"))
		
	End Method

End Type

