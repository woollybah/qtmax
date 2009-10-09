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

Module Qt.QWebHistory

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QWebHistory

	Field qObjectPtr:Byte Ptr

	Function _create:QWebHistory(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWebHistory = New QWebHistory
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method back()
		bmx_qt_qwebhistory_back(qObjectPtr)
	End Method
	
	Method backItem:QWebHistoryItem()
		Return QWebHistoryItem._create(bmx_qt_qwebhistory_backitem(qObjectPtr))
	End Method
	
	Method backItems:QWebHistoryItem[](maxItems:Int)
		Return bmx_qt_qwebhistory_backitems(qObjectPtr, maxItems)
	End Method
	
	' private
	Function _setItem(items:QWebHistoryItem[], index:Int, itemPtr:Byte Ptr)
		items[index] = QWebHistoryItem._create(itemPtr)
	End Function
	
	' private
	Function _newItems:QWebHistoryItem[](size:Int)
		Return New QWebHistoryItem[size]
	End Function
	
	Method canGoBack:Int()
		Return bmx_qt_qwebhistory_cangoback(qObjectPtr)
	End Method
	
	Method canGoForward:Int()
		Return bmx_qt_qwebhistory_cangoforward(qObjectPtr)
	End Method
	
	Method clear()
		bmx_qt_qwebhistory_clear(qObjectPtr)
	End Method
	
	Method count:Int()
		Return bmx_qt_qwebhistory_count(qObjectPtr)
	End Method
	
	Method currentItem:QWebHistoryItem()
		Return QWebHistoryItem._create(bmx_qt_qwebhistory_currentitem(qObjectPtr))
	End Method
	
	Method currentItemIndex:Int()
		Return bmx_qt_qwebhistory_currentitemindex(qObjectPtr)
	End Method
	
	Method forward()
		bmx_qt_qwebhistory_forward(qObjectPtr)
	End Method
	
	Method forwardItem:QWebHistoryItem()
		Return QWebHistoryItem._create(bmx_qt_qwebhistory_forwarditem(qObjectPtr))
	End Method
	
	Method forwardItems:QWebHistoryItem[](maxItems:Int)
		Return bmx_qt_qwebhistory_forwarditems(qObjectPtr, maxItems)
	End Method
	
	Method goToItem(item:QWebHistoryItem)
		bmx_qt_qwebhistory_gotoitem(qObjectPtr, item.qObjectPtr)
	End Method
	
	Method itemAt:QWebHistoryItem(index:Int)
		Return QWebHistoryItem._create(bmx_qt_qwebhistory_itemat(qObjectPtr, index))
	End Method
	
	Method items:QWebHistoryItem[]()
		Return bmx_qt_qwebhistory_items(qObjectPtr)
	End Method
	
	Method maximumItemCount:Int()
		Return bmx_qt_qwebhistory_maximumitemcount(qObjectPtr)
	End Method
	
	Method setMaximumItemCount(count:Int)
		bmx_qt_qwebhistory_setmaximumitemcount(qObjectPtr, count)
	End Method

	Method Delete()
		If qObjectPtr Then
			bmx_qt_qwebhistory_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
End Type

Type QWebHistoryItem

	Field qObjectPtr:Byte Ptr

	Function _create:QWebHistoryItem(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QWebHistoryItem = New QWebHistoryItem
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method icon:QIcon()
		Return QIcon._create(bmx_qt_qwebhistoryitem_icon(qObjectPtr))
	End Method
	
	Method isValid:Int()
		Return bmx_qt_qwebhistoryitem_isvalid(qObjectPtr)
	End Method
	
	Method lastVisited:QDateTime()
		Return QDateTime._create(bmx_qt_qwebhistoryitem_lastvisited(qObjectPtr))
	End Method
	
	Method originalUrl:QUrl()
		Return QUrl._create(bmx_qt_qwebhistoryitem_originalurl(qObjectPtr))
	End Method
	
	Method title:String()
		Return bmx_qt_qwebhistoryitem_title(qObjectPtr)
	End Method
	
	Method url:QUrl()
		Return QUrl._create(bmx_qt_qwebhistoryitem_url(qObjectPtr))
	End Method
	
	Method Delete()
		If qObjectPtr Then
			bmx_qt_qwebhistoryitem_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method

End Type


Extern
	Function bmx_qt_qwebhistory_backitems:QWebHistoryItem[](handle:Byte Ptr, maxItems:Int)
	Function bmx_qt_qwebhistory_forwarditems:QWebHistoryItem[](handle:Byte Ptr, maxItems:Int)
	Function bmx_qt_qwebhistory_items:QWebHistoryItem[](handle:Byte Ptr)
End Extern


