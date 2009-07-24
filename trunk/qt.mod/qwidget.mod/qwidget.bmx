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

	Method OnInit()
	End Method


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
	' TODO
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
	
	' overridable
	Method minimumSizeHint(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method minimumWidth:Int()
	' TODO
	End Method
	
	Method move(x:Int, y:Int)
	' TODO
	End Method
	
	Method nativeParentWidget:QWidget()
	' TODO
	End Method
	
	Method nextInFocusChain:QWidget()
	' TODO
	End Method
	
	
	
	
	
	Method stackUnder(w:QWidget)
		bmx_qt_qwidget_stackunder(qObjectPtr, w.qObjectPtr)
	End Method

	Method setFixedSize(w:Int, h:Int)
		bmx_qt_qwidget_setfixedsize(qObjectPtr, w, h)
	End Method
	
	Method setFixedWidth(w:Int)
		bmx_qt_qwidget_setfixedwidth(qObjectPtr, w)
	End Method
	
	Method setLayout(layout:QLayout)
		bmx_qt_qwidget_setlayout(qObjectPtr, layout.qObjectPtr)
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
	
	Method SetFocus(reason:Int)
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

	' SIGNAL : customContextMenuRequested
	Function _OnCustomContextMenuRequested(obj:QWidget, x:Int, y:Int)
		obj._InvokeSignals("customContextMenuRequested", [String(x), String(y)])
	End Function


End Type

Type QLayout Extends QObject

End Type

Type QLayoutItem

	Field qObjectPtr:Byte Ptr

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
