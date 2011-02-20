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

Module Qt.Core

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"

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
