' Copyright (c) 2009-2013 Bruce A Henderson
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

Module Qt.QDialogButtonBox

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QDialogButtonBox Extends QWidget

	Rem
	bbdoc: Use a policy appropriate for applications on Windows.
	end rem
	Const WinLayout:Int = 0
	Rem
	bbdoc: Use a policy appropriate for applications on Mac OS X.
	end rem
	Const MacLayout:Int = 1
	Rem
	bbdoc: Use a policy appropriate for applications on KDE.
	end rem
	Const KdeLayout:Int = 2
	Rem
	bbdoc: Use a policy appropriate for applications on GNOME.
	end rem
	Const GnomeLayout:Int = 3
	Rem
	bbdoc: The button is invalid.
	end rem
	Const InvalidRole:Int = -1
	Rem
	bbdoc: Clicking the button causes the dialog to be accepted (e.g. OK).
	end rem
	Const AcceptRole:Int = 0
	Rem
	bbdoc: Clicking the button causes the dialog to be rejected (e.g. Cancel).
	end rem
	Const RejectRole:Int = 1
	Rem
	bbdoc: Clicking the button causes a destructive change (e.g. for Discarding Changes) and closes the dialog.
	end rem
	Const DestructiveRole:Int = 2
	Rem
	bbdoc: Clicking the button causes changes to the elements within the dialog.
	end rem
	Const ActionRole:Int = 3
	Rem
	bbdoc: The button can be clicked to request help.
	end rem
	Const HelpRole:Int = 4
	Rem
	bbdoc: The button is a "Yes"-like button.
	end rem
	Const YesRole:Int = 5
	Rem
	bbdoc: The button is a "No"-like button.
	end rem
	Const NoRole:Int = 6
	Rem
	bbdoc: The button applies current changes.
	end rem
	Const ApplyRole:Int = 8
	Rem
	bbdoc: The button resets the dialog's fields to default values.
	end rem
	Const ResetRole:Int = 7
	Rem
	bbdoc: An "OK" button defined with the AcceptRole.
	end rem
	Const Button_Ok:Int = $00000400
	Rem
	bbdoc: A "Open" button defined with the AcceptRole.
	end rem
	Const Button_Open:Int = $00002000
	Rem
	bbdoc: A "Save" button defined with the AcceptRole.
	end rem
	Const Button_Save:Int = $00000800
	Rem
	bbdoc: A "Cancel" button defined with the RejectRole.
	end rem
	Const Button_Cancel:Int = $00400000
	Rem
	bbdoc: A "Close" button defined with the RejectRole.
	end rem
	Const Button_Close:Int = $00200000
	Rem
	bbdoc: A "Discard" or "Don't Save" button, depending on the platform, defined with the DestructiveRole.
	end rem
	Const Button_Discard:Int = $00800000
	Rem
	bbdoc: An "Apply" button defined with the ApplyRole.
	end rem
	Const Button_Apply:Int = $02000000
	Rem
	bbdoc: A "Reset" button defined with the ResetRole.
	end rem
	Const Button_Reset:Int = $04000000
	Rem
	bbdoc: A "Restore Defaults" button defined with the ResetRole.
	end rem
	Const Button_RestoreDefaults:Int = $08000000
	Rem
	bbdoc: A "Help" button defined with the HelpRole.
	end rem
	Const Button_Help:Int = $01000000
	Rem
	bbdoc: A "Save All" button defined with the AcceptRole.
	end rem
	Const Button_SaveAll:Int = $00001000
	Rem
	bbdoc: A "Yes" button defined with the YesRole.
	end rem
	Const Button_Yes:Int = $00004000
	Rem
	bbdoc: A "Yes to All" button defined with the YesRole.
	end rem
	Const Button_YesToAll:Int = $00008000
	Rem
	bbdoc: A "No" button defined with the NoRole.
	end rem
	Const Button_No:Int = $00010000
	Rem
	bbdoc: A "No to All" button defined with the NoRole.
	end rem
	Const Button_NoToAll:Int = $00020000
	Rem
	bbdoc: An "Abort" button defined with the RejectRole.
	end rem
	Const Button_Abort:Int = $00040000
	Rem
	bbdoc: A "Retry" button defined with the AcceptRole.
	end rem
	Const Button_Retry:Int = $00080000
	Rem
	bbdoc: An "Ignore" button defined with the AcceptRole.
	end rem
	Const Button_Ignore:Int = $00100000
	Rem
	bbdoc: An invalid button.
	end rem
	Const Button_NoButton:Int = $00000000
	
	Function CreateDialogButtonBox:QDialogButtonBox(orientation:Int, parent:QWidget = Null)
		Return New QDialogButtonBox.Create(orientation, parent)
	End Function

	Method Create:QDialogButtonBox(orientation:Int, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qdialogbuttonbox_create(Self, orientation, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qdialogbuttonbox_create(Self, orientation, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method addButton(button:QAbstractButton, role:Int)
		bmx_qt_qdialogbuttonbox_addbutton(qObjectPtr, button.qObjectPtr, role)
	End Method
	

End Type


