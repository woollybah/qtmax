SuperStrict

Framework Qt.QApplication
Import Qt.QWidget
Import Qt.QTimer
Import Qt.QColor
Import Qt.QPainter

Global app:QApplication = New QApplication.Create()

Local clock:AnalogClock = New AnalogClock.Create()
clock.show()

app.exec()

End

Type AnalogClock Extends QWidget

	Field hourHand:Int[] = [7, 8, -7, 8, 0, -40]
	Field minuteHand:Int[] = [7, 8, -7, 8, 0, -70]
	
	Field hourColor:QColor = New QColor.Create(127, 0, 127)
	Field minuteColor:QColor = New QColor.Create(0, 127, 127, 191)
	
	Field dragX:Int
	Field dragY:Int
	
	Method Create:AnalogClock()
		Return AnalogClock(Self._Create(Null, Qt_FramelessWindowHint | Qt_WindowSystemMenuHint))
	End Method

	Method OnInit()
		Local timer:QTimer = New QTimer.Create(Self)
		connect(timer, "timeout", Self, "update")
		timer.start(1000)
		
		Local quitAction:QAction = New QAction.Create(tr("E&xit"), Self)
		quitAction.setShortcut(tr("Ctrl+Q"))
		connect(quitAction, "triggered", app, "quit")
		addAction(quitAction)

		setAttribute(WA_TranslucentBackground)
		setContextMenuPolicy(Qt_ActionsContextMenu)
		
		setToolTip(tr("Drag the clock with the left mouse button.~n" + ..
				"Use the right mouse button to open a context menu."))
		setWindowTitle(tr("Analog Clock"))
		resize(200, 200)
	End Method
	
	Method mousePressEvent(event:QMouseEvent)
		If event.button() = Qt_LeftButton Then
			Local gx:Int, gy:Int
			event.globalPos(gx, gy)
			
			Local fx:Int, fy:Int
			frameGeometry().topLeft(fx, fy)
			
			dragX = gx - fx
			dragY = gy - fy
			
			event.accept()
		End If
	End Method
	
	Method mouseMoveEvent(event:QMouseEvent)
		If event.buttons() & Qt_LeftButton Then
			Local gx:Int, gy:Int
			event.globalPos(gx, gy)
			
			move(gx - dragX, gy - dragY)
		
			event.accept()
		End If
	End Method

	Method paintEvent(event:QPaintEvent)
		Local side:Int = Min(width(), height())
		Local time:QTime = QTime.CurrentTime()

		Local painter:QPainter = QPainter(getPainter())

		painter.setRenderHint(QPainter.Antialiasing)
		painter.translate(width() / 2, height() / 2)
		
		Local gradient:QRadialGradient = New QRadialGradient.Create(0.0, 0.0, side*0.5, 0.0, 0.0)
		gradient.setColorAt(0.0, New QColor.Create(255, 255, 255, 255))
		gradient.setColorAt(0.1, New QColor.Create(255, 255, 255, 31))
		gradient.setColorAt(0.7, New QColor.Create(255, 255, 255, 31))
		gradient.setColorAt(0.8, New QColor.Create(0, 31, 0, 31))
		gradient.setColorAt(0.9, New QColor.Create(255, 255, 255, 255))
		gradient.setColorAt(1.0, New QColor.Create(255, 255, 255, 255))
		painter.setPenColor(New QColor.Create(0, 0, 0, 32))
		painter.setBrushGradient(gradient)
		painter.drawEllipse(-side/2.0 + 1, -side/2.0 + 1, side - 2, side - 2)
		
		painter.scale(side / 200.0, side / 200.0)
		
		painter.setPenStyle(Qt_NoPen)
		painter.setBrushColor(hourColor)
		
		painter.save()
		painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)))
		painter.drawConvexPolygon(hourHand)
		painter.restore()
		
		painter.setPenColor(hourColor)
		
		For Local i:Int = 0 Until 12
			painter.DrawLine(88, 0, 96, 0)
			painter.rotate(30.0)
		Next
		
		painter.setPenStyle(Qt_NoPen)
		painter.setBrushColor(minuteColor)
		
		painter.save()
		painter.rotate(6.0 * (time.minute() + time.Second() / 60.0))
		painter.drawConvexPolygon(minuteHand)
		painter.restore()
		
		painter.setPenColor(minuteColor)
		
		For Local j:Int = 0 Until 60
			If j Mod 5 <> 0 Then
				painter.DrawLine(92, 0, 96, 0)
			End If
			painter.rotate(6.0)
		Next

	End Method

End Type

