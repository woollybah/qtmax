' Copyright (c) 2012-2013 Bruce A Henderson
' 
' Permission is hereby granted, free of charge, to any person obtaining a copy
' of this software and associated documentation files (the "Software"), to deal
' in the Software without restriction, including without limitation the rights
' to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
' copies of the Software, and to permit persons to whom the Software is
' furnished to do so, subject to the following conditions:
' 
' The above copyright notice and this permission notice shall be included in
' all copies or substantial portions of the Software.
' 
' THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
' IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
' FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
' AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
' LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
' OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
' THE SOFTWARE.
' 
SuperStrict

Import "qtcommon.bmx"

Type TQtGadget Extends TGadget

	Field widget:QWidget
	Field icons:TQtIconStrip

	Method CreateGadget:TQtGadget(text:String, x:Int, y:Int, w:Int, h:Int, group:TQtGadget, style:Int)
		
		Self.style = style
		SetRect(x, y, w, h)
		parent = group
		InitGadget()
		
		LockLayout()
		
		If (LocalizationMode() & LOCALIZATION_OVERRIDE) Then
			LocalizeGadget(Self, text)
		Else
			SetText(text)
		EndIf

		If parent Then
			parent.kids.Remove(Self)
			parent.kids.AddLast(Self)
		End If
		
		'SetFont(TFLTKGUIDriver.fntDefault)
		Return Self
		
	EndMethod
	
	Method InitGadget()
	EndMethod

	Method SetShow(truefalse:Int)
		'visible = truefalse
		'mySetVisible = visible
DebugLog "SetShow(" + truefalse + ")"
		If truefalse Then
			widget.show()
		Else
			widget.hide()
		EndIf
		
		'UpdateChildVisibility()
	End Method

	Method Rethink()
		If widget Then
			widget.setGeometry(xpos, ypos, width, height)
		End If
	End Method

	Method RealParentForChild:QWidget()
		Return widget
	End Method

	Method SetColor(r:Int, g:Int, b:Int)
		'widget.setStyleSheet("background : rgb(" + r + "," + g + "," + b + ")")
		Local pal:QPalette = widget.palette()
		pal.SetColor(QPalette.Role_Window, New QColor.Create(r, g, b))
		widget.setAutoFillBackground(True)
		widget.setPalette(pal)
	End Method
	
	Method SetTooltip(text:String)
		widget.setToolTip(text)
	End Method

	Method SetIconStrip(iconstrip:TIconStrip)
		icons = TQtIconStrip(iconstrip)
	End Method

	Method State:Int()
		Local s:Int
		
		If widget.isHidden() Then
			s :| STATE_HIDDEN
		End If
		
		Return s
	End Method
	
End Type

Type TQtIconStrip Extends TIconStrip
	
	Field icons:QIcon[]
	Field dim:Int
	
	Function IsNotBlank:Int(pixmap:TPixmap)
		Local h:Int = pixmap.height
		Local c:Int = pixmap.ReadPixel(0,0) 			
		For Local x:Int = 0 Until h
			For Local y:Int = 0 Until h
				If pixmap.ReadPixel(x,y)<>c Return True
			Next
		Next
	End Function
		
	Function Create:TQtIconStrip(source:Object)
		Local iconstrip:TQtIconStrip

		Local pixmap:TPixmap = TPixmap(source)
		If Not pixmap Then
			pixmap = LoadPixmap(source)
		End If
		If Not pixmap Return Null
		
		Select pixmap.format
			Case PF_I8,PF_BGR888
				pixmap = pixmap.Convert( PF_RGB888 )
			Case PF_A8,PF_BGRA8888
				pixmap = pixmap.Convert( PF_RGBA8888 )
		End Select
		
		If AlphaBitsPerPixel[ pixmap.format ]
			For Local y:Int = 0 Until pixmap.height
				For Local x:Int = 0 Until pixmap.width
					Local argb:Int = pixmap.ReadPixel( x,y )
					pixmap.WritePixel x, y, premult(argb)
				Next
			Next
		EndIf
		
		Local n:Int = pixmap.width/pixmap.height
		If n = 0 Return Null
		
		iconstrip = New TQtIconStrip
		iconstrip.pixmap = pixmap
		iconstrip.count = n
		iconstrip.icons = New QIcon[n]
		
		Local w:Int = pixmap.width / n
		iconstrip.dim = w
		For Local x:Int = 0 Until n
			Local pix:TPixmap = pixmap.Window(x*w, 0, w, pixmap.height)
			If IsNotBlank(pix) Then
				iconstrip.icons[x]=New QIcon.Create(QPixmap.FromPixmap(pix))
			End If
		Next

		Return iconstrip
	End Function	

	Function premult:Int(argb:Int)
		Local a:Int = ((argb Shr 24) & $FF)
		Return ((((argb&$ff00ff)*a)Shr 8)&$ff00ff)|((((argb&$ff00)*a)Shr 8)&$ff00)|(a Shl 24)
	End Function
	
EndType


Type TQtWindow Extends TQtGadget

	Method InitGadget()
		CreateWindow()
	End Method
	
	Method CreateWindow()
	
		Local flags:Int = 0
		
		If style & WINDOW_TOOL Then
			flags :| Qt_Tool
		End If
	
		If parent Then
			widget = New MaxGuiQMainWindow.MCreate(TQtGadget(parent).widget, flags, Self)
		Else
			widget = New MaxGuiQMainWindow.MCreate(Null, flags, Self)
		End If
	
		If style & WINDOW_MENU Then
			MaxGuiQMainWindow(widget).createMenuBar()
		End If
		
		If style & WINDOW_STATUS Then
			'createStatusbar()
			MaxGuiQMainWindow(widget).createStatusBar()
			'SetStatus("")
		EndIf
		
		If style & WINDOW_RESIZABLE Then
			
		Else
			widget.setFixedSize(width, height)
		End If
		
		Rethink()
		
		If ~style & WINDOW_HIDDEN
			Setshow(True)
		Else
			SetShow(False)
		End If
		
	End Method
	
	Method onClose()
		
	End Method
	
	Method SetText(text:String)
		widget.setWindowTitle(text)
	End Method

	Method RealParentForChild:QWidget()
		Return MaxGuiQMainWindow(widget).clientWidget
	End Method
	
	Method ClientWidth:Int()
		Return MaxGuiQMainWindow(widget).ClientWidth()
	End Method

	Method ClientHeight:Int()
		Return MaxGuiQMainWindow(widget).ClientHeight()
	End Method

	Method Class:Int()
		Return GADGET_WINDOW
	EndMethod
	
	Method SetStatusText(text:String)
		MaxGuiQMainWindow(widget).SetStatusText(text)
	End Method

	Method AddToolBar(toolbar:TQtToolBar)
		MaxGuiQMainWindow(widget).addToolbar(toolbar.widget)
	End Method
	
End Type

Type TQtButton Extends TQtGadget


	Method SetText(text:String)
		QAbstractButton(widget).setText(text)
	End Method
	
	Method GetText:String()
		Return QAbstractButton(widget).text()
	End Method

	Method Class:Int()
		Return GADGET_BUTTON
	EndMethod

End Type

Type TQtPushButton Extends TQtButton

	Method InitGadget()
		CreateButton()
	End Method
	
	Method CreateButton()
	
		widget = New MaxGuiQPushButton.MCreate("", TQtGadget(parent).RealParentForChild(), Self)
		
		Select style & 7
			Case BUTTON_CHECKBOX
				MaxGuiQPushButton(widget).setFlat(True)
				MaxGuiQPushButton(widget).setCheckable(True)
				MaxGuiQPushButton(widget).setAutoFillBackground(True)
			Case BUTTON_RADIO
				MaxGuiQPushButton(widget).setFlat(True)
				MaxGuiQPushButton(widget).setCheckable(True)
				MaxGuiQPushButton(widget).setAutoExclusive(True)
				MaxGuiQPushButton(widget).setAutoFillBackground(True)
			Default
		End Select
				
		If style = BUTTON_OK Then
			MaxGuiQPushButton(widget).setAutoDefault(True)
			MaxGuiQPushButton(widget).setDefault(True)
		End If
		
		Rethink()
		
		SetShow(True)
		
	End Method

End Type

Type TQtCheckableButton Extends TQtPushButton

	Method State:Int()
		Local flags:Int = Super.State()

		If QAbstractButton(widget).isChecked() Then
			flags:|STATE_SELECTED
		End If

		Return flags
	End Method

	Method SetSelected(bool:Int)
		QAbstractButton(widget).setChecked(bool)
	End Method

End Type

Type TQtCheckboxButton Extends TQtCheckableButton

	Method InitGadget()
		CreateButton()
	End Method
	
	Method CreateButton()
	
		widget = New MaxGuiQCheckboxButton.MCreate("", TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

End Type

Type TQtRadioButton Extends TQtCheckableButton

	Method InitGadget()
		CreateButton()
	End Method
	
	Method CreateButton()
	
		widget = New MaxGuiQRadioButton.MCreate("", TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

End Type

Type TQtLabel Extends TQtGadget

	Method InitGadget()
		CreateLabel()
	End Method
	
	Method CreateLabel()
	
		widget = New MaxGuiQLabel.MCreate("", TQtGadget(parent).RealParentForChild(), Self)
		
		Select style
			Case LABEL_FRAME
				MaxGuiQLabel(widget).setFrameShape(QFrame.Shape_Box)
			Case LABEL_SUNKENFRAME
				MaxGuiQLabel(widget).setFrameStyle(QFrame.Shape_Panel | QFrame.Shadow_Sunken)
			Case LABEL_SEPARATOR
				' TODO : Horiz/Vert depending on width/height ?
				MaxGuiQLabel(widget).setFrameStyle(QFrame.Shape_HLine | QFrame.Shadow_Sunken)
		End Select
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method SetText(text:String)
		' only if we are meant to have text
		If style <> LABEL_SEPARATOR
			MaxGuiQLabel(widget).setText(text)
		End If
	End Method
	
	Method GetText:String()
		Return MaxGuiQLabel(widget).text()
	End Method

	Method Class:Int()
		Return GADGET_LABEL
	EndMethod

End Type


Type TQtPanel Extends TQtGadget

	Field activePanel:Int

	Method InitGadget()
		CreatePanel()
	End Method
	
	Method CreatePanel()
		widget = New MaxGuiQFrame.MCreate(TQtGadget(parent).RealParentForChild(), Self)

		If style & PANEL_SUNKEN Then
				MaxGuiQFrame(widget).setFrameStyle(QFrame.Shape_Box | QFrame.Shadow_Sunken)
		End If

		If style & PANEL_RAISED Then
				MaxGuiQFrame(widget).setFrameStyle(QFrame.Shape_Box | QFrame.Shadow_Raised)
		End If
		
		activePanel = style & PANEL_ACTIVE
		If activePanel Then
			widget.setMouseTracking(True)
		End If

		Rethink()
		
		SetShow(True)
		
	End Method

	Method RealParentForChild:QWidget()
		Return MaxGuiQFrame(widget).clientWidget
	End Method

	Method ClientWidth:Int()
		Return MaxGuiQFrame(widget).ClientWidth()
	End Method

	Method ClientHeight:Int()
		Return MaxGuiQFrame(widget).ClientHeight()
	End Method

	Method Class:Int()
		Return GADGET_PANEL
	EndMethod

End Type

Type TQtGroupBox Extends TQtPanel

	Method InitGadget()
		CreateGroupBox()
	End Method
	
	Method CreateGroupBox()
	
		widget = New MaxGuiQGroupBox.MCreate("", TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method SetText(text:String)
		MaxGuiQGroupBox(widget).setTitle(text)
	End Method
	
	Method GetText:String()
		Return MaxGuiQGroupBox(widget).title()
	End Method

	Method RealParentForChild:QWidget()
		Return MaxGuiQGroupBox(widget).clientWidget
	End Method

	Method ClientWidth:Int()
		Return MaxGuiQGroupBox(widget).ClientWidth()
	End Method

	Method ClientHeight:Int()
		Return MaxGuiQGroupBox(widget).ClientHeight()
	End Method

End Type

Type TQtTextField Extends TQtGadget

	Method InitGadget()
		CreateTextField()
	End Method
	
	Method CreateTextField()
	
		widget = New MaxGuiQLineEdit.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method SetText(text:String)
		MaxGuiQLineEdit(widget).setText(text)
	End Method
	
	Method GetText:String()
		Return MaxGuiQLineEdit(widget).text()
	End Method

	Method Class:Int()
		Return GADGET_TEXTFIELD
	EndMethod

End Type

Type TQtTextArea Extends TQtGadget

	Method InitGadget()
		CreateTextArea()
	End Method
	
	Method CreateTextArea()
	
		widget = New MaxGuiQTextEdit.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		If ~style & TEXTAREA_WORDWRAP Then
			MaxGuiQTextEdit(widget).setLineWrapMode(QTextEdit.Mode_NoWrap)
		End If
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_TEXTAREA
	EndMethod

End Type

Type TQtListBox Extends TQtGadget

	Method InitGadget()
		CreateListBox()
	End Method
	
	Method CreateListBox()
	
		widget = New MaxGuiQListView.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method InsertListItem(index:Int, text:String, tip:String, icon:Int, extra:Object)
		Local image:QIcon
		
		If icons And icon >= 0 Then
			image = icons.icons[icon]
		End If
		
		MaxGuiQListView(widget).insertListItem(index, text, tip, image, extra)
	End Method

	Method SetListItem(index:Int, text:String ,tip:String, icon:Int, data:Object)
		Local image:QIcon
		
		If icons And icon >= 0 Then
			image = icons.icons[icon]
		End If
		
		MaxGuiQListView(widget).setListItem(index, text, tip, image, data)
	End Method

	Method SetListItemState(index:Int, state:Int)
'DebugLog "TQtListBox::SetListItemState"
		MaxGuiQListView(widget).setListItemState(index, state)
	End Method

	Method ListItemState:Int(index:Int)
'DebugLog "TQtListBox::ListItemState"
		Return MaxGuiQListView(widget).listItemState(index)
	End Method

	'Method SelectItem:Int(index:Int, op:Int= 1) '0=deselect 1=select 2=toggle
'DebugLog "TQtListBox::SelectItem"
	'	MaxGuiQListView(widget).selectItem(index, op)
	'End Method

	Method RemoveListItem(index:Int)
DebugLog "TQtListBox::RemoveListItem(" + index + ")"
		MaxGuiQListView(widget).removeItem(index)
	End Method

'	Method ItemState:Int(index:Int)
'DebugLog "TQtListBox::ItemState"
'	End Method

	Method Class:Int()
		Return GADGET_LISTBOX
	EndMethod

End Type

Type TQtProgressBar Extends TQtGadget

	Method InitGadget()
		CreateProgressBar()
	End Method
	
	Method CreateProgressBar()
	
		widget = New MaxGuiQProgressBar.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		MaxGuiQProgressBar(widget).setMaximum(100)
		Rethink()
		
		SetShow(True)
		
	End Method

	Method SetValue(value:Float)
		'Local f:Float = 100.0 / MaxGuiQProgressBar(widget).maximum()
		MaxGuiQProgressBar(widget).setValue(value * 100)
	End Method
	
	Method Class:Int()
		Return GADGET_PROGBAR
	EndMethod

End Type

Type TQtComboBox Extends TQtGadget

	Method InitGadget()
		CreateComboBox()
	End Method
	
	Method CreateComboBox()
	
		widget = New MaxGuiQComboBox.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		If style & COMBOBOX_EDITABLE Then
			MaxGuiQComboBox(widget).setEditable(True)
			MaxGuiQComboBox(widget).setInsertPolicy(QComboBox.InsertPolicy_NoInsert)
		End If
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method InsertListItem(index:Int, text:String, tip:String, icon:Int, extra:Object)
		Local image:QIcon
		
		If icons And icon >= 0 Then
			image = icons.icons[icon]
		End If
		
		MaxGuiQComboBox(widget).insertListItem(index, text, tip, image, extra)
	End Method

	Method SetItemState:Int(index:Int, state:Int)
DebugLog "TQtComboBox::SetItemState"
	End Method

	Method ItemState:Int(index:Int)
DebugLog "TQtComboBox::ItemState"
	End Method
	
	Method SelectedItem:Int()
DebugLog "TQtComboBox::SelectedItem"
		Return MaxGuiQComboBox(widget).currentIndex()
	End Method

	Method SetListItem(index:Int, text:String ,tip:String, icon:Int, data:Object)
		Local image:QIcon
		
		If icons And icon >= 0 Then
			image = icons.icons[icon]
		End If
		
		MaxGuiQComboBox(widget).setListItem(index, text, tip, image, data)
	End Method

	Method SelectItem:Int(index:Int, op:Int= 1) '0=deselect 1=select 2=toggle
DebugLog "TQtComboBox::SelectItem"
		MaxGuiQComboBox(widget).setCurrentIndex(index)
	End Method
	
	Method RemoveListItem(index:Int)
DebugLog "TQtComboBox::RemoveListItem(" + index + ")"
		MaxGuiQComboBox(widget).removeItem(index)
	End Method

	Method Class:Int()
		Return GADGET_COMBOBOX
	EndMethod

End Type

Type TQtDesktop Extends TQtGadget

	Method InitGadget()
		CreateDesktop()
	End Method
	
	Method CreateDesktop()
	
		widget = QApplication.Desktop()
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_DESKTOP
	EndMethod

End Type

Type TQtToolBar Extends TQtGadget

	Method InitGadget()
		CreateToolBar()
	End Method
	
	Method CreateToolBar()

		If parent.Class() <> GADGET_WINDOW Then
			DebugLog "Parent is not a WINDOW!?"
			Return
		End If
	
		widget = New MaxGuiQToolBar.MCreate(Null, Self)
		
		TQtWindow(parent).AddToolbar(Self)		
		
		Rethink()
		
		SetShow(True)
		' window goes hidden? Let's show it for now...
		parent.SetShow(True)
		
		
	End Method

	Method Class:Int()
		Return GADGET_TOOLBAR
	EndMethod

	Method InsertListItem(index:Int, text:String, tip:String, icon:Int, extra:Object)
		Local image:QIcon
		Local w:Int
		
		If icons And icon >= 0 Then
			image = icons.icons[icon]
			w = icons.dim
		End If
		
		MaxGuiQToolBar(widget).InsertListItem(index, text, tip, image, extra, w)
		
	End Method

	Method Rethink()
		' toolbar looks after its own size!
	End Method

End Type

Type TQtTabber Extends TQtGadget

	Method InitGadget()
		CreateTabber()
	End Method
	
	Method CreateTabber()
	
		widget = New MaxGuiQTabWidget.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_TABBER
	EndMethod

End Type

Type TQtTreeView Extends TQtGadget

	Method InitGadget()
		CreateTreeView()
	End Method
	
	Method CreateTreeView()
	
		widget = New MaxGuiQTreeView.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_TREEVIEW
	EndMethod

End Type

Type TQtHtmlView Extends TQtGadget

	Method InitGadget()
		CreateHTMLView()
	End Method
	
	Method CreateHTMLView()
	
		widget = New MaxGuiQWebView.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method SetText(text:String)
	
		' construct a valid URL
		Local anchor$, a:Int
		a = text.Find("#")
		If a <> -1 Then
			anchor = text[a..]
			text = text[..a]
		End If
		If text[0..7].ToLower() <> "http://" And text[0..7].ToLower() <> "file://"
			If FileType(text)
				text = "file://" + text
			Else
				text = "http://" + text
			End If
		End If
		text:+ anchor
		text = text.Replace(" ","%20")

		' load the URL
		MaxGuiQWebView(widget).Load(New QUrl.Create(text))
	End Method
	
	Method Class:Int()
		Return GADGET_HTMLVIEW
	EndMethod

End Type

Type TQtTrackBar Extends TQtGadget

	Method InitGadget()
		CreateTrackBar()
	End Method
	
	Method CreateTrackBar()
	
		Local orientation:Int = Qt_Horizontal

		If style & SLIDER_VERTICAL Then
			orientation = Qt_Vertical
		End If
	
		widget = New MaxGuiQSlider.MCreate(orientation, TQtGadget(parent).RealParentForChild(), Self)
		
		' default range
		SetRange(1, 10)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_SLIDER
	EndMethod

	Method SetRange(small:Int, big:Int)
		MaxGuiQSlider(widget).setRange(small, big)
	End Method
	
End Type

Type TQtStepper Extends TQtGadget

	Method InitGadget()
		CreateStepper()
	End Method
	
	Method CreateStepper()
	
		'Local orientation:Int = Qt_Horizontal

		'If style & SLIDER_VERTICAL Then
		'	orientation = Qt_Vertical
		'End If
	
		widget = New MaxGuiQSpinBox.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_SLIDER
	EndMethod

End Type

Type TQtScrollBar Extends TQtGadget

	Method InitGadget()
		CreateScrollBar()
	End Method
	
	Method CreateScrollBar()
	
		Local orientation:Int = Qt_Horizontal
		
		If style & SLIDER_VERTICAL Then
			orientation = Qt_Vertical
		End If
	
		widget = New MaxGuiQScrollBar.MCreate(orientation, TQtGadget(parent).RealParentForChild(), Self)
		
		' default range
		SetRange(1, 10)

		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_SLIDER
	EndMethod

	Method SetRange(small:Int, big:Int)
		MaxGuiQScrollBar(widget).setRange(small, big)
	End Method

End Type

Type TQtMenuItem Extends TQtGadget

	Method InitGadget()
		CreateMenuItem()
	End Method
	
	Method CreateMenuItem()
	
		widget = New MaxGuiQMenu.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_MENUITEM
	EndMethod

End Type

Type TQtCanvas Extends TQtGadget

	Method InitGadget()
		CreateCanvas()
	End Method
	
	Method CreateCanvas()
	
		'widget = New MaxGuiQGLWidget.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		' PLACEHOLDER
		widget = New QWidget._Create(TQtGadget(parent).RealParentForChild())
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method Class:Int()
		Return GADGET_CANVAS
	EndMethod

End Type

' -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
'                                         NATIVE WIDGETS
' -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

Type MaxGuiQMainWindow Extends QMainWindow

	Field gadget:TQtGadget
	Field menubar:QMenuBar
	Field statusbar:QStatusBar
	
	Field sbLabels:QLabel[3]
	Field sbText:String

	Field tbIconSize:Int
	
	' this is our "client area"
	' it automatically scales to fit the inside of the window.
	Field clientWidget:QWidget

	Method MCreate:MaxGuiQMainWindow(parent:QWidget = Null, flags:Int, owner:TQtGadget)
		gadget = owner
		Super.Create(parent, flags)
		Return Self
	End Method

	Method OnInit()
		clientWidget = New QWidget._Create(Self)
		setCentralWidget(clientWidget)
		' set mouse tracking to generate mouse movement events for child widgets
		clientWidget.setMouseTracking(True)
		' nice toolbars
		setUnifiedTitleAndToolBarOnMac(True)
	End Method
	
	Method createMenuBar()
		menubar = New QMenuBar.Create()
		setMenuBar(menubar)
	End Method
	
	Method createStatusBar()
		statusbar = New QStatusBar.Create()
		setStatusBar(statusbar)
		
		Local align:Int = Qt_AlignLeft
		' set up labels.
		For Local i:Int = 0 Until 3
			sbLabels[i] = New QLabel.Create("")
			Select i
				Case 0
					align = Qt_AlignLeft
				Case 1
					align = Qt_AlignHCenter
				Case 2
					align = Qt_AlignRight
			End Select
			sbLabels[i].setAlignment(align)
			
			statusbar.addWidget(sbLabels[i], 1)
		Next
	End Method
	
	Method closeEvent(event:QCloseEvent)
		PostGuiEvent EVENT_WINDOWCLOSE, gadget
		
		Super.closeEvent(event)
	End Method
	
	Method ClientWidth:Int()
		Return clientWidget.width()
	End Method

	Method ClientHeight:Int()
		Return clientWidget.height()
	End Method

	Method resizeEvent(event:QResizeEvent)
		Local w:Int, h:Int
		event.size(w, h)
		PostGuiEvent EVENT_WINDOWSIZE, gadget ,,,w,h
		
		Super.resizeEvent(event)
	End Method
	
	Method moveEvent(event:QMoveEvent)
		PostGuiEvent EVENT_WINDOWMOVE, gadget
		
		Super.moveEvent(event)
	End Method
	
	Method SetStatusText(text:String)
		Local tab:Int
		Local t0:String, t1:String, t2:String
		
		sbText = text
		
		t0 = text
		tab = t0.find("~t")
		If tab <> -1 Then
			t1 = t0[tab+1..]
			t0 = t0[..tab]
		End If
				
		tab = t1.find("~t")
		If tab <> -1 Then
			t2 = t1[tab+1..]
			t1 = t1[..tab]
		End If
		
		sbLabels[0].setText(t0)
		sbLabels[1].setText(t1)
		sbLabels[2].setText(t2)
	End Method
	
End Type

Type MaxGuiQPushButton Extends QPushButton

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQPushButton(text:String, parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(text, parent)
		Return Self
	End Method

	Method OnInit()
		connect(Self, "clicked", Self, "onClick")
	End Method

	Method onClick()
		PostGuiEvent EVENT_GADGETACTION, gadget
	End Method
	
End Type

Type MaxGuiQCheckBoxButton Extends QCheckBox

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQCheckBoxButton(text:String, parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(text, parent)
		Return Self
	End Method

	Method OnInit()
		connect(Self, "toggled", Self, "onToggled")
	End Method

	Method onToggled()
		PostGuiEvent EVENT_GADGETACTION, gadget, ButtonState(gadget)
	End Method
	
End Type

Type MaxGuiQRadioButton Extends QRadioButton

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQRadioButton(text:String, parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(text, parent)
		Return Self
	End Method

	Method OnInit()
		connect(Self, "toggled", Self, "onToggled")
	End Method

	Method onToggled()
		PostGuiEvent EVENT_GADGETACTION, gadget, ButtonState(gadget)
	End Method
	
End Type

Type MaxGuiQLabel Extends QLabel

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQLabel(text:String, parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(text, parent)
		Return Self
	End Method
	
	Method OnInit()
	End Method

	Method enterEvent(event:QEvent)
		'PostGuiEvent EVENT_MOUSEENTER, gadget
	End Method

	Method leaveEvent(event:QEvent)
		'PostGuiEvent EVENT_MOUSELEAVE, gadget
	End Method

	Method mousePressEvent(event:QMouseEvent)
		If event.button() & Qt_RightButton Then
			PostGuiEvent EVENT_GADGETMENU, gadget, event.button(), event.x(), event.y()
		Else
			PostGuiEvent EVENT_MOUSEDOWN, gadget, event.button(), event.x(), event.y()
		End If
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		' TODO : We want this event for a label?
		PostGuiEvent EVENT_MOUSEUP, gadget, event.button(), event.x(), event.y()
	End Method
	
End Type

' a MaxGUI Panel
Type MaxGuiQFrame Extends QFrame

	Field gadget:TQtPanel

	' this is our "client area"
	' it automatically scales to fit the inside of the gadget.
	Field clientWidget:QWidget

	Method MCreate:MaxGuiQFrame(parent:QWidget, owner:TQtPanel)
		gadget = owner
		Super._Create(parent)
		Return Self
	End Method

	Method OnInit()
		Local layout:QVBoxLayout = New QVBoxLayout.Create()
		layout.setContentsMargins(0, 0, 0, 0)
		
		clientWidget = New QWidget._Create()
		layout.addWidget(clientWidget)
		setLayout(layout)

		' set mouse tracking to generate mouse movement events for child widgets
		clientWidget.setMouseTracking(True)
	End Method

	Method ClientWidth:Int()
		Return clientWidget.width()
	End Method

	Method ClientHeight:Int()
		Return clientWidget.height()
	End Method

	Method enterEvent(event:QEvent)
		If gadget.activePanel Then
			PostGuiEvent EVENT_MOUSEENTER, gadget
		End If
	End Method

	Method leaveEvent(event:QEvent)
		If gadget.activePanel Then
			PostGuiEvent EVENT_MOUSELEAVE, gadget
		End If
	End Method

	Method mousePressEvent(event:QMouseEvent)
		If gadget.activePanel Then
			If event.button() & Qt_RightButton Then
				PostGuiEvent EVENT_GADGETMENU, gadget, event.button(), , event.x(), event.y()
			Else
				PostGuiEvent EVENT_MOUSEDOWN, gadget, event.button(), , event.x(), event.y()
			End If
		End If
	End Method
	
	Method mouseMoveEvent(event:QMouseEvent)
		If gadget.activePanel Then
			PostGuiEvent EVENT_MOUSEMOVE, gadget, event.button(), , event.x(), event.y()
		End If		
	End Method
	
End Type

' "group box" panel
Type MaxGuiQGroupBox Extends QGroupBox

	Field gadget:TQtGadget

	' this is our "client area"
	' it automatically scales to fit the inside of the gadget.
	Field clientWidget:QWidget

	Method MCreate:MaxGuiQGroupBox(text:String, parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(text, parent)
		Return Self
	End Method

	Method OnInit()
		Local layout:QVBoxLayout = New QVBoxLayout.Create()
		layout.setContentsMargins(0, 0, 0, 0)
		
		clientWidget = New QWidget._Create()
		layout.addWidget(clientWidget)
		setLayout(layout)
	End Method

	Method ClientWidth:Int()
		Return clientWidget.width()
	End Method

	Method ClientHeight:Int()
		Return clientWidget.height()
	End Method

End Type

Type MaxGuiQLineEdit Extends QLineEdit

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQLineEdit(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
		connect(Self, "textEdited", Self, "onTextEdited")
	End Method
	
	Method onTextEdited(text:String)
		PostGuiEvent EVENT_GADGETACTION, gadget, ,,,,text
	End Method

End Type

Type MaxGuiQTextEdit Extends QTextEdit

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQTextEdit(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
	End Method

End Type

Type MaxGuiQListView Extends QListView

	Field gadget:TQtGadget
	Field model:QStandardItemModel
	Field selectionModel:QItemSelectionModel
	
	Field runSilent:Int = False

	Method MCreate:MaxGuiQListView(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
		model = New QStandardItemModel.Create()
		setModel(model)

		selectionModel = New QItemSelectionModel.Create(model)
		setSelectionModel(selectionModel)

		setSelectionMode(QAbstractItemView.Mode_SingleSelection)
		
		connect(selectionModel, "selectionChanged", Self, "onSelectionChanged")
		connect(Self, "doubleClicked", Self, "onDoubleClicked")
	End Method

	Method insertListItem(index:Int, text:String, tip:String, icon:QIcon, extra:Object)
		
		model.insertRows(index, 1)

		Local idx:QModelIndex = model.index(index, 0)
		model.setData(idx, text)
		
		If extra Then
			model.setData(idx, extra, Qt_UserRole)
		End If
		
		If tip Then
			model.setData(idx, tip, Qt_ToolTipRole)
		End If
		
		If icon Then
			model.setData(idx, icon, Qt_DecorationRole)
		End If
	End Method

	Method setListItem(index:Int, text:String, tip:String, icon:QIcon, extra:Object)

		Local idx:QModelIndex = model.index(index, 0)
		model.setData(idx, text)
		model.setData(idx, extra, Qt_UserRole)
		model.setData(idx, tip, Qt_ToolTipRole)
		model.setData(idx, icon, Qt_DecorationRole)

	End Method

	Method setListItemState(index:Int, state:Int)
		Local op:Int
		Local idx:QModelIndex = model.index(index, 0)

		If state & STATE_DISABLED Then
			op = QItemSelectionModel.Selection_Deselect
		End If
		
		If state & STATE_SELECTED Then
			op = QItemSelectionModel.Selection_ClearAndSelect
		End If

		runSilent = True
		selectionModel.setCurrentIndex(idx, op)
		runSilent = False
	End Method
	
	Method removeItem(index:Int)
		model.removeRows(index, 1)
	End Method
	
	Method onSelectionChanged(selected:QItemSelection, deselected:QItemSelection)
		If Not runSilent
			' well, it's a bit of a hack, picking the first one from the list (we assume single-row selection!)
			Local indexes:QModelIndex[] = selected.indexes()
		
			If indexes.length > 0	
				PostGuiEvent EVENT_GADGETSELECT, gadget, indexes[0].row()
			End If
		End If
	End Method
	
	Method onDoubleClicked(index:QModelIndex)
		PostGuiEvent EVENT_GADGETACTION, gadget, index.row()
	End Method
	
	Method listItemState:Int(index:Int)
		Local idx:QModelIndex = model.index(index, 0)
		
		If selectionModel.isSelected(idx) Then
			Return STATE_SELECTED
		Else
			Return STATE_DISABLED
		End If
	End Method

End Type

Type MaxGuiQProgressBar Extends QProgressBar

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQProgressBar(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
	End Method

End Type

Type MaxGuiQComboBox Extends QComboBox

	Field gadget:TQtGadget
	Field model:QStandardItemModel

	Method MCreate:MaxGuiQComboBox(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
		model = New QStandardItemModel.Create()
		setModel(model)
	
		connect(Self, "currentIndexChanged", Self, "onCurrentIndexChanged")
		connect(Self, "editTextChanged", Self, "onEditTextChanged")
	End Method

	Method insertListItem(index:Int, text:String, tip:String, icon:QIcon, extra:Object)
		insertItem(index, text, extra)
		If icon Then
			setItemIcon(index, icon)
		End If
	End Method

	Method setListItem(index:Int, text:String, tip:String, icon:QIcon, extra:Object)
		setItemText(index, text)
		If icon Then
			setItemIcon(index, icon)
		End If
		setItemData(index, extra)
	End Method
	
	Method onCurrentIndexChanged(index:Int)
		PostGuiEvent EVENT_GADGETACTION, gadget, index
	End Method
	
	Method onEditTextChanged(text:String)
		Local index:Int = -1 ' TODO : completer().currentIndex().row()
		PostGuiEvent EVENT_GADGETACTION, gadget, index, ,,,text
	End Method
	
End Type

Type MaxGuiQToolBar Extends QToolBar

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQToolBar(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
		setMovable(False)
	End Method

	Method InsertListItem(index:Int, text:String, tip:String, icon:QIcon, extra:Object, width:Int)

		'Local widget:QWidget = New QWidget._Create()
		Local action:QAction
		
		If Not icon Then
			action = New QAction.Create(text, Self)
			action.setSeparator(True)
		Else
			action = New QAction.CreateWithIcon(icon, text, Self)
		End If
		
		action.setToolTip(tip)
		
		addAction(action)
		
		Local parent:TQtWindow = TQtWindow(gadget.parent)
		If parent Then
			If MaxGuiQMainWindow(parent.widget).tbIconSize = 0 And width > 0 Then
				MaxGuiQMainWindow(parent.widget).tbIconSize = width
				MaxGuiQMainWindow(parent.widget).setIconSize(width, width)
			End If
		End If
		
	End Method
	
End Type

Type MaxGuiQTabWidget Extends QTabWidget

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQTabWidget(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
	End Method

End Type

Type MaxGuiQTreeView Extends QTreeView

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQTreeView(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
	End Method

End Type

Type MaxGuiQWebView Extends QWebView

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQWebView(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
	End Method

End Type

Type MaxGuiQSlider Extends QSlider

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQSlider(orientation:Int, parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(orientation, parent)
		Return Self
	End Method

	Method OnInit()
		connect(Self, "valueChanged", Self, "onValueChanged")
	End Method

	Method onValueChanged(value:Int)
		PostGuiEvent EVENT_GADGETACTION, gadget, value
	End Method
	
End Type

Type MaxGuiQScrollBar Extends QScrollBar

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQScrollBar(orientation:Int, parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(orientation, parent)
		Return Self
	End Method

	Method OnInit()
		connect(Self, "valueChanged", Self, "onValueChanged")
	End Method

	Method onValueChanged(value:Int)
		PostGuiEvent EVENT_GADGETACTION, gadget, value
	End Method
	
End Type

Type MaxGuiQSpinBox Extends QSpinBox

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQSpinBox(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
	End Method

End Type

Type MaxGuiQMenu Extends QMenu

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQMenu(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
	End Method

End Type

