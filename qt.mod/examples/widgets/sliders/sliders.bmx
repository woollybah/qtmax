SuperStrict

Framework Qt.QApplication
Import Qt.QComboBox
Import Qt.QStackedWidget
Import Qt.QSpinBox
Import Qt.QLabel

Import "slidersgroup.bmx"

Local app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.Create()
window.show()

app.exec()

End

Type TWindow Extends QWidget

	Field horizontalSliders:SlidersGroup
	Field verticalSliders:SlidersGroup
	Field stackedWidget:QStackedWidget
	
	Field controlsGroup:QGroupBox
	Field minimumLabel:QLabel
	Field maximumLabel:QLabel
	Field valueLabel:QLabel
	Field invertedAppearance:QCheckBox
	Field invertedKeyBindings:QCheckBox
	Field minimumSpinBox:QSpinBox
	Field maximumSpinBox:QSpinBox
	Field valueSpinBox:QSpinBox
	Field orientationCombo:QComboBox
	
	Method Create:TWindow()
		Return TWindow(Super._Create())
	End Method
	
	Method OnInit()
		horizontalSliders = New SlidersGroup.CreateGroup(Qt_Horizontal, tr("Horizontal"))
		verticalSliders = New SlidersGroup.CreateGroup(Qt_Vertical, tr("Vertical"))
		
		stackedWidget = New QStackedWidget.Create()
		stackedWidget.addWidget(horizontalSliders)
		stackedWidget.addWidget(verticalSliders)
		
		createControls(tr("Controls"))
		
		connect(horizontalSliders, "valueChanged", verticalSliders, "setValue")
		connect(verticalSliders, "valueChanged", valueSpinBox, "setValue")
		connect(valueSpinBox, "valueChanged", horizontalSliders, "setValue")
		
		Local layout:QHBoxLayout = New QHBoxLayout.Create()
		layout.addWidget(controlsGroup)
		layout.addWidget(stackedWidget)
		setLayout(layout)
		
		minimumSpinBox.setValue(0)
		maximumSpinBox.setValue(20)
		valueSpinBox.setValue(5)
		
		setWindowTitle(tr("Sliders"))
	End Method
	
	Method createControls(title:String)
		controlsGroup = New QGroupBox.Create(title)

		minimumLabel = New QLabel.Create(tr("Minimum value:"))
		maximumLabel = New QLabel.Create(tr("Maximum value:"))
		valueLabel = New QLabel.Create(tr("Current value:"))

		invertedAppearance = New QCheckBox.Create(tr("Inverted appearance"))
		invertedKeyBindings = New QCheckBox.Create(tr("Inverted key bindings"))
		
		minimumSpinBox = New QSpinBox.Create()
		minimumSpinBox.setRange(-100, 100)
		minimumSpinBox.setSingleStep(1)
		
		maximumSpinBox = New QSpinBox.Create()
		maximumSpinBox.setRange(-100, 100)
		maximumSpinBox.setSingleStep(1)
		
		valueSpinBox = New QSpinBox.Create()
		valueSpinBox.setRange(-100, 100)
		valueSpinBox.setSingleStep(1)
		
		orientationCombo = New QComboBox.Create()
		orientationCombo.addItem(tr("Horizontal slider-like widgets"))
		orientationCombo.addItem(tr("Vertical slider-like widgets"))
		
		connect(orientationCombo, "activated", stackedWidget, "setCurrentIndex")
		connect(minimumSpinBox, "valueChanged", horizontalSliders, "setMinimum")
		connect(minimumSpinBox, "valueChanged", verticalSliders, "setMinimum")
		connect(maximumSpinBox, "valueChanged", horizontalSliders, "setMaximum")
		connect(maximumSpinBox, "valueChanged", verticalSliders, "setMaximum")
		connect(invertedAppearance, "toggled", horizontalSliders, "invertAppearance")
		connect(invertedAppearance, "toggled", verticalSliders, "invertAppearance")
		connect(invertedKeyBindings, "toggled", horizontalSliders, "invertKeyBindings")
		connect(invertedKeyBindings, "toggled", verticalSliders, "invertKeyBindings")
		
		Local controlsLayout:QGridLayout = New QGridLayout.Create()
		controlsLayout.addWidget(minimumLabel, 0, 0)
		controlsLayout.addWidget(maximumLabel, 1, 0)
		controlsLayout.addWidget(valueLabel, 2, 0)
		controlsLayout.addWidget(minimumSpinBox, 0, 1)
		controlsLayout.addWidget(maximumSpinBox, 1, 1)
		controlsLayout.addWidget(valueSpinBox, 2, 1)
		controlsLayout.addWidget(invertedAppearance, 0, 2)
		controlsLayout.addWidget(invertedKeyBindings, 1, 2)
		controlsLayout.addWidget(orientationCombo, 3, 0, 1, 3)
		controlsGroup.setLayout(controlsLayout)
	End Method
	
	
End Type


