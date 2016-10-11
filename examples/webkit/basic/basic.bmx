SuperStrict

Framework Qt.QApplication
Import Qt.QWebKit
Import Qt.QGridLayout
Import BRL.FileSystem

Local app:QApplication = New QApplication.Create()

?macos
Local dir:String = QApplication.applicationDirPath()
QApplication.addLibraryPath(RealPath(dir + "/../plugins"))
?

Local browser:TBrowser = New TBrowser.Create()
browser.show()

app.exec()

End

Type TBrowser Extends QWidget

	Field view:QWebView
	
	Method Create:TBrowser()
		Return TBrowser(Super._Create())
	End Method

	Method OnInit()
		view = New QWebView.Create(Self)
		view.Load(New QUrl.Create("http://blitzmax.com"))
		view.show()
		
		Local mainLayout:QGridLayout = New QGridLayout.Create()
		mainLayout.addWidget(view, 0, 0)
		
		setLayout(mainLayout)
		setWindowTitle(tr("Basic Browser"))
		
	End Method

End Type


