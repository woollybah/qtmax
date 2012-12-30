' Copyright (c) 2012 Bruce A Henderson
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
Import "qtgadget.bmx"


Global QtDriver:TQtGUIDriver =New TQtGUIDriver

Type TQtGuiSystemDriver Extends TQtSystemDriver
	Field gui:TQtGUIDriver

?linux
	Field notifier:MaxQSocketNotifier
?

	Method Poll()
		gui.app.processEvents()
		DispatchGuiEvents()
	End Method
		
	Method Wait()
		Poll()
?linux
		gui.app.processEvents(QEventLoop.WaitForMoreEvents)
?Not Linux
		Super.Wait()
?
	End Method
			
	Function Create:TQtGuiSystemDriver(host:TQtGUIDriver)
		Local guisystem:TQtGuiSystemDriver		
		guisystem=New TQtGuiSystemDriver
		guisystem.gui=host
?linux
		guisystem.notifier = New MaxQSocketNotifier.Create(bbSystemAsyncFD(), QSocketNotifier.Type_Read)
?
		Return guisystem
	End Function
	
End Type

Type TQtSystemDriver Extends TSystemDriver

	Field NativeDriver:TSystemDriver

	Method New()
		NativeDriver=brl.System.Driver
	End Method
	
	Method Poll()
		NativeDriver.Poll()
	End Method
		
	Method Wait()
		NativeDriver.Wait()
	End Method
	
	Method Emit( osevent:Byte Ptr,source:Object )
		Throw "oops"
	End Method

	Method IsFullScreen:Int()
		Return False
	End Method	

	Method SetMouseVisible(bool:Int)
		NativeDriver.SetMouseVisible bool
	End Method

	Method MoveMouse( x:Int, y:Int )
		NativeDriver.MoveMouse x,y
	End Method

	Method Notify( text:String, serious:Int )
		Local msgBox:QMessageBox = New QMessageBox.Create()
		msgBox.setText(text)

		If serious Then
			msgBox.setIcon(QMessageBox.Icon_Critical)
		End If
		
		msgBox.exec()
		msgBox.free()
	End Method
	
	Method Confirm:Int( text:String, serious:Int )
		Local msgBox:QMessageBox = New QMessageBox.Create()
		msgBox.setText(text)
		msgBox.setStandardButtons(QMessageBox.Button_Ok | QMessageBox.Button_Cancel)
	
		If serious Then
			msgBox.setIcon(QMessageBox.Icon_Critical)
		Else
			msgBox.setIcon(QMessageBox.Icon_Information)
		End If
		
		Local ret:Int = msgBox.exec()
		
		msgBox.free()
		
		Select ret
			Case QMessageBox.Button_Ok
				Return 1
			Case QMessageBox.Button_Cancel
				Return 0
		End Select		
	End Method

	Method Proceed:Int( text:String, serious:Int )
		Local msgBox:QMessageBox = New QMessageBox.Create()
		msgBox.setText(text)
		msgBox.setStandardButtons(QMessageBox.Button_Yes | QMessageBox.Button_No | QMessageBox.Button_Cancel)

		If serious Then
			msgBox.setIcon(QMessageBox.Icon_Critical)
		Else
			msgBox.setIcon(QMessageBox.Icon_Information)
		End If
		
		Local ret:Int = msgBox.exec()
		
		msgBox.free()
		
		Select ret
			Case QMessageBox.Button_Yes
				Return 1
			Case QMessageBox.Button_No
				Return 0
		End Select
		
		' otherwise we cancelled
		Return -1
	End Method
	
	Method RequestFile:String( text:String,exts:String, Save:Int,file:String )
		DebugLog "TODO : TQtSystemDriver::RequestFile"
	End Method
	
	Method RequestDir:String( text:String, path:String )
		DebugLog "TODO : TQtSystemDriver::RequestDir"
	End Method

	Method OpenURL:Int( url:String )
		Return NativeDriver.OpenURL(url)
	End Method

End Type


Type TQtGUIDriver Extends TMaxGUIDriver

	Field app:QApplication

	Method New()
		app = New QApplication.Create()
	
		brl.System.Driver = TQtGuiSystemDriver.Create(Self)

		maxgui_driver=Self
		
		
		AddHook EmitEventHook, eventHandler, Null, True
	End Method

	Method LoadFont:TGuiFont(name:String, size:Int, flags:Int)
		DebugLog "TODO : TQtGUIDriver::LoadFont"
	End Method
	
	Method DoLoadFont:TGuiFont(font:TGuiFont)
		DebugLog "TODO : TQtGUIDriver::DoLoadFont"
	End Method
	
	Method CreateGadget:TGadget(GadgetClass:Int, name:String, x:Int, y:Int, w:Int, h:Int,group:TGadget, style:Int)
		Local gadget:TQtGadget
		Local gtkclass:Int = -1
		Local gtkGroup:TQtGadget

		Select GadgetClass
			Case GADGET_DESKTOP
				Return New TQtDesktop.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_WINDOW
				Return New TQtWindow.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_BUTTON
				Select style & 7
					Case 0, BUTTON_OK, BUTTON_CANCEL
						Return New TQtPushButton.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
					Case BUTTON_CHECKBOX
						If style & BUTTON_PUSH Then
							Return New TQtPushButton.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
						Else
							Return New TQtCheckboxButton.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
						End If
					Case BUTTON_RADIO
						If style & BUTTON_PUSH Then
							Return New TQtPushButton.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
						Else
							Return New TQtRadioButton.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
						End If
				End Select
			Case GADGET_PANEL
				Select style & (PANEL_GROUP|PANEL_SUNKEN|PANEL_RAISED)
					Case PANEL_GROUP
						Return New TQtGroupBox.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
					Default
						Return New TQtPanel.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
				End Select
'				If style & PANEL_GROUP Then
'				Else
'				End If
			Case GADGET_TEXTFIELD
				Return New TQtTextField.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_TEXTAREA
				Return New TQtTextArea.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_COMBOBOX
				Return New TQtComboBox.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_LISTBOX
				Return New TQtListBox.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_TOOLBAR
				Return New TQtToolBar.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_TABBER
				Return New TQtTabber.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_TREEVIEW
				Return New TQtTreeView.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_HTMLVIEW
				Return New TQtHtmlView.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_LABEL
				Return New TQtLabel.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_SLIDER
				If style & SLIDER_STEPPER Then
					Return New TQtStepper.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
				Else If style & SLIDER_TRACKBAR Then
					Return New TQtTrackBar.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
				Else
					Return New TQtScrollBar.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
				End If
			Case GADGET_PROGBAR
				Return New TQtProgressBar.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_MENUITEM
				Return New TQtMenuItem.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
			Case GADGET_CANVAS
				Return New TQtCanvas.CreateGadget(name, x, y, w, h, TQtGadget(group), style)
		End Select

	End Method
	
	Function eventHandler:Object(id:Int, data:Object, context:Object )
		'DebugLog "event : " + event.id + " : " + EVENT_WINDOWSIZE
		
		Local event:TEvent = TEvent(data)
		Local gadget:TQtGadget = TQtGadget(event.source)
		
		If gadget Then
			Select event.id
				Case EVENT_WINDOWSIZE
'DebugLog "EVENT_WINDOWSIZE"
					If gadget.width <> event.x Or gadget.height <> event.y Then
'DebugLog "Need layout"
'DebugStop
						gadget.SetRect gadget.xpos,gadget.ypos,event.x,event.y
						gadget.LayoutKids
					Else
						Return data
					EndIf
			End Select
		End If
		
		Return data
	End Function

	Method ActiveGadget:TGadget()
		DebugLog "TODO : TQtGUIDriver::ActiveGadget"
	End Method
	
	Method RequestColor:Int(r:Int, g:Int, b:Int)
		Local rc:Int, gc:Int, bc:Int
		Local color:QColor = QColorDialog.GetColor(New QColor.Create(r, g, b))
		
		If color.isValid()
			color.getRgb(rc, gc, bc)
			Return $ff000000 | (rc Shl 16) | (gc Shl 8) | bc
		End If
		
		Return 0
	End Method
	
	Method RequestFont:TGuiFont(font:TGuiFont)
		DebugLog "TODO : TQtGUIDriver::RequestFont"
	End Method
	
	Method SetPointer(shape:Int)
		' undo the last change
		QApplication.restoreOverrideCursor()
		
		Local cursor:Int
		Select shape
			Case POINTER_DEFAULT
				' just return to the standard cursor
				Return
			Case POINTER_ARROW
				cursor = Qt_ArrowCursor
			Case POINTER_IBEAM
				cursor = Qt_IBeamCursor
			Case POINTER_WAIT
				cursor = Qt_WaitCursor
			Case POINTER_CROSS
				cursor = Qt_CrossCursor
			Case POINTER_UPARROW
				cursor = Qt_UpArrowCursor
			Case POINTER_SIZENWSE
				cursor = Qt_SizeFDiagCursor
			Case POINTER_SIZENESW
				cursor = Qt_SizeBDiagCursor
			Case POINTER_SIZEWE
				cursor = Qt_SizeHorCursor
			Case POINTER_SIZENS
				cursor = Qt_SizeVerCursor
			Case POINTER_SIZEALL
				cursor = Qt_SizeAllCursor
			Case POINTER_NO
				cursor = Qt_ForbiddenCursor
			Case POINTER_HAND
				cursor = Qt_OpenHandCursor
			Case POINTER_APPSTARTING
				cursor = Qt_BusyCursor
			Case POINTER_HELP
				cursor = Qt_WhatsThisCursor
		End Select
		
		QApplication.setOverrideCursor(New QCursor.Create(cursor))
	End Method
	
	Method LoadIconStrip:TIconStrip(source:Object)
		Return TQtIconStrip.Create(source)
	End Method
	
	Method UserName:String()
	End Method
	
	Method ComputerName:String()
	End Method

End Type

?linux
Type MaxQSocketNotifier Extends QSocketNotifier

	Method Create:MaxQSocketNotifier(socket:Int, sType:Int, parent:QObject = Null)
		Return MaxQSocketNotifier(Super.Create(socket, sType, parent))
	End Method

	Method OnInit()
		connect(Self, "activated", Self, "onActivated")
	End Method
	
	Method onActivated(socket:Int)
		bbSystemFlushAsyncOps
	End Method

End Type
?
