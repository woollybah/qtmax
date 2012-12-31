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

Module Qt.QApplication

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QApplication Extends QCoreApplication

	Function CreateApplication:QApplication()
		Return New QApplication.Create()
	End Function
	
	Method Create:QApplication()
		qObjectPtr = bmx_qt_qapplication_create(Self)
		qApp = Self
		Return Self
	End Method

	Method exec:Int()
		Return bmx_qt_qapplication_exec()
	End Method

	Method aboutQt()
		bmx_qt_qapplication_aboutqt(qObjectPtr)
	End Method
	
	Method closeAllWindows()
		bmx_qt_qapplication_closeallwindows(qObjectPtr)
	End Method
	
	Method setStyleSheet(sheet:String)
		bmx_qt_qapplication_setstylesheet(qObjectPtr, sheet)
	End Method


	Function activeModalWidget:QWidget()
		Return QWidget._find(bmx_qt_qapplication_activemodalwidget())
	End Function
	
	Function activePopupWidget:QWidget()
		Return QWidget._find(bmx_qt_qapplication_activepopupwidget())
	End Function
	
	Function activeWindow:QWidget()
		Return QWidget._find(bmx_qt_qapplication_activewindow())
	End Function
	
	Function alert(widget:QWidget, msec:Int = 0)
		bmx_qt_qapplication_alert(widget.qObjectPtr, msec)
	End Function
	
	'Function allWidgets()
	'	Return bmx_qt_qapplication()
	'End Function
	
	Function beep()
		bmx_qt_qapplication_beep()
	End Function
	
	Function changeOverrideCursor(cursor:QCursor)
		bmx_qt_qapplication_changeoverridecursor(cursor.qObjectPtr)
	End Function
	
	Function clipboard:QClipboard()
		Return QClipboard._find(bmx_qt_qapplication_clipboard())
	End Function
	
	Function colorSpec:Int()
		Return bmx_qt_qapplication_colorspec()
	End Function
	
	Function cursorFlashTime:Int()
		Return bmx_qt_qapplication_cursorflashtime()
	End Function
	
	Function Desktop:QDesktopWidget()
		Return QDesktopWidget._find(bmx_qt_qapplication_desktop())
	End Function
	
	Function desktopSettingsAware:Int()
		Return bmx_qt_qapplication_desktopsettingsaware()
	End Function
	
	Function doubleClickInterval:Int()
		Return bmx_qt_qapplication_doubleclickinterval()
	End Function
	
	Function focusWidget:QWidget()
		Return QWidget._find(bmx_qt_qapplication_focuswidget())
	End Function
	
	Function font:QFont()
		Return QFont._create(bmx_qt_qapplication_font())
	End Function
	
	Function fontWidget:QFont(widget:QWidget)
		Return QFont._create(bmx_qt_qapplication_fontwidget(widget.qObjectPtr))
	End Function
	
	Function FontName:QFont(className:String)
		Return QFont._create(bmx_qt_qapplication_fontname(className))
	End Function
	
	Function fontMetrics:QFontMetrics()
		Return QFontMetrics._create(bmx_qt_qapplication_fontmetrics())
	End Function
	
	Function globalStrut(w:Int Var, h:Int Var)
		bmx_qt_qapplication_globalstrut(Varptr w, Varptr h)
	End Function
	
	Function isEffectEnabled:Int(effect:Int)
		Return bmx_qt_qapplication_iseffectenabled(effect)
	End Function
	
	Function isLeftToRight:Int()
		Return bmx_qt_qapplication_islefttoright()
	End Function
	
	Function isRightToLeft:Int()
		Return bmx_qt_qapplication_isrighttoleft()
	End Function
	
	Function keyboardInputDirection:Int()
		Return bmx_qt_qapplication_keyboardinputdirection()
	End Function
	
	Function keyboardInputInterval:Int()
		Return bmx_qt_qapplication_keyboardinputinterval()
	End Function
	
	Function keyboardInputLocale:QLocale()
		Return QLocale._create(bmx_qt_qapplication_keyboardinputlocale())
	End Function
	
	Function keyboardModifiers:Int()
		Return bmx_qt_qapplication_keyboardmodifiers()
	End Function
	
	Function layoutDirection:Int()
		Return bmx_qt_qapplication_layoutdirection()
	End Function
	
	Function mouseButtons:Int()
		Return bmx_qt_qapplication_mousebuttons()
	End Function
	
	Function overrideCursor:QCursor()
		Return QCursor._create(bmx_qt_qapplication_overridecursor())
	End Function
	
	Function quitOnLastWindowClosed:Int()
		Return bmx_qt_qapplication_quitonlastwindowclosed()
	End Function
	
	Function restoreOverrideCursor()
		bmx_qt_qapplication_restoreoverridecursor()
	End Function
	
	Function setActiveWindow(active:QWidget)
		bmx_qt_qapplication_setactivewindow(active.qObjectPtr)
	End Function
	
	Function setColorSpec(spec:Int)
		bmx_qt_qapplication_setcolorspec(spec)
	End Function
	
	Function setCursorFlashTime(time:Int)
		bmx_qt_qapplication_setcursorflashtime(time)
	End Function
	
	Function setDesktopSettingsAware(on:Int)
		bmx_qt_qapplication_setdesktopsettingsaware(on)
	End Function
	
	Function setDoubleClickInterval(interval:Int)
		bmx_qt_qapplication_setdoubleclickinterval(interval)
	End Function
	
	Function setEffectEnabled(effect:Int, enable:Int = True)
		bmx_qt_qapplication_seteffectenabled(effect, enable)
	End Function
	
	Function setFont(font:QFont, className:String = Null)
		bmx_qt_qapplication_setfont(font.qObjectPtr, className)
	End Function
	
	Function setGlobalStrut(w:Int, h:Int)
		bmx_qt_qapplication_setglobalstrut(w, h)
	End Function
	
	Function setGraphicsSystem(system:String)
		bmx_qt_qapplication_setgraphicssystem(system)
	End Function
	
	Function setKeyboardInputInterval(interval:Int)
		bmx_qt_qapplication_setkeyboardinputinterval(interval)
	End Function
	
	Function setLayoutDirection(direction:Int)
		bmx_qt_qapplication_setlayoutdirection(direction)
	End Function
	
	Function setOverrideCursor(cursor:QCursor)
		bmx_qt_qapplication_setoverridecursor(cursor.qObjectPtr)
	End Function
	
	Function setPalette(palette:QPalette, className:String = Null)
		bmx_qt_qapplication_setpalette(palette.qObjectPtr, className)
	End Function
	
	Function setQuitOnLastWindowClosed(quit:Int)
		bmx_qt_qapplication_setquitonlastwindowclosed(quit)
	End Function
	
	Function setStartDragDistance(l:Int)
		bmx_qt_qapplication_setstartdragdistance(l)
	End Function
	
	Function setStartDragTime(ms:Int)
		bmx_qt_qapplication_setstartdragtime(ms)
	End Function
	

	' SIGNAL : commitDataRequest
	Function _OnCommitDataRequest(obj:QApplication, m:Byte Ptr)
		obj._InvokeSignals("commitDataRequest", [QSessionManager._create(m)])
	End Function

	' SIGNAL : focusChanged
	Function _OnFocusChanged(obj:QApplication, old:Byte Ptr, now:Byte Ptr)
		obj._InvokeSignals("focusChanged", [QWidget._find(old), QWidget._find(now)])
	End Function

	' SIGNAL : fontDatabaseChanged
	Function _OnFontDatabaseChanged(obj:QApplication)
		obj._InvokeSignals("fontDatabaseChanged", Null)
	End Function

	' SIGNAL : lastWindowClosed
	Function _OnLastWindowClosed(obj:QApplication)
		obj._InvokeSignals("lastWindowClosed", Null)
	End Function

	' SIGNAL : saveStateRequest
	Function _OnSaveStateRequest(obj:QApplication, m:Byte Ptr)
		obj._InvokeSignals("saveStateRequest", [QSessionManager._create(m)])
	End Function

End Type

