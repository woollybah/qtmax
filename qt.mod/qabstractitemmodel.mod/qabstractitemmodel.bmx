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

Module Qt.QAbstractItemModel

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QAbstractItemModel Extends QObject

	Function _create:QAbstractItemModel(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QAbstractItemModel = New QAbstractItemModel
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function _find:QAbstractItemModel(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local model:QAbstractItemModel = QAbstractItemModel(qfind(qObjectPtr))
			If Not model Then
				Return QAbstractItemModel._create(qObjectPtr)
			End If
			Return model
		End If
	End Function
	

	Method _itemChanged(data:Object)
	End Method
	
	Method _doBeginInsertRows(item:Object, row:Int, count:Int)
	End Method

	Method _doEndInsertRows(item:Object, row:Int, count:Int)
	End Method

	Method _doBeginRemoveRows(item:Object, row:Int, count:Int)
	End Method

	Method _doEndRemoveRows(item:Object, row:Int, count:Int)
	End Method

Rem
	Method buddy:QModelIndex(index:QModelIndex)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method canFetchMore:Int(parent:QModelIndex)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method columnCount:Int(parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method data:Object(index:QModelIndex, role:Int = Qt_DisplayRole)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method dropMimeData:Int(QMimeData * data, Qt::DropAction action, Int row, Int column, QModelIndex & parent)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method fetchMore(parent:QModelIndex)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method flags:Int(index:QModelIndex)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method hasChildren:Int(parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method hasIndex:Int(row:Int, column:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method headerData:Object(section:Int, orientation:Int, role:Int = Qt_DisplayRole)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method index:QModelIndex(row:Int, column:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method insertColumn:Int(column:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method insertColumns:Int(column:Int, count:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method insertRow:Int(row:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method insertRows:Int(row:Int, count:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method itemData:TMap(index:QModelIndex)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method match:QModelIndex[](start:QModelIndex, role:Int, value:Object, hits:Int = 1, flags:Int = Qt_MatchStartsWith | Qt_MatchWrap)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method mimeData:QMimeData(QModelIndexList & indexes)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method mimeTypes:String[]()
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method parent:QModelIndex(index:QModelIndex)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method removeColumn:Int(column:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method removeColumns:Int(column:Int, count:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method removeRow:Int(row:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method removeRows:Int(row:Int, count:Int, parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method rowCount:Int(parent:QModelIndex = Null)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method setData:Int(index:QModelIndex, value:Object, role:Int = Qt_EditRole)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method setHeaderData:Int(section:Int, orientation:Int, value:Object, role:Int = Qt_EditRole)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method setItemData:Int(index:QModelIndex, roles:TMap)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method setSupportedDragActions(actions:Int)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method sibling:QModelIndex(row:Int, column:Int, index:QModelIndex)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method sort(column:Int, order:Int = Qt_AscendingOrder)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method span(index:QModelIndex, w:Int Var, h:Int Var)
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method supportedDragActions:Int()
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
	
	Method supportedDropActions:Int()
		Return bmx_qt_qabstractitemmodel_(qObjectPtr)
	End Method
End Rem

End Type

Rem
bbdoc: Used to locate data in a data model.
about: This class is used as an index into item models derived from QAbstractItemModel.
The index is used by item views, delegates, and selection models to locate an item in the model.
End Rem
Type QModelIndex

	Field qObjectPtr:Byte Ptr
	
	Function _create:QModelIndex(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QModelIndex = New QModelIndex
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method child:QModelIndex(row:Int, column:Int)
		Return QModelIndex._create(bmx_qt_qmodelindex_child(qObjectPtr, row, column))
	End Method
	
	Method column:Int()
		Return bmx_qt_qmodelindex_column(qObjectPtr)
	End Method
	
	'QVariant	data ( Int role = Qt::DisplayRole ) Const
	
	Method flags:Int()
		Return bmx_qt_qmodelindex_flags(qObjectPtr)
	End Method
	
	Method internalId:Long()
		Local id:Long
		bmx_qt_qmodelindex_internalid(qObjectPtr, Varptr id)
		Return id
	End Method
	
	Method internalPointer:Byte Ptr()
		Return bmx_qt_qmodelindex_internalpointer(qObjectPtr)
	End Method
	
	Method isEqual:Int(index:QModelIndex)
		Return bmx_qt_qmodelindex_isequal(qObjectPtr, index.qObjectPtr)
	End Method
	
	Method isLessThan:Int(index:QModelIndex)
		Return bmx_qt_qmodelindex_islessthan(qObjectPtr, index.qObjectPtr)
	End Method
	
	Method isNotEqual:Int(index:QModelIndex)
		Return bmx_qt_qmodelindex_isnotequal(qObjectPtr, index.qObjectPtr)
	End Method

	Method isValid:Int()
		Return bmx_qt_qmodelindex_isvalid(qObjectPtr)
	End Method
	
	Method model:QAbstractItemModel()
		Return QAbstractItemModel._find(bmx_qt_qmodelindex_model(qObjectPtr))
	End Method
	
	Method parent:QModelIndex()
		Return QModelIndex._create(bmx_qt_qmodelindex_parent(qObjectPtr))
	End Method
	
	Method row:Int()
		Return bmx_qt_qmodelindex_row(qObjectPtr)
	End Method
	
	Method sibling:QModelIndex(row:Int, column:Int)
		Return QModelIndex._create(bmx_qt_qmodelindex_sibling(qObjectPtr, row, column))
	End Method
	
	
	Function _newArray:QModelIndex[](size:Int)
		Return New QModelIndex[size]
	End Function
	
	Function _setArrayItem(array:QModelIndex[], index:Int, value:Byte Ptr)
		array[index] = New QModelIndex._create(value)
	End Function
	
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qmodelindex_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method

End Type
