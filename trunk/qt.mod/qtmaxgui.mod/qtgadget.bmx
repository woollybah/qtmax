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

Import "qtfont.bmx"

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
'DebugLog "SetShow(" + truefalse + ")"
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

	' default to own width
	Method ClientWidth:Int()
		Return widget.width()
	End Method

	' default to own height
	Method ClientHeight:Int()
		Return widget.height()
	End Method

	Method getParentWindow:TQtGadget()
		If TQtWindow(Self) Then Return Self
	
		If parent Then
			If TQtWindow(parent) Then
				Return TQtGadget(parent)
			End If
			
			Return TQtGadget(parent).getParentWindow()
		End If
		
		Return Null
	End Method

	Method SetFont(font:TGuiFont)
		widget.setFont(TQtGuiFont(font).font)
	End Method

	Method ConvertPixmap:QPixmap(pixmap:TPixmap)
		If pixmap
			Select pixmap.format
				Case PF_I8,PF_BGR888
					pixmap=pixmap.Convert( PF_RGB888 )
				Case PF_A8,PF_BGRA8888
					pixmap=pixmap.Convert( PF_RGBA8888 )
				Default
					pixmap=pixmap.Copy()
			End Select
			
			If AlphaBitsPerPixel[ pixmap.format ]
				For Local y:Int = 0 Until pixmap.height
					For Local x:Int = 0 Until pixmap.width
						Local argb:Int = pixmap.ReadPixel( x,y )
						pixmap.WritePixel x, y, TQtIconStrip.premult(argb)
					Next
				Next
			EndIf
			Return QPixmap.FromPixmap(pixmap)
		EndIf
		Return Null
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
			Default
				pixmap = pixmap.Copy()
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
		
		If parent Then
			widget = New MaxGuiQMainWindow.MCreate(TQtGadget(parent).widget, style, Self)
		Else
			widget = New MaxGuiQMainWindow.MCreate(Null, style, Self)
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

	Method Rethink()
		If widget Then
			widget.move(xpos, ypos)
			widget.resize(width, height)

			LayoutKids()
		End If
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
	
	Method GetMenu:TGadget()
		' return the window itself. Menus are attached to the menubar.
		' we deal with that in the menu item code!
		Return Self
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
	
	Method SetPixmap(pixmap:TPixmap, flags:Int)
		If pixmap Then
			Local pix:QPixmap = ConvertPixmap(pixmap)
			MaxGuiQFrame(widget).setPixmap(pix, flags)
		End If
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
	
		widget = New MaxGuiQPlainTextEdit.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		If ~style & TEXTAREA_WORDWRAP Then
			MaxGuiQPlainTextEdit(widget).setLineWrapMode(QPlainTextEdit.Mode_NoWrap)
		End If
		
		If style & TEXTAREA_READONLY Then
			MaxGuiQPlainTextEdit(widget).setReadOnly(True)
		End If
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method SetText(text:String)
		MaxGuiQPlainTextEdit(widget).setPlainText(text)
	End Method

	Method ReplaceText(pos:Int, length:Int, text:String, units:Int)
		MaxGuiQPlainTextEdit(widget).replaceText(pos, length, text, units)
	End Method

	Method AddText(text:String)
		MaxGuiQPlainTextEdit(widget).appendPlainText(text)
	End Method

	Method AreaText:String(pos:Int, length:Int, units:Int)
		Return MaxGuiQPlainTextEdit(widget).areaText(pos, length, units)
	End Method

	Method AreaLen:Int(units:Int)
		Return MaxGuiQPlainTextEdit(widget).areaLen(units)
	End Method

	Method LockText()
		' TODO : maybe to grab a QTextCursor and apply everything to it until unlocked
		'  when we finally re-set it to the edit widget.
		MaxGuiQPlainTextEdit(widget).lock()
	End Method

	Method UnlockText()
		MaxGuiQPlainTextEdit(widget).unlock()
	End Method

	Method SetTabs(tabwidth:Int)
		MaxGuiQPlainTextEdit(widget).setTabStopWidth(tabwidth)
	End Method

	Method SetMargins(leftmargin:Int)
		DebugLog "TODO - TQtTextArea::SetMargins"
	End Method

	Method GetCursorPos:Int(units:Int)
		Return MaxGuiQPlainTextEdit(widget).getCursorPos(units)
	End Method

	Method GetSelectionLength:Int(units:Int)
		Return MaxGuiQPlainTextEdit(widget).getSelectionLength(units)
	End Method

	Method SetStyle(r:Int, g:Int, b:Int, flags:Int, pos:Int, length:Int, units:Int)
		MaxGuiQPlainTextEdit(widget).setTextStyle(r, g, b, flags, pos, length, units)
	End Method	

	Method SetSelection(pos:Int, length:Int, units:Int)
		MaxGuiQPlainTextEdit(widget).setSelection(pos, length, units)
	End Method

	Method CharX:Int(char:Int)
		Return MaxGuiQPlainTextEdit(widget).charX(char)
	End Method

	Method CharY:Int(char:Int)
		Return MaxGuiQPlainTextEdit(widget).charY(char)
	End Method

	Method CharAt:Int(line:Int)
		Return MaxGuiQPlainTextEdit(widget).charAt(line)
	End Method

	Method LineAt:Int(index:Int)
		Return MaxGuiQPlainTextEdit(widget).lineAt(index)
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

	Method GetWidth%()
		Return widget.width()
	EndMethod
	
	Method GetHeight%()
		Return widget.height()
	EndMethod

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

	Method InsertListItem(index:Int, text:String, tip:String, icon:Int, extra:Object)
		Local image:QIcon
		
		If icons And icon >= 0 Then
			image = icons.icons[icon]
		End If
		MaxGuiQTabWidget(widget).insertListItem(index, text, tip, image, extra)
	End Method
	
	Method RealParentForChild:QWidget()
		Return MaxGuiQTabWidget(widget).clientWidget
	End Method

	Method ClientWidth:Int()
		Return MaxGuiQTabWidget(widget).ClientWidth()
	End Method

	Method ClientHeight:Int()
		Return MaxGuiQTabWidget(widget).ClientHeight()
	End Method
	
	Method SelectedItem:Int()
		Return MaxGuiQTabWidget(widget).currentIndex()
	End Method

	Method Class:Int()
		Return GADGET_TABBER
	EndMethod

End Type

Type TQtTreeViewNode Extends TQtGadget

	Field item:QStandardItem

	Method CreateNode:TQtTreeViewNode(text:String, group:TQtGadget, tree:QWidget, style:Int)
	
		Self.style = style
		parent = group
		widget = tree
		'InitGadget()

		MaxGuiQTreeView(widget).insertNode(Self)
		
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
		
		Return Self
	End Method

	Method InitGadget()
	End Method
	
	Method InsertNode:TGadget(index:Int, text:String, icon:Int)
		Local node:TQtTreeViewNode = New TQtTreeViewNode.CreateNode(text, Self, widget, index)
		'node.SetIcon icon
		node._SetParent Self
		Return node
	End Method

	Method ModifyNode(text$, icon:Int)
		Local image:QIcon
		
		If icons And icon >= 0 Then
			image = icons.icons[icon]
		End If
		
		MaxGuiQTreeView(widget).setItemText(item, text)
		If image Then
			item.setIcon(image)
		End If
	End Method
	
	Method SelectedNode:TGadget()
		DebugLog "TODO : TQtTreeView::SelectedNode"
	End Method
	
	Method CountKids:Int()
		DebugLog "TODO : TQtTreeView::CountKids"
	End Method

	Method SetText(text:String)
		MaxGuiQTreeView(widget).setItemText(item, text)
	End Method

	Method Class:Int()
		Return GADGET_NODE
	EndMethod

End Type


Type TQtTreeView Extends TQtTreeViewNode

	Method InitGadget()
		CreateTreeView()
	End Method
	
	Method CreateTreeView()
	
		widget = New MaxGuiQTreeView.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		' get root item
		item = MaxGuiQTreeView(widget).model.root
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method RootNode:TGadget()
		Return Self
	End Method
	
	Method SetText(text:String)
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

	Field action:QAction

	Method InitGadget()
		CreateMenuItem()
	End Method
	
	Method CreateMenuItem()

		If parent Then
			Local parentWindow:TQtGadget = TQtGadget(parent).getParentWindow()
			If parentWindow Then
				action = New MaxGuiQMenuAction.MCreate(parentWindow.widget, Self)
			Else
				action = New MaxGuiQMenuAction.MCreate(qApp, Self)
			End If
		Else
			action = New MaxGuiQMenuAction.MCreate(qApp, Self)
		End If
		
		Rethink()
		
		'SetShow(True)
		
	End Method
	
	Method SetText(text:String)
		'If action Then
			If text Then
				action.setText(text)
			Else
				action.setSeparator(True)
			End If
		'End If
	End Method

	Method SetTooltip(text:String)
		action.setToolTip(text)
	End Method

	Method SetHotKey(hotkey:Int, modifier:Int)
		hotkey = TQtKeyMap.mapKey(hotkey)
		modifier = TQtKeyMap.mapModifier(modifier)
		
		Local seq:QKeySequence = New QKeySequence.Create(hotkey + modifier)
		action.setShortcut(seq)
	End Method

	Method ClientWidth:Int()
		Return 0
	End Method

	Method ClientHeight:Int()
		Return 0
	End Method

	Method Class:Int()
		Return GADGET_MENUITEM
	EndMethod

End Type

Type TQtCanvas Extends TQtGadget

	Field canvas:TGraphics
	Field canvasFlags:Int

	Method InitGadget()
		CreateCanvas()
	End Method
	
	Method CreateCanvas()
	
		widget = New MaxGuiCanvasWidget.MCreate(TQtGadget(parent).RealParentForChild(), Self)
		
		' no widget double-buffering
		widget.setAttribute(Qt_WA_PaintOnScreen)
		
		Rethink()
		
		SetShow(True)
		
	End Method

	Method AttachGraphics:TGraphics( flags:Int )
		canvasFlags = flags
		canvas=brl.Graphics.AttachGraphics(widget.winId(), flags)
	End Method
	
	Method CanvasGraphics:TGraphics()
		Return canvas
	End Method
	
	Method Activate(kind:Int)
		If kind = ACTIVATE_REDRAW Then
			widget.update()
		End If
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

	Method MCreate:MaxGuiQMainWindow(parent:QWidget = Null, style:Int, owner:TQtGadget)
		Local flags:Int
		
		If style & WINDOW_TOOL Then
			flags :| Qt_Tool
		End If

		gadget = owner
		Super.Create(parent, flags)
		Return Self
	End Method

	Method OnInit()
		clientWidget = New QWidget._Create(Self)
		setCentralWidget(clientWidget)
		
		If gadget.style & WINDOW_CLIENTCOORDS Then
			clientWidget.resize(gadget.width, gadget.height)
		End If
		
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

		gadget.SetRect(gadget.xpos, gadget.ypos, w, h)
		gadget.layoutKids

		PostGuiEvent EVENT_WINDOWSIZE, gadget ,,,w,h
		
		Super.resizeEvent(event)
	End Method
	
	Method moveEvent(event:QMoveEvent)
		Local x:Int, y:Int
		event.pos(x, y)
		
		gadget.SetRect(x, y, gadget.width, gadget.height)
		
		PostGuiEvent EVENT_WINDOWMOVE, gadget,,,x,y
		
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
			PostGuiEvent EVENT_GADGETMENU, gadget, event.button(), , event.x(), event.y()
		Else
			PostGuiEvent EVENT_MOUSEDOWN, gadget, event.button(), , event.x(), event.y()
		End If
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		' TODO : We want this event for a label?
		PostGuiEvent EVENT_MOUSEUP, gadget, event.button(), , event.x(), event.y()
	End Method
	
End Type

' a MaxGUI Panel
Type MaxGuiQFrame Extends QFrame

	Field gadget:TQtPanel

	' this is our "client area"
	' it automatically scales to fit the inside of the gadget.
	Field clientWidget:MaxGuiQClientWidget

	Method MCreate:MaxGuiQFrame(parent:QWidget, owner:TQtPanel)
		gadget = owner
		Super._Create(parent)
		Return Self
	End Method

	Method OnInit()
		Local layout:QVBoxLayout = New QVBoxLayout.Create()
		layout.setContentsMargins(0, 0, 0, 0)
		
		clientWidget = MaxGuiQClientWidget(New MaxGuiQClientWidget._Create())
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

	Method mouseReleaseEvent(event:QMouseEvent)
		If gadget.activePanel Then
			PostGuiEvent EVENT_MOUSEUP, gadget, event.button(), , event.x(), event.y()
		End If		
	End Method

	Method setPixmap(pixmap:QPixmap, flags:Int)
		clientWidget.pix = pixmap
		clientWidget.pixFlags = flags
		
		update()
	End Method

End Type

Type MaxGuiQClientWidget Extends QWidget

	Field pix:QPixmap
	Field pixFlags:Int

	Method OnInit()
	End Method
	
	Method paintEvent(event:QPaintEvent)
		If pix Then

			Local painter:QPainter = New QPainter.Create(Self)

			Select pixFlags & (PANELPIXMAP_TILE | PANELPIXMAP_CENTER | PANELPIXMAP_FIT | PANELPIXMAP_FIT2 | PANELPIXMAP_STRETCH)
				Case PANELPIXMAP_TILE

					painter.drawTiledPixmap(0, 0, width(), height(), pix)
				
				Case PANELPIXMAP_CENTER

					painter.DrawPixmap(width() / 2 - pix.width() / 2, height() / 2 - pix.height() / 2, pix)
					
				Case PANELPIXMAP_FIT
					Local _w:Float = width() / (pix.width() * 1.0)
					Local _h:Float = height() / (pix.height() * 1.0)

					Local newWidth:Int = Min(_w, _h) * pix.width()
					Local newHeight:Int = Min(_w, _h) * pix.height()

					painter.DrawPixmapSize(width() / 2 - newWidth / 2, height() / 2 - newHeight / 2, newWidth, newHeight, pix)

				Case PANELPIXMAP_FIT2
					Local _w:Float = width() / (pix.width() * 1.0)
					Local _h:Float = height() / (pix.height() * 1.0)

					Local newWidth:Int = Max(_w, _h) * pix.width()
					Local newHeight:Int = Max(_w, _h) * pix.height()

					painter.DrawPixmapSize(width() / 2 - newWidth / 2, height() / 2 - newHeight / 2, newWidth, newHeight, pix)
					
				Case PANELPIXMAP_STRETCH

					painter.DrawPixmapSize(0, 0, width(), height(), pix)
			End Select
			
			painter.DoEnd()
		End If
		
		Super.paintEvent(event)
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

Type MaxGuiQPlainTextEdit Extends QPlainTextEdit

	Field gadget:TQtGadget
	
	Field lockedCursor:QTextCursor
	Field locked:Int
	
	Field styles:TMap = New TMap

	Method MCreate:MaxGuiQPlainTextEdit(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
		connect(Self, "cursorPositionChanged", Self, "onCursorPositionChanged")
		connect(Self, "textChanged", Self, "onTextChanged")
	End Method

	Method onCursorPositionChanged()
		If Not locked Then
			PostGuiEvent EVENT_GADGETSELECT, gadget
		End If
	End Method
	
	Method onTextChanged()
		If Not locked Then
			PostGuiEvent EVENT_GADGETACTION, gadget
		End If
	End Method

	Method setSelection(pos:Int, length:Int, units:Int)

		Local cursor:QTextCursor = getCursor()
		
		setCursorSelection(cursor, pos, length, units)
		
		updateCursor(cursor)
	End Method

	Method setCursorSelection(cursor:QTextCursor, pos:Int, length:Int, units:Int)

		Local moveOp:Int = QTextCursor.Op_NextCharacter
		
		If units = TEXTAREA_LINES Then
			moveOp = QTextCursor.Op_Down

			' 1) move cursor pos/anchor, to start, then find pos
			cursor.movePosition(QTextCursor.Op_Start)
			cursor.movePosition(moveOp, QTextCursor.Mode_MoveAnchor, pos)
		Else
			' 1) set absolute pos
			cursor.setPosition(pos)
		End If
		
		' 2) move, keep anchor
		cursor.movePosition(moveOp, QTextCursor.Mode_KeepAnchor, length)
	
	End Method

	Method getCursorPos:Int(units:Int)
		Local cursor:QTextCursor = textCursor()
		
		If units = TEXTAREA_LINES Then
			Return cursor.blockNumber()
		Else
			Return cursor.position()
		End If
	End Method
	
	Method getSelectionLength:Int(units:Int)
		Local cursor:QTextCursor = textCursor()
		Return calcLength(cursor, units)
	End Method
	
	Method calcLength:Int(cursor:QTextCursor, units:Int)
		If units = TEXTAREA_LINES Then
			Local _start:Int = cursor.selectionStart()
			Local _end:Int = cursor.selectionEnd()
			
			cursor.setPosition(_start)
			_start = cursor.blockNumber()
			
			cursor.setPosition(_end)
			_end = cursor.blockNumber()
			
			Return _end - _start
		Else
			Return Abs(cursor.position() - cursor.anchor())
		End If
	End Method
	
	Method areaLen:Int(units:Int)
		Local cursor:QTextCursor = textCursor()

		cursor.movePosition(QTextCursor.Op_Start, QTextCursor.Mode_MoveAnchor)
		cursor.movePosition(QTextCursor.Op_Start, QTextCursor.Mode_KeepAnchor)

		Return calcLength(cursor, units)
	End Method
	
	Method charX:Int(char:Int)
		Local cursor:QTextCursor = textCursor()
		cursor.setPosition(char)
		Local x:Int, y:Int, w:Int, h:Int
		cursorRectCursor(cursor, x, y, w, h)
		Return x
	End Method

	Method charY:Int(char:Int)
		Local cursor:QTextCursor = textCursor()
		cursor.setPosition(char)
		Local x:Int, y:Int, w:Int, h:Int
		cursorRectCursor(cursor, x, y, w, h)
		Return y
	End Method
	
	Method charAt:Int(line:Int)
		Local cursor:QTextCursor = textCursor()
	
		cursor.movePosition(QTextCursor.Op_Start)
		cursor.movePosition(QTextCursor.Op_Down, QTextCursor.Mode_MoveAnchor, line)
		
		Return cursor.position()
	End Method
	
	Method lineAt:Int(index:Int)
		Local cursor:QTextCursor = textCursor()
		cursor.setPosition(index)
		Return cursor.blockNumber()
	End Method

	Method replaceText(pos:Int, length:Int, text:String, units:Int)
		Local cursor:QTextCursor = getCursor()

		' get the current cursor pos
		Local position:Int = cursor.position()
	
		' select text in range
		setCursorSelection(cursor, pos, length, units)
		
		' remove selected text
		cursor.removeSelectedText()
		
		' insert new text
		cursor.insertText(text)

		' reset the cursor
		cursor.setPosition(position)
		
		updateCursor(cursor)
	End Method
	
	Method getCursor:QTextCursor()
		If locked Then
			Return lockedCursor
		Else
			Return textCursor()
		End If
	End Method
	
	Method updateCursor(cursor:QTextCursor)
		If Not locked Then
			setTextCursor(cursor)
		End If
	End Method
	
	Method lock()
		If Not lockedCursor Then
			lockedCursor = textCursor()
			locked = True
		End If
	End Method
	
	Method unlock()
		If lockedCursor Then
			setTextCursor(lockedCursor)
			lockedCursor = Null
			locked = False
		End If
	End Method

	Method setTextStyle(r:Int, g:Int, b:Int, flags:Int, pos:Int, length:Int, units:Int)
		Local cursor:QTextCursor = getCursor()

		' get the current cursor pos
		Local position:Int = cursor.position()

		setCursorSelection(cursor, pos, length, units)
		
		Local format:QTextCharFormat = getStyleFormat(r, g, b, flags)
		
		cursor.setCharFormat(format)
		
		' reset the cursor
		cursor.setPosition(position)
	
		updateCursor(cursor)
	End Method
	
	Method getStyleFormat:QTextCharFormat(r:Int, g:Int, b:Int, flags:Int)
		Local f:String = r + "," + g + "," + b + "," + flags
'DebugLog "getStyleFormat : " + f
		Local format:QTextCharFormat = QTextCharFormat(styles.ValueForKey(f))
		
		If Not format Then
			format = New QTextCharFormat.Create()
			format.setForeground(New QBrush.CreateWithColor(New QColor.Create(r, g, b)))
			
			' flags...
			
			styles.Insert(f, format)
		End If
		
		Return format
	End Method

	Method areaText:String(pos:Int, length:Int, units:Int)
'DebugLog "areaText (" + pos + ", " + length + ", " + units + ")"

		If length <> TEXTAREA_ALL Then
			Local cursor:QTextCursor = textCursor()
			setCursorSelection(cursor, pos, length, units)
		
			Return cursor.selectedText()
		Else
			Return toPlainText()
		End If
	
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
	
	' this is the client widget for ALL pages.
	' Its parent is always the current tab view - i.e. when the page changes this is reparented.
	Field clientWidget:QWidget
	
	' each page widget contains a layout onto which the clientWidget is placed.
	' This causes the clientWidget to auto-fill the space.
	' When a page is removed, the page widget must be freed, etc.
	Field pages:QWidget[0]

	Method MCreate:MaxGuiQTabWidget(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super.Create(parent)
		Return Self
	End Method

	Method OnInit()
		clientWidget = New QWidget._Create()

		connect(Self, "currentChanged", Self, "onCurrentChanged")
	End Method

	Method insertListItem(index:Int, text:String, tip:String, icon:QIcon, extra:Object)
		Local page:QWidget = New QWidget._Create(Self)
		
		Local layout:QVBoxLayout = New QVBoxLayout.Create()
		layout.setContentsMargins(0, 0, 0, 0)
		
		page.setLayout(layout)
		
		' add the page to our internal list
		pages = pages[..index] + [page] + pages[index..]
		
		inserttab(index, page, text, icon)
		
		If tip Then
			setTabToolTip(index, tip)
		End If
		
	End Method
	
	Method onCurrentChanged(index:Int)
		' reparent the clientWidget
		clientWidget.setParent(pages[index])
		
		' delete the old layout
		pages[index].deleteLayout()

		' create a new one for our client widget
		Local layout:QVBoxLayout = New QVBoxLayout.Create()
		layout.setContentsMargins(0, 0, 0, 0)
		
		layout.addWidget(clientWidget)
		
		pages[index].setLayout(layout)
		
		PostGuiEvent EVENT_GADGETACTION, gadget, index
	End Method

	Method ClientWidth:Int()
		Return clientWidget.width()
	End Method

	Method ClientHeight:Int()
		Return clientWidget.height()
	End Method

End Type

Type MaxGuiQTreeView Extends QTreeView
Rem
* EVENT_GADGETSELECT | The user has selected a node.
* EVENT_GADGETACTION | The user has double-clicked a node.
* EVENT_GADGETMENU | The user has right-clicked somewhere in the TreeView.
End Rem

	Field gadget:TQtGadget
	Field model:QStandardItemModel
	Field selectionModel:QItemSelectionModel

	Method MCreate:MaxGuiQTreeView(parent:QWidget, owner:TQtGadget)
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
		
		' hide the header bar of the treeview
		setHeaderHidden(True)
		
		connect(Self, "expanded", Self, "onExpanded")
		connect(Self, "collapsed", Self, "onCollapsed")
	End Method

	Method insertNode(node:TQtTreeViewNode)
'DebugStop
		' insert row in parent, at index (style)
		Local parent:QModelIndex = model.indexFromItem(TQtTreeViewNode(node.parent).item)
		model.insertRows(node.style, 1, parent)
		
		' if we appended, then get the last row from the parent
		' we need this to get our new node's index in the model
		If node.style < 0 Then
			node.style = TQtTreeViewNode(node.parent).item.rowCount() - 1
		End If
		
		Local nodeIndex:QModelIndex = model.index(node.style, 0, parent)
		
		' get item at index, and set in gadget
		node.item = model.itemFromIndex(nodeIndex)
		' a way to get our node from the item
		node.item.setData(node)
	End Method
	
	Method setItemText(item:QStandardItem, text:String)
		Local index:QModelIndex = model.indexFromItem(item)
		model.setData(index, text)
	End Method

	Method onExpanded(index:QModelIndex)
		Local item:QStandardItem = model.itemFromIndex(index)
		PostGuiEvent EVENT_GADGETOPEN, gadget,,,,, item.data()
	End Method

	Method onCollapsed(index:QModelIndex)
		Local item:QStandardItem = model.itemFromIndex(index)
		PostGuiEvent EVENT_GADGETCLOSE, gadget,,,,, item.data()
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

Type MaxGuiQMenuAction Extends QAction

	Field gadget:TQtGadget

	Method MCreate:MaxGuiQMenuAction(parent:QObject, owner:TQtGadget)
		gadget = owner
		Super.Create("", parent)
		Return Self
	End Method

	Method OnInit()

		' if the parent is a window, we need to talk to the menubar
		If TQtWindow(gadget.parent) Then
			' assign a menu to this action because it is a root menu action which sits on the menubar
			gadget.widget = New QMenu.Create()
			QMenu.setMenuForAction(Self, QMenu(gadget.widget))
			
			' add us to the menubar
			MaxGuiQMainWindow(TQtWindow(gadget.parent).widget).menuBar.addAction(Self)
		Else

			If TQtMenuItem(gadget.parent) Then
				' if the parent action doesn't have a menu yet (because it has not children)
				' then we need to assign one to it.	
				If Not TQtMenuItem(gadget.parent).widget Then
					TQtMenuItem(gadget.parent).widget = New QMenu.Create()
					
					' assign menu to action
					QMenu.setMenuForAction(Self, QMenu(TQtMenuItem(gadget.parent).widget))
				End If
	
				' add this action to the parent menu
				QMenu(TQtMenuItem(gadget.parent).widget).addAction(Self)
			Else
				' no parent, so we are the root menu item, perhaps for a popup.
				
			End If

		End If

		connect(Self, "triggered", Self, "onTriggered")

	End Method
	
	Method onTriggered(checked:Int)
		PostGuiEvent EVENT_MENUACTION, gadget, gadget.style ' style is the menu id (really!)
	End Method
	
End Type

Type MaxGuiCanvasWidget Extends QWidget

	Field gadget:TQtGadget

	Method MCreate:MaxGuiCanvasWidget(parent:QWidget, owner:TQtGadget)
		gadget = owner
		Super._Create(parent)
		Return Self
	End Method

	Method OnInit()
		setMouseTracking(True)
	End Method

	Method paintEvent(event:QPaintEvent)
		PostGuiEvent EVENT_GADGETPAINT, gadget
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		PostGuiEvent EVENT_MOUSEMOVE, gadget, event.button(), , event.x(), event.y()
	End Method

	Method paintEngine:Byte Ptr()
		' no widget double buffering

		Return Null

	End Method

	
End Type
