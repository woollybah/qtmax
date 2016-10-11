SuperStrict

Framework Qt.QApplication
Import Qt.QWidget
Import Qt.QGroupBox
Import Qt.QGridLayout
Import Qt.QRadioButton
Import Qt.QVBoxLayout
Import Qt.QCheckBox
Import Qt.QPushButton
Import Qt.QMenu

Local app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.Create()
window.show()

app.exec()

End

Type TWindow Extends QWidget

	Method Create:TWindow()
		Return TWindow(Super._Create())
	End Method

	Method OnInit()
		
		Local grid:QGridLayout = New QGridLayout.Create()
		grid.addWidget(createFirstExclusiveGroup(), 0, 0)
		grid.addWidget(createSecondExclusiveGroup(), 1, 0)
		grid.addWidget(createNonExclusiveGroup(), 0, 1)
		grid.addWidget(createPushButtonGroup(), 1, 1)
		setLayout(grid)
		
		setWindowTitle(tr("Group Boxes"))
		resize(480, 320)
	
	End Method

	Method createFirstExclusiveGroup:QGroupBox()
	
		Local groupBox:QGroupBox = New QGroupBox.Create(tr("Exclusive Radio Buttons"))
		
		Local radio1:QRadioButton = New QRadioButton.Create(tr("&Radio button 1"))
		Local radio2:QRadioButton = New QRadioButton.Create(tr("R&adio button 2"))
		Local radio3:QRadioButton = New QRadioButton.Create(tr("Ra&dio button 3"))
		
		radio1.setChecked(True)

		Local vbox:QVBoxLayout = New QVBoxLayout.Create()
		vbox.addWidget(radio1)
		vbox.addWidget(radio2)
		vbox.addWidget(radio3)
		vbox.addStretch(1)
		groupBox.setLayout(vbox)
		
		Return groupBox
	End Method
	
	Method createSecondExclusiveGroup:QGroupBox()
	
		Local groupBox:QGroupBox = New QGroupBox.Create(tr("E&xclusive Radio Buttons"))
		groupBox.setCheckable(True)
		groupBox.setChecked(False)

		Local radio1:QRadioButton = New QRadioButton.Create(tr("Rad&io button 1"))
		Local radio2:QRadioButton = New QRadioButton.Create(tr("Radi&o button 2"))
		Local radio3:QRadioButton = New QRadioButton.Create(tr("Radio &button 3"))
		radio1.setChecked(True)
		Local checkBox:QCheckBox = New QCheckBox.Create(tr("Ind&ependent checkbox"))
		checkBox.setChecked(True)

		Local vbox:QVBoxLayout = New QVBoxLayout.Create()
		vbox.addWidget(radio1)
		vbox.addWidget(radio2)
		vbox.addWidget(radio3)
		vbox.addWidget(checkBox)
		vbox.addStretch(1)
		groupBox.setLayout(vbox)
		
		Return groupBox
	End Method
	
	Method createNonExclusiveGroup:QGroupBox()
	
		Local groupBox:QGroupBox = New QGroupBox.Create(tr("Non-Exclusive Checkboxes"))
		groupBox.setFlat(True)
	
		Local checkBox1:QCheckBox = New QCheckBox.Create(tr("&Checkbox 1"));
		Local checkBox2:QCheckBox = New QCheckBox.Create(tr("C&heckbox 2"));
		checkBox2.setChecked(True);
		Local tristateBox:QCheckBox = New QCheckBox.Create(tr("Tri-&state button"))
		tristateBox.setTristate(True)

		Local vbox:QVBoxLayout = New QVBoxLayout.Create()
		vbox.addWidget(checkBox1)
		vbox.addWidget(checkBox2)
		vbox.addWidget(tristateBox)
		vbox.addStretch(1)
		groupBox.setLayout(vbox)
		
		Return groupBox
	End Method
	
	Method createPushButtonGroup:QGroupBox()
		Local groupBox:QGroupBox = New QGroupBox.Create(tr("&Push Buttons"))
		groupBox.setCheckable(True)
		groupBox.setChecked(True)
		
		Local pushButton:QPushButton = New QPushButton.Create(tr("&Normal Button"))
		Local toggleButton:QPushButton = New QPushButton.Create(tr("&Toggle Button"))
		toggleButton.setCheckable(True)
		toggleButton.setChecked(True)
		Local flatButton:QPushButton = New QPushButton.Create(tr("&Flat Button"))
		flatButton.setFlat(True)

		Local popupButton:QPushButton = New QPushButton.Create(tr("Pop&up Button"))
		Local menu:QMenu = New QMenu.Create(Self)
		menu.addAction(tr("&First Item"))
		menu.addAction(tr("&Second Item"))
		menu.addAction(tr("&Third Item"))
		menu.addAction(tr("F&ourth Item"))
		popupButton.setMenu(menu)
		
		Local vbox:QVBoxLayout = New QVBoxLayout.Create()
		vbox.addWidget(pushButton)
		vbox.addWidget(toggleButton)
		vbox.addWidget(flatButton)
		vbox.addWidget(popupButton)
		vbox.addStretch(1)
		groupBox.setLayout(vbox)
		
		Return groupBox
	End Method

End Type


