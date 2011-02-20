SuperStrict

Framework Qt.QApplication
Import Qt.QGraphicsView
Import Qt.QPropertyAnimation
Import Qt.QTransform
Import Qt.QGraphicsBlurEffect

Import BRL.LinkedList
Import BRL.JpgLoader

Local app:QApplication = New QApplication.Create()

Local blurPicker:TBlurPicker = New TBlurPicker.Create()
blurPicker.setWindowTitle(QT_TRANSLATE_NOOP("QGraphicsView", "Application Picker"))
blurPicker.setFixedSize(400, 300)
blurPicker.show()

app.exec()

End

Type TBlurPicker Extends QGraphicsView

	Field index:Double { property READ="getIndex" WRITE="setIndex" }
	Field icons:QGraphicsItem[]
	
	Field animation:QPropertyAnimation
	
	Method Create:TBlurPicker(parent:QWidget = Null)
		Return TBlurPicker(Super.Create(parent))
	End Method
	
	Method OnInit()
		animation = New QPropertyAnimation.Create(Self, "index")

		'setBackgroundBrush(New QBrush.CreateWithPixmap(QPixmap.FromPixmap(LoadPixmap("images/background.jpg").Convert(PF_RGB888))))
		'setBackgroundBrush(New QBrush.CreateWithPixmap(QPixmap.FromFile("images/background.jpg")))
		setScene(New QGraphicsScene.Create(Self))
		
		setupScene()
		setIndex(0)
		
		animation.setDuration(400)
		animation.setEasingCurve(New QEasingCurve.Create(QEasingCurve.InOutSine))
		
		setRenderHint(QPainter.Antialiasing, True)
		setFrameStyle(QFrame.Shape_NoFrame)
	End Method
	
	Method setupScene()
		scene().setSceneRect(-200, -120, 400, 240)
		
		Local names:String[] = ["images/accessories-calculator.png", ..
			"images/accessories-text-editor.png", ..
			"images/help-browser.png", ..
			"images/internet-group-chat.png", ..
			"images/internet-mail.png", ..
			"images/internet-web-browser.png", ..
			"images/office-calendar.png", ..
			"images/system-users.png" ]
			
		icons = New QGraphicsItem[names.length]
			
		For Local i:Int = 0 Until names.length
			Local pixmap:QPixmap = QPixmap.FromFile(names[i])
			Local icon:QGraphicsPixmapItem = scene().addPixmap(pixmap)
			icon.setZValue(1)
			icon.setGraphicsEffect(New TBlurEffect.CreateEffect(icon))
			icons[i] = icon
		Next
		
		Local bg:QGraphicsPixmapItem = scene().addPixmap(QPixmap.FromPixmap(LoadPixmap("images/background.jpg").Convert(PF_RGB888)))
		bg.setZValue(0)
		bg.setPos(-200, -150)
		
	End Method

	Method getIndex:Double()
		Return index
	End Method
	
	Method setIndex(index:Double)
		Self.index = index

		Local baseline:Double = 0
		
		For Local i:Int = 0 Until icons.length
			Local icon:QGraphicsItem = icons[i]
			Local a:Double = ((i + index) * 360) / icons.length

			Local xs:Double = 170 * Sin(a)
			Local ys:Double = 100 * Cos(a)

			Local xp:Double, yp:Double
			New QTransform.Create().rotate(-20).mapPointF(xs, ys, xp, yp)
			icon.setPos(xp - 40, yp - 40)
			baseline = Max(baseline, ys)
			TBlurEffect(icon.graphicsEffect()).setBaseLine(baseline)
		Next

		scene().update()
	End Method

	Method keyPressEvent(keyEvent:QKeyEvent)
		Local delta:Int = 0
		
		Select keyEvent.key()
			Case Qt_Key_Left
				delta = -1
			Case Qt_Key_Right
				delta = 1
		End Select
		
		If animation.state() = QAbstractAnimation.Stopped And delta Then
			animation.setEndValue(QDoubleVariant.Create(index + delta))
			animation.start()
			keyEvent.accept()
		End If
		
	End Method

End Type

Type TBlurEffect Extends QGraphicsBlurEffect

	Field baseLine:Double
	Field item:QGraphicsItem
	
	Method CreateEffect:QGraphicsBlurEffect(item:QGraphicsItem)
		Self.item = item
		Return Super.Create()
	End Method
	
	Method OnInit()
		baseLine = 200
	End Method

	Method adjustForItem()
		Local x:Double, y:Double
		item.pos(x, y)
		y = baseLine - y
		
		Local radius:Double = Max(0, Min(y / 32, 16.0))
		setBlurRadius(radius)
	End Method
	
	Method boundingRect:QRectF()
		adjustForItem()
     	Return Super.boundingRect()
	End Method
	
	Method setBaseLine(y:Double)
		baseLine = y
	End Method
	
	Method draw(painter:QPainter)
		adjustForItem()
		Super.draw(painter)
	End Method

End Type

