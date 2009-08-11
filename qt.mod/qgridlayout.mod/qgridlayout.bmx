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

Module Qt.QGridLayout

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QGridLayout Extends QLayout

	Function CreateGridLayout:QGridLayout(parent:QWidget = Null)
		Return New QGridLayout.Create(parent)
	End Function
	
	Method Create:QGridLayout(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qgridlayout_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qgridlayout_create(Self, Null)
		End If
		Return Self
	End Method

	Method addLayout(layout:QLayout, row:Int, column:Int, alignment:Int = 0)
		bmx_qt_qgridlayout_addlayout(qObjectPtr, layout.qObjectPtr, row, column, alignment)
	End Method
	
	Method addWidget(widget:QWidget, row:Int, column:Int, alignment:Int = 0)
		bmx_qt_qgridlayout_addwidget(qObjectPtr, widget.qObjectPtr, row, column, alignment)
	End Method

	Method addWidgetSpan(widget:QWidget, fromRow:Int, fromColumn:Int, rowSpan:Int, columnSpan:Int, alignment:Int = 0)
		bmx_qt_qgridlayout_addwidgetspan(qObjectPtr, widget.qObjectPtr, fromRow, fromColumn, rowSpan, columnSpan, alignment)
	End Method

	Method cellRect:QRect(row:Int, column:Int)
		Return QRect._create(bmx_qt_qgridlayout_cellrect(qObjectPtr, row, column))
	End Method
	
	Method columnCount:Int()
		Return bmx_qt_qgridlayout_columncount(qObjectPtr)
	End Method
	
	Method columnMinimumWidth:Int(column:Int)
		Return bmx_qt_qgridlayout_columnminimumwidth(qObjectPtr, column)
	End Method
	
	Method columnStretch:Int(column:Int)
		Return bmx_qt_qgridlayout_columnstretch(qObjectPtr, column)
	End Method
	
	Method getItemPosition(index:Int, row:Int Var, column:Int Var, rowSpan:Int Var, columnSpan:Int Var)
		bmx_qt_qgridlayout_getitemposition(qObjectPtr, index, Varptr row, Varptr column, Varptr rowSpan, Varptr columnSpan)
	End Method
	
	Method horizontalSpacing:Int()
		Return bmx_qt_qgridlayout_horizontalspacing(qObjectPtr)
	End Method
	
	Method itemAtPosition:QLayoutItem(row:Int, column:Int)
		Return QLayoutItem._create(bmx_qt_qgridlayout_itematposition(qObjectPtr, row, column))
	End Method
	
	Method originCorner:Int()
		Return bmx_qt_qgridlayout_origincorner(qObjectPtr)
	End Method
	
	Method rowCount:Int()
		Return bmx_qt_qgridlayout_rowcount(qObjectPtr)
	End Method
	
	Method rowMinimumHeight:Int(row:Int)
		Return bmx_qt_qgridlayout_rowminimumheight(qObjectPtr, row)
	End Method
	
	Method rowStretch:Int(row:Int)
		Return bmx_qt_qgridlayout_rowstretch(qObjectPtr, row)
	End Method
	
	Method setColumnMinimumWidth(column:Int, minSize:Int)
		bmx_qt_qgridlayout_setcolumnminimumwidth(qObjectPtr, column, minSize)
	End Method
	
	Method setColumnStretch(column:Int, stretch:Int)
		bmx_qt_qgridlayout_setcolumnstretch(qObjectPtr, column, stretch)
	End Method
	
	Method setHorizontalSpacing(spacing:Int)
		bmx_qt_qgridlayout_sethorizontalspacing(qObjectPtr, spacing)
	End Method
	
	Method setOriginCorner(corner:Int)
		bmx_qt_qgridlayout_setorigincorner(qObjectPtr, corner)
	End Method
	
	Method setRowMinimumHeight(row:Int, minSize:Int)
		bmx_qt_qgridlayout_setrowminimumheight(qObjectPtr, row, minSize)
	End Method
	
	Method setRowStretch(row:Int, stretch:Int)
		bmx_qt_qgridlayout_setrowstretch(qObjectPtr, row, stretch)
	End Method
	
	Method setSpacing(spacing:Int)
		bmx_qt_qgridlayout_setspacing(qObjectPtr, spacing)
	End Method
	
	Method setVerticalSpacing(spacing:Int)
		bmx_qt_qgridlayout_setverticalspacing(qObjectPtr, spacing)
	End Method
	
	Method spacing:Int()
		Return bmx_qt_qgridlayout_spacing(qObjectPtr)
	End Method
	
	Method verticalSpacing:Int()
		Return bmx_qt_qgridlayout_verticalspacing(qObjectPtr)
	End Method

End Type

