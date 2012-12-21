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

Module Qt.QComboBox

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QComboBox Extends QWidget

	Field data:QItemList = New QItemList

	Function CreateComboBox:QComboBox(parent:QWidget = Null)
		Return New QComboBox.Create(parent)
	End Function
	
	Method Create:QComboBox(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qcombobox_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qcombobox_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method addItem(text:String, userData:Object = Null)
		Local itemId:Long
		If userData Then
			itemId = data.addItem(userData)
		End If
		bmx_qt_qcombobox_addItem(qObjectPtr, text, itemId)
	End Method
	
	Method addItems(texts:String[])
		bmx_qt_qcombobox_addItems(qObjectPtr, texts)
	End Method
	
	Method count:Int()
		Return bmx_qt_qcombobox_count(qObjectPtr)
	End Method
	
	Method currentIndex:Int()
		Return bmx_qt_qcombobox_currentindex(qObjectPtr)
	End Method
	
	Method currentText:String()
		Return bmx_qt_qcombobox_currenttext(qObjectPtr)
	End Method

	Method duplicatesEnabled:Int()
		Return bmx_qt_qcombobox_duplicatesenabled(qObjectPtr)
	End Method
	
	Method findText:Int(text:String, flags:Int = Qt_MatchExactly | Qt_MatchCaseSensitive)
		Return bmx_qt_qcombobox_findtext(qObjectPtr, text, flags)
	End Method

	Method hasFrame:Int()
		Return bmx_qt_qcombobox_hasframe(qObjectPtr)
	End Method

	Method hidePopup()
		bmx_qt_qcombobox_hidepopup(qObjectPtr)
	End Method

	Method iconSize(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method insertItem(index:Int, text:String, userData:Object = Null)
		Local itemId:Long
		If userData Then
			itemId = data.addItem(userData)
		End If
		bmx_qt_qcombobox_insertitem(qObjectPtr, index, text, itemId)
	End Method
	
	Method insertItems(index:Int, texts:String[])
	' TODO
	End Method

	Method insertPolicy()
	' TODO
	End Method

	Method insertSeparator(index:Int)
	' TODO
	End Method

	Method isEditable:Int()
	' TODO
	End Method

	Method itemData:Object(index:Int)
		Local id:Long
		bmx_qt_qcombobox_itemdata(qObjectPtr, index, Varptr id)
		If id Then
			Return data.itemData(id)
		End If
	End Method
	
	'Method itemDelegate:QAbstractItemDelegate()
	' TODO
	'End Method
	
	Method itemIcon:QIcon(index:Int)
	' TODO
	End Method
	
	Method itemText:String(index:Int)
	' TODO
	End Method
	
	Method lineEdit:QLineEdit()
	' TODO
	End Method
	
	Method maxCount:Int()
	' TODO
	End Method
	
	Method maxVisibleItems:Int()
	' TODO
	End Method
	
	Method minimumContentsLength:Int()
	' TODO
	End Method

	'Method model:QAbstractItemModel()
	' TODO
	'End Method

	Method modelColumn:Int()
	' TODO
	End Method

	Method removeItem(index:Int)
		Local id:Long
		bmx_qt_qcombobox_itemdata(qObjectPtr, index, Varptr id)
		If id Then
			data.removeItem(id)
		End If
		bmx_qt_qcombobox_removeitem(qObjectPtr, index)
	End Method

	'Method rootModelIndex:QModelIndex()
	' TODO
	'End Method

	Method setCompleter(completer:QCompleter)
	' TODO
	End Method

	Method setDuplicatesEnabled(enable:Int)
	' TODO
	End Method

	Method setEditable(editable:Int)
	' TODO
	End Method

	Method setFrame(value:Int)
	' TODO
	End Method

	Method setIconSize(w:Int, h:Int)
	' TODO
	End Method

	Method setInsertPolicy(policy:Int)
	' TODO
	End Method

	Method setItemData(index:Int, value:Object)
		Local id:Long
		bmx_qt_qcombobox_itemdata(qObjectPtr, index, Varptr id)
		data.setItem(id, value)
		bmx_qt_qcombobox_setitemdata(qObjectPtr, index, id)
	End Method

	'Method setItemDelegate(delegate:QAbstractItemDelegate)
	' TODO
	'End Method

	Method setItemIcon(index:Int, icon:QIcon)
	' TODO
	End Method

	Method setItemText(index:Int, text:String)
	' TODO
	End Method

	Method setLineEdit(edit:QLineEdit)
	' TODO
	End Method

	Method setMaxCount(value:Int)
	' TODO
	End Method

	Method setMaxVisibleItems(maxItems:Int)
	' TODO
	End Method

	Method setMinimumContentsLength(characters:Int)
	' TODO
	End Method

	'Method setModel(model:QAbstractItemModel)
	' TODO
	'End Method

	Method setModelColumn(visibleColumn:Int )
	' TODO
	End Method

	'Method setRootModelIndex(index:QModelIndex)
	' TODO
	'End Method

	Method setSizeAdjustPolicy(policy:Int)
	' TODO
	End Method

	Method setValidator(validator:QValidator)
	' TODO
	End Method

	'Method setView(itemView:QAbstractItemView)
	' TODO
	'End Method

	Method showPopup()
	' TODO
	End Method

	Method sizeAdjustPolicy:Int()
	' TODO
	End Method

	Method validator:QValidator()
	' TODO
	End Method

	'Method view:QAbstractItemView()
	' TODO
	'End Method

	Method clear()
		data.clear()
	End Method

	Method clearEditText()
	' TODO
	End Method

	Method setCurrentIndex(index:Int)
		bmx_qt_qcombobox_setcurrentindex(qObjectPtr, index)
	End Method

	Method setEditText(text:String)
	' TODO
	End Method

	' SIGNAL : activated
	Function _OnActivated(obj:QComboBox, index:Int)
		obj._InvokeSignals("activated", [String(index)])
	End Function

	' SIGNAL : currentIndexChanged
	Function _OnCurrentIndexChanged(obj:QComboBox, index:Int)
		obj._InvokeSignals("currentIndexChanged", [String(index)])
	End Function

	' SIGNAL : editTextChanged
	Function _OnEditTextChanged(obj:QComboBox, text:String)
		obj._InvokeSignals("editTextChanged", [text])
	End Function

	' SIGNAL : highlighted
	Function _OnHighlighted(obj:QComboBox, index:Int)
		obj._InvokeSignals("highlighted", [String(index)])
	End Function

End Type

