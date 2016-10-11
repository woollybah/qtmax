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

Module Qt.QTabBar

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009-2013 Bruce A Henderson"


Import "common.bmx"

Rem
bbdoc: Provides a tab bar, e.g. for use in tabbed dialogs.
End Rem
Type QTabBar Extends QWidget

	Rem
	bbdoc: Left side of the tab.
	End Rem
	Const LeftSide:Int = 0
	Rem
	bbdoc: Right side of the tab.
	end rem
	Const RightSide:Int = 1
	Rem
	bbdoc: Select the tab to the left of the one being removed.
	end rem
	Const SelectLeftTab:Int = 0
	Rem
	bbdoc: Select the tab to the right of the one being removed.
	end rem
	Const SelectRightTab:Int = 1
	Rem
	bbdoc: Select the previously selected tab.
	end rem
	Const SelectPreviousTab:Int = 2
	Rem
	bbdoc: The normal rounded look above the pages
	end rem
	Const RoundedNorth:Int = 0
	Rem
	bbdoc: The normal rounded look below the pages
	end rem
	Const RoundedSouth:Int = 1
	Rem
	bbdoc: The normal rounded look on the left side of the pages
	end rem
	Const RoundedWest:Int = 2
	Rem
	bbdoc: The normal rounded look on the right side the pages
	end rem
	Const RoundedEast:Int = 3
	Rem
	bbdoc: Triangular tabs above the pages.
	end rem
	Const TriangularNorth:Int = 4
	Rem
	bbdoc: Triangular tabs similar to those used in the Excel spreadsheet, for example
	end rem
	Const TriangularSouth:Int = 5
	Rem
	bbdoc: Triangular tabs on the left of the pages.
	end rem
	Const TriangularWest:Int = 6
	Rem
	bbdoc: Triangular tabs on the right of the pages.
	end rem
	Const TriangularEast:Int = 7

	
	Field data:QItemList = New QItemList

	Function CreateTabBar:QTabBar(parent:QWidget = Null)
		Return New QTabBar.Create(parent)
	End Function
	
	Method Create:QTabBar(parent:QWidget = Null)
		If parent Then
			qObjectPtr = bmx_qt_qtabbar_create(Self, parent.qObjectPtr)
		Else
			qObjectPtr = bmx_qt_qtabbar_create(Self, Null)
		End If
		OnInit()
		Return Self
	End Method

	Function __create:QTabBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QTabBar = New QTabBar
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function _find:QTabBar(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local widget:QTabBar = QTabBar(qfind(qObjectPtr))
			If Not widget Then
				Return QTabBar.__create(qObjectPtr)
			End If
			Return widget
		End If
	End Function

	Method addTab:Int(text:String, icon:QIcon = Null)
		If icon Then
			Return bmx_qt_qtabbar_addtab(qObjectPtr, text, icon.qObjectPtr)
		Else
			Return bmx_qt_qtabbar_addtab(qObjectPtr, text, Null)
		End If
	End Method
	
	Method count:Int()
		Return bmx_qt_qtabbar_count(qObjectPtr)
	End Method
	
	Method currentIndex:Int()
		Return bmx_qt_qtabbar_currentindex(qObjectPtr)
	End Method
	
	Method documentMode:Int()
		Return bmx_qt_qtabbar_documentmode(qObjectPtr)
	End Method

	Method drawBase:Int()
		Return bmx_qt_qtabbar_drawbase(qObjectPtr)
	End Method
	
	Method elideMode:Int()
		Return bmx_qt_qtabbar_elidemode(qObjectPtr)
	End Method
	
	Method expanding:Int()
		Return bmx_qt_qtabbar_expanding(qObjectPtr)
	End Method
	
	Method iconSize(w:Int Var, h:Int Var)
		bmx_qt_qtabbar_iconsize(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method insertTab:Int(index:Int, text:String, icon:QIcon = Null)
		If icon Then
			Return bmx_qt_qtabbar_inserttab(qObjectPtr, index, text, icon.qObjectPtr)
		Else
			Return bmx_qt_qtabbar_inserttab(qObjectPtr, index, text, Null)
		End If
	End Method
	
	Method isMovable:Int()
		Return bmx_qt_qtabbar_ismovable(qObjectPtr)
	End Method
	
	Method isTabEnabled:Int(index:Int)
		Return bmx_qt_qtabbar_istabenabled(qObjectPtr, index)
	End Method
	
	Method moveTab(_from:Int, _to:Int)
		bmx_qt_qtabbar_movetab(qObjectPtr, _from, _to)
	End Method
	
	Method removeTab(index:Int)
		Local id:Long
		bmx_qt_qtabbar_tabdata(qObjectPtr, index, Varptr id)
		If id Then
			data.removeItem(id)
		End If
		bmx_qt_qtabbar_removetab(qObjectPtr, index)
	End Method
	
	Method selectionBehaviorOnRemove:Int()
		Return bmx_qt_qtabbar_selectionbehavioronremove(qObjectPtr)
	End Method
	
	Method setDocumentMode(set:Int)
		bmx_qt_qtabbar_setdocumentmode(qObjectPtr, set)
	End Method
	
	Method setDrawBase(drawTheBase:Int)
		bmx_qt_qtabbar_setdrawbase(qObjectPtr, drawTheBase)
	End Method
	
	Method setElideMode(_mode:Int)
		bmx_qt_qtabbar_setelidemode(qObjectPtr, _mode)
	End Method
	
	Method setExpanding(enabled:Int)
		bmx_qt_qtabbar_setexpanding(qObjectPtr, enabled)
	End Method
	
	Method setIconSize(w:Int, h:Int)
		bmx_qt_qtabbar_seticonsize(qObjectPtr, w, h)
	End Method
	
	Method setMovable(movable:Int)
		bmx_qt_qtabbar_setmovable(qObjectPtr, movable)
	End Method
	
	Method setSelectionBehaviorOnRemove(behavior:Int)
		bmx_qt_qtabbar_setselectionbehaviouronremove(qObjectPtr, behavior)
	End Method
	
	Method setShape(shape:Int)
		bmx_qt_qtabbar_setshape(qObjectPtr, shape)
	End Method
	
	Method setTabButton(index:Int, position:Int, widget:QWidget)
		bmx_qt_qtabbar_settabbutton(qObjectPtr, index, position, widget.qObjectPtr)
	End Method
	
	Method setTabData(index:Int, value:Object)
		Local id:Long
		bmx_qt_qtabbar_tabdata(qObjectPtr, index, Varptr id)
		data.setItem(id, value)
		bmx_qt_qtabbar_settabdata(qObjectPtr, index, id)
	End Method
	
	Method setTabEnabled(index:Int, enabled:Int)
		bmx_qt_qtabbar_settabenabled(qObjectPtr, index, enabled)
	End Method
	
	Method setTabIcon(index:Int, icon:QIcon)
		bmx_qt_qtabbar_settabicon(qObjectPtr, index, icon.qObjectPtr)
	End Method
	
	Method setTabText(index:Int, text:String)
		bmx_qt_qtabbar_settabtext(qObjectPtr, index, text)
	End Method
	
	Method setTabTextColor(index:Int, color:QColor)
		bmx_qt_qtabbar_settabtextcolor(qObjectPtr, index, color.qObjectPtr)
	End Method
	
	Method setTabToolTip(index:Int, tip:String)
		bmx_qt_qtabbar_settabtooltip(qObjectPtr, index, tip)
	End Method
	
	Method setTabWhatsThis(index:Int, text:String)
		bmx_qt_qtabbar_settabwhatsthis(qObjectPtr, index, text)
	End Method
	
	Method setTabsClosable(closable:Int)
		bmx_qt_qtabbar_settabsclosable(qObjectPtr, closable)
	End Method
	
	Method setUsesScrollButtons(useButtons:Int)
		bmx_qt_qtabbar_setusesscrollbuttons(qObjectPtr, useButtons)
	End Method
	
	Method shape:Int()
		Return bmx_qt_qtabbar_shape(qObjectPtr)
	End Method
	
	Method tabAt:Int(x:Int, y:Int)
		Return bmx_qt_qtabbar_tabat(qObjectPtr, x, y)
	End Method
	
	Method tabButton:QWidget(index:Int, position:Int)
		Return QWidget._find(bmx_qt_qtabbar_tabbutton(qObjectPtr, index, position))
	End Method
	
	Method tabData:Object(index:Int)
		Local id:Long
		bmx_qt_qtabbar_tabdata(qObjectPtr, index, Varptr id)
		If id Then
			Return data.itemData(id)
		End If
	End Method
	
	Method tabIcon:QIcon(index:Int)
		Return QIcon._create(bmx_qt_qtabbar_tabicon(qObjectPtr, index))
	End Method
	
	Method tabRect:QRect(index:Int)
		Return QRect._create(bmx_qt_qtabbar_tabrect(qObjectPtr, index))
	End Method
	
	Method tabText:String(index:Int)
		Return bmx_qt_qtabbar_tabtext(qObjectPtr, index)
	End Method
	
	Method tabTextColor:QColor(index:Int)
		Return QColor._create(bmx_qt_qtabbar_tabtextcolor(qObjectPtr, index))
	End Method
	
	Method tabToolTip:String(index:Int)
		Return bmx_qt_qtabbar_tabtooltip(qObjectPtr, index)
	End Method
	
	Method tabWhatsThis:String(index:Int)
		Return bmx_qt_qtabbar_tabwhatsthis(qObjectPtr, index)
	End Method
	
	Method tabsClosable:Int()
		Return bmx_qt_qtabbar_tabsclosable(qObjectPtr)
	End Method
	
	Method usesScrollButtons:Int()
		Return bmx_qt_qtabbar_usesscrollbuttons(qObjectPtr)
	End Method

	Method setCurrentIndex(index:Int)
		bmx_qt_qtabbar_setcurrentindex(qObjectPtr, index)
	End Method

	' SIGNAL : currentChanged
	Function _OnCurrentChanged(obj:QTabBar, index:Int)
		obj._InvokeSignals("valueChanged", [String(index)])
	End Function

	' SIGNAL : tabCloseRequested
	Function _OnTabCloseRequested(obj:QTabBar, index:Int)
		obj._InvokeSignals("tabCloseRequested", [String(index)])
	End Function

	' SIGNAL : tabMoved
	Function _OnTabMoved(obj:QTabBar, _from:Int, _to:Int)
		obj._InvokeSignals("tabMoved", [String(_from), String(_to)])
	End Function

End Type

