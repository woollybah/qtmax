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

Module Qt.QAbstractItemView

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QAbstractItemView Extends QAbstractScrollArea

	Method setModel(model:QAbstractItemModel)
		bmx_qt_qabstractitemview_setmodel(qObjectPtr, model.qObjectPtr)
	End Method

End Type

Type QAbstractItemDelegate Extends QObject

	Method createEditorQWidget(parent:QWidget, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	
	Method editorEvent:Int(event:QEvent, model:QAbstractItemModel, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	
	Method paint(painter:QPainter, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	
	Method setEditorData(editor:QWidget, index:QModelIndex)
	End Method
	
	Method setModelData(editor:QWidget, model:QAbstractItemModel, index:QModelIndex)
	End Method
	
	Method sizeHint(option:QStyleOptionViewItem, index:QModelIndex, w:Int Var, h:Int Var)
	End Method
	
	Method updateEditorGeometry(editor:QWidget, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	

	Method helpEvent:Int(event:QHelpEvent, view:QAbstractItemView, option:QStyleOptionViewItem, index:QModelIndex)
	End Method
	
End Type

