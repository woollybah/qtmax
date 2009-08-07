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

Module Qt.QApplication

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QApplication Extends QCoreApplication

	Function CreateApplication:QApplication()
		Return New QApplication.Create()
	End Function
	
	Method Create:QApplication()
		qObjectPtr = bmx_qt_qapplication_create(Self)
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

