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

MaxQProgressBar::MaxQProgressBar(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QProgressBar(parent)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(valueChanged(int)), SLOT(onValueChanged(int)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQProgressBar::~MaxQProgressBar()
{
	qunbind(this);
}

void MaxQProgressBar::onValueChanged(int value) {
	_qt_qprogressbar_QProgressBar__OnValueChanged(maxHandle, value);
}

void MaxQProgressBar::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}


// ****************** DEFAULT HANDLERS ********************

// QProgressBar

// QWidget
void MaxQProgressBar::defaultactionEvent(QActionEvent * event){
	QProgressBar::actionEvent(event);
}

void MaxQProgressBar::defaultchangeEvent(QEvent * event){
	QProgressBar::changeEvent(event);
}

void MaxQProgressBar::defaultcloseEvent(QCloseEvent * event){
	QProgressBar::closeEvent(event);
}

void MaxQProgressBar::defaultcontextMenuEvent(QContextMenuEvent * event){
	QProgressBar::contextMenuEvent(event);
}

void MaxQProgressBar::defaultdragEnterEvent(QDragEnterEvent * event){
	QProgressBar::dragEnterEvent(event);
}

void MaxQProgressBar::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QProgressBar::dragLeaveEvent(event);
}

void MaxQProgressBar::defaultdragMoveEvent(QDragMoveEvent * event){
	QProgressBar::dragMoveEvent(event);
}

void MaxQProgressBar::defaultdropEvent(QDropEvent * event){
	QProgressBar::dropEvent(event);
}

void MaxQProgressBar::defaultenterEvent(QEvent * event){
	QProgressBar::enterEvent(event);
}

void MaxQProgressBar::defaultfocusInEvent(QFocusEvent * event){
	QProgressBar::focusInEvent(event);
}

bool MaxQProgressBar::defaultfocusNextChild() {
	return QProgressBar::focusNextChild();
}

bool MaxQProgressBar::defaultfocusNextPrevChild(bool next){
	return QProgressBar::focusNextPrevChild(next);
}

void MaxQProgressBar::defaultfocusOutEvent(QFocusEvent * event){
	QProgressBar::focusOutEvent(event);
}

bool MaxQProgressBar::defaultfocusPreviousChild() {
	return QProgressBar::focusPreviousChild();
}

void MaxQProgressBar::defaulthideEvent(QHideEvent * event){
	QProgressBar::hideEvent(event);
}

void MaxQProgressBar::defaultinputMethodEvent(QInputMethodEvent * event){
	QProgressBar::inputMethodEvent(event);
}

void MaxQProgressBar::defaultkeyPressEvent(QKeyEvent * event){
	QProgressBar::keyPressEvent(event);
}

void MaxQProgressBar::defaultkeyReleaseEvent(QKeyEvent * event){
	QProgressBar::keyReleaseEvent(event);
}

void MaxQProgressBar::defaultleaveEvent(QEvent * event){
	QProgressBar::leaveEvent(event);
}

void MaxQProgressBar::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QProgressBar::mouseDoubleClickEvent(event);
}

void MaxQProgressBar::defaultmouseMoveEvent(QMouseEvent * event){
	QProgressBar::mouseMoveEvent(event);
}

void MaxQProgressBar::defaultmousePressEvent(QMouseEvent * event){
	QProgressBar::mousePressEvent(event);
}

void MaxQProgressBar::defaultmouseReleaseEvent(QMouseEvent * event){
	QProgressBar::mouseReleaseEvent(event);
}

void MaxQProgressBar::defaultmoveEvent(QMoveEvent * event){
	QProgressBar::moveEvent(event);
}

void MaxQProgressBar::defaultpaintEvent(QPaintEvent * event){
	QProgressBar::paintEvent(event);
}

void MaxQProgressBar::defaultresizeEvent(QResizeEvent * event){
	QProgressBar::resizeEvent(event);
}

void MaxQProgressBar::defaultshowEvent(QShowEvent * event){
	QProgressBar::showEvent(event);
}

void MaxQProgressBar::defaulttabletEvent(QTabletEvent * event){
	QProgressBar::tabletEvent(event);
}

void MaxQProgressBar::defaultwheelEvent(QWheelEvent * event){
	QProgressBar::wheelEvent(event);
}

// QObject
bool MaxQProgressBar::defaultevent(QEvent * event){
	return QProgressBar::event(event);
}

void MaxQProgressBar::defaulttimerEvent(QTimerEvent * event){
	QProgressBar::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QProgressBar

// QWidget

void MaxQProgressBar::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQProgressBar::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQProgressBar::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQProgressBar::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQProgressBar::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQProgressBar::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQProgressBar::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQProgressBar::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQProgressBar::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQProgressBar::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQProgressBar::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQProgressBar::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQProgressBar::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQProgressBar::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQProgressBar::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQProgressBar::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQProgressBar::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQProgressBar::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQProgressBar::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQProgressBar::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQProgressBar::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQProgressBar::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQProgressBar::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}

void MaxQProgressBar::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQProgressBar::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQProgressBar::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQProgressBar::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQProgressBar::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQProgressBar::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQProgressBar::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQProgressBar::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QProgressBar

// QWidget
void bmx_qt_qprogressbar_default_actionevent(MaxQProgressBar * bar, QActionEvent * event) {
	bar->defaultactionEvent(event);
}

void bmx_qt_qprogressbar_default_changeevent(MaxQProgressBar * bar, QEvent * event) {
	bar->defaultchangeEvent(event);
}

void bmx_qt_qprogressbar_default_closeevent(MaxQProgressBar * bar, QCloseEvent * event) {
	bar->defaultcloseEvent(event);
}

void bmx_qt_qprogressbar_default_contextmenuevent(MaxQProgressBar * bar, QContextMenuEvent * event) {
	bar->defaultcontextMenuEvent(event);
}

void bmx_qt_qprogressbar_default_dragenterevent(MaxQProgressBar * bar, QDragEnterEvent * event) {
	bar->defaultdragEnterEvent(event);
}

void bmx_qt_qprogressbar_default_dragleaveevent(MaxQProgressBar * bar, QDragLeaveEvent * event) {
	bar->defaultdragLeaveEvent(event);
}

void bmx_qt_qprogressbar_default_dragmoveevent(MaxQProgressBar * bar, QDragMoveEvent * event) {
	bar->defaultdragMoveEvent(event);
}

void bmx_qt_qprogressbar_default_dropevent(MaxQProgressBar * bar, QDropEvent * event) {
	bar->defaultdropEvent(event);
}

void bmx_qt_qprogressbar_default_enterevent(MaxQProgressBar * bar, QEvent * event) {
	bar->defaultenterEvent(event);
}

void bmx_qt_qprogressbar_default_focusinevent(MaxQProgressBar * bar, QFocusEvent * event) {
	bar->defaultfocusInEvent(event);
}

int bmx_qt_qprogressbar_default_focusnextprevchild(MaxQProgressBar * bar, int next) {
	return static_cast<int>(bar->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qprogressbar_default_focusnextchild(MaxQProgressBar * bar) {
	return static_cast<int>(bar->defaultfocusNextChild());
}

void bmx_qt_qprogressbar_default_focusoutevent(MaxQProgressBar * bar, QFocusEvent * event) {
	bar->defaultfocusOutEvent(event);
}

int bmx_qt_qprogressbar_default_focuspreviouschild(MaxQProgressBar * bar) {
	return static_cast<int>(bar->defaultfocusPreviousChild());
}

void bmx_qt_qprogressbar_default_hideevent(MaxQProgressBar * bar, QHideEvent * event) {
	bar->defaulthideEvent(event);
}

void bmx_qt_qprogressbar_default_inputmethodevent(MaxQProgressBar * bar, QInputMethodEvent * event) {
	bar->defaultinputMethodEvent(event);
}

void bmx_qt_qprogressbar_default_keypressevent(MaxQProgressBar * bar, QKeyEvent * event) {
	bar->defaultkeyPressEvent(event);
}

void bmx_qt_qprogressbar_default_keyreleaseevent(MaxQProgressBar * bar, QKeyEvent * event) {
	bar->defaultkeyReleaseEvent(event);
}

void bmx_qt_qprogressbar_default_leaveevent(MaxQProgressBar * bar, QEvent * event) {
	bar->defaultleaveEvent(event);
}

void bmx_qt_qprogressbar_default_mousedoubleclickevent(MaxQProgressBar * bar, QMouseEvent * event) {
	bar->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qprogressbar_default_mousemoveevent(MaxQProgressBar * bar, QMouseEvent * event) {
	bar->defaultmouseMoveEvent(event);
}

void bmx_qt_qprogressbar_default_mousepressevent(MaxQProgressBar * bar, QMouseEvent * event) {
	bar->defaultmousePressEvent(event);
}

void bmx_qt_qprogressbar_default_mousereleaseevent(MaxQProgressBar * bar, QMouseEvent * event) {
	bar->defaultmouseReleaseEvent(event);
}

void bmx_qt_qprogressbar_default_moveevent(MaxQProgressBar * bar, QMoveEvent * event) {
	bar->defaultmoveEvent(event);
}

void bmx_qt_qprogressbar_default_paintevent(MaxQProgressBar * bar, QPaintEvent * event) {
	bar->defaultpaintEvent(event);
}

void bmx_qt_qprogressbar_default_resizeevent(MaxQProgressBar * bar, QResizeEvent * event) {
	bar->defaultresizeEvent(event);
}

void bmx_qt_qprogressbar_default_showevent(MaxQProgressBar * bar, QShowEvent * event) {
	bar->defaultshowEvent(event);
}

void bmx_qt_qprogressbar_default_tabletevent(MaxQProgressBar * bar, QTabletEvent * event) {
	bar->defaulttabletEvent(event);
}

void bmx_qt_qprogressbar_default_wheelevent(MaxQProgressBar * bar, QWheelEvent * event) {
	bar->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qprogressbar_default_event(MaxQProgressBar * bar, QEvent * event) {
	return static_cast<int>(bar->defaultevent(event));
}

void bmx_qt_qprogressbar_default_timerevent(MaxQProgressBar * bar, QTimerEvent * event) {
	bar->defaulttimerEvent(event);
}


// *********************************************

QProgressBar::Direction bmx_qt_getprogressbardirection(int dir) {
	switch (dir) {
		case 0:
			return QProgressBar::TopToBottom;
		case 1:
			return QProgressBar::BottomToTop;
	}
	
	return QProgressBar::TopToBottom;
}


QProgressBar * bmx_qt_qprogressbar_create(BBObject * handle, QWidget * parent) {
	return new MaxQProgressBar(handle, parent);
}

int bmx_qt_qprogressbar_alignment(QProgressBar * bar) {
	return static_cast<int>(bar->alignment());
}

BBString * bmx_qt_qprogressbar_format(QProgressBar * bar) {
	return bbStringFromQString(bar->format());
}

int bmx_qt_qprogressbar_invertedappearance(QProgressBar * bar) {
	return static_cast<int>(bar->invertedAppearance());
}

int bmx_qt_qprogressbar_istextvisible(QProgressBar * bar) {
	return static_cast<int>(bar->isTextVisible());
}

int bmx_qt_qprogressbar_maximum(QProgressBar * bar) {
	return bar->maximum();
}

int bmx_qt_qprogressbar_minimum(QProgressBar * bar) {
	return bar->minimum();
}

int bmx_qt_qprogressbar_orientation(QProgressBar * bar) {
	return static_cast<int>(bar->orientation());
}

void bmx_qt_qprogressbar_setalignment(QProgressBar * bar, int alignment) {
	bar->setAlignment(bmx_qt_getalignment(alignment));
}

void bmx_qt_qprogressbar_setformat(QProgressBar * bar, BBString * format) {
	bar->setFormat(qStringFromBBString(format));
}

void bmx_qt_qprogressbar_setinvertedappearance(QProgressBar * bar, int invert) {
	bar->setInvertedAppearance(static_cast<bool>(invert));
}

void bmx_qt_qprogressbar_settextdirection(QProgressBar * bar, int textDirection) {
	bar->setTextDirection(bmx_qt_getprogressbardirection(textDirection));
}

void bmx_qt_qprogressbar_settextvisible(QProgressBar * bar, int visible) {
	bar->setTextVisible(static_cast<bool>(visible));
}

BBString * bmx_qt_qprogressbar_text(QProgressBar * bar) {
	return bbStringFromQString(bar->text());
}

int bmx_qt_qprogressbar_textdirection(QProgressBar * bar) {
	return static_cast<int>(bar->textDirection());
}

int bmx_qt_qprogressbar_value(QProgressBar * bar) {
	return bar->value();
}

void bmx_qt_qprogressbar_reset(QProgressBar * bar) {
	bar->reset();
}

void bmx_qt_qprogressbar_setmaximum(QProgressBar * bar, int maximum) {
	bar->setMaximum(maximum);
}

void bmx_qt_qprogressbar_setminimum(QProgressBar * bar, int minimum) {
	bar->setMinimum(minimum);
}

void bmx_qt_qprogressbar_setorientation(QProgressBar * bar, int orientation) {
	bar->setOrientation(bmx_qt_getorientation(orientation));
}

void bmx_qt_qprogressbar_setrange(QProgressBar * bar, int minimum, int maximum) {
	bar->setRange(minimum, maximum);
}

void bmx_qt_qprogressbar_setvalue(QProgressBar * bar, int value) {
	bar->setValue(value);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
