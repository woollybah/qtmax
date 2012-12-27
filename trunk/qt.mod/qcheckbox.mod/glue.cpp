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

MaxQCheckBox::MaxQCheckBox(BBObject * handle, const QString & text, QWidget * parent)
	: maxHandle(handle), QCheckBox(text, parent)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(clicked(bool)), SLOT(onClicked(bool)));
	connect(this, SIGNAL(pressed()), SLOT(onPressed()));
	connect(this, SIGNAL(released()), SLOT(onReleased()));
	connect(this, SIGNAL(toggled(bool)), SLOT(onToggled(bool)));
	connect(this, SIGNAL(stateChanged(int)), SLOT(onStateChanged(int)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQCheckBox::~MaxQCheckBox()
{
	qunbind(this);
}

void MaxQCheckBox::onClicked(bool checked) {
	_qt_qcheckbox_QCheckBox__OnClicked(maxHandle, static_cast<int>(checked));
}

void MaxQCheckBox::onPressed() {
	_qt_qcheckbox_QCheckBox__OnPressed(maxHandle);
}

void MaxQCheckBox::onReleased() {
	_qt_qcheckbox_QCheckBox__OnReleased(maxHandle);
}

void MaxQCheckBox::onToggled(bool checked) {
	_qt_qcheckbox_QCheckBox__OnToggled(maxHandle, static_cast<int>(checked));
}

void MaxQCheckBox::onStateChanged(int state) {
	_qt_qcheckbox_QCheckBox__OnStateChanged(maxHandle, state);
}

void MaxQCheckBox::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}


// ****************** DEFAULT HANDLERS ********************

// QCheckBox

// QAbstractButton
void MaxQCheckBox::defaultcheckStateSet() {
	QCheckBox::checkStateSet();
}

bool MaxQCheckBox::defaulthitButton(const QPoint & pos) const{
	return QCheckBox::hitButton(pos);
}

void MaxQCheckBox::defaultnextCheckState() {
	QCheckBox::nextCheckState();
}

// QWidget
void MaxQCheckBox::defaultactionEvent(QActionEvent * event){
	QCheckBox::actionEvent(event);
}

void MaxQCheckBox::defaultchangeEvent(QEvent * event){
	QCheckBox::changeEvent(event);
}

void MaxQCheckBox::defaultcloseEvent(QCloseEvent * event){
	QCheckBox::closeEvent(event);
}

void MaxQCheckBox::defaultcontextMenuEvent(QContextMenuEvent * event){
	QCheckBox::contextMenuEvent(event);
}

void MaxQCheckBox::defaultdragEnterEvent(QDragEnterEvent * event){
	QCheckBox::dragEnterEvent(event);
}

void MaxQCheckBox::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QCheckBox::dragLeaveEvent(event);
}

void MaxQCheckBox::defaultdragMoveEvent(QDragMoveEvent * event){
	QCheckBox::dragMoveEvent(event);
}

void MaxQCheckBox::defaultdropEvent(QDropEvent * event){
	QCheckBox::dropEvent(event);
}

void MaxQCheckBox::defaultenterEvent(QEvent * event){
	QCheckBox::enterEvent(event);
}

void MaxQCheckBox::defaultfocusInEvent(QFocusEvent * event){
	QCheckBox::focusInEvent(event);
}

bool MaxQCheckBox::defaultfocusNextChild() {
	return QCheckBox::focusNextChild();
}

bool MaxQCheckBox::defaultfocusNextPrevChild(bool next){
	return QCheckBox::focusNextPrevChild(next);
}

void MaxQCheckBox::defaultfocusOutEvent(QFocusEvent * event){
	QCheckBox::focusOutEvent(event);
}

bool MaxQCheckBox::defaultfocusPreviousChild() {
	return QCheckBox::focusPreviousChild();
}

void MaxQCheckBox::defaulthideEvent(QHideEvent * event){
	QCheckBox::hideEvent(event);
}

void MaxQCheckBox::defaultinputMethodEvent(QInputMethodEvent * event){
	QCheckBox::inputMethodEvent(event);
}

void MaxQCheckBox::defaultkeyPressEvent(QKeyEvent * event){
	QCheckBox::keyPressEvent(event);
}

void MaxQCheckBox::defaultkeyReleaseEvent(QKeyEvent * event){
	QCheckBox::keyReleaseEvent(event);
}

void MaxQCheckBox::defaultleaveEvent(QEvent * event){
	QCheckBox::leaveEvent(event);
}

void MaxQCheckBox::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QCheckBox::mouseDoubleClickEvent(event);
}

void MaxQCheckBox::defaultmouseMoveEvent(QMouseEvent * event){
	QCheckBox::mouseMoveEvent(event);
}

void MaxQCheckBox::defaultmousePressEvent(QMouseEvent * event){
	QCheckBox::mousePressEvent(event);
}

void MaxQCheckBox::defaultmouseReleaseEvent(QMouseEvent * event){
	QCheckBox::mouseReleaseEvent(event);
}

void MaxQCheckBox::defaultmoveEvent(QMoveEvent * event){
	QCheckBox::moveEvent(event);
}

void MaxQCheckBox::defaultpaintEvent(QPaintEvent * event){
	QCheckBox::paintEvent(event);
}

void MaxQCheckBox::defaultresizeEvent(QResizeEvent * event){
	QCheckBox::resizeEvent(event);
}

void MaxQCheckBox::defaultshowEvent(QShowEvent * event){
	QCheckBox::showEvent(event);
}

void MaxQCheckBox::defaulttabletEvent(QTabletEvent * event){
	QCheckBox::tabletEvent(event);
}

void MaxQCheckBox::defaultwheelEvent(QWheelEvent * event){
	QCheckBox::wheelEvent(event);
}

// QObject
bool MaxQCheckBox::defaultevent(QEvent * event){
	return QCheckBox::event(event);
}

void MaxQCheckBox::defaulttimerEvent(QTimerEvent * event){
	QCheckBox::timerEvent(event);
}

// ****************** HANDLERS - TO MAX ********************

// QCheckBox

// QAbstractButton
void MaxQCheckBox::checkStateSet() {
	_qt_qabstractbutton_QAbstractButton__checkStateSet(maxHandle);
}

bool MaxQCheckBox::hitButton(const QPoint & pos) const {
	return static_cast<bool>(_qt_qabstractbutton_QAbstractButton__hitButton(maxHandle, pos.x(), pos.y()));
}

void MaxQCheckBox::nextCheckState() {
	_qt_qabstractbutton_QAbstractButton__nextCheckState(maxHandle);
}

// QWidget
void MaxQCheckBox::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQCheckBox::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQCheckBox::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQCheckBox::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQCheckBox::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQCheckBox::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQCheckBox::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQCheckBox::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQCheckBox::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQCheckBox::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQCheckBox::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQCheckBox::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQCheckBox::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQCheckBox::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQCheckBox::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQCheckBox::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQCheckBox::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQCheckBox::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQCheckBox::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQCheckBox::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQCheckBox::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQCheckBox::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQCheckBox::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQCheckBox::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQCheckBox::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQCheckBox::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQCheckBox::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQCheckBox::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQCheckBox::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQCheckBox::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQCheckBox::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QCheckBox

// QAbstractButton
void bmx_qt_qcheckbox_default_checkstateset(MaxQCheckBox * check) {
	check->defaultcheckStateSet();
}

int bmx_qt_qcheckbox_default_hitbutton(MaxQCheckBox * check, int x, int y) {
	return static_cast<int>(check->defaulthitButton(QPoint(x, y)));
}

void bmx_qt_qcheckbox_default_nextcheckstate(MaxQCheckBox * check) {
	check->defaultnextCheckState();
}

// QWidget
void bmx_qt_qcheckbox_default_actionevent(MaxQCheckBox * check, QActionEvent * event) {
	check->defaultactionEvent(event);
}

void bmx_qt_qcheckbox_default_changeevent(MaxQCheckBox * check, QEvent * event) {
	check->defaultchangeEvent(event);
}

void bmx_qt_qcheckbox_default_closeevent(MaxQCheckBox * check, QCloseEvent * event) {
	check->defaultcloseEvent(event);
}

void bmx_qt_qcheckbox_default_contextmenuevent(MaxQCheckBox * check, QContextMenuEvent * event) {
	check->defaultcontextMenuEvent(event);
}

void bmx_qt_qcheckbox_default_dragenterevent(MaxQCheckBox * check, QDragEnterEvent * event) {
	check->defaultdragEnterEvent(event);
}

void bmx_qt_qcheckbox_default_dragleaveevent(MaxQCheckBox * check, QDragLeaveEvent * event) {
	check->defaultdragLeaveEvent(event);
}

void bmx_qt_qcheckbox_default_dragmoveevent(MaxQCheckBox * check, QDragMoveEvent * event) {
	check->defaultdragMoveEvent(event);
}

void bmx_qt_qcheckbox_default_dropevent(MaxQCheckBox * check, QDropEvent * event) {
	check->defaultdropEvent(event);
}

void bmx_qt_qcheckbox_default_enterevent(MaxQCheckBox * check, QEvent * event) {
	check->defaultenterEvent(event);
}

void bmx_qt_qcheckbox_default_focusinevent(MaxQCheckBox * check, QFocusEvent * event) {
	check->defaultfocusInEvent(event);
}

int bmx_qt_qcheckbox_default_focusnextprevchild(MaxQCheckBox * check, int next) {
	return static_cast<int>(check->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qcheckbox_default_focusnextchild(MaxQCheckBox * check) {
	return static_cast<int>(check->defaultfocusNextChild());
}

void bmx_qt_qcheckbox_default_focusoutevent(MaxQCheckBox * check, QFocusEvent * event) {
	check->defaultfocusOutEvent(event);
}

int bmx_qt_qcheckbox_default_focuspreviouschild(MaxQCheckBox * check) {
	return static_cast<int>(check->defaultfocusPreviousChild());
}

void bmx_qt_qcheckbox_default_hideevent(MaxQCheckBox * check, QHideEvent * event) {
	check->defaulthideEvent(event);
}

void bmx_qt_qcheckbox_default_inputmethodevent(MaxQCheckBox * check, QInputMethodEvent * event) {
	check->defaultinputMethodEvent(event);
}

void bmx_qt_qcheckbox_default_keypressevent(MaxQCheckBox * check, QKeyEvent * event) {
	check->defaultkeyPressEvent(event);
}

void bmx_qt_qcheckbox_default_keyreleaseevent(MaxQCheckBox * check, QKeyEvent * event) {
	check->defaultkeyReleaseEvent(event);
}

void bmx_qt_qcheckbox_default_leaveevent(MaxQCheckBox * check, QEvent * event) {
	check->defaultleaveEvent(event);
}

void bmx_qt_qcheckbox_default_mousedoubleclickevent(MaxQCheckBox * check, QMouseEvent * event) {
	check->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qcheckbox_default_mousemoveevent(MaxQCheckBox * check, QMouseEvent * event) {
	check->defaultmouseMoveEvent(event);
}

void bmx_qt_qcheckbox_default_mousepressevent(MaxQCheckBox * check, QMouseEvent * event) {
	check->defaultmousePressEvent(event);
}

void bmx_qt_qcheckbox_default_mousereleaseevent(MaxQCheckBox * check, QMouseEvent * event) {
	check->defaultmouseReleaseEvent(event);
}

void bmx_qt_qcheckbox_default_moveevent(MaxQCheckBox * check, QMoveEvent * event) {
	check->defaultmoveEvent(event);
}

void bmx_qt_qcheckbox_default_paintevent(MaxQCheckBox * check, QPaintEvent * event) {
	check->defaultpaintEvent(event);
}

void bmx_qt_qcheckbox_default_resizeevent(MaxQCheckBox * check, QResizeEvent * event) {
	check->defaultresizeEvent(event);
}

void bmx_qt_qcheckbox_default_showevent(MaxQCheckBox * check, QShowEvent * event) {
	check->defaultshowEvent(event);
}

void bmx_qt_qcheckbox_default_tabletevent(MaxQCheckBox * check, QTabletEvent * event) {
	check->defaulttabletEvent(event);
}

void bmx_qt_qcheckbox_default_wheelevent(MaxQCheckBox * check, QWheelEvent * event) {
	check->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qcheckbox_default_event(MaxQCheckBox * check, QEvent * event) {
	return static_cast<int>(check->defaultevent(event));
}

void bmx_qt_qcheckbox_default_timerevent(MaxQCheckBox * check, QTimerEvent * event) {
	check->defaulttimerEvent(event);
}


// *********************************************

QCheckBox * bmx_qt_qcheckbox_create(BBObject * handle, BBString * text, QWidget * parent) {
	return new MaxQCheckBox(handle, qStringFromBBString(text), parent);
}

int bmx_qt_qcheckbox_checkstate(QCheckBox * cb) {
	return cb->checkState();
}

int bmx_qt_qcheckbox_istristate(QCheckBox * cb) {
	return static_cast<int>(cb->isTristate());
}

void bmx_qt_qcheckbox_setcheckstate(QCheckBox * cb, int s) {
	Qt::CheckState state;
	switch(s) {
		case 0:
			state = Qt::Unchecked;
			break;
		case 1:
			state = Qt::PartiallyChecked;
			break;
		case 2:
			state = Qt::Checked;
			break;
	}
	
	cb->setCheckState(state);
}

void bmx_qt_qcheckbox_settristate(QCheckBox * cb, int value) {
	cb->setTristate(static_cast<bool>(value));
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
