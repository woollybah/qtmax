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

Module Qt.QTextEdit

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"



Type QTextEdit Extends QAbstractScrollArea

	Function CreateTextEdit:QTextEdit(parent:QWidget = Null)
		Return New QTextEdit.Create(parent)
	End Function
	
	Method Create:QTextEdit(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qtextedit_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qtextedit_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method acceptRichText:Int()
	' TODO
	End Method
	
	Method alignment:Int()
	' TODO
	End Method
	
	Method anchorAt:String(x:Int, y:Int)
	' TODO
	End Method
	
	Method autoFormatting:Int()
	' TODO
	End Method
	
	Method canPaste:Int()
	' TODO
	End Method
	
	Method createStandardContextMenu:QMenu(x:Int = -1, y:Int = -1)
	' TODO
	End Method
	
	Method currentCharFormat:Int()
	' TODO
	End Method
	
	Method currentFont:QFont()
	' TODO
	End Method
	
	Method cursorForPosition:QTextCursor(x:Int, y:Int)
	' TODO
	End Method
	
	'QRect cursorRect(cursor:QTextCursor)
	' TODO
	'end method
	
	'QRect cursorRect()
	' TODO
	'end method
	
	Method cursorWidth:Int()
	' TODO
	End Method
	
	Method document:QTextDocument()
	' TODO
	End Method
	
	Method documentTitle:String()
	' TODO
	End Method
	
	Method ensureCursorVisible()
	' TODO
	End Method
	
	Method find:Int(Exp:String, options:Int = 0)
	' TODO
	End Method
	
	Method fontFamily:String()
	' TODO
	End Method
	
	Method fontItalic:Int()
	' TODO
	End Method
	
	Method fontPointSize:Double()
	' TODO
	End Method
	
	Method fontUnderline:Int()
	' TODO
	End Method
	
	Method fontWeight:Int()
	' TODO
	End Method
	
	Method isReadOnly:Int()
	' TODO
	End Method
	
	Method isUndoRedoEnabled:Int()
	' TODO
	End Method
	
	Method lineWrapColumnOrWidth:Int()
	' TODO
	End Method
	
	Method lineWrapMode:Int()
	' TODO
	End Method
	
	Method loadResource:QVariant(_type:Int, name:QUrl)
	' TODO
	End Method
	
	Method mergeCurrentCharFormat(modifier:QTextCharFormat)
	' TODO
	End Method
	
	'Method moveCursor(operation:Int, Mode:Int = QTextCursor.MoveAnchor)
	' TODO
	'End Method
	
	Method overwriteMode:Int()
	' TODO
	End Method
	
	Method Print(printer:QPrinter)
	' TODO
	End Method
	
	Method setAcceptRichText(accept:Int)
	' TODO
	End Method
	
	Method setAutoFormatting(features:Int)
	' TODO
	End Method
	
	Method setCurrentCharFormat(format:QTextCharFormat)
	' TODO
	End Method
	
	Method setCursorWidth(width:Int)
	' TODO
	End Method
	
	Method setDocument(document:QTextDocument)
	' TODO
	End Method
	
	Method setDocumentTitle(title:String)
	' TODO
	End Method
	
	Method setLineWrapColumnOrWidth(w:Int)
	' TODO
	End Method
	
	Method setLineWrapMode(Mode:Int)
	' TODO
	End Method
	
	Method setOverwriteMode(overwrite:Int)
	' TODO
	End Method
	
	Method setReadOnly(value:Int)
		bmx_qt_qtextedit_setreadonly(qObjectPtr, value)
	End Method

	Method setTabChangesFocus(b:Int)
	' TODO
	End Method
	
	Method setTabStopWidth(width:Int)
	' TODO
	End Method
	
	Method setTextCursor(cursor:QTextCursor)
	' TODO
	End Method
	
	Method setTextInteractionFlags(flags:Int)
	' TODO
	End Method
	
	Method setUndoRedoEnabled(enable:Int)
	' TODO
	End Method
	
	Method setWordWrapMode(policy:Int)
	' TODO
	End Method
	
	Method tabChangesFocus:Int()
	' TODO
	End Method
	
	Method tabStopWidth:Int()
	' TODO
	End Method
	
	Method textBackgroundColor:QColor()
	' TODO
	End Method
	
	Method textColor:QColor()
	' TODO
	End Method
	
	Method textCursor:QTextCursor()
	' TODO
	End Method
	
	Method textInteractionFlags:Int()
	' TODO
	End Method
	
	Method toHtml:String()
	' TODO
	End Method
	
	Method toPlainText:String()
	' TODO
	End Method
	
	Method wordWrapMode:Int()
	' TODO
	End Method

End Type

