SuperStrict

Import Qt.QWidget
Import Qt.QPainterPath

Const Operation_NoTransformation:Int = 0
Const Operation_Translate:Int = 1
Const Operation_Rotate:Int = 2
Const Operation_Scale:Int = 3

Type RenderArea Extends QWidget

	Field operations:Int[]
	Field shape:QPainterPath
	Field xBoundingRect:QRect
	Field yBoundingRect:QRect

	Method Create:RenderArea()
		Return RenderArea(Super._Create())
	End Method

	Method OnInit()
		Local newFont:QFont = font()
		newFont.setPixelSize(12)
		setFont(newFont)
		
		Local fontMetrics:QFontMetrics = New QFontMetrics.Create(newFont)
		xBoundingRect = fontMetrics.boundingRect(tr("x"))
		yBoundingRect = fontMetrics.boundingRect(tr("y"))
	End Method

	Method paintEvent(event:QPaintEvent)
		Local painter:QPainter = New QPainter.Create(Self)
		
		painter.setRenderHint(QPainter.Antialiasing)
		painter.fillRectRectBrush(event.rect(), New QBrush.CreateWithGlobalColor(Qt_white))
		
		painter.translate(66, 66)
		
		painter.save()
		transformPainter(painter)
		drawShape(painter)
		painter.restore()
		
		drawOutline(painter)
		
		transformPainter(painter)
		drawCoordinates(painter)
		
		painter.DoEnd()
	End Method
	
	Method setShape(shape:QPainterPath)
		Self.shape = shape
		update()
	End Method

	Method drawCoordinates(painter:QPainter)
		painter.setPenColor(New QColor.CreateWithGlobalColor(Qt_red))
		
		painter.DrawLine(0, 0, 50, 0)
		painter.DrawLine(48, -2, 50, 0)
		painter.DrawLine(48, 2, 50, 0)
		painter.DrawText(60 - xBoundingRect.width() / 2, 0 + xBoundingRect.height() / 2, tr("x"))
		
		painter.DrawLine(0, 0, 0, 50)
		painter.DrawLine(-2, 48, 0, 50)
		painter.DrawLine(2, 48, 0, 50)
		painter.DrawText(0 - yBoundingRect.width() / 2, 60 + yBoundingRect.height() / 2, tr("y"))
	End Method
	
	Method drawOutline(painter:QPainter)
		painter.setPenColor(New QColor.CreateWithGlobalColor(Qt_darkGreen))
		painter.setPenStyle(Qt_DashLine)
		painter.setBrushStyle(Qt_NoBrush)
		painter.DrawRect(0, 0, 100, 100)
	End Method
	
	Method drawShape(painter:QPainter)
		painter.fillPath(shape, New QBrush.CreateWithGlobalColor(Qt_blue))
	End Method
	
	Method transformPainter(painter:QPainter)
		For Local i:Int = 0 Until operations.length
			Select operations[i]
				Case Operation_Translate
					painter.translate(50, 50)
	
				Case Operation_Scale
					painter.scale(0.75, 0.75)
	
				Case Operation_Rotate
					painter.rotate(60)

			End Select
		Next
	End Method
	
	Method sizeHint(w:Int Var, h:Int Var)
		w = 232
		h = 232
	End Method

	Method minimumSizeHint(w:Int Var, h:Int Var)
		w = 182
		h = 182
	End Method

	Method setOperations(operations:Int[])
		Self.operations = operations
		update()
	End Method
	
End Type


