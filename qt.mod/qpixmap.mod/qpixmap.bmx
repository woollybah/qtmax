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

Module Qt.QPixmap

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type QPixmap Extends QPaintDevice

	Function _create:QPixmap(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QPixmap = New QPixmap
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Method Create:QPixmap(width:Int, height:Int)
		qObjectPtr = bmx_qt_qpixmap_create(width, height)
		Return Self
	End Method

	Function FromImage:QPixmap(image:QImage, flags:Int = Qt_AutoColor)
		Return QPixmap._create(bmx_qt_qpixmap_fromimage(image.qObjectPtr, flags))
	End Function
	
	Function FromFile:QPixmap(filename:String, format:String = "", flags:Int = Qt_AutoColor)
		Return QPixmap._create(bmx_qt_qpixmap_fromfile(filename, format, flags))
	End Function
	
	Function FromPixmap:QPixmap(pixmap:TPixmap)
		Local image:QImage = New QImage.CreateWithPixmap(pixmap)
		Return FromImage(image)
	End Function
	
	Method fill(color:Int = Qt_white)
		bmx_qt_qpixmap_fill(qObjectPtr, color)
	End Method
	
	Method fillColor(color:QColor)
		bmx_qt_qpixmap_fillcolor(qObjectPtr, color.qObjectPtr)
	End Method

	Method mask:QBitmap()
	' TODO
	End Method
	
	Method rect:QRect()
	' TODO
	End Method
	
	Method save:Int(fileName:String, format:String = Null, quality:Int = -1)
	' TODO
	End Method

	Method scaled:QPixmap(width:Int, height:Int, aspectRatioMode:Int = Qt_IgnoreAspectRatio, transformMode:Int = Qt_FastTransformation)
		Return QPixmap._create(bmx_qt_qpixmap_scaled(qObjectPtr, width, height, aspectRatioMode, transformMode))
	End Method

	Method scaledToHeight:QPixmap(height:Int, _mode:Int = Qt_FastTransformation)
	' TODO
	End Method
	
	Method scaledToWidth:QPixmap(width:Int, _mode:Int = Qt_FastTransformation)
	' TODO
	End Method

	Method setAlphaChannel(alphaChannel:QPixmap)
	' TODO
	End Method
	
	Method setMask(mask:QBitmap)
	' TODO
	End Method
	
	Method size(w:Int Var, h:Int Var)
		bmx_qt_qpixmap_size(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method toImage:QImage()
		Return QImage._create(bmx_qt_qpixmap_toimage(qObjectPtr))
	End Method
	
	Function grabWindow:QPixmap(window:Int, x:Int = 0, y:Int = 0, width:Int = -1, height:Int = -1)
		Return QPixmap._create(bmx_qt_qpixmap_grabwindow(window, x, y, width, height))
	End Function
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qpixmap_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type

Type QBitmap Extends QPixmap

	Function _create:QBitmap(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QBitmap = New QBitmap
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

End Type

