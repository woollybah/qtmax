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

Module Qt.QAbstractScrollArea

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"



Type QAbstractScrollArea Extends QFrame

	Method addScrollBarWidget(widget:QWidget, alignment:Int)
		bmx_qt_qabstractscrollarea_addscrollbarwidget(qObjectPtr, widget.qObjectPtr, alignment)
	End Method
	
	Method cornerWidget:QWidget()
		Return QWidget._find(bmx_qt_qabstractscrollarea_cornerwidget(qObjectPtr))
	End Method
	
	Method horizontalScrollBar:QScrollBar()
		Return QScrollBar._find(bmx_qt_qabstractscrollarea_horizontalscrollbar(qObjectPtr))
	End Method
	
	Method horizontalScrollBarPolicy:Int()
		Return bmx_qt_qabstractscrollarea_horizontalscrollbarpolicy(qObjectPtr)
	End Method
	
	Method maximumViewportSize(w:Int Var, h:Int Var)
		bmx_qt_qabstractscrollarea_maximumviewportsize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method scrollBarWidgets:QWidget[](alignment:Int)
		'Return bmx_qt_qabstractscrollarea_scrollbarwidgets(qObjectPtr)
	End Method
	
	Method setCornerWidget(widget:QWidget)
		bmx_qt_qabstractscrollarea_setcornerwidget(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method setHorizontalScrollBar(scrollBar:QScrollBar)
		bmx_qt_qabstractscrollarea_sethorizontalscrollbar(qObjectPtr, scrollBar.qObjectPtr)
	End Method
	
	Method setHorizontalScrollBarPolicy(policy:Int)
		bmx_qt_qabstractscrollarea_sethorizontalscrollbarpolicy(qObjectPtr, policy)
	End Method
	
	Method setVerticalScrollBar(scrollBar:QScrollBar)
		bmx_qt_qabstractscrollarea_setverticalscrollbar(qObjectPtr, scrollBar.qObjectPtr)
	End Method
	
	Method setVerticalScrollBarPolicy(policy:Int)
		bmx_qt_qabstractscrollarea_setverticalscrollbarpolicy(qObjectPtr, policy)
	End Method
	
	Method SetViewport(widget:QWidget)
		bmx_qt_qabstractscrollarea_setviewport(qObjectPtr, widget.qObjectPtr)
	End Method
	
	Method verticalScrollBar:QScrollBar()
		Return QScrollBar._find(bmx_qt_qabstractscrollarea_verticalscrollbar(qObjectPtr))
	End Method
	
	Method verticalScrollBarPolicy:Int()
		Return bmx_qt_qabstractscrollarea_verticalscrollbarpolicy(qObjectPtr)
	End Method
	
	Method viewport:QWidget() 
		Return QWidget._find(bmx_qt_qabstractscrollarea_viewport(qObjectPtr))
	End Method

	
End Type

