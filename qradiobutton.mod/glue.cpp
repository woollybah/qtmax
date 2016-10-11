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

MaxQRadioButton::MaxQRadioButton(BBObject * handle, const QString & text, QWidget * parent)
	: maxHandle(handle), QRadioButton(text, parent)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(clicked(bool)), SLOT(onClicked(bool)));
	connect(this, SIGNAL(pressed()), SLOT(onPressed()));
	connect(this, SIGNAL(released()), SLOT(onReleased()));
	connect(this, SIGNAL(toggled(bool)), SLOT(onToggled(bool)));
}

MaxQRadioButton::~MaxQRadioButton()
{
	qunbind(this);
}

void MaxQRadioButton::onClicked(bool checked) {
	_qt_qradiobutton_QRadioButton__OnClicked(maxHandle, static_cast<int>(checked));
}

void MaxQRadioButton::onPressed() {
	_qt_qradiobutton_QRadioButton__OnPressed(maxHandle);
}

void MaxQRadioButton::onReleased() {
	_qt_qradiobutton_QRadioButton__OnReleased(maxHandle);
}

void MaxQRadioButton::onToggled(bool checked) {
	_qt_qradiobutton_QRadioButton__OnToggled(maxHandle, static_cast<int>(checked));
}

// ****************** DEFAULT HANDLERS ********************

// QRadioButton

// QAbstractButton
void MaxQRadioButton::defaultcheckStateSet() {
	QRadioButton::checkStateSet();
}

bool MaxQRadioButton::defaulthitButton(const QPoint & pos) const{
	return QRadioButton::hitButton(pos);
}

void MaxQRadioButton::defaultnextCheckState() {
	QRadioButton::nextCheckState();
}

// QWidget
void MaxQRadioButton::defaultactionEvent(QActionEvent * event){
	QRadioButton::actionEvent(event);
}

void MaxQRadioButton::defaultchangeEvent(QEvent * event){
	QRadioButton::changeEvent(event);
}

void MaxQRadioButton::defaultcloseEvent(QCloseEvent * event){
	QRadioButton::closeEvent(event);
}

void MaxQRadioButton::defaultcontextMenuEvent(QContextMenuEvent * event){
	QRadioButton::contextMenuEvent(event);
}

void MaxQRadioButton::defaultdragEnterEvent(QDragEnterEvent * event){
	QRadioButton::dragEnterEvent(event);
}

void MaxQRadioButton::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QRadioButton::dragLeaveEvent(event);
}

void MaxQRadioButton::defaultdragMoveEvent(QDragMoveEvent * event){
	QRadioButton::dragMoveEvent(event);
}

void MaxQRadioButton::defaultdropEvent(QDropEvent * event){
	QRadioButton::dropEvent(event);
}

void MaxQRadioButton::defaultenterEvent(QEvent * event){
	QRadioButton::enterEvent(event);
}

void MaxQRadioButton::defaultfocusInEvent(QFocusEvent * event){
	QRadioButton::focusInEvent(event);
}

bool MaxQRadioButton::defaultfocusNextChild() {
	return QRadioButton::focusNextChild();
}

bool MaxQRadioButton::defaultfocusNextPrevChild(bool next){
	return QRadioButton::focusNextPrevChild(next);
}

void MaxQRadioButton::defaultfocusOutEvent(QFocusEvent * event){
	QRadioButton::focusOutEvent(event);
}

bool MaxQRadioButton::defaultfocusPreviousChild() {
	return QRadioButton::focusPreviousChild();
}

void MaxQRadioButton::defaulthideEvent(QHideEvent * event){
	QRadioButton::hideEvent(event);
}

void MaxQRadioButton::defaultinputMethodEvent(QInputMethodEvent * event){
	QRadioButton::inputMethodEvent(event);
}

void MaxQRadioButton::defaultkeyPressEvent(QKeyEvent * event){
	QRadioButton::keyPressEvent(event);
}

void MaxQRadioButton::defaultkeyReleaseEvent(QKeyEvent * event){
	QRadioButton::keyReleaseEvent(event);
}

void MaxQRadioButton::defaultleaveEvent(QEvent * event){
	QRadioButton::leaveEvent(event);
}

void MaxQRadioButton::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QRadioButton::mouseDoubleClickEvent(event);
}

void MaxQRadioButton::defaultmouseMoveEvent(QMouseEvent * event){
	QRadioButton::mouseMoveEvent(event);
}

void MaxQRadioButton::defaultmousePressEvent(QMouseEvent * event){
	QRadioButton::mousePressEvent(event);
}

void MaxQRadioButton::defaultmouseReleaseEvent(QMouseEvent * event){
	QRadioButton::mouseReleaseEvent(event);
}

void MaxQRadioButton::defaultmoveEvent(QMoveEvent * event){
	QRadioButton::moveEvent(event);
}

void MaxQRadioButton::defaultpaintEvent(QPaintEvent * event){
	QRadioButton::paintEvent(event);
}

void MaxQRadioButton::defaultresizeEvent(QResizeEvent * event){
	QRadioButton::resizeEvent(event);
}

void MaxQRadioButton::defaultshowEvent(QShowEvent * event){
	QRadioButton::showEvent(event);
}

void MaxQRadioButton::defaulttabletEvent(QTabletEvent * event){
	QRadioButton::tabletEvent(event);
}

void MaxQRadioButton::defaultwheelEvent(QWheelEvent * event){
	QRadioButton::wheelEvent(event);
}

// QObject
bool MaxQRadioButton::defaultevent(QEvent * event){
	return QRadioButton::event(event);
}

void MaxQRadioButton::defaulttimerEvent(QTimerEvent * event){
	QRadioButton::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QRadioButton

// QAbstractButton
void MaxQRadioButton::checkStateSet() {
	_qt_qabstractbutton_QAbstractButton__checkStateSet(maxHandle);
}

bool MaxQRadioButton::hitButton(const QPoint & pos) const {
	return static_cast<bool>(_qt_qabstractbutton_QAbstractButton__hitButton(maxHandle, pos.x(), pos.y()));
}

void MaxQRadioButton::nextCheckState() {
	_qt_qabstractbutton_QAbstractButton__nextCheckState(maxHandle);
}

// QWidget
void MaxQRadioButton::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQRadioButton::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQRadioButton::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQRadioButton::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQRadioButton::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQRadioButton::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQRadioButton::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQRadioButton::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQRadioButton::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQRadioButton::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQRadioButton::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQRadioButton::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQRadioButton::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQRadioButton::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQRadioButton::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQRadioButton::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQRadioButton::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQRadioButton::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQRadioButton::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQRadioButton::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQRadioButton::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQRadioButton::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQRadioButton::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQRadioButton::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQRadioButton::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQRadioButton::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQRadioButton::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQRadioButton::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQRadioButton::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQRadioButton::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQRadioButton::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QRadioButton

// QAbstractButton
void bmx_qt_qradiobutton_default_checkstateset(MaxQRadioButton * button) {
	button->defaultcheckStateSet();
}

int bmx_qt_qradiobutton_default_hitbutton(MaxQRadioButton * button, int x, int y) {
	return static_cast<int>(button->defaulthitButton(QPoint(x, y)));
}

void bmx_qt_qradiobutton_default_nextcheckstate(MaxQRadioButton * button) {
	button->defaultnextCheckState();
}

// QWidget
void bmx_qt_qradiobutton_default_actionevent(MaxQRadioButton * button, QActionEvent * event) {
	button->defaultactionEvent(event);
}

void bmx_qt_qradiobutton_default_changeevent(MaxQRadioButton * button, QEvent * event) {
	button->defaultchangeEvent(event);
}

void bmx_qt_qradiobutton_default_closeevent(MaxQRadioButton * button, QCloseEvent * event) {
	button->defaultcloseEvent(event);
}

void bmx_qt_qradiobutton_default_contextmenuevent(MaxQRadioButton * button, QContextMenuEvent * event) {
	button->defaultcontextMenuEvent(event);
}

void bmx_qt_qradiobutton_default_dragenterevent(MaxQRadioButton * button, QDragEnterEvent * event) {
	button->defaultdragEnterEvent(event);
}

void bmx_qt_qradiobutton_default_dragleaveevent(MaxQRadioButton * button, QDragLeaveEvent * event) {
	button->defaultdragLeaveEvent(event);
}

void bmx_qt_qradiobutton_default_dragmoveevent(MaxQRadioButton * button, QDragMoveEvent * event) {
	button->defaultdragMoveEvent(event);
}

void bmx_qt_qradiobutton_default_dropevent(MaxQRadioButton * button, QDropEvent * event) {
	button->defaultdropEvent(event);
}

void bmx_qt_qradiobutton_default_enterevent(MaxQRadioButton * button, QEvent * event) {
	button->defaultenterEvent(event);
}

void bmx_qt_qradiobutton_default_focusinevent(MaxQRadioButton * button, QFocusEvent * event) {
	button->defaultfocusInEvent(event);
}

int bmx_qt_qradiobutton_default_focusnextprevchild(MaxQRadioButton * button, int next) {
	return static_cast<int>(button->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qradiobutton_default_focusnextchild(MaxQRadioButton * button) {
	return static_cast<int>(button->defaultfocusNextChild());
}

void bmx_qt_qradiobutton_default_focusoutevent(MaxQRadioButton * button, QFocusEvent * event) {
	button->defaultfocusOutEvent(event);
}

int bmx_qt_qradiobutton_default_focuspreviouschild(MaxQRadioButton * button) {
	return static_cast<int>(button->defaultfocusPreviousChild());
}

void bmx_qt_qradiobutton_default_hideevent(MaxQRadioButton * button, QHideEvent * event) {
	button->defaulthideEvent(event);
}

void bmx_qt_qradiobutton_default_inputmethodevent(MaxQRadioButton * button, QInputMethodEvent * event) {
	button->defaultinputMethodEvent(event);
}

void bmx_qt_qradiobutton_default_keypressevent(MaxQRadioButton * button, QKeyEvent * event) {
	button->defaultkeyPressEvent(event);
}

void bmx_qt_qradiobutton_default_keyreleaseevent(MaxQRadioButton * button, QKeyEvent * event) {
	button->defaultkeyReleaseEvent(event);
}

void bmx_qt_qradiobutton_default_leaveevent(MaxQRadioButton * button, QEvent * event) {
	button->defaultleaveEvent(event);
}

void bmx_qt_qradiobutton_default_mousedoubleclickevent(MaxQRadioButton * button, QMouseEvent * event) {
	button->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qradiobutton_default_mousemoveevent(MaxQRadioButton * button, QMouseEvent * event) {
	button->defaultmouseMoveEvent(event);
}

void bmx_qt_qradiobutton_default_mousepressevent(MaxQRadioButton * button, QMouseEvent * event) {
	button->defaultmousePressEvent(event);
}

void bmx_qt_qradiobutton_default_mousereleaseevent(MaxQRadioButton * button, QMouseEvent * event) {
	button->defaultmouseReleaseEvent(event);
}

void bmx_qt_qradiobutton_default_moveevent(MaxQRadioButton * button, QMoveEvent * event) {
	button->defaultmoveEvent(event);
}

void bmx_qt_qradiobutton_default_paintevent(MaxQRadioButton * button, QPaintEvent * event) {
	button->defaultpaintEvent(event);
}

void bmx_qt_qradiobutton_default_resizeevent(MaxQRadioButton * button, QResizeEvent * event) {
	button->defaultresizeEvent(event);
}

void bmx_qt_qradiobutton_default_showevent(MaxQRadioButton * button, QShowEvent * event) {
	button->defaultshowEvent(event);
}

void bmx_qt_qradiobutton_default_tabletevent(MaxQRadioButton * button, QTabletEvent * event) {
	button->defaulttabletEvent(event);
}

void bmx_qt_qradiobutton_default_wheelevent(MaxQRadioButton * button, QWheelEvent * event) {
	button->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qradiobutton_default_event(MaxQRadioButton * button, QEvent * event) {
	return static_cast<int>(button->defaultevent(event));
}

void bmx_qt_qradiobutton_default_timerevent(MaxQRadioButton * button, QTimerEvent * event) {
	button->defaulttimerEvent(event);
}

// *********************************************

QRadioButton * bmx_qt_qradiobutton_create(BBObject * handle, BBString * text, QWidget * parent) {
	return new MaxQRadioButton(handle, qStringFromBBString(text), parent);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
