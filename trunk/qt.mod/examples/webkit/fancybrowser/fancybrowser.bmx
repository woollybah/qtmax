SuperStrict

Framework Qt.QApplication
Import Qt.QWebKit
Import Qt.QMainWindow
Import Qt.QLineEdit
Import Qt.QToolBar
Import BRL.FileSystem
Import BRL.RamStream
Import BRL.TextStream

Incbin "jquery.min.js"

Local app:QApplication = New QApplication.Create()

?macos
Local dir:String = QApplication.applicationDirPath()
QApplication.addLibraryPath(RealPath(dir + "/../plugins"))
?

Local window:TMainWindow = New TMainWindow.Create()
window.show()

app.exec()

End

Type TMainWindow Extends QMainWindow

	Field jQuery:String
	Field view:QWebView
	Field locationEdit:QLineEdit
	Field progress:Int
	
	Method Create:TMainWindow(parent:QWidget = Null, flags:Int = 0)
		Return TMainWindow(Super.Create(parent, flags))
	End Method

	Method OnInit()
	
		jQuery = LoadText("incbin::jquery.min.js")
	
		view = New QWebView.Create(Self)
		view.Load(New QUrl.Create("http://www.google.com/ncr"))
		connect(view, "loadFinished", Self, "adjustLocation")
		connect(view, "titleChanged", Self, "adjustTitle")
		connect(view, "loadProgress", Self, "setProgress")
		connect(view, "loadFinished", Self, "finishLoading")
		
		locationEdit = New QLineEdit.Create(Self)
		'locationEdit.setSizePolicy(QSizePolicy_Expanding, locationEdit.sizePolicy().verticalPolicy())
		connect(locationEdit, "returnPressed", Self, "changeLocation")
		
		Local toolBar:QToolBar = addToolBar(tr("Navigation"))
		toolBar.addAction(view.pageAction(QWebPage.Back))
		toolBar.addAction(view.pageAction(QWebPage.Forward))
		toolBar.addAction(view.pageAction(QWebPage.Reload))
		toolBar.addAction(view.pageAction(QWebPage.Stop))
		toolBar.addWidget(locationEdit)
		
		Local effectMenu:QMenu = menuBar().addMenu(tr("&Effect"))
		effectMenu.addAction("Highlight all links", Self, "highlightAllLinks")
		
		Local rotateAction:QAction = New QAction.Create(Self)
		rotateAction.setIcon(style().standardIcon(QStyle_SP_FileDialogDetailedView))
		rotateAction.setCheckable(True)
		rotateAction.setText(tr("Turn images upside down"))
		connect(rotateAction, "toggled", Self, "rotateImages")
		effectMenu.addAction(rotateAction)
		
		Local toolsMenu:QMenu = menuBar().addMenu(tr("&Tools"))
		toolsMenu.addAction(tr("Remove GIF images"), Self, "removeGifImages")
		toolsMenu.addAction(tr("Remove all inline frames"), Self, "removeInlineFrames")
		toolsMenu.addAction(tr("Remove all object elements"), Self, "removeObjectElements")
		toolsMenu.addAction(tr("Remove all embedded elements"), Self, "removeEmbeddedElements")
		
		setCentralWidget(view)
	End Method

	Method adjustLocation()
		locationEdit.setText(view.url().toString())
	End Method
	
	Method changeLocation()
		Local url:QUrl = New QUrl.Create(locationEdit.text())
		view.Load(url)
		view.SetFocus()
	End Method
	
	Method adjustTitle()
		If progress <= 0 Or progress >= 100 Then
			setWindowTitle(view.title())
		Else
			setWindowTitle(view.title() + " (" + progress + "%)")
		End If
	End Method
	
	Method setProgress(p:Int)
		progress = p
		adjustTitle()
	End Method
	
	Method finishLoading(finished:Int)
		progress = 100
		adjustTitle()
		view.page().mainFrame().evaluateJavaScript(jQuery)
	End Method
	
	Method highlightAllLinks()
		Local code:String = "$('a').each( function () { $(this).css('background-color', 'yellow') } )"
		view.page().mainFrame().evaluateJavaScript(code)
	End Method
	
	Method rotateImages(toggle:Int)
	End Method
	
	Method removeGifImages()
	End Method
	
	Method removeInlineFrames()
	End Method
	
	Method removeObjectElements()
	End Method
	
	Method removeEmbeddedElements()
	End Method
	

End Type

