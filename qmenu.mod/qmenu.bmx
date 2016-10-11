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

Module Qt.QMenu

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QMenu Extends QWidget

	Function __create:QMenu(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QMenu = New QMenu
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QMenu(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QMenu = QMenu(qfind(qObjectPtr))
			If Not widget Then
				Return QMenu.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function
	
	Function CreateMenu:QMenu(parent:QWidget = Null)
		Return New QMenu.Create(parent)
	End Function
	
	Method Create:QMenu(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qmenu_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qmenu_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method CreateWithTitle:QMenu(title:String, parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qmenu_createwithtitle(Self, title, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qmenu_createwithtitle(Self, title, Null)
		End If
		OnInit()
		Return Self
	End Method


	Method actionAt:QAction(x:Int, y:Int)
		Return QAction._find(bmx_qt_qmenu_actionat(qObjectPtr, x, y))
	End Method
	
	Method actionGeometry:QRect(act:QAction)
		Return QRect._create(bmx_qt_qmenu_actiongeometry(qObjectPtr, act.qObjectPtr))
	End Method
	
	Method activeAction:QAction()
		Return QAction._find(bmx_qt_qmenu_activeaction(qObjectPtr))
	End Method
	
	Method addAction:QAction(action:Object)
		If QAction(action) Then
			bmx_qt_qmenu_addaction(qObjectPtr, QAction(action).qObjectPtr)
			Return QAction(action)
		ElseIf String(action) Then
			Return QAction._find(bmx_qt_qmenu_addactiontxt(qObjectPtr, String(action)))
		End If
	End Method
	
	Method addActionConnect:QAction(text:String, receiver:QObject, slot:String)
		Local action:QAction = addAction(text)
		connect(action, "triggered", receiver, slot)
		Return action
	End Method
	
	Method addMenuAction:QAction(menu:QMenu)
		Return QAction._find(bmx_qt_qmenu_addmenuaction(qObjectPtr, menu.qObjectPtr))
	End Method
	
	Method addMenu:QMenu(title:String)
		Return QMenu._find(bmx_qt_qmenu_addmenu(qObjectPtr, title))
	End Method
	
	Method addSeparator:QAction()
		Return QAction._find(bmx_qt_qmenu_addseparator(qObjectPtr))
	End Method
	
	Method clear()
		bmx_qt_qmenu_clear(qObjectPtr)
	End Method
	
	Method defaultAction:QAction()
		Return QAction._find(bmx_qt_qmenu_defaultaction(qObjectPtr))
	End Method
	
	Method exec:QAction()
		Return QAction._find(bmx_qt_qmenu_exec(qObjectPtr))
	End Method
	
	Method execAction:QAction(x:Int, y:Int, action:QAction = Null)
		If action Then
			Return QAction._find(bmx_qt_qmenu_execaction(qObjectPtr, x, y, action.qObjectPtr))
		Else
			Return QAction._find(bmx_qt_qmenu_execaction(qObjectPtr, x, y, Null))
		End If
	End Method
	
	Method hideTearOffMenu()
		bmx_qt_qmenu_hidetearoffmenu(qObjectPtr)
	End Method
	
	Method icon:QIcon()
		' TODO
		'Return QIcon._create(bmx_qt_qmenu_icon(qObjectPtr))
	End Method
	
	Method insertMenu:QAction(before:QAction, menu:QMenu)
		Return QAction._find(bmx_qt_qmenu_insertmenu(qObjectPtr, before.qObjectPtr, menu.qObjectPtr))
	End Method
	
	Method insertSeparator:QAction(before:QAction)
		Return QAction._find(bmx_qt_qmenu_insertseparator(qObjectPtr, before.qObjectPtr))
	End Method
	
	Method isEmpty:Int()
		Return bmx_qt_qmenu_isempty(qObjectPtr)
	End Method
	
	Method isTearOffEnabled:Int()
		Return bmx_qt_qmenu_istearoffenabled(qObjectPtr)
	End Method
	
	Method isTearOffMenuVisible:Int()
		Return bmx_qt_qmenu_istearoffmenuvisible(qObjectPtr)
	End Method
	
	Method menuAction:QAction()
		Return QAction._find(bmx_qt_qmenu_menuaction(qObjectPtr))
	End Method
	
	Method popup(x:Int, y:Int, atAction:QAction = Null)
		If atAction Then
			bmx_qt_qmenu_popup(qObjectPtr, x, y, atAction.qObjectPtr)
		Else
			bmx_qt_qmenu_popup(qObjectPtr, x, y, Null)
		End If
	End Method
	
	Method separatorsCollapsible:Int()
		Return bmx_qt_qmenu_separatorscollapsible(qObjectPtr)
	End Method
	
	Method setActiveAction(act:QAction)
		bmx_qt_qmenu_setactiveaction(qObjectPtr, act.qObjectPtr)
	End Method
	
	Method setDefaultAction(act:QAction)
		bmx_qt_qmenu_setdefaultaction(qObjectPtr, act.qObjectPtr)
	End Method
	
	Method setIcon(icon:QIcon)
		' TODO
		'bmx_qt_qmenu_seticon(qObjectPtr, icon.qObjectPtr)
	End Method
	
	Method setSeparatorsCollapsible(collapse:Int)
		bmx_qt_qmenu_setseparatorscollapsible(qObjectPtr, collapse)
	End Method
	
	Method setTearOffEnabled(value:Int)
		bmx_qt_qmenu_settearoffenabled(qObjectPtr, value)
	End Method
	
	Method setTitle(title:String)
		bmx_qt_qmenu_settitle(qObjectPtr, title)
	End Method
	
	Method title:String()
		Return bmx_qt_qmenu_title(qObjectPtr)
	End Method

	Rem
	bbdoc: Returns the menu contained by the action.
	about: Actions that contain menus can be used to create menu items with submenus, or inserted into toolbars to create buttons
	with popup menus.
	<p>
	Note : This should really be a Method on QAction, but because of reference issues with BlitzMax, it is here as a Function instead.
	</p>
	End Rem
	Function menuForAction:QMenu(action:QAction)
		Return QMenu._find(bmx_qt_qaction_menu(action.qObjectPtr))
	End Function
	
	Rem
	bbdoc: Sets the menu contained by the action to the specified @menu.
	about: Note : This should really be a Method on QAction, but because of reference issues with BlitzMax, it is here as a Function instead.
	End Rem
	Function setMenuForAction(action:QAction, menu:QMenu)
		bmx_qt_qaction_setmenu(action.qObjectPtr, menu.qObjectPtr)
	End Function


	' SIGNAL : aboutToHide
	Function _OnAboutToHide(obj:QMenu)
		obj._InvokeSignals("aboutToHide", Null)
	End Function

	' SIGNAL : aboutToShow
	Function _OnAboutToShow(obj:QMenu)
		obj._InvokeSignals("aboutToShow", Null)
	End Function

	' SIGNAL : hovered
	Function _OnHovered(obj:QMenu, action:Byte Ptr)
		obj._InvokeSignals("hovered", [QAction._find(action)])
	End Function

	' SIGNAL : triggered
	Function _OnTriggered(obj:QMenu, action:Byte Ptr)
		obj._InvokeSignals("triggered", [QAction._find(action)])
	End Function

	Method Free()
		Super.Free()
		If qObjectPtr Then
			bmx_qt_qmenu_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
End Type

