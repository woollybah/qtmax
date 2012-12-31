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



// ****************** DEFAULT HANDLERS ********************

// QLabel
// QFrame
// QWidget
void MaxQLabel::defaultactionEvent(QActionEvent * event){
	QLabel::actionEvent(event);
}

void MaxQLabel::defaultchangeEvent(QEvent * event){
	QLabel::changeEvent(event);
}

void MaxQLabel::defaultcloseEvent(QCloseEvent * event){
	QLabel::closeEvent(event);
}

void MaxQLabel::defaultcontextMenuEvent(QContextMenuEvent * event){
	QLabel::contextMenuEvent(event);
}

void MaxQLabel::defaultdragEnterEvent(QDragEnterEvent * event){
	QLabel::dragEnterEvent(event);
}

void MaxQLabel::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QLabel::dragLeaveEvent(event);
}

void MaxQLabel::defaultdragMoveEvent(QDragMoveEvent * event){
	QLabel::dragMoveEvent(event);
}

void MaxQLabel::defaultdropEvent(QDropEvent * event){
	QLabel::dropEvent(event);
}

void MaxQLabel::defaultenterEvent(QEvent * event){
	QLabel::enterEvent(event);
}

void MaxQLabel::defaultfocusInEvent(QFocusEvent * event){
	QLabel::focusInEvent(event);
}

bool MaxQLabel::defaultfocusNextChild() {
	return QLabel::focusNextChild();
}

bool MaxQLabel::defaultfocusNextPrevChild(bool next){
	return QLabel::focusNextPrevChild(next);
}

void MaxQLabel::defaultfocusOutEvent(QFocusEvent * event){
	QLabel::focusOutEvent(event);
}

bool MaxQLabel::defaultfocusPreviousChild() {
	return QLabel::focusPreviousChild();
}

void MaxQLabel::defaulthideEvent(QHideEvent * event){
	QLabel::hideEvent(event);
}

void MaxQLabel::defaultinputMethodEvent(QInputMethodEvent * event){
	QLabel::inputMethodEvent(event);
}

void MaxQLabel::defaultkeyPressEvent(QKeyEvent * event){
	QLabel::keyPressEvent(event);
}

void MaxQLabel::defaultkeyReleaseEvent(QKeyEvent * event){
	QLabel::keyReleaseEvent(event);
}

void MaxQLabel::defaultleaveEvent(QEvent * event){
	QLabel::leaveEvent(event);
}

void MaxQLabel::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QLabel::mouseDoubleClickEvent(event);
}

void MaxQLabel::defaultmouseMoveEvent(QMouseEvent * event){
	QLabel::mouseMoveEvent(event);
}

void MaxQLabel::defaultmousePressEvent(QMouseEvent * event){
	QLabel::mousePressEvent(event);
}

void MaxQLabel::defaultmouseReleaseEvent(QMouseEvent * event){
	QLabel::mouseReleaseEvent(event);
}

void MaxQLabel::defaultmoveEvent(QMoveEvent * event){
	QLabel::moveEvent(event);
}

void MaxQLabel::defaultpaintEvent(QPaintEvent * event){
	QLabel::paintEvent(event);
}

void MaxQLabel::defaultresizeEvent(QResizeEvent * event){
	QLabel::resizeEvent(event);
}

void MaxQLabel::defaultshowEvent(QShowEvent * event){
	QLabel::showEvent(event);
}

void MaxQLabel::defaulttabletEvent(QTabletEvent * event){
	QLabel::tabletEvent(event);
}

void MaxQLabel::defaultwheelEvent(QWheelEvent * event){
	QLabel::wheelEvent(event);
}

// QObject
bool MaxQLabel::defaultevent(QEvent * event){
	return QLabel::event(event);
}

void MaxQLabel::defaulttimerEvent(QTimerEvent * event){
	QLabel::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QLabel
// QFrame
// QWidget
void MaxQLabel::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQLabel::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQLabel::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQLabel::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQLabel::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQLabel::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQLabel::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQLabel::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQLabel::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQLabel::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQLabel::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQLabel::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQLabel::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQLabel::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQLabel::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQLabel::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQLabel::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQLabel::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQLabel::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQLabel::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQLabel::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQLabel::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQLabel::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQLabel::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQLabel::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQLabel::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQLabel::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQLabel::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQLabel::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQLabel::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQLabel::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QLabel
// QFrame
// QWidget
void bmx_qt_qlabel_default_actionevent(MaxQLabel * label, QActionEvent * event) {
	label->defaultactionEvent(event);
}

void bmx_qt_qlabel_default_changeevent(MaxQLabel * label, QEvent * event) {
	label->defaultchangeEvent(event);
}

void bmx_qt_qlabel_default_closeevent(MaxQLabel * label, QCloseEvent * event) {
	label->defaultcloseEvent(event);
}

void bmx_qt_qlabel_default_contextmenuevent(MaxQLabel * label, QContextMenuEvent * event) {
	label->defaultcontextMenuEvent(event);
}

void bmx_qt_qlabel_default_dragenterevent(MaxQLabel * label, QDragEnterEvent * event) {
	label->defaultdragEnterEvent(event);
}

void bmx_qt_qlabel_default_dragleaveevent(MaxQLabel * label, QDragLeaveEvent * event) {
	label->defaultdragLeaveEvent(event);
}

void bmx_qt_qlabel_default_dragmoveevent(MaxQLabel * label, QDragMoveEvent * event) {
	label->defaultdragMoveEvent(event);
}

void bmx_qt_qlabel_default_dropevent(MaxQLabel * label, QDropEvent * event) {
	label->defaultdropEvent(event);
}

void bmx_qt_qlabel_default_enterevent(MaxQLabel * label, QEvent * event) {
	label->defaultenterEvent(event);
}

void bmx_qt_qlabel_default_focusinevent(MaxQLabel * label, QFocusEvent * event) {
	label->defaultfocusInEvent(event);
}

int bmx_qt_qlabel_default_focusnextprevchild(MaxQLabel * label, int next) {
	return static_cast<int>(label->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qlabel_default_focusnextchild(MaxQLabel * label) {
	return static_cast<int>(label->defaultfocusNextChild());
}

void bmx_qt_qlabel_default_focusoutevent(MaxQLabel * label, QFocusEvent * event) {
	label->defaultfocusOutEvent(event);
}

int bmx_qt_qlabel_default_focuspreviouschild(MaxQLabel * label) {
	return static_cast<int>(label->defaultfocusPreviousChild());
}

void bmx_qt_qlabel_default_hideevent(MaxQLabel * label, QHideEvent * event) {
	label->defaulthideEvent(event);
}

void bmx_qt_qlabel_default_inputmethodevent(MaxQLabel * label, QInputMethodEvent * event) {
	label->defaultinputMethodEvent(event);
}

void bmx_qt_qlabel_default_keypressevent(MaxQLabel * label, QKeyEvent * event) {
	label->defaultkeyPressEvent(event);
}

void bmx_qt_qlabel_default_keyreleaseevent(MaxQLabel * label, QKeyEvent * event) {
	label->defaultkeyReleaseEvent(event);
}

void bmx_qt_qlabel_default_leaveevent(MaxQLabel * label, QEvent * event) {
	label->defaultleaveEvent(event);
}

void bmx_qt_qlabel_default_mousedoubleclickevent(MaxQLabel * label, QMouseEvent * event) {
	label->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qlabel_default_mousemoveevent(MaxQLabel * label, QMouseEvent * event) {
	label->defaultmouseMoveEvent(event);
}

void bmx_qt_qlabel_default_mousepressevent(MaxQLabel * label, QMouseEvent * event) {
	label->defaultmousePressEvent(event);
}

void bmx_qt_qlabel_default_mousereleaseevent(MaxQLabel * label, QMouseEvent * event) {
	label->defaultmouseReleaseEvent(event);
}

void bmx_qt_qlabel_default_moveevent(MaxQLabel * label, QMoveEvent * event) {
	label->defaultmoveEvent(event);
}

void bmx_qt_qlabel_default_paintevent(MaxQLabel * label, QPaintEvent * event) {
	label->defaultpaintEvent(event);
}

void bmx_qt_qlabel_default_resizeevent(MaxQLabel * label, QResizeEvent * event) {
	label->defaultresizeEvent(event);
}

void bmx_qt_qlabel_default_showevent(MaxQLabel * label, QShowEvent * event) {
	label->defaultshowEvent(event);
}

void bmx_qt_qlabel_default_tabletevent(MaxQLabel * label, QTabletEvent * event) {
	label->defaulttabletEvent(event);
}

void bmx_qt_qlabel_default_wheelevent(MaxQLabel * label, QWheelEvent * event) {
	label->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qlabel_default_event(MaxQLabel * label, QEvent * event) {
	return static_cast<int>(label->defaultevent(event));
}

void bmx_qt_qlabel_default_timerevent(MaxQLabel * label, QTimerEvent * event) {
	label->defaulttimerEvent(event);
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

