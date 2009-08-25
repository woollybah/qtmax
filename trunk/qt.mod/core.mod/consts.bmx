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

Rem
bbdoc: Aligns with the Left edge.
End Rem
Const Qt_AlignLeft:Int = $0001
Rem
bbdoc: Aligns with the Right edge.
End Rem
Const Qt_AlignRight:Int = $0002
Rem
bbdoc: Centers horizontally in the available space.
End Rem
Const Qt_AlignHCenter:Int = $0004
Rem
bbdoc: Justifies the text in the available space.
End Rem
Const Qt_AlignJustify:Int = $0008

Rem
bbdoc: Aligns with the top.
end rem
Const Qt_AlignTop:Int = $0020
Rem
bbdoc: Aligns with the bottom.
end rem
Const Qt_AlignBottom:Int = $0040
Rem
bbdoc: Centers vertically in the available space.
end rem
Const Qt_AlignVCenter:Int = $0080
Rem
bbdoc: Centers in both dimensions.
End Rem
Const Qt_AlignCenter:Int = Qt_AlignVCenter | Qt_AlignHCenter
Rem
bbdoc: If the widget's layout direction is Qt_RightToLeft (instead of Qt_LeftToRight, the default), Qt_AlignLeft refers to the right edge and Qt_AlignRight to the left edge.
about: This is normally the desired behavior. If you want Qt_AlignLeft to always mean "left" and Qt_AlignRight to always mean "right", combine
the flag with Qt_AlignAbsolute.
End Rem
Const Qt_AlignAbsolute:Int = $0010
Rem
bbdoc: Synonym for Qt_AlignLeft.
End Rem
Const Qt_AlignLeading:Int = Qt_AlignLeft
Rem
bbdoc: Synonym for Qt_AlignRight.
End Rem
Const Qt_AlignTrailing:Int = Qt_AlignRight

Rem
bbdoc: This is the default type for QWidget.
about: Widgets of this type are child widgets if they have a parent, and independent windows if they have no parent.
See also #Qt_Window and #Qt_SubWindow.
End Rem
Const Qt_Widget:Int = $00000000
Rem
bbdoc: Indicates that the widget is a window, usually with a window system frame and a title bar, irrespective of whether the widget has a parent or not.
about: Note that it is not possible to unset this flag if the widget does not have a parent.
End Rem
Const Qt_Window:Int = $00000001
Rem
bbdoc: Indicates that the widget is a window that should be decorated as a dialog (i.e., typically no maximize or minimize buttons in the title bar).
about: This is the default type for QDialog. If you want to use it as a modal dialog, it should be launched from another window,
or have a parent and used with the QWidget_windowModality property. If you make it modal, the dialog will prevent other top-level
windows in the application from getting any input. We refer to a top-level window that has a parent as a secondary window.
End Rem
Const Qt_Dialog:Int = $00000002 | Qt_Window
Rem
bbdoc: Indicates that the widget is a Macintosh sheet.
end rem
Const Qt_Sheet:Int = $00000004 | Qt_Window
Rem
bbdoc: Indicates that the widget is a Macintosh drawer.
end rem
Const Qt_Drawer:Int = $00000006 | Qt_Window
Rem
bbdoc: Indicates that the widget is a pop-up top-level window, i.e. that it is modal, but has a window system frame appropriate for pop-up menus.
end rem
Const Qt_Popup:Int = $00000008 | Qt_Window
Rem
bbdoc: Indicates that the widget is a tool window.
about: A tool window is often a small window with a smaller than usual title bar and decoration, typically used for collections of
tool buttons. It there is a parent, the tool window will always be kept on top of it. If there isn't a parent, you may consider
using #Qt_WindowStaysOnTopHint as well. If the window system supports it, a tool window can be decorated with a somewhat lighter frame.
It can also be combined with #Qt_FramelessWindowHint. 
<p>
On Mac OS X, tool windows correspond to the Floating class of windows. This means that the window lives on a level above normal windows;
it impossible to put a normal window on top of it. By default, tool windows will disappear when the application is inactive. This can
be controlled by the #Qt_WA_MacAlwaysShowToolWindow attribute.
</p>
End Rem
Const Qt_Tool:Int = $0000000a | Qt_Window
Rem
bbdoc: Indicates that the widget is a tooltip.
about: This is used internally to implement tooltips.
End Rem
Const Qt_ToolTip:Int = $0000000c | Qt_Window
Rem
bbdoc: Indicates that the window is a splash screen.
about: This is the default type for QSplashScreen.
End Rem
Const Qt_SplashScreen:Int = $0000000e | Qt_Window
Rem
bbdoc: Indicates that this widget is the desktop.
about: This is the type for QDesktopWidget.
End Rem
Const Qt_Desktop:Int = $00000010 | Qt_Window
Rem
bbdoc: Indicates that this widget is a sub-window, such as a QMdiSubWindow widget.
end rem
Const Qt_SubWindow:Int = $00000012
Rem
bbdoc: Gives the window a thin dialog border on Windows.
about: This style is traditionally used for fixed-size dialogs.
end rem
Const Qt_MSWindowsFixedSizeDialogHint:Int = $00000100
Rem
bbdoc: Gives the window its own display context on Windows.
end rem
Const Qt_MSWindowsOwnDC:Int = $00000200
Rem
bbdoc: Bypass the window manager completely.
about: This results in a borderless window that is not managed at all (i.e., no keyboard input unless you call QWidget::activateWindow() manually).
end rem
Const Qt_X11BypassWindowManagerHint:Int = $00000400
Rem
bbdoc: Produces a borderless window.
about: The user cannot move or resize a borderless window via the window system. On X11, the result of the flag is dependent
on the window manager and its ability to understand Motif and/or NETWM hints. Most existing modern window managers can handle this.
end rem
Const Qt_FramelessWindowHint:Int = $00000800
Rem
bbdoc: Turns off the default window title hints.
end rem
Const Qt_CustomizeWindowHint:Int = $02000000
Rem
bbdoc: Gives the window a title bar.
end rem
Const Qt_WindowTitleHint:Int = $00001000
Rem
bbdoc: Adds a window system menu, and possibly a close button (for example on Mac).
about: If you need to hide or show a close button, it is more portable to use WindowCloseButtonHint.
end rem
Const Qt_WindowSystemMenuHint:Int = $00002000
Rem
bbdoc: Adds a minimize button.
about: On some platforms this implies Qt_WindowSystemMenuHint for it to work.
end rem
Const Qt_WindowMinimizeButtonHint:Int = $00004000
Rem
bbdoc: Adds a maximize button.
about: On some platforms this implies Qt_WindowSystemMenuHint for it to work.
end rem
Const Qt_WindowMaximizeButtonHint:Int = $00008000
Rem
bbdoc: Adds a minimize and a maximize button.
about: On some platforms this implies Qt_WindowSystemMenuHint for it to work.
end rem
Const Qt_WindowMinMaxButtonsHint:Int = Qt_WindowMinimizeButtonHint | Qt_WindowMaximizeButtonHint
Rem
bbdoc: Adds a close button.
about: On some platforms this implies Qt_WindowSystemMenuHint for it to work.
end rem
Const Qt_WindowCloseButtonHint:Int = $08000000
Rem
bbdoc: Adds a context help button to dialogs.
about: On some platforms this implies Qt_WindowSystemMenuHint for it to work.
end rem
Const Qt_WindowContextHelpButtonHint:Int = $00010000
Rem
bbdoc: On Mac OS X adds a tool bar button (i.e., the oblong button that is on the top right of windows that have toolbars.
end rem
Const Qt_MacWindowToolBarButtonHint:Int = $10000000
Rem
bbdoc: Prevents the window and its children from automatically embedding themselves into a QGraphicsProxyWidget if the parent widget is already embedded.
about: You can set this flag if you want your widget to always be a toplevel widget on the desktop, regardless of whether the parent widget is embedded in a scene or not.
end rem
Const Qt_BypassGraphicsProxyWidget:Int = $20000000
Rem
bbdoc:  
end rem
Const Qt_WindowShadeButtonHint:Int = $00020000
Rem
bbdoc: Informs the window system that the window should stay on top of all other windows.
about: Note that on some window managers on X11 you also have to pass Qt::X11BypassWindowManagerHint for this flag to work correctly.
end rem
Const Qt_WindowStaysOnTopHint:Int = $00040000
Rem
bbdoc: Informs the window system that the window should stay on bottom of all other windows.
about: Note that on X11 this hint will work only in window managers that support _NET_WM_STATE_BELOW atom. If a window always on the bottom has a
parent, the parent will also be left on the bottom. This window hint is currently not implemented for Mac OS X.
end rem
Const Qt_WindowStaysOnBottomHint:Int = $04000000
Rem
bbdoc: A mask for extracting the window type part of the window flags.
end rem
Const Qt_WindowType_Mask:Int = $000000ff

Rem
bbdoc: A mouse action occurred.
end rem
Const Qt_MouseFocusReason:Int = 0
Rem
bbdoc: The Tab key was pressed.
end rem
Const Qt_TabFocusReason:Int = 1
Rem
bbdoc: A Backtab occurred.
about: The input for this may include the Shift or Control keys; e.g. Shift+Tab.
End Rem
Const Qt_BacktabFocusReason:Int = 2
Rem
bbdoc: The window system made this window either active or inactive.
end rem
Const Qt_ActiveWindowFocusReason:Int = 3
Rem
bbdoc: The application opened/closed a pop-up that grabbed/released the keyboard focus.
end rem
Const Qt_PopupFocusReason:Int = 4
Rem
bbdoc: The user typed a label's buddy shortcut
End Rem
Const Qt_ShortcutFocusReason:Int = 5
Rem
bbdoc: The menu bar took focus.
end rem
Const Qt_MenuBarFocusReason:Int = 6
Rem
bbdoc: Another reason, usually application-specific.
end rem
Const Qt_OtherFocusReason:Int = 7

Rem
bbdoc: No line at all.
about: For example, QPainter::drawRect() fills but does not draw any boundary line.
End Rem
Const Qt_NoPen:Int = 0
Rem
bbdoc: A plain line.
end rem
Const Qt_SolidLine:Int = 1
Rem
bbdoc: Dashes separated by a few pixels.
end rem
Const Qt_DashLine:Int = 2
Rem
bbdoc: Dots separated by a few pixels.
end rem
Const Qt_DotLine:Int = 3
Rem
bbdoc: Alternate dots and dashes.
end rem
Const Qt_DashDotLine:Int = 4
Rem
bbdoc: One dash, two dots, one dash, two dots.
end rem
Const Qt_DashDotDotLine:Int = 5
Rem
bbdoc: A custom pattern defined using QPainterPathStroker::setDashPattern().
end rem
Const Qt_CustomDashLine:Int = 6


Const Qt_Horizontal:Int = $1
Const Qt_Vertical:Int = $2

Const Qt_LeftToolBarArea:Int = $1
Const Qt_RightToolBarArea:Int = $2
Const Qt_TopToolBarArea:Int = $4
Const Qt_BottomToolBarArea:Int = $8
Const Qt_AllToolBarAreas:Int = $F
Const Qt_NoToolBarArea:Int = 0

Rem
bbdoc: Specifies the size using absolute measurements.
End Rem
Const Qt_AbsoluteSize:Int = 0
Rem
bbdoc: Specifies the size relative to the bounding rectangle, typically using percentage measurements.
End Rem
Const Qt_RelativeSize:Int = 1

Rem
bbdoc: The items are sorted ascending e.g. starts with 'AAA' ends with 'ZZZ' in Latin-1 locales
End Rem
Const Qt_AscendingOrder:Int = 0
Rem
bbdoc: The items are sorted descending e.g. starts with 'ZZZ' ends with 'AAA' in Latin-1 locales
End Rem
Const Qt_DescendingOrder:Int = 1

Rem
bbdoc: The ellipsis should appear at the beginning of the text.
end rem
Const Qt_ElideLeft:Int = 0
Rem
bbdoc: The ellipsis should appear at the end of the text.
end rem
Const Qt_ElideRight:Int = 1
Rem
bbdoc: The ellipsis should appear in the middle of the text.
end rem
Const Qt_ElideMiddle:Int = 2
Rem
bbdoc: Ellipsis should NOT appear in the text.
end rem
Const Qt_ElideNone:Int = 3

Rem
bbdoc: Specifies that the region is filled using the odd even fill rule.
about: With this rule, we determine whether a point is inside the shape by using the following method. Draw
a horizontal line from the point to a location outside the shape, and count the number of intersections. If the
number of intersections is an odd number, the point is inside the shape. This mode is the default.
End Rem
Const Qt_OddEvenFill:Int = 0
Rem
bbdoc: Specifies that the region is filled using the non zero winding rule.
about: With this rule, we determine whether a point is inside the shape by using the following method. Draw a
horizontal line from the point to a location outside the shape. Determine whether the direction of the line at
each intersection point is up or down. The winding number is determined by summing the direction of each
intersection. If the number is non zero, the point is inside the shape. This fill mode can also in most cases
be considered as the intersection of closed shapes.
End Rem
Const Qt_WindingFill:Int = 1

Rem
bbdoc: the widget accepts focus by tabbing.
end rem
Const Qt_TabFocus:Int = $1
Rem
bbdoc: the widget accepts focus by clicking.
end rem
Const Qt_ClickFocus:Int = $2
Rem
bbdoc: the widget accepts focus by both tabbing and clicking.
about: On Mac OS X this will also be indicate that the widget accepts tab focus when in 'Text/List focus mode'.
end rem
Const Qt_StrongFocus:Int = Qt_TabFocus | Qt_ClickFocus | $8
Rem
bbdoc: like Qt_StrongFocus plus the widget accepts focus by using the mouse wheel.
end rem
Const Qt_WheelFocus:Int = Qt_StrongFocus | $4
Rem
bbdoc: the widget does not accept focus.
end rem
Const Qt_NoFocus:Int = 0

Rem
bbdoc: (default) - If the image has depth 1 and contains only black and white pixels, the pixmap becomes monochrome.
end rem
Const Qt_AutoColor:Int = $00000000
Rem
bbdoc: The pixmap is dithered/converted to the native display depth.
end rem
Const Qt_ColorOnly:Int = $00000003
Rem
bbdoc: The pixmap becomes monochrome. If necessary, it is dithered using the chosen dithering algorithm.
end rem
Const Qt_MonoOnly:Int = $00000002
Rem
bbdoc: (default) - A high-quality dither.
end rem
Const Qt_DiffuseDither:Int = $00000000
Rem
bbdoc: A faster, more ordered dither.
end rem
Const Qt_OrderedDither:Int = $00000010
Rem
bbdoc: No dithering; closest color is used.
end rem
Const Qt_ThresholdDither:Int = $00000020
Rem
bbdoc: (default) - No dithering.
end rem
Const Qt_ThresholdAlphaDither:Int = $00000000
Rem
bbdoc: A faster, more ordered dither.
end rem
Const Qt_OrderedAlphaDither:Int = $00000004
Rem
bbdoc: A high-quality dither.
end rem
Const Qt_DiffuseAlphaDither:Int = $00000008
Rem
bbdoc: (default when converting to a pixmap) - Always dither 32-bit images when the image is converted to 8 bits.
end rem
Const Qt_PreferDither:Int = $00000040
Rem
bbdoc: (default when converting for the purpose of saving to file) - Dither 32-bit images only if the image has more than 256 colors and it is being converted to 8 bits.
end rem
Const Qt_AvoidDither:Int = $00000080

Rem
bbdoc: <img src="images/cursor-arrow.png" /> The standard arrow cursor.
End Rem
Const Qt_ArrowCursor:Int = 0
Rem
bbdoc: <img src="images/cursor-uparrow.png" /> An arrow pointing upwards toward the top of the screen.
End Rem
Const Qt_UpArrowCursor:Int = 1
Rem
bbdoc: <img src="images/cursor-cross.png" /> A crosshair cursor, typically used to help the user accurately select a point on the screen.
End Rem
Const Qt_CrossCursor:Int = 2
Rem
bbdoc: <img src="images/cursor-wait.png" /> An hourglass or watch cursor, usually shown during operations that prevent the user from interacting with the application.
End Rem
Const Qt_WaitCursor:Int = 3
Rem
bbdoc: <img src="images/cursor-ibeam.png" /> A caret or ibeam cursor, indicating that a widget can accept and display text input.
End Rem
Const Qt_IBeamCursor:Int = 4
Rem
bbdoc: <img src="images/cursor-sizev.png" /> A cursor used for elements that are used to vertically resize top-level windows.
End Rem
Const Qt_SizeVerCursor:Int = 5
Rem
bbdoc: <img src="images/cursor-sizeh.png" /> A cursor used for elements that are used to horizontally resize top-level windows.
End Rem
Const Qt_SizeHorCursor:Int = 6
Rem
bbdoc: <img src="images/cursor-sizeb.png" /> A cursor used for elements that are used to diagonally resize top-level windows at their top-right and bottom-left corners.
End Rem
Const Qt_SizeBDiagCursor:Int = 7
Rem
bbdoc: <img src="images/cursor-sizef.png" /> A cursor used for elements that are used to diagonally resize top-level windows at their top-left and bottom-right corners.
End Rem
Const Qt_SizeFDiagCursor:Int = 8
Rem
bbdoc: <img src="images/cursor-sizeall.png" /> A cursor used for elements that are used to resize top-level windows in any direction.
End Rem
Const Qt_SizeAllCursor:Int = 9
Rem
bbdoc: A blank/invisible cursor, typically used when the cursor shape needs to be hidden.
End Rem
Const Qt_BlankCursor:Int = 10
Rem
bbdoc: <img src="images/cursor-vsplit.png" /> A cursor used for vertical splitters, indicating that a handle can be dragged horizontally to adjust the use of available space.
End Rem
Const Qt_SplitVCursor:Int = 11
Rem
bbdoc: <img src="images/cursor-hsplit.png" /> A cursor used for horizontal splitters, indicating that a handle can be dragged vertically to adjust the use of available space.
End Rem
Const Qt_SplitHCursor:Int = 12
Rem
bbdoc: <img src="images/cursor-hand.png" /> A pointing hand cursor that is typically used for clickable elements such as hyperlinks.
End Rem
Const Qt_PointingHandCursor:Int = 13
Rem
bbdoc: <img src="images/cursor-forbidden.png" /> A slashed circle cursor, typically used during drag and drop operations to indicate that dragged content cannot be dropped on particular widgets or inside certain regions.
End Rem
Const Qt_ForbiddenCursor:Int = 14
Rem
bbdoc: <img src="images/cursor-openhand.png" /> A cursor representing an open hand, typically used to indicate that the area under the cursor is the visible part of a canvas that the user can click and drag in order to scroll around.
End Rem
Const Qt_OpenHandCursor:Int = 17
Rem
bbdoc: <img src="images/cursor-closedhand.png" /> A cursor representing a closed hand, typically used to indicate that a dragging operation is in progress that involves scrolling.
End Rem
Const Qt_ClosedHandCursor:Int = 18
Rem
bbdoc: <img src="images/cursor-whatsthis.png" /> An arrow with a question mark, typically used to indicate the presence of What's This? help for a widget.
End Rem
Const Qt_WhatsThisCursor:Int = 15
Rem
bbdoc: <img src="images/cursor-wait.png" /> An hourglass or watch cursor, usually shown during operations that allow the user to interact with the application while they are performed in the background.
End Rem
Const Qt_BusyCursor:Int = 16
Rem
bbdoc: 
End Rem
Const Qt_BitmapCursor:Int = 24

Rem
bbdoc: Performs QVariant-based matching.
end rem
Const Qt_MatchExactly:Int = 0
Rem
bbdoc: Performs string-based matching.
about: String-based comparisons are case-insensitive unless the MatchCaseSensitive flag is also specified.
end rem
Const Qt_MatchFixedString:Int = 8
Rem
bbdoc: The search term is contained in the item.
end rem
Const Qt_MatchContains:Int = 1
Rem
bbdoc: The search term matches the start of the item.
end rem
Const Qt_MatchStartsWith:Int = 2
Rem
bbdoc: The search term matches the end of the item.
end rem
Const Qt_MatchEndsWith:Int = 3
Rem
bbdoc: The search is case sensitive.
end rem
Const Qt_MatchCaseSensitive:Int = 16
Rem
bbdoc: Performs string-based matching using a regular expression as the search term.
end rem
Const Qt_MatchRegExp:Int = 4
Rem
bbdoc: Performs string-based matching using a string with wildcards as the search term.
end rem
Const Qt_MatchWildcard:Int = 5
Rem
bbdoc: Perform a search that wraps around, so that when the search reaches the last item in the model, it begins again at the first item and continues until all items have been examined.
end rem
Const Qt_MatchWrap:Int = 32
Rem
bbdoc: Searches the entire hierarchy.
end rem
Const Qt_MatchRecursive:Int = 64

Rem
bbdoc: The key data to be rendered in the form of text.
end rem
Const Qt_DisplayRole:Int = 0
Rem
bbdoc: The data to be rendered as a decoration in the form of an icon.
end rem
Const Qt_DecorationRole:Int = 1
Rem
bbdoc: The data in a form suitable for editing in an editor.
end rem
Const Qt_EditRole:Int = 2
Rem
bbdoc: The data displayed in the item's tooltip.
end rem
Const Qt_ToolTipRole:Int = 3
Rem
bbdoc: The data displayed in the status bar.
end rem
Const Qt_StatusTipRole:Int = 4
Rem
bbdoc: The data displayed for the item in "What's This?" mode.
end rem
Const Qt_WhatsThisRole:Int = 5
Rem
bbdoc: The size hint for the item that will be supplied to views.
end rem
Const Qt_SizeHintRole:Int = 13
Rem
bbdoc: The font used for items rendered with the default delegate.
end rem
Const Qt_FontRole:Int = 6
Rem
bbdoc: The alignment of the text for items rendered with the default delegate.
end rem
Const Qt_TextAlignmentRole:Int = 7
Rem
bbdoc: The background brush used for items rendered with the default delegate.
end rem
Const Qt_BackgroundRole:Int = 8
Rem
bbdoc: This role is obsolete. Use BackgroundRole instead.
end rem
Const Qt_BackgroundColorRole:Int = 8
Rem
bbdoc: The foreground brush (text color, typically) used for items rendered with the default delegate.
end rem
Const Qt_ForegroundRole:Int = 9
Rem
bbdoc: This role is obsolete. Use ForegroundRole instead.
end rem
Const Qt_TextColorRole:Int = 9
Rem
bbdoc: This role is used to obtain the checked state of an item (see Qt_CheckState).
end rem
Const Qt_CheckStateRole:Int = 10
Rem
bbdoc: The text to be used by accessibility extensions and plugins, such as screen readers.
end rem
Const Qt_AccessibleTextRole:Int = 11
Rem
bbdoc: A description of the item for accessibility purposes.
end rem
Const Qt_AccessibleDescriptionRole:Int = 12
Rem
bbdoc: The first role that can be used for application-specific purposes.
end rem
Const Qt_UserRole:Int = 32

Rem
bbdoc: a square line end that does not cover the end point of the line.
end rem
Const Qt_FlatCap:Int = $00
Rem
bbdoc: a square line end that covers the end point and extends beyond it by half the line width.
end rem
Const Qt_SquareCap:Int = $10
Rem
bbdoc: a rounded line end.
end rem
Const Qt_RoundCap:Int = $20
Rem
bbdoc: The outer edges of the lines are extended to meet at an angle, and this area is filled.
end rem
Const Qt_MiterJoin:Int = $00
Rem
bbdoc: The triangular notch between the two lines is filled.
end rem
Const Qt_BevelJoin:Int = $40
Rem
bbdoc: A circular arc between the two lines is filled.
end rem
Const Qt_RoundJoin:Int = $80
Rem
bbdoc: A miter join corresponding to the definition of a miter join in the SVG 1.2 Tiny specification.
end rem
Const Qt_SvgMiterJoin:Int = $100

