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

Module Qt.QStandardItemModel

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QStandardItemModel Extends QAbstractItemModel

	Field root:QStandardItem

	Function CreateStandardItemModel:QStandardItemModel(parent:QObject = Null)
		Return New QStandardItemModel.Create(parent)
	End Function
	
	Method Create:QStandardItemModel(parent:QObject = Null)
		If parent Then
			qObjectPtr = bmx_qt_qstandarditemmodel_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qstandarditemmodel_create(Self, Null)
		End If
		
		root = New QStandardItem.CreateEmpty()
		root.model = Self
		
		Return Self
	End Method
	
	Rem
	bbdoc: Returns the index of the item in the model specified by the given row, column and parent index.
	End Rem
	Method index:QModelIndex(row:Int, column:Int, parent:QModelIndex = Null)
		If parent Then
			Return QModelIndex._create(bmx_qt_qstandarditemmodel_index(qObjectPtr, row, column, parent.qObjectPtr))
		Else
			Return QModelIndex._create(bmx_qt_qstandarditemmodel_index(qObjectPtr, row, column, Null))
		End If
	End Method

	' TODO : bool QAbstractItemModel::setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole )
	' for each kind of value (object, string, int, etc … QColor, QFont ?)
	' perhaps setFont() etc
	'
	' calling setDataInternal will update the view automatically :-)
	'
	
	Rem
	bbdoc: Sets the @role data for the item at @index to @value.
	returns: True if successful; otherwise returns False.
	about: This method supports standard Objects and Strings. For other types (int, etc) use the appropriate setDataXXX
	method, where XXX is the type of data you want to set.
	End Rem
	Method setData:Int(index:QModelIndex, value:Object, role:Int = Qt_EditRole)
		Return setDataObject_(index, role, value)
	End Method
	
	Rem
	bbdoc: Sets the @role data for the item at @index to the int @value.
	End Rem
	Method setDataInt:Int(index:QModelIndex, value:Int, role:Int = Qt_EditRole)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Local v:TInt = New TInt
			v.value = value
			item.setDataInternal(role, v)
			Return True
		Else
			Return False
		End If
	End Method

	Rem
	bbdoc: Sets the @role data for the item at @index to the short @value.
	End Rem
	Method setDataShort:Int(index:QModelIndex, value:Short, role:Int = Qt_EditRole)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Local v:TShort = New TShort
			v.value = value
			item.setDataInternal(role, v)
			Return True
		Else
			Return False
		End If
	End Method

	Rem
	bbdoc: Sets the @role data for the item at @index to the long @value.
	End Rem
	Method setDataLong:Int(index:QModelIndex, value:Long, role:Int = Qt_EditRole)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Local v:TLong = New TLong
			v.value = value
			item.setDataInternal(role, v)
			Return True
		Else
			Return False
		End If
	End Method

	Rem
	bbdoc: Sets the @role data for the item at @index to the byte @value.
	End Rem
	Method setDataByte:Int(index:QModelIndex, value:Byte, role:Int = Qt_EditRole)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Local v:TByte = New TByte
			v.value = value
			item.setDataInternal(role, v)
			Return True
		Else
			Return False
		End If
	End Method

	Rem
	bbdoc: Sets the @role data for the item at @index to the float @value.
	End Rem
	Method setDataFloat:Int(index:QModelIndex, value:Float, role:Int = Qt_EditRole)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Local v:TFloat = New TFloat
			v.value = value
			item.setDataInternal(role, v)
			Return True
		Else
			Return False
		End If
	End Method
	
	Rem
	bbdoc: Sets the @role data for the item at @index to the double @value.
	End Rem
	Method setDataDouble:Int(index:QModelIndex, value:Double, role:Int = Qt_EditRole)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Local v:TDouble = New TDouble
			v.value = value
			item.setDataInternal(role, v)
			Return True
		Else
			Return False
		End If
	End Method

	
	Method itemFromIndex:QStandardItem(index:QModelIndex)
		If (Not index) Or (Not index.isValid()) Then
			Return root
		End If

		Local parent:QStandardItem = QStandardItem.castToObj(index.internalPointer())
		If Not parent Then
			Return Null
		End If
		
		Local item:QStandardItem = parent.child(index.row(), index.column())
		
		' create one if it doesn't exist?
		If Not item Then
			item = New QStandardItem.CreateEmpty()
			item.model = Self
			parent.setChildRC(index.row(), index.column(), item)
		End If
		
		Return item
	End Method
	
	Method indexFromItem:QModelIndex(item:QStandardItem)
		Local row:Int, col:Int
		If item And item.parentItem Then
			item.pos(row, col)
			Return QModelIndex._create(bmx_qt_qstandarditemmodel_createindex(qObjectPtr, row, col, item.parentItem.qObjectPtr))
		Else
			item.pos(row, col)
			Return QModelIndex._create(bmx_qt_qstandarditemmodel_createindex(qObjectPtr, row, col, root.qObjectPtr))
		End If
		Return Null
	End Method
	
	Rem
	bbdoc: Returns the number of columns for the children of the given parent.
	End Rem
	Method columnCount:Int(parent:QModelIndex = Null)
		Local item:QStandardItem = itemFromIndex(parent)
		If item Then
			Return item.columnCount()
		Else
			Return 0
		End If
	End Method

	Rem
	bbdoc: Returns the number of rows under the given parent.
	about: When the parent is valid it means that rowCount is returning the number of children of parent.
	End Rem
	Method rowCount:Int(parent:QModelIndex = Null)
		Local item:QStandardItem = itemFromIndex(parent)
		If item Then
			Return item.rowCount()
		Else
			Return 0
		End If
	End Method

	Method getDataInt:Int(index:QModelIndex, role:Int)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Local v:TInt = TInt(item.getDataInternal(role))
			If v Then
				Return v.value
			End If
		End If
		
		Return -1
	End Method

	' internal
	' set Object data
	Method setDataObject_:Int(index:QModelIndex, role:Int, value:Object)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			item.setDataInternal(role, value)
			Return True
		Else
			Return False
		End If
	End Method

	Method getDataString:String(index:QModelIndex, role:Int)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Local v:String = String(item.getDataInternal(role))
			If v Then
				Return v
			End If
		End If
		
		Return Null
	End Method
	
	Method getDataObject:Object(index:QModelIndex, role:Int)
		Local item:QStandardItem = itemFromIndex(index)
		If item Then
			Return item.getDataInternal(role)
		End If
		
		Return Null
	End Method
	
	Rem
	bbdoc: Inserts count rows into the model before the given row.
	returns: True if the rows were successfully inserted; otherwise returns False.
	about: Items in the new row will be children of the item represented by the parent model index.
	If @row is 0, the rows are prepended to any existing rows in the parent.
	If parent has no children, a single column with count rows is inserted.
	End Rem
	Method insertRows:Int(row:Int, count:Int, parent:QModelIndex = Null)
		Local item:QStandardItem
		If (Not parent) Or (Not parent.isValid()) Then
			item = root
		Else
			item = itemFromIndex(parent)
		End If
		
		If Not item Then
			Return False
		End If
		
		Return item.insertRows(row, count)
	End Method

	Rem
	bbdoc: Removes @count rows starting with the given row under parent parent from the model.
	returns: True if the rows were successfully removed; otherwise returns False.
	End Rem
	Method removeRows:Int(row:Int, count:Int, parent:QModelIndex = Null)
		Local item:QStandardItem
		If (Not parent) Or (Not parent.isValid()) Then
			item = root
		Else
			item = itemFromIndex(parent)
		End If

		If Not item Then
			Return False
		End If

		Return item.removeRows(row, count)
	End Method
	
	
	
	Method _itemChanged(data:Object)
'DebugLog "QStandardItemModel::_itemChanged"
		Local index:QModelIndex = indexFromItem(QStandardItem(data))
		bmx_qt_qstandarditemmodel_dataChanged(qObjectPtr, index.qObjectPtr, index.qObjectPtr)
	End Method
	
	Method _doBeginInsertRows(item:Object, row:Int, count:Int)
		Local index:QModelIndex = indexFromItem(QStandardItem(item))
		If index Then
			bmx_qt_qstandarditemmodel_dobegininsertrows(qObjectPtr, index.qObjectPtr, row, count)
		Else
			bmx_qt_qstandarditemmodel_dobegininsertrows(qObjectPtr, Null, row, count)
		End If
	End Method

	Method _doEndInsertRows(item:Object, row:Int, count:Int)
		bmx_qt_qstandarditemmodel_doendinsertrows(qObjectPtr)
	End Method

	Method _doBeginRemoveRows(item:Object, row:Int, count:Int)
		Local index:QModelIndex = indexFromItem(QStandardItem(item))
		If index Then
			bmx_qt_qstandarditemmodel_dobeginremoverows(qObjectPtr, index.qObjectPtr, row, count)
		Else
			bmx_qt_qstandarditemmodel_dobeginremoverows(qObjectPtr, Null, row, count)
		End If
	End Method

	Method _doEndRemoveRows(item:Object, row:Int, count:Int)
		bmx_qt_qstandarditemmodel_doendremoverows(qObjectPtr)
	End Method
	
	
	
	Function _itemFromIndex:Byte Ptr(obj:QStandardItemModel, index:Byte Ptr)
		Local item:QStandardItem = obj.itemFromIndex(QModelIndex._create(index))
		If item Then
			Return item.qObjectPtr
		Else
			Return Null
		End If
	End Function

	Function _indexFromItem:Byte Ptr(obj:QStandardItemModel, item:QStandardItem)
		Local index:QModelIndex = obj.indexFromItem(item)
		If index Then
			Return index.qObjectPtr
		Else
			Return Null
		End If
	End Function

	Function _columnCount:Int(obj:QStandardItemModel, index:Byte Ptr)
		Return obj.columnCount(QModelIndex._create(index))
	End Function
	
	Function _rowCount:Int(obj:QStandardItemModel, index:Byte Ptr)
		Return obj.rowCount(QModelIndex._create(index))
	End Function
	
	Function _setDataInt:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int, value:Int)
		Return obj.setDataInt(QModelIndex._create(index), value, role)
	End Function
	
	Function _setDataString:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int, value:String)
		Return obj.setDataObject_(QModelIndex._create(index), role, value)
	End Function
	
	Function _setDataObject:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int, value:Object)
		Return obj.setDataObject_(QModelIndex._create(index), role, value)
	End Function
	
	Function _setDataColor:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int, color:Byte Ptr)
		Return obj.setDataObject_(QModelIndex._create(index), role, QColor._create(color))
	End Function
	
	Function _setDataIcon:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int, icon:Byte Ptr)
		Return obj.setDataObject_(QModelIndex._create(index), role, QIcon._create(icon))
	End Function
	
	Function _setDataPixmap:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int, pixmap:Byte Ptr)
		Return obj.setDataObject_(QModelIndex._create(index), role, QPixmap._create(pixmap))
	End Function
	
	Function _setDataBrush:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int, brush:Byte Ptr)
		Return obj.setDataObject_(QModelIndex._create(index), role, QBrush._create(brush))
	End Function
	
	Function _setDataFont:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int, font:Byte Ptr)
		Return obj.setDataObject_(QModelIndex._create(index), role, QFont._create(font))
	End Function
	
	Function _getDataInt:Int(obj:QStandardItemModel, index:Byte Ptr, role:Int)
		Return obj.getDataInt(QModelIndex._create(index), role)
	End Function
	
	Function _getDataString:String(obj:QStandardItemModel, index:Byte Ptr, role:Int)
		Return obj.getDataString(QModelIndex._create(index), role)
	End Function
	
	Function _getDataObject:Object(obj:QStandardItemModel, index:Byte Ptr, role:Int)
		Return obj.getDataObject(QModelIndex._create(index), role)
	End Function
	
	Function _getDataType:Byte Ptr(obj:QStandardItemModel, index:Byte Ptr, role:Int, _type:Int Ptr)
		Local data:Object = obj.getDataObject(QModelIndex._create(index), role)
		
		If QColor(data) Then
			_type[0] = QVariant.Type_Color
			Return QColor(data).qObjectPtr
		Else If QIcon(data) Then
			_type[0] = QVariant.Type_Icon
			Return QIcon(data).qObjectPtr
		Else If QPixmap(data) Then
			_type[0] = QVariant.Type_Pixmap
			Return QPixmap(data).qObjectPtr
		Else If QBrush(data) Then
			_type[0] = QVariant.Type_Brush
			Return QBrush(data).qObjectPtr
		Else If QFont(data) Then
			_type[0] = QVariant.Type_Font
			Return QFont(data).qObjectPtr
		Else
			Return Null
		End If
	End Function
		
	Function _insertRows:Int(obj:QStandardItemModel, row:Int, count:Int, parent:Byte Ptr)
		Return obj.insertRows(row, count, QModelIndex._create(parent))
	End Function

	Function _removeRows:Int(obj:QStandardItemModel, row:Int, count:Int, parent:Byte Ptr)
		Return obj.removeRows(row, count, QModelIndex._create(parent))
	End Function
	
	
	

	' SIGNAL : itemChanged
	Function _OnItemChanged(obj:QStandardItemModel, item:Byte Ptr)
		obj._InvokeSignals("itemChanged", [QStandardItem.castToObj(item)])
	End Function

	' SIGNAL : columnsAboutToBeInserted
	Function _OnColumnsAboutToBeInserted(obj:QStandardItemModel, parent:Byte Ptr, _start:Int, _end:Int)
		obj._InvokeSignals("columnsAboutToBeInserted", [Object(QModelIndex._create(parent)), Object(String(_start)), Object(String(_end))])
	End Function

	' SIGNAL : columnsAboutToBeMoved
	Function _OnColumnsAboutToBeMoved(obj:QStandardItemModel, sourceParent:Byte Ptr, sourceStart:Int, sourceEnd:Int, destinationParent:Byte Ptr, destinationColumn:Int)
		obj._InvokeSignals("columnsAboutToBeMoved", [Object(QModelIndex._create(sourceParent)), Object(String(sourceStart)), Object(String(sourceEnd)), Object(QModelIndex._create(destinationParent)), Object(String(destinationColumn))])
	End Function

	' SIGNAL : columnsAboutToBeRemoved
	Function _OnColumnsAboutToBeRemoved(obj:QStandardItemModel, parent:Byte Ptr, _start:Int, _end:Int)
		obj._InvokeSignals("columnsAboutToBeRemoved", [Object(QModelIndex._create(parent)), Object(String(_start)), Object(String(_end))])
	End Function

	' SIGNAL : columnsInserted
	Function _OnColumnsInserted(obj:QStandardItemModel, parent:Byte Ptr, _start:Int, _end:Int)
		obj._InvokeSignals("columnsInserted", [Object(QModelIndex._create(parent)), Object(String(_start)), Object(String(_end))])
	End Function

	' SIGNAL : columnsMoved
	Function _OnColumnsMoved(obj:QStandardItemModel, sourceParent:Byte Ptr, sourceStart:Int, sourceEnd:Int, destinationParent:Byte Ptr, destinationColumn:Int)
		obj._InvokeSignals("columnsMoved", [Object(QModelIndex._create(sourceParent)), Object(String(sourceStart)), Object(String(sourceEnd)), Object(QModelIndex._create(destinationParent)), Object(String(destinationColumn))])
	End Function

	' SIGNAL : columnsRemoved
	Function _OnColumnsRemoved(obj:QStandardItemModel, parent:Byte Ptr, _start:Int, _end:Int)
		obj._InvokeSignals("columnsRemoved", [Object(QModelIndex._create(parent)), Object(String(_start)), Object(String(_end))])
	End Function

	' SIGNAL : dataChanged
	Function _OnDataChanged(obj:QStandardItemModel, topLeft:Byte Ptr, bottomRight:Byte Ptr)
		obj._InvokeSignals("dataChanged", [QModelIndex._create(topLeft), QModelIndex._create(bottomRight)])
	End Function

	' SIGNAL : headerDataChanged
	Function _OnHeaderDataChanged(obj:QStandardItemModel, orientation:Int, _first:Int, _last:Int)
		obj._InvokeSignals("headerDataChanged", [String(orientation), String(_first), String(_last)])
	End Function

	' SIGNAL : layoutAboutToBeChanged
	Function _OnLayoutAboutToBeChanged(obj:QStandardItemModel)
		obj._InvokeSignals("layoutAboutToBeChanged", Null)
	End Function

	' SIGNAL : layoutChanged
	Function _OnLayoutChanged(obj:QStandardItemModel)
		obj._InvokeSignals("layoutChanged", Null)
	End Function

	' SIGNAL : modelAboutToBeReset
	Function _OnModelAboutToBeReset(obj:QStandardItemModel)
		obj._InvokeSignals("modelAboutToBeReset", Null)
	End Function

	' SIGNAL : modelReset
	Function _OnModelReset(obj:QStandardItemModel)
		obj._InvokeSignals("modelReset", Null)
	End Function

	' SIGNAL : rowsAboutToBeInserted
	Function _OnRowsAboutToBeInserted(obj:QStandardItemModel, parent:Byte Ptr, _start:Int, _end:Int)
		obj._InvokeSignals("rowsAboutToBeInserted", [Object(QModelIndex._create(parent)), Object(String(_start)), Object(String(_end))])
	End Function

	' SIGNAL : rowsAboutToBeMoved
	Function _OnRowsAboutToBeMoved(obj:QStandardItemModel, sourceParent:Byte Ptr, sourceStart:Int, sourceEnd:Int, destinationParent:Byte Ptr, destinationRow:Int)
		obj._InvokeSignals("rowsAboutToBeMoved", [Object(QModelIndex._create(sourceParent)), Object(String(sourceStart)), Object(String(sourceEnd)), Object(QModelIndex._create(destinationParent)), Object(String(destinationRow))])
	End Function

	' SIGNAL : rowsAboutToBeRemoved
	Function _OnRowsAboutToBeRemoved(obj:QStandardItemModel, parent:Byte Ptr, _start:Int, _end:Int)
		obj._InvokeSignals("rowsAboutToBeRemoved", [Object(QModelIndex._create(parent)), Object(String(_start)), Object(String(_end))])
	End Function

	' SIGNAL : rowsInserted
	Function _OnRowsInserted(obj:QStandardItemModel, parent:Byte Ptr, _start:Int, _end:Int)
		obj._InvokeSignals("rowsInserted", [Object(QModelIndex._create(parent)), Object(String(_start)), Object(String(_end))])
	End Function

	' SIGNAL : rowsMoved
	Function _OnRowsMoved(obj:QStandardItemModel, sourceParent:Byte Ptr, sourceStart:Int, sourceEnd:Int, destinationParent:Byte Ptr, destinationRow:Int)
		obj._InvokeSignals("rowsMoved", [Object(QModelIndex._create(sourceParent)), Object(String(sourceStart)), Object(String(sourceEnd)), Object(QModelIndex._create(destinationParent)), Object(String(destinationRow))])
	End Function

	' SIGNAL : rowsRemoved
	Function _OnRowsRemoved(obj:QStandardItemModel, parent:Byte Ptr, _start:Int, _end:Int)
		obj._InvokeSignals("rowsRemoved", [Object(QModelIndex._create(parent)), Object(String(_start)), Object(String(_end))])
	End Function

End Type

