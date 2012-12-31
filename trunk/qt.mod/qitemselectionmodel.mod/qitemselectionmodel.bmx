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

Module Qt.QItemSelectionModel

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QItemSelectionModel Extends QObject

	Rem
	bbdoc: No selection will be made.
	End Rem
	Const Selection_NoUpdate:Int = $0000

	Rem
	bbdoc: The complete selection will be cleared.
	End Rem
	Const Selection_Clear:Int = $0001

	Rem
	bbdoc: All specified indexes will be selected.
	End Rem
	Const Selection_Select:Int = $0002

	Rem
	bbdoc: All specified indexes will be deselected.
	End Rem
	Const Selection_Deselect:Int = $0004

	Rem
	bbdoc: All specified indexes will be selected or deselected depending on their current state.
	End Rem
	Const Selection_Toggle:Int = $0008

	Rem
	bbdoc: The current selection will be updated.
	End Rem
	Const Selection_Current:Int = $0010

	Rem
	bbdoc: All indexes will be expanded to span rows.
	End Rem
	Const Selection_Rows:Int = $0020

	Rem
	bbdoc: All indexes will be expanded to span columns.
	End Rem
	Const Selection_Columns:Int = $0040

	Rem
	bbdoc: A combination of Select and Current, provided for convenience.
	End Rem
	Const Selection_SelectCurrent:Int = Selection_Select | Selection_Current

	Rem
	bbdoc: A combination of Toggle and Current, provided for convenience.
	End Rem
	Const Selection_ToggleCurrent:Int = Selection_Toggle | Selection_Current

	Rem
	bbdoc: A combination of Clear and Select, provided for convenience.
	End Rem
	Const Selection_ClearAndSelect:Int = Selection_Clear | Selection_Select



	Function CreateItemSelectionModel:QItemSelectionModel(model:QAbstractItemModel)
		Return New QItemSelectionModel.Create(model)
	End Function
	
	Method Create:QItemSelectionModel(model:QAbstractItemModel)
		qObjectPtr = bmx_qt_qitemselectionmodel_create(Self, model.qObjectPtr)
		Return Self
	End Method
	
	Method clear()
		bmx_qt_qitemselectionmodel_clear(qObjectPtr)
	End Method
	
	Method clearSelection()
		bmx_qt_qitemselectionmodel_clearselection(qObjectPtr)
	End Method
	
	Method columnIntersectsSelection:Int(column:Int, parent:QModelIndex)
		Return bmx_qt_qitemselectionmodel_columnintersectsselection(qObjectPtr, column, parent.qObjectPtr)
	End Method

	Method currentIndex:QModelIndex()
		Return New QModelIndex._create(bmx_qt_qitemselectionmodel_currentindex(qObjectPtr))
	End Method

	Method hasSelection:Int()
		Return bmx_qt_qitemselectionmodel_hasselection(qObjectPtr)
	End Method

	Method isColumnSelected:Int(column:Int, parent:QModelIndex)
		Return bmx_qt_qitemselectionmodel_iscolumnselected(qObjectPtr, column, parent.qObjectPtr)
	End Method

	Method isRowSelected:Int(row:Int, parent:QModelIndex)
		Return bmx_qt_qitemselectionmodel_isrowselected(qObjectPtr, row, parent.qObjectPtr)
	End Method

	Method isSelected:Int(index:QModelIndex)
		Return bmx_qt_qitemselectionmodel_isselected(qObjectPtr, index.qObjectPtr)
	End Method

	Method model:QAbstractItemModel()
	' TODO
	End Method
	
	Method reset()
		bmx_qt_qitemselectionmodel_reset(qObjectPtr)
	End Method

	Method rowIntersectsSelection:Int(row:Int, parent:QModelIndex)
		Return bmx_qt_qitemselectionmodel_rowintersectsselection(qObjectPtr, row, parent.qObjectPtr)
	End Method
	
	Method selectIndex(index:QModelIndex, command:Int)
		bmx_qt_qitemselectionmodel_selectindex(qObjectPtr, index.qObjectPtr, command)
	End Method

	Method selectedColumns:QModelIndex[](row:Int = 0)
		Return bmx_qt_qitemselectionmodel_selectedcolumns(qObjectPtr, row)
	End Method

	Method selectedIndexes:QModelIndex[]()
		Return bmx_qt_qitemselectionmodel_selectedindexes(qObjectPtr)
	End Method

	Method selectedRows:QModelIndex[](column:Int = 0)
		Return bmx_qt_qitemselectionmodel_selectedrows(qObjectPtr, column)
	End Method

	Method setCurrentIndex(index:QModelIndex, command:Int)
		bmx_qt_qitemselectionmodel_setcurrentindex(qObjectPtr, index.qObjectPtr, command)
	End Method
	
	Method selection:QItemSelection()
		Return QItemSelection._create(bmx_qt_qitemselectionmodel_selection(qObjectPtr))
	End Method



	' SIGNAL : currentChanged
	Function _OnCurrentChanged(obj:QItemSelectionModel, _current:Byte Ptr, _previous:Byte Ptr)
		obj._InvokeSignals("currentChanged", [New QModelIndex._create(_current), New QModelIndex._create(_previous)])
	End Function

	' SIGNAL : currentColumnChanged
	Function _OnCurrentColumnChanged(obj:QItemSelectionModel, _current:Byte Ptr, _previous:Byte Ptr)
		obj._InvokeSignals("currentColumnChanged", [New QModelIndex._create(_current), New QModelIndex._create(_previous)])
	End Function

	' SIGNAL : currentRowChanged
	Function _OnCurrentRowChanged(obj:QItemSelectionModel, _current:Byte Ptr, _previous:Byte Ptr)
		obj._InvokeSignals("currentRowChanged", [New QModelIndex._create(_current), New QModelIndex._create(_previous)])
	End Function

	' SIGNAL : selectionChanged
	Function _OnSelectionChanged(obj:QItemSelectionModel, selected:Byte Ptr, deselected:Byte Ptr)
		obj._InvokeSignals("selectionChanged", [New QItemSelection._create(selected), New QItemSelection._create(deselected)])
	End Function

End Type


Rem
bbdoc: Manages information about selected items in a model.
about: A QItemSelection describes the items in a model that have been selected by the user.
A QItemSelection is basically a list of selection ranges. It provides functions for creating and manipulating
selections, and selecting a range of items from a model.
End Rem
Type QItemSelection

	Field qObjectPtr:Byte Ptr

	Function _create:QItemSelection(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QItemSelection = New QItemSelection
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Rem
	bbdoc: 
	End Rem
	Method contains:Int(index:QModelIndex)
		Return bmx_qt_qitemselection_contains(qObjectPtr, index.qObjectPtr)
	End Method
	
	Method indexes:QModelIndex[]()
		Return bmx_qt_qitemselection_indexes(qObjectPtr)
	End Method
	
	Method selectRange(topLeft:QModelIndex, bottomRight:QModelIndex)
		bmx_qt_qitemselection_selectrange(qObjectPtr, topLeft.qObjectPtr, bottomRight.qObjectPtr)
	End Method
	

	Method Free()
		If qObjectPtr Then
			bmx_qt_qitemselection_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type
