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

Rem
bbdoc: QTextDocument
End Rem
Module Qt.QTextDocument

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: Holds formatted text that can be viewed and edited using a QTextEdit.
about: QTextDocument is a container for structured rich text documents, providing support for styled text and various
types of document elements, such as lists, tables, frames, and images. They can be created for use in a QTextEdit, or
used independently.
<p>
Each document element is described by an associated format object. Each format object is treated as a unique object by
QTextDocuments, and can be passed to objectForFormat() to obtain the document element that it is applied to.
</p>
<p>
A QTextDocument can be edited programmatically using a QTextCursor, and its contents can be examined by traversing the
document structure. The entire document structure is stored as a hierarchy of document elements beneath the root frame,
found with the rootFrame() function. Alternatively, if you just want to iterate over the textual contents of the document
you can use begin(), end(), and findBlock() to retrieve text blocks that you can examine and iterate over.
</p>
<p>
The layout of a document is determined by the documentLayout(); you can create your own QAbstractTextDocumentLayout
subclass and set it using setDocumentLayout() if you want to use your own layout logic. The document's title and other
meta-information can be obtained by calling the metaInformation() function. For documents that are exposed to users through
the QTextEdit class, the document title is also available via the QTextEdit::documentTitle() function.
</p>
<p>
The toPlainText() and toHtml() convenience functions allow you to retrieve the contents of the document as plain text and
HTML. The document's text can be searched using the find() functions.
</p>
<p>
Undo/redo of operations performed on the document can be controlled using the setUndoRedoEnabled() function. The undo/redo
system can be controlled by an editor widget through the undo() and redo() slots; the document also provides contentsChanged(),
undoAvailable(), and redoAvailable() signals that inform connected editor widgets about the state of the undo/redo system.
</p>
End Rem
Type QTextDocument Extends QObject

	Function _create:QTextDocument(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextDocument = New QTextDocument
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function _find:QTextDocument(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QTextDocument = QTextDocument(qfind(qObjectPtr))
			If Not widget Then
				Return QTextDocument._create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Method idealWidth:Double()
		Return bmx_qt_qtextdocument_idealwidth(qObjectPtr)
	End Method
	
	Method indentWidth:Double()
		Return bmx_qt_qtextdocument_indentewidth(qObjectPtr)
	End Method

	Method isEmpty:Int()
		Return bmx_qt_qtextdocument_isempty(qObjectPtr)
	End Method

	Method isModified:Int()
		Return bmx_qt_qtextdocument_ismodified(qObjectPtr)
	End Method

	Method isRedoAvailable:Int()
		Return bmx_qt_qtextdocument_isredoavailable(qObjectPtr)
	End Method

	Method isUndoAvailable:Int()
		Return bmx_qt_qtextdocument_isundoavailable(qObjectPtr)
	End Method

	Method isUndoRedoEnabled:Int()
		Return bmx_qt_qtextdocument_isundoredoenabled(qObjectPtr)
	End Method

	Method lastBlock:QTextBlock()
		Return QTextBlock._create(bmx_qt_qtextdocument_lastblock(qObjectPtr))
	End Method
	
	Method lineCount:Int()
		Return bmx_qt_qtextdocument_linecount(qObjectPtr)
	End Method
	
	Method markContentsDirty(position:Int, length:Int)
		bmx_qt_qtextdocument_markcontentsdirty(qObjectPtr, position, length)
	End Method
	
	Method maximumBlockCount:Int()
		Return bmx_qt_qtextdocument_maximumblockcount(qObjectPtr)
	End Method
	
	Method metaInformation:String(info:Int)
		Return bmx_qt_qtextdocument_metainformation(qObjectPtr, info)
	End Method
	
	Method objectForIndex:QTextObject(objectIndex:Int)
		Return QTextObject._create(bmx_qt_qtextdocument_object(qObjectPtr, objectIndex))
	End Method
	
	Method objectForFormat:QTextObject(f:QTextFormat)
		Return QTextObject._create(bmx_qt_qtextdocument_objectforformat(qObjectPtr, f.qObjectPtr))
	End Method
	
	Method pageCount:Int()
		Return bmx_qt_qtextdocument_pagecount(qObjectPtr)
	End Method
	
	Method pageSize(w:Double Var, h:Double Var)
		bmx_qt_qtextdocument_pagesize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method Print(printer:QPrinter)
		bmx_qt_qtextdocument_print(qObjectPtr, printer.qObjectPtr)
	End Method
	
	Method redo(cursor:QTextCursor)
		If cursor Then
			bmx_qt_qtextdocument_redo(qObjectPtr, cursor.qObjectPtr)
		Else
			bmx_qt_qtextdocument_redo(qObjectPtr, Null)
		End If
	End Method
	
	'method resource:QVariant(_type:int, name:QUrl)
	'	return bmx_qt_qtextdocument_resource(qObjectPtr)
	'end method
	
	Method revision:Int()
		Return bmx_qt_qtextdocument_revision(qObjectPtr)
	End Method
	
	Method rootFrame:QTextFrame()
		Return QTextFrame._create(bmx_qt_qtextdocument_rootframe(qObjectPtr))
	End Method
	
	Method setDefaultFont(font:QFont)
		bmx_qt_qtextdocument_setdefaultfont(qObjectPtr, font.qObjectPtr)
	End Method
	
	Method setDefaultStyleSheet(sheet:String)
		bmx_qt_qtextdocument_setdefaultstylesheet(qObjectPtr, sheet)
	End Method
	
	Method setDefaultTextOption(option:QTextOption)
		bmx_qt_qtextdocument_setdefaulttextoption(qObjectPtr, option.qObjectPtr)
	End Method
	
	Method setDocumentLayout(layout:QAbstractTextDocumentLayout)
		bmx_qt_qtextdocument_setdocumentlayout(qObjectPtr, layout.qObjectPtr)
	End Method
	
	Method setDocumentMargin(margin:Double)
		bmx_qt_qtextdocument_setdocumentmargin(qObjectPtr, margin)
	End Method
	
	Method setHtml(html:String)
		bmx_qt_qtextdocument_sethtml(qObjectPtr, html)
	End Method
	
	Method setIndentWidth(width:Double)
		bmx_qt_qtextdocument_setindentwidth(qObjectPtr, width)
	End Method
	
	Method setMaximumBlockCount(maximum:Int)
		bmx_qt_qtextdocument_setmaximumblockcount(qObjectPtr, maximum)
	End Method
	
	Method setMetaInformation(info:Int, text:String)
		bmx_qt_qtextdocument_setmetainformation(qObjectPtr, info, text)
	End Method
	
	Method setModified(m:Int = True)
		bmx_qt_qtextdocument_setmodified(qObjectPtr, m)
	End Method
	
	Method setPageSize(w:Double, h:Double)
		bmx_qt_qtextdocument_setpagesize(qObjectPtr, w, h)
	End Method
	
	Method setPlainText(text:String)
		bmx_qt_qtextdocument_setplaintext(qObjectPtr, text)
	End Method
	
	Method setTextWidth(width:Double)
		bmx_qt_qtextdocument_settextwidth(qObjectPtr, width)
	End Method
	
	Method setUndoRedoEnabled(enable:Int)
		bmx_qt_qtextdocument_setundoredoenabled(qObjectPtr, enable)
	End Method
	
	Method setUseDesignMetrics(b:Int)
		bmx_qt_qtextdocument_setusedesignmetrics(qObjectPtr, b)
	End Method
	
	Method size(w:Double Var, h:Double Var)
		bmx_qt_qtextdocument_size(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method TextWidth:Double()
		Return bmx_qt_qtextdocument_textwidth(qObjectPtr)
	End Method
	
	'method toHtml:String(const QByteArray & encoding = QByteArray())
	'	return bmx_qt_qtextdocument_tohtml(qObjectPtr)
	'end method
	
	Method toPlainText:String()
		Return bmx_qt_qtextdocument_toplaintext(qObjectPtr)
	End Method
	
	Method undo(cursor:QTextCursor = Null)
		If cursor Then
			bmx_qt_qtextdocument_undo(qObjectPtr, cursor.qObjectPtr)
		Else
			bmx_qt_qtextdocument_undo(qObjectPtr, Null)
		End If
	End Method
	
	Method useDesignMetrics:Int()
		Return bmx_qt_qtextdocument_usedesignmetrics(qObjectPtr)
	End Method

	' SIGNAL : blockCountChanged
	Function _OnBlockCountChanged(obj:QTextDocument, newBlockCount:Int)
		obj._InvokeSignals("blockCountChanged", [String(newBlockCount)])
	End Function

	' SIGNAL : contentsChange
	Function _OnContentsChange(obj:QTextDocument, position:Int, charsRemoved:Int, charsAdded:Int)
		obj._InvokeSignals("contentsChange", [String(position), String(charsRemoved), String(charsAdded)])
	End Function

	' SIGNAL : contentsChanged
	Function _OnContentsChanged(obj:QTextDocument)
		obj._InvokeSignals("contentsChanged", Null)
	End Function

	' SIGNAL : cursorPositionChanged
	Function _OnCursorPositionChanged(obj:QTextDocument, cursor:Byte Ptr)
		obj._InvokeSignals("cursorPositionChanged", [QTextCursor._create(cursor)])
	End Function

	' SIGNAL : documentLayoutChanged
	Function _OnDocumentLayoutChanged(obj:QTextDocument)
		obj._InvokeSignals("documentLayoutChanged", Null)
	End Function

	' SIGNAL : modificationChanged
	Function _OnModificationChanged(obj:QTextDocument, changed:Int)
		obj._InvokeSignals("modificationChanged", [String(changed)])
	End Function

	' SIGNAL : redoAvailable
	Function _OnRedoAvailable(obj:QTextDocument, available:Int)
		obj._InvokeSignals("redoAvailable", [String(available)])
	End Function

	' SIGNAL : undoAvailable
	Function _OnUndoAvailable(obj:QTextDocument, available:Int)
		obj._InvokeSignals("undoAvailable", [String(available)])
	End Function

	' SIGNAL : undoCommandAdded
	Function _OnUndoCommandAdded(obj:QTextDocument)
		obj._InvokeSignals("undoCommandAdded", Null)
	End Function

End Type

Rem
bbdoc: An API to access and modify QTextDocuments.
about: Text cursors are objects that are used to access and modify the contents and underlying structure of text
documents via a programming interface that mimics the behavior of a cursor in a text editor. QTextCursor contains
information about both the cursor's position within a QTextDocument and any selection that it has made.
<p>
QTextCursor is modeled on the way a text cursor behaves in a text editor, providing a programmatic means of performing
standard actions through the user interface. A document can be thought of as a single string of characters with the
cursor's position() being between any two characters (or at the very beginning or very end of the document). Documents
can also contain tables, lists, images, and other objects in addition to text but, from the developer's point of view,
the document can be treated as one long string. Some portions of that string can be considered to lie within particular
blocks (e.g. paragraphs), or within a table's cell, or a list's item, or other structural elements. When we refer to
"current character" we mean the character immediately after the cursor position() in the document; similarly the
"current block" is the block that contains the cursor position().
</p>
<p>
A QTextCursor also has an anchor() position. The text that is between the anchor() and the position() is the selection.
If anchor() == position() there is no selection.
</p>
<p>
The cursor position can be changed programmatically using setPosition() and movePosition(); the latter can also be used
to select text. For selections see selectionStart(), selectionEnd(), hasSelection(), clearSelection(), and removeSelectedText().
</p>
<p>
If the position() is at the start of a block atBlockStart() returns true; and if it is at the end of a block atBlockEnd()
returns true. The format of the current character is returned by charFormat(), and the format of the current block is
returned by blockFormat().
</p>
<p>
Formatting can be applied to the current text document using the setCharFormat(), mergeCharFormat(), setBlockFormat() and
mergeBlockFormat() functions. The 'set' functions will replace the cursor's current character or block format, while the
'merge' functions add the given format properties to the cursor's current format. If the cursor has a selection the given
format is applied to the current selection. Note that when only parts of a block is selected the block format is applied to
the entire block. The text at the current character position can be turned into a list using createList().
</p>
<p>
Deletions can be achieved using deleteChar(), deletePreviousChar(), and removeSelectedText().
</p>
<p>
Text strings can be inserted into the document with the insertText() function, blocks (representing new paragraphs) can be
inserted with insertBlock().
</p>
<p>
Existing fragments of text can be inserted with insertFragment() but, if you want to insert pieces of text in various formats,
it is usually still easier to use insertText() and supply a character format.
</p>
<p>
Various types of higher-level structure can also be inserted into the document with the cursor:
<ul>
<li> Lists are ordered sequences of block elements that are decorated with bullet points or symbols. These are inserted in a
specified format with insertList().</li>
<li> Tables are inserted with the insertTable() function, and can be given an optional format. These contain an array of cells
that can be traversed using the cursor.</li>
<li> Inline images are inserted with insertImage(). The image to be used can be specified in an image format, or by name.</li>
<li> Frames are inserted by calling insertFrame() with a specified format.</li>
</li>
</p>
<p>
Actions can be grouped (i.e. treated as a single action for undo/redo) using beginEditBlock() and endEditBlock().
</p>
<p>
Cursor movements are limited to valid cursor positions. In Latin writing this is usually after every character in the text.
In some other writing systems cursor movements are limited to "clusters" (e.g. a syllable in Devanagari, or a base letter plus
diacritics). Functions such as movePosition() and deleteChar() limit cursor movement to these valid positions.
</p>
End Rem
Type QTextCursor

	Rem
	bbdoc: Moves the anchor to the same position as the cursor itself.
	end rem
	Const Mode_MoveAnchor:Int = 0
	Rem
	bbdoc: Keeps the anchor where it is.
	end rem
	Const Mode_KeepAnchor:Int = 1

	Rem
	bbdoc: Keep the cursor where it is
	end rem
	Const Op_NoMove:Int = 0
	Rem
	bbdoc: Move to the start of the document.
	end rem
	Const Op_Start:Int = 1
	Rem
	bbdoc: Move to the start of the current line.
	end rem
	Const Op_StartOfLine:Int = 3
	Rem
	bbdoc: Move to the start of the current block.
	end rem
	Const Op_StartOfBlock:Int = 4
	Rem
	bbdoc: Move to the start of the current word.
	end rem
	Const Op_StartOfWord:Int = 5
	Rem
	bbdoc: Move to the start of the previous block.
	end rem
	Const Op_PreviousBlock:Int = 6
	Rem
	bbdoc: Move to the previous character.
	end rem
	Const Op_PreviousCharacter:Int = 7
	Rem
	bbdoc: Move to the beginning of the previous word.
	end rem
	Const Op_PreviousWord:Int = 8
	Rem
	bbdoc: Move up one line.
	end rem
	Const Op_Up:Int = 2
	Rem
	bbdoc: Move left one character.
	end rem
	Const Op_Left:Int = 9
	Rem
	bbdoc: Move left one word.
	end rem
	Const Op_WordLeft:Int = 10
	Rem
	bbdoc: Move to the end of the document.
	end rem
	Const Op_End:Int = 11
	Rem
	bbdoc: Move to the end of the current line.
	end rem
	Const Op_EndOfLine:Int = 13
	Rem
	bbdoc: Move to the end of the current word.
	end rem
	Const Op_EndOfWord:Int = 14
	Rem
	bbdoc: Move to the end of the current block.
	end rem
	Const Op_EndOfBlock:Int = 15
	Rem
	bbdoc: Move to the beginning of the next block.
	end rem
	Const Op_NextBlock:Int = 16
	Rem
	bbdoc: Move to the next character.
	end rem
	Const Op_NextCharacter:Int = 17
	Rem
	bbdoc: Move to the next word.
	end rem
	Const Op_NextWord:Int = 18
	Rem
	bbdoc: Move down one line.
	end rem
	Const Op_Down:Int = 12
	Rem
	bbdoc: Move right one character.
	end rem
	Const Op_Right:Int = 19
	Rem
	bbdoc: Move right one word.
	end rem
	Const Op_WordRight:Int = 20
	Rem
	bbdoc: Move to the beginning of the next table cell inside the current table.
	about: If the current cell is the last cell in the row, the cursor will move to the first cell in the next row.
	End Rem
	Const Op_NextCell:Int = 21
	Rem
	bbdoc: Move to the beginning of the previous table cell inside the current table.
	about: If the current cell is the first cell in the row, the cursor will move to the last cell in the previous row.
	End Rem
	Const Op_PreviousCell:Int = 22
	Rem
	bbdoc: Move to the first new cell of the next row in the current table.
	end rem
	Const Op_NextRow:Int = 23
	Rem
	bbdoc: Move to the last cell of the previous row in the current table.
	end rem
	Const Op_PreviousRow:Int = 24

	Rem
	bbdoc: Selects the entire document.
	end rem
	Const Type_Document:Int = 3
	Rem
	bbdoc: Selects the block of text under the cursor.
	end rem
	Const Type_BlockUnderCursor:Int = 2
	Rem
	bbdoc: Selects the line of text under the cursor.
	end rem
	Const Type_LineUnderCursor:Int = 1
	Rem
	bbdoc: Selects the word under the cursor.
	about: If the cursor is not positioned within a string of selectable characters, no text is selected.
	End Rem
	Const Type_WordUnderCursor:Int = 0
	

	Field qObjectPtr:Byte Ptr
	
	Function _create:QTextCursor(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextCursor = New QTextCursor
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method anchor:Int()
		Return bmx_qt_qtextcursor_anchor(qObjectPtr)
	End Method
	
	Method atBlockEnd:Int()
		Return bmx_qt_qtextcursor_atblockend(qObjectPtr)
	End Method
	
	Method atBlockStart:Int()
		Return bmx_qt_qtextcursor_atblockstart(qObjectPtr)
	End Method
	
	Method atEnd:Int()
		Return bmx_qt_qtextcursor_atend(qObjectPtr)
	End Method
	
	Method atStart:Int()
		Return bmx_qt_qtextcursor_atstart(qObjectPtr)
	End Method
	
	Method beginEditBlock()
		bmx_qt_qtextcursor_begineditblock(qObjectPtr)
	End Method
	
	Method block:QTextBlock()
		Return QTextBlock._create(bmx_qt_qtextcursor_block(qObjectPtr))
	End Method
	
	Method blockCharFormat:QTextCharFormat()
		Return QTextCharFormat._create(bmx_qt_qtextcursor_blockcharformat(qObjectPtr))
	End Method
	
	Method blockFormat:QTextBlockFormat()
		Return QTextBlockFormat._create(bmx_qt_qtextcursor_blockformat(qObjectPtr))
	End Method
	
	Method blockNumber:Int()
		Return bmx_qt_qtextcursor_blocknumber(qObjectPtr)
	End Method
	
	Method charFormat:QTextCharFormat()
		Return QTextCharFormat._create(bmx_qt_qtextcursor_charformat(qObjectPtr))
	End Method
	
	Method clearSelection()
		bmx_qt_qtextcursor_clearselection(qObjectPtr)
	End Method
	
	Method columnNumber:Int()
		Return bmx_qt_qtextcursor_columnnumber(qObjectPtr)
	End Method

	Method deleteChar()
		bmx_qt_qtextcursor_deletechar(qObjectPtr)
	End Method
	
	Method deletePreviousChar()
		bmx_qt_qtextcursor_deletepreviouschar(qObjectPtr)
	End Method
	
	Method document:QTextDocument()
	' TODO
	End Method
	
	Method endEditBlock()
		bmx_qt_qtextcursor_endeditblock(qObjectPtr)
	End Method
	
	Method hasComplexSelection:Int()
		Return bmx_qt_qtextcursor_hascomplexselection(qObjectPtr)
	End Method
	
	Method hasSelection:Int()
		Return bmx_qt_qtextcursor_hasselection(qObjectPtr)
	End Method
	
	Method insertBlock()
		bmx_qt_qtextcursor_insertblock(qObjectPtr)
	End Method
	
	Method insertBlockFormat(format:QTextBlockFormat)
		bmx_qt_qtextcursor_insertblockformat(qObjectPtr, format.qObjectPtr)
	End Method
	
	Method insertBlockCharFormat(format:QTextBlockFormat, charFormat:QTextCharFormat)
		bmx_qt_qtextcursor_insertblockcharformat(qObjectPtr, format.qObjectPtr, charFormat.qObjectPtr)
	End Method
	
	Method insertFragment(fragment:QTextDocumentFragment)
		bmx_qt_qtextcursor_insertfragment(qObjectPtr, fragment.qObjectPtr)
	End Method
	
	Method insertFrame:QTextFrame(format:QTextFrameFormat)
			'Return QTextFrame._create(bmx_qt_qtextcursor_insertframe(qObjectPtr, format.qObjectPtr)
	End Method
	
	Method insertHtml(html:String)
		bmx_qt_qtextcursor_inserthtml(qObjectPtr, html)
	End Method
	
	Method insertImage(format:QTextImageFormat)
		bmx_qt_qtextcursor_insertimage(qObjectPtr, format.qObjectPtr)
	End Method
	
	Method insertImageAlign(format:QTextImageFormat, alignment:Int)
		bmx_qt_qtextcursor_insertimagealign(qObjectPtr, format.qObjectPtr, alignment)
	End Method
	
	Method insertImageName(name:String)
		bmx_qt_qtextcursor_insertimagename(qObjectPtr, name)
	End Method
	
	Method insertImageImage(image:QImage, name:String = Null)
		bmx_qt_qtextcursor_insertimageimage(qObjectPtr, image.qObjectPtr, name)
	End Method
	
	Method insertText(text:String)
		bmx_qt_qtextcursor_inserttext(qObjectPtr, text)
	End Method
	
	Method insertTextFormat(text:String, format:QTextCharFormat)
		bmx_qt_qtextcursor_inserttextformat(qObjectPtr, text, format.qObjectPtr)
	End Method
	
	Method isCopyOf:Int(other:QTextCursor)
		Return bmx_qt_qtextcursor_iscopyof(qObjectPtr, other.qObjectPtr)
	End Method
	
	Method isNull:Int()
		Return bmx_qt_qtextcursor_isnull(qObjectPtr)
	End Method
	
	Method joinPreviousEditBlock()
		bmx_qt_qtextcursor_joinpreviouseditblock(qObjectPtr)
	End Method
	
	Method keepPositionOnInsert:Int()
		Return bmx_qt_qtextcursor_keeppositiononinsert(qObjectPtr)
	End Method
	
	Method mergeBlockCharFormat(modifier:QTextCharFormat)
		bmx_qt_qtextcursor_mergeblockcharformat(qObjectPtr, modifier.qObjectPtr)
	End Method
	
	Method mergeBlockFormat(modifier:QTextBlockFormat)
		bmx_qt_qtextcursor_mergeblockformat(qObjectPtr, modifier.qObjectPtr)
	End Method
	
	Method mergeCharFormat(modifier:QTextCharFormat)
		bmx_qt_qtextcursor_mergecharformat(qObjectPtr, modifier.qObjectPtr)
	End Method
	
	Method movePosition:Int(operation:Int, Mode:Int = Mode_MoveAnchor, n:Int = 1)
		Return bmx_qt_qtextcursor_moveposition(qObjectPtr, operation, Mode, n)
	End Method
	
	Method position:Int()
		Return bmx_qt_qtextcursor_position(qObjectPtr)
	End Method
	
	Method positionInBlock:Int()
		Return bmx_qt_qtextcursor_positioninblock(qObjectPtr)
	End Method
	
	Method removeSelectedText()
		bmx_qt_qtextcursor_removeselectedtext(qObjectPtr)
	End Method
	
	Method selectText(selection:Int)
		bmx_qt_qtextcursor_selecttext(qObjectPtr, selection)
	End Method
	
	Method selectedTableCells(firstRow:Int Var, numRows:Int Var, firstColumn:Int Var, numColumns:Int Var)
	' TODO
	End Method
	
	Method selectedText:String()
		Return bmx_qt_qtextcursor_selectedtext(qObjectPtr)
	End Method
	
	Method selection:QTextDocumentFragment()
		Return QTextDocumentFragment._create(bmx_qt_qtextcursor_selection(qObjectPtr))
	End Method
	
	Method selectionEnd:Int()
		Return bmx_qt_qtextcursor_selectionend(qObjectPtr)
	End Method
	
	Method selectionStart:Int()
		Return bmx_qt_qtextcursor_selectionstart(qObjectPtr)
	End Method
	
	Method setBlockCharFormat(format:QTextCharFormat)
		bmx_qt_qtextcursor_setblockcharformat(qObjectPtr, format.qObjectPtr)
	End Method
	
	Method setBlockFormat(format:QTextBlockFormat)
		bmx_qt_qtextcursor_setblockformat(qObjectPtr, format.qObjectPtr)
	End Method
	
	Method setCharFormat(format:QTextCharFormat)
		bmx_qt_qtextcursor_setcharformat(qObjectPtr, format.qObjectPtr)
	End Method
	
	Method setKeepPositionOnInsert(value:Int)
		bmx_qt_qtextcursor_setkeepoisitiononinsert(qObjectPtr, value)
	End Method
	
	Method setPosition(pos:Int, Mode:Int = Mode_MoveAnchor)
		bmx_qt_qtextcursor_setposition(qObjectPtr, pos, Mode)
	End Method
	
	Method setVerticalMovementX(x:Int)
		bmx_qt_qtextcursor_setverticalmovementx(qObjectPtr, x)
	End Method
	
	Method setVisualNavigation(value:Int)
		bmx_qt_qtextcursor_setvisualnavigation(qObjectPtr, value)
	End Method
	
	Method verticalMovementX:Int()
		Return bmx_qt_qtextcursor_verticalmovementx(qObjectPtr)
	End Method
	
	Method visualNavigation:Int()
		Return bmx_qt_qtextcursor_visualnavigation(qObjectPtr)
	End Method

End Type


Type QTextBlock

	Field qObjectPtr:Byte Ptr
	
	Function _create:QTextBlock(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextBlock = New QTextBlock
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QTextObject Extends QObject

	Function _create:QTextObject(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextObject = New QTextObject
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QTextFrame Extends QTextObject

	Function _create:QTextFrame(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextFrame = New QTextFrame
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QTextOption

	Rem
	bbdoc: Text is not wrapped at all.
	End Rem
	Const Wrap_NoWrap:Int = 0
	Rem
	bbdoc: Text is wrapped at word boundaries.
	End Rem
	Const Wrap_WordWrap:Int = 1
	Rem
	bbdoc: Same as QTextOption::NoWrap
	End Rem
	Const Wrap_ManualWrap:Int = 2
	Rem
	bbdoc: Text can be wrapped at any point on a line, even if it occurs in the middle of a word.
	End Rem
	Const Wrap_WrapAnywhere:Int = 3
	Rem
	bbdoc: If possible, wrapping occurs at a word boundary;
	about: otherwise it will occur at the appropriate point on the line, even in the middle of a word.
	End Rem
	Const Wrap_WrapAtWordBoundaryOrAnywhere:Int = 4

	Field qObjectPtr:Byte Ptr
	
	Function _create:QTextOption(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextOption = New QTextOption
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QAbstractTextDocumentLayout Extends QObject

	Function _create:QAbstractTextDocumentLayout(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QAbstractTextDocumentLayout = New QAbstractTextDocumentLayout
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QTextDocumentFragment

	Field qObjectPtr:Byte Ptr
	
	Function _create:QTextDocumentFragment(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextDocumentFragment = New QTextDocumentFragment
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

