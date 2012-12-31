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

MaxQAbstractScrollArea::MaxQAbstractScrollArea(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QAbstractScrollArea(parent)
{
	qbind(this, handle);
}

MaxQAbstractScrollArea::~MaxQAbstractScrollArea()
{
	qunbind(this);
}


// ****************** DEFAULT HANDLERS ********************

// QAbstractScrollArea
void MaxQAbstractScrollArea::defaultscrollContentsBy(int dx, int dy){
	QAbstractScrollArea::scrollContentsBy(dx, dy);
}

bool MaxQAbstractScrollArea::defaultviewportEvent(QEvent * event){
	return QAbstractScrollArea::viewportEvent(event);
}

// QFrame
// QWidget
void MaxQAbstractScrollArea::defaultactionEvent(QActionEvent * event){
	QAbstractScrollArea::actionEvent(event);
}

void MaxQAbstractScrollArea::defaultchangeEvent(QEvent * event){
	QAbstractScrollArea::changeEvent(event);
}

void MaxQAbstractScrollArea::defaultcloseEvent(QCloseEvent * event){
	QAbstractScrollArea::closeEvent(event);
}

void MaxQAbstractScrollArea::defaultcontextMenuEvent(QContextMenuEvent * event){
	QAbstractScrollArea::contextMenuEvent(event);
}

void MaxQAbstractScrollArea::defaultdragEnterEvent(QDragEnterEvent * event){
	QAbstractScrollArea::dragEnterEvent(event);
}

void MaxQAbstractScrollArea::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QAbstractScrollArea::dragLeaveEvent(event);
}

void MaxQAbstractScrollArea::defaultdragMoveEvent(QDragMoveEvent * event){
	QAbstractScrollArea::dragMoveEvent(event);
}

void MaxQAbstractScrollArea::defaultdropEvent(QDropEvent * event){
	QAbstractScrollArea::dropEvent(event);
}

void MaxQAbstractScrollArea::defaultenterEvent(QEvent * event){
	QAbstractScrollArea::enterEvent(event);
}

void MaxQAbstractScrollArea::defaultfocusInEvent(QFocusEvent * event){
	QAbstractScrollArea::focusInEvent(event);
}

bool MaxQAbstractScrollArea::defaultfocusNextChild() {
	return QAbstractScrollArea::focusNextChild();
}

bool MaxQAbstractScrollArea::defaultfocusNextPrevChild(bool next){
	return QAbstractScrollArea::focusNextPrevChild(next);
}

void MaxQAbstractScrollArea::defaultfocusOutEvent(QFocusEvent * event){
	QAbstractScrollArea::focusOutEvent(event);
}

bool MaxQAbstractScrollArea::defaultfocusPreviousChild() {
	return QAbstractScrollArea::focusPreviousChild();
}

void MaxQAbstractScrollArea::defaulthideEvent(QHideEvent * event){
	QAbstractScrollArea::hideEvent(event);
}

void MaxQAbstractScrollArea::defaultinputMethodEvent(QInputMethodEvent * event){
	QAbstractScrollArea::inputMethodEvent(event);
}

void MaxQAbstractScrollArea::defaultkeyPressEvent(QKeyEvent * event){
	QAbstractScrollArea::keyPressEvent(event);
}

void MaxQAbstractScrollArea::defaultkeyReleaseEvent(QKeyEvent * event){
	QAbstractScrollArea::keyReleaseEvent(event);
}

void MaxQAbstractScrollArea::defaultleaveEvent(QEvent * event){
	QAbstractScrollArea::leaveEvent(event);
}

void MaxQAbstractScrollArea::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QAbstractScrollArea::mouseDoubleClickEvent(event);
}

void MaxQAbstractScrollArea::defaultmouseMoveEvent(QMouseEvent * event){
	QAbstractScrollArea::mouseMoveEvent(event);
}

void MaxQAbstractScrollArea::defaultmousePressEvent(QMouseEvent * event){
	QAbstractScrollArea::mousePressEvent(event);
}

void MaxQAbstractScrollArea::defaultmouseReleaseEvent(QMouseEvent * event){
	QAbstractScrollArea::mouseReleaseEvent(event);
}

void MaxQAbstractScrollArea::defaultmoveEvent(QMoveEvent * event){
	QAbstractScrollArea::moveEvent(event);
}

void MaxQAbstractScrollArea::defaultpaintEvent(QPaintEvent * event){
	QAbstractScrollArea::paintEvent(event);
}

void MaxQAbstractScrollArea::defaultresizeEvent(QResizeEvent * event){
	QAbstractScrollArea::resizeEvent(event);
}

void MaxQAbstractScrollArea::defaultshowEvent(QShowEvent * event){
	QAbstractScrollArea::showEvent(event);
}

void MaxQAbstractScrollArea::defaulttabletEvent(QTabletEvent * event){
	QAbstractScrollArea::tabletEvent(event);
}

void MaxQAbstractScrollArea::defaultwheelEvent(QWheelEvent * event){
	QAbstractScrollArea::wheelEvent(event);
}

// QObject
bool MaxQAbstractScrollArea::defaultevent(QEvent * event){
	return QAbstractScrollArea::event(event);
}

void MaxQAbstractScrollArea::defaulttimerEvent(QTimerEvent * event){
	QAbstractScrollArea::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QAbstractScrollArea
void MaxQAbstractScrollArea::scrollContentsBy(int dx, int dy) {
	_qt_qabstractscrollarea_QAbstractScrollArea__scrollContentsBy(maxHandle, dx, dy);
}

bool MaxQAbstractScrollArea::viewportEvent(QEvent * event) {
	return static_cast<bool>(_qt_qabstractscrollarea_QAbstractScrollArea__viewportEvent(maxHandle, event));
}
// QFrame
// QWidget
void MaxQAbstractScrollArea::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQAbstractScrollArea::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQAbstractScrollArea::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQAbstractScrollArea::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQAbstractScrollArea::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQAbstractScrollArea::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQAbstractScrollArea::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQAbstractScrollArea::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQAbstractScrollArea::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQAbstractScrollArea::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QAbstractScrollArea
void bmx_qt_qabstractscrollarea_default_scrollcontentsby(MaxQAbstractScrollArea * area, int dx, int dy) {
	area->defaultscrollContentsBy(dx, dy);
}

int bmx_qt_qabstractscrollarea_default_viewportevent(MaxQAbstractScrollArea * area, QEvent * event) {
	static_cast<int>(area->defaultviewportEvent(event));
}

// QFrame
// QWidget
void bmx_qt_qabstractscrollarea_default_actionevent(MaxQAbstractScrollArea * area, QActionEvent * event) {
	area->defaultactionEvent(event);
}

void bmx_qt_qabstractscrollarea_default_changeevent(MaxQAbstractScrollArea * area, QEvent * event) {
	area->defaultchangeEvent(event);
}

void bmx_qt_qabstractscrollarea_default_closeevent(MaxQAbstractScrollArea * area, QCloseEvent * event) {
	area->defaultcloseEvent(event);
}

void bmx_qt_qabstractscrollarea_default_contextmenuevent(MaxQAbstractScrollArea * area, QContextMenuEvent * event) {
	area->defaultcontextMenuEvent(event);
}

void bmx_qt_qabstractscrollarea_default_dragenterevent(MaxQAbstractScrollArea * area, QDragEnterEvent * event) {
	area->defaultdragEnterEvent(event);
}

void bmx_qt_qabstractscrollarea_default_dragleaveevent(MaxQAbstractScrollArea * area, QDragLeaveEvent * event) {
	area->defaultdragLeaveEvent(event);
}

void bmx_qt_qabstractscrollarea_default_dragmoveevent(MaxQAbstractScrollArea * area, QDragMoveEvent * event) {
	area->defaultdragMoveEvent(event);
}

void bmx_qt_qabstractscrollarea_default_dropevent(MaxQAbstractScrollArea * area, QDropEvent * event) {
	area->defaultdropEvent(event);
}

void bmx_qt_qabstractscrollarea_default_enterevent(MaxQAbstractScrollArea * area, QEvent * event) {
	area->defaultenterEvent(event);
}

void bmx_qt_qabstractscrollarea_default_focusinevent(MaxQAbstractScrollArea * area, QFocusEvent * event) {
	area->defaultfocusInEvent(event);
}

int bmx_qt_qabstractscrollarea_default_focusnextprevchild(MaxQAbstractScrollArea * area, int next) {
	return static_cast<int>(area->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qabstractscrollarea_default_focusnextchild(MaxQAbstractScrollArea * area) {
	return static_cast<int>(area->defaultfocusNextChild());
}

void bmx_qt_qabstractscrollarea_default_focusoutevent(MaxQAbstractScrollArea * area, QFocusEvent * event) {
	area->defaultfocusOutEvent(event);
}

int bmx_qt_qabstractscrollarea_default_focuspreviouschild(MaxQAbstractScrollArea * area) {
	return static_cast<int>(area->defaultfocusPreviousChild());
}

void bmx_qt_qabstractscrollarea_default_hideevent(MaxQAbstractScrollArea * area, QHideEvent * event) {
	area->defaulthideEvent(event);
}

void bmx_qt_qabstractscrollarea_default_inputmethodevent(MaxQAbstractScrollArea * area, QInputMethodEvent * event) {
	area->defaultinputMethodEvent(event);
}

void bmx_qt_qabstractscrollarea_default_keypressevent(MaxQAbstractScrollArea * area, QKeyEvent * event) {
	area->defaultkeyPressEvent(event);
}

void bmx_qt_qabstractscrollarea_default_keyreleaseevent(MaxQAbstractScrollArea * area, QKeyEvent * event) {
	area->defaultkeyReleaseEvent(event);
}

void bmx_qt_qabstractscrollarea_default_leaveevent(MaxQAbstractScrollArea * area, QEvent * event) {
	area->defaultleaveEvent(event);
}

void bmx_qt_qabstractscrollarea_default_mousedoubleclickevent(MaxQAbstractScrollArea * area, QMouseEvent * event) {
	area->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qabstractscrollarea_default_mousemoveevent(MaxQAbstractScrollArea * area, QMouseEvent * event) {
	area->defaultmouseMoveEvent(event);
}

void bmx_qt_qabstractscrollarea_default_mousepressevent(MaxQAbstractScrollArea * area, QMouseEvent * event) {
	area->defaultmousePressEvent(event);
}

void bmx_qt_qabstractscrollarea_default_mousereleaseevent(MaxQAbstractScrollArea * area, QMouseEvent * event) {
	area->defaultmouseReleaseEvent(event);
}

void bmx_qt_qabstractscrollarea_default_moveevent(MaxQAbstractScrollArea * area, QMoveEvent * event) {
	area->defaultmoveEvent(event);
}

void bmx_qt_qabstractscrollarea_default_paintevent(MaxQAbstractScrollArea * area, QPaintEvent * event) {
	area->defaultpaintEvent(event);
}

void bmx_qt_qabstractscrollarea_default_resizeevent(MaxQAbstractScrollArea * area, QResizeEvent * event) {
	area->defaultresizeEvent(event);
}

void bmx_qt_qabstractscrollarea_default_showevent(MaxQAbstractScrollArea * area, QShowEvent * event) {
	area->defaultshowEvent(event);
}

void bmx_qt_qabstractscrollarea_default_tabletevent(MaxQAbstractScrollArea * area, QTabletEvent * event) {
	area->defaulttabletEvent(event);
}

void bmx_qt_qabstractscrollarea_default_wheelevent(MaxQAbstractScrollArea * area, QWheelEvent * event) {
	area->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qabstractscrollarea_default_event(MaxQAbstractScrollArea * area, QEvent * event) {
	return static_cast<int>(area->defaultevent(event));
}

void bmx_qt_qabstractscrollarea_default_timerevent(MaxQAbstractScrollArea * area, QTimerEvent * event) {
	area->defaulttimerEvent(event);
}



// *********************************************

void bmx_qt_qabstractscrollarea_addscrollbarwidget(QAbstractScrollArea * sa, QWidget * widget, int alignment) {
	sa->addScrollBarWidget(widget, (Qt::Alignment)alignment);
}

QWidget * bmx_qt_qabstractscrollarea_cornerwidget(QAbstractScrollArea * sa) {
	return sa->cornerWidget();
}

QScrollBar * bmx_qt_qabstractscrollarea_horizontalscrollbar(QAbstractScrollArea * sa) {
	return sa->horizontalScrollBar();
}

int bmx_qt_qabstractscrollarea_horizontalscrollbarpolicy(QAbstractScrollArea * sa) {
	return sa->horizontalScrollBarPolicy();
}

void bmx_qt_qabstractscrollarea_maximumviewportsize(QAbstractScrollArea * sa, int * w, int * h) {
	QSize s(sa->maximumViewportSize());
	*w = s.width();
	*h = s.height();
}

void bmx_qt_qabstractscrollarea_setcornerwidget(QAbstractScrollArea * sa, QWidget * widget) {
	sa->setCornerWidget(widget);
}

void bmx_qt_qabstractscrollarea_sethorizontalscrollbar(QAbstractScrollArea * sa, QScrollBar * scrollBar) {
	sa->setHorizontalScrollBar(scrollBar);
}

void bmx_qt_qabstractscrollarea_sethorizontalscrollbarpolicy(QAbstractScrollArea * sa, int policy) {
	sa->setHorizontalScrollBarPolicy((Qt::ScrollBarPolicy)policy);
}

void bmx_qt_qabstractscrollarea_setverticalscrollbar(QAbstractScrollArea * sa, QScrollBar * scrollBar) {
	sa->setVerticalScrollBar(scrollBar);
}

void bmx_qt_qabstractscrollarea_setverticalscrollbarpolicy(QAbstractScrollArea * sa, int policy) {
	sa->setVerticalScrollBarPolicy((Qt::ScrollBarPolicy)policy);
}

void bmx_qt_qabstractscrollarea_setviewport(QAbstractScrollArea * sa, QWidget * widget) {
	sa->setViewport(widget);
}

QScrollBar * bmx_qt_qabstractscrollarea_verticalscrollbar(QAbstractScrollArea * sa) {
	return sa->verticalScrollBar();
}

int bmx_qt_qabstractscrollarea_verticalscrollbarpolicy(QAbstractScrollArea * sa) {
	return sa->verticalScrollBarPolicy();
}

QWidget * bmx_qt_qabstractscrollarea_viewport(QAbstractScrollArea * sa) {
	return sa->viewport();
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
