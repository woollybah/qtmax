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

Import Qt.Core
Import Qt.QCoreApplication
Import Qt.QPainter
Import Qt.QSessionManager
Import Qt.QWidget
Import Qt.QCursor
Import Qt.QClipboard
Import Qt.QDesktopWidget
Import Qt.QPalette
Import BRL.Blitz


' headers :-)
?win32
Import "../lib/win32/include/*.h"
?macos
Import "../lib/macos/include/*.h"
?Not linux
Import "../src/include/*.h"
Import "../src/include/Qt/*.h"
Import "../src/include/QtCore/*.h"
Import "../src/include/QtGui/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
?


Import "glue.cpp"

Extern

	Function bmx_qt_qapplication_create:Byte Ptr(handle:Object)
	Function bmx_qt_qapplication_exec:Int()
	Function bmx_qt_qapplication_aboutqt(handle:Byte Ptr)
	Function bmx_qt_qapplication_closeallwindows(handle:Byte Ptr)
	Function bmx_qt_qapplication_setstylesheet(handle:Byte Ptr, sheet:String)

	Function bmx_qt_qapplication_activemodalwidget:Byte Ptr()
	Function bmx_qt_qapplication_activepopupwidget:Byte Ptr()
	Function bmx_qt_qapplication_activewindow:Byte Ptr()
	Function bmx_qt_qapplication_alert(widget:Byte Ptr, msec:Int)
	Function bmx_qt_qapplication_beep()
	Function bmx_qt_qapplication_changeoverridecursor(cursor:Byte Ptr)
	Function bmx_qt_qapplication_clipboard:Byte Ptr()
	Function bmx_qt_qapplication_colorspec:Int()
	Function bmx_qt_qapplication_cursorflashtime:Int()
	Function bmx_qt_qapplication_desktop:Byte Ptr()
	Function bmx_qt_qapplication_desktopsettingsaware:Int()
	Function bmx_qt_qapplication_doubleclickinterval:Int()
	Function bmx_qt_qapplication_focuswidget:Byte Ptr()
	Function bmx_qt_qapplication_font:Byte Ptr()
	Function bmx_qt_qapplication_fontwidget:Byte Ptr(widget:Byte Ptr)
	Function bmx_qt_qapplication_fontname:Byte Ptr(className:String)
	Function bmx_qt_qapplication_fontmetrics:Byte Ptr()
	Function bmx_qt_qapplication_globalstrut(w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qapplication_iseffectenabled:Int(effect:Int)
	Function bmx_qt_qapplication_islefttoright:Int()
	Function bmx_qt_qapplication_isrighttoleft:Int()
	Function bmx_qt_qapplication_keyboardinputdirection:Int()
	Function bmx_qt_qapplication_keyboardinputinterval:Int()
	Function bmx_qt_qapplication_keyboardinputlocale:Byte Ptr()
	Function bmx_qt_qapplication_keyboardmodifiers:Int()
	Function bmx_qt_qapplication_layoutdirection:Int()
	Function bmx_qt_qapplication_mousebuttons:Int()
	Function bmx_qt_qapplication_overridecursor:Byte Ptr()
	Function bmx_qt_qapplication_quitonlastwindowclosed:Int()
	Function bmx_qt_qapplication_restoreoverridecursor()
	Function bmx_qt_qapplication_setactivewindow(widget:Byte Ptr)
	Function bmx_qt_qapplication_setcolorspec(spec:Int)
	Function bmx_qt_qapplication_setcursorflashtime(time:Int)
	Function bmx_qt_qapplication_setdesktopsettingsaware(on:Int)
	Function bmx_qt_qapplication_setdoubleclickinterval(interval:Int)
	Function bmx_qt_qapplication_seteffectenabled(effect:Int, enable:Int)
	Function bmx_qt_qapplication_setfont(font:Byte Ptr, className:String)
	Function bmx_qt_qapplication_setglobalstrut(w:Int, h:Int)
	Function bmx_qt_qapplication_setgraphicssystem(system:String)
	Function bmx_qt_qapplication_setkeyboardinputinterval(interval:Int)
	Function bmx_qt_qapplication_setlayoutdirection(direction:Int)
	Function bmx_qt_qapplication_setoverridecursor(cursor:Byte Ptr)
	Function bmx_qt_qapplication_setpalette(palette:Byte Ptr, className:String)
	Function bmx_qt_qapplication_setquitonlastwindowclosed(quit:Int)
	Function bmx_qt_qapplication_setstartdragdistance(l:Int)
	Function bmx_qt_qapplication_setstartdragtime(ms:Int)
	
End Extern
