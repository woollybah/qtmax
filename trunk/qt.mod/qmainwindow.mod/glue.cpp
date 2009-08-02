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

MaxQMainWindow::MaxQMainWindow(BBObject * handle, QWidget * parent, Qt::WindowFlags flags)
	: maxHandle(handle), QMainWindow(parent, flags)
{
	qbind(this, handle);
}

MaxQMainWindow::~MaxQMainWindow()
{
	qunbind(this);
}


// *********************************************

QMainWindow * bmx_qt_qmainwindow_create(BBObject * handle, QWidget * parent, int flags) {
	return new MaxQMainWindow(handle, parent, bmx_qt_getwindowflags(flags));
}

void bmx_qt_qmainwindow_adddockwidget(QMainWindow * window, int area, QDockWidget * dockwidget, int orientation) {
	window->addDockWidget((Qt::DockWidgetArea)area, dockwidget, (Qt::Orientation)orientation);
}

void bmx_qt_qmainwindow_addtoolbararea(QMainWindow * window, int area, QToolBar * toolbar) {
	window->addToolBar((Qt::ToolBarArea)area, toolbar);
}

QToolBar * bmx_qt_qmainwindow_addtoolbar(QMainWindow * window, QToolBar * toolbar) {
	window->addToolBar(toolbar);
	return toolbar;
}

QToolBar * bmx_qt_qmainwindow_addtoolbartxt(QMainWindow * window, BBString * title) {
	QToolBar *toolBar = new MaxQToolBar(window);
	toolBar->setWindowTitle(qStringFromBBString(title));
	window->addToolBar(toolBar);
	return toolBar;
}

void bmx_qt_qmainwindow_addtoolbarbreak(QMainWindow * window, int area) {
	window->addToolBarBreak((Qt::ToolBarArea)area);
}

QWidget * bmx_qt_qmainwindow_centralwidget(QMainWindow * window) {
	return window->centralWidget();
}

int bmx_qt_qmainwindow_corner(QMainWindow * window, int c) {
	return window->corner((Qt::Corner)c);
}

QMenu * bmx_qt_qmainwindow_createpopupmenu(QMainWindow * window) {
	return window->createPopupMenu();
}

int bmx_qt_qmainwindow_dockoptions(QMainWindow * window) {
	return window->dockOptions();
}

int bmx_qt_qmainwindow_dockwidgetarea(QMainWindow * window, QDockWidget * dockwidget) {
	return window->dockWidgetArea(dockwidget);
}

int bmx_qt_qmainwindow_documentmode(QMainWindow * window) {
	return static_cast<int>(window->documentMode());
}

void bmx_qt_qmainwindow_iconsize(QMainWindow * window, int * w, int * h) {
	QSize s(window->iconSize());
	*w = s.width();
	*h = s.height();
}

void bmx_qt_qmainwindow_inserttoolbar(QMainWindow * window, QToolBar * before, QToolBar * toolbar) {
	window->insertToolBar(before, toolbar);
}

void bmx_qt_qmainwindow_inserttoolbarbreak(QMainWindow * window, QToolBar * before) {
	window->insertToolBarBreak(before);
}

int bmx_qt_qmainwindow_isanimated(QMainWindow * window) {
	return static_cast<int>(window->isAnimated());
}

int bmx_qt_qmainwindow_isdocknestingenabled(QMainWindow * window) {
	return static_cast<int>(window->isDockNestingEnabled());
}

QMenuBar * bmx_qt_qmainwindow_menubar(QMainWindow * window) {
	return window->menuBar();
}

QWidget * bmx_qt_qmainwindow_menuwidget(QMainWindow * window) {
	return window->menuWidget();
}

void bmx_qt_qmainwindow_removedockwidget(QMainWindow * window, QDockWidget * dockwidget) {
	window->removeDockWidget(dockwidget);
}

void bmx_qt_qmainwindow_removetoolbar(QMainWindow * window, QToolBar * toolbar) {
	window->removeToolBar(toolbar);
}

void bmx_qt_qmainwindow_removetoolbarbreak(QMainWindow * window, QToolBar * before) {
	window->removeToolBarBreak(before);
}

void bmx_qt_qmainwindow_restoredockwidget(QMainWindow * window, QDockWidget * dockwidget) {
	window->restoreDockWidget(dockwidget);
}

void bmx_qt_qmainwindow_setcentralwidget(QMainWindow * window, QWidget * widget) {
	window->setCentralWidget(widget);
}

void bmx_qt_qmainwindow_setcorner(QMainWindow * window, int corner, int area) {
	window->setCorner((Qt::Corner)corner, (Qt::DockWidgetArea)area);
}

void bmx_qt_qmainwindow_setdockoptions(QMainWindow * window, int options) {
	window->setDockOptions((QMainWindow::DockOptions)options);
}

void bmx_qt_qmainwindow_setdocumentmode(QMainWindow * window, int enabled) {
	window->setDocumentMode(static_cast<bool>(enabled));
}

void bmx_qt_qmainwindow_seticonsize(QMainWindow * window, int w, int h) {
	window->setIconSize(QSize(w, h));
}

void bmx_qt_qmainwindow_setmenubar(QMainWindow * window, QMenuBar * menuBar) {
	window->setMenuBar(menuBar);
}

void bmx_qt_qmainwindow_setmenuwidget(QMainWindow * window, QWidget * widget) {
	window->setMenuWidget(widget);
}

void bmx_qt_qmainwindow_setstatusbar(QMainWindow * window, QStatusBar * statusbar) {
	window->setStatusBar(statusbar);
}

void bmx_qt_qmainwindow_settabposition(QMainWindow * window, int areas, int tabPosition) {
	window->setTabPosition((Qt::DockWidgetAreas)areas, (QTabWidget::TabPosition)tabPosition);
}

void bmx_qt_qmainwindow_settabshape(QMainWindow * window, int tabShape) {
	window->setTabShape((QTabWidget::TabShape)tabShape);
}

void bmx_qt_qmainwindow_settoolbuttonstyle(QMainWindow * window, int toolButtonStyle) {
	window->setToolButtonStyle((Qt::ToolButtonStyle)toolButtonStyle);
}

void bmx_qt_qmainwindow_setunifiedtitleandtoolbaronmac(QMainWindow * window, int set) {
	window->setUnifiedTitleAndToolBarOnMac(static_cast<bool>(set));
}

void bmx_qt_qmainwindow_splitdockwidget(QMainWindow * window, QDockWidget * _first, QDockWidget * _second, int orientation) {
	window->splitDockWidget(_first, _second, (Qt::Orientation )orientation);
}

QStatusBar * bmx_qt_qmainwindow_statusBar(QMainWindow * window) {
	return window->statusBar();
}

int bmx_qt_qmainwindow_tabposition(QMainWindow * window, int area) {
	return window->tabPosition((Qt::DockWidgetArea )area);
}

int bmx_qt_qmainwindow_tabshape(QMainWindow * window) {
	return window->tabShape();
}

void bmx_qt_qmainwindow_tabifydockwidget(QMainWindow * window, QDockWidget * _first, QDockWidget * _second) {
	window->tabifyDockWidget(_first, _second);
}

int bmx_qt_qmainwindow_toolbararea(QMainWindow * window, QToolBar * toolbar) {
	return window->toolBarArea(toolbar);
}

int bmx_qt_qmainwindow_toolbarbreak(QMainWindow * window, QToolBar * toolbar) {
	return static_cast<int>(window->toolBarBreak(toolbar));
}

int bmx_qt_qmainwindow_toolbuttonstyle(QMainWindow * window) {
	return window->toolButtonStyle();
}

int bmx_qt_qmainwindow_unifiedtitleandtoolbaronmac(QMainWindow * window) {
	return static_cast<int>(window->unifiedTitleAndToolBarOnMac());
}

void bmx_qt_qmainwindow_setanimated(QMainWindow * window, int enabled) {
	window->setAnimated(static_cast<bool>(enabled));
}

void bmx_qt_qmainwindow_setdocknestingenabled(QMainWindow * window, int enabled) {
	window->setDockNestingEnabled(static_cast<bool>(enabled));
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

