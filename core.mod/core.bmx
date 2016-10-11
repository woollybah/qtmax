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

Module Qt.Core

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"

?macos
ModuleInfo "LD_OPTS: -L%PWD%/../lib/macos/"
?win32
ModuleInfo "LD_OPTS: -L%PWD%/../lib/win32/"
?

?macos
Import "-lQtCore.4"
?win32
Import "-lQtCore4"
?linux
Import "-lQtCore"
?


Import "qvariant.bmx"
Import "qrect.bmx"
Import "qrectf.bmx"
Import "qevent.bmx"
Import "qdatetime.bmx"
Import "qlinef.bmx"
Import "common.bmx"

Type QCoreObjectPtr

	Field qObjectPtr:Byte Ptr

	Method isWidget:Int()
		Return False
	End Method
	
End Type

Type QSize

	Function scale(w:Int Var, h:Int Var, scaleW:Int, scaleH:Int, _mode:Int)
		bmx_qt_qsize_scale(Varptr w, Varptr h, scaleW, scaleH, _mode)
	End Function

End Type


Type QItemList

	Field list:TMap = New TMap
	Field lastItemId:Long
	
	Method addItem:Long(data:Object)
		Local id:Long = newItem()
		list.Insert(String(id), data)
		Return id
	End Method
	
	Method itemData:Object(itemId:Long)
		Return list.ValueForKey(String(itemId))
	End Method
	
	Method setItem(id:Long Var, data:Object)
		If Not id Then
			id = newItem()
		End If
		list.Insert(String(id), data)
	End Method
	
	Method removeItem(itemId:Long)
		list.Remove(String(itemId))
	End Method
	
	Method clear()
		list.Clear()
	End Method

	Method newItem:Long()
		lastItemId:+ 1
		Return lastItemId
	End Method

End Type

Type QChar

	Rem
	bbdoc: Unicode class name Mn
	end rem
	Const Mark_NonSpacing:Int = 1
	Rem
	bbdoc: Unicode class name Mc
	end rem
	Const Mark_SpacingCombining:Int = 2
	Rem
	bbdoc: Unicode class name Me
	end rem
	Const Mark_Enclosing:Int = 3
	Rem
	bbdoc: Unicode class name Nd
	end rem
	Const Number_DecimalDigit:Int = 4
	Rem
	bbdoc: Unicode class name Nl
	end rem
	Const Number_Letter:Int = 5
	Rem
	bbdoc: Unicode class name No
	end rem
	Const Number_Other:Int = 6
	Rem
	bbdoc: Unicode class name Zs
	end rem
	Const Separator_Space:Int = 7
	Rem
	bbdoc: Unicode class name Zl
	end rem
	Const Separator_Line:Int = 8
	Rem
	bbdoc: Unicode class name Zp
	end rem
	Const Separator_Paragraph:Int = 9
	Rem
	bbdoc: Unicode class name Cc
	end rem
	Const Other_Control:Int = 10
	Rem
	bbdoc: Unicode class name Cf
	end rem
	Const Other_Format:Int = 11
	Rem
	bbdoc: Unicode class name Cs
	end rem
	Const Other_Surrogate:Int = 12
	Rem
	bbdoc: Unicode class name Co
	end rem
	Const Other_PrivateUse:Int = 13
	Rem
	bbdoc: Unicode class name Cn
	end rem
	Const Other_NotAssigned:Int = 14
	Rem
	bbdoc: Unicode class name Lu
	end rem
	Const Letter_Uppercase:Int = 15
	Rem
	bbdoc: Unicode class name Ll
	end rem
	Const Letter_Lowercase:Int = 16
	Rem
	bbdoc: Unicode class name Lt
	end rem
	Const Letter_Titlecase:Int = 17
	Rem
	bbdoc: Unicode class name Lm
	end rem
	Const Letter_Modifier:Int = 18
	Rem
	bbdoc: Unicode class name Lo
	end rem
	Const Letter_Other:Int = 19
	Rem
	bbdoc: Unicode class name Pc
	end rem
	Const Punctuation_Connector:Int = 20
	Rem
	bbdoc: Unicode class name Pd
	end rem
	Const Punctuation_Dash:Int = 21
	Rem
	bbdoc: Unicode class name Ps
	end rem
	Const Punctuation_Open:Int = 22
	Rem
	bbdoc: Unicode class name Pe
	end rem
	Const Punctuation_Close:Int = 23
	Rem
	bbdoc: Unicode class name Pi
	end rem
	Const Punctuation_InitialQuote:Int = 24
	Rem
	bbdoc: Unicode class name Pf
	end rem
	Const Punctuation_FinalQuote:Int = 25
	Rem
	bbdoc: Unicode class name Po
	end rem
	Const Punctuation_Other:Int = 26
	Rem
	bbdoc: Unicode class name Sm
	end rem
	Const Symbol_Math:Int = 27
	Rem
	bbdoc: Unicode class name Sc
	end rem
	Const Symbol_Currency:Int = 28
	Rem
	bbdoc: Unicode class name Sk
	end rem
	Const Symbol_Modifier:Int = 29
	Rem
	bbdoc: Unicode class name So
	end rem
	Const Symbol_Other:Int = 30
	Rem
	bbdoc: Qt cannot find an appropriate category for the character.
	end rem
	Const NoCategory:Int = 0
	
	Function category:Int(char:Int)
		Return bmx_qt_qchar_category(char)
	End Function

End Type

Type TQtKeyMap

	Function mapModifier:Int(maxKey:Int)
		Local m:Int = 0

		If maxKey & MODIFIER_SHIFT Then    'shift key
				m:| Qt_KeyMod_ShiftModifier
		End If

?MacOs
		If maxKey & MODIFIER_SYSTEM Then  'ctrl key
				m:| Qt_KeyMod_ControlModifier
		End If

		If maxKey & MODIFIER_CONTROL Then   ' windows / apple
				m:| Qt_KeyMod_MetaModifier   ' ??? or 3, 4, or 5...
		End If
?Not MacOs
		If maxKey & MODIFIER_CONTROL Then  'ctrl key
				m:| Qt_KeyMod_ControlModifier
		End If

		If maxKey & MODIFIER_SYSTEM Then   ' windows / apple
				m:| Qt_KeyMod_MetaModifier   ' ??? or 3, 4, or 5...
		End If
?

		If maxKey & MODIFIER_OPTION Then   'alt or menu key
				m:| Qt_KeyMod_AltModifier
		End If

		Return m
	End Function

	Function mapKey:Int(maxKey:Int)
		Global map:Int[]
	
		If Not map Then
			map = New Int[255]
	
			map[KEY_BACKSPACE] = Qt_Key_Backspace
			map[KEY_TAB] = Qt_Key_Tab
			map[KEY_CLEAR] = Qt_Key_Clear
			map[KEY_RETURN] = Qt_Key_Return
			map[KEY_ENTER] = Qt_Key_Enter
			map[KEY_ESCAPE] = Qt_Key_Escape
			map[KEY_SPACE] = Qt_Key_Space
			map[KEY_PAGEUP] = Qt_Key_PageUp
			map[KEY_PAGEDOWN] = Qt_Key_PageDown
			map[KEY_END] = Qt_Key_End
			map[KEY_HOME] = Qt_Key_Home
			
			map[KEY_LEFT] = Qt_Key_Left
			map[KEY_UP] = Qt_Key_Up
			map[KEY_RIGHT] = Qt_Key_Right
			map[KEY_DOWN] = Qt_Key_Down
			
			map[KEY_SELECT] = Qt_Key_Select
			map[KEY_PRINT] = Qt_Key_Print
			map[KEY_EXECUTE] = Qt_Key_Execute
			map[KEY_SCREEN] = Qt_Key_SysReq
			map[KEY_INSERT] = Qt_Key_Insert
			map[KEY_DELETE] = Qt_Key_Delete
	
	
			map[KEY_0] = Qt_Key_0
			map[KEY_1] = Qt_Key_1
			map[KEY_2] = Qt_Key_2
			map[KEY_3] = Qt_Key_3
			map[KEY_4] = Qt_Key_4
			map[KEY_5] = Qt_Key_5
			map[KEY_6] = Qt_Key_6
			map[KEY_7] = Qt_Key_7
			map[KEY_8] = Qt_Key_8
			map[KEY_9] = Qt_Key_9
			map[KEY_A] = Qt_Key_A
			map[KEY_B] = Qt_Key_B
			map[KEY_C] = Qt_Key_C
			map[KEY_D] = Qt_Key_D
			map[KEY_E] = Qt_Key_E
			map[KEY_F] = Qt_Key_F
			map[KEY_G] = Qt_Key_G
			map[KEY_H] = Qt_Key_H
			map[KEY_I] = Qt_Key_I
			map[KEY_J] = Qt_Key_J
			map[KEY_K] = Qt_Key_K
			map[KEY_L] = Qt_Key_L
			map[KEY_M] = Qt_Key_M
			map[KEY_N] = Qt_Key_N
			map[KEY_O] = Qt_Key_O
			map[KEY_P] = Qt_Key_P
			map[KEY_Q] = Qt_Key_Q
			map[KEY_R] = Qt_Key_R
			map[KEY_S] = Qt_Key_S
			map[KEY_T] = Qt_Key_T
			map[KEY_U] = Qt_Key_U
			map[KEY_V] = Qt_Key_V
			map[KEY_W] = Qt_Key_W
			map[KEY_X] = Qt_Key_X
			map[KEY_Y] = Qt_Key_Y
			map[KEY_Z] = Qt_Key_Z
	
			map[KEY_NUM0] = Qt_Key_0 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM1] = Qt_Key_1 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM2] = Qt_Key_2 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM3] = Qt_Key_3 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM4] = Qt_Key_4 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM5] = Qt_Key_5 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM6] = Qt_Key_6 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM7] = Qt_Key_7 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM8] = Qt_Key_8 + Qt_KeyMod_KeypadModifier
			map[KEY_NUM9] = Qt_Key_9 + Qt_KeyMod_KeypadModifier
			
			map[KEY_NUMMULTIPLY] = Qt_Key_Asterisk + Qt_KeyMod_KeypadModifier
			map[KEY_NUMADD] = Qt_Key_Plus + Qt_KeyMod_KeypadModifier
			map[KEY_NUMSUBTRACT] = Qt_Key_Minus + Qt_KeyMod_KeypadModifier
			map[KEY_NUMDECIMAL] = Qt_Key_Period + Qt_KeyMod_KeypadModifier
			map[KEY_NUMDIVIDE] = Qt_Key_Slash + Qt_KeyMod_KeypadModifier
			
			map[KEY_F1] = Qt_Key_F1
			map[KEY_F2] = Qt_Key_F2
			map[KEY_F3] = Qt_Key_F3
			map[KEY_F4] = Qt_Key_F4
			map[KEY_F5] = Qt_Key_F5
			map[KEY_F6] = Qt_Key_F6
			map[KEY_F7] = Qt_Key_F7
			map[KEY_F8] = Qt_Key_F8
			map[KEY_F9] = Qt_Key_F9
			map[KEY_F10] = Qt_Key_F10
			map[KEY_F11] = Qt_Key_F11
			map[KEY_F12] = Qt_Key_F12
			
			map[KEY_TILDE] = Qt_Key_AsciiTilde
			map[KEY_MINUS] = Qt_Key_Minus
			map[KEY_EQUALS] = Qt_Key_Plus
			
			map[KEY_OPENBRACKET] = Qt_Key_BracketLeft
			map[KEY_CLOSEBRACKET] = Qt_Key_BracketRight
			map[KEY_BACKSLASH] = Qt_Key_Backslash
			
			map[KEY_SEMICOLON] = Qt_Key_Semicolon
			map[KEY_QUOTES] = Qt_Key_At
			
			map[KEY_COMMA] = Qt_Key_Comma
			map[KEY_PERIOD] = Qt_Key_Period
			map[KEY_SLASH] = Qt_Key_Slash
			
			map[KEY_LSHIFT] = Qt_Key_Shift
			map[KEY_RSHIFT] = Qt_Key_Shift
			map[KEY_LCONTROL] = Qt_Key_Control
			map[KEY_RCONTROL] = Qt_Key_Control
			map[KEY_LALT] = Qt_Key_Alt
			map[KEY_RALT] = Qt_Key_Alt
			map[KEY_LSYS] = Qt_Key_Meta
			map[KEY_RSYS] = Qt_Key_Meta
	
		End If
	
		Return map[maxKey]
	
	End Function

End Type
