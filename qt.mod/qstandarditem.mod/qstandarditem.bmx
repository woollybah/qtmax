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

Module Qt.QStandardItem

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


' Implementation Note :
'
'  
'

Type QStandardItem

	Field roles:TCleanMap = New TCleanMap
	Field children:TItemList = New TItemList
	Field parentItem:QStandardItem
	Field rows:Int
	Field columns:Int = 1
	Field itemFlags:Int = Qt_ItemIsSelectable | Qt_ItemIsEnabled | Qt_ItemIsEditable | Qt_ItemIsDragEnabled | Qt_ItemIsDropEnabled
	Field lastIndexOf:Int = 2
	
	Field model:QAbstractItemModel
	
	Field qObjectPtr:Byte Ptr
	
	
	Function _create:QStandardItem(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QStandardItem = New QStandardItem
			this.qObjectPtr = qObjectPtr
			Return this
		End If
		Return Null
	End Function
	
	' internal
	Method CreateEmpty:QStandardItem()
		qObjectPtr = bmx_qt_qstandarditem_create(Self)
		Return Self
	End Method
	
	
	Function CreateStandardItem:QStandardItem(text:String, icon:QIcon = Null)
		Return New QStandardItem.Create(text, icon)
	End Function
	
	Method Create:QStandardItem(text:String, icon:QIcon = Null)
		qObjectPtr = bmx_qt_qstandarditem_create(Self)
		setText(text)
		If icon Then
			setIcon(icon)
		End If
		Return Self
	End Method
	
	
	Method setDataInternal(role:Int, data:Object)

		' edit and display are the same...
		If role = Qt_EditRole Then
			role = Qt_DisplayRole
		End If

		Local r:TRole = TRole.getRole(role)
		roles.Insert(r, data)
		
		If model Then
			model._itemChanged(Self)
		End If
	End Method
	
	Method getDataInternal:Object(role:Int)

		' edit and display are the same...
		If role = Qt_EditRole Then
			role = Qt_DisplayRole
		End If

		Local r:TRole = TRole.getRole(role)
		Return roles.ValueForKey(r)
	End Method
	
	
	Method accessibleDescription:String()
		Return String(getDataInternal(Qt_AccessibleDescriptionRole))
	End Method
	
	Method accessibleText:String()
		Return String(getDataInternal(Qt_AccessibleTextRole))
	End Method
	
	Method appendColumn(items:TList)
	' TODO
	End Method
	
	Method appendRowItems(items:TList)
	' TODO
	End Method
	
	Method appendRow(item:QStandardItem)
		insertRow(rowCount(), item)
	End Method
	
	Method appendRows(items:TList)
	' TODO
	End Method
	
	Method background:QBrush()
	' TODO
	End Method
	
	Method checkState:Int()
		'Return bmx_qt_qstandarditem_checkstate(qObjectPtr)
	End Method
	
	Method child:QStandardItem(row:Int, column:Int = 0)
		Local index:Int = childIndex(row, column)
		If index = -1 Then
			Return Null
		End If
		Return children.itemAt(index)
	End Method
	
	Method childIndex:Int(row:Int, column:Int)
		If (row < 0) Or (column < 0) Or (row >= rowCount()) Or (column >= columnCount()) Then
			Return -1
		End If
		Return (row * columnCount()) + column
	End Method

	Method childIndexItem:Int(child:QStandardItem)
		Local start:Int = Max(0, lastIndexOf - 2)
		lastIndexOf = indexOfChild(child, start)
		If lastIndexOf = -1 And start <> 0 Then
			lastIndexOf = lastIndexOfChild(child, start)
		End If
		Return lastIndexOf
	End Method

	Method column:Int()
		'Return bmx_qt_qstandarditem_column(qObjectPtr)
	End Method
	
	Method columnCount:Int()
		Return columns
	End Method
	
	Method data:Object()
		Return getDataInternal(Qt_UserRole)
	End Method
	
	Method flags:Int()
		Return itemFlags
	End Method
	
	Method font:QFont()
	' TODO
	End Method
	
	Method foreground:QBrush()
	' TODO
	End Method
	
	Method hasChildren:Int()
		'Return bmx_qt_qstandarditem_haschildren(qObjectPtr)
	End Method
	
	Method icon:QIcon()
	' TODO
	End Method
	
	Method indexOfChild:Int(child:QStandardItem, start:Int)
		While start < children.length()
			If children.itemAt(start) = child Then
				Return start
			End If
			
			start :+ 1
		Wend
		
		Return -1
	End Method

	Method lastIndexOfChild:Int(child:QStandardItem, start:Int)
		Local index:Int = start
		While index >= 0
			If children.itemAt(index) = child Then
				Return index
			End If
			
			index :- 1
		Wend
		
		Return -1
	End Method
	
	'Method index:QModelIndex()
	' TODO
	'End Method
	
	Method insertColumn(column:Int, items:TList)
	' TODO
	End Method
	
	Method insertColumns(column:Int, count:Int)
	' TODO
	End Method
	
	Method insertRowItems(row:Int, items:TList)
	' TODO
	End Method
	
	Method insertRow(row:Int, item:QStandardItem)
		If row >= 0 Then
			insertRows(row, 1)
			
			item.parentItem = Self
			item.model = model
			
			Local index:Int = childIndex(row, 0)
			children.SetItemAt(index, item)
		End If
	End Method
	
	Method insertRowsItems(row:Int, items:TList)
	' TODO
	End Method
	
	Method insertRows:Int(row:Int, count:Int)
'DebugLog "Item::insertRows(" + row + ", " + count + ")"
		If (count < 1) Or (row > rowCount()) Then
			Return False
		End If
		
		' for append new rows
		If row < 0 Then
			row = rowCount()
		End If
		
		If model Then
			model._doBeginInsertRows(Self, row, row + count - 1)
		End If
		
		rows :+ count
		
		children.InsertRows(row, count)
		
		If model Then
			model._doEndInsertRows(Self, row, count)
		End If
		
		Return True
	End Method

	Method removeRows:Int(row:Int, count:Int)
		If (count < 1) Or (row < 0) Or ((row + count) > rowCount()) Then
			Return False
		End If
		
		If model Then
			model._doBeginRemoveRows(Self, row, row + count - 1)
		End If
		
		Local _start:Int = childIndex(row, 0)
		Local _end:Int = count * columnCount()
		
		For Local i:Int = _start Until _start + _end
			Local item:QStandardItem = children.itemAt(i)
			If item Then
				item.Free()
			End If
		Next
		
		rows :- count
		
		children.RemoveRows(row, count)
		
		If model Then
			model._doEndRemoveRows(Self, row, count)
		End If
		
		Return True
	End Method
	
	Method isCheckable:Int()
		'Return bmx_qt_qstandarditem_ischeckable(qObjectPtr)
	End Method
	
	Method isDragEnabled:Int()
		'Return bmx_qt_qstandarditem_isdragenabled(qObjectPtr)
	End Method
	
	Method isDropEnabled:Int()
		'Return bmx_qt_qstandarditem_isdropenabled(qObjectPtr)
	End Method
	
	Method isEditable:Int()
		'Return bmx_qt_qstandarditem_iseditable(qObjectPtr)
	End Method
	
	Method isEnabled:Int()
		'Return bmx_qt_qstandarditem_isenabled(qObjectPtr)
	End Method
	
	Method isSelectable:Int()
		'Return bmx_qt_qstandarditem_isselectable(qObjectPtr)
	End Method
	
	Method isTristate:Int()
		'Return bmx_qt_qstandarditem_istristate(qObjectPtr)
	End Method

	Method itemFromIndex:QStandardItem(index:QModelIndex)

		If (index.row() < 0) Or (index.column() < 0) Then
	        Return Null
		End If
		Local parent:QStandardItem = QStandardItem.castToObj(index.internalPointer())
		If Not parent Then
			Return Null
		End If
		
		Local item:QStandardItem = parent.child(index.row(), index.column())
		
		' create one if it doesn't exist?
		If Not item Then
			item = New QStandardItem.CreateEmpty()
			parent.setChildRC(index.row(), index.column(), item)
		End If
		
		Return item
	End Method
	
	'Method model:QStandardItemModel()
	' TODO
	'End Method
	
	Method parent:QStandardItem()
		Return parentItem
	End Method
	
	Method pos(row:Int Var, column:Int Var)
		If parentItem Then
			Local index:Int = parentItem.childIndexItem(Self)
			If index <> -1 Then
				row = index / parentItem.columnCount()
				column = index Mod parentItem.columnCount()
				Return
			End If
		End If
		
		row = -1
		column = -1
	End Method
	
	Method removeColumn(column:Int)
		removeColumns(column, 1)
	End Method
	
	Method removeColumns(column:Int, count:Int)
		'bmx_qt_qstandarditem_removecolumns(qObjectPtr, column, count)
	End Method
	
	Method removeRow(row:Int)
		removeRows(row, 1)
	End Method
	
	Method row:Int()
		Return parentItem.indexOfChild(Self, 0)
	End Method
	
	Method rowCount:Int()
		Return rows
		'Return bmx_qt_qstandarditem_rowcount(qObjectPtr)
	End Method
	
	Method setAccessibleDescription(accessibleDescription:String)
		setDataInternal(Qt_AccessibleDescriptionRole, accessibleDescription)
		'bmx_qt_qstandarditem_setaccessibledescription(qObjectPtr, accessibleDescription)
	End Method
	
	Method setAccessibleText(accessibleText:String)
		setDataInternal(Qt_AccessibleTextRole, accessibleText)
		'bmx_qt_qstandarditem_setaccessibletext(qObjectPtr, accessibleText)
	End Method
	
	Method setBackground(brush:QBrush)
	' TODO
	End Method
	
	Method setCheckState(state:Int)
		Local v:TInt = New TInt
		v.value = state
		setDataInternal(Qt_CheckStateRole, v)
		'bmx_qt_qstandarditem_setcheckstate(qObjectPtr, state)
	End Method
	
	Method setCheckable(checkable:Int)
		If checkable Then
			itemFlags :| Qt_ItemIsUserCheckable
		Else
			itemFlags :~ Qt_ItemIsUserCheckable
		End If
'		bmx_qt_qstandarditem_setcheckable(qObjectPtr, checkable)
	End Method
	
	Method setChildRC(row:Int, column:Int, item:QStandardItem)
'DebugLog "setChildRC"
		If row < 0 Or column < 0 Then
			Return
		End If
		
		If rows <= row Then
	        setRowCount(row + 1)
		End If
		
		If columns <= column Then
			setColumnCount(column + 1)
		End If
		
		Local index:Int = childIndex(row, column)
		
		If item Then
			item.parentItem = Self
		End If
		
		children.SetItemAt(index, item)
		
	End Method
	
	Method setChild(row:Int, item:QStandardItem)
		'bmx_qt_qstandarditem_setchild(qObjectPtr, row, item.qObjectPtr)
	End Method
	
	Method setColumnCount(columns:Int)
		If Self.columns = columns Then
			Return
		End If
		
		If Self.columns < columns Then
			' insert columns
		Else
			' remove columns
		End If
		'bmx_qt_qstandarditem_setcolumncount(qObjectPtr, columns)
	End Method
	
	Method setData(value:Object)
		setDataInternal(Qt_UserRole, value)
		'bmx_qt_qstandarditem_setdata(qObjectPtr, value)
	End Method
	
	Method setDragEnabled(dragEnabled:Int)
		If dragEnabled Then
			itemFlags :| Qt_ItemIsDragEnabled
		Else
			itemFlags :~ Qt_ItemIsDragEnabled
		End If
	End Method
	
	Method setDropEnabled(dropEnabled:Int)
		If dropEnabled Then
			itemFlags :| Qt_ItemIsDropEnabled
		Else
			itemFlags :~ Qt_ItemIsDropEnabled
		End If
	End Method
	
	Method setEditable(editable:Int)
		If editable Then
			itemFlags :| Qt_ItemIsEditable
		Else
			itemFlags :~ Qt_ItemIsEditable
		End If
	End Method
	
	Method setEnabled(enabled:Int)
		If enabled Then
			itemFlags :| Qt_ItemIsEnabled
		Else
			itemFlags :~ Qt_ItemIsEnabled
		End If
	End Method
	
	Method setFlags(flags:Int)
		itemFlags = flags
	End Method
	
	Method setFont(font:QFont)
	' TODO
	End Method
	
	Method setForeground(brush:QBrush)
	' TODO
	End Method
	
	Method setIcon(icon:QIcon)
		setDataInternal(Qt_DecorationRole, icon)
	End Method
	
	Method setRowCount(rows:Int)
		If Self.rows = rows Then
			Return
		End If
		'bmx_qt_qstandarditem_setrowcount(qObjectPtr, rows)
	End Method
	
	Method setSelectable(selectable:Int)
		If selectable Then
			itemFlags :| Qt_ItemIsSelectable
		Else
			itemFlags :~ Qt_ItemIsSelectable
		End If
	End Method
	
	Method setSizeHint(width:Int, height:Int)
		'bmx_qt_qstandarditem_setsizehint(qObjectPtr, width, height)
	End Method
	
	Method setStatusTip(statusTip:String)
		setDataInternal(Qt_StatusTipRole, statusTip)
	End Method
	
	Method setText(text:String)
		setDataInternal(Qt_DisplayRole, text)
	End Method
	
	Method setTextAlignment(alignment:Int)
		Local v:TInt = New TInt
		v.value = alignment
		setDataInternal(Qt_TextAlignmentRole, v)
	End Method
	
	Method setToolTip(toolTip:String)
		setDataInternal(Qt_ToolTipRole, toolTip)
	End Method
	
	Method setTristate(tristate:Int)
		If tristate Then
			itemFlags :| Qt_ItemIsTristate
		Else
			itemFlags :~ Qt_ItemIsTristate
		End If
	End Method
	
	Method setWhatsThis(whatsThis:String)
		setDataInternal(Qt_WhatsThisRole, whatsThis)
	End Method
	
	Method sizeHint(width:Int Var, height:Int Var)
	' TODO
	End Method
	
	Method sortChildren(column:Int, order:Int = Qt_AscendingOrder)
	' TODO
	End Method
	
	Method statusTip:String()
		Return String(getDataInternal(Qt_StatusTipRole))
	End Method
	
	Method takeChild:QStandardItem(row:Int, column:Int = 0)
	' TODO
	End Method
	
	Method takeColumn:TList(column:Int)
	' TODO
	End Method
	
	Method takeRow:TList(row:Int)
	' TODO
	End Method
	
	Method text:String()
		Return String(getDataInternal(Qt_DisplayRole))
	End Method
	
	Method textAlignment:Int()
		Local value:TInt = TInt(getDataInternal(Qt_TextAlignmentRole))
		If value Then
			Return value.value
		End If
		Return Qt_AlignLeft
	End Method
	
	Method toolTip:String()
		Return String(getDataInternal(Qt_ToolTipRole))
	End Method
	
	Method itemType:Int()
		'Return bmx_qt_qstandarditem_type(qObjectPtr)
	End Method
	
	Method whatsThis:String()
		Return String(getDataInternal(Qt_WhatsThisRole))
	End Method


	Function _columnCount:Int(obj:QStandardItem)
		Return obj.columnCount()
	End Function

	Function _rowCount:Int(obj:QStandardItem)
		Return obj.rowCount()
	End Function


	Function _Free(obj:QStandardItem)
		obj.qObjectPtr = Null
	End Function
	
	Function castToObj:QStandardItem(item:Byte Ptr)
		Return QStandardItem(bmx_qt_qstandarditem_casttoobj(item))
	End Function
	
	Method ToString:String()
		Return text()
	End Method
	
	' tody up for removal
	Method Free()
		If qObjectPtr Then
			model = Null
			parentItem = Null
	
			' Free all children
			For Local i:Int = 0 Until children.items.length
				Local item:QStandardItem = children.items[i]
				If item Then
					item.Free()
				End If
			Next
			
			children.Clear()
			children = Null
			
			roles.Clear()
	
			bmx_qt_qstandarditem_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		If qObjectPtr Then
			DebugLog "Delete before Free! The model is broken :-("
		End If
	End Method
	
End Type


Type TRole
	Global roles:TRole[100]

	Field id:Int
	
	Function getRole:TRole(index:Int)
		Local role:TRole = roles[index]
		If Not role Then
			role = New TRole
			role.id = index
			roles[index] = role
		End If
		
		Return role
	End Function
	
	Method Compare:Int(obj:Object)
		Return id - TRole(obj).id
	End Method
	
End Type

Type TCleanMap
	Field map:TMap = New TMap
	
	' inserting a null object will remove the entry.
	Method Insert(key:Object, value:Object)
		If value = Null Then
			map.Remove(key)
		Else
			map.Insert(key, value)
		End If
	End Method
	
	Method ValueForKey:Object(key:Object)
		Return map.ValueForKey(key)
	End Method
	
	Method Clear()
		map.Clear()
	End Method
	
End Type

' helper types for storing numbers as objects!
Type TNumber
End Type

Type TInt Extends TNumber
	Field value:Int
End Type

Type TFloat Extends TNumber
	Field value:Float
End Type

Type TShort Extends TNumber
	Field value:Short
End Type

Type TLong Extends TNumber
	Field value:Long
End Type

Type TDouble Extends TNumber
	Field value:Double
End Type

Type TByte Extends TNumber
	Field value:Byte
End Type

' where all the magic happens.
' keeps track of child items and looks after insertions and removals.
Type TItemList

	Field items:QStandardItem[0]

	Method InsertRows(index:Int, count:Int)
		'DebugLog "TItemList::InsertRows(" + index + ", " + count + ")"
		Local size:Int = items.length
		
		' expand if necessary
		If index >= size Then
			items = items[..index + count]
		Else
			If index = 0 Then
				items = New QStandardItem[count] + items
			Else
				items = items[..index] + New QStandardItem[count] + items[index..]
			End If
		End If
	End Method
	
	Method RemoveRows(index:Int, count:Int)
		Local toEnd:Int = False
		
		If index + count > items.length Then
			toEnd = True
		End If
		
		If index = 0 Then
			If toEnd Then
				items = New QStandardItem[0]
			Else
				items = items[1..]
			End If
		Else
			If toEnd Then
				items = items[..index]
			Else
				items = items[..index] + items[index + count..]
			End If
		End If
	End Method

	Method InsertItemAt(index:Int, value:QStandardItem)

		InsertRows(index, 1)
		SetItemAt(index, value)
	
	End Method
		
	Method SetItemAt(index:Int, value:QStandardItem)
		' TODO : if item exists here already.. we need to free it up properly?
		items[index] = value
	End Method
	
	Method itemAt:QStandardItem(index:Int)
		If items.length > index Then
			Return items[index]
		End If
		Return Null
	End Method
	
	Method Clear()
		For Local i:Int = 0 Until items.length
			items[i] = Null
		Next
	End Method
	
	Method length:Int()
		Return items.length
	End Method
	
	' for debugging the list
	Method dump()
		For Local i:Int = 0 Until items.length
			Local item:QStandardItem = items[i]
			If item Then
				DebugLog i + " : " + item.toString()
			Else
				DebugLog i + " : ..."
			End If
		Next
		DebugLog ""
	End Method

End Type

