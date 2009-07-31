/*
  Copyright (c) 2009 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQWidget::MaxQWidget(BBObject * handle, QWidget * parent, Qt::WindowFlags flags)
	: maxHandle(handle), QWidget(parent, flags)
{
	qbind(this, handle);
}

MaxQWidget::~MaxQWidget()
{
	qunbind(this);
}


void MaxQWidget::paintEvent(QPaintEvent * event) {
	QPainter p(this);
	_qt_qwidget_QWidget__OnPaintEvent(maxHandle, event, _qt_qpainter_QPainter__create(&p));
}

void MaxQWidget::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseDoubleClickEvent(maxHandle, event);
}

void MaxQWidget::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseMoveEvent(maxHandle, event);
}

void MaxQWidget::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMousePressEvent(maxHandle, event);
}

void MaxQWidget::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseReleseEvent(maxHandle, event);
}

// ---------------------------------------------------------------------------------------

MaxQAction::MaxQAction(BBObject * handle, const QString & text, QObject * parent)
	: maxHandle(handle), QAction(text, parent)
{
	qbind(this, handle);

	doConnections();
}

MaxQAction::~MaxQAction()
{
	qunbind(this);
}

MaxQAction::MaxQAction(QObject * obj)
	: QAction(obj)
{
	maxHandle = _qt_qwidget_QAction__create(this);
	qbind(this, maxHandle);

	doConnections();
}

MaxQAction::MaxQAction(const QString & text, QObject * obj)
	: QAction(text, obj)
{
	maxHandle = _qt_qwidget_QAction__create(this);
	qbind(this, maxHandle);

	doConnections();
}

void MaxQAction::doConnections() {
	connect(this, SIGNAL(changed()), SLOT(onChanged()));
	connect(this, SIGNAL(hovered()), SLOT(onHovered()));
	connect(this, SIGNAL(toggled(bool)), SLOT(onToggled(bool)));
	connect(this, SIGNAL(triggered(bool)), SLOT(onTriggered(bool)));
}

void MaxQAction::onChanged() {
	_qt_qwidget_QAction__OnChanged(maxHandle);
}

void MaxQAction::onHovered() {
	_qt_qwidget_QAction__OnHovered(maxHandle);
}

void MaxQAction::onToggled(bool checked) {
	_qt_qwidget_QAction__OnToggled(maxHandle, static_cast<int>(checked));
}

void MaxQAction::onTriggered(bool checked) {
	_qt_qwidget_QAction__OnTriggered(maxHandle, static_cast<int>(checked));
}


// *********************************************


QWidget * bmx_qt_qwidget_create(BBObject * handle, QWidget * parent, int f) {
	return new MaxQWidget(handle, parent, bmx_qt_getwindowflags(f));
}

void bmx_qt_qwidget_hide(QWidget * widget) {
	widget->hide();
}

void bmx_qt_qwidget_show(QWidget * widget) {
	widget->show();
}

void bmx_qt_qwidget_setlayout(QWidget * widget, QLayout * layout) {
	widget->setLayout(layout);
}

void bmx_qt_qwidget_setwindowtitle(QWidget * widget, BBString * title) {
	widget->setWindowTitle(qStringFromBBString(title));
}

void bmx_qt_qwidget_showfullscreen(QWidget * widget) {
	widget->showFullScreen();
}

void bmx_qt_qwidget_showmaximized(QWidget * widget) {
	widget->showMaximized();
}

void bmx_qt_qwidget_showminimized(QWidget * widget) {
	widget->showMinimized();
}

void bmx_qt_qwidget_shownormal(QWidget * widget) {
	widget->showNormal();
}

void bmx_qt_qwidget_stackunder(QWidget * widget, QWidget * w) {
	widget->stackUnder(w);
}

void bmx_qt_qwidget_setfixedsize(QWidget * widget, int w, int h) {
	widget->setFixedSize(w, h);
}

void bmx_qt_qwidget_setfixedwidth(QWidget * widget, int w) {
	widget->setFixedWidth(w);
}

void bmx_qt_qwidget_setfocus(QWidget * widget, int reason) {
	widget->setFocus(bmx_qt_getfocusreason(reason));
}

void bmx_qt_qwidget_close(QWidget * widget) {
	widget->close();
}


void bmx_qt_qwidget_update(QWidget * widget) {
	widget->update();
}


void bmx_qt_qwidget_raise(QWidget * widget) {
	widget->raise();
}


void bmx_qt_qwidget_repaint(QWidget * widget) {
	widget->repaint();
}


void bmx_qt_qwidget_setdisabled(QWidget * widget, int disable) {
	widget->setDisabled(static_cast<bool>(disable));
}


void bmx_qt_qwidget_setenabled(QWidget * widget, int value) {
	widget->setEnabled(static_cast<bool>(value));
}


void bmx_qt_qwidget_sethidden(QWidget * widget, int hidden) {
	widget->setHidden(static_cast<bool>(hidden));
}


void bmx_qt_qwidget_setstylesheet(QWidget * widget, BBString * styleSheet) {
	widget->setStyleSheet(qStringFromBBString(styleSheet));
}


void bmx_qt_qwidget_setvisible(QWidget * widget, int visible) {
	widget->setVisible(static_cast<bool>(visible));
}


void bmx_qt_qwidget_setwindowmodified(QWidget * widget, int value) {
	widget->setWindowModified(static_cast<bool>(value));
}

void bmx_qt_qwidget_resize(QWidget * widget, int w, int h) {
	widget->resize(w, h);
}

int bmx_qt_qwidget_height(QWidget * widget) {
	return widget->height();
}

int bmx_qt_qwidget_width(QWidget * widget) {
	return widget->width();
}

void bmx_qt_qwidget_addaction(QWidget * widget, QAction * action) {
	widget->addAction(action);
}

void bmx_qt_qwidget_setcontextmenupolicy(QWidget * widget, int p) {
	Qt::ContextMenuPolicy policy;
	
	switch(p) {
		case 0:
			policy = Qt::NoContextMenu;
			break;
		case 1:
			policy = Qt::DefaultContextMenu;
			break;
		case 2:
			policy = Qt::ActionsContextMenu;
			break;
		case 3:
			policy = Qt::CustomContextMenu;
			break;
		case 4:
			policy = Qt::PreventContextMenu;
			break;
	}
	
	widget->setContextMenuPolicy(policy);
}

MaxQRect * bmx_qt_qwidget_framegeometry(QWidget * widget) {
	return new MaxQRect(widget->frameGeometry());
}

void bmx_qt_qwidget_framesize(QWidget * widget, int * w, int * h) {
	QSize s(widget->frameSize());
	*w = s.width();
	*h = s.height();
}

MaxQRect * bmx_qt_qwidget_geometry(QWidget * widget) {
	return new MaxQRect(widget->geometry());
}

void bmx_qt_qwidget_setattribute(QWidget * widget, int attribute) {
	widget->setAttribute(bmx_qt_inttowidgetattribute(attribute));
}

void bmx_qt_qwidget_move(QWidget * widget, int x, int y) {
	widget->move(x, y);
}

void bmx_qt_qwidget_settooltip(QWidget * widget, BBString * text) {
	widget->setToolTip(qStringFromBBString(text));
}

MaxQSizePolicy * bmx_qt_qwidget_sizepolicy(QWidget * widget) {
	return new MaxQSizePolicy(widget->sizePolicy());
}

// *********************************************

QAction * bmx_qt_qaction_create(BBObject * handle, BBString * text, QObject * parent) {
	return new MaxQAction(handle, qStringFromBBString(text), parent);
}

void bmx_qt_qaction_setshortcut(QAction * handle, BBString * sequence) {
	handle->setShortcut(qStringFromBBString(sequence));
}

// *********************************************

Qt::WidgetAttribute bmx_qt_inttowidgetattribute(int a) {
	switch(a) {
		case 0:
			return Qt::WA_Disabled;
		case 1:
			return Qt::WA_UnderMouse;
		case 2:
			return Qt::WA_MouseTracking;
		case 4:
			return Qt::WA_OpaquePaintEvent;
		case 5:
			return Qt::WA_StaticContents;
		case 7:
			return Qt::WA_LaidOut;
		case 8:
			return Qt::WA_PaintOnScreen;
		case 9:
			return Qt::WA_NoSystemBackground;
		case 10:
			return Qt::WA_UpdatesDisabled;
		case 11:
			return Qt::WA_Mapped;
		case 12:
			return Qt::WA_MacNoClickThrough;
		case 13:
			return Qt::WA_PaintOutsidePaintEvent;
		case 14:
			return Qt::WA_InputMethodEnabled;
		case 15:
			return Qt::WA_WState_Visible;
		case 16:
			return Qt::WA_WState_Hidden;
		case 32:
			return Qt::WA_ForceDisabled;
		case 33:
			return Qt::WA_KeyCompression;
		case 34:
			return Qt::WA_PendingMoveEvent;
		case 35:
			return Qt::WA_PendingResizeEvent;
		case 36:
			return Qt::WA_SetPalette;
		case 37:
			return Qt::WA_SetFont;
		case 38:
			return Qt::WA_SetCursor;
		case 39:
			return Qt::WA_NoChildEventsFromChildren;
		case 41:
			return Qt::WA_WindowModified;
		case 42:
			return Qt::WA_Resized;
		case 43:
			return Qt::WA_Moved;
		case 44:
			return Qt::WA_PendingUpdate;
		case 45:
			return Qt::WA_InvalidSize;
		case 46:
			return Qt::WA_MacBrushedMetal;
		case 47:
			return Qt::WA_CustomWhatsThis;
		case 48:
			return Qt::WA_LayoutOnEntireRect;
		case 49:
			return Qt::WA_OutsideWSRange;
		case 50:
			return Qt::WA_GrabbedShortcut;
		case 51:
			return Qt::WA_TransparentForMouseEvents;
		case 52:
			return Qt::WA_PaintUnclipped;
		case 53:
			return Qt::WA_SetWindowIcon;
		case 54:
			return Qt::WA_NoMouseReplay;
		case 55:
			return Qt::WA_DeleteOnClose;
		case 56:
			return Qt::WA_RightToLeft;
		case 57:
			return Qt::WA_SetLayoutDirection;
		case 58:
			return Qt::WA_NoChildEventsForParent;
		case 59:
			return Qt::WA_ForceUpdatesDisabled;
		case 60:
			return Qt::WA_WState_Created;
		case 61:
			return Qt::WA_WState_CompressKeys;
		case 62:
			return Qt::WA_WState_InPaintEvent;
		case 63:
			return Qt::WA_WState_Reparented;
		case 64:
			return Qt::WA_WState_ConfigPending;
		case 66:
			return Qt::WA_WState_Polished;
		case 68:
			return Qt::WA_WState_OwnSizePolicy;
		case 69:
			return Qt::WA_WState_ExplicitShowHide;
		case 71:
			return Qt::WA_MouseNoMask;
		case 73:
			return Qt::WA_NoMousePropagation;
		case 74:
			return Qt::WA_Hover;
		case 75:
			return Qt::WA_InputMethodTransparent;
		case 76:
			return Qt::WA_QuitOnClose;
		case 77:
			return Qt::WA_KeyboardFocusChange;
		case 78:
			return Qt::WA_AcceptDrops;
		case 80:
			return Qt::WA_WindowPropagation;
		case 81:
			return Qt::WA_NoX11EventCompression;
		case 82:
			return Qt::WA_TintedBackground;
		case 83:
			return Qt::WA_X11OpenGLOverlay;
		case 84:
			return Qt::WA_AlwaysShowToolTips;
		case 85:
			return Qt::WA_MacOpaqueSizeGrip;
		case 86:
			return Qt::WA_SetStyle;
		case 87:
			return Qt::WA_SetLocale;
		case 88:
			return Qt::WA_MacShowFocusRect;
		case 89:
			return Qt::WA_MacNormalSize;
		case 90:
			return Qt::WA_MacSmallSize;
		case 91:
			return Qt::WA_MacMiniSize;
		case 92:
			return Qt::WA_LayoutUsesWidgetRect;
		case 93:
			return Qt::WA_StyledBackground;
		case 94:
			return Qt::WA_MSWindowsUseDirect3D;
		case 95:
			return Qt::WA_CanHostQMdiSubWindowTitleBar;
		case 96:
			return Qt::WA_MacAlwaysShowToolWindow;
		case 97:
			return Qt::WA_StyleSheet;
		case 98:
			return Qt::WA_ShowWithoutActivating;
		case 99:
			return Qt::WA_X11BypassTransientForHint;
		case 100:
			return Qt::WA_NativeWindow;
		case 101:
			return Qt::WA_DontCreateNativeAncestors;
		case 102:
			return Qt::WA_MacVariableSize;
		case 103:
			return Qt::WA_DontShowOnScreen;
		case 104:
			return Qt::WA_X11NetWmWindowTypeDesktop;
		case 105:
			return Qt::WA_X11NetWmWindowTypeDock;
		case 106:
			return Qt::WA_X11NetWmWindowTypeToolBar;
		case 107:
			return Qt::WA_X11NetWmWindowTypeMenu;
		case 108:
			return Qt::WA_X11NetWmWindowTypeUtility;
		case 109:
			return Qt::WA_X11NetWmWindowTypeSplash;
		case 110:
			return Qt::WA_X11NetWmWindowTypeDialog;
		case 111:
			return Qt::WA_X11NetWmWindowTypeDropDownMenu;
		case 112:
			return Qt::WA_X11NetWmWindowTypePopupMenu;
		case 113:
			return Qt::WA_X11NetWmWindowTypeToolTip;
		case 114:
			return Qt::WA_X11NetWmWindowTypeNotification;
		case 115:
			return Qt::WA_X11NetWmWindowTypeCombo;
		case 116:
			return Qt::WA_X11NetWmWindowTypeDND;
		case 117:
			return Qt::WA_MacFrameworkScaled;
		case 118:
			return Qt::WA_SetWindowModality;
		case 119:
			return Qt::WA_WState_WindowOpacitySet;
		case 120:
			return Qt::WA_TranslucentBackground;
	}
	
	return Qt::WA_Disabled;
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
