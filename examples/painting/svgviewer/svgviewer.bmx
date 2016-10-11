SuperStrict

Framework Qt.QApplication
Import Qt.QMainWindow
Import Qt.QMenu
Import Qt.QLabel
Import Qt.QVBoxLayout
Import Qt.QMessageBox
Import Qt.QFileDialog

Import "svgview.bmx"

Global app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.Create()
window.show()

app.exec()

End

Type TWindow Extends QMainWindow
	Field m_nativeAction:QAction
	Field m_glAction:QAction
	Field m_imageAction:QAction
	Field m_highQualityAntialiasingAction:QAction
	Field m_backgroundAction:QAction
	Field m_outlineAction:QAction
	
	Field m_view:SvgView
	
	Field m_currentPath:String

	Method Create:TWindow(parent:QWidget = Null, flags:Int = 0)
		Return TWindow(Super.Create(parent, flags))
	End Method

	Method OnInit()
		m_view = SvgView(New SvgView.Create())
		
		Local fileMenu:QMenu = New QMenu.CreateWithTitle(tr("&File"), Self)
		Local openAction:QAction = fileMenu.addAction(tr("&Open..."))
		openAction.setShortcut(tr("Ctrl+O"))
		Local quitAction:QAction = fileMenu.addAction(tr("E&xit"))
		quitAction.setShortcut(tr("Ctrl+Q"))
		
		menuBar().addMenuAction(fileMenu)
		
		Local viewMenu:QMenu = New QMenu.CreateWithTitle(tr("&View"), Self)
		m_backgroundAction = viewMenu.addAction(tr("&Background"))
		m_backgroundAction.setEnabled(False)
		m_backgroundAction.setCheckable(True)
		m_backgroundAction.setChecked(False)
		connect(m_backgroundAction, "toggled", m_view, "setViewBackground")
		
		m_outlineAction = viewMenu.addAction(tr("&Outline"))
		m_outlineAction.setEnabled(False)
		m_outlineAction.setCheckable(True)
		m_outlineAction.setChecked(True)
		connect(m_outlineAction, "toggled", m_view, "setViewOutline")
		
		menuBar().addMenuAction(viewMenu)
		
		Local rendererMenu:QMenu = New QMenu.CreateWithTitle(tr("&Renderer"), Self)
		m_nativeAction = rendererMenu.addAction(tr("&Native"))
		m_nativeAction.setCheckable(True)
		m_nativeAction.setChecked(True)
		'm_glAction = rendererMenu.addAction(tr("&OpenGL"))
		'm_glAction.setCheckable(true)
		m_imageAction = rendererMenu.addAction(tr("&Image"))
		m_imageAction.setCheckable(True)
		
		'rendererMenu.addSeparator()
		'm_highQualityAntialiasingAction = rendererMenu.addAction(tr("&High Quality Antialiasing"))
		'm_highQualityAntialiasingAction.setEnabled(false)
		'm_highQualityAntialiasingAction.setCheckable(true)
		'm_highQualityAntialiasingAction.setChecked(false)
		'connect(m_highQualityAntialiasingAction, SIGNAL(toggled(bool)), m_view, SLOT(setHighQualityAntialiasing(bool)))
		
		Local rendererGroup:QActionGroup = New QActionGroup.Create(Self)
		rendererGroup.addAction(m_nativeAction)
		'rendererGroup.addAction(m_glAction)
		rendererGroup.addAction(m_imageAction)
		
		menuBar().addMenuAction(rendererMenu)
		
		connect(openAction, "triggered", Self, "OpenFile")
		connect(quitAction, "triggered", app, "quit")
		connect(rendererGroup, "triggered", Self, "setRenderer")
		
		setCentralWidget(m_view)
		setWindowTitle(tr("SVG Viewer"))
	End Method

	Method OpenFile(path:String)
		Local fileName:String
		If path = "0" Then
			path = ""
		End If
		If Not path Then
			fileName = QFileDialog.getOpenFileName(Self, tr("Open SVG File"), m_currentPath, "SVG files (*.svg *.svgz *.svg.gz)")
		Else
			fileName = path
		End If
		
		If fileName Then
			Local file:QFile = New QFile.Create(fileName)
			If Not file.exists() Then
				QMessageBox.critical(Self, tr("Open SVG File"), "Could not open file '" + fileName + "'.")
		
				m_outlineAction.setEnabled(False)
				m_backgroundAction.setEnabled(False)
				Return
			End If
		
			m_view.OpenFile(file)
		
			If Not fileName.startsWith(":/") Then
				m_currentPath = fileName
				setWindowTitle(tr(m_currentPath + " - SVGViewer"))
			End If
		
			m_outlineAction.setEnabled(True)
			m_backgroundAction.setEnabled(True)

			Local w:Int, h:Int
			m_view.sizeHint(w, h)
			resize(w + 80, h + menuBar().height())
		End If
	End Method
	
	Method setRenderer(action:QAction)
		If action = m_nativeAction Then
			m_view.setRenderer(SvgView.Renderer_Native)
		ElseIf action = m_imageAction Then
			m_view.setRenderer(SvgView.Renderer_Image)
		End If
	End Method
	
End Type


