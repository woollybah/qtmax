SuperStrict

Import Qt.QGraphicsView
Import Qt.QGraphicsRectItem
Import Qt.QFile
Import Qt.QPainter
Import Qt.QGraphicsSvgItem

Type SvgView Extends QGraphicsView

	Const Renderer_Native:Int = 0
	Const Renderer_OpenGL:Int = 1
	Const Renderer_Image:Int = 2

	Field m_renderer:Int

	Field m_svgItem:QGraphicsItem
	Field m_backgroundItem:QGraphicsRectItem
	Field m_outlineItem:QGraphicsRectItem
	
	Field m_image:QImage
	
	Method OnInit()
		m_renderer = Renderer_Native

		setScene(New QGraphicsScene.Create(Self))
		setTransformationAnchor(AnchorUnderMouse)
		setDragMode(ScrollHandDrag)

		' Prepare background check-board pattern
		Local tilePixmap:QPixmap = New QPixmap.Create(64, 64)
		tilePixmap.fill(Qt_white)
		Local tilePainter:QPainter = New QPainter.Create(tilePixmap)
		Local color:QColor = New QColor.Create(220, 220, 220)
		tilePainter.fillRectColor(0, 0, 32, 32, color)
		tilePainter.fillRectColor(32, 32, 32, 32, color)
		tilePainter.DoEnd()
		
		setBackgroundBrush(New QBrush.CreateWithPixmap(tilePixmap))
	End Method

	Method OpenFile(file:QFile)
		If Not file.exists() Then
			Return
		End If
		
		Local s:QGraphicsScene = scene()
		
		Local drawBackground:Int = False
		If m_backgroundItem Then
			drawBackground = m_backgroundItem.isVisible()
		End If
		
		Local drawOutline:Int = True
		If m_outlineItem Then
			drawOutline = m_outlineItem.isVisible()
		End If
		
		s.clear()
		resetTransform()

		m_svgItem = New QGraphicsSvgItem.Create(file.fileName())
		m_svgItem.setFlags(QGraphicsItem.ItemClipsToShape)
		m_svgItem.setCacheMode(QGraphicsItem.NoCache)
		m_svgItem.setVisible(True)
		m_svgItem.setZValue(0)
		
		m_backgroundItem = New QGraphicsRectItem.Create(m_svgItem.boundingRect())
		m_backgroundItem.setBrush(New QBrush.CreateWithGlobalColor(Qt_white))
		m_backgroundItem.setPenStyle(Qt_NoPen)
		m_backgroundItem.setVisible(drawBackground)
		m_backgroundItem.setZValue(-1)
		
		m_outlineItem = New QGraphicsRectItem.Create(m_svgItem.boundingRect())
		Local outline:QPen = New QPen.CreateWithAttributes(New QBrush.CreateWithGlobalColor(Qt_black), 2, Qt_DashLine)
		outline.setCosmetic(True)
		m_outlineItem.setPen(outline)
		m_outlineItem.setBrushStyle(Qt_NoBrush)
		m_outlineItem.setVisible(drawOutline)
		m_outlineItem.setZValue(1)
		
		s.addItem(m_backgroundItem)
		s.addItem(m_svgItem)
		s.addItem(m_outlineItem)
		
		s.setSceneRect(m_outlineItem.boundingRect().adjusted(-10, -10, 10, 10))
	End Method
	
	Method setRenderer(renderType:Int = Renderer_Native)
		m_renderer = renderType
		
		If m_renderer = Renderer_OpenGL Then
			'SetViewport(New QGLWidget.Create(QGLFormat(QGL.SampleBuffers)))
		Else
			SetViewport(New QWidget._Create())
		End If
	End Method
	
	Method drawBackground(p:QPainter, rect:QRectF)
		p.save()
		p.resetTransform()
		p.drawTiledPixmapRect(viewport().rect(), backgroundBrush().texture())
		p.restore()
	End Method
	
	Method setHighQualityAntialiasing(highQualityAntialiasing:Int)
		setRenderHint(QPainter.HighQualityAntialiasing, highQualityAntialiasing)
	End Method
	
	Method setViewBackground(enable:Int)
		If Not m_backgroundItem Then
			Return
		End If
		
		m_backgroundItem.setVisible(enable)
	End Method
	
	Method setViewOutline(enable:Int)
		If Not m_outlineItem Then
			Return
		End If
		
		m_outlineItem.setVisible(enable)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		Local factor:Double = 1.2 ^ (event.delta() / 240.0)
		scale(factor, factor)
		event.accept()
	End Method
	
	Method paintEvent(event:QPaintEvent)

		If m_renderer = Renderer_Image Then
			Local iw:Int, ih:Int, vw:Int, vh:Int
			If m_image Then
				m_image.size(iw, ih)
			End If
			viewport().size(vw, vh)
			If iw <> vw And ih <> vh Then
				m_image = New QImage.Create(vw, vh, QImage.Format_ARGB32_Premultiplied)
			End If

			Local imagePainter:QPainter = New QPainter.Create(m_image)
			Super.render(imagePainter)
			imagePainter.DoEnd()
			
			Local p:QPainter = New QPainter.Create(viewport())
			p.DrawImage(0, 0, m_image)
			p.DoEnd()
		Else
			Super.paintEvent(event)
		End If
	End Method

End Type

