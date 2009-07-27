SuperStrict

Framework Qt.QApplication
Import Qt.QLineEdit
Import Qt.QGroupBox
Import Qt.QComboBox
Import Qt.QLabel
Import Qt.QGridLayout
Import Qt.QIntValidator
Import Qt.QDoubleValidator

Local app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.Create()
window.show()

app.exec()

End

Type TWindow Extends QWidget

	Field echoLineEdit:QLineEdit
	Field validatorLineEdit:QLineEdit
	Field alignmentLineEdit:QLineEdit
	Field inputMaskLineEdit:QLineEdit
	Field accessLineEdit:QLineEdit
	
	Method Create:TWindow()
		Return TWindow(Super._Create())
	End Method
	
	Method OnInit()

		Local echoGroup:QGroupBox = New QGroupBox.Create(tr("Echo"))
		
		Local echoLabel:QLabel = New QLabel.Create(tr("Mode:"))
		Local echoComboBox:QComboBox = New QComboBox.Create()
		echoComboBox.addItem(tr("Normal"))
		echoComboBox.addItem(tr("Password"))
		echoComboBox.addItem(tr("PasswordEchoOnEdit"))
		echoComboBox.addItem(tr("No Echo"))
		
		echoLineEdit = New QLineEdit.Create()
		echoLineEdit.SetFocus()


		Local validatorGroup:QGroupBox = New QGroupBox.Create(tr("Validator"))
		
		Local validatorLabel:QLabel = New QLabel.Create(tr("Type:"))
		Local validatorComboBox:QComboBox = New QComboBox.Create()
		validatorComboBox.addItem(tr("No validator"))
		validatorComboBox.addItem(tr("Integer validator"))
		validatorComboBox.addItem(tr("Double validator"))
		
		validatorLineEdit = New QLineEdit.Create()
		

		Local alignmentGroup:QGroupBox = New QGroupBox.Create(tr("Alignment"))
		
		Local alignmentLabel:QLabel = New QLabel.Create(tr("Type:"))
		Local alignmentComboBox:QComboBox = New QComboBox.Create()
		alignmentComboBox.addItem(tr("Left"))
		alignmentComboBox.addItem(tr("Centered"))
		alignmentComboBox.addItem(tr("Right"))
		
		alignmentLineEdit = New QLineEdit.Create()


		Local inputMaskGroup:QGroupBox = New QGroupBox.Create(tr("Input mask"))
		
		Local inputMaskLabel:QLabel = New QLabel.Create(tr("Type:"))
		Local inputMaskComboBox:QComboBox = New QComboBox.Create()
		inputMaskComboBox.addItem(tr("No mask"))
		inputMaskComboBox.addItem(tr("Phone number"))
		inputMaskComboBox.addItem(tr("ISO date"))
		inputMaskComboBox.addItem(tr("License key"))
		
		inputMaskLineEdit = New QLineEdit.Create()
		

		Local accessGroup:QGroupBox = New QGroupBox.Create(tr("Access"))
		
		Local accessLabel:QLabel = New QLabel.Create(tr("Read-only:"))
		Local accessComboBox:QComboBox = New QComboBox.Create()
		accessComboBox.addItem(tr("False"))
		accessComboBox.addItem(tr("True"))
		
		accessLineEdit = New QLineEdit.Create()
		

		connect(echoComboBox, "activated", Self, "echoChanged")
		connect(validatorComboBox, "activated", Self, "validatorChanged")
		connect(alignmentComboBox, "activated", Self, "alignmentChanged")
		connect(inputMaskComboBox, "activated", Self, "inputMaskChanged")
		connect(accessComboBox, "activated", Self, "accessChanged")
	

		Local echoLayout:QGridLayout = New QGridLayout.Create()
		echoLayout.addWidget(echoLabel, 0, 0)
		echoLayout.addWidget(echoComboBox, 0, 1)
		echoLayout.addWidgetSpan(echoLineEdit, 1, 0, 1, 2)
		echoGroup.setLayout(echoLayout)
		
		Local validatorLayout:QGridLayout = New QGridLayout.Create()
		validatorLayout.addWidget(validatorLabel, 0, 0)
		validatorLayout.addWidget(validatorComboBox, 0, 1)
		validatorLayout.addWidgetSpan(validatorLineEdit, 1, 0, 1, 2)
		validatorGroup.setLayout(validatorLayout)

		Local alignmentLayout:QGridLayout = New QGridLayout.Create()
		alignmentLayout.addWidget(alignmentLabel, 0, 0)
		alignmentLayout.addWidget(alignmentComboBox, 0, 1)
		alignmentLayout.addWidgetSpan(alignmentLineEdit, 1, 0, 1, 2)
		alignmentGroup.setLayout(alignmentLayout)
		
		Local inputMaskLayout:QGridLayout = New QGridLayout.Create()
		inputMaskLayout.addWidget(inputMaskLabel, 0, 0)
		inputMaskLayout.addWidget(inputMaskComboBox, 0, 1)
		inputMaskLayout.addWidgetSpan(inputMaskLineEdit, 1, 0, 1, 2)
		inputMaskGroup.setLayout(inputMaskLayout)
		
		Local accessLayout:QGridLayout = New QGridLayout.Create()
		accessLayout.addWidget(accessLabel, 0, 0)
		accessLayout.addWidget(accessComboBox, 0, 1)
		accessLayout.addWidgetSpan(accessLineEdit, 1, 0, 1, 2)
		accessGroup.setLayout(accessLayout)
		
		Local layout:QGridLayout = New QGridLayout.Create()
		layout.addWidget(echoGroup, 0, 0)
		layout.addWidget(validatorGroup, 1, 0)
		layout.addWidget(alignmentGroup, 2, 0)
		layout.addWidget(inputMaskGroup, 0, 1)
		layout.addWidget(accessGroup, 1, 1)

		setLayout(layout)
		setWindowTitle(tr("Line Edits"))

	End Method	

	Method echoChanged(index:Int)
		Select index
			Case 0
				echoLineEdit.setEchoMode(QLineEdit.Normal)
			Case 1
				echoLineEdit.setEchoMode(QLineEdit.Password)
			Case 2
				echoLineEdit.setEchoMode(QLineEdit.PasswordEchoOnEdit)
			Case 3
				echoLineEdit.setEchoMode(QLineEdit.NoEcho)
		End Select
	End Method
	
	Method validatorChanged(index:Int)
		Select index
			Case 0
				validatorLineEdit.setValidator(Null)
			Case 1
				validatorLineEdit.setValidator(New QIntValidator.Create(validatorLineEdit))
			Case 2
				validatorLineEdit.setValidator(New QDoubleValidator.CreateWithRange(-999.0, 999.0, 2, validatorLineEdit))
		End Select
	End Method

	Method alignmentChanged(index:Int)
		Select index
			Case 0
				alignmentLineEdit.setAlignment(Qt_AlignLeft)
			Case 1
				alignmentLineEdit.setAlignment(Qt_AlignCenter)
			Case 2
				alignmentLineEdit.setAlignment(Qt_AlignRight)
		End Select
	End Method

	Method inputMaskChanged(index:Int)
		Select index
			Case 0
				inputMaskLineEdit.setInputMask("")
			Case 1
				inputMaskLineEdit.setInputMask("+99 99 99 99 99;_")
			Case 2
				inputMaskLineEdit.setInputMask("0000-00-00")
				inputMaskLineEdit.setText("00000000")
				inputMaskLineEdit.setCursorPosition(0)
			Case 3
				inputMaskLineEdit.setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#")
		End Select
	End Method

	Method accessChanged(index:Int)
		Select index
			Case 0
				accessLineEdit.setReadOnly(False)
			Case 1
				accessLineEdit.setReadOnly(True)
		End Select
	End Method

End Type

