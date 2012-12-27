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

	connect(this, SIGNAL(iconSizeChanged(const QSize & )), SLOT(onIconSizeChanged(const QSize & )));
	connect(this, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle )), SLOT(onToolButtonStyleChanged(Qt::ToolButtonStyle )));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint & )), SLOT(onCustomContextMenuRequested(const QPoint & )));
}

MaxQMainWindow::~MaxQMainWindow()
{
	qunbind(this);
}

void MaxQMainWindow::onIconSizeChanged(const QSize & iconSize) {
	_qt_qmainwindow_QMainWindow__OnIconSizeChanged(maxHandle, iconSize.width(), iconSize.height());
}

void MaxQMainWindow::onToolButtonStyleChanged(Qt::ToolButtonStyle toolButtonStyle) {
	_qt_qmainwindow_QMainWindow__OnToolButtonStyleChanged(maxHandle, toolButtonStyle);
}

void MaxQMainWindow::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}


// ****************** DEFAULT HANDLERS ********************

// QWidget
void MaxQMainWindow::defaultactionEvent(QActionEvent * event){
	QMainWindow::actionEvent(event);
}

void MaxQMainWindow::defaultchangeEvent(QEvent * event){
	QMainWindow::changeEvent(event);
}

void MaxQMainWindow::defaultcloseEvent(QCloseEvent * event){
	QMainWindow::closeEvent(event);
}

void MaxQMainWindow::defaultcontextMenuEvent(QContextMenuEvent * event){
	QMainWindow::contextMenuEvent(event);
}

void MaxQMainWindow::defaultdragEnterEvent(QDragEnterEvent * event){
	QMainWindow::dragEnterEvent(event);
}

void MaxQMainWindow::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QMainWindow::dragLeaveEvent(event);
}

void MaxQMainWindow::defaultdragMoveEvent(QDragMoveEvent * event){
	QMainWindow::dragMoveEvent(event);
}

void MaxQMainWindow::defaultdropEvent(QDropEvent * event){
	QMainWindow::dropEvent(event);
}

void MaxQMainWindow::defaultenterEvent(QEvent * event){
	QMainWindow::enterEvent(event);
}

void MaxQMainWindow::defaultfocusInEvent(QFocusEvent * event){
	QMainWindow::focusInEvent(event);
}

bool MaxQMainWindow::defaultfocusNextChild() {
	return QMainWindow::focusNextChild();
}

bool MaxQMainWindow::defaultfocusNextPrevChild(bool next){
	return QMainWindow::focusNextPrevChild(next);
}

void MaxQMainWindow::defaultfocusOutEvent(QFocusEvent * event){
	QMainWindow::focusOutEvent(event);
}

bool MaxQMainWindow::defaultfocusPreviousChild() {
	return QMainWindow::focusPreviousChild();
}

void MaxQMainWindow::defaulthideEvent(QHideEvent * event){
	QMainWindow::hideEvent(event);
}

void MaxQMainWindow::defaultinputMethodEvent(QInputMethodEvent * event){
	QMainWindow::inputMethodEvent(event);
}

void MaxQMainWindow::defaultkeyPressEvent(QKeyEvent * event){
	QMainWindow::keyPressEvent(event);
}

void MaxQMainWindow::defaultkeyReleaseEvent(QKeyEvent * event){
	QMainWindow::keyReleaseEvent(event);
}

void MaxQMainWindow::defaultleaveEvent(QEvent * event){
	QMainWindow::leaveEvent(event);
}

void MaxQMainWindow::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QMainWindow::mouseDoubleClickEvent(event);
}

void MaxQMainWindow::defaultmouseMoveEvent(QMouseEvent * event){
	QMainWindow::mouseMoveEvent(event);
}

void MaxQMainWindow::defaultmousePressEvent(QMouseEvent * event){
	QMainWindow::mousePressEvent(event);
}

void MaxQMainWindow::defaultmouseReleaseEvent(QMouseEvent * event){
	QMainWindow::mouseReleaseEvent(event);
}

void MaxQMainWindow::defaultmoveEvent(QMoveEvent * event){
	QMainWindow::moveEvent(event);
}

void MaxQMainWindow::defaultpaintEvent(QPaintEvent * event){
	QMainWindow::paintEvent(event);
}

void MaxQMainWindow::defaultresizeEvent(QResizeEvent * event){
	QMainWindow::resizeEvent(event);
}

void MaxQMainWindow::defaultshowEvent(QShowEvent * event){
	QMainWindow::showEvent(event);
}

void MaxQMainWindow::defaulttabletEvent(QTabletEvent * event){
	QMainWindow::tabletEvent(event);
}

void MaxQMainWindow::defaultwheelEvent(QWheelEvent * event){
	QMainWindow::wheelEvent(event);
}

// QObject
bool MaxQMainWindow::defaultevent(QEvent * event){
	return QMainWindow::event(event);
}

void MaxQMainWindow::defaulttimerEvent(QTimerEvent * event){
	QMainWindow::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QWidget
void MaxQMainWindow::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQMainWindow::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQMainWindow::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQMainWindow::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQMainWindow::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQMainWindow::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQMainWindow::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQMainWindow::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQMainWindow::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQMainWindow::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQMainWindow::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQMainWindow::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQMainWindow::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQMainWindow::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQMainWindow::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQMainWindow::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQMainWindow::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQMainWindow::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQMainWindow::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQMainWindow::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQMainWindow::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQMainWindow::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQMainWindow::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQMainWindow::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQMainWindow::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQMainWindow::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQMainWindow::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQMainWindow::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQMainWindow::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQMainWindow::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQMainWindow::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QWidget
void bmx_qt_qmainwindow_default_actionevent(MaxQMainWindow * window, QActionEvent * event) {
	window->defaultactionEvent(event);
}

void bmx_qt_qmainwindow_default_changeevent(MaxQMainWindow * window, QEvent * event) {
	window->defaultchangeEvent(event);
}

void bmx_qt_qmainwindow_default_closeevent(MaxQMainWindow * window, QCloseEvent * event) {
	window->defaultcloseEvent(event);
}

void bmx_qt_qmainwindow_default_contextmenuevent(MaxQMainWindow * window, QContextMenuEvent * event) {
	window->defaultcontextMenuEvent(event);
}

void bmx_qt_qmainwindow_default_dragenterevent(MaxQMainWindow * window, QDragEnterEvent * event) {
	window->defaultdragEnterEvent(event);
}

void bmx_qt_qmainwindow_default_dragleaveevent(MaxQMainWindow * window, QDragLeaveEvent * event) {
	window->defaultdragLeaveEvent(event);
}

void bmx_qt_qmainwindow_default_dragmoveevent(MaxQMainWindow * window, QDragMoveEvent * event) {
	window->defaultdragMoveEvent(event);
}

void bmx_qt_qmainwindow_default_dropevent(MaxQMainWindow * window, QDropEvent * event) {
	window->defaultdropEvent(event);
}

void bmx_qt_qmainwindow_default_enterevent(MaxQMainWindow * window, QEvent * event) {
	window->defaultenterEvent(event);
}

void bmx_qt_qmainwindow_default_focusinevent(MaxQMainWindow * window, QFocusEvent * event) {
	window->defaultfocusInEvent(event);
}

int bmx_qt_qmainwindow_default_focusnextprevchild(MaxQMainWindow * window, int next) {
	return static_cast<int>(window->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qmainwindow_default_focusnextchild(MaxQMainWindow * window) {
	return static_cast<int>(window->defaultfocusNextChild());
}

void bmx_qt_qmainwindow_default_focusoutevent(MaxQMainWindow * window, QFocusEvent * event) {
	window->defaultfocusOutEvent(event);
}

int bmx_qt_qmainwindow_default_focuspreviouschild(MaxQMainWindow * window) {
	return static_cast<int>(window->defaultfocusPreviousChild());
}

void bmx_qt_qmainwindow_default_hideevent(MaxQMainWindow * window, QHideEvent * event) {
	window->defaulthideEvent(event);
}

void bmx_qt_qmainwindow_default_inputmethodevent(MaxQMainWindow * window, QInputMethodEvent * event) {
	window->defaultinputMethodEvent(event);
}

void bmx_qt_qmainwindow_default_keypressevent(MaxQMainWindow * window, QKeyEvent * event) {
	window->defaultkeyPressEvent(event);
}

void bmx_qt_qmainwindow_default_keyreleaseevent(MaxQMainWindow * window, QKeyEvent * event) {
	window->defaultkeyReleaseEvent(event);
}

void bmx_qt_qmainwindow_default_leaveevent(MaxQMainWindow * window, QEvent * event) {
	window->defaultleaveEvent(event);
}

void bmx_qt_qmainwindow_default_mousedoubleclickevent(MaxQMainWindow * window, QMouseEvent * event) {
	window->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qmainwindow_default_mousemoveevent(MaxQMainWindow * window, QMouseEvent * event) {
	window->defaultmouseMoveEvent(event);
}

void bmx_qt_qmainwindow_default_mousepressevent(MaxQMainWindow * window, QMouseEvent * event) {
	window->defaultmousePressEvent(event);
}

void bmx_qt_qmainwindow_default_mousereleaseevent(MaxQMainWindow * window, QMouseEvent * event) {
	window->defaultmouseReleaseEvent(event);
}

void bmx_qt_qmainwindow_default_moveevent(MaxQMainWindow * window, QMoveEvent * event) {
	window->defaultmoveEvent(event);
}

void bmx_qt_qmainwindow_default_paintevent(MaxQMainWindow * window, QPaintEvent * event) {
	window->defaultpaintEvent(event);
}

void bmx_qt_qmainwindow_default_resizeevent(MaxQMainWindow * window, QResizeEvent * event) {
	window->defaultresizeEvent(event);
}

void bmx_qt_qmainwindow_default_showevent(MaxQMainWindow * window, QShowEvent * event) {
	window->defaultshowEvent(event);
}

void bmx_qt_qmainwindow_default_tabletevent(MaxQMainWindow * window, QTabletEvent * event) {
	window->defaulttabletEvent(event);
}

void bmx_qt_qmainwindow_default_wheelevent(MaxQMainWindow * window, QWheelEvent * event) {
	window->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qmainwindow_default_event(MaxQMainWindow * window, QEvent * event) {
	return static_cast<int>(window->defaultevent(event));
}

void bmx_qt_qmainwindow_default_timerevent(MaxQMainWindow * window, QTimerEvent * event) {
	window->defaulttimerEvent(event);
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
	QToolBar *toolBar = window->addToolBar(qStringFromBBString(title));
	MaxQToolBar::link(toolBar);
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

