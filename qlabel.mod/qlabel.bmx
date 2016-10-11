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

Module Qt.QLabel

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QLabel Extends QFrame

	Function CreateLabel:QLabel(text:String, parent:QWidget = Null, flags:Int = 0)
		Return New QLabel.Create(text, parent, flags)
	End Function
	
	Method Create:QLabel(text:String, parent:QWidget = Null, flags:Int = 0)
		If parent Then
			qObjectPtr = bmx_qt_qlabel_create(Self, text, parent.qObjectPtr, flags)
		Else
			qObjectPtr = bmx_qt_qlabel_create(Self, text, Null, flags)
		End If
		OnInit()
		Return Self
	End Method

	Method alignment:Int()
		Return bmx_qt_qlabel_alignment(qObjectPtr)
	End Method
	
	Method buddy:QWidget()
		Return QWidget._find(bmx_qt_qlabel_buddy(qObjectPtr))
	End Method
	
	Method hasScaledContents:Int()
		Return bmx_qt_qlabel_hasscaledcontents(qObjectPtr)
	End Method
	
	Method indent:Int()
		Return bmx_qt_qlabel_indent(qObjectPtr)
	End Method
	
	Method margin:Int()
		Return bmx_qt_qlabel_margin(qObjectPtr)
	End Method
	
	'Method movie:QMovie()
	' TODO
	'End Method
	
	Method openExternalLinks:Int()
		Return bmx_qt_qlabel_openexternallinks(qObjectPtr)
	End Method
	
	'Method picture:QPicture()
	' TODO
	'End Method
	
	Method pixmap:QPixmap()
		Return QPixmap._create(bmx_qt_qlabel_pixmap(qObjectPtr))
	End Method
	
	Method setAlignment(alignment:Int)
		bmx_qt_qlabel_setalignment(qObjectPtr, alignment)
	End Method
	
	Method setBuddy(buddy:QWidget)
		If buddy Then
			bmx_qt_qlabel_setbuddy(qObjectPtr, buddy.qObjectPtr)
		Else
			bmx_qt_qlabel_setbuddy(qObjectPtr, Null)
		End If
	End Method
	
	Method setIndent(indent:Int)
		bmx_qt_qlabel_setindent(qObjectPtr, indent)
	End Method
	
	Method setMargin(margin:Int)
		bmx_qt_qlabel_setmargin(qObjectPtr, margin)
	End Method
	
	Method setOpenExternalLinks(open:Int)
		bmx_qt_qlabel_setopenexternallinks(qObjectPtr, open)
	End Method
	
	Method setScaledContents(scaled:Int)
		bmx_qt_qlabel_setscaledcontents(qObjectPtr, scaled)
	End Method
	
	Method setTextFormat(format:Int)
		bmx_qt_qlabel_settextformat(qObjectPtr, format)
	End Method
	
	Method setTextInteractionFlags(flags:Int)
		bmx_qt_qlabel_settextinteractionflags(qObjectPtr, flags)
	End Method
	
	Method setWordWrap(value:Int)
		bmx_qt_qlabel_setwordwrap(qObjectPtr, value)
	End Method
	
	Method text:String()
		Return bmx_qt_qlabel_text(qObjectPtr)
	End Method

	Method textFormat:Int()
		Return bmx_qt_qlabel_textformat(qObjectPtr)
	End Method

	Method textInteractionFlags:Int()
		Return bmx_qt_qlabel_textinteractionflags(qObjectPtr)
	End Method

	Method wordWrap:Int()
		Return bmx_qt_qlabel_wordwrap(qObjectPtr)
	End Method

	Method clear()
		bmx_qt_qlabel_clear(qObjectPtr)
	End Method
	
	'Method setMovie(movie:QMovie)
	' TODO
	'End Method

	Method setNum(num:Int)
		bmx_qt_qlabel_setnum(qObjectPtr, num)
	End Method

	Method setNumDouble(num:Double)
		bmx_qt_qlabel_setnumdouble(qObjectPtr, num)
	End Method

	'Method setPicture(picture:QPicture)
	' TODO
	'End Method

	Method setPixmap(pixmap:QPixmap)
		bmx_qt_qlabel_setpixmap(qObjectPtr, pixmap.qObjectPtr)
	End Method

	Method setText(text:String)
		bmx_qt_qlabel_settext(qObjectPtr, text)
	End Method


	' DEFAULT EVENT HANDLERS
	
	' QLabel
	' QFrame
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qlabel_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qlabel_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qlabel_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qlabel_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qlabel_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qlabel_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qlabel_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qlabel_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qlabel_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qlabel_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qlabel_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qlabel_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qlabel_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qlabel_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qlabel_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qlabel_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qlabel_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qlabel_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qlabel_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qlabel_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qlabel_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qlabel_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qlabel_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qlabel_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qlabel_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qlabel_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qlabel_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qlabel_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qlabel_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qlabel_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qlabel_default_timerevent(qObjectPtr, event.qObjectPtr)
	End Method



	' SIGNAL : linkActivated
	Function _OnLinkActivated(obj:QLabel, text:String)
		obj._InvokeSignals("linkActivated", [text])
	End Function

	' SIGNAL : linkHovered
	Function _OnLinkHovered(obj:QLabel, text:String)
		obj._InvokeSignals("linkHovered", [text])
	End Function

End Type

