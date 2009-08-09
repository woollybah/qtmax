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

Import Qt.Core
Import Qt.QObject
Import Qt.QLocale
Import Qt.QRegion
Import Qt.QPaintEvent
Import Qt.QMouseEvent
Import Qt.QMoveEvent
Import Qt.QCloseEvent
Import Qt.QContextMenuEvent
Import Qt.QFocusEvent
Import Qt.QHideEvent
Import Qt.QInputMethodEvent
Import Qt.QKeyEvent
Import Qt.QResizeEvent
Import Qt.QShowEvent
Import Qt.QTabletEvent
Import Qt.QWheelEvent
Import Qt.QIcon
Import Qt.QSizePolicy
Import Qt.QFont
Import Qt.QFontMetrics
Import Qt.QKeySequence
Import BRL.Blitz


' headers :-)
?win32
Import "../lib/win32/include/*.h"
?macos
Import "../lib/macos/include/*.h"
?Not linux
Import "../src/include/*.h"
Import "../src/include/Qt/*.h"
Import "../src/include/QtCore/*.h"
Import "../src/include/QtGui/*.h"
?linux
Import "/usr/include/qt4/*.h"
Import "/usr/include/qt4/Qt/*.h"
Import "/usr/include/qt4/QtCore/*.h"
Import "/usr/include/qt4/QtGui/*.h"
?


Import "glue.cpp"

Extern

	Function bmx_qt_qwidget_create:Byte Ptr(handle:Object, parent:Byte Ptr, flags:Int)
	Function bmx_qt_qwidget_hide(handle:Byte Ptr)
	Function bmx_qt_qwidget_show(handle:Byte Ptr)
	Function bmx_qt_qwidget_setlayout(handle:Byte Ptr, layout:Byte Ptr)
	Function bmx_qt_qwidget_setwindowtitle(handle:Byte Ptr, title:String)

	Function bmx_qt_qwidget_showfullscreen(handle:Byte Ptr)
	Function bmx_qt_qwidget_showmaximized(handle:Byte Ptr)
	Function bmx_qt_qwidget_showminimized(handle:Byte Ptr)
	Function bmx_qt_qwidget_shownormal(handle:Byte Ptr)
	Function bmx_qt_qwidget_stackunder(handle:Byte Ptr, w:Byte Ptr)
	Function bmx_qt_qwidget_setfixedsize(handle:Byte Ptr, w:Int, h:Int)
	Function bmx_qt_qwidget_setfixedwidth(handle:Byte Ptr, w:Int)
	Function bmx_qt_qwidget_setfocus(handle:Byte Ptr, reason:Int)
	Function bmx_qt_qwidget_close(handle:Byte Ptr)
	Function bmx_qt_qwidget_update(handle:Byte Ptr)
	Function bmx_qt_qwidget_raise(handle:Byte Ptr)
	Function bmx_qt_qwidget_repaint(handle:Byte Ptr)
	Function bmx_qt_qwidget_setdisabled(handle:Byte Ptr, disable:Int)
	Function bmx_qt_qwidget_setenabled(handle:Byte Ptr, value:Int)
	Function bmx_qt_qwidget_sethidden(handle:Byte Ptr, hidden:Int)
	Function bmx_qt_qwidget_setstylesheet(handle:Byte Ptr, styleSheet:String)
	Function bmx_qt_qwidget_setvisible(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qwidget_setwindowmodified(handle:Byte Ptr, value:Int)
	Function bmx_qt_qwidget_resize(handle:Byte Ptr, w:Int, h:Int)
	Function bmx_qt_qwidget_addaction(handle:Byte Ptr, action:Byte Ptr)
	Function bmx_qt_qwidget_setcontextmenupolicy(handle:Byte Ptr, policy:Int)
	Function bmx_qt_qwidget_framegeometry:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwidget_framesize(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_qt_qwidget_geometry:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwidget_setattribute(handle:Byte Ptr, attribute:Int)
	Function bmx_qt_qwidget_move(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_qt_qwidget_settooltip(handle:Byte Ptr, text:String)
	Function bmx_qt_qwidget_sizepolicy:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwidget_setsizepolicyhv(handle:Byte Ptr, horizontalPolicy:Int, verticalPolicy:Int)
	Function bmx_qt_qwidget_font:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwidget_fontmetrics:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qwidget_setfont(handle:Byte Ptr, font:Byte Ptr)

	Function bmx_qt_qwidget_height:Int(handle:Byte Ptr)
	Function bmx_qt_qwidget_width:Int(handle:Byte Ptr)

	Function bmx_qt_qaction_create:Byte Ptr(handle:Object, text:String, parent:Byte Ptr)
	Function bmx_qt_qaction_createwithicon:Byte Ptr(handle:Object, icon:Byte Ptr, text:String, parent:Byte Ptr)
	Function bmx_qt_qaction_setshortcut(handle:Byte Ptr, sequence:String)
	Function bmx_qt_qaction_actiongroup:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qaction_activate(handle:Byte Ptr, event:Int)
	Function bmx_qt_qaction_autorepeat:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_data:Object(handle:Byte Ptr)
	Function bmx_qt_qaction_font:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qaction_icontext:String(handle:Byte Ptr)
	Function bmx_qt_qaction_ischeckable:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_ischecked:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_isenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_isiconvisibleinmenu:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_isseparator:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_isvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_menu:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qaction_menurole:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_parentwidget:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qaction_setactiongroup(handle:Byte Ptr, group:Byte Ptr)
	Function bmx_qt_qaction_setautorepeat(handle:Byte Ptr, value:Int)
	Function bmx_qt_qaction_setcheckable(handle:Byte Ptr, value:Int)
	Function bmx_qt_qaction_setdata(handle:Byte Ptr, userData:Object)
	Function bmx_qt_qaction_setfont(handle:Byte Ptr, font:Byte Ptr)
	Function bmx_qt_qaction_seticontext(handle:Byte Ptr, text:String)
	Function bmx_qt_qaction_seticonvisibleinmenu(handle:Byte Ptr, visible:Int)
	Function bmx_qt_qaction_setmenu(handle:Byte Ptr, menu:Byte Ptr)
	Function bmx_qt_qaction_setmenurole(handle:Byte Ptr, menuRole:Int)
	Function bmx_qt_qaction_setseparator(handle:Byte Ptr, value:Int)
	Function bmx_qt_qaction_setshortcutcontext(handle:Byte Ptr, context:Int)
	Function bmx_qt_qaction_setstatustip(handle:Byte Ptr, statusTip:String)
	Function bmx_qt_qaction_settext(handle:Byte Ptr, text:String)
	Function bmx_qt_qaction_settooltip(handle:Byte Ptr, tip:String)
	Function bmx_qt_qaction_setwhatsthis(handle:Byte Ptr, what:String)
	Function bmx_qt_qaction_shortcut:String(handle:Byte Ptr)
	Function bmx_qt_qaction_shortcutcontext:Int(handle:Byte Ptr)
	Function bmx_qt_qaction_showstatustext:Int(handle:Byte Ptr, widget:Byte Ptr)
	Function bmx_qt_qaction_statustip:String(handle:Byte Ptr)
	Function bmx_qt_qaction_text:String(handle:Byte Ptr)
	Function bmx_qt_qaction_tooltip:String(handle:Byte Ptr)
	Function bmx_qt_qaction_whatsthis:String(handle:Byte Ptr)
	Function bmx_qt_qaction_setshortcuts(handle:Byte Ptr, key:Int)
	Function bmx_qt_qaction_hover(handle:Byte Ptr)
	Function bmx_qt_qaction_setchecked(handle:Byte Ptr, value:Int)
	Function bmx_qt_qaction_setdisabled(handle:Byte Ptr, value:Int)
	Function bmx_qt_qaction_setenabled(handle:Byte Ptr, value:Int)
	Function bmx_qt_qaction_setvisible(handle:Byte Ptr, value:Int)
	Function bmx_qt_qaction_toggle(handle:Byte Ptr)
	Function bmx_qt_qaction_trigger(handle:Byte Ptr)


	Function bmx_qt_qactiongroup_create:Byte Ptr(handle:Object, parent:Byte Ptr)
	Function bmx_qt_qactiongroup_addaction:Byte Ptr(handle:Byte Ptr, action:Byte Ptr)
	Function bmx_qt_qactiongroup_addactiontext:Byte Ptr(handle:Byte Ptr, text:String)
	Function bmx_qt_qactiongroup_checkedaction:Byte Ptr(handle:Byte Ptr)
	Function bmx_qt_qactiongroup_isenabled:Int(handle:Byte Ptr)
	Function bmx_qt_qactiongroup_isexclusive:Int(handle:Byte Ptr)
	Function bmx_qt_qactiongroup_isvisible:Int(handle:Byte Ptr)
	Function bmx_qt_qactiongroup_removeaction(handle:Byte Ptr, action:Byte Ptr)
	Function bmx_qt_qactiongroup_setdisabled(handle:Byte Ptr, value:Int)
	Function bmx_qt_qactiongroup_setenabled(handle:Byte Ptr, value:Int)
	Function bmx_qt_qactiongroup_setexclusive(handle:Byte Ptr, value:Int)
	Function bmx_qt_qactiongroup_setvisible(handle:Byte Ptr, value:Int)

End Extern

Rem
bbdoc: Allows data from drag and drop operations to be dropped onto the widget (see QWidget::setAcceptDrops()).
end rem
Const WA_AcceptDrops:Int = 78
Rem
bbdoc: Enables tooltips for inactive windows.
end rem
Const WA_AlwaysShowToolTips:Int = 84
Rem
bbdoc: This flag is superfluous and obsolete; it no longer has any effect.
about: Since Qt 4.1, all widgets that do not set WA_PaintOnScreen propagate their contents.
end rem
Const WA_ContentsPropagated:Int = 3
Rem
bbdoc: Indicates that the widget wants to continue operating normally in "What's This?" mode.
about: This is set by the widget's author.
end rem
Const WA_CustomWhatsThis:Int = 47
Rem
bbdoc: Makes Qt delete this widget when the widget has accepted the close event (see QWidget::closeEvent()).
end rem
Const WA_DeleteOnClose:Int = 55
Rem
bbdoc: Indicates that the widget is disabled, i.e. it does not receive any mouse or keyboard events.
about: There is also a getter functions QWidget::isEnabled(). This is set/cleared by the Qt kernel.
end rem
Const WA_Disabled:Int = 0
Rem
bbdoc: Indicates that the widget is explicitly disabled, i.e. it will remain disabled even when all its ancestors are set to the enabled state.
about: This implies WA_Disabled. This is set/cleared by QWidget::setEnabled() and QWidget::setDisabled().
end rem
Const WA_ForceDisabled:Int = 32
Rem
bbdoc: Indicates that updates are explicitly disabled for the widget; i.e. it will remain disabled even when all its ancestors are set to the updates-enabled state.
about: This implies WA_UpdatesDisabled. This is set/cleared by QWidget::setUpdatesEnabled().
end rem
Const WA_ForceUpdatesDisabled:Int = 59
Rem
bbdoc: This attribute has been deprecated. Use QWidget::windowModality instead.
end rem
Const WA_GroupLeader:Int = 72
Rem
bbdoc: Forces Qt to generate paint events when the mouse enters or leaves the widget.
about: This feature is typically used when implementing custom styles; see the Styles example for details.
end rem
Const WA_Hover:Int = 74
Rem
bbdoc: Enables input methods for Asian languages.
about: Must be set when creating custom text editing widgets. On Windows CE this flag can be used in addition to QApplication::autoSipEnabled to automatically
display the SIP when entering a widget.
end rem
Const WA_InputMethodEnabled:Int = 14
Rem
bbdoc: Set on a toplevel window when the users changes focus with the keyboard (tab, backtab, or shortcut).
end rem
Const WA_KeyboardFocusChange:Int = 77
Rem
bbdoc: Enables key event compression if set, and disables it if not set.
about: By default key compression is off, so widgets receive one key press event for each key press (or more, since autorepeat is usually on). If you turn
it on and your program doesn't keep up with key input, Qt may try to compress key events so that more than one character can be processed in each event.
For example, a word processor widget might receive 2, 3 or more characters in each QKeyEvent::text(), if the layout recalculation takes too long for the
CPU. If a widget supports multiple character unicode input, it is always safe to turn the compression on. Qt performs key event compression only for
printable characters. Qt::Modifier keys, cursor movement keys, function keys and miscellaneous action keys (e.g. Escape, Enter, Backspace, PrintScreen)
will stop key event compression, even if there are more compressible key events available. Platforms other than Mac and X11 do not support this compression,
in which case turning it on will have no effect. This is set/cleared by the widget's author.
end rem
Const WA_KeyCompression:Int = 33
Rem
bbdoc: Indicates that the widget wants QLayout to operate on the entire QWidget::rect(), not only on QWidget::contentsRect().
about: This is set by the widget's author.
end rem
Const WA_LayoutOnEntireRect:Int = 48
Rem
bbdoc: Ignore the layout item rect from the style when laying out this widget with QLayout.
about: This makes a difference in QMacStyle and QPlastiqueStyle for some widgets.
end rem
Const WA_LayoutUsesWidgetRect:Int = 92
Rem
bbdoc: When a widget that has this attribute set is clicked, and its window is inactive, the click will make the window active but won't be seen by the widget.
about: Typical use of this attribute is on widgets with "destructive" actions, such as a "Delete" button. WA_MacNoClickThrough also applies to all child
widgets of the widget that has it set.
end rem
Const WA_MacNoClickThrough:Int = 12
Rem
bbdoc: Indicates that the native Carbon size grip should be opaque instead of transparent (the default).
about: This attribute is only applicable to Mac OS X and is set by the widget's author.
end rem
Const WA_MacOpaqueSizeGrip:Int = 85
Rem
bbdoc: Indicates that this widget should get a QFocusFrame around it.
about: Some widgets draw their own focus halo regardless of this attribute. Not that the QWidget::focusPolicy also plays the main role in whether something is
given focus or not, this only controls whether or not this gets the focus frame. This attribute is only applicable to Mac OS X.
end rem
Const WA_MacShowFocusRect:Int = 88
Rem
bbdoc: Indicates the widget should have the normal size for widgets in Mac OS X.
about: This attribute is only applicable to Mac OS X.
end rem
Const WA_MacNormalSize:Int = 89
Rem
bbdoc: Indicates the widget should have the small size for widgets in Mac OS X.
about: This attribute is only applicable to Mac OS X.
end rem
Const WA_MacSmallSize:Int = 90
Rem
bbdoc: Indicates the widget should have the mini size for widgets in Mac OS X.
about: This attribute is only applicable to Mac OS X.
end rem
Const WA_MacMiniSize:Int = 91
Rem
bbdoc: Indicates the widget can choose between alternative sizes for widgets to avoid clipping.
about: This attribute is only applicable to Mac OS X.
end rem
Const WA_MacVariableSize:Int = 102
Rem
bbdoc: Indicates the widget should be drawn in the brushed metal style as supported by the windowing system.
about: This attribute is only applicable to Mac OS X.
end rem
Const WA_MacBrushedMetal:Int = 46
Rem
bbdoc: Indicates that the widget is mapped on screen. 
about: This is set/cleared by the Qt kernel.
end rem
Const WA_Mapped:Int = 11
Rem
bbdoc: Makes the widget receive mouse events for the entire widget regardless of the currently set mask, overriding QWidget::setMask().
about: This is not applicable for top-level windows.
end rem
Const WA_MouseNoMask:Int = 71
Rem
bbdoc: Indicates that the widget has mouse tracking enabled.
about: See QWidget::mouseTracking.
end rem
Const WA_MouseTracking:Int = 2
Rem
bbdoc: Indicates that the widget has an explicit position.
about: This is set/cleared by QWidget::move() and by QWidget::setGeometry().
end rem
Const WA_Moved:Int = 43
Rem
bbdoc: Makes drawing to a widget with this attribute set use the Direct3D paint engine, if the Direct3D paint engine is available.
about: This functionality is experimental.
end rem
Const WA_MSWindowsUseDirect3D:Int = 94
Rem
bbdoc: Indicates that the widget does not want ChildAdded or ChildRemoved events sent to its parent.
about: This is rarely necessary but can help to avoid automatic insertion widgets like splitters and layouts. This is set by a widget's author.
end rem
Const WA_NoChildEventsForParent:Int = 58
Rem
bbdoc: Indicates that the widget does not want to receive ChildAdded or ChildRemoved events sent from its children.
about: This is set by a widget's author.
end rem
Const WA_NoChildEventsFromChildren:Int = 39
Rem
bbdoc: Used for pop-up widgets.
about: Indicates that the most recent mouse press event should not be replayed when the pop-up widget closes. The flag is set by
the widget's author and cleared by the Qt kernel every time the widget receives a new mouse event.
end rem
Const WA_NoMouseReplay:Int = 54
Rem
bbdoc: Prohibits mouse events from being propagated to the widget's parent.
about: This attribute is disabled by default.
end rem
Const WA_NoMousePropagation:Int = 73
Rem
bbdoc: When enabled, this attribute disables the delivery of mouse events to the widget and its children.
about: Mouse events are delivered to other widgets as if the widget and its children were not present in the widget hierarchy; mouse clicks
and other events effectively "pass through" them. This attribute is disabled by default.
end rem
Const WA_TransparentForMouseEvents:Int = 51
Rem
bbdoc: Indicates that the widget has no background, i.e. when the widget receives paint events, the background is not automatically repainted.
about: Note: Unlike WA_OpaquePaintEvent, newly exposed areas are never filled with the background (e.g., after showing a window for the first
time the user can see "through" it until the application processes the paint events). This flag is set or cleared by the widget's author.
end rem
Const WA_NoSystemBackground:Int = 9
Rem
bbdoc: Indicates that the widget paints all its pixels when it receives a paint event.
about: Thus, it is not required for operations like updating, resizing, scrolling and focus changes to erase the widget before generating paint
events. The use of WA_OpaquePaintEvent provides a small optimization by helping to reduce flicker on systems that do not support double buffering
and avoiding computational cycles necessary to erase the background prior to painting. Note: Unlike WA_NoSystemBackground, WA_OpaquePaintEvent
makes an effort to avoid transparent window backgrounds. This flag is set or cleared by the widget's author.
end rem
Const WA_OpaquePaintEvent:Int = 4
Rem
bbdoc: Indicates that the widget is outside the valid range of the window system's coordinate system.
about: A widget outside the valid range cannot be mapped on screen. This is set/cleared by the Qt kernel.
end rem
Const WA_OutsideWSRange:Int = 49
Rem
bbdoc: Indicates that the widget wants to draw directly onto the screen.
about: Widgets with this attribute set do not participate in composition management, i.e. they cannot be semi-transparent or shine through
semi-transparent overlapping widgets. Note: This flag is only supported on X11 and it disables double buffering. On Qt for Embedded Linux,
the flag only works when set on a top-level widget and it relies on support from the active screen driver. This flag is set or cleared by the
widget's author. To render outside of Qt's paint system, e.g., if you require native painting primitives, you need to reimplement QWidget::paintEngine()
to return 0 and set this flag.
end rem
Const WA_PaintOnScreen:Int = 8
Rem
bbdoc: Makes it possible to use QPainter to paint on the widget outside paintEvent().
about: This flag is not supported on Windows, Mac OS X or Embedded Linux. We recommend that you use it only when porting Qt 3 code to Qt 4.
end rem
Const WA_PaintOutsidePaintEvent:Int = 13
Rem
bbdoc: Makes all painters operating on this widget unclipped.
about: Children of this widget or other widgets in front of it do not clip the area the painter can paint on. This flag is only supported for widgets
with the WA_PaintOnScreen flag set. The preferred way to do this in a cross platform way is to create a transparent widget that lies in front of the other widgets.
end rem
Const WA_PaintUnclipped:Int = 52
Rem
bbdoc: Indicates that a move event is pending, e.g., when a hidden widget was moved.
about: This flag is set or cleared by the Qt kernel.
end rem
Const WA_PendingMoveEvent:Int = 34
Rem
bbdoc: Indicates that a resize event is pending, e.g., when a hidden widget was resized.
about: This flag is set or cleared by the Qt kernel.
end rem
Const WA_PendingResizeEvent:Int = 35
Rem
bbdoc: Makes Qt quit the application when the last widget with the attribute set has accepted closeEvent().
about: This behavior can be modified with the QApplication::quitOnLastWindowClosed property. By default this attribute is set for all widgets of type Qt::Window.
end rem
Const WA_QuitOnClose:Int = 76
Rem
bbdoc: Indicates that the widget has an explicit size.
about: This flag is set or cleared by QWidget::resize() and QWidget::setGeometry().
end rem
Const WA_Resized:Int = 42
Rem
bbdoc: Indicates that the layout direction for the widget is right to left.
end rem
Const WA_RightToLeft:Int = 56
Rem
bbdoc: Indicates that the widget has a cursor of its own.
about: This flag is set or cleared by QWidget::setCursor() and QWidget::unsetCursor().
end rem
Const WA_SetCursor:Int = 38
Rem
bbdoc: Indicates that the widget has a font of its own.
about: This flag is set or cleared by QWidget::setFont().
end rem
Const WA_SetFont:Int = 37
Rem
bbdoc: Indicates that the widget has a palette of its own.
about: This flag is set or cleared by QWidget::setPalette().
end rem
Const WA_SetPalette:Int = 36
Rem
bbdoc: Indicates that the widget has a style of its own.
about: This flag is set or cleared by QWidget::setStyle().
end rem
Const WA_SetStyle:Int = 86
Rem
bbdoc: This attribute has been deprecated.
about: Use QWidget::windowModality instead.
end rem
Const WA_ShowModal:Int = 70
Rem
bbdoc: Indicates that the widget contents are north-west aligned and static.
about: On resize, such a widget will receive paint events only for parts of itself that are newly visible. This flag is set or cleared by the widget's author.
end rem
Const WA_StaticContents:Int = 5
Rem
bbdoc: Indicates that the widget is styled using a style sheet.
end rem
Const WA_StyleSheet:Int = 97
Rem
bbdoc: Indicates that the widget should have a translucent background, i.e., any non-opaque regions of the widgets will be translucent because the widget will have an alpha channel.
about: Setting this flag causes WA_NoSystemBackground to be set. On Windows the widget also needs the Qt::FramelessWindowHint window flag to be set.
This flag is set or cleared by the widget's author.
end rem
Const WA_TranslucentBackground:Int = 120
Rem
bbdoc: Indicates that the widget is under the mouse cursor.
about: The value is not updated correctly during drag and drop operations. There is also a getter function, QWidget::underMouse(). This flag is set or cleared by the Qt kernel.
end rem
Const WA_UnderMouse:Int = 1
Rem
bbdoc: Indicates that updates are blocked (including the system background).
about: This flag is set or cleared by the Qt kernel.
end rem
Const WA_UpdatesDisabled:Int = 10


Rem
bbdoc: The widget does not feature a context menu, context menu handling is deferred to the widget's parent.
end rem
Const Qt_NoContextMenu:Int = 0
Rem
bbdoc: The widget does not feature a context menu, and in contrast to NoContextMenu, the handling is not deferred to the widget's parent.
about: This means that all right mouse button events are guaranteed to be delivered to the widget itself through mousePressEvent(), and mouseReleaseEvent().
end rem
Const Qt_PreventContextMenu:Int = 4
Rem
bbdoc: The widget's QWidget::contextMenuEvent() handler is called.
End Rem
Const Qt_DefaultContextMenu:Int = 1
Rem
bbdoc: The widget displays its QWidget::actions() as context menu.
End Rem
Const Qt_ActionsContextMenu:Int = 2
Rem
bbdoc: The widget emits the QWidget::customContextMenuRequested() signal.
End Rem
Const Qt_CustomContextMenu:Int = 3


Rem
bbdoc: The button state does not refer to any button (see QMouseEvent::button()).
end rem
Const Qt_NoButton:Int = $00000000
Rem
bbdoc: The left button is pressed, or an event refers to the left button.
about: The left button may be the right button on left-handed mice.
end rem
Const Qt_LeftButton:Int = $00000001
Rem
bbdoc: The right button.
end rem
Const Qt_RightButton:Int = $00000002
Rem
bbdoc: The middle button.
end rem
Const Qt_MidButton:Int = $00000004
Rem
bbdoc: The first X button.
end rem
Const Qt_XButton1:Int = $00000008
Rem
bbdoc: The second X button.
end rem
Const Qt_XButton2:Int = $00000010
