SuperStrict

Framework Qt.QApplication
Import Qt.QCheckBox
Import Qt.QGridLayout
Import Qt.QGroupBox
Import Qt.QHBoxLayout
Import Qt.QLabel
Import Qt.QPushButton
Import Qt.QSpinBox
Import Qt.QVBoxLayout
Import Qt.QTimer
Import Qt.QFileDialog
Import BRL.FileSystem

Global app:QApplication = New QApplication.Create()

Local window:Screenshot = New Screenshot.Create()
window.show()

app.exec()

End

Type Screenshot Extends QWidget

	Field originalPixmap:QPixmap

	Field screenshotLabel:QLabel
	Field optionsGroupBox:QGroupBox
	Field delaySpinBox:QSpinBox
	Field delaySpinBoxLabel:QLabel
	Field hideThisWindowCheckBox:QCheckBox
	Field newScreenshotButton:QPushButton
	Field saveScreenshotButton:QPushButton
	Field quitScreenshotButton:QPushButton

	Field mainLayout:QVBoxLayout
	Field optionsGroupBoxLayout:QGridLayout
	Field buttonsLayout:QHBoxLayout

	Method Create:Screenshot(parent:QWidget = Null, flags:Int = 0)
		Return Screenshot(Super._Create(parent, flags))
	End Method

	Method OnInit()
		screenshotLabel = New QLabel.Create("")
		screenshotLabel.setSizePolicyHV(QSizePolicy.Expanding, QSizePolicy.Expanding)
		screenshotLabel.setAlignment(Qt_AlignCenter)
		screenshotLabel.setMinimumSize(240, 160)
		
		createOptionsGroupBox()
		createButtonsLayout()
		
		mainLayout = New QVBoxLayout.Create()
		mainLayout.addWidget(screenshotLabel)
		mainLayout.addWidget(optionsGroupBox)
		mainLayout.addLayout(buttonsLayout)
		setLayout(mainLayout)
		
		shootScreen()
		delaySpinBox.setValue(5)
		
		setWindowTitle(tr("Screenshot"))
		resize(300, 200)
	End Method
	
	Method resizeEvent(event:QResizeEvent)
		Local sw:Int, sh:Int, w:Int, h:Int
		originalPixmap.size(sw, sh)
		screenshotLabel.size(w, h)
		QSize.scale(sw, sh, w, h, Qt_KeepAspectRatio)
		
		If screenshotLabel.pixmap() Then
			screenshotLabel.pixmap().size(w, h)
		End If
		
		If Not screenshotLabel.pixmap() Or (sw <> w And sh <> h) Then
			updateScreenshotLabel()
		End If
	End Method

	Method createOptionsGroupBox()
		optionsGroupBox = New QGroupBox.Create(tr("Options"))
		
		delaySpinBox = New QSpinBox.Create()
		delaySpinBox.setSuffix(tr(" s"))
		delaySpinBox.setMaximum(60)
		connect(delaySpinBox, "valueChanged", Self, "updateCheckBox")
		
		delaySpinBoxLabel = New QLabel.Create(tr("Screenshot Delay:"))
		
		hideThisWindowCheckBox = New QCheckBox.Create(tr("Hide This Window"))
		
		optionsGroupBoxLayout = New QGridLayout.Create()
		optionsGroupBoxLayout.addWidget(delaySpinBoxLabel, 0, 0)
		optionsGroupBoxLayout.addWidget(delaySpinBox, 0, 1)
		optionsGroupBoxLayout.addWidgetSpan(hideThisWindowCheckBox, 1, 0, 1, 2)
		optionsGroupBox.setLayout(optionsGroupBoxLayout)
	End Method
	
	Method createButtonsLayout()
		newScreenshotButton = CreateButton(tr("New Screenshot"), Self, "newScreenshot")
		saveScreenshotButton = CreateButton(tr("Save Screenshot"), Self, "saveScreenshot")
		quitScreenshotButton = CreateButton(tr("Quit"), Self, "close")
		
		buttonsLayout = New QHBoxLayout.Create()
		buttonsLayout.addStretch()
		buttonsLayout.addWidget(newScreenshotButton)
		buttonsLayout.addWidget(saveScreenshotButton)
		buttonsLayout.addWidget(quitScreenshotButton)	End Method
	
	Method CreateButton:QPushButton(text:String, receiver:QWidget, member:String)
		Local button:QPushButton = New QPushButton.Create(text)
		button.connect(button, "clicked", receiver, member)
		Return button
	End Method

	Method updateScreenshotLabel()
		Local w:Int, h:Int
		screenshotLabel.size(w, h)
		screenshotLabel.setPixmap(originalPixmap.scaled(w, h, Qt_KeepAspectRatio, Qt_SmoothTransformation))	End Method
	
	Method newScreenshot()
		If hideThisWindowCheckBox.isChecked() Then
			hide()
		End If
		newScreenshotButton.setDisabled(True)
		
		QTimer.singleShot(delaySpinBox.value() * 1000, Self, "shootScreen")
	End Method
	
	Method saveScreenshot()
		Local format:String = "png"
		Local initialPath:String = CurrentDir() + tr("/untitled.") + format
		
		Local fileName:String = QFileDialog.getSaveFileName(Self, tr("Save As"), initialPath, tr_arg("%1 Files (*.%2);;All Files (*)", [format.ToUpper(), format]))
		
		If fileName Then
			originalPixmap.save(fileName, format)
		End If
	End Method
	
	Method shootScreen()
		If delaySpinBox.value() <> 0 Then
			app.beep()
		End If
		originalPixmap = QPixmap.grabWindow(QApplication.Desktop().winId())
		updateScreenshotLabel()
		
		newScreenshotButton.setDisabled(False)
		If hideThisWindowCheckBox.isChecked() Then
			show()
		End If
	End Method
	
	Method updateCheckBox()
		If delaySpinBox.value() = 0 Then
			hideThisWindowCheckBox.setDisabled(True)
			hideThisWindowCheckBox.setChecked(False)
		Else
			hideThisWindowCheckBox.setDisabled(False)
		End If
	End Method
	
End Type

	
