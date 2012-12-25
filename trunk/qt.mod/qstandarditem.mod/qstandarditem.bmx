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

Module Qt.QStandardItem

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


' Implementation Note :
'
'  Unlike QObject classes, we don't track QStandardItem* with an attached reference of the BlitMax object.
'  
'

Type QStandardItem

	Field qObjectPtr:Byte Ptr
	
	Function _Create:QStandardItem(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QStandardItem = New QStandardItem
			this.qObjectPtr = qObjectPtr
			Return this
		End If
		Return Null
	End Function

	Function CreateStandardItem:QStandardItem(text:String, icon:QIcon = Null)
		Return New QStandardItem.Create(text, icon)
	End Function
	
	Method Create:QStandardItem(text:String, icon:QIcon = Null)
		If icon Then
			qObjectPtr = bmx_qt_qstandarditem_create(text, icon.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qstandarditem_create(text, Null)
		End If
	End Method
	
	Method accessibleDescription:String()
		Return bmx_qt_qstandarditem_accessibledescription(qObjectPtr)
	End Method
	
	Method accessibleText:String()
		Return bmx_qt_qstandarditem_accessibletext(qObjectPtr)
	End Method
	
	Method appendColumn(items:TList)
	' TODO
	End Method
	
	Method appendRowItems(items:TList)
	' TODO
	End Method
	
	Method appendRow(item:QStandardItem)
		bmx_qt_qstandarditem_appendrow(qObjectPtr, item.qObjectPtr)
	End Method
	
	Method appendRows(items:TList)
	' TODO
	End Method
	
	Method background:QBrush()
	' TODO
	End Method
	
	Method checkState:Int()
		Return bmx_qt_qstandarditem_checkstate(qObjectPtr)
	End Method
	
	Method child:QStandardItem(row:Int, column:Int = 0)
	' TODO
	End Method
	
	Method column:Int()
		Return bmx_qt_qstandarditem_column(qObjectPtr)
	End Method
	
	Method columnCount:Int()
		Return bmx_qt_qstandarditem_columncount(qObjectPtr)
	End Method
	
	Method data:Object()
		Return bmx_qt_qstandarditem_data(qObjectPtr)
	End Method
	
	Method flags:Int()
		Return bmx_qt_qstandarditem_flags(qObjectPtr)
	End Method
	
	Method font:QFont()
	' TODO
	End Method
	
	Method foreground:QBrush()
	' TODO
	End Method
	
	Method hasChildren:Int()
		Return bmx_qt_qstandarditem_haschildren(qObjectPtr)
	End Method
	
	Method icon:QIcon()
	' TODO
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
		bmx_qt_qstandarditem_insertrow(qObjectPtr, row, item.qObjectPtr)
	End Method
	
	Method insertRowsItems(row:Int, items:TList)
	' TODO
	End Method
	
	Method insertRows(row:Int, count:Int)
		bmx_qt_qstandarditem_insertrows(qObjectPtr, row, count)
	End Method
	
	Method isCheckable:Int()
		Return bmx_qt_qstandarditem_ischeckable(qObjectPtr)
	End Method
	
	Method isDragEnabled:Int()
		Return bmx_qt_qstandarditem_isdragenabled(qObjectPtr)
	End Method
	
	Method isDropEnabled:Int()
		Return bmx_qt_qstandarditem_isdropenabled(qObjectPtr)
	End Method
	
	Method isEditable:Int()
		Return bmx_qt_qstandarditem_iseditable(qObjectPtr)
	End Method
	
	Method isEnabled:Int()
		Return bmx_qt_qstandarditem_isenabled(qObjectPtr)
	End Method
	
	Method isSelectable:Int()
		Return bmx_qt_qstandarditem_isselectable(qObjectPtr)
	End Method
	
	Method isTristate:Int()
		Return bmx_qt_qstandarditem_istristate(qObjectPtr)
	End Method
	
	'Method model:QStandardItemModel()
	' TODO
	'End Method
	
	Method parent:QStandardItem()
	' TODO
	End Method
	
	Method removeColumn(column:Int)
		bmx_qt_qstandarditem_removecolumn(qObjectPtr, column)
	End Method
	
	Method removeColumns(column:Int, count:Int)
		bmx_qt_qstandarditem_removecolumns(qObjectPtr, column, count)
	End Method
	
	Method removeRow(row:Int)
		bmx_qt_qstandarditem_removerow(qObjectPtr, row)
	End Method
	
	Method removeRows(row:Int, count:Int)
		bmx_qt_qstandarditem_removerows(qObjectPtr, row, count)
	End Method
	
	Method row:Int()
		Return bmx_qt_qstandarditem_row(qObjectPtr)
	End Method
	
	Method rowCount:Int()
		Return bmx_qt_qstandarditem_rowcount(qObjectPtr)
	End Method
	
	Method setAccessibleDescription(accessibleDescription:String)
		bmx_qt_qstandarditem_setaccessibledescription(qObjectPtr, accessibleDescription)
	End Method
	
	Method setAccessibleText(accessibleText:String)
		bmx_qt_qstandarditem_setaccessibletext(qObjectPtr, accessibleText)
	End Method
	
	Method setBackground(brush:QBrush)
	' TODO
	End Method
	
	Method setCheckState(state:Int)
		bmx_qt_qstandarditem_setcheckstate(qObjectPtr, state)
	End Method
	
	Method setCheckable(checkable:Int)
		bmx_qt_qstandarditem_setcheckable(qObjectPtr, checkable)
	End Method
	
	Method setChildRC(row:Int, column:Int, item:QStandardItem)
		bmx_qt_qstandarditem_setchildrc(qObjectPtr, row, column, item.qObjectPtr)
	End Method
	
	Method setChild(row:Int, item:QStandardItem)
		bmx_qt_qstandarditem_setchild(qObjectPtr, row, item.qObjectPtr)
	End Method
	
	Method setColumnCount(columns:Int)
		bmx_qt_qstandarditem_setcolumncount(qObjectPtr, columns)
	End Method
	
	Method setData(value:Object)
		bmx_qt_qstandarditem_setdata(qObjectPtr, value)
	End Method
	
	Method setDragEnabled(dragEnabled:Int)
		bmx_qt_qstandarditem_setdragenabled(qObjectPtr, dragEnabled)
	End Method
	
	Method setDropEnabled(dropEnabled:Int)
		bmx_qt_qstandarditem_setdropenabled(qObjectPtr, dropEnabled)
	End Method
	
	Method setEditable(editable:Int)
		bmx_qt_qstandarditem_seteditable(qObjectPtr, editable)
	End Method
	
	Method setEnabled(enabled:Int)
		bmx_qt_qstandarditem_setenabled(qObjectPtr, enabled)
	End Method
	
	Method setFlags(flags:Int)
		bmx_qt_qstandarditem_setflags(qObjectPtr, flags)
	End Method
	
	Method setFont(font:QFont)
	' TODO
	End Method
	
	Method setForeground(brush:QBrush)
	' TODO
	End Method
	
	Method setIcon(icon:QIcon)
	' TODO
	End Method
	
	Method setRowCount(rows:Int)
		bmx_qt_qstandarditem_setrowcount(qObjectPtr, rows)
	End Method
	
	Method setSelectable(selectable:Int)
		bmx_qt_qstandarditem_setselectable(qObjectPtr, selectable)
	End Method
	
	Method setSizeHint(width:Int, height:Int)
		bmx_qt_qstandarditem_setsizehint(qObjectPtr, width, height)
	End Method
	
	Method setStatusTip(statusTip:String)
		bmx_qt_qstandarditem_setstatustip(qObjectPtr, statustip)
	End Method
	
	Method setText(text:String)
		bmx_qt_qstandarditem_settext(qObjectPtr, text)
	End Method
	
	Method setTextAlignment(alignment:Int)
		bmx_qt_qstandarditem_settextalignment(qObjectPtr, alignment)
	End Method
	
	Method setToolTip(toolTip:String)
		bmx_qt_qstandarditem_settooltip(qObjectPtr, toolTip)
	End Method
	
	Method setTristate(tristate:Int)
		bmx_qt_qstandarditem_settristate(qObjectPtr, tristate)
	End Method
	
	Method setWhatsThis(whatsThis:String)
		bmx_qt_qstandarditem_setwhatsthis(qObjectPtr, whatsThis)
	End Method
	
	Method sizeHint(width:Int Var, height:Int Var)
	' TODO
	End Method
	
	Method sortChildren(column:Int, order:Int = Qt_AscendingOrder)
	' TODO
	End Method
	
	Method statusTip:String()
		Return bmx_qt_qstandarditem_statustip(qObjectPtr)
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
		Return bmx_qt_qstandarditem_text(qObjectPtr)
	End Method
	
	Method textAlignment:Int()
		Return bmx_qt_qstandarditem_textalignment(qObjectPtr)
	End Method
	
	Method toolTip:String()
		Return bmx_qt_qstandarditem_tooltip(qObjectPtr)
	End Method
	
	Method itemType:Int()
		Return bmx_qt_qstandarditem_type(qObjectPtr)
	End Method
	
	Method whatsThis:String()
		Return bmx_qt_qstandarditem_whatsthis(qObjectPtr)
	End Method


	Function _Free(obj:QStandardItem)
		obj.qObjectPtr = Null
	End Function
	
End Type

