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

MaxQAbstractItemView::MaxQAbstractItemView(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QAbstractItemView(parent)
{
	qbind(this, handle);
}

MaxQAbstractItemView::~MaxQAbstractItemView()
{
	qunbind(this);
}

void MaxQAbstractItemView::onActivated(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnActivated(maxHandle, new MaxQModelIndex(index));
}

void MaxQAbstractItemView::onClicked(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnClicked(maxHandle, new MaxQModelIndex(index));
}

void MaxQAbstractItemView::onDoubleClicked(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnDoubleClicked(maxHandle, new MaxQModelIndex(index));
}

void MaxQAbstractItemView::onEntered(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnEntered(maxHandle, new MaxQModelIndex(index));
}

void MaxQAbstractItemView::onPressed(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnPressed(maxHandle, new MaxQModelIndex(index));
}

void MaxQAbstractItemView::onViewportEntered() {
	_qt_qabstractitemview_QAbstractItemView__OnViewportEntered(maxHandle);
}

void MaxQAbstractItemView::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

// ****************** DEFAULT HANDLERS ********************

// QAbstractItemView
// QAbstractScrollArea
void MaxQAbstractItemView::defaultscrollContentsBy(int dx, int dy){
	QAbstractItemView::scrollContentsBy(dx, dy);
}

bool MaxQAbstractItemView::defaultviewportEvent(QEvent * event){
	return QAbstractItemView::viewportEvent(event);
}

// QFrame
// QWidget
void MaxQAbstractItemView::defaultactionEvent(QActionEvent * event){
	QAbstractItemView::actionEvent(event);
}

void MaxQAbstractItemView::defaultchangeEvent(QEvent * event){
	QAbstractItemView::changeEvent(event);
}

void MaxQAbstractItemView::defaultcloseEvent(QCloseEvent * event){
	QAbstractItemView::closeEvent(event);
}

void MaxQAbstractItemView::defaultcontextMenuEvent(QContextMenuEvent * event){
	QAbstractItemView::contextMenuEvent(event);
}

void MaxQAbstractItemView::defaultdragEnterEvent(QDragEnterEvent * event){
	QAbstractItemView::dragEnterEvent(event);
}

void MaxQAbstractItemView::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QAbstractItemView::dragLeaveEvent(event);
}

void MaxQAbstractItemView::defaultdragMoveEvent(QDragMoveEvent * event){
	QAbstractItemView::dragMoveEvent(event);
}

void MaxQAbstractItemView::defaultdropEvent(QDropEvent * event){
	QAbstractItemView::dropEvent(event);
}

void MaxQAbstractItemView::defaultenterEvent(QEvent * event){
	QAbstractItemView::enterEvent(event);
}

void MaxQAbstractItemView::defaultfocusInEvent(QFocusEvent * event){
	QAbstractItemView::focusInEvent(event);
}

bool MaxQAbstractItemView::defaultfocusNextChild() {
	return QAbstractItemView::focusNextChild();
}

bool MaxQAbstractItemView::defaultfocusNextPrevChild(bool next){
	return QAbstractItemView::focusNextPrevChild(next);
}

void MaxQAbstractItemView::defaultfocusOutEvent(QFocusEvent * event){
	QAbstractItemView::focusOutEvent(event);
}

bool MaxQAbstractItemView::defaultfocusPreviousChild() {
	return QAbstractItemView::focusPreviousChild();
}

void MaxQAbstractItemView::defaulthideEvent(QHideEvent * event){
	QAbstractItemView::hideEvent(event);
}

void MaxQAbstractItemView::defaultinputMethodEvent(QInputMethodEvent * event){
	QAbstractItemView::inputMethodEvent(event);
}

void MaxQAbstractItemView::defaultkeyPressEvent(QKeyEvent * event){
	QAbstractItemView::keyPressEvent(event);
}

void MaxQAbstractItemView::defaultkeyReleaseEvent(QKeyEvent * event){
	QAbstractItemView::keyReleaseEvent(event);
}

void MaxQAbstractItemView::defaultleaveEvent(QEvent * event){
	QAbstractItemView::leaveEvent(event);
}

void MaxQAbstractItemView::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QAbstractItemView::mouseDoubleClickEvent(event);
}

void MaxQAbstractItemView::defaultmouseMoveEvent(QMouseEvent * event){
	QAbstractItemView::mouseMoveEvent(event);
}

void MaxQAbstractItemView::defaultmousePressEvent(QMouseEvent * event){
	QAbstractItemView::mousePressEvent(event);
}

void MaxQAbstractItemView::defaultmouseReleaseEvent(QMouseEvent * event){
	QAbstractItemView::mouseReleaseEvent(event);
}

void MaxQAbstractItemView::defaultmoveEvent(QMoveEvent * event){
	QAbstractItemView::moveEvent(event);
}

void MaxQAbstractItemView::defaultpaintEvent(QPaintEvent * event){
	QAbstractItemView::paintEvent(event);
}

void MaxQAbstractItemView::defaultresizeEvent(QResizeEvent * event){
	QAbstractItemView::resizeEvent(event);
}

void MaxQAbstractItemView::defaultshowEvent(QShowEvent * event){
	QAbstractItemView::showEvent(event);
}

void MaxQAbstractItemView::defaulttabletEvent(QTabletEvent * event){
	QAbstractItemView::tabletEvent(event);
}

void MaxQAbstractItemView::defaultwheelEvent(QWheelEvent * event){
	QAbstractItemView::wheelEvent(event);
}

// QObject
bool MaxQAbstractItemView::defaultevent(QEvent * event){
	return QAbstractItemView::event(event);
}

void MaxQAbstractItemView::defaulttimerEvent(QTimerEvent * event){
	QAbstractItemView::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QAbstractItemView
// QAbstractScrollArea
void MaxQAbstractItemView::scrollContentsBy(int dx, int dy) {
	_qt_qabstractscrollarea_QAbstractScrollArea__scrollContentsBy(maxHandle, dx, dy);
}

bool MaxQAbstractItemView::viewportEvent(QEvent * event) {
	return static_cast<bool>(_qt_qabstractscrollarea_QAbstractScrollArea__viewportEvent(maxHandle, event));
}
// QFrame
// QWidget
void MaxQAbstractItemView::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQAbstractItemView::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQAbstractItemView::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQAbstractItemView::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQAbstractItemView::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQAbstractItemView::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQAbstractItemView::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQAbstractItemView::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQAbstractItemView::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQAbstractItemView::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQAbstractItemView::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQAbstractItemView::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQAbstractItemView::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQAbstractItemView::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQAbstractItemView::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQAbstractItemView::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQAbstractItemView::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQAbstractItemView::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQAbstractItemView::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQAbstractItemView::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQAbstractItemView::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQAbstractItemView::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQAbstractItemView::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQAbstractItemView::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQAbstractItemView::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQAbstractItemView::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQAbstractItemView::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQAbstractItemView::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQAbstractItemView::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQAbstractItemView::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQAbstractItemView::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QAbstractItemView
// QAbstractScrollArea
void bmx_qt_qabstractitemview_default_scrollcontentsby(MaxQAbstractItemView * view, int dx, int dy) {
	view->defaultscrollContentsBy(dx, dy);
}

int bmx_qt_qabstractitemview_default_viewportevent(MaxQAbstractItemView * view, QEvent * event) {
	static_cast<int>(view->defaultviewportEvent(event));
}

// QFrame
// QWidget
void bmx_qt_qabstractitemview_default_actionevent(MaxQAbstractItemView * view, QActionEvent * event) {
	view->defaultactionEvent(event);
}

void bmx_qt_qabstractitemview_default_changeevent(MaxQAbstractItemView * view, QEvent * event) {
	view->defaultchangeEvent(event);
}

void bmx_qt_qabstractitemview_default_closeevent(MaxQAbstractItemView * view, QCloseEvent * event) {
	view->defaultcloseEvent(event);
}

void bmx_qt_qabstractitemview_default_contextmenuevent(MaxQAbstractItemView * view, QContextMenuEvent * event) {
	view->defaultcontextMenuEvent(event);
}

void bmx_qt_qabstractitemview_default_dragenterevent(MaxQAbstractItemView * view, QDragEnterEvent * event) {
	view->defaultdragEnterEvent(event);
}

void bmx_qt_qabstractitemview_default_dragleaveevent(MaxQAbstractItemView * view, QDragLeaveEvent * event) {
	view->defaultdragLeaveEvent(event);
}

void bmx_qt_qabstractitemview_default_dragmoveevent(MaxQAbstractItemView * view, QDragMoveEvent * event) {
	view->defaultdragMoveEvent(event);
}

void bmx_qt_qabstractitemview_default_dropevent(MaxQAbstractItemView * view, QDropEvent * event) {
	view->defaultdropEvent(event);
}

void bmx_qt_qabstractitemview_default_enterevent(MaxQAbstractItemView * view, QEvent * event) {
	view->defaultenterEvent(event);
}

void bmx_qt_qabstractitemview_default_focusinevent(MaxQAbstractItemView * view, QFocusEvent * event) {
	view->defaultfocusInEvent(event);
}

int bmx_qt_qabstractitemview_default_focusnextprevchild(MaxQAbstractItemView * view, int next) {
	return static_cast<int>(view->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qabstractitemview_default_focusnextchild(MaxQAbstractItemView * view) {
	return static_cast<int>(view->defaultfocusNextChild());
}

void bmx_qt_qabstractitemview_default_focusoutevent(MaxQAbstractItemView * view, QFocusEvent * event) {
	view->defaultfocusOutEvent(event);
}

int bmx_qt_qabstractitemview_default_focuspreviouschild(MaxQAbstractItemView * view) {
	return static_cast<int>(view->defaultfocusPreviousChild());
}

void bmx_qt_qabstractitemview_default_hideevent(MaxQAbstractItemView * view, QHideEvent * event) {
	view->defaulthideEvent(event);
}

void bmx_qt_qabstractitemview_default_inputmethodevent(MaxQAbstractItemView * view, QInputMethodEvent * event) {
	view->defaultinputMethodEvent(event);
}

void bmx_qt_qabstractitemview_default_keypressevent(MaxQAbstractItemView * view, QKeyEvent * event) {
	view->defaultkeyPressEvent(event);
}

void bmx_qt_qabstractitemview_default_keyreleaseevent(MaxQAbstractItemView * view, QKeyEvent * event) {
	view->defaultkeyReleaseEvent(event);
}

void bmx_qt_qabstractitemview_default_leaveevent(MaxQAbstractItemView * view, QEvent * event) {
	view->defaultleaveEvent(event);
}

void bmx_qt_qabstractitemview_default_mousedoubleclickevent(MaxQAbstractItemView * view, QMouseEvent * event) {
	view->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qabstractitemview_default_mousemoveevent(MaxQAbstractItemView * view, QMouseEvent * event) {
	view->defaultmouseMoveEvent(event);
}

void bmx_qt_qabstractitemview_default_mousepressevent(MaxQAbstractItemView * view, QMouseEvent * event) {
	view->defaultmousePressEvent(event);
}

void bmx_qt_qabstractitemview_default_mousereleaseevent(MaxQAbstractItemView * view, QMouseEvent * event) {
	view->defaultmouseReleaseEvent(event);
}

void bmx_qt_qabstractitemview_default_moveevent(MaxQAbstractItemView * view, QMoveEvent * event) {
	view->defaultmoveEvent(event);
}

void bmx_qt_qabstractitemview_default_paintevent(MaxQAbstractItemView * view, QPaintEvent * event) {
	view->defaultpaintEvent(event);
}

void bmx_qt_qabstractitemview_default_resizeevent(MaxQAbstractItemView * view, QResizeEvent * event) {
	view->defaultresizeEvent(event);
}

void bmx_qt_qabstractitemview_default_showevent(MaxQAbstractItemView * view, QShowEvent * event) {
	view->defaultshowEvent(event);
}

void bmx_qt_qabstractitemview_default_tabletevent(MaxQAbstractItemView * view, QTabletEvent * event) {
	view->defaulttabletEvent(event);
}

void bmx_qt_qabstractitemview_default_wheelevent(MaxQAbstractItemView * view, QWheelEvent * event) {
	view->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qabstractitemview_default_event(MaxQAbstractItemView * view, QEvent * event) {
	return static_cast<int>(view->defaultevent(event));
}

void bmx_qt_qabstractitemview_default_timerevent(MaxQAbstractItemView * view, QTimerEvent * event) {
	view->defaulttimerEvent(event);
}

// *********************************************

void bmx_qt_qabstractitemview_setmodel(QAbstractItemView * view, QAbstractItemModel * model) {
	view->setModel(model);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
