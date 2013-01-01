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

Import "key_consts.bmx"

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
End Rem
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
bbdoc: It does not have any properties set.
End Rem
Const Qt_NoItemFlags:Int = 0
Rem
bbdoc: It can be selected.
End Rem
Const Qt_ItemIsSelectable:Int = 1
Rem
bbdoc: It can be edited.
End Rem
Const Qt_ItemIsEditable:Int = 2
Rem
bbdoc: It can be dragged.
End Rem
Const Qt_ItemIsDragEnabled:Int = 4
Rem
bbdoc: It can be used as a drop target.
End Rem
Const Qt_ItemIsDropEnabled:Int = 8
Rem
bbdoc: It can be checked or unchecked by the user.
End Rem
Const Qt_ItemIsUserCheckable:Int = 16
Rem
bbdoc: The user can interact with the item.
End Rem
Const Qt_ItemIsEnabled:Int = 32
Rem
bbdoc: The item is checkable with three separate states.
End Rem
Const Qt_ItemIsTristate:Int = 64

Rem
bbdoc: A square line end that does not cover the end point of the line.
End Rem
Const Qt_FlatCap:Int = $00
Rem
bbdoc: A square line end that covers the end point and extends beyond it by half the line width.
End Rem
Const Qt_SquareCap:Int = $10
Rem
bbdoc: A rounded line end.
End Rem
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

Rem
bbdoc: The size is scaled freely.
about: The aspect ratio is not preserved.
End Rem
Const Qt_IgnoreAspectRatio:Int = 0
Rem
bbdoc: The size is scaled to a rectangle as large as possible inside a given rectangle, preserving the aspect ratio.
end rem
Const Qt_KeepAspectRatio:Int = 1
Rem
bbdoc: The size is scaled to a rectangle as small as possible outside a given rectangle, preserving the aspect ratio.
end rem
Const Qt_KeepAspectRatioByExpanding:Int = 2

Rem
bbdoc: The transformation is performed quickly, with no smoothing.
end rem
Const Qt_FastTransformation:Int = 0
Rem
bbdoc: The resulting image is transformed using bilinear filtering.
end rem
Const Qt_SmoothTransformation:Int = 1

Const Qt_Monday:Int = 1
Const Qt_Tuesday:Int = 2
Const Qt_Wednesday:Int = 3
Const Qt_Thursday:Int = 4
Const Qt_Friday:Int = 5
Const Qt_Saturday:Int = 6
Const Qt_Sunday:Int = 7

Rem
bbdoc: This operation turns clipping off.
end rem
Const Qt_NoClip:Int = 0
Rem
bbdoc: Replaces the current clip path/rect/region with the one supplied in the function call.
end rem
Const Qt_ReplaceClip:Int = 1
Rem
bbdoc: Intersects the current clip path/rect/region with the one supplied in the function call.
end rem
Const Qt_IntersectClip:Int = 2
Rem
bbdoc: Unites the current clip path/rect/region with the one supplied in the function call.
end rem
Const Qt_UniteClip:Int = 3

Rem
bbdoc: Allows data from drag and drop operations to be dropped onto the widget (see QWidget::setAcceptDrops()).
end rem
Const Qt_WA_AcceptDrops:Int = 78
Rem
bbdoc: Enables tooltips for inactive windows.
end rem
Const Qt_WA_AlwaysShowToolTips:Int = 84
Rem
bbdoc: This flag is superfluous and obsolete; it no longer has any effect. Since Qt 4.1, all widgets that do not set WA_PaintOnScreen propagate their contents.
end rem
Const Qt_WA_ContentsPropagated:Int = 3
Rem
bbdoc: Indicates that the widget wants to continue operating normally in "What's This?" mode. This is set by the widget's author.
end rem
Const Qt_WA_CustomWhatsThis:Int = 47
Rem
bbdoc: Makes Qt delete this widget when the widget has accepted the close event (see QWidget::closeEvent()).
end rem
Const Qt_WA_DeleteOnClose:Int = 55
Rem
bbdoc: Indicates that the widget is disabled, i.e. it does not receive any mouse or keyboard events. There is also a getter functions QWidget::isEnabled(). This is set/cleared by the Qt kernel.
end rem
Const Qt_WA_Disabled:Int = 0
Rem
bbdoc: Indicates that the widget is explicitly disabled, i.e. it will remain disabled even when all its ancestors are set to the enabled state. This implies WA_Disabled. This is set/cleared by QWidget::setEnabled() and QWidget::setDisabled().
end rem
Const Qt_WA_ForceDisabled:Int = 32
Rem
bbdoc: Indicates that updates are explicitly disabled for the widget; i.e. it will remain disabled even when all its ancestors are set to the updates-enabled state. This implies WA_UpdatesDisabled. This is set/cleared by QWidget::setUpdatesEnabled().
end rem
Const Qt_WA_ForceUpdatesDisabled:Int = 59
Rem
bbdoc: This attribute has been deprecated. Use QWidget::windowModality instead.
end rem
Const Qt_WA_GroupLeader:Int = 72
Rem
bbdoc: Forces Qt to generate paint events when the mouse enters or leaves the widget. This feature is typically used when implementing custom styles; see the Styles example for details.
end rem
Const Qt_WA_Hover:Int = 74
Rem
bbdoc: Enables input methods for Asian languages. Must be set when creating custom text editing widgets. On Windows CE this flag can be used in addition to QApplication::autoSipEnabled to automatically display the SIP when entering a widget.
end rem
Const Qt_WA_InputMethodEnabled:Int = 14
Rem
bbdoc: Set on a toplevel window when the users changes focus with the keyboard (tab, backtab, or shortcut).
end rem
Const Qt_WA_KeyboardFocusChange:Int = 77
Rem
bbdoc: Enables key event compression if set, and disables it if not set. By default key compression is off, so widgets receive one key press event for each key press (or more, since autorepeat is usually on). If you turn it on and your program doesn't keep up with key input, Qt may try to compress key events so that more than one character can be processed in each event. For example, a word processor widget might receive 2, 3 or more characters in each QKeyEvent::text(), if the layout recalculation takes too long for the CPU. If a widget supports multiple character unicode input, it is always safe to turn the compression on. Qt performs key event compression only for printable characters. Qt_Modifier keys, cursor movement keys, function keys and miscellaneous action keys (e.g. Escape, Enter, Backspace, PrintScreen) will stop key event compression, even if there are more compressible key events available. Platforms other than Mac and X11 do not support this compression, in which case turning it on will have no effect. This is set/cleared by the widget's author.
end rem
Const Qt_WA_KeyCompression:Int = 33
Rem
bbdoc: Indicates that the widget wants QLayout to operate on the entire QWidget::rect(), not only on QWidget::contentsRect(). This is set by the widget's author.
end rem
Const Qt_WA_LayoutOnEntireRect:Int = 48
Rem
bbdoc: Ignore the layout item rect from the style when laying out this widget with QLayout. This makes a difference in QMacStyle and QPlastiqueStyle for some widgets.
end rem
Const Qt_WA_LayoutUsesWidgetRect:Int = 92
Rem
bbdoc: When a widget that has this attribute set is clicked, and its window is inactive, the click will make the window active but won't be seen by the widget. Typical use of this attribute is on widgets with "destructive" actions, such as a "Delete" button. WA_MacNoClickThrough also applies to all child widgets of the widget that has it set.
end rem
Const Qt_WA_MacNoClickThrough:Int = 12
Rem
bbdoc: Indicates that the native Carbon size grip should be opaque instead of transparent (the default). This attribute is only applicable to Mac OS X and is set by the widget's author.
end rem
Const Qt_WA_MacOpaqueSizeGrip:Int = 85
Rem
bbdoc: Indicates that this widget should get a QFocusFrame around it. Some widgets draw their own focus halo regardless of this attribute. Not that the QWidget::focusPolicy also plays the main role in whether something is given focus or not, this only controls whether or not this gets the focus frame. This attribute is only applicable to Mac OS X.
end rem
Const Qt_WA_MacShowFocusRect:Int = 88
Rem
bbdoc: Indicates the widget should have the normal size for widgets in Mac OS X. This attribute is only applicable to Mac OS X.
end rem
Const Qt_WA_MacNormalSize:Int = 89
Rem
bbdoc: Indicates the widget should have the small size for widgets in Mac OS X. This attribute is only applicable to Mac OS X.
end rem
Const Qt_WA_MacSmallSize:Int = 90
Rem
bbdoc: Indicates the widget should have the mini size for widgets in Mac OS X. This attribute is only applicable to Mac OS X.
end rem
Const Qt_WA_MacMiniSize:Int = 91
Rem
bbdoc: Indicates the widget can choose between alternative sizes for widgets to avoid clipping. This attribute is only applicable to Mac OS X.
end rem
Const Qt_WA_MacVariableSize:Int = 102
Rem
bbdoc: Indicates the widget should be drawn in the brushed metal style as supported by the windowing system. This attribute is only applicable to Mac OS X.
end rem
Const Qt_WA_MacBrushedMetal:Int = 46
Rem
bbdoc: Indicates that the widget is mapped on screen. This is set/cleared by the Qt kernel.
end rem
Const Qt_WA_Mapped:Int = 11
Rem
bbdoc: Makes the widget receive mouse events for the entire widget regardless of the currently set mask, overriding QWidget::setMask(). This is not applicable for top-level windows.
end rem
Const Qt_WA_MouseNoMask:Int = 71
Rem
bbdoc: Indicates that the widget has mouse tracking enabled. See QWidget::mouseTracking.
end rem
Const Qt_WA_MouseTracking:Int = 2
Rem
bbdoc: Indicates that the widget has an explicit position. This is set/cleared by QWidget::move() and by QWidget::setGeometry().
end rem
Const Qt_WA_Moved:Int = 43
Rem
bbdoc: Makes drawing to a widget with this attribute set use the Direct3D paint engine, if the Direct3D paint engine is available. This functionality is experimental.
end rem
Const Qt_WA_MSWindowsUseDirect3D:Int = 94
Rem
bbdoc: Indicates that the widget does not want ChildAdded or ChildRemoved events sent to its parent. This is rarely necessary but can help to avoid automatic insertion widgets like splitters and layouts. This is set by a widget's author.
end rem
Const Qt_WA_NoChildEventsForParent:Int = 58
Rem
bbdoc: Indicates that the widget does not want to receive ChildAdded or ChildRemoved events sent from its children. This is set by a widget's author.
end rem
Const Qt_WA_NoChildEventsFromChildren:Int = 39
Rem
bbdoc: Used for pop-up widgets.
about: Indicates that the most recent mouse press event should not be replayed when the
pop-up widget closes. The flag is set by the widget's author and cleared by the Qt kernel
every time the widget receives a new mouse event.
end rem
Const Qt_WA_NoMouseReplay:Int = 54
Rem
bbdoc: Prohibits mouse events from being propagated to the widget's parent.
about: This attribute is disabled by default.
end rem
Const Qt_WA_NoMousePropagation:Int = 73
Rem
bbdoc: When enabled, this attribute disables the delivery of mouse events to the widget and
its children. Mouse events are delivered to other widgets as if the widget and its children
were not present in the widget hierarchy; mouse clicks and other events effectively
"pass through" them. This attribute is disabled by default.
end rem
Const Qt_WA_TransparentForMouseEvents:Int = 51
Rem
bbdoc: Indicates that the widget has no background, i.e. when the widget receives paint events, the background is not automatically repainted.
about: Note: Unlike WA_OpaquePaintEvent, newly exposed areas are never filled with the
background (e.g., after showing a window for the first time the user can see "through"
it until the application processes the paint events). This flag is set or cleared by the
widget's author.
end rem
Const Qt_WA_NoSystemBackground:Int = 9
Rem
bbdoc: Indicates that the widget paints all its pixels when it receives a paint event.
about: Thus, it is not required for operations like updating, resizing, scrolling and focus
changes to erase the widget before generating paint events. The use of WA_OpaquePaintEvent
provides a small optimization by helping to reduce flicker on systems that do not support
double buffering and avoiding computational cycles necessary to erase the background prior
to painting. Note: Unlike WA_NoSystemBackground, WA_OpaquePaintEvent makes an effort to
avoid transparent window backgrounds. This flag is set or cleared by the widget's author.
end rem
Const Qt_WA_OpaquePaintEvent:Int = 4
Rem
bbdoc: Indicates that the widget is outside the valid range of the window system's coordinate system.
about: A widget outside the valid range cannot be mapped on screen. This is set/cleared by
the Qt kernel.
end rem
Const Qt_WA_OutsideWSRange:Int = 49
Rem
bbdoc: Indicates that the widget wants to draw directly onto the screen.
about: Widgets with this attribute set do not participate in composition management,
i.e. they cannot be semi-transparent or shine through semi-transparent overlapping
widgets. Note: This flag is only supported on X11 and it disables double buffering.
On Qt for Embedded Linux, the flag only works when set on a top-level widget and it
relies on support from the active screen driver. This flag is set or cleared by the
widget's author. To render outside of Qt's paint system, e.g., if you require native
painting primitives, you need to reimplement QWidget::paintEngine() to return 0 and set
this flag.
end rem
Const Qt_WA_PaintOnScreen:Int = 8
Rem
bbdoc: Makes it possible to use QPainter to paint on the widget outside paintEvent().
about: This flag is not supported on Windows, Mac OS X or Embedded Linux. We recommend
that you use it only when porting Qt 3 code to Qt 4.
end rem
Const Qt_WA_PaintOutsidePaintEvent:Int = 13
Rem
bbdoc: Makes all painters operating on this widget unclipped.
about: Children of this widget or other widgets in front of it do not clip the area the
painter can paint on. This flag is only supported for widgets with the WA_PaintOnScreen
flag set. The preferred way to do this in a cross platform way is to create a transparent
widget that lies in front of the other widgets.
end rem
Const Qt_WA_PaintUnclipped:Int = 52
Rem
bbdoc: Indicates that a move event is pending, e.g., when a hidden widget was moved.
about: This flag is set or cleared by the Qt kernel.
end rem
Const Qt_WA_PendingMoveEvent:Int = 34
Rem
bbdoc: Indicates that a resize event is pending, e.g., when a hidden widget was resized.
about: This flag is set or cleared by the Qt kernel.
end rem
Const Qt_WA_PendingResizeEvent:Int = 35
Rem
bbdoc: Makes Qt quit the application when the last widget with the attribute set has accepted closeEvent().
about: This behavior can be modified with the QApplication::quitOnLastWindowClosed property.
By default this attribute is set for all widgets of type Qt_Window.
end rem
Const Qt_WA_QuitOnClose:Int = 76
Rem
bbdoc: Indicates that the widget has an explicit size.
about: This flag is set or cleared by QWidget::resize() and QWidget::setGeometry().
end rem
Const Qt_WA_Resized:Int = 42
Rem
bbdoc: Indicates that the layout direction for the widget is right to left.
end rem
Const Qt_WA_RightToLeft:Int = 56
Rem
bbdoc: Indicates that the widget has a cursor of its own.
about: This flag is set or cleared by QWidget::setCursor() and QWidget::unsetCursor().
end rem
Const Qt_WA_SetCursor:Int = 38
Rem
bbdoc: Indicates that the widget has a font of its own.
about: This flag is set or cleared by QWidget::setFont().
end rem
Const Qt_WA_SetFont:Int = 37
Rem
bbdoc: Indicates that the widget has a palette of its own.
about: This flag is set or cleared by QWidget::setPalette().
end rem
Const Qt_WA_SetPalette:Int = 36
Rem
bbdoc: Indicates that the widget has a style of its own.
about: This flag is set or cleared by QWidget::setStyle().
end rem
Const Qt_WA_SetStyle:Int = 86
Rem
bbdoc: This attribute has been deprecated.
about: Use QWidget::windowModality instead.
end rem
Const Qt_WA_ShowModal:Int = 70
Rem
bbdoc: Indicates that the widget contents are north-west aligned and static.
about: On resize, such a widget will receive paint events only for parts of itself
that are newly visible. This flag is set or cleared by the widget's author.
end rem
Const Qt_WA_StaticContents:Int = 5
Rem
bbdoc: Indicates that the widget is styled using a style sheet.
end rem
Const Qt_WA_StyleSheet:Int = 97
Rem
bbdoc: Indicates that the widget should have a translucent background, i.e., any non-opaque regions of the widgets will be translucent because the widget will have an alpha channel.
about: Setting this flag causes WA_NoSystemBackground to be set. On Windows the widget also
needs the Qt_FramelessWindowHint window flag to be set. This flag is set or cleared by
the widget's author.
end rem
Const Qt_WA_TranslucentBackground:Int = 120
Rem
bbdoc: Indicates that the widget is under the mouse cursor.
about: The value is not updated correctly during drag and drop operations. There is also
a getter function, QWidget::underMouse(). This flag is set or cleared by the Qt kernel.
end rem
Const Qt_WA_UnderMouse:Int = 1
Rem
bbdoc: Indicates that updates are blocked (including the system background).
about: This flag is set or cleared by the Qt kernel.
end rem
Const Qt_WA_UpdatesDisabled:Int = 10

Rem
bbdoc: Indicates that the window is marked as modified.
about: On some platforms this flag will do nothing, on others (including Mac OS X and Windows) the window will take a modified appearance.
This flag is set or cleared by QWidget::setWindowModified().
End Rem
Const Qt_WA_WindowModified:Int = 41
Rem
bbdoc: Makes a toplevel window inherit font and palette from its parent.
end rem
Const Qt_WA_WindowPropagation:Int = 80
Rem
bbdoc: On Mac OS X, show the tool window even when the application is not active.
about: By default, all tool windows are hidden when the application is inactive.
End Rem
Const Qt_WA_MacAlwaysShowToolWindow:Int = 96
Rem
bbdoc: Indicates the locale should be taken into consideration in the widget.
end rem
Const Qt_WA_SetLocale:Int = 87
Rem
bbdoc: Indicates the widget should be drawn using a styled background.
end rem
Const Qt_WA_StyledBackground:Int = 93
Rem
bbdoc: Show the widget without making it active.
end rem
Const Qt_WA_ShowWithoutActivating:Int = 98
Rem
bbdoc: Indicates that a native window is created for the widget.
about: Enabling this flag will also force a native window for the widget's ancestors unless Qt::WA_DontCreateNativeAncestors is set.
End Rem
Const Qt_WA_NativeWindow:Int = 100
Rem
bbdoc: Indicates that the widget's ancestors are kept non-native even though the widget itself is native.
end rem
Const Qt_WA_DontCreateNativeAncestors:Int = 101
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_DESKTOP to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
End Rem
Const Qt_WA_X11NetWmWindowTypeDesktop:Int = 104
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_DOCK to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
End Rem
Const Qt_WA_X11NetWmWindowTypeDock:Int = 105
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_TOOLBAR to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
Note: Qt automaticaly sets this attribute for QToolBar.
End Rem
Const Qt_WA_X11NetWmWindowTypeToolBar:Int = 106
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_MENU to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
Note: Qt automatically sets this attribute for QMenu when torn-off.
End Rem
Const Qt_WA_X11NetWmWindowTypeMenu:Int = 107
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_UTILITY to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
Note: Qt automatically sets this attribute for the Qt::Tool window type.
End Rem
Const Qt_WA_X11NetWmWindowTypeUtility:Int = 108
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_SPLASH to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
Note: Qt automatically sets this attribute for the Qt::SplashScreen window type.
End Rem
Const Qt_WA_X11NetWmWindowTypeSplash:Int = 109
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_DIALOG to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
Note: Qt automatically sets this attribute for the Qt::Dialog and Qt::Sheet window types.
End Rem
Const Qt_WA_X11NetWmWindowTypeDialog:Int = 110
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_DROPDOWN_MENU to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
Note: Qt automatically sets this attribute for QMenus added to a QMenuBar.
End Rem
Const Qt_WA_X11NetWmWindowTypeDropDownMenu:Int = 111
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_POPUP_MENU to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
Note: Qt automatically sets this attribute for QMenu.
End Rem
Const Qt_WA_X11NetWmWindowTypePopupMenu:Int = 112
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_TOOLTIP to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms. 
Note: Qt automatically sets this attribute for the Qt::ToolTip window type.
End Rem
Const Qt_WA_X11NetWmWindowTypeToolTip:Int = 113
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_NOTIFICATION to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms.
End Rem
Const Qt_WA_X11NetWmWindowTypeNotification:Int = 114
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_COMBO to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms. 
Note: Qt automatically sets this attribute for the QComboBox pop-up.
End Rem
Const Qt_WA_X11NetWmWindowTypeCombo:Int = 115
Rem
bbdoc: Adds _NET_WM_WINDOW_TYPE_DND to the window's _NET_WM_WINDOW_TYPE X11 window property.
about: See http://standards.freedesktop.org/wm-spec/ for more details. This attribute has no effect on non-X11 platforms. 
Note: Qt automatically sets this attribute on the feedback widget used during a drag.
End Rem
Const Qt_WA_X11NetWmWindowTypeDND:Int = 116
Rem
bbdoc: Enables resolution independence aware mode on Mac when using Carbon.
about: This attribute has no effect on Cocoa. The attribute is off by default and can be enabled on a per-window basis.
End Rem
Const Qt_WA_MacFrameworkScaled:Int = 117
Rem
bbdoc: Allows touch events (see QTouchEvent) to be sent to the widget.
about: Must be set on all widgets that can handle touch events. Without this attribute set, events from a touch device will be sent as mouse events.
End Rem
Const Qt_WA_AcceptTouchEvents:Int = 121
Rem
bbdoc: Allows touchpad single touch events to be sent to the widget.
end rem
Const Qt_WA_TouchPadAcceptSingleTouchEvents:Int = 123
Rem
bbdoc: Allows widget to merge softkeys with parent widget
about: i.e. widget can set only one softkeys and request softkey implementation to take rest of the softkeys from the parent.
Note parents are traversed until WA_MergeSoftkeys is not set. See also Qt::WA_MergeSoftkeysRecursively This attribute currently has effect only on Symbian platforms
End Rem
Const Qt_WA_MergeSoftkeys:Int = 124
Rem
bbdoc: Allows widget to merge softkeys recursively with all parents.
about: If this attribute is set, the widget parents are traversed until window boundary (widget without parent or dialog) is found.
This attribute currently has effect only on Symbian platforms
End Rem
Const Qt_WA_MergeSoftkeysRecursively:Int = 125
Rem
bbdoc: Asks the window manager to not give focus to this top level window.
about: This attribute has no effect on non-X11 platforms.
End Rem
Const Qt_WA_X11DoNotAcceptFocus:Int = 132
Rem
bbdoc: Locks the widget to a portrait orientation, ignoring changes to the display's orientation with respect to the user.
end rem
Const Qt_WA_LockPortraitOrientation:Int = 128
Rem
bbdoc: Locks the widget to a landscape orientation, ignoring changes to the display's orientation with respect to the user.
end rem
Const Qt_WA_LockLandscapeOrientation:Int = 129
Rem
bbdoc: Causes the widget to change orientation whenever the display changes orientation with respect to the user.
end rem
Const Qt_WA_AutoOrientation:Int = 130
Rem
bbdoc: Since Qt 4.8, this attribute disables drop shadows for this top level window.
about: Only affects Cocoa builds of Qt for Mac OS X.
End Rem
Const Qt_WA_MacNoShadow:Int = 134


Rem
bbdoc: The X axis.
End Rem
Const Qt_XAxis:Int = 0
Rem
bbdoc: The Y axis.
End Rem
Const Qt_YAxis:Int = 1
Rem
bbdoc: The Z axis.
End Rem
Const Qt_ZAxis:Int = 2


Rem
bbdoc: 'void' Meta Type.
End Rem
Const QMetaType_Void:Int = 0
Rem
bbdoc: 'bool' Meta Type.
End Rem
Const QMetaType_Bool:Int = 1
Rem
bbdoc: 'int' Meta Type.
End Rem
Const QMetaType_Int:Int = 2
Rem
bbdoc: 'unsigned int' Meta Type.
End Rem
Const QMetaType_UInt:Int = 3
Rem
bbdoc: 'double' Meta Type.
End Rem
Const QMetaType_Double:Int = 6
Rem
bbdoc: 'QChar' Meta Type.
End Rem
Const QMetaType_QChar:Int = 7
Rem
bbdoc: 'QString' Meta Type.
End Rem
Const QMetaType_QString:Int = 10
Rem
bbdoc: 'QByteArray' Meta Type.
End Rem
Const QMetaType_QByteArray:Int = 12
Rem
bbdoc: 'void *' Meta Type.
End Rem
Const QMetaType_VoidStar:Int = 128
Rem
bbdoc: 'long' Meta Type.
End Rem
Const QMetaType_Long:Int = 129
Rem
bbdoc: 'LongLong' Meta Type.
End Rem
Const QMetaType_LongLong:Int = 4
Rem
bbdoc: 'short' Meta Type.
End Rem
Const QMetaType_Short:Int = 130
Rem
bbdoc: 'char' Meta Type.
End Rem
Const QMetaType_Char:Int = 131
Rem
bbdoc: 'unsigned long' Meta Type.
End Rem
Const QMetaType_ULong:Int = 132
Rem
bbdoc: 'ULongLong' Meta Type.
End Rem
Const QMetaType_ULongLong:Int = 5
Rem
bbdoc: 'unsigned short' Meta Type.
End Rem
Const QMetaType_UShort:Int = 133
Rem
bbdoc: 'unsigned char' Meta Type.
End Rem
Const QMetaType_UChar:Int = 134
Rem
bbdoc: 'float' Meta Type.
End Rem
Const QMetaType_Float:Int = 135
Rem
bbdoc: 'QObject *' Meta Type.
End Rem
Const QMetaType_QObjectStar:Int = 136
Rem
bbdoc: 'QWidget *' Meta Type.
End Rem
Const QMetaType_QWidgetStar:Int = 137
Rem
bbdoc: 'QVariant' Meta Type.
End Rem
Const QMetaType_QVariant:Int = 138
Rem
bbdoc: 'QColorGroup' Meta Type.
End Rem
Const QMetaType_QColorGroup:Int = 63
Rem
bbdoc: 'QCursor' Meta Type.
End Rem
Const QMetaType_QCursor:Int = 74
Rem
bbdoc: 'QDate' Meta Type.
End Rem
Const QMetaType_QDate:Int = 14
Rem
bbdoc: 'QSize' Meta Type.
End Rem
Const QMetaType_QSize:Int = 21
Rem
bbdoc: 'QTime' Meta Type.
End Rem
Const QMetaType_QTime:Int = 15
Rem
bbdoc: 'QVariantList' Meta Type.
End Rem
Const QMetaType_QVariantList:Int = 9
Rem
bbdoc: 'QPolygon' Meta Type.
End Rem
Const QMetaType_QPolygon:Int = 71
Rem
bbdoc: 'QColor' Meta Type.
End Rem
Const QMetaType_QColor:Int = 67
Rem
bbdoc: 'QSizeF' Meta Type.
End Rem
Const QMetaType_QSizeF:Int = 22
Rem
bbdoc: 'QRectF' Meta Type.
End Rem
Const QMetaType_QRectF:Int = 20
Rem
bbdoc: 'QLine' Meta Type.
End Rem
Const QMetaType_QLine:Int = 23
Rem
bbdoc: 'QTextLength' Meta Type.
End Rem
Const QMetaType_QTextLength:Int = 78
Rem
bbdoc: 'QStringList' Meta Type.
End Rem
Const QMetaType_QStringList:Int = 11
Rem
bbdoc: 'QVariantMap' Meta Type.
End Rem
Const QMetaType_QVariantMap:Int = 8
Rem
bbdoc: 'QVariantHash' Meta Type.
End Rem
Const QMetaType_QVariantHash:Int = 28
Rem
bbdoc: 'QIcon' Meta Type.
End Rem
Const QMetaType_QIcon:Int = 69
Rem
bbdoc: 'QPen' Meta Type.
End Rem
Const QMetaType_QPen:Int = 77
Rem
bbdoc: 'QLineF' Meta Type.
End Rem
Const QMetaType_QLineF:Int = 24
Rem
bbdoc: 'QTextFormat' Meta Type.
End Rem
Const QMetaType_QTextFormat:Int = 79
Rem
bbdoc: 'QRect' Meta Type.
End Rem
Const QMetaType_QRect:Int = 19
Rem
bbdoc: 'QPoint' Meta Type.
End Rem
Const QMetaType_QPoint:Int = 25
Rem
bbdoc: 'QUrl' Meta Type.
End Rem
Const QMetaType_QUrl:Int = 17
Rem
bbdoc: 'QRegExp' Meta Type.
End Rem
Const QMetaType_QRegExp:Int = 27
Rem
bbdoc: 'QDateTime' Meta Type.
End Rem
Const QMetaType_QDateTime:Int = 16
Rem
bbdoc: 'QPointF' Meta Type.
End Rem
Const QMetaType_QPointF:Int = 26
Rem
bbdoc: 'QPalette' Meta Type.
End Rem
Const QMetaType_QPalette:Int = 68
Rem
bbdoc: 'QFont' Meta Type.
End Rem
Const QMetaType_QFont:Int = 64
Rem
bbdoc: 'QBrush' Meta Type.
End Rem
Const QMetaType_QBrush:Int = 66
Rem
bbdoc: 'QRegion' Meta Type.
End Rem
Const QMetaType_QRegion:Int = 72
Rem
bbdoc: 'QBitArray' Meta Type.
End Rem
Const QMetaType_QBitArray:Int = 13
Rem
bbdoc: 'QImage' Meta Type.
End Rem
Const QMetaType_QImage:Int = 70
Rem
bbdoc: 'QKeySequence' Meta Type.
End Rem
Const QMetaType_QKeySequence:Int = 76
Rem
bbdoc: 'QSizePolicy' Meta Type.
End Rem
Const QMetaType_QSizePolicy:Int = 75
Rem
bbdoc: 'QPixmap' Meta Type.
End Rem
Const QMetaType_QPixmap:Int = 65
Rem
bbdoc: 'QLocale' Meta Type.
End Rem
Const QMetaType_QLocale:Int = 18
Rem
bbdoc: 'QBitmap' Meta Type.
End Rem
Const QMetaType_QBitmap:Int = 73
Rem
bbdoc: 'QMatrix' Meta Type.
End Rem
Const QMetaType_QMatrix:Int = 80
Rem
bbdoc: 'QTransform' Meta Type.
End Rem
Const QMetaType_QTransform:Int = 81
Rem
bbdoc: 'QMatrix4x4' Meta Type.
End Rem
Const QMetaType_QMatrix4x4:Int = 82
Rem
bbdoc: 'QVector2D' Meta Type.
End Rem
Const QMetaType_QVector2D:Int = 83
Rem
bbdoc: 'QVector3D' Meta Type.
End Rem
Const QMetaType_QVector3D:Int = 84
Rem
bbdoc: 'QVector4D' Meta Type.
End Rem
Const QMetaType_QVector4D:Int = 85
Rem
bbdoc: 'QQuaternion' Meta Type.
End Rem
Const QMetaType_QQuaternion:Int = 86
Rem
bbdoc: 'QEasingCurve' Meta Type.
End Rem
Const QMetaType_QEasingCurve:Int = 29
Rem
bbdoc: 'Base value for user types' Meta Type.
End Rem
Const QMetaType_User:Int = 256
