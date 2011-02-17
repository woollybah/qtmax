' Copyright (c) 2009 Bruce A Henderson
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

Module Qt.QAbstractButton

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QAbstractButton Extends QWidget

	Function __create:QAbstractButton(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QAbstractButton = New QAbstractButton
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QAbstractButton(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QAbstractButton = QAbstractButton(qfind(qObjectPtr))
			If Not widget Then
				Return QAbstractButton.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Method autoExclusive:Int()
		Return bmx_qt_qabstractbutton_autoexclusive(qObjectPtr)
	End Method
	
	Method autoRepeat:Int()
		Return bmx_qt_qabstractbutton_autorepeat(qObjectPtr)
	End Method
	
	Method autoRepeatDelay:Int()
		Return bmx_qt_qabstractbutton_autorepeatdelay(qObjectPtr)
	End Method
	
	Method autoRepeatInterval:Int()
		Return bmx_qt_qabstractbutton_autorepeatinterval(qObjectPtr)
	End Method
	
	Method group:QButtonGroup()
		Return QButtonGroup._create(bmx_qt_qabstractbutton_group(qObjectPtr))
	End Method
	
	Method icon:QIcon()
		Return QIcon._create(bmx_qt_qabstractbutton_icon(qObjectPtr))
	End Method
	
	Method iconSize(w:Int Var, h:Int Var)
		bmx_qt_qabstractbutton_iconsize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method isCheckable:Int()
		Return bmx_qt_qabstractbutton_ischeckable(qObjectPtr)
	End Method
	
	Method isChecked:Int()
		Return bmx_qt_qabstractbutton_ischecked(qObjectPtr)
	End Method
	
	Method isDown:Int()
		Return bmx_qt_qabstractbutton_isdown(qObjectPtr)
	End Method
	
	Method setAutoExclusive(value:Int)
		bmx_qt_qabstractbutton_setautoexclusive(qObjectPtr, value)
	End Method
	
	Method setAutoRepeat(value:Int)
		bmx_qt_qabstractbutton_setautorepeat(qObjectPtr, value)
	End Method
	
	Method setAutoRepeatDelay(value:Int)
		bmx_qt_qabstractbutton_setautorepeatdelay(qObjectPtr, value)
	End Method
	
	Method setAutoRepeatInterval(value:Int)
		bmx_qt_qabstractbutton_setautorepeatinterval(qObjectPtr, value)
	End Method
	
	Method setCheckable(value:Int)
		bmx_qt_qabstractbutton_setcheckable(qObjectPtr, value)
	End Method
	
	Method setDown(value:Int)
		bmx_qt_qabstractbutton_setdown(qObjectPtr, value)
	End Method

	Method setIcon(icon:QIcon)
		bmx_qt_qabstractbutton_seticon(qObjectPtr, icon.qObjectPtr)
	End Method
	
	'Method setShortcut(key:QKeySequence)
	' TODO
	'End Method
	
	Method setText(text:String)
		bmx_qt_qabstractbutton_settext(qObjectPtr, text)
	End Method
	
	'Method shortcut:QKeySequence()
	' TODO
	'End Method
	
	Method text:String()
		Return bmx_qt_qabstractbutton_text(qObjectPtr)
	End Method
	
	Method animateClick(msec:Int = 100)
		bmx_qt_qabstractbutton_animateclick(qObjectPtr, msec)
	End Method
	
	Method click()
		bmx_qt_qabstractbutton_click(qObjectPtr)
	End Method
	
	Method setChecked(value:Int)
		bmx_qt_qabstractbutton_setchecked(qObjectPtr, value)
	End Method
	
	Method setIconSize(w:Int, h:Int)
		bmx_qt_qabstractbutton_seticonsize(qObjectPtr, w, h)
	End Method
	
	Method toggle()
		bmx_qt_qabstractbutton_toggle(qObjectPtr)
	End Method
	
End Type


Type QButtonGroup Extends QObject

	Function _create:QButtonGroup(qObjectPtr:Byte Ptr)
	' TODO
	End Function

	Function CreateButtonGroup:QButtonGroup(parent:QObject = Null)
		Return New QButtonGroup.Create(parent)
	End Function
	
	Method Create:QButtonGroup(parent:QObject = Null)
	' TODO
		Return Self
	End Method
	
	Method addButton(button:QAbstractButton, id:Int = -1)
	' TODO
	End Method
	
	Method button:QAbstractButton(id:Int)
	' TODO
	End Method
	
	Method checkedButton:QAbstractButton()
	' TODO
	End Method
	
	Method checkedId:Int()
	' TODO
	End Method
	
	Method exclusive:Int()
	' TODO
	End Method
	
	Method id:Int(button:QAbstractButton)
	' TODO
	End Method
	
	Method removeButton(button:QAbstractButton)
	' TODO
	End Method
	
	Method setExclusive(value:Int)
	' TODO
	End Method
	
	Method setId(button:QAbstractButton, id:Int)
	' TODO
	End Method

End Type
