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
bbdoc: The base of all user interface objects.
End Rem
Module Qt.QWidget

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
Import "-lQtGui.4"
?win32
Import "-lQtGui4"
?linux
Import "-lQtGui"
?

Import "common.bmx"


Type QWidget Extends QObject

	Method isWidget:Int()
		Return True
	End Method

	Function CreateWidget:QWidget(parent:QWidget = Null, flags:Int = 0)
		Return New QWidget._Create(parent, flags)
	End Function
	
	Method _Create:QWidget(parent:QWidget = Null, flags:Int = 0)
		If parent Then
			qObjectPtr = bmx_qt_qwidget_create(Self, parent.qObjectPtr, flags)
		Else
			qObjectPtr = bmx_qt_qwidget_create(Self, Null, flags)
		End If
		OnInit()
		Return Self
	End Method
	
	Function __create:QWidget(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWidget = New QWidget
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QWidget(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QWidget = QWidget(qfind(qObjectPtr))
			If Not widget Then
				Return QWidget.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Method OnInit()
	End Method

	Method acceptDrops:Int()
		Return bmx_qt_qwidget_acceptdrops(qObjectPtr)
	End Method
	
	Method accessibleDescription:String()
		Return bmx_qt_qwidget_accessibledescription(qObjectPtr)
	End Method
	
	Method accessibleName:String()
		Return bmx_qt_qwidget_accessiblename(qObjectPtr)
	End Method
	
	'method actions:QAction[]()
	'' TODO
	'end method
	
	Method ActivateWindow()
		bmx_qt_qwidget_activatewindow(qObjectPtr)
	End Method
	
	Method addAction:QAction(action:Object)
		If QAction(action) Then
			bmx_qt_qwidget_addaction(qObjectPtr, QAction(action).qObjectPtr)
			Return QAction(action)
		End If
	End Method

	Method adjustSize()
		bmx_qt_qwidget_adjustsize(qObjectPtr)
	End Method
	
	Method autoFillBackground:Int()
		Return bmx_qt_qwidget_autofillbackground(qObjectPtr)
	End Method
	
	Method backgroundRole:Int()
		Return bmx_qt_qwidget_backgroundrole(qObjectPtr)
	End Method
	
	Method baseSize(w:Int Var, h:Int Var)
		bmx_qt_qwidget_basesize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method childAt:QWidget(x:Int, y:Int )
		Return QWidget._find(bmx_qt_qwidget_childat(qObjectPtr, x, y))
	End Method
	
	Method childrenRect:QRect()
		Return QRect._create(bmx_qt_qwidget_childrenrect(qObjectPtr))
	End Method
	
	Method childrenRegion:QRegion()
		Return QRegion._create(bmx_qt_qwidget_childrenregion(qObjectPtr))
	End Method
	
	Method clearFocus()
		bmx_qt_qwidget_clearfocus(qObjectPtr)
	End Method
	
	Method clearMask()
		bmx_qt_qwidget_clearmask(qObjectPtr)
	End Method
	
	Method contentsRect:QRect()
		Return QRect._create(bmx_qt_qwidget_contentsrect(qObjectPtr))
	End Method
	

	Method font:QFont()
		Return QFont._create(bmx_qt_qwidget_font(qObjectPtr))
	End Method
	
	Method fontMetrics:QFontMetrics()
		Return QFontMetrics._create(bmx_qt_qwidget_fontmetrics(qObjectPtr))
	End Method

	Method frameGeometry:QRect()
		Return QRect._create(bmx_qt_qwidget_framegeometry(qObjectPtr))
	End Method
	
	Method frameSize(w:Int Var, h:Int Var)
		bmx_qt_qwidget_framesize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method geometry:QRect()
		Return QRect._create(bmx_qt_qwidget_geometry(qObjectPtr))
	End Method
	
	Method hasEditFocus:Int()
	' TODO
	End Method
	
	Method hasFocus:Int()
	' TODO
	End Method
	
	Method hasMouseTracking:Int()
	' TODO
	End Method
	
	Method height:Int()
		Return bmx_qt_qwidget_height(qObjectPtr)
	End Method
	
	Method heightForWidth:Int(w:Int)
	' TODO
	End Method

	'Method inputContext:QInputContext()
	' TODO
	'End Method
	
	'Method inputMethodQuery:QVariant(query:Int)
	' TODO
	'End Method

	'Method insertAction(before:QAction, action:QAction)
	' TODO
	'End Method

	'Method insertActions(before:QAction, actions:QAction([])
	' TODO
	'End Method

	Method isActiveWindow:Int()
	' TODO
	End Method
	
	Method isAncestorOf:Int(child:QWidget)
	' TODO
	End Method
	
	Method isEnabled:Int()
	' TODO
	End Method
	
	Method isEnabledTo:Int(ancestor:QWidget)
	' TODO
	End Method
	
	Method isFullScreen:Int()
	' TODO
	End Method
	
	Method isHidden:Int()
	' TODO
	End Method
	
	Method isMaximized:Int()
	' TODO
	End Method
	
	Method isMinimized:Int()
	' TODO
	End Method
	
	Method isModal:Int()
	' TODO
	End Method
	
	Method isVisible:Int()
	' TODO
	End Method
	
	Method isVisibleTo:Int(ancestor:QWidget)
	' TODO
	End Method
	
	Method isWindow:Int()
	' TODO
	End Method
	
	Method isWindowModified:Int()
	' TODO
	End Method


	Method layout:QLayout()
	' TODO
	End Method
	
	Method layoutDirection:Int()
	' TODO
	End Method
	
	Method locale:QLocale()
		Return QLocale._create(bmx_qt_qwidget_locale(qObjectPtr))
	End Method
	
	Method macCGHandle:Byte Ptr()
	' TODO
	End Method
	
	Method macQDHandle:Byte Ptr()
	' TODO
	End Method
	
	Method mapFrom(parent:QWidget, x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapFromGlobal(x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapFromParent(x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapTo(parent:QWidget, x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapToGlobal(x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mapToParent(x:Int, y:Int, toX:Int Var, toY:Int Var)
	' TODO
	End Method
	
	Method mask:QRegion()
	' TODO
	End Method
	
	Method maximumHeight:Int()
	' TODO
	End Method
	
	Method maximumSize(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method maximumWidth:Int()
	' TODO
	End Method
	
	Method minimumHeight:Int()
	' TODO
	End Method
	
	Method minimumSize(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method minimumWidth:Int()
	' TODO
	End Method
	
	Method move(x:Int, y:Int)
		bmx_qt_qwidget_move(qObjectPtr, x, y)
	End Method
	
	Method nativeParentWidget:QWidget()
	' TODO
	End Method
	
	Method nextInFocusChain:QWidget()
	' TODO
	End Method
	
	Method parentWidget:QWidget()
		Return QWidget._find(bmx_qt_qwidget_parentwidget(qObjectPtr))
	End Method
	
	Method pos(x:Int Var, y:Int Var)
		bmx_qt_qwidget_pos(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method rect:QRect()
		Return QRect._create(bmx_qt_qwidget_rect(qObjectPtr))
	End Method
	
	Method resize(w:Int, h:Int)
		bmx_qt_qwidget_resize(qObjectPtr, w, h)
	End Method
	
	Method setAttribute(attribute:Int)
		bmx_qt_qwidget_setattribute(qObjectPtr, attribute)
	End Method
	
	Method setContextMenuPolicy(policy:Int)
		bmx_qt_qwidget_setcontextmenupolicy(qObjectPtr, policy)
	End Method
	
	Method setFixedSize(w:Int, h:Int)
		bmx_qt_qwidget_setfixedsize(qObjectPtr, w, h)
	End Method
	
	Method setFixedWidth(w:Int)
		bmx_qt_qwidget_setfixedwidth(qObjectPtr, w)
	End Method

	Method setFocusPolicy(policy:Int)
	' TODO
	End Method
	
	Method setFocusProxy(w:QWidget)
	' TODO
	End Method

	Method setFont(font:QFont)
		bmx_qt_qwidget_setfont(qObjectPtr, font.qObjectPtr)
	End Method
	
	Method setForegroundRole(role:Int)
	' TODO
	End Method
	
	Method setGeometryRect(rect:QRect)
	' TODO
	End Method
	
	Method setGeometry(x:Int, y:Int, w:Int, h:Int)
	' TODO
	End Method
	
	'Method setInputContext(context:QInputContext)
	' TODO
	'End Method

	Method setLayout(layout:QLayout)
		bmx_qt_qwidget_setlayout(qObjectPtr, layout.qObjectPtr)
	End Method

	Method setLayoutDirection(direction:Int)
	' TODO
	End Method
	
	Method setLocale(locale:QLocale)
	' TODO
	End Method
	
	'Method setMask(bitmap:QBitmap)
	' TODO
	'End Method
	
	Method setMaskRegion(region:QRegion)
	' TODO
	End Method
	
	Method setMaximumHeight(maxh:Int)
	' TODO
	End Method
	
	Method setMaximumSize(w:Int, h:Int)
	' TODO
	End Method
	
	Method setMaximumWidth(maxw:Int)
	' TODO
	End Method
	
	Method setMinimumHeight(minh:Int)
	' TODO
	End Method
	
	Method setMinimumSize(w:Int, h:Int)
	' TODO
	End Method
	
	Method setMinimumWidth(minw:Int)
	' TODO
	End Method
	
	Method setMouseTracking(enable:Int)
	' TODO
	End Method

	'Method setPalette(p:QPalette)
	' TODO
	'End Method
	
	Method setParent(parent:QWidget)
	' TODO
	End Method
	
	Method setShortcutAutoRepeat(id:Int, enable:Int = True)
	' TODO
	End Method
	
	Method setShortcutEnabled(id:Int, enable:Int = True)
	' TODO
	End Method
	
	Method setSizeIncrement(w:Int, h:Int)
	' TODO
	End Method

	Method setSizePolicy(policy:QSizePolicy)
	' TODO
	End Method
	
	Method setSizePolicyHV(horizontalPolicy:Int, verticalPolicy:Int)
		bmx_qt_qwidget_setsizepolicyhv(qObjectPtr, horizontalPolicy, verticalPolicy)
	End Method

	Method setStatusTip(tip:String)
	' TODO
	End Method

	'Method setStyle(style:QStyle)
	' TODO
	'End Method

	Method setToolTip(text:String)
		bmx_qt_qwidget_settooltip(qObjectPtr, text)
	End Method

	Method setUpdatesEnabled(enable:Int)
	' TODO
	End Method
	
	Method setWhatsThis(text:String)
	' TODO
	End Method
	
	Method setWindowFilePath(filePath:String)
	' TODO
	End Method
	
	Method setWindowFlags(flags:Int)
	' TODO
	End Method
	
	Method setWindowIcon(icon:QIcon)
	' TODO
	End Method
	
	Method setWindowIconText(text:String)
	' TODO
	End Method
	
	Method setWindowModality(windowModality:Int)
	' TODO
	End Method
	
	Method setWindowOpacity(level:Double)
	' TODO
	End Method
	
	Method setWindowRole(role:String)
	' TODO
	End Method
	
	Method setWindowState(windowState:Int)
	' TODO
	End Method

	Method size(w:Int Var, h:Int Var)
		bmx_qt_qwidget_size(qObjectPtr, Varptr w, Varptr h)
	End Method

	Method sizeIncrement(w:Int Var, h:Int Var)
		bmx_qt_qwidget_sizeincrement(qObjectPtr, Varptr w, Varptr h)
	End Method

	Method sizePolicy:QSizePolicy()
		Return QSizePolicy._create(bmx_qt_qwidget_sizepolicy(qObjectPtr))
	End Method

	Method stackUnder(w:QWidget)
		bmx_qt_qwidget_stackunder(qObjectPtr, w.qObjectPtr)
	End Method

	Method whatsThis:String()
	' TODO
	End Method
	
	Method width:Int()
		Return bmx_qt_qwidget_width(qObjectPtr)
	End Method
	
	Method winId:Int()
		Return bmx_qt_qwidget_winid(qObjectPtr)
	End Method
	
	Method window:QWidget()
		Return QWidget._find(bmx_qt_qwidget_window(qObjectPtr))
	End Method
	
	Method windowFilePath:String()
		Return bmx_qt_qwidget_windowfilepath(qObjectPtr)
	End Method
	
	Method windowFlags:Int()
		Return bmx_qt_qwidget_windowflags(qObjectPtr)
	End Method
	
	Method windowIcon:QIcon()
		Return QIcon._create(bmx_qt_qwidget_windowicon(qObjectPtr))
	End Method
	
	Method windowIconText:String()
		Return bmx_qt_qwidget_windowicontext(qObjectPtr)
	End Method
	
	Method windowModality:Int()
		Return bmx_qt_qwidget_windowmodality(qObjectPtr)
	End Method
	
	Method windowOpacity:Double()
		Return bmx_qt_qwidget_windowopacity(qObjectPtr)
	End Method
	
	Method windowRole:String()
		Return bmx_qt_qwidget_windowrole(qObjectPtr)
	End Method
	
	Method windowState:Int()
		Return bmx_qt_qwidget_windowstate(qObjectPtr)
	End Method
	
	'Method windowSurface:QWindowSurface()
	' TODO
	'End Method
	
	Method windowTitle:String()
		Return bmx_qt_qwidget_windowtitle(qObjectPtr)
	End Method
	
	Method windowType:Int()
		Return bmx_qt_qwidget_windowtype(qObjectPtr)
	End Method
	
	Method x:Int()
		Return bmx_qt_qwidget_x(qObjectPtr)
	End Method
	
	Method y:Int()
		Return bmx_qt_qwidget_y(qObjectPtr)
	End Method
	

	' SLOTS
	
	Method close()
		bmx_qt_qwidget_close(qObjectPtr)
	End Method

	Method hide()
		bmx_qt_qwidget_hide(qObjectPtr)
	End Method

	Method raise()
		bmx_qt_qwidget_raise(qObjectPtr)
	End Method
	
	Method repaint()
		bmx_qt_qwidget_repaint(qObjectPtr)
	End Method
	
	Method setDisabled(disable:Int)
		bmx_qt_qwidget_setdisabled(qObjectPtr, disable)
	End Method
	
	Method setEnabled(value:Int)
		bmx_qt_qwidget_setenabled(qObjectPtr, value)
	End Method
	
	Method SetFocus(reason:Int = Qt_OtherFocusReason)
		bmx_qt_qwidget_setfocus(qObjectPtr, reason)
	End Method
	
	Method setHidden(hidden:Int)
		bmx_qt_qwidget_sethidden(qObjectPtr, hidden)
	End Method
	
	Method setStyleSheet(styleSheet:String)
		bmx_qt_qwidget_setstylesheet(qObjectPtr, styleSheet)
	End Method
	
	Method setVisible(visible:Int)
		bmx_qt_qwidget_setvisible(qObjectPtr, visible)
	End Method
	
	Method setWindowModified(value:Int)
		bmx_qt_qwidget_setwindowmodified(qObjectPtr, value)
	End Method
	

	Method setWindowTitle(title:String)
		bmx_qt_qwidget_setwindowtitle(qObjectPtr, title)
	End Method

	Method show()
		bmx_qt_qwidget_show(qObjectPtr)
	End Method
	
	Method showFullScreen()
		bmx_qt_qwidget_showfullscreen(qObjectPtr)
	End Method
	
	Method showMaximized()
		bmx_qt_qwidget_showmaximized(qObjectPtr)
	End Method
	
	Method showMinimized()
		bmx_qt_qwidget_showminimized(qObjectPtr)
	End Method
	
	Method showNormal()
		bmx_qt_qwidget_shownormal(qObjectPtr)
	End Method
	
	Method update()
		bmx_qt_qwidget_update(qObjectPtr)
	End Method



	Rem
	bbdoc: 
	End Rem
	Method paintEvent(event:QPaintEvent)
	End Method
	
	Function _OnPaintEvent(obj:QWidget, event:Byte Ptr)
		obj.paintEvent(QPaintEvent._create(event))
	End Function
	
	Method sizeHint(w:Int Var, h:Int Var)
	End Method
	
	Function _SizeHint(obj:QWidget, w:Int Ptr, h:Int Ptr)
		Local width:Int, height:Int
		obj.sizeHint(width, height)
		w[0] = width
		h[0] = height
	End Function

	Method minimumSizeHint(w:Int Var, h:Int Var)
	End Method
	
	Function _MinimumSizeHint(obj:QWidget, w:Int Ptr, h:Int Ptr)
		Local width:Int, height:Int
		obj.minimumSizeHint(width, height)
		w[0] = width
		h[0] = height
	End Function
	
	Rem
	bbdoc: 
	End Rem
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qwidget_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Function _OnMouseDoubleClickEvent(obj:QWidget, event:Byte Ptr)
		obj.mouseMoveEvent(QMouseEvent._create(event))
	End Function

	Rem
	bbdoc: 
	End Rem
	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qwidget_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Function _OnMouseMoveEvent(obj:QWidget, event:Byte Ptr)
		obj.mouseMoveEvent(QMouseEvent._create(event))
	End Function

	Rem
	bbdoc: 
	End Rem
	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qwidget_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Function _OnMousePressEvent(obj:QWidget, event:Byte Ptr)
		obj.mousePressEvent(QMouseEvent._create(event))
	End Function

	Rem
	bbdoc: 
	End Rem
	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qwidget_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Function _OnMouseReleaseEvent(obj:QWidget, event:Byte Ptr)
		obj.mouseReleaseEvent(QMouseEvent._create(event))
	End Function

	Method actionEvent(event:QActionEvent)
		bmx_qt_qwidget_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnActionEvent(obj:QWidget, event:Byte Ptr)
		obj.actionEvent(QActionEvent._create(event))
	End Function
	
	Method changeEvent(event:QEvent)
		bmx_qt_qwidget_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnChangeEvent(obj:QWidget, event:Byte Ptr)
		obj.changeEvent(QEvent._create(event))
	End Function
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qwidget_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnCloseEvent(obj:QWidget, event:Byte Ptr)
		obj.closeEvent(QCloseEvent._create(event))
	End Function
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qwidget_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnContextMenuEvent(obj:QWidget, event:Byte Ptr)
		obj.contextMenuEvent(QContextMenuEvent._create(event))
	End Function
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qwidget_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnDragEnterEvent(obj:QWidget, event:Byte Ptr)
		obj.dragEnterEvent(QDragEnterEvent._create(event))
	End Function
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qwidget_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnDragLeaveEvent(obj:QWidget, event:Byte Ptr)
		obj.dragLeaveEvent(QDragLeaveEvent._create(event))
	End Function
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qwidget_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnDragMoveEvent(obj:QWidget, event:Byte Ptr)
		obj.dragMoveEvent(QDragMoveEvent._create(event))
	End Function
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qwidget_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnDropEvent(obj:QWidget, event:Byte Ptr)
		obj.dropEvent(QDropEvent._create(event))
	End Function
	
	Method enterEvent(event:QEvent)
		bmx_qt_qwidget_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnEnterEvent(obj:QWidget, event:Byte Ptr)
		obj.enterEvent(QEvent._create(event))
	End Function
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qwidget_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnFocusInEvent(obj:QWidget, event:Byte Ptr)
		obj.focusInEvent(QFocusEvent._create(event))
	End Function
	
	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qwidget_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnFocusOutEvent(obj:QWidget, event:Byte Ptr)
		obj.focusOutEvent(QFocusEvent._create(event))
	End Function
	
	Method hideEvent(event:QHideEvent)
		bmx_qt_qwidget_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnHideEvent(obj:QWidget, event:Byte Ptr)
		obj.hideEvent(QHideEvent._create(event))
	End Function
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qwidget_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnInputMethodEvent(obj:QWidget, event:Byte Ptr)
		obj.inputMethodEvent(QInputMethodEvent._create(event))
	End Function
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qwidget_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnKeyPressEvent(obj:QWidget, event:Byte Ptr)
		obj.keyPressEvent(QKeyEvent._create(event))
	End Function
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qwidget_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnKeyReleaseEvent(obj:QWidget, event:Byte Ptr)
		obj.keyReleaseEvent(QKeyEvent._create(event))
	End Function
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qwidget_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnLeaveEvent(obj:QWidget, event:Byte Ptr)
		obj.leaveEvent(QEvent._create(event))
	End Function
	
	Method moveEvent(event:QMoveEvent)
		bmx_qt_qwidget_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnMoveEvent(obj:QWidget, event:Byte Ptr)
		obj.moveEvent(QMoveEvent._create(event))
	End Function
	
	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qwidget_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnResizeEvent(obj:QWidget, event:Byte Ptr)
		obj.resizeEvent(QResizeEvent._create(event))
	End Function
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qwidget_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnShowEvent(obj:QWidget, event:Byte Ptr)
		obj.showEvent(QShowEvent._create(event))
	End Function
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qwidget_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnTabletEvent(obj:QWidget, event:Byte Ptr)
		obj.tabletEvent(QTabletEvent._create(event))
	End Function
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qwidget_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Function _OnWheelEvent(obj:QWidget, event:Byte Ptr)
		obj.wheelEvent(QWheelEvent._create(event))
	End Function
	
	' SIGNAL : customContextMenuRequested
	Function _OnCustomContextMenuRequested(obj:QWidget, x:Int, y:Int)
		obj._InvokeSignals("customContextMenuRequested", [String(x), String(y)])
	End Function

End Type

Type QLayout Extends QObject

	Rem
	bbdoc: The main widget's minimum size is set to minimumSize(), unless the widget already has a minimum size.
	end rem
	Const SetDefaultConstraint:Int = 0
	Rem
	bbdoc: The main widget's size is set to sizeHint(); it cannot be resized at all.
	end rem
	Const SetFixedSize:Int = 3
	Rem
	bbdoc: The main widget's minimum size is set to minimumSize(); it cannot be smaller.
	end rem
	Const SetMinimumSize:Int = 2
	Rem
	bbdoc: The main widget's maximum size is set to maximumSize(); it cannot be larger.
	end rem
	Const SetMaximumSize:Int = 4
	Rem
	bbdoc: The main widget's minimum size is set to minimumSize() and its maximum size is set to maximumSize().
	end rem
	Const SetMinAndMaxSize:Int = 5
	Rem
	bbdoc: The widget is not constrained.
	end rem
	Const SetNoConstraint:Int = 1

	
	Method setSizeConstraint(constraint:Int)
		bmx_qt_qlayout_setsizeconstraint(qObjectPtr, constraint)
	End Method
	
End Type

Type QLayoutItem

	Field qObjectPtr:Byte Ptr
	
	Function _create:QLayoutItem(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QLayoutItem = New QLayoutItem
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method alignment:Int()
	End Method
	
	Method controlTypes:Int()
	End Method
	
	Method expandingDirections:Int()
	End Method
	
	Method geometry:QRect()
	End Method
	
	Method hasHeightForWidth:Int()
	End Method
	
	Method heightForWidth:Int(w:Int)
	End Method
	
	Method invalidate()
	End Method
	
	Method isEmpty:Int()
	End Method
	
	Method layout:QLayout()
	End Method
	
	Method maximumSize(w:Int Var, h:Int Var)
	End Method
	
	Method minimumHeightForWidth:Int(w:Int)
	End Method
	
	Method minimumSize(w:Int Var, h:Int Var)
	End Method
	
	Method setAlignment(alignment:Int)
	End Method
	
	Method setGeometry(r:QRect)
	End Method
	
	Method sizeHint(w:Int Var, h:Int Var)
	End Method
	
	Method spacerItem:QSpacerItem()
	End Method
	
	Method widget:QWidget()
	End Method
	
	
End Type

Type QSpacerItem Extends QLayoutItem

End Type

Type QWidgetItem Extends QLayoutItem

End Type


Type QAction Extends QObject

	Function _create:QAction(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QAction = New QAction
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QAction(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QAction = QAction(qfind(qObjectPtr))
			If Not widget Then
				Return QAction._create(qObjectPtr)
			End If
			Return widget
		End If
	End Function
	
	Function CreateAction:QAction(text:String, parent:QObject)
		Return New QAction.Create(text, parent)
	End Function
	
	Method Create:QAction(text:String, parent:QObject)
		qObjectPtr = bmx_qt_qaction_create(Self, text, parent.qObjectPtr)
		Return Self
	End Method

	Method CreateWithIcon:QAction(icon:QIcon, text:String, parent:QObject)
		qObjectPtr = bmx_qt_qaction_createwithicon(Self, icon.qObjectPtr, text, parent.qObjectPtr)
		Return Self
	End Method

	Method actionGroup:QActionGroup()
		Return QActionGroup._create(bmx_qt_qaction_actiongroup(qObjectPtr))
	End Method
	
	Method activate(event:Int)
		bmx_qt_qaction_activate(qObjectPtr, event)
	End Method
	
	'QList<QGraphicsWidget *> associatedGraphicsWidgets()
	
	'QList<QWidget *> associatedWidgets()
	
	Method autoRepeat:Int()
		Return bmx_qt_qaction_autorepeat(qObjectPtr)
	End Method
	
	Method data:Object()
		Return bmx_qt_qaction_data(qObjectPtr)
	End Method
	
	Method font:QFont()
		Return QFont._create(bmx_qt_qaction_font(qObjectPtr))
	End Method
	
	Method icon:QIcon()
		' TODO
		'Return bmx_qt_qaction_icon(qObjectPtr)
	End Method
	
	Method iconText:String()
		Return bmx_qt_qaction_icontext(qObjectPtr)
	End Method
	
	Method isCheckable:Int()
		Return bmx_qt_qaction_ischeckable(qObjectPtr)
	End Method
	
	Method isChecked:Int()
		Return bmx_qt_qaction_ischecked(qObjectPtr)
	End Method
	
	Method isEnabled:Int()
		Return bmx_qt_qaction_isenabled(qObjectPtr)
	End Method
	
	Method isIconVisibleInMenu:Int()
		Return bmx_qt_qaction_isiconvisibleinmenu(qObjectPtr)
	End Method
	
	Method isSeparator:Int()
		Return bmx_qt_qaction_isseparator(qObjectPtr)
	End Method
	
	Method isVisible:Int()
		Return bmx_qt_qaction_isvisible(qObjectPtr)
	End Method
	
	' Note : moved to Qt.QMenu, because of referencing issues.
	'Method menu:QMenu()
	'	Return QMenu._find(bmx_qt_qaction_menu(qObjectPtr))
	'End Method
	
	Method menuRole:Int()
		Return bmx_qt_qaction_menurole(qObjectPtr)
	End Method
	
	Method parentWidget:QWidget()
		Return QWidget._find(bmx_qt_qaction_parentwidget(qObjectPtr))
	End Method
	
	Method setActionGroup(group:QActionGroup)
		bmx_qt_qaction_setactiongroup(qObjectPtr, group.qObjectPtr)
	End Method
	
	Method setAutoRepeat(value:Int)
		bmx_qt_qaction_setautorepeat(qObjectPtr, value)
	End Method
	
	Method setCheckable(value:Int)
		bmx_qt_qaction_setcheckable(qObjectPtr, value)
	End Method
	
	Method setData(userData:Object)
		bmx_qt_qaction_setdata(qObjectPtr, userData)
	End Method
	
	Method setFont(font:QFont)
		bmx_qt_qaction_setfont(qObjectPtr, font.qObjectPtr)
	End Method
	
	Method setIcon(icon:QIcon)
		' TODO
		'bmx_qt_qaction_seticon(qObjectPtr)
	End Method
	
	Method setIconText(text:String)
		bmx_qt_qaction_seticontext(qObjectPtr, text)
	End Method
	
	Method setIconVisibleInMenu(visible:Int)
		bmx_qt_qaction_seticonvisibleinmenu(qObjectPtr, visible)
	End Method
	
	' Note : moved to Qt.QMenu, because of referencing issues.
	'Method setMenu(menu:QMenu)
	'	bmx_qt_qaction_setmenu(qObjectPtr, menu.qObjectPtr)
	'End Method
	
	Method setMenuRole(menuRole:Int)
		bmx_qt_qaction_setmenurole(qObjectPtr, menuRole)
	End Method
	
	Method setSeparator(value:Int)
		bmx_qt_qaction_setseparator(qObjectPtr, value)
	End Method
	
	Method setShortcutContext(context:Int)
		bmx_qt_qaction_setshortcutcontext(qObjectPtr, context)
	End Method
	
	'method setShortcuts(QList<QKeySequence> & shortcuts)
	
	Method setShortcuts(key:Int)
		bmx_qt_qaction_setshortcuts(qObjectPtr, key)
	End Method
	
	Method setStatusTip(statusTip:String)
		bmx_qt_qaction_setstatustip(qObjectPtr, statusTip)
	End Method
	
	Method setText(text:String)
		bmx_qt_qaction_settext(qObjectPtr, text)
	End Method
	
	Method setToolTip(tip:String)
		bmx_qt_qaction_settooltip(qObjectPtr, tip)
	End Method
	
	Method setWhatsThis(what:String)
		bmx_qt_qaction_setwhatsthis(qObjectPtr, what)
	End Method
	
	Method shortcut:String()
		Return bmx_qt_qaction_shortcut(qObjectPtr)
	End Method
	
	Method shortcutContext:Int()
		Return bmx_qt_qaction_shortcutcontext(qObjectPtr)
	End Method
	
	'QList<QKeySequence> shortcuts()
	
	Method showStatusText:Int(widget:QWidget = Null)
		If widget Then
			Return bmx_qt_qaction_showstatustext(qObjectPtr, widget.qObjectPtr)
		Else
			Return bmx_qt_qaction_showstatustext(qObjectPtr, Null)
		End If
	End Method
	
	Method statusTip:String()
		Return bmx_qt_qaction_statustip(qObjectPtr)
	End Method
	
	Method text:String()
		Return bmx_qt_qaction_text(qObjectPtr)
	End Method
	
	Method toolTip:String()
		Return bmx_qt_qaction_tooltip(qObjectPtr)
	End Method
	
	Method whatsThis:String() 
		Return bmx_qt_qaction_whatsthis(qObjectPtr)
	End Method
	
	Method setShortcut(sequence:String)
		bmx_qt_qaction_setshortcut(qObjectPtr, sequence)
	End Method

	Method hover()
		bmx_qt_qaction_hover(qObjectPtr)
	End Method
	
	Method setChecked(value:Int)
		bmx_qt_qaction_setchecked(qObjectPtr, value)
	End Method
	
	Method setDisabled(value:Int)
		bmx_qt_qaction_setdisabled(qObjectPtr, value)
	End Method
	
	Method setEnabled(value:Int)
		bmx_qt_qaction_setenabled(qObjectPtr, value)
	End Method
	
	Method setVisible(value:Int)
		bmx_qt_qaction_setvisible(qObjectPtr, value)
	End Method
	
	Method toggle()
		bmx_qt_qaction_toggle(qObjectPtr)
	End Method
	
	Method trigger()
		bmx_qt_qaction_trigger(qObjectPtr)
	End Method
	
	' SIGNAL : changed
	Function _OnChanged(obj:QAction)
		obj._InvokeSignals("changed", Null)
	End Function

	' SIGNAL : hovered
	Function _OnHovered(obj:QAction)
		obj._InvokeSignals("hovered", Null)
	End Function

	' SIGNAL : toggled
	Function _OnToggled(obj:QAction, checked:Int)
		obj._InvokeSignals("toggled", [String(checked)])
	End Function

	' SIGNAL : triggered
	Function _OnTriggered(obj:QAction, checked:Int)
		obj._InvokeSignals("triggered", [String(checked)])
	End Function

End Type

Type QActionGroup Extends QObject

	Function _create:QActionGroup(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QActionGroup = New QActionGroup
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QActionGroup(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QActionGroup = QActionGroup(qfind(qObjectPtr))
			If Not widget Then
				Return QActionGroup._create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Function CreateActionGroup:QActionGroup(parent:QObject)
		Return New QActionGroup.Create(parent)
	End Function
	
	Method Create:QActionGroup(parent:QObject)
		qObjectPtr = bmx_qt_qactiongroup_create(Self, parent.qObjectPtr)
		Return Self
	End Method
	
	Method AddAction:QAction(action:QAction)
		Return QAction._find(bmx_qt_qactiongroup_addaction(qObjectPtr, action.qObjectPtr))
	End Method
	
	Method AddActionText:QAction(text:String)
		Return QAction._find(bmx_qt_qactiongroup_addactiontext(qObjectPtr, text))
	End Method
	
	Method checkedAction:QAction()
		Return QAction._find(bmx_qt_qactiongroup_checkedaction(qObjectPtr))
	End Method
	
	Method isEnabled:Int()
		Return bmx_qt_qactiongroup_isenabled(qObjectPtr)
	End Method
	
	Method isExclusive:Int()
		Return bmx_qt_qactiongroup_isexclusive(qObjectPtr)
	End Method
	
	Method isVisible:Int()
		Return bmx_qt_qactiongroup_isvisible(qObjectPtr)
	End Method
	
	Method removeAction(action:QAction)
		bmx_qt_qactiongroup_removeaction(qObjectPtr, action.qObjectPtr)
	End Method

	Method setDisabled(value:Int)
		bmx_qt_qactiongroup_setdisabled(qObjectPtr, value)
	End Method
	
	Method setEnabled(value:Int)
		bmx_qt_qactiongroup_setenabled(qObjectPtr, value)
	End Method
	
	Method setExclusive(value:Int)
		bmx_qt_qactiongroup_setexclusive(qObjectPtr, value)
	End Method
	
	Method setVisible(value:Int)
		bmx_qt_qactiongroup_setvisible(qObjectPtr, value)
	End Method

	' SIGNAL : hovered
	Function _OnHovered(obj:QActionGroup, action:Byte Ptr)
		obj._InvokeSignals("hovered", [QAction._find(action)])
	End Function

	' SIGNAL : triggered
	Function _OnTriggered(obj:QActionGroup, action:Byte Ptr)
		obj._InvokeSignals("triggered", [QAction._find(action)])
	End Function

End Type

Type QActionEvent Extends QEvent

	Function _create:QActionEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QActionEvent = New QActionEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QDropEvent Extends QEvent

	Function _create:QDropEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QDropEvent = New QDropEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QDragMoveEvent Extends QDropEvent

	Function _create:QDragMoveEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QDragMoveEvent = New QDragMoveEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QDragEnterEvent Extends QDragMoveEvent

	Function _create:QDragEnterEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QDragEnterEvent = New QDragEnterEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

Type QDragLeaveEvent Extends QEvent

	Function _create:QDragLeaveEvent(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QDragLeaveEvent = New QDragLeaveEvent
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

