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
bbdoc: Provides an event loop for console Qt applications.
End Rem
Module Qt.QCoreApplication

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: A global referring to the unique application object.
End Rem
Global qApp:QCoreApplication

Rem
bbdoc: 
End Rem
Type QCoreApplication Extends QObject

	Function CreateApplication:QCoreApplication()
		Return New QCoreApplication.Create()
	End Function
	
	Method Create:QCoreApplication()
		qObjectPtr = bmx_qt_qcoreapplication_create(Self)
		qApp = Self
		Return Self
	End Method

	Rem
	bbdoc: Tells the application to exit with return code 0 (success).
	about: Equivalent to calling QCoreApplication::exit(0).
	<p>
	It's common to connect the QApplication::lastWindowClosed() signal to quit(), and you also often
	connect e.g. QAbstractButton::clicked() or signals in QAction, QMenu, or QMenuBar to it.
	</p>
	End Rem	
	Method quit()
		bmx_qt_qcoreapplication_quit(qObjectPtr)
	End Method

	Function addLibraryPath(path:String)
		bmx_qt_qcoreapplication_addlibrarypath(path)
	End Function
	
	Function applicationDirPath:String()
		Return bmx_qt_qcoreapplication_applicationdirpath()
	End Function
	
	Function applicationFilePath:String()
		Return bmx_qt_qcoreapplication_applicationfilepath()
	End Function
	
	Function applicationName:String()
		Return bmx_qt_qcoreapplication_applicationname()
	End Function
	
	Function applicationPid:Long()
		Local pid:Long
		bmx_qt_qcoreapplication_applicationpid(Varptr pid)
		Return pid
	End Function
	
	Function applicationVersion:String()
	End Function
	
	Function closingDown:Int()
	End Function
		
	Method exec:Int()
	End Method

	Function exitApplication(returnCode:Int = 0)
	End Function
	
	Function flush()
		bmx_qt_qcoreapplication_flush()
	End Function

	Method processEvents(flags:Int = QEventLoop.AllEvents)
		bmx_qt_qcoreapplication_processevents(qObjectPtr, flags)
	End Method
	
	Method processEventsTime(flags:Int, maxtime:Int)
	End Method

	' SIGNAL : aboutToQuit
	Function _OnAboutToQuit(obj:QCoreApplication)
		obj._InvokeSignals("aboutToQuit", Null)
	End Function

End Type

Rem
bbdoc: Marks the string literal @text for dynamic translation in the current context (class), i.e the stored @text will not be altered.
End Rem
Function QT_TR_NOOP:String(text:String)
	Return bmx_qt_qcoreapplication_translate("", text, "", 0)
End Function

Rem
bbdoc: Marks the string literal @text for dynamic translation in the given @context; i.e, the stored sourceText will not be altered.
about: The context is typically a class and also needs to be specified as string literal.
End Rem
Function QT_TRANSLATE_NOOP:String(context:String, text:String)
	Return bmx_qt_qcoreapplication_translate(context, text, "", 0)
End Function
