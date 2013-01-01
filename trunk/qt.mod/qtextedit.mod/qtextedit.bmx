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

Module Qt.QTextEdit

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"



Type QTextEdit Extends QAbstractScrollArea

	Rem
	bbdoc: Don't do any automatic formatting.
	end rem
	Const Formatter_AutoNone:Int = 0
	Rem
	bbdoc: Automatically create bullet lists (e.g. when the user enters an asterisk ('*') in the left most column, or presses Enter in an existing list item.
	end rem
	Const Formatter_AutoBulletList:Int = 1
	Rem
	bbdoc: Apply all automatic formatting. Currently only automatic bullet lists are supported.
	end rem
	Const Formatter_AutoAll:Int = 2

	Rem
	bbdoc: 
	end rem
	Const Mode_NoWrap:Int = 0
	Rem
	bbdoc: 
	end rem
	Const Mode_WidgetWidth:Int = 1
	Rem
	bbdoc: 
	end rem
	Const Mode_FixedPixelWidth:Int = 2
	Rem
	bbdoc: 
	end rem
	Const Mode_FixedColumnWidth:Int = 3

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
		Return bmx_qt_qtextedit_acceptrichtext(qObjectPtr)
	End Method
	
	Method alignment:Int()
		Return bmx_qt_qtextedit_alignment(qObjectPtr)
	End Method
	
	Method anchorAt:String(x:Int, y:Int)
		Return bmx_qt_qtextedit_anchorat(qObjectPtr, x, y)
	End Method
	
	Method autoFormatting:Int()
		Return bmx_qt_qtextedit_autoformatting(qObjectPtr)
	End Method
	
	Method canPaste:Int()
		Return bmx_qt_qtextedit_canpaste(qObjectPtr)
	End Method
	
	Method createStandardContextMenu:QMenu(x:Int = -1, y:Int = -1)
	' TODO
	End Method
	
	Method currentCharFormat:QTextCharFormat()
		Return QTextCharFormat._create(bmx_qt_qtextedit_currentcharformat(qObjectPtr))
	End Method
	
	Method currentFont:QFont()
		Return QFont._create(bmx_qt_qtextedit_currentfont(qObjectPtr))
	End Method
	
	Method cursorForPosition:QTextCursor(x:Int, y:Int)
		Return QTextCursor._create(bmx_qt_qtextedit_cursorforposition(qObjectPtr, x, y))
	End Method
	
	'QRect cursorRect(cursor:QTextCursor)
	' TODO
	'end method
	
	'QRect cursorRect()
	' TODO
	'end method
	
	Method cursorWidth:Int()
		Return bmx_qt_qtextedit_cursorwidth(qObjectPtr)
	End Method
	
	Method document:QTextDocument()
		Return QTextDocument._find(bmx_qt_qtextedit_document(qObjectPtr))
	End Method
	
	Method documentTitle:String()
		Return bmx_qt_qtextedit_documenttitle(qObjectPtr)
	End Method
	
	Method ensureCursorVisible()
		bmx_qt_qtextedit_ensurecursorvisible(qObjectPtr)
	End Method
	
	Method find:Int(expr:String, options:Int = 0)
		Return bmx_qt_qtextedit_find(qObjectPtr, expr, options)
	End Method
	
	Method fontFamily:String()
		Return bmx_qt_qtextedit_fontfamily(qObjectPtr)
	End Method
	
	Method fontItalic:Int()
		Return bmx_qt_qtextedit_fontitalic(qObjectPtr)
	End Method
	
	Method fontPointSize:Double()
		Return bmx_qt_qtextedit_fontpointsize(qObjectPtr)
	End Method
	
	Method fontUnderline:Int()
		Return bmx_qt_qtextedit_fontunderline(qObjectPtr)
	End Method
	
	Method fontWeight:Int()
		Return bmx_qt_qtextedit_fontweight(qObjectPtr)
	End Method
	
	Method isReadOnly:Int()
		Return bmx_qt_qtextedit_isreadonly(qObjectPtr)
	End Method
	
	Method isUndoRedoEnabled:Int()
		Return bmx_qt_qtextedit_isundoredoenabled(qObjectPtr)
	End Method
	
	Method lineWrapColumnOrWidth:Int()
		Return bmx_qt_qtextedit_linewrapcolumnorwidth(qObjectPtr)
	End Method
	
	Method lineWrapMode:Int()
		Return bmx_qt_qtextedit_linewrapmode(qObjectPtr)
	End Method
	
	Method loadResource:QVariant(_type:Int, name:QUrl)
	' TODO
	End Method
	
	Method mergeCurrentCharFormat(modifier:QTextCharFormat)
		bmx_qt_qtextedit_mergecurrentcharformat(qObjectPtr, modifier.qObjectPtr)
	End Method
	
	'Method moveCursor(operation:Int, Mode:Int = QTextCursor.MoveAnchor)
	' TODO
	'End Method
	
	Method overwriteMode:Int()
		Return bmx_qt_qtextedit_overwritemode(qObjectPtr)
	End Method
	
	Method Print(printer:QPrinter)
	' TODO
	End Method
	
	Method setAcceptRichText(accept:Int)
		bmx_qt_qtextedit_setacceptrichtext(qObjectPtr, accept)
	End Method
	
	Method setAutoFormatting(features:Int)
		bmx_qt_qtextedit_setautoformatting(qObjectPtr, features)
	End Method
	
	Method setCurrentCharFormat(format:QTextCharFormat)
	' TODO
	End Method
	
	Method setCursorWidth(width:Int)
		bmx_qt_qtextedit_setcursorwidth(qObjectPtr, width)
	End Method
	
	Method setDocument(document:QTextDocument)
	' TODO
	End Method
	
	Method setDocumentTitle(title:String)
		bmx_qt_qtextedit_setdocumenttitle(qObjectPtr, title)
	End Method
	
	Method setLineWrapColumnOrWidth(w:Int)
		bmx_qt_qtextedit_setlinewrapcolumnorwidth(qObjectPtr, w)
	End Method
	
	Method setLineWrapMode(Mode:Int)
		bmx_qt_qtextedit_setlinewrapmode(qObjectPtr, Mode)
	End Method
	
	Method setOverwriteMode(overwrite:Int)
	' TODO
	End Method
	
	Method setReadOnly(value:Int)
		bmx_qt_qtextedit_setreadonly(qObjectPtr, value)
	End Method

	Method setTabChangesFocus(value:Int)
		bmx_qt_qtextedit_settabchangesfocus(qObjectPtr, value)
	End Method
	
	Method setTabStopWidth(width:Int)
		bmx_qt_qtextedit_settabstopwidth(qObjectPtr, width)
	End Method
	
	Method setTextCursor(cursor:QTextCursor)
		bmx_qt_qtextedit_settextcursor(qObjectPtr, cursor.qObjectPtr)
	End Method
	
	Method setTextInteractionFlags(flags:Int)
		bmx_qt_qtextedit_settextinteractionflags(qObjectPtr, flags)
	End Method
	
	Method setUndoRedoEnabled(enable:Int)
		bmx_qt_qtextedit_setundoredoenabled(qObjectPtr, enable)
	End Method
	
	Method setWordWrapMode(policy:Int)
		bmx_qt_qtextedit_setwordwrapmode(qObjectPtr, policy)
	End Method
	
	Method tabChangesFocus:Int()
		Return bmx_qt_qtextedit_tabchangesfocus(qObjectPtr)
	End Method
	
	Method tabStopWidth:Int()
		Return bmx_qt_qtextedit_tabstopwidth(qObjectPtr)
	End Method
	
	Method textBackgroundColor:QColor()
		Return QColor._create(bmx_qt_qtextedit_textbackgroundcolor(qObjectPtr))
	End Method
	
	Method textColor:QColor()
		Return QColor._create(bmx_qt_qtextedit_textcolor(qObjectPtr))
	End Method
	
	Method textCursor:QTextCursor()
		Return QTextCursor._create(bmx_qt_qtextedit_textcursor(qObjectPtr))
	End Method
	
	Method textInteractionFlags:Int()
	' TODO
	End Method
	
	Method toHtml:String()
		Return bmx_qt_qtextedit_tohtml(qObjectPtr)
	End Method
	
	Method toPlainText:String()
		Return bmx_qt_qtextedit_toplaintext(qObjectPtr)
	End Method
	
	Method wordWrapMode:Int()
	' TODO
	End Method

	' SLOTS
	
	Method append(text:String)
		bmx_qt_qtextedit_append(qObjectPtr, text)
	End Method
	
	Method clear()
		bmx_qt_qtextedit_clear(qObjectPtr)
	End Method
	
	Method copy()
		bmx_qt_qtextedit_copy(qObjectPtr)
	End Method
	
	Method cut()
		bmx_qt_qtextedit_cut(qObjectPtr)
	End Method
	
	Method insertHtml(text:String)
		bmx_qt_qtextedit_inserthtml(qObjectPtr, text)
	End Method
	
	Method insertPlainText(text:String)
		bmx_qt_qtextedit_insertplaintext(qObjectPtr, text)
	End Method
	
	Method paste()
		bmx_qt_qtextedit_paste(qObjectPtr)
	End Method
	
	Method redo()
		bmx_qt_qtextedit_redo(qObjectPtr)
	End Method
	
	Method scrollToAnchor(name:String)
		bmx_qt_qtextedit_scrolltoanchor(qObjectPtr, name)
	End Method
	
	Method selectAll()
		bmx_qt_qtextedit_selectall(qObjectPtr)
	End Method
	
	Method setAlignment(a:Int)
		bmx_qt_qtextedit_setalignment(qObjectPtr, a)
	End Method
	
	Method setCurrentFont(f:QFont)
		bmx_qt_qtextedit_setcurrentfont(qObjectPtr, f.qObjectPtr)
	End Method
	
	Method setFontFamily(fontFamily:String)
		bmx_qt_qtextedit_setfontfamily(qObjectPtr, fontFamily)
	End Method
	
	Method setFontItalic(italic:Int)
		bmx_qt_qtextedit_setfontitalic(qObjectPtr, italic)
	End Method
	
	Method setFontPointSize(s:Double)
		bmx_qt_qtextedit_setfontpointsize(qObjectPtr, s)
	End Method
	
	Method setFontUnderline(underline:Int)
		bmx_qt_qtextedit_setfontunderline(qObjectPtr, underline)
	End Method
	
	Method setFontWeight(weight:Int)
		bmx_qt_qtextedit_setfontweight(qObjectPtr, weight)
	End Method
	
	Method setHtml(text:String)
		bmx_qt_qtextedit_sethtml(qObjectPtr, text)
	End Method
	
	Method setPlainText(text:String)
		bmx_qt_qtextedit_setplaintext(qObjectPtr, text)
	End Method
	
	Method setText(text:String)
		bmx_qt_qtextedit_settext(qObjectPtr, text)
	End Method
	
	Method setTextBackgroundColor(c:QColor)
		bmx_qt_qtextedit_settextbackgroundcolor(qObjectPtr, c.qObjectPtr)
	End Method
	
	Method setTextColor(c:QColor)
		bmx_qt_qtextedit_settextcolor(qObjectPtr, c.qObjectPtr)
	End Method
	
	Method undo()
		bmx_qt_qtextedit_undo(qObjectPtr)
	End Method
	
	Method zoomIn(_range:Int = 1)
		bmx_qt_qtextedit_zoomin(qObjectPtr, _range)
	End Method
	
	Method zoomOut(_range:Int = 1)
		bmx_qt_qtextedit_zoomout(qObjectPtr, _range)
	End Method
	
	
	
	' DEFAULT EVENT HANDLERS
	
	' QAbstractScrollArea
	Method scrollContentsBy(dx:Int, dy:Int)
		bmx_qt_qtextedit_default_scrollcontentsby(qObjectPtr, dx, dy)
	End Method
	
	Method viewportEvent:Int(event:QEvent)
		Return bmx_qt_qtextedit_default_viewportevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	' QFrame
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qtextedit_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qtextedit_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qtextedit_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qtextedit_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qtextedit_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qtextedit_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qtextedit_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qtextedit_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qtextedit_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qtextedit_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qtextedit_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qtextedit_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qtextedit_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qtextedit_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qtextedit_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qtextedit_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qtextedit_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qtextedit_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qtextedit_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qtextedit_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qtextedit_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qtextedit_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qtextedit_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qtextedit_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qtextedit_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qtextedit_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qtextedit_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qtextedit_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qtextedit_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qtextedit_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qtextedit_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method



	
	
	' SIGNAL : copyAvailable
	Function _OnCopyAvailable(obj:QTextEdit, yes:Int)
		obj._InvokeSignals("copyAvailable", [String(yes)])
	End Function

	' SIGNAL : currentCharFormatChanged
	Function _OnCurrentCharFormatChanged(obj:QTextEdit, format:Byte Ptr)
		obj._InvokeSignals("currentCharFormatChanged", [QTextCharFormat._create(format)])
	End Function

	' SIGNAL : cursorPositionChanged
	Function _OnCursorPositionChanged(obj:QTextEdit)
		obj._InvokeSignals("cursorPositionChanged", Null)
	End Function

	' SIGNAL : redoAvailable
	Function _OnRedoAvailable(obj:QTextEdit, available:Int)
		obj._InvokeSignals("redoAvailable", [String(available)])
	End Function

	' SIGNAL : selectionChanged
	Function _OnSelectionChanged(obj:QTextEdit)
		obj._InvokeSignals("selectionChanged", Null)
	End Function

	' SIGNAL : textChanged
	Function _OnTextChanged(obj:QTextEdit)
		obj._InvokeSignals("textChanged", Null)
	End Function

	' SIGNAL : undoAvailable
	Function _OnUndoAvailable(obj:QTextEdit, available:Int)
		obj._InvokeSignals("undoAvailable", [String(available)])
	End Function

End Type

