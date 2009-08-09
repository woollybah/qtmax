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

Rem
bbdoc: QTextDocument
End Rem
Module Qt.QTextDocument

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


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

	Field qObjectPtr:Byte Ptr
	
	Function _create:QTextCursor(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTextCursor = New QTextCursor
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type
