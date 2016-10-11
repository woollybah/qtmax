SuperStrict

Import Qt.QGroupBox
Import Qt.QSlider
Import Qt.QScrollBar
Import Qt.QDial
Import Qt.QBoxLayout

Type SlidersGroup Extends QGroupBox

	Field slider:QSlider
	Field scrollBar:QScrollBar
	Field dial:QDial
	
	Field orientation:Int
	
	Method CreateGroup:SlidersGroup(orientation:Int, title:String, parent:QWidget = Null)
		Self.orientation = orientation
		Return SlidersGroup(Super.Create(title, parent))
	End Method

	Method OnInit()
		slider = New QSlider.Create(orientation)
		slider.setFocusPolicy(Qt_StrongFocus)
		slider.setTickPosition(QSlider.TicksBothSides)
		slider.setTickInterval(10)
		slider.setSingleStep(1)
		
		scrollBar = New QScrollBar.Create(orientation)
		scrollBar.setFocusPolicy(Qt_StrongFocus)
		
		dial = New QDial.Create()
		dial.setFocusPolicy(Qt_StrongFocus)
		
		connect(slider, "valueChanged", scrollBar, "setValue")
		connect(scrollBar, "valueChanged", dial, "setValue")
		connect(dial, "valueChanged", slider, "setValue")
		connect(dial, "valueChanged", Self, "valueChanged")
		
		Local direction:Int
		
		If orientation = Qt_Horizontal Then
			direction = QBoxLayout.TopToBottom
		Else
			direction = QBoxLayout.LeftToRight
		End If
		
		Local slidersLayout:QBoxLayout = New QBoxLayout.CreateLayout(direction)
		slidersLayout.addWidget(slider)
		slidersLayout.addWidget(scrollBar)
		slidersLayout.addWidget(dial)
		setLayout(slidersLayout)
	End Method

	Method setValue(value:Int)
		slider.setValue(value)
	End Method
	
	Method setMinimum(value:Int)
		slider.setMinimum(value)
		scrollBar.setMinimum(value)
		dial.setMinimum(value)
	End Method
	
	Method setMaximum(value:Int)
		slider.setMaximum(value)
		scrollBar.setMaximum(value)
		dial.setMaximum(value)
	End Method
	
	Method invertAppearance(invert:Int)
		slider.setInvertedAppearance(invert)
		scrollBar.setInvertedAppearance(invert)
		dial.setInvertedAppearance(invert)
	End Method
	
	Method invertKeyBindings(invert:Int)
		slider.setInvertedControls(invert)
		scrollBar.setInvertedControls(invert)
		dial.setInvertedControls(invert)
	End Method

	Method valueChanged(value:Int)
		_InvokeSignals("valueChanged", [String(value)])
	End Method
	
End Type

