SuperStrict

Framework Qt.QApplication
Import Qt.QCheckBox
Import Qt.QLabel
Import Qt.QPushButton
Import Qt.QLineEdit
Import Qt.QDialog
Import Qt.QDialogButtonBox
Import Qt.QVBoxLayout
Import Qt.QHBoxLayout
Import Qt.QGridLayout

Global app:QApplication = New QApplication.Create()

Local dialog:FindDialog = New FindDialog.Create()

dialog.exec()

End

Type FindDialog Extends QDialog

	Field label:QLabel
	Field lineEdit:QLineEdit
	Field caseCheckBox:QCheckBox
	Field fromStartCheckBox:QCheckBox
	Field wholeWordsCheckBox:QCheckBox
	Field searchSelectionCheckBox:QCheckBox
	Field backwardCheckBox:QCheckBox
	Field buttonBox:QDialogButtonBox
	Field findButton:QPushButton
	Field moreButton:QPushButton
	Field extension:QWidget

	Method Create:FindDialog(parent:QWidget = Null, flags:Int = 0)
		Return FindDialog(Super.Create(parent, flags))
	End Method

	Method OnInit()
		label = New QLabel.Create(tr("Find &what:"))
		lineEdit = New QLineEdit.Create()
		label.setBuddy(lineEdit)
		
		caseCheckBox = New QCheckBox.Create(tr("Match &case"))
		fromStartCheckBox = New QCheckBox.Create(tr("Search from &start"))
		fromStartCheckBox.setChecked(True)
		
		findButton = New QPushButton.Create(tr("&Find"))
		findButton.setDefault(True)
		
		moreButton = New QPushButton.Create(tr("&More"))
		moreButton.setCheckable(True)
		moreButton.setAutoDefault(False)
		
		buttonBox = New QDialogButtonBox.Create(Qt_Vertical)
		buttonBox.addButton(findButton, QDialogButtonBox.ActionRole)
		buttonBox.addButton(moreButton, QDialogButtonBox.ActionRole)
		
		extension = New QWidget._Create()
		
		wholeWordsCheckBox = New QCheckBox.Create(tr("&Whole words"))
		backwardCheckBox = New QCheckBox.Create(tr("Search &backward"))
		searchSelectionCheckBox = New QCheckBox.Create(tr("Search se&lection"))
		
		connect(moreButton, "toggled", extension, "setVisible")
		
		Local extensionLayout:QVBoxLayout = New QVBoxLayout.Create()
		extensionLayout.setContentsMargins(0, 0, 0, 0)
		extensionLayout.addWidget(wholeWordsCheckBox)
		extensionLayout.addWidget(backwardCheckBox)
		extensionLayout.addWidget(searchSelectionCheckBox)
		extension.setLayout(extensionLayout)
		
		Local topLeftLayout:QHBoxLayout = New QHBoxLayout.Create()
		topLeftLayout.addWidget(label)
		topLeftLayout.addWidget(lineEdit)
		
		Local leftLayout:QVBoxLayout = New QVBoxLayout.Create()
		leftLayout.addLayout(topLeftLayout)
		leftLayout.addWidget(caseCheckBox)
		leftLayout.addWidget(fromStartCheckBox)
		leftLayout.addStretch(1)
		
		Local mainLayout:QGridLayout = New QGridLayout.Create()
		mainLayout.setSizeConstraint(QLayout.SetFixedSize)
		mainLayout.addLayout(leftLayout, 0, 0)
		mainLayout.addWidget(buttonBox, 0, 1)
		mainLayout.addWidgetSpan(extension, 1, 0, 1, 2)
		setLayout(mainLayout)
		
		setWindowTitle(tr("Extension"))
		extension.hide()
	End Method
	
End Type	
