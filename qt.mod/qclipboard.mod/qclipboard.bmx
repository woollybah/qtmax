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

Module Qt.QClipboard

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QClipboard Extends QObject

	Rem
	bbdoc: Indicates that data should be stored and retrieved from the global clipboard.
	End Rem
	Const Clipboard:Int = 0
	Rem
	bbdoc: Indicates that data should be stored and retrieved from the global mouse selection.
	about: Support for Selection is provided only on systems with a global mouse selection (e.g. X11).
	End Rem
	Const Selection:Int = 1
	Rem
	bbdoc: Indicates that data should be stored and retrieved from the Find buffer.
	about: This mode is used for holding search strings on Mac OS X.
	End Rem
	Const FindBuffer:Int = 2

	Function _create:QClipboard(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QClipboard = New QClipboard
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QClipboard(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local cb:QClipboard = QClipboard(qfind(qObjectPtr))
			If Not cb Then
				Return QClipboard._create(qObjectPtr)
			End If
			Return cb
		End If
	End Function

	Method clear(_mode:Int = Clipboard)
		bmx_qt_qclipboard_clear(qObjectPtr, _mode)
	End Method
	
	Method image:QImage(_mode:Int = Clipboard)
		Return QImage._create(bmx_qt_qclipboard_image(qObjectPtr, _mode))
	End Method
	
	Method mimeData:QMimeData(_mode:Int = Clipboard)
		Return QMimeData._find(bmx_qt_qclipboard_mimedata(qObjectPtr, _mode))
	End Method
	
	Method ownsClipboard:Int()
		Return bmx_qt_qclipboard_ownsclipboard(qObjectPtr)
	End Method
	
	Method ownsFindBuffer:Int()
		Return bmx_qt_qclipboard_ownsfindbuffer(qObjectPtr)
	End Method
	
	Method ownsSelection:Int()
		Return bmx_qt_qclipboard_ownsselection(qObjectPtr)
	End Method
	
	Method pixmap:QPixmap(_mode:Int = Clipboard)
		Return QPixmap._create(bmx_qt_qclipboard_pixmap(qObjectPtr, _mode))
	End Method
	
	Method setImage(image:QImage, _mode:Int = Clipboard)
		bmx_qt_qclipboard_setimage(qObjectPtr, image.qObjectPtr, _mode)
	End Method
	
	Method setMimeData(src:QMimeData, _mode:Int = Clipboard)
		bmx_qt_qclipboard_setmimedata(qObjectPtr, src.qObjectPtr, _mode)
	End Method
	
	Method setPixmap(pixmap:QPixmap, _mode:Int = Clipboard)
		bmx_qt_qclipboard_setpixmap(qObjectPtr, pixmap.qObjectPtr, _mode)
	End Method
	
	Method setText(text:String, _mode:Int = Clipboard)
		bmx_qt_qclipboard_settext(qObjectPtr, text, _mode)
	End Method
	
	Method supportsFindBuffer:Int()
		Return bmx_qt_qclipboard_supportsfindbuffer(qObjectPtr)
	End Method
	
	Method supportsSelection:Int()
		Return bmx_qt_qclipboard_supportsselection(qObjectPtr)
	End Method
	
	Method text:String(_mode:Int = Clipboard)
		Return bmx_qt_qclipboard_text(qObjectPtr, _mode)
	End Method
	
	Method textSubType:String(subtype:String, _mode:Int = Clipboard)
		Return bmx_qt_qclipboard_textsubtype(qObjectPtr, subtype, _mode)
	End Method
	
	' SIGNAL : changed
	Function _OnChanged(obj:QClipboard, _mode:Int)
		obj._InvokeSignals("changed", [String(_mode)])
	End Function

	' SIGNAL : dataChanged
	Function _OnDataChanged(obj:QClipboard)
		obj._InvokeSignals("dataChanged", Null)
	End Function
	
	' SIGNAL : findBufferChanged
	Function _OnFindBufferChanged(obj:QClipboard)
		obj._InvokeSignals("findBufferChanged", Null)
	End Function
	
	' SIGNAL : selectionChanged
	Function _OnSelectionChanged(obj:QClipboard)
		obj._InvokeSignals("selectionChanged", Null)
	End Function
	
End Type

