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

	Method autoExclusive:Int()
	End Method
	
	Method autoRepeat:Int()
	End Method
	
	Method autoRepeatDelay:Int()
	End Method
	
	Method autoRepeatInterval:Int()
	End Method
	
	Method group:QButtonGroup()
	End Method
	
	'Method icon:QIcon()
	'End Method
	
	Method iconSize(w:Int Ptr, h:Int Ptr)
	End Method
	
	Method isCheckable:Int()
	End Method
	
	Method isChecked:Int()
	End Method
	
	Method isDown:Int()
	End Method
	
	Method setAutoExclusive(value:Int)
	End Method
	
	Method setAutoRepeat(value:Int)
	End Method
	
	Method setAutoRepeatDelay(value:Int)
	End Method
	
	Method setAutoRepeatInterval(value:Int)
	End Method
	
	Method setCheckable(value:Int)
	End Method
	
	Method setDown(value:Int)
	End Method

	Method setIcon(icon:QIcon)
	' TODO
	End Method
	
	'Method setShortcut(key:QKeySequence)
	' TODO
	'End Method
	
	Method setText(text:String)
	' TODO
	End Method
	
	'Method shortcut:QKeySequence()
	' TODO
	'End Method
	
	Method text:String()
	' TODO
	End Method
	
	Method animateClick(msec:Int = 100)
	' TODO
	End Method
	
	Method click()
	' TODO
	End Method
	
	Method setChecked(value:Int)
	' TODO
	End Method
	
	Method setIconSize(w:Int, h:Int)
	' TODO
	End Method
	
	Method toggle()
	' TODO
	End Method
	
End Type


Type QButtonGroup Extends QObject

	Function CreateButtonGroup:QButtonGroup(parent:QObject = Null)
		Return New QButtonGroup.Create(parent)
	End Function
	
	Method Create:QButtonGroup(parent:QObject = Null)
		
		Return Self
	End Method
	
	Method addButton(button:QAbstractButton, id:Int)
	End Method
	
	Method button:QAbstractButton(id:Int)
	End Method
	
	Method checkedButton:QAbstractButton()
	End Method
	
	Method checkedId:Int()
	End Method
	
	Method exclusive:Int()
	End Method
	
	Method id:Int(button:QAbstractButton)
	End Method
	
	Method removeButton(button:QAbstractButton)
	End Method
	
	Method setExclusive(value:Int)
	End Method
	
	Method setId(button:QAbstractButton, id:Int)
	End Method

End Type
