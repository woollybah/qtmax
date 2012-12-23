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

MaxQLabel::MaxQLabel(BBObject * handle, const QString & text, QWidget * parent, Qt::WindowFlags flags)
	: maxHandle(handle), QLabel(text, parent, flags)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(linkActivated(const QString & )), SLOT(onLinkActivated(const QString & )));
	connect(this, SIGNAL(linkHovered(const QString & )), SLOT(onLinkHovered(const QString & )));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint & )), SLOT(onCustomContextMenuRequested(const QPoint & )));
}

MaxQLabel::~MaxQLabel()
{
	qunbind(this);
}

void MaxQLabel::onLinkActivated(const QString & link) {
	_qt_qlabel_QLabel__OnLinkActivated(maxHandle, bbStringFromQString(link));
}

void MaxQLabel::onLinkHovered(const QString & link) {
	_qt_qlabel_QLabel__OnLinkHovered(maxHandle, bbStringFromQString(link));
}

void MaxQLabel::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

void MaxQLabel::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

void MaxQLabel::contextMenuEvent(QContextMenuEvent * ev) {
	_qt_qwidget_QWidget__OnContextMenuEvent(maxHandle, ev);
}

void MaxQLabel::focusInEvent(QFocusEvent * ev) {
	_qt_qwidget_QWidget__OnFocusInEvent(maxHandle, ev);
}

bool MaxQLabel::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__OnFocusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQLabel::focusOutEvent(QFocusEvent * ev) {
	_qt_qwidget_QWidget__OnFocusOutEvent(maxHandle, ev);
}

void MaxQLabel::keyPressEvent(QKeyEvent * ev) {
	_qt_qwidget_QWidget__OnKeyPressEvent(maxHandle, ev);
}

void MaxQLabel::mouseMoveEvent(QMouseEvent * ev) {
	_qt_qwidget_QWidget__OnMouseMoveEvent(maxHandle, ev);
}

void MaxQLabel::mousePressEvent(QMouseEvent * ev) {
	_qt_qwidget_QWidget__OnMousePressEvent(maxHandle, ev);
}

void MaxQLabel::mouseReleaseEvent(QMouseEvent * ev) {
	_qt_qwidget_QWidget__OnMouseReleaseEvent(maxHandle, ev);
}

void MaxQLabel::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__OnEnterEvent(maxHandle, event);
}

void MaxQLabel::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__OnLeaveEvent(maxHandle, event);
}


// *********************************************

QLabel * bmx_qt_qlabel_create(BBObject * handle, BBString * text, QWidget * parent, int f) {

	return new MaxQLabel(handle, qStringFromBBString(text), parent, bmx_qt_getwindowflags(f));

}

int bmx_qt_qlabel_alignment(QLabel * label) {
	return label->alignment();
}

QWidget * bmx_qt_qlabel_buddy(QLabel * label) {
	return label->buddy();
}

int bmx_qt_qlabel_hasscaledcontents(QLabel * label) {
	return static_cast<int>(label->hasScaledContents());
}

int bmx_qt_qlabel_indent(QLabel * label) {
	return label->indent();
}

int bmx_qt_qlabel_margin(QLabel * label) {
	return label->margin();
}

int bmx_qt_qlabel_openexternallinks(QLabel * label) {
	return static_cast<int>(label->openExternalLinks());
}

void bmx_qt_qlabel_setalignment(QLabel * label, int alignment) {
	label->setAlignment(bmx_qt_getalignment(alignment));
}

void bmx_qt_qlabel_setbuddy(QLabel * label, QWidget * buddy) {
	label->setBuddy(buddy);
}

void bmx_qt_qlabel_setindent(QLabel * label, int indent) {
	label->setIndent(indent);
}

void bmx_qt_qlabel_setmargin(QLabel * label, int margin) {
	label->setMargin(margin);
}

void bmx_qt_qlabel_setopenexternallinks(QLabel * label, int open) {
	label->setOpenExternalLinks(static_cast<bool>(open));
}

void bmx_qt_qlabel_setscaledcontents(QLabel * label, int scaled) {
	label->setScaledContents(static_cast<bool>(scaled));
}

void bmx_qt_qlabel_settextformat(QLabel * label, int format) {
	label->setTextFormat(bmx_qt_inttotextformat(format));
}

void bmx_qt_qlabel_settextinteractionflags(QLabel * label, int flags) {
	label->setTextInteractionFlags(bmx_qt_inttotextinteractionflags(flags));
}

void bmx_qt_qlabel_setwordwrap(QLabel * label, int value) {
	label->setWordWrap(static_cast<bool>(value));
}

BBString * bmx_qt_qlabel_text(QLabel * label) {
	return bbStringFromQString(label->text());
}

int bmx_qt_qlabel_textformat(QLabel * label) {
	return label->textFormat();
}

int bmx_qt_qlabel_textinteractionflags(QLabel * label) {
	return label->textInteractionFlags();
}

int bmx_qt_qlabel_wordwrap(QLabel * label) {
	return static_cast<int>(label->wordWrap());
}

void bmx_qt_qlabel_clear(QLabel * label) {
	label->clear();
}

void bmx_qt_qlabel_setnum(QLabel * label, int num) {
	label->setNum(num);
}

void bmx_qt_qlabel_setnumdouble(QLabel * label, double num) {
	label->setNum(num);
}

void bmx_qt_qlabel_settext(QLabel * label, BBString * text) {
	label->setText(qStringFromBBString(text));
}

MaxQPixmap * bmx_qt_qlabel_pixmap(QLabel * label) {
	return new MaxQPixmap(*label->pixmap());
}

void bmx_qt_qlabel_setpixmap(QLabel * label, MaxQPixmap * pixmap) {
	label->setPixmap(pixmap->Pixmap());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

