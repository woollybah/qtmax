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

Module Qt.QPalette

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"


Type QPalette

	Rem
	bbdoc: Used for widgets (not windows) that are disabled for some reason.
	End Rem
	Const Group_Disabled:Int = 1
	
	Rem
	bbdoc: Used for the window that has keyboard focus.
	End Rem
	Const Group_Active:Int = 0
	
	Rem
	bbdoc: Used for other windows
	End Rem
	Const Group_Inactive:Int = 2
	
	Rem
	bbdoc: synonym for Active
	End Rem
	Const Group_Normal:Int = Group_Active


	Rem
	bbdoc: A general background color.
	End Rem
	Const Role_Window:Int = 10
	
	Rem
	bbdoc: A general foreground color.
	End Rem
	Const Role_WindowText:Int = 0
	
	Rem
	bbdoc: Used mostly as the background color for text entry widgets, but can also be used for other painting - such as the background of combobox drop down lists and toolbar handles.
	about: It is usually white or another light color.
	End Rem
	Const Role_Base:Int = 9
	
	Rem
	bbdoc: Used as the alternate background color in views with alternating row colors (see QAbstractItemView::setAlternatingRowColors()).
	End Rem
	Const Role_AlternateBase:Int = 16
	
	Rem
	bbdoc: Used as the background color for QToolTip and QWhatsThis.
	about: Tool tips use the Inactive color group of QPalette, because tool tips are not active windows.
	End Rem
	Const Role_ToolTipBase:Int = 18
	
	Rem
	bbdoc: Used as the foreground color for QToolTip and QWhatsThis.
	about: Tool tips use the Inactive color group of QPalette, because tool tips are not active windows.
	End Rem
	Const Role_ToolTipText:Int = 19
	
	Rem
	bbdoc: The foreground color used with Base.
	about: This is usually the same as the Role_WindowText, in which case it must provide good contrast with Window and Base.
	End Rem
	Const Role_Text:Int = 6
	
	Rem
	bbdoc: The general button background color.
	about: This background can be different from Role_Window as some styles require a different background color for buttons.
	End Rem
	Const Role_Button:Int = 1
	
	Rem
	bbdoc: A foreground color used with the Button color.
	End Rem
	Const Role_ButtonText:Int = 8
	
	Rem
	bbdoc: A text color that is very different from Role_WindowText, and contrasts well with e.g. Dark.
	about: Typically used for text that needs to be drawn where Role_Text or Role_WindowText would give poor contrast, such as on pressed push buttons.
	Note that text colors can be used for things other than just words; text colors are usually used for text, but it's quite common to use the 
	text color roles for lines, icons, etc.
	End Rem
	Const Role_BrightText:Int = 7

	Rem
	bbdoc: Lighter than Button color.
	End Rem
	Const Role_Light:Int = 2
	
	Rem
	bbdoc: Between Button and Light.
	End Rem
	Const Role_Midlight:Int = 3
	
	Rem
	bbdoc: Darker than Button.
	End Rem
	Const Role_Dark:Int = 4
	
	Rem
	bbdoc: Between Button and Dark.
	End Rem
	Const Role_Mid:Int = 5
	
	Rem
	bbdoc: A very dark color.
	about: By default, the shadow color is Qt::black.
	End Rem
	Const Role_Shadow:Int = 11
	
	Rem
	bbdoc: A color to indicate a selected item or the current item.
	about: By default, the highlight color is Qt::darkBlue.
	End Rem
	Const Role_Highlight:Int = 12
	
	Rem
	bbdoc: A text color that contrasts with Highlight.
	about: By default, the highlighted text color is Qt::white.
	End Rem
	Const Role_HighlightedText:Int = 13
	
	Rem
	bbdoc: A text color used for unvisited hyperlinks.
	about: By default, the link color is Qt::blue.
	End Rem
	Const Role_Link:Int = 14
	
	Rem
	bbdoc: A text color used for already visited hyperlinks.
	about: By default, the linkvisited color is Qt::magenta.
	End Rem
	Const Role_LinkVisited:Int = 15


	Field qObjectPtr:Byte Ptr
	
	Function _create:QPalette(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QPalette = New QPalette
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Method alternateBase:QBrush()
		Return QBrush._create(bmx_qt_qpalette_alternatebase(qObjectPtr))
	End Method
	
	Method base:QBrush()
		Return QBrush._create(bmx_qt_qpalette_base(qObjectPtr))
	End Method
	
	Method brightText:QBrush()
		Return QBrush._create(bmx_qt_qpalette_brighttext(qObjectPtr))
	End Method
	
	Method brushForGroup:QBrush(group:Int, role:Int)
		Return QBrush._create(bmx_qt_qpalette_brushforgroup(qObjectPtr, group, role))
	End Method
	
	Method brush:QBrush(role:Int)
		Return QBrush._create(bmx_qt_qpalette_brush(qObjectPtr, role))
	End Method
	
	Method button:QBrush()
		Return QBrush._create(bmx_qt_qpalette_button(qObjectPtr))
	End Method
	
	Method buttonText:QBrush()
		Return QBrush._create(bmx_qt_qpalette_buttontext(qObjectPtr))
	End Method
	
	Method cacheKey:Long()
		Local key:Long
		bmx_qt_qpalette_cachekey(qObjectPtr, Varptr key)
		Return key
	End Method
	
	Method colorForGroup:QColor(group:Int, role:Int)
		Return QColor._create(bmx_qt_qpalette_colorforgroup(qObjectPtr, group, role))
	End Method
	
	Method color:QColor(role:Int)
		Return QColor._create(bmx_qt_qpalette_color(qObjectPtr, role))
	End Method
	
	Method currentColorGroup:Int()
		Return bmx_qt_qpalette_currentcolorgroup(qObjectPtr)
	End Method
	
	Method dark:QBrush()
		Return QBrush._create(bmx_qt_qpalette_dark(qObjectPtr))
	End Method
	
	Method highlight:QBrush()
		Return QBrush._create(bmx_qt_qpalette_highlight(qObjectPtr))
	End Method
	
	Method highlightedText:QBrush()
		Return QBrush._create(bmx_qt_qpalette_highlightedtext(qObjectPtr))
	End Method
	
	Method isBrushSet:Int(cg:Int, cr:Int)
		Return bmx_qt_qpalette_isbrushset(qObjectPtr, cg, cr)
	End Method
	
	Method isCopyOf:Int(p:QPalette)
		Return bmx_qt_qpalette_iscopyof(qObjectPtr, p.qObjectPtr)
	End Method
	
	Method isEqual:Int(cg1:Int, cg2:Int)
		Return bmx_qt_qpalette_isequal(qObjectPtr, cg1, cg2)
	End Method
	
	Method light:QBrush()
		Return QBrush._create(bmx_qt_qpalette_light(qObjectPtr))
	End Method
	
	Method link:QBrush()
		Return QBrush._create(bmx_qt_qpalette_link(qObjectPtr))
	End Method
	
	Method linkVisited:QBrush()
		Return QBrush._create(bmx_qt_qpalette_linkvisited(qObjectPtr))
	End Method
	
	Method Mid:QBrush()
		Return QBrush._create(bmx_qt_qpalette_mid(qObjectPtr))
	End Method
	
	Method midlight:QBrush()
		Return QBrush._create(bmx_qt_qpalette_midlight(qObjectPtr))
	End Method
	
	Method resolve:QPalette(other:QPalette)
		Return QPalette._create(bmx_qt_qpalette_resolve(qObjectPtr, other.qObjectPtr))
	End Method
	
	Method setBrush(role:Int, brush:QBrush)
		bmx_qt_qpalette_setbrush(qObjectPtr, role, brush.qObjectPtr)
	End Method
	
	Method setBrushForGroup(group:Int, role:Int, brush:QBrush)
		bmx_qt_qpalette_setbrushforgroup(qObjectPtr, group, role, brush.qObjectPtr)
	End Method
	
	Method setColorForGroup(group:Int, role:Int, color:QColor)
		bmx_qt_qpalette_setcolorforgroup(qObjectPtr, group, role, color.qObjectPtr)
	End Method
	
	Method SetColor(role:Int, color:QColor )
		bmx_qt_qpalette_setcolor(qObjectPtr, role, color.qObjectPtr)
	End Method
	
	Method setColorGroup(cg:Int, windowText:QBrush, button:QBrush, light:QBrush, dark:QBrush, Mid:QBrush, text:QBrush, brightText:QBrush, base:QBrush, window:QBrush)
		bmx_qt_qpalette_setcolorgroup(qObjectPtr, cg, windowText.qObjectPtr, button.qObjectPtr, light.qObjectPtr, dark.qObjectPtr, Mid.qObjectPtr, text.qObjectPtr, brightText.qObjectPtr, base.qObjectPtr, window.qObjectPtr)
	End Method
	
	Method setCurrentColorGroup(cg:Int)
		bmx_qt_qpalette_setcurrentcolorgroup(qObjectPtr, cg)
	End Method
	
	Method shadow:QBrush()
		Return QBrush._create(bmx_qt_qpalette_shadow(qObjectPtr))
	End Method
	
	Method text:QBrush()
		Return QBrush._create(bmx_qt_qpalette_text(qObjectPtr))
	End Method
	
	Method toolTipBase:QBrush()
		Return QBrush._create(bmx_qt_qpalette_tooltipbase(qObjectPtr))
	End Method
	
	Method toolTipText:QBrush()
		Return QBrush._create(bmx_qt_qpalette_tooltiptext(qObjectPtr))
	End Method
	
	Method window:QBrush()
		Return QBrush._create(bmx_qt_qpalette_window(qObjectPtr))
	End Method
	
	Method windowText:QBrush()
		Return QBrush._create(bmx_qt_qpalette_windowtext(qObjectPtr))
	End Method
	
End Type

