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

Module Qt.QPlainTextEdit

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QPlainTextEdit Extends QAbstractScrollArea

	Rem
	bbdoc: 
	end rem
	Const Mode_NoWrap:Int = 0
	Rem
	bbdoc: 
	end rem
	Const Mode_WidgetWidth:Int = 1


	Function CreatePlainTextEdit:QPlainTextEdit(parent:QWidget = Null)
		Return New QPlainTextEdit.Create(parent)
	End Function
	
	Method Create:QPlainTextEdit(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qplaintextedit_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qplaintextedit_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method anchorAt:String(x:Int, y:Int)
		Return bmx_qt_qplaintextedit_anchorat(qObjectPtr, x, y)
	End Method

	Method backgroundVisible:Int()
		Return bmx_qt_qplaintextedit_backgroundvisible(qObjectPtr)
	End Method
	
	Method blockCount:Int()
		Return bmx_qt_qplaintextedit_blockcount(qObjectPtr)
	End Method
	
	Method canPaste:Int()
		Return bmx_qt_qplaintextedit_canpaste(qObjectPtr)
	End Method
	
	Method centerOnScroll:Int()
		Return bmx_qt_qplaintextedit_centeronscroll(qObjectPtr)
	End Method
	
	Method createStandardContextMenu:QMenu()
	' TODO
	End Method
	
	Method currentCharFormat:QTextCharFormat()
		Return QTextCharFormat._create(bmx_qt_qplaintextedit_currentcharformat(qObjectPtr))
	End Method
	
	Method cursorForPosition:QTextCursor(x:Int, y:Int)
		Return QTextCursor._create(bmx_qt_qplaintextedit_cursorforposition(qObjectPtr, x, y))
	End Method
	
	Method cursorRectCursor(cursor:QTextCursor, x:Int Var, y:Int Var, width:Int Var, height:Int Var)
		bmx_qt_qplaintextedit_cursorrectcursor(qObjectPtr, cursor.qObjectPtr, Varptr x, Varptr y, Varptr width, Varptr height)
	End Method
	
	Method cursorRect(x:Int Var, y:Int Var, width:Int Var, height:Int Var)
		bmx_qt_qplaintextedit_cursorrect(qObjectPtr, Varptr x, Varptr y, Varptr width, Varptr height)
	End Method
	
	Method cursorWidth:Int()
		Return bmx_qt_qplaintextedit_cursorwidth(qObjectPtr)
	End Method
	
	Method document:QTextDocument()
	' TODO
	End Method
	
	Method documentTitle:String()
		Return bmx_qt_qplaintextedit_documenttitle(qObjectPtr)
	End Method
	
	Method ensureCursorVisible()
		bmx_qt_qplaintextedit_ensurecursorvisible(qObjectPtr)
	End Method
	
	'Method QList<QTextEdit::ExtraSelection> extraSelections()
	' TODO
	'End Method
	
	Method find:Int(expr:String, options:Int = 0)
		Return bmx_qt_qplaintextedit_find(qObjectPtr, expr, options)
	End Method
	
	Method isReadOnly:Int()
		Return bmx_qt_qplaintextedit_isreadonly(qObjectPtr)
	End Method
	
	Method isUndoRedoEnabled:Int()
		Return bmx_qt_qplaintextedit_isundoredoenabled(qObjectPtr)
	End Method
	
	Method lineWrapMode:Int()
		Return bmx_qt_qplaintextedit_linewrapmode(qObjectPtr)
	End Method
	
	'Method virtual QVariant loadResource(Type:Int, name:QUrl)
	' TODO
	'End Method
	
	Method maximumBlockCount:Int()
		Return bmx_qt_qplaintextedit_maximumblockcount(qObjectPtr)
	End Method
	
	Method mergeCurrentCharFormat(modifier:QTextCharFormat)
		bmx_qt_qplaintextedit_mergecurrentcharformat(qObjectPtr, modifier.qObjectPtr)
	End Method
	
	Method moveCursor(operation:Int, Mode:Int = QTextCursor.Mode_MoveAnchor)
		bmx_qt_qplaintextedit_movecursor(qObjectPtr, operation, Mode)
	End Method
	
	Method overwriteMode:Int()
		Return bmx_qt_qplaintextedit_overwritemode(qObjectPtr)
	End Method
	
	Method Print(printer:QPrinter)
	' TODO
	End Method
	
	Method setBackgroundVisible(visible:Int)
		bmx_qt_qplaintextedit_setbackgroundvisible(qObjectPtr, visible)
	End Method
	
	Method setCenterOnScroll(enabled:Int)
		bmx_qt_qplaintextedit_setcenteronscrol(qObjectPtr, enabled)
	End Method
	
	Method setCurrentCharFormat(format:QTextCharFormat)
		bmx_qt_qplaintextedit_setcurrentcharformat(qObjectPtr, format.qObjectPtr)
	End Method
	
	Method setCursorWidth(width:Int)
		bmx_qt_qplaintextedit_setcursorwidth(qObjectPtr, width)
	End Method
	
	Method setDocument(document:QTextDocument)
		bmx_qt_qplaintextedit_setdocument(qObjectPtr, document.qObjectPtr)
	End Method
	
	Method setDocumentTitle(title:String)
		bmx_qt_qplaintextedit_setdocumenttitle(qObjectPtr, title)
	End Method
	
	'Method setExtraSelections(QList<QTextEdit::ExtraSelection> & selections)
	' TODO
	'End Method
	
	Method setLineWrapMode(Mode:Int)
		bmx_qt_qplaintextedit_setlinewrapmode(qObjectPtr, Mode)
	End Method
	
	Method setMaximumBlockCount(maximum:Int)
		bmx_qt_qplaintextedit_setmaximumblockcount(qObjectPtr, maximum)
	End Method
	
	Method setOverwriteMode(overwrite:Int)
		bmx_qt_qplaintextedit_setoverwritemode(qObjectPtr, overwrite)
	End Method
	
	Method setReadOnly(ro:Int)
		bmx_qt_qplaintextedit_setreadonly(qObjectPtr, ro)
	End Method
	
	Method setTabChangesFocus(value:Int)
		bmx_qt_qplaintextedit_settabchangesfocus(qObjectPtr, value)
	End Method
	
	Method setTabStopWidth(width:Int)
		bmx_qt_qplaintextedit_settabstopwidth(qObjectPtr, width)
	End Method
	
	Method setTextCursor(cursor:QTextCursor)
		bmx_qt_qplaintextedit_settextcursor(qObjectPtr, cursor.qObjectPtr)
	End Method
	
	Method setTextInteractionFlags(flags:Int)
		bmx_qt_qplaintextedit_settextinteractionflags(qObjectPtr, flags)
	End Method
	
	Method setUndoRedoEnabled(enable:Int)
		bmx_qt_qplaintextedit_setundoredoenabled(qObjectPtr, enable)
	End Method
	
	Method setWordWrapMode(policy:Int)
		bmx_qt_qplaintextedit_setwordwrapmode(qObjectPtr, policy)
	End Method
	
	Method tabChangesFocus:Int()
		Return bmx_qt_qplaintextedit_tabchangesfocus(qObjectPtr)
	End Method
	
	Method tabStopWidth:Int()
		Return bmx_qt_qplaintextedit_tabstopwidth(qObjectPtr)
	End Method
	
	Method textCursor:QTextCursor()
		Return QTextCursor._create(bmx_qt_qplaintextedit_textcursor(qObjectPtr))
	End Method
	
	Method textInteractionFlags:Int()
		Return bmx_qt_qplaintextedit_textinteractionflags(qObjectPtr)
	End Method
	
	Method toPlainText:String()
		Return bmx_qt_qplaintextedit_toplaintext(qObjectPtr)
	End Method
	
	Method wordWrapMode:Int()
		Return bmx_qt_qplaintextedit_wordwrapmode(qObjectPtr)
	End Method

	Method appendHtml(html:String)
		bmx_qt_qplaintextedit_appendhtml(qObjectPtr, html)
	End Method
	
	Method appendPlainText(text:String)
		bmx_qt_qplaintextedit_appendplaintext(qObjectPtr, text)
	End Method
	
	Method centerCursor()
		bmx_qt_qplaintextedit_centercursor(qObjectPtr)
	End Method
	
	Method clear()
		bmx_qt_qplaintextedit_clear(qObjectPtr)
	End Method
	
	Method copy()
		bmx_qt_qplaintextedit_copy(qObjectPtr)
	End Method
	
	Method cut()
		bmx_qt_qplaintextedit_cut(qObjectPtr)
	End Method
	
	Method insertPlainText(text:String)
		bmx_qt_qplaintextedit_insertplaintext(qObjectPtr, text)
	End Method
	
	Method paste()
		bmx_qt_qplaintextedit_paste(qObjectPtr)
	End Method
	
	Method redo()
		bmx_qt_qplaintextedit_redo(qObjectPtr)
	End Method
	
	Method selectAll()
		bmx_qt_qplaintextedit_selectall(qObjectPtr)
	End Method
	
	Method setPlainText(text:String)
		bmx_qt_qplaintextedit_setplaintext(qObjectPtr, text)
	End Method
	
	Method undo()
		bmx_qt_qplaintextedit_undo(qObjectPtr)
	End Method

	Method setViewportMargins(_left:Int, _top:Int, _right:Int, _bottom:Int)
		bmx_qt_qplaintextedit_setviewportmargins(qObjectPtr, _left, _top, _right, _bottom)
	End Method


	' DEFAULT EVENT HANDLERS
	
	' QPlainTextEdit
	' QAbstractScrollArea
	Method scrollContentsBy(dx:Int, dy:Int)
		bmx_qt_qplaintextedit_default_scrollcontentsby(qObjectPtr, dx, dy)
	End Method
	
	Method viewportEvent:Int(event:QEvent)
		Return bmx_qt_qplaintextedit_default_viewportevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	' QFrame
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qplaintextedit_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qplaintextedit_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qplaintextedit_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qplaintextedit_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qplaintextedit_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qplaintextedit_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qplaintextedit_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qplaintextedit_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qplaintextedit_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qplaintextedit_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qplaintextedit_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qplaintextedit_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qplaintextedit_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qplaintextedit_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qplaintextedit_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qplaintextedit_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qplaintextedit_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qplaintextedit_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qplaintextedit_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qplaintextedit_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qplaintextedit_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qplaintextedit_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qplaintextedit_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qplaintextedit_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qplaintextedit_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qplaintextedit_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qplaintextedit_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qplaintextedit_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qplaintextedit_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qplaintextedit_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qplaintextedit_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method



	' SIGNAL : blockCountChanged
	Function _OnBlockCountChanged(obj:QPlainTextEdit, newBlockCount:Int)
		obj._InvokeSignals("blockCountChanged", [String(newBlockCount)])
	End Function

	' SIGNAL : copyAvailable
	Function _OnCopyAvailable(obj:QPlainTextEdit, yes:Int)
		obj._InvokeSignals("copyAvailable", [String(yes)])
	End Function

	' SIGNAL : cursorPositionChanged
	Function _OnCursorPositionChanged(obj:QPlainTextEdit)
		obj._InvokeSignals("cursorPositionChanged", Null)
	End Function

	' SIGNAL : modificationChanged
	Function _OnModificationChanged(obj:QPlainTextEdit, changed:Int)
		obj._InvokeSignals("modificationChanged", [String(changed)])
	End Function

	' SIGNAL : redoAvailable
	Function _OnRedoAvailable(obj:QPlainTextEdit, available:Int)
		obj._InvokeSignals("redoAvailable", [String(available)])
	End Function

	' SIGNAL : selectionChanged
	Function _OnSelectionChanged(obj:QPlainTextEdit)
		obj._InvokeSignals("selectionChanged", Null)
	End Function

	' SIGNAL : textChanged
	Function _OnTextChanged(obj:QPlainTextEdit)
		obj._InvokeSignals("textChanged", Null)
	End Function

	' SIGNAL : undoAvailable
	Function _OnUndoAvailable(obj:QPlainTextEdit, available:Int)
		obj._InvokeSignals("undoAvailable", [String(available)])
	End Function

	' SIGNAL : updateRequest
	Function _OnUpdateRequest(obj:QPlainTextEdit, x:Int, y:Int, width:Int, height:Int, dy:Int)
		obj._InvokeSignals("updateRequest", [String(x), String(y), String(width), String(height), String(dy)])
	End Function

End Type

