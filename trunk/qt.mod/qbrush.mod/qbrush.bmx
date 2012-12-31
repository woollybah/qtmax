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

Module Qt.QBrush

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: Defines the fill pattern of shapes drawn by #QPainter.
End Rem
Type QBrush

	Field qObjectPtr:Byte Ptr
	
	Function _create:QBrush(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QBrush = New QBrush
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function CreateBrush:QBrush()
	End Function
	
	Method Create:QBrush()
		qObjectPtr = bmx_qt_qbrush_create()
		Return Self
	End Method
	
	Method CreateWithStyle:QBrush(style:Int)
	End Method
	
	Method CreateWithColor:QBrush(color:QColor, style:Int = Qt_SolidPattern)
		qObjectPtr = bmx_qt_qbrush_createwithcolor(color.qObjectPtr, style)
		Return Self
	End Method
	
	Method CreateWithGlobalColor:QBrush(color:Int, style:Int = Qt_SolidPattern)
		qObjectPtr = bmx_qt_qbrush_createwithglobalcolor(color, style)
		Return Self
	End Method
	
	Method CreateWithPattern:QBrush(color:QColor, pixmap:QPixmap)
	End Method
	
	Method CreateWithGlobalPattern:QBrush(color:Int, pixmap:QPixmap)
	End Method
	
	Method CreateWithPixmap:QBrush(pixmap:QPixmap)
		qObjectPtr = bmx_qt_qbrush_createwithpixmap(pixmap.qObjectPtr)
		Return Self
	End Method
	
	Method CreateWithGradient:QBrush(gradient:QGradient)
		qObjectPtr = bmx_qt_qbrush_createwithgradient(gradient.qObjectPtr)
		Return Self
	End Method

	Method color:QColor()
	' TODO
	End Method
	
	Method gradient:QGradient()
	' TODO
	End Method
	
	Method isOpaque:Int()
	' TODO
	End Method
	
	Method matrix:QMatrix()
	' TODO
	End Method
	
	Method SetColor(color:QColor)
	' TODO
	End Method
	
	Method SetGlobalColor(color:Int)
	' TODO
	End Method
	
	Method setMatrix(matrix:QMatrix)
	' TODO
	End Method
	
	Method setStyle(style:Int)
	' TODO
	End Method
	
	Method setTexture(pixmap:QPixmap)
	' TODO
	End Method
	
	Method setTextureImage(image:QImage)
	' TODO
	End Method
	
	Method SetTransform( matrix:QTransform)
	' TODO
	End Method
	
	Method style:Int()
	' TODO
	End Method
	
	Method texture:QPixmap()
		Return QPixmap._create(bmx_qt_qbrush_texture(qObjectPtr))
	End Method
	
	Method textureImage:QImage()
	' TODO
	End Method
	
	Method transform:QTransform()
	' TODO
	End Method

	Method Free()
		If qObjectPtr Then
			bmx_qt_qbrush_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type

