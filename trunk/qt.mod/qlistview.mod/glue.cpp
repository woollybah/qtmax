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

MaxQListView::MaxQListView(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QListView(parent)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(indexesMoved(const QModelIndexList &)), SLOT(onIndexesMoved(const QModelIndexList &)));
	connect(this, SIGNAL(activated(const QModelIndex &)), SLOT(onActivated(const QModelIndex &)));
	connect(this, SIGNAL(clicked(const QModelIndex &)), SLOT(onClicked(const QModelIndex &)));
	connect(this, SIGNAL(doubleClicked(const QModelIndex &)), SLOT(onDoubleClicked(const QModelIndex &)));
	connect(this, SIGNAL(entered(const QModelIndex &)), SLOT(onEntered(const QModelIndex &)));
	connect(this, SIGNAL(pressed(const QModelIndex &)), SLOT(onPressed(const QModelIndex &)));
	connect(this, SIGNAL(viewportEntered()), SLOT(onViewportEntered()));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQListView::~MaxQListView()
{
	qunbind(this);
}

void MaxQListView::onIndexesMoved(const QModelIndexList & indexes) {

}

void MaxQListView::onActivated(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnActivated(maxHandle, new MaxQModelIndex(index));
}

void MaxQListView::onClicked(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnClicked(maxHandle, new MaxQModelIndex(index));
}

void MaxQListView::onDoubleClicked(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnDoubleClicked(maxHandle, new MaxQModelIndex(index));
}

void MaxQListView::onEntered(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnEntered(maxHandle, new MaxQModelIndex(index));
}

void MaxQListView::onPressed(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnPressed(maxHandle, new MaxQModelIndex(index));
}

void MaxQListView::onViewportEntered() {
	_qt_qabstractitemview_QAbstractItemView__OnViewportEntered(maxHandle);
}

void MaxQListView::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}


// ****************** DEFAULT HANDLERS ********************

// QListView
// QAbstractItemView
// QAbstractScrollArea
void MaxQListView::defaultscrollContentsBy(int dx, int dy){
	QListView::scrollContentsBy(dx, dy);
}

bool MaxQListView::defaultviewportEvent(QEvent * event){
	return QListView::viewportEvent(event);
}

// QFrame
// QWidget
void MaxQListView::defaultactionEvent(QActionEvent * event){
	QListView::actionEvent(event);
}

void MaxQListView::defaultchangeEvent(QEvent * event){
	QListView::changeEvent(event);
}

void MaxQListView::defaultcloseEvent(QCloseEvent * event){
	QListView::closeEvent(event);
}

void MaxQListView::defaultcontextMenuEvent(QContextMenuEvent * event){
	QListView::contextMenuEvent(event);
}

void MaxQListView::defaultdragEnterEvent(QDragEnterEvent * event){
	QListView::dragEnterEvent(event);
}

void MaxQListView::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QListView::dragLeaveEvent(event);
}

void MaxQListView::defaultdragMoveEvent(QDragMoveEvent * event){
	QListView::dragMoveEvent(event);
}

void MaxQListView::defaultdropEvent(QDropEvent * event){
	QListView::dropEvent(event);
}

void MaxQListView::defaultenterEvent(QEvent * event){
	QListView::enterEvent(event);
}

void MaxQListView::defaultfocusInEvent(QFocusEvent * event){
	QListView::focusInEvent(event);
}

bool MaxQListView::defaultfocusNextChild() {
	return QListView::focusNextChild();
}

bool MaxQListView::defaultfocusNextPrevChild(bool next){
	return QListView::focusNextPrevChild(next);
}

void MaxQListView::defaultfocusOutEvent(QFocusEvent * event){
	QListView::focusOutEvent(event);
}

bool MaxQListView::defaultfocusPreviousChild() {
	return QListView::focusPreviousChild();
}

void MaxQListView::defaulthideEvent(QHideEvent * event){
	QListView::hideEvent(event);
}

void MaxQListView::defaultinputMethodEvent(QInputMethodEvent * event){
	QListView::inputMethodEvent(event);
}

void MaxQListView::defaultkeyPressEvent(QKeyEvent * event){
	QListView::keyPressEvent(event);
}

void MaxQListView::defaultkeyReleaseEvent(QKeyEvent * event){
	QListView::keyReleaseEvent(event);
}

void MaxQListView::defaultleaveEvent(QEvent * event){
	QListView::leaveEvent(event);
}

void MaxQListView::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QListView::mouseDoubleClickEvent(event);
}

void MaxQListView::defaultmouseMoveEvent(QMouseEvent * event){
	QListView::mouseMoveEvent(event);
}

void MaxQListView::defaultmousePressEvent(QMouseEvent * event){
	QListView::mousePressEvent(event);
}

void MaxQListView::defaultmouseReleaseEvent(QMouseEvent * event){
	QListView::mouseReleaseEvent(event);
}

void MaxQListView::defaultmoveEvent(QMoveEvent * event){
	QListView::moveEvent(event);
}

void MaxQListView::defaultpaintEvent(QPaintEvent * event){
	QListView::paintEvent(event);
}

void MaxQListView::defaultresizeEvent(QResizeEvent * event){
	QListView::resizeEvent(event);
}

void MaxQListView::defaultshowEvent(QShowEvent * event){
	QListView::showEvent(event);
}

void MaxQListView::defaulttabletEvent(QTabletEvent * event){
	QListView::tabletEvent(event);
}

void MaxQListView::defaultwheelEvent(QWheelEvent * event){
	QListView::wheelEvent(event);
}

// QObject
bool MaxQListView::defaultevent(QEvent * event){
	return QListView::event(event);
}

void MaxQListView::defaulttimerEvent(QTimerEvent * event){
	QListView::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QListView
// QAbstractItemView
// QAbstractScrollArea
void MaxQListView::scrollContentsBy(int dx, int dy) {
	_qt_qabstractscrollarea_QAbstractScrollArea__scrollContentsBy(maxHandle, dx, dy);
}

bool MaxQListView::viewportEvent(QEvent * event) {
	return static_cast<bool>(_qt_qabstractscrollarea_QAbstractScrollArea__viewportEvent(maxHandle, event));
}
// QFrame
// QWidget
void MaxQListView::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQListView::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQListView::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQListView::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQListView::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQListView::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQListView::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQListView::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQListView::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQListView::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQListView::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQListView::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQListView::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQListView::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQListView::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQListView::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQListView::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQListView::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQListView::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQListView::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQListView::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQListView::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQListView::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQListView::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQListView::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQListView::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQListView::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQListView::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQListView::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQListView::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQListView::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QListView
// QAbstractItemView
// QAbstractScrollArea
void bmx_qt_qlistview_default_scrollcontentsby(MaxQListView * view, int dx, int dy) {
	view->defaultscrollContentsBy(dx, dy);
}

int bmx_qt_qlistview_default_viewportevent(MaxQListView * view, QEvent * event) {
	static_cast<int>(view->defaultviewportEvent(event));
}

// QFrame
// QWidget
void bmx_qt_qlistview_default_actionevent(MaxQListView * view, QActionEvent * event) {
	view->defaultactionEvent(event);
}

void bmx_qt_qlistview_default_changeevent(MaxQListView * view, QEvent * event) {
	view->defaultchangeEvent(event);
}

void bmx_qt_qlistview_default_closeevent(MaxQListView * view, QCloseEvent * event) {
	view->defaultcloseEvent(event);
}

void bmx_qt_qlistview_default_contextmenuevent(MaxQListView * view, QContextMenuEvent * event) {
	view->defaultcontextMenuEvent(event);
}

void bmx_qt_qlistview_default_dragenterevent(MaxQListView * view, QDragEnterEvent * event) {
	view->defaultdragEnterEvent(event);
}

void bmx_qt_qlistview_default_dragleaveevent(MaxQListView * view, QDragLeaveEvent * event) {
	view->defaultdragLeaveEvent(event);
}

void bmx_qt_qlistview_default_dragmoveevent(MaxQListView * view, QDragMoveEvent * event) {
	view->defaultdragMoveEvent(event);
}

void bmx_qt_qlistview_default_dropevent(MaxQListView * view, QDropEvent * event) {
	view->defaultdropEvent(event);
}

void bmx_qt_qlistview_default_enterevent(MaxQListView * view, QEvent * event) {
	view->defaultenterEvent(event);
}

void bmx_qt_qlistview_default_focusinevent(MaxQListView * view, QFocusEvent * event) {
	view->defaultfocusInEvent(event);
}

int bmx_qt_qlistview_default_focusnextprevchild(MaxQListView * view, int next) {
	return static_cast<int>(view->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qlistview_default_focusnextchild(MaxQListView * view) {
	return static_cast<int>(view->defaultfocusNextChild());
}

void bmx_qt_qlistview_default_focusoutevent(MaxQListView * view, QFocusEvent * event) {
	view->defaultfocusOutEvent(event);
}

int bmx_qt_qlistview_default_focuspreviouschild(MaxQListView * view) {
	return static_cast<int>(view->defaultfocusPreviousChild());
}

void bmx_qt_qlistview_default_hideevent(MaxQListView * view, QHideEvent * event) {
	view->defaulthideEvent(event);
}

void bmx_qt_qlistview_default_inputmethodevent(MaxQListView * view, QInputMethodEvent * event) {
	view->defaultinputMethodEvent(event);
}

void bmx_qt_qlistview_default_keypressevent(MaxQListView * view, QKeyEvent * event) {
	view->defaultkeyPressEvent(event);
}

void bmx_qt_qlistview_default_keyreleaseevent(MaxQListView * view, QKeyEvent * event) {
	view->defaultkeyReleaseEvent(event);
}

void bmx_qt_qlistview_default_leaveevent(MaxQListView * view, QEvent * event) {
	view->defaultleaveEvent(event);
}

void bmx_qt_qlistview_default_mousedoubleclickevent(MaxQListView * view, QMouseEvent * event) {
	view->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qlistview_default_mousemoveevent(MaxQListView * view, QMouseEvent * event) {
	view->defaultmouseMoveEvent(event);
}

void bmx_qt_qlistview_default_mousepressevent(MaxQListView * view, QMouseEvent * event) {
	view->defaultmousePressEvent(event);
}

void bmx_qt_qlistview_default_mousereleaseevent(MaxQListView * view, QMouseEvent * event) {
	view->defaultmouseReleaseEvent(event);
}

void bmx_qt_qlistview_default_moveevent(MaxQListView * view, QMoveEvent * event) {
	view->defaultmoveEvent(event);
}

void bmx_qt_qlistview_default_paintevent(MaxQListView * view, QPaintEvent * event) {
	view->defaultpaintEvent(event);
}

void bmx_qt_qlistview_default_resizeevent(MaxQListView * view, QResizeEvent * event) {
	view->defaultresizeEvent(event);
}

void bmx_qt_qlistview_default_showevent(MaxQListView * view, QShowEvent * event) {
	view->defaultshowEvent(event);
}

void bmx_qt_qlistview_default_tabletevent(MaxQListView * view, QTabletEvent * event) {
	view->defaulttabletEvent(event);
}

void bmx_qt_qlistview_default_wheelevent(MaxQListView * view, QWheelEvent * event) {
	view->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qlistview_default_event(MaxQListView * view, QEvent * event) {
	return static_cast<int>(view->defaultevent(event));
}

void bmx_qt_qlistview_default_timerevent(MaxQListView * view, QTimerEvent * event) {
	view->defaulttimerEvent(event);
}

// *********************************************

QListView * bmx_qt_qlistview_create(BBObject * handle, QWidget * parent) {
	return new MaxQListView(handle, parent);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
