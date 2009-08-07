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

Module Qt.QKeySequence

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QKeySequence

	Field qObjectPtr:Byte Ptr
	
	Rem
	bbdoc: Add new tab.
	end rem
	Const Key_AddTab:Int = 19
	Rem
	bbdoc: Navigate back.
	end rem
	Const Key_Back:Int = 13
	Rem
	bbdoc: Bold text.
	end rem
	Const Key_Bold:Int = 27
	Rem
	bbdoc: Close document/tab.
	end rem
	Const Key_Close:Int = 4
	Rem
	bbdoc: Copy.
	end rem
	Const Key_Copy:Int = 9
	Rem
	bbdoc: Cut.
	end rem
	Const Key_Cut:Int = 8
	Rem
	bbdoc: Delete.
	end rem
	Const Key_Delete:Int = 7
	Rem
	bbdoc: Delete end of line.
	end rem
	Const Key_DeleteEndOfLine:Int = 60
	Rem
	bbdoc: Delete word from the end of the cursor.
	end rem
	Const Key_DeleteEndOfWord:Int = 59
	Rem
	bbdoc: Delete the beginning of a word up to the cursor.
	end rem
	Const Key_DeleteStartOfWord:Int = 58
	Rem
	bbdoc: Find in document.
	end rem
	Const Key_Find:Int = 22
	Rem
	bbdoc: Find next result.
	end rem
	Const Key_FindNext:Int = 23
	Rem
	bbdoc: Find previous result.
	end rem
	Const Key_FindPrevious:Int = 24
	Rem
	bbdoc: Navigate forward.
	end rem
	Const Key_Forward:Int = 14
	Rem
	bbdoc: Open help contents.
	end rem
	Const Key_HelpContents:Int = 1
	Rem
	bbdoc: Insert a new line.
	end rem
	Const Key_InsertLineSeparator:Int = 62
	Rem
	bbdoc: Insert a new paragraph.
	end rem
	Const Key_InsertParagraphSeparator:Int = 61
	Rem
	bbdoc: Italic text.
	end rem
	Const Key_Italic:Int = 28
	Rem
	bbdoc: Move cursor to end of block.
	about: This shortcut is only used on the OS X.
	End Rem
	Const Key_MoveToEndOfBlock:Int = 41
	Rem
	bbdoc: Move cursor to end of document.
	end rem
	Const Key_MoveToEndOfDocument:Int = 43
	Rem
	bbdoc: Move cursor to end of line.
	end rem
	Const Key_MoveToEndOfLine:Int = 39
	Rem
	bbdoc: Move cursor to next character.
	end rem
	Const Key_MoveToNextChar:Int = 30
	Rem
	bbdoc: Move cursor to next line.
	end rem
	Const Key_MoveToNextLine:Int = 34
	Rem
	bbdoc: Move cursor to next page.
	end rem
	Const Key_MoveToNextPage:Int = 36
	Rem
	bbdoc: Move cursor to next word.
	end rem
	Const Key_MoveToNextWord:Int = 32
	Rem
	bbdoc: Move cursor to previous character.
	end rem
	Const Key_MoveToPreviousChar:Int = 31
	Rem
	bbdoc: Move cursor to previous line.
	end rem
	Const Key_MoveToPreviousLine:Int = 35
	Rem
	bbdoc: Move cursor to previous page.
	end rem
	Const Key_MoveToPreviousPage:Int = 37
	Rem
	bbdoc: Move cursor to previous word.
	end rem
	Const Key_MoveToPreviousWord:Int = 33
	Rem
	bbdoc: Move cursor to start of a block.
	about: This shortcut is only used on OS X.
	End Rem
	Const Key_MoveToStartOfBlock:Int = 40
	Rem
	bbdoc: Move cursor to start of document.
	end rem
	Const Key_MoveToStartOfDocument:Int = 42
	Rem
	bbdoc: Move cursor to start of line.
	end rem
	Const Key_MoveToStartOfLine:Int = 38
	Rem
	bbdoc: Create new document.
	end rem
	Const Key_New:Int = 6
	Rem
	bbdoc: Navigate to next tab or child window.
	end rem
	Const Key_NextChild:Int = 20
	Rem
	bbdoc: Open document.
	end rem
	Const Key_Open:Int = 3
	Rem
	bbdoc: Paste.
	end rem
	Const Key_Paste:Int = 10
	Rem
	bbdoc: Navigate to previous tab or child window.
	end rem
	Const Key_PreviousChild:Int = 21
	Rem
	bbdoc: Print document.
	end rem
	Const Key_Print:Int = 18
	Rem
	bbdoc: Redo.
	end rem
	Const Key_Redo:Int = 12
	Rem
	bbdoc: Refresh or reload current document.
	end rem
	Const Key_Refresh:Int = 15
	Rem
	bbdoc: Find and replace.
	end rem
	Const Key_Replace:Int = 25
	Rem
	bbdoc: Save document after prompting the user for a file name.
	end rem
	Const Key_SaveAs:Int = 63
	Rem
	bbdoc: Save document.
	end rem
	Const Key_Save:Int = 5
	Rem
	bbdoc: Select all text.
	end rem
	Const Key_SelectAll:Int = 26
	Rem
	bbdoc: Extend selection to the end of a text block.
	about: This shortcut is only used on OS X.
	End Rem
	Const Key_SelectEndOfBlock:Int = 55
	Rem
	bbdoc: Extend selection to end of document.
	end rem
	Const Key_SelectEndOfDocument:Int = 57
	Rem
	bbdoc: Extend selection to end of line.
	end rem
	Const Key_SelectEndOfLine:Int = 53
	Rem
	bbdoc: Extend selection to next character.
	end rem
	Const Key_SelectNextChar:Int = 44
	Rem
	bbdoc: Extend selection to next line.
	end rem
	Const Key_SelectNextLine:Int = 48
	Rem
	bbdoc: Extend selection to next page.
	end rem
	Const Key_SelectNextPage:Int = 50
	Rem
	bbdoc: Extend selection to next word.
	end rem
	Const Key_SelectNextWord:Int = 46
	Rem
	bbdoc: Extend selection to previous character.
	end rem
	Const Key_SelectPreviousChar:Int = 45
	Rem
	bbdoc: Extend selection to previous line.
	end rem
	Const Key_SelectPreviousLine:Int = 49
	Rem
	bbdoc: Extend selection to previous page.
	end rem
	Const Key_SelectPreviousPage:Int = 51
	Rem
	bbdoc: Extend selection to previous word.
	end rem
	Const Key_SelectPreviousWord:Int = 47
	Rem
	bbdoc: Extend selection to the start of a text block.
	about: This shortcut is only used on OS X.
	End Rem
	Const Key_SelectStartOfBlock:Int = 54
	Rem
	bbdoc: Extend selection to start of document.
	end rem
	Const Key_SelectStartOfDocument:Int = 56
	Rem
	bbdoc: Extend selection to start of line.
	end rem
	Const Key_SelectStartOfLine:Int = 52
	Rem
	bbdoc: Underline text.
	end rem
	Const Key_Underline:Int = 29
	Rem
	bbdoc: Undo.
	end rem
	Const Key_Undo:Int = 11
	Rem
	bbdoc: Unbound key.
	end rem
	Const Key_UnknownKey:Int = 0
	Rem
	bbdoc: Activate whats this.
	end rem
	Const Key_WhatsThis:Int = 2
	Rem
	bbdoc: Zoom in.
	end rem
	Const Key_ZoomIn:Int = 16
	Rem
	bbdoc: Zoom out.
	end rem
	Const Key_ZoomOut:Int = 17


End Type
