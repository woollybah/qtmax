SuperStrict

Framework Qt.QApplication
Import Qt.QPainterPath
Import Qt.QComboBox
Import Qt.QGridLayout

Import "renderarea.bmx"

Local app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.Create()
window.show()

app.exec()

End

Type TWindow Extends QWidget

	Const NumTransformedAreas:Int = 3

	Field originalRenderArea:RenderArea
	Field transformedRenderAreas:RenderArea[NumTransformedAreas]

	Field shapeComboBox:QComboBox
	Field operationComboBoxes:QComboBox[NumTransformedAreas]
	Field shapes:TList

	Method Create:TWindow()
		Return TWindow(Super._Create())
	End Method

	Method OnInit()
		originalRenderArea = New RenderArea.Create()
		
		shapeComboBox = New QComboBox.Create()
		shapeComboBox.addItem(tr("Clock"))
		shapeComboBox.addItem(tr("House"))
		shapeComboBox.addItem(tr("Text"))
		shapeComboBox.addItem(tr("Truck"))
		
		Local layout:QGridLayout = New QGridLayout.Create()
		layout.addWidget(originalRenderArea, 0, 0)
		layout.addWidget(shapeComboBox, 1, 0)


		setLayout(layout)
		setupShapes()
		shapeSelected(0)

		setWindowTitle(tr("Transformations"))
		
	End Method
	
	Method setupShapes()

		Local truck:QPainterPath = New QPainterPath.Create()
		truck.setFillRule(Qt_WindingFill)
		truck.moveTo(0.0, 87.0)
		truck.lineTo(0.0, 60.0)
		truck.lineTo(10.0, 60.0)
		truck.lineTo(35.0, 35.0)
		truck.lineTo(100.0, 35.0)
		truck.lineTo(100.0, 87.0)
		truck.lineTo(0.0, 87.0)
		truck.moveTo(17.0, 60.0)
		truck.lineTo(55.0, 60.0)
		truck.lineTo(55.0, 40.0)
		truck.lineTo(37.0, 40.0)
		truck.lineTo(17.0, 60.0)
		truck.addEllipse(17.0, 75.0, 25.0, 25.0)
		truck.addEllipse(63.0, 75.0, 25.0, 25.0)
		
		Local clock:QPainterPath = New QPainterPath.Create()
		clock.addEllipse(-50.0, -50.0, 100.0, 100.0)
		clock.addEllipse(-48.0, -48.0, 96.0, 96.0)
		clock.moveTo(0.0, 0.0)
		clock.lineTo(-2.0, -2.0)
		clock.lineTo(0.0, -42.0)
		clock.lineTo(2.0, -2.0)
		clock.lineTo(0.0, 0.0)
		clock.moveTo(0.0, 0.0)
		clock.lineTo(2.732, -0.732)
		clock.lineTo(24.495, 14.142)
		clock.lineTo(0.732, 2.732)
		clock.lineTo(0.0, 0.0)
		
		Local house:QPainterPath = New QPainterPath.Create()
		house.moveTo(-45.0, -20.0)
		house.lineTo(0.0, -45.0)
		house.lineTo(45.0, -20.0)
		house.lineTo(45.0, 45.0)
		house.lineTo(-45.0, 45.0)
		house.lineTo(-45.0, -20.0)
		house.addRect(15.0, 5.0, 20.0, 35.0)
		house.addRect(-35.0, -15.0, 25.0, 25.0)
		
		Local text:QPainterPath = New QPainterPath.Create()
		Local font:QFont = New QFont.Create()
		font.setPixelSize(50)
		Local fontBoundingRect:QRect = New QFontMetrics.Create(font).boundingRect(tr("Qt"))
		Local x:Float, y:Float
		fontBoundingRect.center(x, y)
		text.addText(x, y, font, tr("Qt"))
		
		shapes.AddLast(clock)
		shapes.AddLast(house)
		shapes.AddLast(text)
		shapes.AddLast(truck)
		
		connect(shapeComboBox, "activated", Self, "shapeSelected")
		

	End Method
	
	Method operationChanged()
	End Method
	
	Method shapeSelected(index:Int)
	End Method

End Type


