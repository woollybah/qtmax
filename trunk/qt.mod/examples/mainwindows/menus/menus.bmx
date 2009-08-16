SuperStrict

Framework Qt.QApplication
Import Qt.QMainWindow
Import Qt.QMenu
Import Qt.QLabel
Import Qt.QVBoxLayout
Import Qt.QMessageBox

Global app:QApplication = New QApplication.Create()

Local window:TWindow = New TWindow.Create()
window.show()

app.exec()

End

Type TWindow Extends QMainWindow

	Field fileMenu:QMenu
	Field editMenu:QMenu
	Field formatMenu:QMenu
	Field helpMenu:QMenu
	Field alignmentGroup:QActionGroup
	Field newAct:QAction
	Field openAct:QAction
	Field saveAct:QAction
	Field printAct:QAction
	Field exitAct:QAction
	Field undoAct:QAction
	Field redoAct:QAction
	Field cutAct:QAction
	Field copyAct:QAction
	Field pasteAct:QAction
	Field boldAct:QAction
	Field italicAct:QAction
	Field leftAlignAct:QAction
	Field rightAlignAct:QAction
	Field justifyAct:QAction
	Field centerAct:QAction
	Field setLineSpacingAct:QAction
	Field setParagraphSpacingAct:QAction
	Field aboutAct:QAction
	Field aboutQtAct:QAction
	Field infoLabel:QLabel
	
	Method Create:TWindow(parent:QWidget = Null, flags:Int = 0)
		Return TWindow(Super.Create(parent, flags))
	End Method

	Method OnInit()
		Local widget:QWidget = New QWidget._Create()
		setCentralWidget(widget)
		
		Local topFiller:QWidget = New QWidget._Create()
		topFiller.setSizePolicyHV(QSizePolicy.Expanding, QSizePolicy.Expanding)
		
		infoLabel = New QLabel.Create(tr("<i>Choose a menu option, or right-click to invoke a context menu</i>"))
		infoLabel.setFrameStyle(QFrame.Shape_StyledPanel | QFrame.Shadow_Sunken)
		infoLabel.setAlignment(Qt_AlignCenter)
		
		Local bottomFiller:QWidget = New QWidget._Create()
		bottomFiller.setSizePolicyHV(QSizePolicy.Expanding, QSizePolicy.Expanding)
		
		Local layout:QVBoxLayout = New QVBoxLayout.Create()
		layout.addWidget(topFiller)
		layout.addWidget(infoLabel)
		layout.addWidget(bottomFiller)
		widget.setLayout(layout)
		
		createActions()
		createMenus()
		
		Local message:String = tr("A context menu is available by right-clicking")
		statusBar().showMessage(message)
		
		setWindowTitle(tr("Menus"))
		setMinimumSize(160, 160)
		resize(480, 320)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		Local menu:QMenu = New QMenu.Create(Self)
		menu.addAction(cutAct)
		menu.addAction(copyAct)
		menu.addAction(pasteAct)
		Local x:Int, y:Int
		event.globalPos(x, y)
		menu.execAction(x, y)
		menu.Free()
	End Method

	Method createActions()
		newAct = New QAction.Create(tr("&New"), Self)
		newAct.setShortcuts(QKeySequence.Key_New)
		newAct.setStatusTip(tr("Create a new file"))
		connect(newAct, "triggered", Self, "newFile")
		
		openAct = New QAction.Create(tr("&Open..."), Self)
		openAct.setShortcuts(QKeySequence.Key_Open)
		openAct.setStatusTip(tr("Open an existing file"))
		connect(openAct, "triggered", Self, "open")
		
		saveAct = New QAction.Create(tr("&Save"), Self)
		saveAct.setShortcuts(QKeySequence.Key_Save)
		saveAct.setStatusTip(tr("Save the document to disk"))
		connect(saveAct, "triggered", Self, "save")
		
		printAct = New QAction.Create(tr("&Print..."), Self)
		printAct.setShortcuts(QKeySequence.Key_Print)
		printAct.setStatusTip(tr("Print the document"))
		connect(printAct, "triggered", Self, "print")
		
		exitAct = New QAction.Create(tr("E&xit"), Self)
		exitAct.setShortcut(tr("Ctrl+Q"))
		exitAct.setStatusTip(tr("Exit the application"))
		connect(exitAct, "triggered", Self, "close")
		
		undoAct = New QAction.Create(tr("&Undo"), Self)
		undoAct.setShortcuts(QKeySequence.Key_Undo)
		undoAct.setStatusTip(tr("Undo the last operation"))
		connect(undoAct, "triggered", Self, "undo")
		
		redoAct = New QAction.Create(tr("&Redo"), Self)
		redoAct.setShortcuts(QKeySequence.Key_Redo)
		redoAct.setStatusTip(tr("Redo the last operation"))
		connect(redoAct, "triggered", Self, "redo")
		
		cutAct = New QAction.Create(tr("Cu&t"), Self)
		cutAct.setShortcuts(QKeySequence.Key_Cut)
		cutAct.setStatusTip(tr("Cut the current selection's contents to the clipboard"))
		connect(cutAct, "triggered", Self, "cut")
		
		copyAct = New QAction.Create(tr("&Copy"), Self)
		copyAct.setShortcut(tr("Ctrl+C"))
		copyAct.setStatusTip(tr("Copy the current selection's contents to the clipboard"))
		connect(copyAct, "triggered", Self, "copy")
		
		pasteAct = New QAction.Create(tr("&Paste"), Self)
		pasteAct.setShortcuts(QKeySequence.Key_Paste)
		pasteAct.setStatusTip(tr("Paste the clipboard's contents into the current selection"))
		connect(pasteAct, "triggered", Self, "paste")
		
		boldAct = New QAction.Create(tr("&Bold"), Self)
		boldAct.setCheckable(True)
		boldAct.setShortcut(tr("Ctrl+B"))
		boldAct.setStatusTip(tr("Make the text bold"))
		connect(boldAct, "triggered", Self, "bold")
		
		Local boldFont:QFont = boldAct.font()
		boldFont.setBold(True)
		boldAct.setFont(boldFont)
		
		italicAct = New QAction.Create(tr("&Italic"), Self)
		italicAct.setCheckable(True)
		italicAct.setShortcut(tr("Ctrl+I"))
		italicAct.setStatusTip(tr("Make the text italic"))
		connect(italicAct, "triggered", Self, "italic")
		
		Local italicFont:QFont = italicAct.font()
		italicFont.setItalic(True)
		italicAct.setFont(italicFont)
		
		setLineSpacingAct = New QAction.Create(tr("Set &Line Spacing..."), Self)
		setLineSpacingAct.setStatusTip(tr("Change the gap between the lines of a paragraph"))
		connect(setLineSpacingAct, "triggered", Self, "setLineSpacing")
		
		setParagraphSpacingAct = New QAction.Create(tr("Set &Paragraph Spacing..."), Self)
		setLineSpacingAct.setStatusTip(tr("Change the gap between paragraphs"))
		connect(setParagraphSpacingAct, "triggered", Self, "setParagraphSpacing")
		
		aboutAct = New QAction.Create(tr("&About"), Self)
		aboutAct.setStatusTip(tr("Show the application's About box"))
		connect(aboutAct, "triggered", Self, "about")
		
		aboutQtAct = New QAction.Create(tr("About &Qt"), Self)
		aboutQtAct.setStatusTip(tr("Show the Qt library's About box"))
		connect(aboutQtAct, "triggered", app, "aboutQt")
		connect(aboutQtAct, "triggered", Self, "aboutQt")
		
		leftAlignAct = New QAction.Create(tr("&Left Align"), Self)
		leftAlignAct.setCheckable(True)
		leftAlignAct.setShortcut(tr("Ctrl+L"))
		leftAlignAct.setStatusTip(tr("Left align the selected text"))
		connect(leftAlignAct, "triggered", Self, "leftAlign")
		
		rightAlignAct = New QAction.Create(tr("&Right Align"), Self)
		rightAlignAct.setCheckable(True)
		rightAlignAct.setShortcut(tr("Ctrl+R"))
		rightAlignAct.setStatusTip(tr("Right align the selected text"))
		connect(rightAlignAct, "triggered", Self, "rightAlign")
		
		justifyAct = New QAction.Create(tr("&Justify"), Self)
		justifyAct.setCheckable(True)
		justifyAct.setShortcut(tr("Ctrl+J"))
		justifyAct.setStatusTip(tr("Justify the selected text"))
		connect(justifyAct, "triggered", Self, "justify")
		
		centerAct = New QAction.Create(tr("&Center"), Self)
		centerAct.setCheckable(True)
		centerAct.setShortcut(tr("Ctrl+E"))
		centerAct.setStatusTip(tr("Center the selected text"))
		connect(centerAct, "triggered", Self, "center")
		
		alignmentGroup = New QActionGroup.Create(Self)
		alignmentGroup.addAction(leftAlignAct)
		alignmentGroup.addAction(rightAlignAct)
		alignmentGroup.addAction(justifyAct)
		alignmentGroup.addAction(centerAct)
		leftAlignAct.setChecked(True)
	End Method
	
	Method createMenus()
		fileMenu = menuBar().addMenu(tr("&File"))
		fileMenu.addAction(newAct)
		fileMenu.addAction(openAct)
		fileMenu.addAction(saveAct)
		fileMenu.addAction(printAct)
		fileMenu.addSeparator()
		fileMenu.addAction(exitAct)
		
		editMenu = menuBar().addMenu(tr("&Edit"))
		editMenu.addAction(undoAct)
		editMenu.addAction(redoAct)
		editMenu.addSeparator()
		editMenu.addAction(cutAct)
		editMenu.addAction(copyAct)
		editMenu.addAction(pasteAct)
		editMenu.addSeparator()
		
		helpMenu = menuBar().addMenu(tr("&Help"))
		helpMenu.addAction(aboutAct)
		helpMenu.addAction(aboutQtAct)
		
		formatMenu = editMenu.addMenu(tr("&Format"))
		formatMenu.addAction(boldAct)
		formatMenu.addAction(italicAct)
		formatMenu.addSeparator().setText(tr("Alignment"))
		formatMenu.addAction(leftAlignAct)
		formatMenu.addAction(rightAlignAct)
		formatMenu.addAction(justifyAct)
		formatMenu.addAction(centerAct)
		formatMenu.addSeparator()
		formatMenu.addAction(setLineSpacingAct)
		formatMenu.addAction(setParagraphSpacingAct)
	End Method

	Method newFile()
		infoLabel.setText(tr("Invoked <b>File|New</b>"))
	End Method
	
	Method open()
		infoLabel.setText(tr("Invoked <b>File|Open</b>"))
	End Method
	
	Method save()
		infoLabel.setText(tr("Invoked <b>File|Save</b>"))
	End Method
	
	Method Print()
		infoLabel.setText(tr("Invoked <b>File|Print</b>"))
	End Method
	
	Method undo()
		infoLabel.setText(tr("Invoked <b>Edit|Undo</b>"))
	End Method
	
	Method redo()
		infoLabel.setText(tr("Invoked <b>Edit|Redo</b>"))
	End Method
	
	Method cut()
		infoLabel.setText(tr("Invoked <b>Edit|Cut</b>"))
	End Method
	
	Method copy()
		infoLabel.setText(tr("Invoked <b>Edit|Copy</b>"))
	End Method
	
	Method paste()
		infoLabel.setText(tr("Invoked <b>Edit|Paste</b>"))
	End Method
	
	Method bold()
		infoLabel.setText(tr("Invoked <b>Edit|Format|Bold</b>"))
	End Method
	
	Method italic()
		infoLabel.setText(tr("Invoked <b>Edit|Format|Italic</b>"))
	End Method
	
	Method leftAlign()
		infoLabel.setText(tr("Invoked <b>Edit|Format|Left Align</b>"))
	End Method
	
	Method rightAlign()
		infoLabel.setText(tr("Invoked <b>Edit|Format|Right Align</b>"))
	End Method
	
	Method justify()
		infoLabel.setText(tr("Invoked <b>Edit|Format|Justify</b>"))
	End Method
	
	Method center()
		infoLabel.setText(tr("Invoked <b>Edit|Format|Center</b>"))
	End Method
	
	Method setLineSpacing()
		infoLabel.setText(tr("Invoked <b>Edit|Format|Set Line Spacing</b>"))
	End Method
	
	Method setParagraphSpacing()
		infoLabel.setText(tr("Invoked <b>Edit|Format|Set Paragraph Spacing</b>"))
	End Method
	
	Method about()
		infoLabel.setText(tr("Invoked <b>Help|About</b>"))
		QMessageBox.about(Self, tr("About Menu"), tr("The <b>Menu</b> example shows how to create menu-bar menus and context menus."))
	End Method
	
	Method aboutQt()
		infoLabel.setText(tr("Invoked <b>Help|About Qt</b>"))
	End Method
	
End Type
