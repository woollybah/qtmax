/*
  Copyright (c) 2009-2013 Bruce A Henderson
 
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

MaxQToolBar::MaxQToolBar(BBObject * handle, QToolBar * tb)
	: toolBar(tb), MaxQObjectWrapper(handle, tb)
{
	doConnections();
}

MaxQToolBar::MaxQToolBar(QToolBar * tb)
	: toolBar(tb), MaxQObjectWrapper(tb)
{
	maxHandle = _qt_qtoolbar_QToolBar___create(tb);
	qbind(tb, maxHandle);

	doConnections();
}

MaxQToolBar::~MaxQToolBar()
{
}

void MaxQToolBar::doConnections() {
	connect(toolBar, SIGNAL(actionTriggered(QAction *)), SLOT(onActionTriggered(QAction *)));
	connect(toolBar, SIGNAL(allowedAreasChanged(Qt::ToolBarAreas)), SLOT(onAllowedAreasChanged(Qt::ToolBarAreas)));
	connect(toolBar, SIGNAL(iconSizeChanged(const QSize &)), SLOT(onIconSizeChanged(const QSize &)));
	connect(toolBar, SIGNAL(movableChanged(bool)), SLOT(onMovableChanged(bool)));
	connect(toolBar, SIGNAL(orientationChanged(Qt::Orientation)), SLOT(onOrientationChanged(Qt::Orientation)));
	connect(toolBar, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), SLOT(onToolButtonStyleChanged(Qt::ToolButtonStyle)));
	connect(toolBar, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

QToolBar * MaxQToolBar::ToolBar() {
	return toolBar;
}

void MaxQToolBar::link(QToolBar * tb) {
	BBObject * handle = qfind(tb);
	
	if (handle == &bbNullObject) {
		MaxQToolBar * toolbar = new MaxQToolBar(tb);
	}
}


void MaxQToolBar::onActionTriggered(QAction * action) {
	_qt_qtoolbar_QToolBar__OnActionTriggered(maxHandle, action);
}

void MaxQToolBar::onAllowedAreasChanged(Qt::ToolBarAreas allowedAreas) {
	_qt_qtoolbar_QToolBar__OnAllowedAreasChanged(maxHandle, static_cast<int>(allowedAreas));
}

void MaxQToolBar::onIconSizeChanged(const QSize & iconSize) {
	_qt_qtoolbar_QToolBar__OnIconSizeChanged(maxHandle, iconSize.width(), iconSize.height());
}

void MaxQToolBar::onMovableChanged(bool movable) {
	_qt_qtoolbar_QToolBar__OnMovableChanged(maxHandle, static_cast<int>(movable));
}

void MaxQToolBar::onOrientationChanged(Qt::Orientation orientation) {
	_qt_qtoolbar_QToolBar__OnOrientationChanged(maxHandle, static_cast<int>(orientation));
}

void MaxQToolBar::onToolButtonStyleChanged(Qt::ToolButtonStyle toolButtonStyle) {
	_qt_qtoolbar_QToolBar__OnToolButtonStyleChanged(maxHandle, static_cast<int>(toolButtonStyle));
}

void MaxQToolBar::onTopLevelChanged(bool topLevel) {
	_qt_qtoolbar_QToolBar__OnTopLevelChanged(maxHandle, static_cast<int>(topLevel));
}

void MaxQToolBar::onVisibilityChanged(bool visible) {
	_qt_qtoolbar_QToolBar__OnVisibilityChanged(maxHandle, static_cast<int>(visible));
}

void MaxQToolBar::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}


// *********************************************

QToolBar * bmx_qt_qtoolbar_create(BBObject * handle, QWidget * parent) {
	MaxQToolBar * tb = new MaxQToolBar(handle, new QToolBar(parent));
	return tb->ToolBar();
}

void bmx_qt_qtoolbar_addwidget(QToolBar * tb, QWidget * widget) {
	tb->addWidget(widget);
}

int bmx_qt_qtoolbar_allowedareas(QToolBar * tb) {
	return static_cast<int>(tb->allowedAreas());
}

void bmx_qt_qtoolbar_clear(QToolBar * tb) {
	tb->clear();
}

void bmx_qt_qtoolbar_iconsize(QToolBar * tb, int * w, int * h) {
	QSize s(tb->iconSize());
	*w = s.width();
	*h = s.height();
}

int bmx_qt_qtoolbar_isareaallowed(QToolBar * tb, int area) {
	return static_cast<int>(tb->isAreaAllowed((Qt::ToolBarArea)area));
}

int bmx_qt_qtoolbar_isfloatable(QToolBar * tb) {
	return static_cast<int>(tb->isFloatable());
}

int bmx_qt_qtoolbar_isfloating(QToolBar * tb) {
	return static_cast<int>(tb->isFloating());
}

int bmx_qt_qtoolbar_ismovable(QToolBar * tb) {
	return static_cast<int>(tb->isMovable());
}

int bmx_qt_qtoolbar_orientation(QToolBar * tb) {
	return static_cast<int>(tb->orientation());
}

void bmx_qt_qtoolbar_setallowedareas(QToolBar * tb, int areas) {
	tb->setAllowedAreas(bmx_qt_inttotoolbarareas(areas));
}

void bmx_qt_qtoolbar_setfloatable(QToolBar * tb, int floatable) {
	tb->setFloatable(static_cast<bool>(floatable));
}

void bmx_qt_qtoolbar_setmovable(QToolBar * tb, int movable) {
	tb->setMovable(static_cast<bool>(movable));
}

void bmx_qt_qtoolbar_setorientation(QToolBar * tb, int orientation) {
	tb->setOrientation(bmx_qt_getorientation(orientation));
}

int bmx_qt_qtoolbar_toolbuttonstyle(QToolBar * tb) {
	static_cast<int>(tb->toolButtonStyle());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
