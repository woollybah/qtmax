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

MaxQFrame::MaxQFrame(BBObject * handle, QWidget * parent, Qt::WindowFlags flags)
	: maxHandle(handle), QFrame(parent, flags)
{
	qbind(this, handle);
}

MaxQFrame::~MaxQFrame()
{
	qunbind(this);
}


// ****************** DEFAULT HANDLERS ********************

// QFrame

// QWidget
void MaxQFrame::defaultactionEvent(QActionEvent * event){
	QFrame::actionEvent(event);
}

void MaxQFrame::defaultchangeEvent(QEvent * event){
	QFrame::changeEvent(event);
}

void MaxQFrame::defaultcloseEvent(QCloseEvent * event){
	QFrame::closeEvent(event);
}

void MaxQFrame::defaultcontextMenuEvent(QContextMenuEvent * event){
	QFrame::contextMenuEvent(event);
}

void MaxQFrame::defaultdragEnterEvent(QDragEnterEvent * event){
	QFrame::dragEnterEvent(event);
}

void MaxQFrame::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QFrame::dragLeaveEvent(event);
}

void MaxQFrame::defaultdragMoveEvent(QDragMoveEvent * event){
	QFrame::dragMoveEvent(event);
}

void MaxQFrame::defaultdropEvent(QDropEvent * event){
	QFrame::dropEvent(event);
}

void MaxQFrame::defaultenterEvent(QEvent * event){
	QFrame::enterEvent(event);
}

void MaxQFrame::defaultfocusInEvent(QFocusEvent * event){
	QFrame::focusInEvent(event);
}

bool MaxQFrame::defaultfocusNextChild() {
	return QFrame::focusNextChild();
}

bool MaxQFrame::defaultfocusNextPrevChild(bool next){
	return QFrame::focusNextPrevChild(next);
}

void MaxQFrame::defaultfocusOutEvent(QFocusEvent * event){
	QFrame::focusOutEvent(event);
}

bool MaxQFrame::defaultfocusPreviousChild() {
	return QFrame::focusPreviousChild();
}

void MaxQFrame::defaulthideEvent(QHideEvent * event){
	QFrame::hideEvent(event);
}

void MaxQFrame::defaultinputMethodEvent(QInputMethodEvent * event){
	QFrame::inputMethodEvent(event);
}

void MaxQFrame::defaultkeyPressEvent(QKeyEvent * event){
	QFrame::keyPressEvent(event);
}

void MaxQFrame::defaultkeyReleaseEvent(QKeyEvent * event){
	QFrame::keyReleaseEvent(event);
}

void MaxQFrame::defaultleaveEvent(QEvent * event){
	QFrame::leaveEvent(event);
}

void MaxQFrame::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QFrame::mouseDoubleClickEvent(event);
}

void MaxQFrame::defaultmouseMoveEvent(QMouseEvent * event){
	QFrame::mouseMoveEvent(event);
}

void MaxQFrame::defaultmousePressEvent(QMouseEvent * event){
	QFrame::mousePressEvent(event);
}

void MaxQFrame::defaultmouseReleaseEvent(QMouseEvent * event){
	QFrame::mouseReleaseEvent(event);
}

void MaxQFrame::defaultmoveEvent(QMoveEvent * event){
	QFrame::moveEvent(event);
}

void MaxQFrame::defaultpaintEvent(QPaintEvent * event){
	QFrame::paintEvent(event);
}

void MaxQFrame::defaultresizeEvent(QResizeEvent * event){
	QFrame::resizeEvent(event);
}

void MaxQFrame::defaultshowEvent(QShowEvent * event){
	QFrame::showEvent(event);
}

void MaxQFrame::defaulttabletEvent(QTabletEvent * event){
	QFrame::tabletEvent(event);
}

void MaxQFrame::defaultwheelEvent(QWheelEvent * event){
	QFrame::wheelEvent(event);
}

// QObject
bool MaxQFrame::defaultevent(QEvent * event){
	return QFrame::event(event);
}

void MaxQFrame::defaulttimerEvent(QTimerEvent * event){
	QFrame::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************


// QWidget
void MaxQFrame::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQFrame::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQFrame::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQFrame::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQFrame::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQFrame::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQFrame::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQFrame::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQFrame::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQFrame::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQFrame::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQFrame::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQFrame::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQFrame::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQFrame::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQFrame::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQFrame::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQFrame::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQFrame::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQFrame::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQFrame::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQFrame::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQFrame::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQFrame::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQFrame::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQFrame::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQFrame::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQFrame::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQFrame::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQFrame::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQFrame::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QFrame
// QWidget
void bmx_qt_qframe_default_actionevent(MaxQFrame * frame, QActionEvent * event) {
	frame->defaultactionEvent(event);
}

void bmx_qt_qframe_default_changeevent(MaxQFrame * frame, QEvent * event) {
	frame->defaultchangeEvent(event);
}

void bmx_qt_qframe_default_closeevent(MaxQFrame * frame, QCloseEvent * event) {
	frame->defaultcloseEvent(event);
}

void bmx_qt_qframe_default_contextmenuevent(MaxQFrame * frame, QContextMenuEvent * event) {
	frame->defaultcontextMenuEvent(event);
}

void bmx_qt_qframe_default_dragenterevent(MaxQFrame * frame, QDragEnterEvent * event) {
	frame->defaultdragEnterEvent(event);
}

void bmx_qt_qframe_default_dragleaveevent(MaxQFrame * frame, QDragLeaveEvent * event) {
	frame->defaultdragLeaveEvent(event);
}

void bmx_qt_qframe_default_dragmoveevent(MaxQFrame * frame, QDragMoveEvent * event) {
	frame->defaultdragMoveEvent(event);
}

void bmx_qt_qframe_default_dropevent(MaxQFrame * frame, QDropEvent * event) {
	frame->defaultdropEvent(event);
}

void bmx_qt_qframe_default_enterevent(MaxQFrame * frame, QEvent * event) {
	frame->defaultenterEvent(event);
}

void bmx_qt_qframe_default_focusinevent(MaxQFrame * frame, QFocusEvent * event) {
	frame->defaultfocusInEvent(event);
}

int bmx_qt_qframe_default_focusnextprevchild(MaxQFrame * frame, int next) {
	return static_cast<int>(frame->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qframe_default_focusnextchild(MaxQFrame * frame) {
	return static_cast<int>(frame->defaultfocusNextChild());
}

void bmx_qt_qframe_default_focusoutevent(MaxQFrame * frame, QFocusEvent * event) {
	frame->defaultfocusOutEvent(event);
}

int bmx_qt_qframe_default_focuspreviouschild(MaxQFrame * frame) {
	return static_cast<int>(frame->defaultfocusPreviousChild());
}

void bmx_qt_qframe_default_hideevent(MaxQFrame * frame, QHideEvent * event) {
	frame->defaulthideEvent(event);
}

void bmx_qt_qframe_default_inputmethodevent(MaxQFrame * frame, QInputMethodEvent * event) {
	frame->defaultinputMethodEvent(event);
}

void bmx_qt_qframe_default_keypressevent(MaxQFrame * frame, QKeyEvent * event) {
	frame->defaultkeyPressEvent(event);
}

void bmx_qt_qframe_default_keyreleaseevent(MaxQFrame * frame, QKeyEvent * event) {
	frame->defaultkeyReleaseEvent(event);
}

void bmx_qt_qframe_default_leaveevent(MaxQFrame * frame, QEvent * event) {
	frame->defaultleaveEvent(event);
}

void bmx_qt_qframe_default_mousedoubleclickevent(MaxQFrame * frame, QMouseEvent * event) {
	frame->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qframe_default_mousemoveevent(MaxQFrame * frame, QMouseEvent * event) {
	frame->defaultmouseMoveEvent(event);
}

void bmx_qt_qframe_default_mousepressevent(MaxQFrame * frame, QMouseEvent * event) {
	frame->defaultmousePressEvent(event);
}

void bmx_qt_qframe_default_mousereleaseevent(MaxQFrame * frame, QMouseEvent * event) {
	frame->defaultmouseReleaseEvent(event);
}

void bmx_qt_qframe_default_moveevent(MaxQFrame * frame, QMoveEvent * event) {
	frame->defaultmoveEvent(event);
}

void bmx_qt_qframe_default_paintevent(MaxQFrame * frame, QPaintEvent * event) {
	frame->defaultpaintEvent(event);
}

void bmx_qt_qframe_default_resizeevent(MaxQFrame * frame, QResizeEvent * event) {
	frame->defaultresizeEvent(event);
}

void bmx_qt_qframe_default_showevent(MaxQFrame * frame, QShowEvent * event) {
	frame->defaultshowEvent(event);
}

void bmx_qt_qframe_default_tabletevent(MaxQFrame * frame, QTabletEvent * event) {
	frame->defaulttabletEvent(event);
}

void bmx_qt_qframe_default_wheelevent(MaxQFrame * frame, QWheelEvent * event) {
	frame->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qframe_default_event(MaxQFrame * frame, QEvent * event) {
	return static_cast<int>(frame->defaultevent(event));
}

void bmx_qt_qframe_default_timerevent(MaxQFrame * frame, QTimerEvent * event) {
	frame->defaulttimerEvent(event);
}


// *********************************************

QFrame * bmx_qt_qframe_create(BBObject * handle, QWidget * parent, int flags) {
	return new MaxQFrame(handle, parent, bmx_qt_getwindowflags(flags));
}

void bmx_qt_qframe_framerect(QFrame * frame, int * x, int * y, int * w, int * h) {
	QRect r(frame->frameRect());
	*x = r.x();
	*y = r.y();
	*w = r.width();
	*h = r.height();
}

int bmx_qt_qframe_frameshadow(QFrame * frame) {
	return frame->frameShadow();
}

int bmx_qt_qframe_frameshape(QFrame * frame) {
	return frame->frameShape();
}

int bmx_qt_qframe_framestyle(QFrame * frame) {
	return frame->frameStyle();
}

int bmx_qt_qframe_framewidth(QFrame * frame) {
	return frame->frameWidth();
}

int bmx_qt_qframe_linewidth(QFrame * frame) {
	return frame->lineWidth();
}

int bmx_qt_qframe_midlinewidth(QFrame * frame) {
	return frame->midLineWidth();
}

void bmx_qt_qframe_setframerect(QFrame * frame, int x, int y, int w, int h) {
	frame->setFrameRect(QRect(x, y, w, h));
}

void bmx_qt_qframe_setframeshadow(QFrame * frame, int shadow) {
	QFrame::Shadow s;
	
	switch(shadow) {
		case 0x0010:
			s = QFrame::Plain;
			break;
		case 0x0020:
			s = QFrame::Raised;
			break;
		case 0x0030:
			s = QFrame::Sunken;
			break;
		default:
			s = QFrame::Plain;
	}
	
	frame->setFrameShadow(s);
}

void bmx_qt_qframe_setframeshape(QFrame * frame, int shape) {
	QFrame::Shape s;
	
	switch(shape) {
		case 0:
			s = QFrame::NoFrame;
			break;
		case 0x0001:
			s = QFrame::Box;
			break;
		case 0x0002:
			s = QFrame::Panel;
			break;
		case 0x0006:
			s = QFrame::StyledPanel;
			break;
		case 0x0004:
			s = QFrame::HLine;
			break;
		case 0x0005:
			s = QFrame::VLine;
			break;
		case 0x0003:
			s = QFrame::WinPanel;
			break;
		default:
			s = QFrame::NoFrame;
	}
			
	frame->setFrameShape(s);
}

void bmx_qt_qframe_setframestyle(QFrame * frame, int style) {
	frame->setFrameStyle(style);
}

void bmx_qt_qframe_setlinewidth(QFrame * frame, int width) {
	frame->setLineWidth(width);
}

void bmx_qt_qframe_setmidlinewidth(QFrame * frame, int width) {
	frame->setMidLineWidth(width);
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
