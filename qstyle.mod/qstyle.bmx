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

Module Qt.QStyle

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QStyle Extends QObject

	Rem
	bbdoc: Indicates that the widget does not have a state.
	end rem
	Const State_None:Int = $00000000
	Rem
	bbdoc: Indicates that the widget is active.
	end rem
	Const State_Active:Int = $00010000
	Rem
	bbdoc: Used to indicate if auto-raise appearance should be usd on a tool button.
	end rem
	Const State_AutoRaise:Int = $00001000
	Rem
	bbdoc: Used to indicate if an item view branch has children.
	end rem
	Const State_Children:Int = $00080000
	Rem
	bbdoc: Used to indicate if a down arrow should be visible on the widget.
	end rem
	Const State_DownArrow:Int = $00000040
	Rem
	bbdoc: Used to indicate if an editor is opened on the widget.
	end rem
	Const State_Editing:Int = $00400000
	Rem
	bbdoc: Used to indicate if the widget is enabled.
	end rem
	Const State_Enabled:Int = $00000001
	Rem
	bbdoc: Used to indicate if the widget currently has edit focus.
	end rem
	Const State_HasEditFocus:Int = $01000000
	Rem
	bbdoc: Used to indicate if the widget has focus.
	end rem
	Const State_HasFocus:Int = $00000100
	Rem
	bbdoc: Used to indicate if the widget is laid out horizontally, for example. a tool bar.
	end rem
	Const State_Horizontal:Int = $00000080
	Rem
	bbdoc: Used to indicate if the focus was changed with the keyboard, e.g., tab, backtab or shortcut.
	end rem
	Const State_KeyboardFocusChange:Int = $00800000
	Rem
	bbdoc: Used to indicate if the widget is under the mouse.
	end rem
	Const State_MouseOver:Int = $00002000
	Rem
	bbdoc: Used to indicate a tri-state checkbox.
	end rem
	Const State_NoChange:Int = $00000010
	Rem
	bbdoc: Used to indicate if the widget is not checked.
	end rem
	Const State_Off:Int = $00000008
	Rem
	bbdoc: Used to indicate if the widget is checked.
	end rem
	Const State_On:Int = $00000020
	Rem
	bbdoc: Used to indicate if a button is raised.
	end rem
	Const State_Raised:Int = $00000002
	Rem
	bbdoc: Used to indicate if a widget is read-only.
	end rem
	Const State_ReadOnly:Int = $02000000
	Rem
	bbdoc: Used to indicate if a widget is selected.
	end rem
	Const State_Selected:Int = $00008000
	Rem
	bbdoc: Used by item views to indicate if a horizontal branch should be drawn.
	end rem
	Const State_Item:Int = $00100000
	Rem
	bbdoc: Used by item views to indicate if the tree branch is open.
	end rem
	Const State_Open:Int = $00040000
	Rem
	bbdoc: Used by item views to indicate if a vertical line needs to be drawn (for siblings).
	end rem
	Const State_Sibling:Int = $00200000
	Rem
	bbdoc: Used to indicate if the widget is sunken or pressed.
	end rem
	Const State_Sunken:Int = $00000004
	Rem
	bbdoc: Used to indicate if an up arrow should be visible on the widget.
	end rem
	Const State_UpArrow:Int = $00004000
	Rem
	bbdoc: Used to indicate a mini style Mac widget or button.
	end rem
	Const State_Mini:Int = $08000000
	Rem
	bbdoc: Used to indicate a small style Mac widget or button.
	end rem
	Const State_Small:Int = $04000000

	
End Type


