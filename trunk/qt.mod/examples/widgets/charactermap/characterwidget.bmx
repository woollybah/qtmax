SuperStrict

Import Qt.QWidget
Import Qt.QFontDatabase
Import Qt.QPainter
Import Qt.QToolTip

Type CharacterWidget Extends QWidget

	Field displayFont:QFont = New QFont.Create()
	Field columns:Int
	Field lastKey:Int
	Field squareSize:Int
	
	Method Create:CharacterWidget()
		Return CharacterWidget(_Create())
	End Method

	Method OnInit()
		squareSize = 24
		columns = 16
		lastKey = -1
		setMouseTracking(True)
	End Method
	
	Method sizeHint(w:Int Var, h:Int Var)
		w = columns * squareSize
		h = (65536 / columns) * squareSize
	End Method
	
	Method updateFont(font:QFont)
		displayFont.setFamily(font.family())
		squareSize = Max(24, New QFontMetrics.Create(displayFont).xHeight() * 3)
		adjustSize()
		update()
	End Method
	
	Method updateSize(FontSize:String)
		displayFont.setPointSize(FontSize.toInt())
		squareSize = Max(24, New QFontMetrics.Create(displayFont).xHeight() * 3)
		adjustSize()
		update()
	End Method
	
	Method updateStyle(FontStyle:String)
		Local fontDatabase:QFontDatabase = New QFontDatabase.Create()
		Local oldStrategy:Int = displayFont.styleStrategy()
		displayFont = fontDatabase.font(displayFont.family(), FontStyle, displayFont.pointSize())
		displayFont.setStyleStrategy(oldStrategy)
		squareSize = Max(24, New QFontMetrics.Create(displayFont).xHeight() * 3)
		adjustSize()
		update()
	End Method
	
	Method updateFontMerging(enable:Int)
		If enable Then
			displayFont.setStyleStrategy(QFont.Strategy_PreferDefault)
		Else
			displayFont.setStyleStrategy(QFont.Strategy_NoFontMerging)
		End If
		adjustSize()
		update()
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		Local gPosX:Int, gPosY:Int
		event.globalPos(gPosX, gPosY)
		
		Local widgetPositionX:Int, widgetPositionY:Int
		mapFromGlobal(widgetPositionX, widgetPositionY, gPosX, gPosY)
		
		Local key:Int = (widgetPositionY / squareSize) * columns + widgetPositionX / squareSize
		
		Local text:String = "<p>Character: <span style=~qfont-size: 24pt; font-family: " + displayFont.family() + "~q>" + ..
				Chr(key) + "</span><p>Value: " + key
			
		QToolTip.showText(gPosX, gPosY, text, Self)
	End Method
	
	Method mousePressEvent(event:QMouseEvent)
		If event.button() = Qt_LeftButton Then
			lastKey = (Event.y() / squareSize) * columns + event.x() / squareSize
			If QChar.category(lastKey) <> QChar.NoCategory Then
				characterSelected(Chr(lastKey))
			End If
			update()
		Else
			Super.mousePressEvent(event)
		End If
	End Method
	
	Method paintEvent(event:QPaintEvent)
		Local painter:QPainter = New QPainter.Create(Self)
		painter.fillRectRectBrush(event.rect(), New QBrush.CreateWithGlobalColor(Qt_white))
		painter.setFont(displayFont)
		
		Local redrawRect:QRect = event.rect()
		Local beginRow:Int = redrawRect.top() / squareSize
		Local endRow:Int = redrawRect.bottom() / squareSize
		Local beginColumn:Int = redrawRect.Left() / squareSize
		Local endColumn:Int = redrawRect.Right() / squareSize

		painter.setPen(New QPen.CreateWithGlobalColor(Qt_gray))
		For Local row:Int = beginRow To endRow
			For Local column:Int = beginColumn To endColumn
				painter.DrawRect(column * squareSize, row * squareSize, squareSize, squareSize)
			Next
		Next
		
		Local fontMetrics:QFontMetrics = New QFontMetrics.Create(displayFont)
		painter.setPen(New QPen.CreateWithGlobalColor(Qt_black))
		For Local row:Int = beginRow To endRow
		
			For Local column:Int = beginColumn To endColumn
		
				Local key:Int = row * columns + column
				painter.setClipRect(column * squareSize, row * squareSize, squareSize, squareSize)
		
				If key = lastKey Then
					painter.fillRectBrush(column * squareSize + 1, row * squareSize + 1, squareSize, squareSize, New QBrush.CreateWithGlobalColor(Qt_red))
				End If
		
'				painter.DrawText(column * squareSize + (squareSize / 2) - fontMetrics.width(key)/2, row * squareSize + 4 + fontMetrics.ascent(), Chr(key))
				painter.DrawText(column * squareSize + (squareSize / 3), row * squareSize + fontMetrics.ascent(), Chr(key))
			Next
		Next
		
		painter.DoEnd()
	End Method
	
	Method characterSelected(character:String)
		_InvokeSignals("characterSelected", [character])
	End Method
	
End Type
