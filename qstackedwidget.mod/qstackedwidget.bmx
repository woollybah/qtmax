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

Module Qt.QStackedWidget

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"


Type QStackedWidget Extends QFrame

	Function CreateStackedWidget:QStackedWidget(parent:QWidget = Null)
		Return New QStackedWidget.Create(parent)
	End Function
	
	Method Create:QStackedWidget(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qstackedwidget_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qstackedwidget_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Method addWidget:Int(widget:QWidget)
		Return bmx_qt_qstackedwidget_addwidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method count:Int()
		Return bmx_qt_qstackedwidget_count(qObjectPtr)
	End Method
	
	Method currentIndex:Int()
		Return bmx_qt_qstackedwidget_currentindex(qObjectPtr)
	End Method
	
	Method currentWidget:QWidget()
		Return QWidget._find(bmx_qt_qstackedwidget_currentwidget(qObjectPtr))
	End Method
	
	Method indexOf:Int(widget:QWidget)
		Return bmx_qt_qstackedwidget_indexof(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method insertWidget:Int(index:Int, widget:QWidget)
		Return bmx_qt_qstackedwidget_insertwidget(qObjectPtr, index, widget.qObjectPtr)
	End Method
	
	Method removeWidget(widget:QWidget)
		bmx_qt_qstackedwidget_removewidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method widget:QWidget(index:Int)
		Return QWidget._find(bmx_qt_qstackedwidget_widget(qObjectPtr, index))
	End Method

	Method setCurrentIndex(index:Int)
		bmx_qt_qstackedwidget_setcurrentindex(qObjectPtr, index)
	End Method
	
	Method setCurrentWidget(widget:QWidget)
		bmx_qt_qstackedwidget_setcurrentwidget(qObjectPtr, widget.qObjectPtr)
	End Method

	' SIGNAL : currentChanged
	Function _OnCurrentChanged(obj:QStackedWidget, index:Int)
		obj._InvokeSignals("currentChanged", [String(index)])
	End Function

	' SIGNAL : widgetRemoved
	Function _OnWidgetRemoved(obj:QStackedWidget, index:Int)
		obj._InvokeSignals("widgetRemoved", [String(index)])
	End Function

End Type

