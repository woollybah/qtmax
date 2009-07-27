SuperStrict

Framework Qt.QApplication
Import Qt.QWidget
Import Qt.QTimer
Import Qt.QColor
Import Qt.QPainter

Local app:QApplication = New QApplication.Create()

Local clock:AnalogClock = New AnalogClock.Create()
clock.show()

app.exec()

End

Type AnalogClock Extends QWidget

	Method Create:AnalogClock()
		Return AnalogClock(Self._Create())
	End Method

	Method OnInit()
		Local timer:QTimer = New QTimer.Create(Self)
		connect(timer, "timeout", Self, "update")
		timer.start(1000)
		
		setWindowTitle(tr("Analog Clock"))
		resize(200, 200)
	End Method

	Method paintEvent(event:QPaintEvent)
		Local hourColor:QColor = New QColor.Create(127, 0, 127)
		Local minuteColor:QColor = New QColor.Create(0, 127, 127, 191)
		
		Local size:Int = Min(width(), height())
		Local time:QTime = QTime.CurrentTime()
		
		Local painter:QPainter = New QPainter.Create()
		painter.doBegin(Self)
		
		painter.setRenderHint(QPainter.Antialiasing)
		painter.translate(width() / 2, height() / 2)
		painter.scale(side / 200.0, side / 200.0)
		
		painter.setPen(Qt_NoPen)
		painter.setBrush(hourColor)
		
		painter.save()
		painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)))
		painter.drawConvexPolygon(hourHand)
		painter.restore()
		
		painter.setPen(hourColor)
		
		For Local i:Int = 0 Until 12
			painter.DrawLine(88, 0, 96, 0)
			painter.rotate(30.0)
		Next
		
		painter.setPen(Qt_NoPen)
		painter.setBrush(minuteColor)
		
		painter.save()
		painter.rotate(6.0 * (time.minute() + time.Second() / 60.0))
		painter.drawConvexPolygon(minuteHand)
		painter.restore()
		
		painter.setPen(minuteColor)
		
		For Local j:Int = 0 Until 60
			If j Mod 5 <> 0 Then
				painter.DrawLine(92, 0, 96, 0)
			End If
			painter.rotate(6.0)
		Next
		
		painter.doEnd()
	End Method

End Type

