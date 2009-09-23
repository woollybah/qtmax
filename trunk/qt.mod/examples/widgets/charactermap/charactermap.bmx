SuperStrict

Framework Qt.QApplication
Import Qt.QMainWindow
Import Qt.QComboBox
Import Qt.QFontComboBox
Import Qt.QLineEdit
Import Qt.QScrollArea
Import Qt.QCheckBox
Import Qt.QLabel
Import Qt.QPushButton
Import Qt.QHBoxLayout
Import Qt.QVBoxLayout

Import "characterwidget.bmx"

Local app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.Create()
window.show()

app.exec()

End

Type TWindow Extends QMainWindow

	Field charWidget:CharacterWidget
	Field clipboard:QClipboard
	Field styleCombo:QComboBox
	Field sizeCombo:QComboBox
	Field fontCombo:QFontComboBox
	Field lineEdit:QLineEdit
	Field scrollArea:QScrollArea
	Field fontMerging:QCheckBox

	Method Create:TWindow(parent:QWidget = Null, flags:Int = 0)
		Return TWindow(Super.Create(parent, flags))
	End Method
	
	Method OnInit()
		Local centralWidget:QWidget = New QWidget._Create()
		
		Local fontLabel:QLabel = New QLabel.Create(tr("Font:"))
		fontCombo = New QFontComboBox.Create()
		Local sizeLabel:QLabel = New QLabel.Create(tr("Size:"))
		sizeCombo = New QComboBox.Create()
		Local styleLabel:QLabel = New QLabel.Create(tr("Style:"))
		styleCombo = New QComboBox.Create()
		Local fontMergingLabel:QLabel = New QLabel.Create(tr("Automatic Font Merging:"))
		fontMerging = New QCheckBox.Create()
		fontMerging.setChecked(True)
		
		scrollArea = New QScrollArea.Create()
		charWidget = New CharacterWidget.Create()
		scrollArea.setWidget(charWidget)
		
		findStyles(fontCombo.currentFont())
		findSizes(fontCombo.currentFont())
		
		lineEdit = New QLineEdit.Create()
		Local clipboardButton:QPushButton = New QPushButton.Create(tr("&To clipboard"))
		
		clipboard = QApplication.clipboard()
		
		connect(fontCombo, "currentFontChanged", Self, "findStyles")
		connect(fontCombo, "currentFontChanged", Self, "findSizes")
		connect(fontCombo, "currentFontChanged", charWidget, "updateFont")
		connect(sizeCombo, "currentIndexChanged", charWidget, "updateSize")
		connect(styleCombo, "currentIndexChanged", charWidget, "updateStyle")
		connect(charWidget, "characterSelected", Self, "insertCharacter")
		connect(clipboardButton, "clicked", Self, "updateClipboard")
		connect(fontMerging, "toggled", charWidget, "updateFontMerging")
		
		Local controlsLayout:QHBoxLayout = New QHBoxLayout.Create()
		controlsLayout.addWidget(fontLabel)
		controlsLayout.addWidget(fontCombo, 1)
		controlsLayout.addWidget(sizeLabel)
		controlsLayout.addWidget(sizeCombo, 1)
		controlsLayout.addWidget(styleLabel)
		controlsLayout.addWidget(styleCombo, 1)
		controlsLayout.addWidget(fontMergingLabel)
		controlsLayout.addWidget(fontMerging, 1)
		controlsLayout.addStretch(1)
		
		Local lineLayout:QHBoxLayout = New QHBoxLayout.Create()
		lineLayout.addWidget(lineEdit, 1)
		lineLayout.addSpacing(12)
		lineLayout.addWidget(clipboardButton)
		
		Local centralLayout:QVBoxLayout = New QVBoxLayout.Create()
		centralLayout.addLayout(controlsLayout)
		centralLayout.addWidget(scrollArea, 1)
		centralLayout.addSpacing(4)
		centralLayout.addLayout(lineLayout)
		centralWidget.setLayout(centralLayout)
		
		setCentralWidget(centralWidget)
		setWindowTitle(tr("Character Map"))
	End Method

	Method findStyles(font:QFont)
		Local fontDatabase:QFontDatabase = New QFontDatabase.Create()
		Local currentItem:String = styleCombo.currentText()
		styleCombo.clear()
		
		For Local style:String = EachIn fontDatabase.styles(font.family())
			styleCombo.addItem(style)
		Next
		
		Local styleIndex:Int = styleCombo.findText(currentItem)
		
		If styleIndex = -1 Then
			styleCombo.setCurrentIndex(0)
		Else
			styleCombo.setCurrentIndex(styleIndex)
		End If
	End Method
	
	Method findSizes(font:QFont)
		Local fontDatabase:QFontDatabase = New QFontDatabase.Create()
		Local currentSize:String = sizeCombo.currentText()
		sizeCombo.blockSignals(True)
		sizeCombo.clear()
		
		Local size:Int
		If fontDatabase.isSmoothlyScalable(font.family(), fontDatabase.styleString(font)) Then
			For size = EachIn QFontDatabase.standardSizes()
				sizeCombo.addItem(size)
				sizeCombo.setEditable(True)
			Next
		
		Else
			For size = EachIn fontDatabase.smoothSizes(font.family(), fontDatabase.styleString(font))
				sizeCombo.addItem(size)
				sizeCombo.setEditable(False)
			Next
		End If
		
		sizeCombo.blockSignals(False)
		
		Local sizeIndex:Int = sizeCombo.findText(currentSize)
		
		If sizeIndex = -1 Then
			sizeCombo.setCurrentIndex(Max(0, sizeCombo.count() / 3))
		Else
			sizeCombo.setCurrentIndex(sizeIndex)
		End If
	End Method

	Method insertCharacter(character:String)
	End Method

	Method updateClipboard()
	End Method
	
End Type

