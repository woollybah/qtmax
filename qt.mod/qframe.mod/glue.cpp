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

MaxQFrame::MaxQFrame(BBObject * handle, QWidget * parent, Qt::WindowFlags flags)
	: maxHandle(handle), QFrame(parent, flags)
{
	qbind(this, handle);
}

MaxQFrame::~MaxQFrame()
{
	qunbind(this);
}

void MaxQFrame::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

void MaxQFrame::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseDoubleClickEvent(maxHandle, event);
}

void MaxQFrame::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseMoveEvent(maxHandle, event);
}

void MaxQFrame::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMousePressEvent(maxHandle, event);
}

void MaxQFrame::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseReleaseEvent(maxHandle, event);
}

void MaxQFrame::actionEvent(QActionEvent * event){
	_qt_qwidget_QWidget__OnActionEvent(maxHandle, event);
}

void MaxQFrame::closeEvent(QCloseEvent * event){
	_qt_qwidget_QWidget__OnCloseEvent(maxHandle, event);
}

void MaxQFrame::contextMenuEvent(QContextMenuEvent * event){
	_qt_qwidget_QWidget__OnContextMenuEvent(maxHandle, event);
}

void MaxQFrame::dragEnterEvent(QDragEnterEvent * event){
	_qt_qwidget_QWidget__OnDragEnterEvent(maxHandle, event);
}

void MaxQFrame::dragLeaveEvent(QDragLeaveEvent * event){
	_qt_qwidget_QWidget__OnDragLeaveEvent(maxHandle, event);
}

void MaxQFrame::dragMoveEvent(QDragMoveEvent * event){
	_qt_qwidget_QWidget__OnDragMoveEvent(maxHandle, event);
}

void MaxQFrame::dropEvent(QDropEvent * event){
	_qt_qwidget_QWidget__OnDropEvent(maxHandle, event);
}

void MaxQFrame::enterEvent(QEvent * event){
	_qt_qwidget_QWidget__OnEnterEvent(maxHandle, event);
}

void MaxQFrame::focusInEvent(QFocusEvent * event){
	_qt_qwidget_QWidget__OnFocusInEvent(maxHandle, event);
}

void MaxQFrame::focusOutEvent(QFocusEvent * event){
	_qt_qwidget_QWidget__OnFocusOutEvent(maxHandle, event);
}

void MaxQFrame::hideEvent(QHideEvent * event){
	_qt_qwidget_QWidget__OnHideEvent(maxHandle, event);
}

void MaxQFrame::inputMethodEvent(QInputMethodEvent * event){
	_qt_qwidget_QWidget__OnInputMethodEvent(maxHandle, event);
}

void MaxQFrame::keyPressEvent(QKeyEvent * event){
	_qt_qwidget_QWidget__OnKeyPressEvent(maxHandle, event);
}

void MaxQFrame::keyReleaseEvent(QKeyEvent * event){
	_qt_qwidget_QWidget__OnKeyReleaseEvent(maxHandle, event);
}

void MaxQFrame::leaveEvent(QEvent * event){
	_qt_qwidget_QWidget__OnLeaveEvent(maxHandle, event);
}

void MaxQFrame::moveEvent(QMoveEvent * event){
	_qt_qwidget_QWidget__OnMoveEvent(maxHandle, event);
}

void MaxQFrame::resizeEvent(QResizeEvent * event){
	_qt_qwidget_QWidget__OnResizeEvent(maxHandle, event);
}

void MaxQFrame::showEvent(QShowEvent * event){
	_qt_qwidget_QWidget__OnShowEvent(maxHandle, event);
}

void MaxQFrame::tabletEvent(QTabletEvent * event){
	_qt_qwidget_QWidget__OnTabletEvent(maxHandle, event);
}

void MaxQFrame::wheelEvent(QWheelEvent * event){
	_qt_qwidget_QWidget__OnWheelEvent(maxHandle, event);
}


void MaxQFrame::paintEvent(QPaintEvent * event) {
	_qt_qframe_QFrame__OnPaintEvent(maxHandle, event);
}

void MaxQFrame::changeEvent(QEvent * event){
	_qt_qframe_QFrame__OnChangeEvent(maxHandle, event);
}

bool MaxQFrame::event(QEvent * event){
	return static_cast<bool>(_qt_qframe_QFrame__OnEvent(maxHandle, event));
}


void MaxQFrame::defaultChangeEvent(QEvent * event) {
	QFrame::changeEvent(event);
}

bool MaxQFrame::defaultEvent(QEvent * event) {
	return QFrame::event(event);
}

void MaxQFrame::defaultPaintEvent(QPaintEvent * event) {
	QFrame::paintEvent(event);
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

void bmx_qt_qframe_default_changeevent(MaxQFrame * frame, QEvent * event) {
	frame->defaultChangeEvent(event);
}

int bmx_qt_qframe_default_event(MaxQFrame * frame, QEvent * event) {
	return static_cast<int>(frame->defaultEvent(event));
}

void bmx_qt_qframe_default_paintevent(MaxQFrame * frame, QPaintEvent * event) {
	frame->defaultPaintEvent(event);
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
