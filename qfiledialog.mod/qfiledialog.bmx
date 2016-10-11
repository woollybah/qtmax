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

Module Qt.QFileDialog

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QFileDialog Extends QDialog

	Rem
	bbdoc: Only show directories in the file dialog.
	about: By default both files and directories are shown. (Valid only in the Directory file mode.)
	End Rem
	Const Option_ShowDirsOnly:Int = $00000001
	Rem
	bbdoc: Don't resolve symlinks in the file dialog.
	about: By default symlinks are resolved.
	End Rem
	Const Option_DontResolveSymlinks:Int = $00000002
	Rem
	bbdoc: Don't ask for confirmation if an existing file is selected.
	about: By default confirmation is requested.
	End Rem
	Const Option_DontConfirmOverwrite:Int = $00000004
	Rem
	bbdoc: Don't use the native file dialog.
	about: By default, the native file dialog is used unless you use a subclass of QFileDialog that contains the Q_OBJECT macro.
	End Rem
	Const Option_DontUseNativeDialog:Int = $00000010
	Rem
	bbdoc: Indicates that the model is readonly.
	End Rem
	Const Option_ReadOnly:Int = $00000020
	Rem
	bbdoc: Indicates if the file name filter details are hidden or not.
	End Rem
	Const Option_HideNameFilterDetails:Int = $00000040
	Rem
	bbdoc: In previous versions of Qt, the static functions would create a sheet by default if the static function was given a parent.
	about: This is no longer supported and does nothing in Qt 4.5, The static functions will always be an application modal dialog.
	If you want to use sheets, use QFileDialog::open() instead.
	End Rem
	Const Option_DontUseSheet:Int = $00000008

	Function getExistingDirectory:String(parent:QWidget = Null, caption:String = "", dir:String = "", options:Int = 0)
		If parent Then
			Return bmx_qt_qfiledialog_getexistingdirectory(parent.qObjectPtr, caption, dir, options)
		Else
			Return bmx_qt_qfiledialog_getexistingdirectory(Null, caption, dir, options)
		End If
	End Function

	Function getOpenFileName:String(parent:QWidget = Null, caption:String = "", dir:String = "", filter:String = "", options:Int = 0)
		If parent Then
			Return bmx_qt_qfiledialog_getopenfilename(parent.qObjectPtr, caption, dir, filter, options)
		Else
			Return bmx_qt_qfiledialog_getopenfilename(Null, caption, dir, filter, options)
		End If
	End Function

	Function getSaveFileName:String(parent:QWidget = Null, caption:String = "", dir:String = "", filter:String = "", options:Int = 0)
		If parent Then
			Return bmx_qt_qfiledialog_getsavefilename(parent.qObjectPtr, caption, dir, filter, options)
		Else
			Return bmx_qt_qfiledialog_getsavefilename(Null, caption, dir, filter, options)
		End If
	End Function

End Type

