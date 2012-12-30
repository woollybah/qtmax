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

		Rem
	bbdoc: The string will not be inserted into the combobox.
	End Rem
	Const InsertPolicy_NoInsert:Int = 0
	
	Rem
	bbdoc: The string will be inserted as the first item in the combobox.
	End Rem
	Const InsertPolicy_InsertAtTop:Int = 1
	
	Rem
	bbdoc: The current item will be replaced by the string.
	End Rem
	Const InsertPolicy_InsertAtCurrent:Int = 2
	
	Rem
	bbdoc: The string will be inserted after the last item in the combobox.
	End Rem
	Const InsertPolicy_InsertAtBottom:Int = 3
	
	Rem
	bbdoc: The string is inserted after the current item in the combobox.
	End Rem
	Const InsertPolicy_InsertAfterCurrent:Int = 4
	
	Rem
	bbdoc: The string is inserted before the current item in the combobox.
	End Rem
	Const InsertPolicy_InsertBeforeCurrent:Int = 5
	
	Rem
	bbdoc: The string is inserted in the alphabetic order in the combobox.
	End Rem
	Const InsertPolicy_InsertAlphabetically:Int = 6


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
		bmx_qt_qcombobox_addItem(qObjectPtr, text, userData)
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
		'Local itemId:Long
		'If userData Then
		'	itemId = data.addItem(userData)
		'End If
		bmx_qt_qcombobox_insertitem(qObjectPtr, index, text, userData)
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
		Return bmx_qt_qcombobox_itemdata(qObjectPtr, index)
	End Method
	
	'Method itemDelegate:QAbstractItemDelegate()
	' TODO
	'End Method
	
	Method itemIcon:QIcon(index:Int)
	' TODO
	End Method
	
	Method itemText:String(index:Int)
		Return bmx_qt_qcombobox_itemtext(qObjectPtr, index)
	End Method
	
	Method lineEdit:QLineEdit()
	' TODO
	End Method
	
	Method maxCount:Int()
		Return bmx_qt_qcombobox_maxcount(qObjectPtr)
	End Method
	
	Method maxVisibleItems:Int()
		Return bmx_qt_qcombobox_maxvisibleitems(qObjectPtr)
	End Method
	
	Method minimumContentsLength:Int()
		Return bmx_qt_qcombobox_minimumcontentslength(qObjectPtr)
	End Method

	'Method model:QAbstractItemModel()
	' TODO
	'End Method

	Method modelColumn:Int()
		Return bmx_qt_qcombobox_modelcolumn(qObjectPtr)
	End Method

	Method removeItem(index:Int)
		bmx_qt_qcombobox_removeitem(qObjectPtr, index)
	End Method

	'Method rootModelIndex:QModelIndex()
	' TODO
	'End Method

	Method setCompleter(completer:QCompleter)
	' TODO
	End Method

	Method setDuplicatesEnabled(enable:Int)
		bmx_qt_qcombobox_setduplicatesenabled(qObjectPtr, enable)
	End Method

	Method setEditable(editable:Int)
		bmx_qt_qcombobox_seteditable(qObjectPtr, editable)
	End Method

	Method setFrame(value:Int)
		bmx_qt_qcombobox_setframe(qObjectPtr, value)
	End Method

	Method setIconSize(w:Int, h:Int)
		bmx_qt_qcombobox_seticonsize(qObjectPtr, w, h)
	End Method

	Method setInsertPolicy(policy:Int)
		bmx_qt_qcombobox_setinsertpolicy(qObjectPtr, policy)
	End Method

	Method setItemData(index:Int, value:Object)
		bmx_qt_qcombobox_setitemdata(qObjectPtr, index, value)
	End Method

	'Method setItemDelegate(delegate:QAbstractItemDelegate)
	' TODO
	'End Method

	Method setItemIcon(index:Int, icon:QIcon)
		bmx_qt_qcombobox_setitemicon(qObjectPtr, index, icon.qObjectPtr)
	End Method

	Method setItemText(index:Int, text:String)
		bmx_qt_qcombobox_setitemtext(qObjectPtr, index, text)
	End Method

	Method setLineEdit(edit:QLineEdit)
	' TODO
	End Method

	Method setMaxCount(value:Int)
		bmx_qt_qcombobox_setmaxcount(qObjectPtr, value)
	End Method

	Method setMaxVisibleItems(maxItems:Int)
		bmx_qt_qcombobox_setmaxvisibleitems(qObjectPtr, maxItems)
	End Method

	Method setMinimumContentsLength(characters:Int)
		bmx_qt_qcombobox_setminimumcontentslength(qObjectPtr, characters)
	End Method

	Method setModel(model:QAbstractItemModel)
		bmx_qt_qcombobox_setmodel(qObjectPtr, model.qObjectPtr)
	End Method

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
		'data.clear()
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



	' DEFAULT EVENT HANDLERS
	
	' QProgressBar
	' QWidget
	Method actionEvent(event:QActionEvent)
		bmx_qt_qcombobox_default_actionevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method changeEvent(event:QEvent)
		bmx_qt_qcombobox_default_changeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method closeEvent(event:QCloseEvent)
		bmx_qt_qcombobox_default_closeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method contextMenuEvent(event:QContextMenuEvent)
		bmx_qt_qcombobox_default_contextmenuevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragEnterEvent(event:QDragEnterEvent)
		bmx_qt_qcombobox_default_dragenterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragLeaveEvent(event:QDragLeaveEvent)
		bmx_qt_qcombobox_default_dragleaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dragMoveEvent(event:QDragMoveEvent)
		bmx_qt_qcombobox_default_dragmoveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method dropEvent(event:QDropEvent)
		bmx_qt_qcombobox_default_dropevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method enterEvent(event:QEvent)
		bmx_qt_qcombobox_default_enterevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusInEvent(event:QFocusEvent)
		bmx_qt_qcombobox_default_focusinevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusNextChild:Int()
		Return bmx_qt_qcombobox_default_focusnextchild(qObjectPtr)
	End Method 

	Method focusNextPrevChild:Int(_next:Int)
		Return bmx_qt_qcombobox_default_focusnextprevchild(qObjectPtr, _next)
	End Method

	Method focusOutEvent(event:QFocusEvent)
		bmx_qt_qcombobox_default_focusoutevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method focusPreviousChild:Int()
		Return bmx_qt_qcombobox_default_focuspreviouschild(qObjectPtr)
	End Method 

	Method hideEvent(event:QHideEvent)
		bmx_qt_qcombobox_default_hideevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method inputMethodEvent(event:QInputMethodEvent)
		bmx_qt_qcombobox_default_inputmethodevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyPressEvent(event:QKeyEvent)
		bmx_qt_qcombobox_default_keypressevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method keyReleaseEvent(event:QKeyEvent)
		bmx_qt_qcombobox_default_keyreleaseevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method leaveEvent(event:QEvent)
		bmx_qt_qcombobox_default_leaveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method mouseDoubleClickEvent(event:QMouseEvent)
		bmx_qt_qcombobox_default_mousedoubleclickevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseMoveEvent(event:QMouseEvent)
		bmx_qt_qcombobox_default_mousemoveevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mousePressEvent(event:QMouseEvent)
		bmx_qt_qcombobox_default_mousepressevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method mouseReleaseEvent(event:QMouseEvent)
		bmx_qt_qcombobox_default_mousereleaseevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method moveEvent(event:QMoveEvent)
		bmx_qt_qcombobox_default_moveevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method paintEvent(event:QPaintEvent)
		bmx_qt_qcombobox_default_paintevent(qObjectPtr, event.qObjectPtr)
	End Method

	Method resizeEvent(event:QResizeEvent)
		bmx_qt_qcombobox_default_resizeevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method showEvent(event:QShowEvent)
		bmx_qt_qcombobox_default_showevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method tabletEvent(event:QTabletEvent)
		bmx_qt_qcombobox_default_tabletevent(qObjectPtr, event.qObjectPtr)
	End Method
	
	Method wheelEvent(event:QWheelEvent)
		bmx_qt_qcombobox_default_wheelevent(qObjectPtr, event.qObjectPtr)
	End Method

	' QObject
	Method event:Int(evt:QEvent)
		Return bmx_qt_qcombobox_default_event(qObjectPtr, evt.qObjectPtr)
	End Method

	Method timerEvent(event:QTimerEvent)
		bmx_qt_qcombobox_default_timerevent(qObjectPtr, event.qObjectPtr)
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

