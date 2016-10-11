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

Module Qt.QToolButton

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QToolButton Extends QAbstractButton

	Function CreateToolButton:QToolButton(parent:QWidget = Null)
		Return New QToolButton.Create(parent)
	End Function
	
	Method Create:QToolButton(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qtoolbutton_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qtoolbutton_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method arrowType:Int()
		Return bmx_qt_qtoolbutton_arrowtype(qObjectPtr)
	End Method
	
	Method autoRaise:Int()
		Return bmx_qt_qtoolbutton_autoraise(qObjectPtr)
	End Method
	
	Method defaultAction:QAction()
		Return QAction._find(bmx_qt_qtoolbutton_defaultaction(qObjectPtr))
	End Method
	
	Method menu:QMenu()
		Return QMenu._find(bmx_qt_qtoolbutton_menu(qObjectPtr))
	End Method
	
	Method popupMode:Int()
		Return bmx_qt_qtoolbutton_popupmode(qObjectPtr)
	End Method
	
	Method setArrowType(arrow:Int)
		bmx_qt_qtoolbutton_setarrowtype(qObjectPtr, arrow)
	End Method
	
	Method setAutoRaise(enable:Int)
		bmx_qt_qtoolbutton_setautoraise(qObjectPtr, enable)
	End Method
	
	Method setMenu(menu:QMenu)
		bmx_qt_qtoolbutton_setmenu(qObjectPtr, menu.qObjectPtr)
	End Method
	
	Method setPopupMode(_mode:Int)
		bmx_qt_qtoolbutton_setpopupmode(qObjectPtr, _mode)
	End Method
	
	Method toolButtonStyle:Int()
		Return bmx_qt_qtoolbutton_toolbuttonstyle(qObjectPtr)
	End Method
	
	Method setDefaultAction(action:QACtion)
		bmx_qt_qtoolbutton_setdefaultaction(qObjectPtr, action.qObjectPtr)
	End Method
	
	Method setToolButtonStyle(style:Int)
		bmx_qt_qtoolbutton_settoolbuttonstyle(qObjectPtr, style)
	End Method
	
	Method showMenu()
		bmx_qt_qtoolbutton_showmenu(qObjectPtr)
	End Method


End Type
