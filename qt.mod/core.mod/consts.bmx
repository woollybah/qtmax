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


