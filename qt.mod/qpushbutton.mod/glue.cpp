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

MaxQPushButton::MaxQPushButton(BBObject * handle, const QString & text, QWidget * parent)
	: maxHandle(handle), QPushButton(text, parent)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(clicked(bool)), SLOT(onClicked(bool)));
	connect(this, SIGNAL(pressed()), SLOT(onPressed()));
	connect(this, SIGNAL(released()), SLOT(onReleased()));
	connect(this, SIGNAL(toggled(bool)), SLOT(onToggled(bool)));
}

MaxQPushButton::~MaxQPushButton()
{
	qunbind(this);
}

void MaxQPushButton::onClicked(bool checked) {
	_qt_qpushbutton_QPushButton__OnClicked(maxHandle, static_cast<int>(checked));
}

void MaxQPushButton::onPressed() {
	_qt_qpushbutton_QPushButton__OnPressed(maxHandle);
}

void MaxQPushButton::onReleased() {
	_qt_qpushbutton_QPushButton__OnReleased(maxHandle);
}

void MaxQPushButton::onToggled(bool checked) {
	_qt_qpushbutton_QPushButton__OnToggled(maxHandle, static_cast<int>(checked));
}


// ****************** DEFAULT HANDLERS ********************

// QPushButton

// QAbstractButton
void MaxQPushButton::defaultcheckStateSet() {
	QPushButton::checkStateSet();
}

bool MaxQPushButton::defaulthitButton(const QPoint & pos) const{
	return QPushButton::hitButton(pos);
}

void MaxQPushButton::defaultnextCheckState() {
	QPushButton::nextCheckState();
}

// QWidget
void MaxQPushButton::defaultactionEvent(QActionEvent * event){
	QPushButton::actionEvent(event);
}

void MaxQPushButton::defaultchangeEvent(QEvent * event){
	QPushButton::changeEvent(event);
}

void MaxQPushButton::defaultcloseEvent(QCloseEvent * event){
	QPushButton::closeEvent(event);
}

void MaxQPushButton::defaultcontextMenuEvent(QContextMenuEvent * event){
	QPushButton::contextMenuEvent(event);
}

void MaxQPushButton::defaultdragEnterEvent(QDragEnterEvent * event){
	QPushButton::dragEnterEvent(event);
}

void MaxQPushButton::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QPushButton::dragLeaveEvent(event);
}

void MaxQPushButton::defaultdragMoveEvent(QDragMoveEvent * event){
	QPushButton::dragMoveEvent(event);
}

void MaxQPushButton::defaultdropEvent(QDropEvent * event){
	QPushButton::dropEvent(event);
}

void MaxQPushButton::defaultenterEvent(QEvent * event){
	QPushButton::enterEvent(event);
}

void MaxQPushButton::defaultfocusInEvent(QFocusEvent * event){
	QPushButton::focusInEvent(event);
}

bool MaxQPushButton::defaultfocusNextChild() {
	return QPushButton::focusNextChild();
}

bool MaxQPushButton::defaultfocusNextPrevChild(bool next){
	return QPushButton::focusNextPrevChild(next);
}

void MaxQPushButton::defaultfocusOutEvent(QFocusEvent * event){
	QPushButton::focusOutEvent(event);
}

bool MaxQPushButton::defaultfocusPreviousChild() {
	return QPushButton::focusPreviousChild();
}

void MaxQPushButton::defaulthideEvent(QHideEvent * event){
	QPushButton::hideEvent(event);
}

void MaxQPushButton::defaultinputMethodEvent(QInputMethodEvent * event){
	QPushButton::inputMethodEvent(event);
}

void MaxQPushButton::defaultkeyPressEvent(QKeyEvent * event){
	QPushButton::keyPressEvent(event);
}

void MaxQPushButton::defaultkeyReleaseEvent(QKeyEvent * event){
	QPushButton::keyReleaseEvent(event);
}

void MaxQPushButton::defaultleaveEvent(QEvent * event){
	QPushButton::leaveEvent(event);
}

void MaxQPushButton::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QPushButton::mouseDoubleClickEvent(event);
}

void MaxQPushButton::defaultmouseMoveEvent(QMouseEvent * event){
	QPushButton::mouseMoveEvent(event);
}

void MaxQPushButton::defaultmousePressEvent(QMouseEvent * event){
	QPushButton::mousePressEvent(event);
}

void MaxQPushButton::defaultmouseReleaseEvent(QMouseEvent * event){
	QPushButton::mouseReleaseEvent(event);
}

void MaxQPushButton::defaultmoveEvent(QMoveEvent * event){
	QPushButton::moveEvent(event);
}

void MaxQPushButton::defaultpaintEvent(QPaintEvent * event){
	QPushButton::paintEvent(event);
}

void MaxQPushButton::defaultresizeEvent(QResizeEvent * event){
	QPushButton::resizeEvent(event);
}

void MaxQPushButton::defaultshowEvent(QShowEvent * event){
	QPushButton::showEvent(event);
}

void MaxQPushButton::defaulttabletEvent(QTabletEvent * event){
	QPushButton::tabletEvent(event);
}

void MaxQPushButton::defaultwheelEvent(QWheelEvent * event){
	QPushButton::wheelEvent(event);
}

// QObject
bool MaxQPushButton::defaultevent(QEvent * event){
	return QPushButton::event(event);
}

void MaxQPushButton::defaulttimerEvent(QTimerEvent * event){
	QPushButton::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QPushButton

// QAbstractButton
void MaxQPushButton::checkStateSet() {
	_qt_qabstractbutton_QAbstractButton__checkStateSet(maxHandle);
}

bool MaxQPushButton::hitButton(const QPoint & pos) const {
	return static_cast<bool>(_qt_qabstractbutton_QAbstractButton__hitButton(maxHandle, pos.x(), pos.y()));
}

void MaxQPushButton::nextCheckState() {
	_qt_qabstractbutton_QAbstractButton__nextCheckState(maxHandle);
}

// QWidget

void MaxQPushButton::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQPushButton::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQPushButton::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQPushButton::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQPushButton::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQPushButton::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQPushButton::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQPushButton::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQPushButton::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQPushButton::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQPushButton::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQPushButton::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQPushButton::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQPushButton::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQPushButton::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQPushButton::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQPushButton::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQPushButton::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQPushButton::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQPushButton::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQPushButton::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQPushButton::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQPushButton::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}

void MaxQPushButton::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQPushButton::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQPushButton::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQPushButton::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQPushButton::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQPushButton::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQPushButton::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQPushButton::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QPushButton

// QAbstractButton
void bmx_qt_qpushbutton_default_checkstateset(MaxQPushButton * button) {
	button->defaultcheckStateSet();
}

int bmx_qt_qpushbutton_default_hitbutton(MaxQPushButton * button, int x, int y) {
	return static_cast<int>(button->defaulthitButton(QPoint(x, y)));
}

void bmx_qt_qpushbutton_default_nextcheckstate(MaxQPushButton * button) {
	button->defaultnextCheckState();
}

// QWidget
void bmx_qt_qpushbutton_default_actionevent(MaxQPushButton * button, QActionEvent * event) {
	button->defaultactionEvent(event);
}

void bmx_qt_qpushbutton_default_changeevent(MaxQPushButton * button, QEvent * event) {
	button->defaultchangeEvent(event);
}

void bmx_qt_qpushbutton_default_closeevent(MaxQPushButton * button, QCloseEvent * event) {
	button->defaultcloseEvent(event);
}

void bmx_qt_qpushbutton_default_contextmenuevent(MaxQPushButton * button, QContextMenuEvent * event) {
	button->defaultcontextMenuEvent(event);
}

void bmx_qt_qpushbutton_default_dragenterevent(MaxQPushButton * button, QDragEnterEvent * event) {
	button->defaultdragEnterEvent(event);
}

void bmx_qt_qpushbutton_default_dragleaveevent(MaxQPushButton * button, QDragLeaveEvent * event) {
	button->defaultdragLeaveEvent(event);
}

void bmx_qt_qpushbutton_default_dragmoveevent(MaxQPushButton * button, QDragMoveEvent * event) {
	button->defaultdragMoveEvent(event);
}

void bmx_qt_qpushbutton_default_dropevent(MaxQPushButton * button, QDropEvent * event) {
	button->defaultdropEvent(event);
}

void bmx_qt_qpushbutton_default_enterevent(MaxQPushButton * button, QEvent * event) {
	button->defaultenterEvent(event);
}

void bmx_qt_qpushbutton_default_focusinevent(MaxQPushButton * button, QFocusEvent * event) {
	button->defaultfocusInEvent(event);
}

int bmx_qt_qpushbutton_default_focusnextprevchild(MaxQPushButton * button, int next) {
	return static_cast<int>(button->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qpushbutton_default_focusnextchild(MaxQPushButton * button) {
	return static_cast<int>(button->defaultfocusNextChild());
}

void bmx_qt_qpushbutton_default_focusoutevent(MaxQPushButton * button, QFocusEvent * event) {
	button->defaultfocusOutEvent(event);
}

int bmx_qt_qpushbutton_default_focuspreviouschild(MaxQPushButton * button) {
	return static_cast<int>(button->defaultfocusPreviousChild());
}

void bmx_qt_qpushbutton_default_hideevent(MaxQPushButton * button, QHideEvent * event) {
	button->defaulthideEvent(event);
}

void bmx_qt_qpushbutton_default_inputmethodevent(MaxQPushButton * button, QInputMethodEvent * event) {
	button->defaultinputMethodEvent(event);
}

void bmx_qt_qpushbutton_default_keypressevent(MaxQPushButton * button, QKeyEvent * event) {
	button->defaultkeyPressEvent(event);
}

void bmx_qt_qpushbutton_default_keyreleaseevent(MaxQPushButton * button, QKeyEvent * event) {
	button->defaultkeyReleaseEvent(event);
}

void bmx_qt_qpushbutton_default_leaveevent(MaxQPushButton * button, QEvent * event) {
	button->defaultleaveEvent(event);
}

void bmx_qt_qpushbutton_default_mousedoubleclickevent(MaxQPushButton * button, QMouseEvent * event) {
	button->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qpushbutton_default_mousemoveevent(MaxQPushButton * button, QMouseEvent * event) {
	button->defaultmouseMoveEvent(event);
}

void bmx_qt_qpushbutton_default_mousepressevent(MaxQPushButton * button, QMouseEvent * event) {
	button->defaultmousePressEvent(event);
}

void bmx_qt_qpushbutton_default_mousereleaseevent(MaxQPushButton * button, QMouseEvent * event) {
	button->defaultmouseReleaseEvent(event);
}

void bmx_qt_qpushbutton_default_moveevent(MaxQPushButton * button, QMoveEvent * event) {
	button->defaultmoveEvent(event);
}

void bmx_qt_qpushbutton_default_paintevent(MaxQPushButton * button, QPaintEvent * event) {
	button->defaultpaintEvent(event);
}

void bmx_qt_qpushbutton_default_resizeevent(MaxQPushButton * button, QResizeEvent * event) {
	button->defaultresizeEvent(event);
}

void bmx_qt_qpushbutton_default_showevent(MaxQPushButton * button, QShowEvent * event) {
	button->defaultshowEvent(event);
}

void bmx_qt_qpushbutton_default_tabletevent(MaxQPushButton * button, QTabletEvent * event) {
	button->defaulttabletEvent(event);
}

void bmx_qt_qpushbutton_default_wheelevent(MaxQPushButton * button, QWheelEvent * event) {
	button->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qpushbutton_default_event(MaxQPushButton * button, QEvent * event) {
	return static_cast<int>(button->defaultevent(event));
}

void bmx_qt_qpushbutton_default_timerevent(MaxQPushButton * button, QTimerEvent * event) {
	button->defaulttimerEvent(event);
}

// *********************************************

QPushButton * bmx_qt_qpushbutton_create(BBObject * handle, BBString * text, QWidget * parent) {
	return new MaxQPushButton(handle, qStringFromBBString(text), parent);
}

int bmx_qt_qpushbutton_autodefault(QPushButton * button) {
	return static_cast<int>(button->autoDefault());
}

int bmx_qt_qpushbutton_isdefault(QPushButton * button) {
	return static_cast<int>(button->isDefault());
}

int bmx_qt_qpushbutton_isflat(QPushButton * button) {
	return static_cast<int>(button->isFlat());
}

QMenu * bmx_qt_qpushbutton_menu(QPushButton * button) {
	return button->menu();
}

void bmx_qt_qpushbutton_setautodefault(QPushButton * button, int value) {
	button->setAutoDefault(static_cast<bool>(value));
}

void bmx_qt_qpushbutton_setdefault(QPushButton * button, int value) {
	button->setDefault(static_cast<bool>(value));
}

void bmx_qt_qpushbutton_setflat(QPushButton * button, int value) {
	button->setFlat(static_cast<bool>(value));
}

void bmx_qt_qpushbutton_setmenu(QPushButton * button, QMenu * menu) {
	button->setMenu(menu);
}

void bmx_qt_qpushbutton_showmenu(QPushButton * button) {
	button->showMenu();
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
