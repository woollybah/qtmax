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

MaxQGLWidget::MaxQGLWidget(BBObject * handle, QGLContext * context, QWidget * parent, QGLWidget * shareWidget, Qt::WindowFlags flags)
	: maxHandle(handle), QGLWidget(context, parent, shareWidget, flags)
{
	qbind(this, handle);
}

MaxQGLWidget::~MaxQGLWidget()
{
	qunbind(this);
}


// ****************** DEFAULT HANDLERS ********************

// QGLWidget
void MaxQGLWidget::defaultglDraw() {
	QGLWidget::glDraw();
}

void MaxQGLWidget::defaultglInit() {
	QGLWidget::glInit();
}

void MaxQGLWidget::defaultinitializeGL() {
	QGLWidget::initializeGL();
}

void MaxQGLWidget::defaultinitializeOverlayGL() {
	QGLWidget::initializeOverlayGL();
}

void MaxQGLWidget::defaultpaintGL() {
	QGLWidget::paintGL();
}

void MaxQGLWidget::defaultpaintOverlayGL() {
	QGLWidget::paintOverlayGL();
}

void MaxQGLWidget::defaultresizeGL(int width, int height) {
	QGLWidget::resizeGL(width, height);
}

void MaxQGLWidget::defaultresizeOverlayGL(int width, int height) {
	QGLWidget::resizeOverlayGL(width, height);
}

// QWidget
void MaxQGLWidget::defaultactionEvent(QActionEvent * event){
	QGLWidget::actionEvent(event);
}

void MaxQGLWidget::defaultchangeEvent(QEvent * event){
	QGLWidget::changeEvent(event);
}

void MaxQGLWidget::defaultcloseEvent(QCloseEvent * event){
	QGLWidget::closeEvent(event);
}

void MaxQGLWidget::defaultcontextMenuEvent(QContextMenuEvent * event){
	QGLWidget::contextMenuEvent(event);
}

void MaxQGLWidget::defaultdragEnterEvent(QDragEnterEvent * event){
	QGLWidget::dragEnterEvent(event);
}

void MaxQGLWidget::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QGLWidget::dragLeaveEvent(event);
}

void MaxQGLWidget::defaultdragMoveEvent(QDragMoveEvent * event){
	QGLWidget::dragMoveEvent(event);
}

void MaxQGLWidget::defaultdropEvent(QDropEvent * event){
	QGLWidget::dropEvent(event);
}

void MaxQGLWidget::defaultenterEvent(QEvent * event){
	QGLWidget::enterEvent(event);
}

void MaxQGLWidget::defaultfocusInEvent(QFocusEvent * event){
	QGLWidget::focusInEvent(event);
}

bool MaxQGLWidget::defaultfocusNextChild() {
	return QGLWidget::focusNextChild();
}

bool MaxQGLWidget::defaultfocusNextPrevChild(bool next){
	return QGLWidget::focusNextPrevChild(next);
}

void MaxQGLWidget::defaultfocusOutEvent(QFocusEvent * event){
	QGLWidget::focusOutEvent(event);
}

bool MaxQGLWidget::defaultfocusPreviousChild() {
	return QGLWidget::focusPreviousChild();
}

void MaxQGLWidget::defaulthideEvent(QHideEvent * event){
	QGLWidget::hideEvent(event);
}

void MaxQGLWidget::defaultinputMethodEvent(QInputMethodEvent * event){
	QGLWidget::inputMethodEvent(event);
}

void MaxQGLWidget::defaultkeyPressEvent(QKeyEvent * event){
	QGLWidget::keyPressEvent(event);
}

void MaxQGLWidget::defaultkeyReleaseEvent(QKeyEvent * event){
	QGLWidget::keyReleaseEvent(event);
}

void MaxQGLWidget::defaultleaveEvent(QEvent * event){
	QGLWidget::leaveEvent(event);
}

void MaxQGLWidget::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QGLWidget::mouseDoubleClickEvent(event);
}

void MaxQGLWidget::defaultmouseMoveEvent(QMouseEvent * event){
	QGLWidget::mouseMoveEvent(event);
}

void MaxQGLWidget::defaultmousePressEvent(QMouseEvent * event){
	QGLWidget::mousePressEvent(event);
}

void MaxQGLWidget::defaultmouseReleaseEvent(QMouseEvent * event){
	QGLWidget::mouseReleaseEvent(event);
}

void MaxQGLWidget::defaultmoveEvent(QMoveEvent * event){
	QGLWidget::moveEvent(event);
}

void MaxQGLWidget::defaultpaintEvent(QPaintEvent * event){
	QGLWidget::paintEvent(event);
}

void MaxQGLWidget::defaultresizeEvent(QResizeEvent * event){
	QGLWidget::resizeEvent(event);
}

void MaxQGLWidget::defaultshowEvent(QShowEvent * event){
	QGLWidget::showEvent(event);
}

void MaxQGLWidget::defaulttabletEvent(QTabletEvent * event){
	QGLWidget::tabletEvent(event);
}

void MaxQGLWidget::defaultwheelEvent(QWheelEvent * event){
	QGLWidget::wheelEvent(event);
}

// QObject
bool MaxQGLWidget::defaultevent(QEvent * event){
	return QGLWidget::event(event);
}

void MaxQGLWidget::defaulttimerEvent(QTimerEvent * event){
	QGLWidget::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QGLWidget
void MaxQGLWidget::glDraw() {
	_qt_qglwidget_QGLWidget__glDraw(maxHandle);
}

void MaxQGLWidget::glInit() {
	_qt_qglwidget_QGLWidget__glInit(maxHandle);
}

void MaxQGLWidget::initializeGL() {
	_qt_qglwidget_QGLWidget__initializeGL(maxHandle);
}

void MaxQGLWidget::initializeOverlayGL() {
	_qt_qglwidget_QGLWidget__initializeOverlayGL(maxHandle);
}

void MaxQGLWidget::paintGL() {
	_qt_qglwidget_QGLWidget__paintGL(maxHandle);
}

void MaxQGLWidget::paintOverlayGL() {
	_qt_qglwidget_QGLWidget__paintOverlayGL(maxHandle);
}

void MaxQGLWidget::resizeGL(int width, int height) {
	_qt_qglwidget_QGLWidget__resizeGL(maxHandle, width, height);
}

void MaxQGLWidget::resizeOverlayGL(int width, int height) {
	_qt_qglwidget_QGLWidget__resizeOverlayGL(maxHandle, width, height);
}

// QWidget
void MaxQGLWidget::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQGLWidget::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQGLWidget::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQGLWidget::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQGLWidget::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQGLWidget::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQGLWidget::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQGLWidget::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQGLWidget::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQGLWidget::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQGLWidget::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQGLWidget::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQGLWidget::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQGLWidget::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQGLWidget::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQGLWidget::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQGLWidget::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQGLWidget::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQGLWidget::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQGLWidget::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQGLWidget::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQGLWidget::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQGLWidget::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}

void MaxQGLWidget::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQGLWidget::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQGLWidget::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQGLWidget::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQGLWidget::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQGLWidget::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQGLWidget::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQGLWidget::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QGLWidget
void bmx_qt_qglwidget_default_gldraw(MaxQGLWidget * widget) {
	widget->defaultglDraw();
}

void bmx_qt_qglwidget_default_glinit(MaxQGLWidget * widget) {
	widget->defaultglInit();
}

void bmx_qt_qglwidget_default_initializegl(MaxQGLWidget * widget) {
	widget->defaultinitializeGL();
}

void bmx_qt_qglwidget_default_initializeoverlaygl(MaxQGLWidget * widget) {
	widget->defaultinitializeOverlayGL();
}

void bmx_qt_qglwidget_default_paintgl(MaxQGLWidget * widget) {
	widget->defaultpaintGL();
}

void bmx_qt_qglwidget_default_paintoverlaygl(MaxQGLWidget * widget) {
	widget->defaultpaintOverlayGL();
}

void bmx_qt_qglwidget_default_resizegl(MaxQGLWidget * widget, int width, int height) {
	widget->defaultresizeGL(width, height);
}

void bmx_qt_qglwidget_default_resizeoverlaygl(MaxQGLWidget * widget, int width, int height) {
	widget->defaultresizeOverlayGL(width, height);
}


// QWidget
void bmx_qt_qglwidget_default_actionevent(MaxQGLWidget * widget, QActionEvent * event) {
	widget->defaultactionEvent(event);
}

void bmx_qt_qglwidget_default_changeevent(MaxQGLWidget * widget, QEvent * event) {
	widget->defaultchangeEvent(event);
}

void bmx_qt_qglwidget_default_closeevent(MaxQGLWidget * widget, QCloseEvent * event) {
	widget->defaultcloseEvent(event);
}

void bmx_qt_qglwidget_default_contextmenuevent(MaxQGLWidget * widget, QContextMenuEvent * event) {
	widget->defaultcontextMenuEvent(event);
}

void bmx_qt_qglwidget_default_dragenterevent(MaxQGLWidget * widget, QDragEnterEvent * event) {
	widget->defaultdragEnterEvent(event);
}

void bmx_qt_qglwidget_default_dragleaveevent(MaxQGLWidget * widget, QDragLeaveEvent * event) {
	widget->defaultdragLeaveEvent(event);
}

void bmx_qt_qglwidget_default_dragmoveevent(MaxQGLWidget * widget, QDragMoveEvent * event) {
	widget->defaultdragMoveEvent(event);
}

void bmx_qt_qglwidget_default_dropevent(MaxQGLWidget * widget, QDropEvent * event) {
	widget->defaultdropEvent(event);
}

void bmx_qt_qglwidget_default_enterevent(MaxQGLWidget * widget, QEvent * event) {
	widget->defaultenterEvent(event);
}

void bmx_qt_qglwidget_default_focusinevent(MaxQGLWidget * widget, QFocusEvent * event) {
	widget->defaultfocusInEvent(event);
}

int bmx_qt_qglwidget_default_focusnextprevchild(MaxQGLWidget * widget, int next) {
	return static_cast<int>(widget->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qglwidget_default_focusnextchild(MaxQGLWidget * widget) {
	return static_cast<int>(widget->defaultfocusNextChild());
}

void bmx_qt_qglwidget_default_focusoutevent(MaxQGLWidget * widget, QFocusEvent * event) {
	widget->defaultfocusOutEvent(event);
}

int bmx_qt_qglwidget_default_focuspreviouschild(MaxQGLWidget * widget) {
	return static_cast<int>(widget->defaultfocusPreviousChild());
}

void bmx_qt_qglwidget_default_hideevent(MaxQGLWidget * widget, QHideEvent * event) {
	widget->defaulthideEvent(event);
}

void bmx_qt_qglwidget_default_inputmethodevent(MaxQGLWidget * widget, QInputMethodEvent * event) {
	widget->defaultinputMethodEvent(event);
}

void bmx_qt_qglwidget_default_keypressevent(MaxQGLWidget * widget, QKeyEvent * event) {
	widget->defaultkeyPressEvent(event);
}

void bmx_qt_qglwidget_default_keyreleaseevent(MaxQGLWidget * widget, QKeyEvent * event) {
	widget->defaultkeyReleaseEvent(event);
}

void bmx_qt_qglwidget_default_leaveevent(MaxQGLWidget * widget, QEvent * event) {
	widget->defaultleaveEvent(event);
}

void bmx_qt_qglwidget_default_mousedoubleclickevent(MaxQGLWidget * widget, QMouseEvent * event) {
	widget->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qglwidget_default_mousemoveevent(MaxQGLWidget * widget, QMouseEvent * event) {
	widget->defaultmouseMoveEvent(event);
}

void bmx_qt_qglwidget_default_mousepressevent(MaxQGLWidget * widget, QMouseEvent * event) {
	widget->defaultmousePressEvent(event);
}

void bmx_qt_qglwidget_default_mousereleaseevent(MaxQGLWidget * widget, QMouseEvent * event) {
	widget->defaultmouseReleaseEvent(event);
}

void bmx_qt_qglwidget_default_moveevent(MaxQGLWidget * widget, QMoveEvent * event) {
	widget->defaultmoveEvent(event);
}

void bmx_qt_qglwidget_default_paintevent(MaxQGLWidget * widget, QPaintEvent * event) {
	widget->defaultpaintEvent(event);
}

void bmx_qt_qglwidget_default_resizeevent(MaxQGLWidget * widget, QResizeEvent * event) {
	widget->defaultresizeEvent(event);
}

void bmx_qt_qglwidget_default_showevent(MaxQGLWidget * widget, QShowEvent * event) {
	widget->defaultshowEvent(event);
}

void bmx_qt_qglwidget_default_tabletevent(MaxQGLWidget * widget, QTabletEvent * event) {
	widget->defaulttabletEvent(event);
}

void bmx_qt_qglwidget_default_wheelevent(MaxQGLWidget * widget, QWheelEvent * event) {
	widget->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qglwidget_default_event(MaxQGLWidget * widget, QEvent * event) {
	return static_cast<int>(widget->defaultevent(event));
}

void bmx_qt_qglwidget_default_timerevent(MaxQGLWidget * widget, QTimerEvent * event) {
	widget->defaulttimerEvent(event);
}


// *********************************************



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
