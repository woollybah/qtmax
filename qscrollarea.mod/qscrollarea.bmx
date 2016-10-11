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

Module Qt.QScrollArea

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Type QScrollArea Extends QAbstractScrollArea

	Function CreateScrollArea:QScrollArea(parent:QWidget = Null)
	End Function
	
	Method Create:QScrollArea(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qscrollarea_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qscrollarea_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method
	
	Method alignment:Int()
		Return bmx_qt_qscrollarea_alignment(qObjectPtr)
	End Method
	
	Method ensureVisible(x:Int, y:Int, xmargin:Int = 50, ymargin:Int = 50)
		bmx_qt_qscrollarea_ensurevisible(qObjectPtr, x, y, xmargin, ymargin)
	End Method
	
	Method ensureWidgetVisible(childWidget:QWidget, xmargin:Int = 50, ymargin:Int = 50)
		bmx_qt_qscrollarea_ensurewidgetvisible(qObjectPtr, childWidget.qObjectPtr, xmargin, ymargin)
	End Method
	
	Method setAlignment(alignment:Int)
		bmx_qt_qscrollarea_setalignment(qObjectPtr, alignment)
	End Method
	
	Method setWidget(widget:QWidget)
		bmx_qt_qscrollarea_setwidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method setWidgetResizable(resizable:Int)
		bmx_qt_qscrollarea_setwidgetresizable(qObjectPtr, resizable)
	End Method
	
	Method takeWidget:QWidget()
		Return QWidget._find(bmx_qt_qscrollarea_takewidget(qObjectPtr))
	End Method
	
	Method widget:QWidget()
		Return QWidget._find(bmx_qt_qscrollarea_widget(qObjectPtr))
	End Method
	
	Method widgetResizable:Int()
		Return bmx_qt_qscrollarea_widgetresizable(qObjectPtr)
	End Method


End Type

