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

Module Qt.QMenuBar

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QMenuBar Extends QWidget

	Function CreateMenuBar:QMenuBar(parent:QWidget = Null)
		Return New QMenuBar.Create(parent)
	End Function
	
	Method Create:QMenuBar(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qmenubar_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qmenubar_create(Self, Null)
		End If
		Return Self
	End Method

	Function __create:QMenuBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QMenuBar = New QMenuBar
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QMenuBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QMenuBar = QMenuBar(qfind(qObjectPtr))
			If Not widget Then
				Return QMenuBar.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Method activeAction:QAction()
		Return QAction._find(bmx_qt_qmenubar_activeaction(qObjectPtr))
	End Method
	
	Method addAction:QAction(action:Object)
		If QAction(action) Then
			Return QAction._find(bmx_qt_qmenubar_adaction(qObjectPtr, QAction(action).qObjectPtr))
		Else If String(action) Then
			Return QAction._find(bmx_qt_qmenubar_adactiontxt(qObjectPtr, String(action)))
		End If
	End Method
	
	Method addMenuAction:QAction(menu:QMenu)
		Return QAction._find(bmx_qt_qmenubar_addmenu(qObjectPtr, menu.qObjectPtr))
	End Method

	Method addMenu:QMenu(menu:String)
		Return QMenu._find(bmx_qt_qmenubar_addmenutxt(qObjectPtr, String(menu)))
	End Method
	
	Method addSeparator:QAction()
		Return QAction._find(bmx_qt_qmenubar_addseparator(qObjectPtr))
	End Method
	
	Method clear()
		bmx_qt_qmenubar_clear(qObjectPtr)
	End Method
	
	Method insertMenu:QAction(before:QAction, menu:QMenu)
		Return QAction._find(bmx_qt_qmenubar_insertmenu(qObjectPtr, before.qObjectPtr, menu.qObjectPtr))
	End Method
	
	Method insertSeparator:QAction(before:QAction)
		Return QAction._find(bmx_qt_qmenubar_insertSeparator(qObjectPtr, before.qObjectPtr))
	End Method
	
	Method isDefaultUp:Int()
		Return bmx_qt_qmenubar_isdefaultup(qObjectPtr)
	End Method
	
	Method setActiveAction(act:QAction)
		bmx_qt_qmenubar_setactiveaction(qObjectPtr, act.qObjectPtr)
	End Method
	
	Method setDefaultUp(value:Int)
		bmx_qt_qmenubar_setdefaultup(qObjectPtr, value)
	End Method


End Type

