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
Import Qt.QWidget
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

	Function bmx_qt_qgridlayout_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qgridlayout_addlayout(handle:Byte Ptr, layout:Byte Ptr, row:Int, column:Int, alignment:Int)
	Function bmx_qt_qgridlayout_addlayoutspan(handle:Byte Ptr, layout:Byte Ptr, row:Int, column:Int, rowSpan:Int, columnSpan:Int, alignment:Int)
	Function bmx_qt_qgridlayout_addwidget(handle:Byte Ptr, widget:Byte Ptr, row:Int, column:Int, alignment:Int)
	Function bmx_qt_qgridlayout_addwidgetspan(handle:Byte Ptr, widget:Byte Ptr, fromRow:Int, fromColumn:Int, rowSpan:Int, columnSpan:Int, alignment:Int)
	Function bmx_qt_qgridlayout_cellrect:Byte Ptr(handle:Byte Ptr, row:Int, column:Int)
	Function bmx_qt_qgridlayout_columncount:Int(handle:Byte Ptr)
	Function bmx_qt_qgridlayout_columnminimumwidth:Int(handle:Byte Ptr, column:Int)
	Function bmx_qt_qgridlayout_columnstretch:Int(handle:Byte Ptr, column:Int)
	Function bmx_qt_qgridlayout_getitemposition(handle:Byte Ptr, index:Int, row:Int Ptr, column:Int Ptr, rowSpan:Int Ptr, columnSpan:Int Ptr)
	Function bmx_qt_qgridlayout_horizontalspacing:Int(handle:Byte Ptr)
	Function bmx_qt_qgridlayout_itematposition:Byte Ptr(handle:Byte Ptr, row:Int, column:Int)
	Function bmx_qt_qgridlayout_origincorner:Int(handle:Byte Ptr)
	Function bmx_qt_qgridlayout_rowcount:Int(handle:Byte Ptr)
	Function bmx_qt_qgridlayout_rowminimumheight:Int(handle:Byte Ptr, row:Int)
	Function bmx_qt_qgridlayout_rowstretch:Int(handle:Byte Ptr, row:Int)
	Function bmx_qt_qgridlayout_setcolumnminimumwidth(handle:Byte Ptr, column:Int, minSize:Int)
	Function bmx_qt_qgridlayout_setcolumnstretch(handle:Byte Ptr, column:Int, stretch:Int)
	Function bmx_qt_qgridlayout_sethorizontalspacing(handle:Byte Ptr, spacing:Int)
	Function bmx_qt_qgridlayout_setorigincorner(handle:Byte Ptr, corner:Int)
	Function bmx_qt_qgridlayout_setrowminimumheight(handle:Byte Ptr, row:Int, minSize:Int)
	Function bmx_qt_qgridlayout_setrowstretch(handle:Byte Ptr, row:Int, stretch:Int)
	Function bmx_qt_qgridlayout_setspacing(handle:Byte Ptr, spacing:Int)
	Function bmx_qt_qgridlayout_setverticalspacing(handle:Byte Ptr, spacing:Int)
	Function bmx_qt_qgridlayout_spacing:Int(handle:Byte Ptr)
	Function bmx_qt_qgridlayout_verticalspacing:Int(handle:Byte Ptr)

End Extern
