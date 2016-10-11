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

MaxQLineEdit::MaxQLineEdit(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QLineEdit(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(cursorPositionChanged(int, int)), SLOT(onCursorPositionChanged(int, int)));
	connect(this, SIGNAL(editingFinished()), SLOT(onEditingFinished()));
	connect(this, SIGNAL(returnPressed()), SLOT(onReturnPressed()));
	connect(this, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()));
	connect(this, SIGNAL(textChanged(const QString & )), SLOT(onTextChanged(const QString & )));
	connect(this, SIGNAL(textEdited(const QString & )), SLOT(onTextEdited(const QString & )));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint & )), SLOT(onCustomContextMenuRequested(const QPoint & )));
}

MaxQLineEdit::~MaxQLineEdit()
{
	qunbind(this);
}

void MaxQLineEdit::onCursorPositionChanged(int oldPos, int newPos) {
	_qt_qlineedit_QLineEdit__OnCursorPositionChanged(maxHandle, oldPos, newPos);
}

void MaxQLineEdit::onEditingFinished() {
	_qt_qlineedit_QLineEdit__OnEditingFinished(maxHandle);
}

void MaxQLineEdit::onReturnPressed() {
	_qt_qlineedit_QLineEdit__OnReturnPressed(maxHandle);
}

void MaxQLineEdit::onSelectionChanged() {
	_qt_qlineedit_QLineEdit__OnSelectionChanged(maxHandle);
}

void MaxQLineEdit::onTextChanged(const QString & text) {
	_qt_qlineedit_QLineEdit__OnTextChanged(maxHandle, bbStringFromQString(text));
}

void MaxQLineEdit::onTextEdited(const QString & text) {
	_qt_qlineedit_QLineEdit__OnTextEdited(maxHandle, bbStringFromQString(text));
}

void MaxQLineEdit::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

// ****************** DEFAULT HANDLERS ********************

// QLineEdit
// QWidget
void MaxQLineEdit::defaultactionEvent(QActionEvent * event){
	QLineEdit::actionEvent(event);
}

void MaxQLineEdit::defaultchangeEvent(QEvent * event){
	QLineEdit::changeEvent(event);
}

void MaxQLineEdit::defaultcloseEvent(QCloseEvent * event){
	QLineEdit::closeEvent(event);
}

void MaxQLineEdit::defaultcontextMenuEvent(QContextMenuEvent * event){
	QLineEdit::contextMenuEvent(event);
}

void MaxQLineEdit::defaultdragEnterEvent(QDragEnterEvent * event){
	QLineEdit::dragEnterEvent(event);
}

void MaxQLineEdit::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QLineEdit::dragLeaveEvent(event);
}

void MaxQLineEdit::defaultdragMoveEvent(QDragMoveEvent * event){
	QLineEdit::dragMoveEvent(event);
}

void MaxQLineEdit::defaultdropEvent(QDropEvent * event){
	QLineEdit::dropEvent(event);
}

void MaxQLineEdit::defaultenterEvent(QEvent * event){
	QLineEdit::enterEvent(event);
}

void MaxQLineEdit::defaultfocusInEvent(QFocusEvent * event){
	QLineEdit::focusInEvent(event);
}

bool MaxQLineEdit::defaultfocusNextChild() {
	return QLineEdit::focusNextChild();
}

bool MaxQLineEdit::defaultfocusNextPrevChild(bool next){
	return QLineEdit::focusNextPrevChild(next);
}

void MaxQLineEdit::defaultfocusOutEvent(QFocusEvent * event){
	QLineEdit::focusOutEvent(event);
}

bool MaxQLineEdit::defaultfocusPreviousChild() {
	return QLineEdit::focusPreviousChild();
}

void MaxQLineEdit::defaulthideEvent(QHideEvent * event){
	QLineEdit::hideEvent(event);
}

void MaxQLineEdit::defaultinputMethodEvent(QInputMethodEvent * event){
	QLineEdit::inputMethodEvent(event);
}

void MaxQLineEdit::defaultkeyPressEvent(QKeyEvent * event){
	QLineEdit::keyPressEvent(event);
}

void MaxQLineEdit::defaultkeyReleaseEvent(QKeyEvent * event){
	QLineEdit::keyReleaseEvent(event);
}

void MaxQLineEdit::defaultleaveEvent(QEvent * event){
	QLineEdit::leaveEvent(event);
}

void MaxQLineEdit::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QLineEdit::mouseDoubleClickEvent(event);
}

void MaxQLineEdit::defaultmouseMoveEvent(QMouseEvent * event){
	QLineEdit::mouseMoveEvent(event);
}

void MaxQLineEdit::defaultmousePressEvent(QMouseEvent * event){
	QLineEdit::mousePressEvent(event);
}

void MaxQLineEdit::defaultmouseReleaseEvent(QMouseEvent * event){
	QLineEdit::mouseReleaseEvent(event);
}

void MaxQLineEdit::defaultmoveEvent(QMoveEvent * event){
	QLineEdit::moveEvent(event);
}

void MaxQLineEdit::defaultpaintEvent(QPaintEvent * event){
	QLineEdit::paintEvent(event);
}

void MaxQLineEdit::defaultresizeEvent(QResizeEvent * event){
	QLineEdit::resizeEvent(event);
}

void MaxQLineEdit::defaultshowEvent(QShowEvent * event){
	QLineEdit::showEvent(event);
}

void MaxQLineEdit::defaulttabletEvent(QTabletEvent * event){
	QLineEdit::tabletEvent(event);
}

void MaxQLineEdit::defaultwheelEvent(QWheelEvent * event){
	QLineEdit::wheelEvent(event);
}

// QObject
bool MaxQLineEdit::defaultevent(QEvent * event){
	return QLineEdit::event(event);
}

void MaxQLineEdit::defaulttimerEvent(QTimerEvent * event){
	QLineEdit::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QLineEdit
// QWidget
void MaxQLineEdit::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQLineEdit::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQLineEdit::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQLineEdit::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQLineEdit::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQLineEdit::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQLineEdit::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQLineEdit::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQLineEdit::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQLineEdit::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQLineEdit::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQLineEdit::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQLineEdit::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQLineEdit::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQLineEdit::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQLineEdit::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQLineEdit::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQLineEdit::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQLineEdit::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQLineEdit::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQLineEdit::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQLineEdit::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQLineEdit::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQLineEdit::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQLineEdit::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQLineEdit::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQLineEdit::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQLineEdit::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQLineEdit::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQLineEdit::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQLineEdit::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QLineEdit
// QWidget
void bmx_qt_qlineedit_default_actionevent(MaxQLineEdit * edit, QActionEvent * event) {
	edit->defaultactionEvent(event);
}

void bmx_qt_qlineedit_default_changeevent(MaxQLineEdit * edit, QEvent * event) {
	edit->defaultchangeEvent(event);
}

void bmx_qt_qlineedit_default_closeevent(MaxQLineEdit * edit, QCloseEvent * event) {
	edit->defaultcloseEvent(event);
}

void bmx_qt_qlineedit_default_contextmenuevent(MaxQLineEdit * edit, QContextMenuEvent * event) {
	edit->defaultcontextMenuEvent(event);
}

void bmx_qt_qlineedit_default_dragenterevent(MaxQLineEdit * edit, QDragEnterEvent * event) {
	edit->defaultdragEnterEvent(event);
}

void bmx_qt_qlineedit_default_dragleaveevent(MaxQLineEdit * edit, QDragLeaveEvent * event) {
	edit->defaultdragLeaveEvent(event);
}

void bmx_qt_qlineedit_default_dragmoveevent(MaxQLineEdit * edit, QDragMoveEvent * event) {
	edit->defaultdragMoveEvent(event);
}

void bmx_qt_qlineedit_default_dropevent(MaxQLineEdit * edit, QDropEvent * event) {
	edit->defaultdropEvent(event);
}

void bmx_qt_qlineedit_default_enterevent(MaxQLineEdit * edit, QEvent * event) {
	edit->defaultenterEvent(event);
}

void bmx_qt_qlineedit_default_focusinevent(MaxQLineEdit * edit, QFocusEvent * event) {
	edit->defaultfocusInEvent(event);
}

int bmx_qt_qlineedit_default_focusnextprevchild(MaxQLineEdit * edit, int next) {
	return static_cast<int>(edit->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qlineedit_default_focusnextchild(MaxQLineEdit * edit) {
	return static_cast<int>(edit->defaultfocusNextChild());
}

void bmx_qt_qlineedit_default_focusoutevent(MaxQLineEdit * edit, QFocusEvent * event) {
	edit->defaultfocusOutEvent(event);
}

int bmx_qt_qlineedit_default_focuspreviouschild(MaxQLineEdit * edit) {
	return static_cast<int>(edit->defaultfocusPreviousChild());
}

void bmx_qt_qlineedit_default_hideevent(MaxQLineEdit * edit, QHideEvent * event) {
	edit->defaulthideEvent(event);
}

void bmx_qt_qlineedit_default_inputmethodevent(MaxQLineEdit * edit, QInputMethodEvent * event) {
	edit->defaultinputMethodEvent(event);
}

void bmx_qt_qlineedit_default_keypressevent(MaxQLineEdit * edit, QKeyEvent * event) {
	edit->defaultkeyPressEvent(event);
}

void bmx_qt_qlineedit_default_keyreleaseevent(MaxQLineEdit * edit, QKeyEvent * event) {
	edit->defaultkeyReleaseEvent(event);
}

void bmx_qt_qlineedit_default_leaveevent(MaxQLineEdit * edit, QEvent * event) {
	edit->defaultleaveEvent(event);
}

void bmx_qt_qlineedit_default_mousedoubleclickevent(MaxQLineEdit * edit, QMouseEvent * event) {
	edit->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qlineedit_default_mousemoveevent(MaxQLineEdit * edit, QMouseEvent * event) {
	edit->defaultmouseMoveEvent(event);
}

void bmx_qt_qlineedit_default_mousepressevent(MaxQLineEdit * edit, QMouseEvent * event) {
	edit->defaultmousePressEvent(event);
}

void bmx_qt_qlineedit_default_mousereleaseevent(MaxQLineEdit * edit, QMouseEvent * event) {
	edit->defaultmouseReleaseEvent(event);
}

void bmx_qt_qlineedit_default_moveevent(MaxQLineEdit * edit, QMoveEvent * event) {
	edit->defaultmoveEvent(event);
}

void bmx_qt_qlineedit_default_paintevent(MaxQLineEdit * edit, QPaintEvent * event) {
	edit->defaultpaintEvent(event);
}

void bmx_qt_qlineedit_default_resizeevent(MaxQLineEdit * edit, QResizeEvent * event) {
	edit->defaultresizeEvent(event);
}

void bmx_qt_qlineedit_default_showevent(MaxQLineEdit * edit, QShowEvent * event) {
	edit->defaultshowEvent(event);
}

void bmx_qt_qlineedit_default_tabletevent(MaxQLineEdit * edit, QTabletEvent * event) {
	edit->defaulttabletEvent(event);
}

void bmx_qt_qlineedit_default_wheelevent(MaxQLineEdit * edit, QWheelEvent * event) {
	edit->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qlineedit_default_event(MaxQLineEdit * edit, QEvent * event) {
	return static_cast<int>(edit->defaultevent(event));
}

void bmx_qt_qlineedit_default_timerevent(MaxQLineEdit * edit, QTimerEvent * event) {
	edit->defaulttimerEvent(event);
}

// *********************************************

QLineEdit * bmx_qt_qlineedit_create(BBObject * handle, QWidget * parent) {
	return new MaxQLineEdit(handle, parent);
}

void bmx_qt_qlineedit_setreadonly(QLineEdit * edit, int value) {
	edit->setReadOnly(static_cast<bool>(value));
}

void bmx_qt_qlineedit_clear(QLineEdit * edit) {
	edit->clear();
}


void bmx_qt_qlineedit_copy(QLineEdit * edit) {
	edit->copy();
}


void bmx_qt_qlineedit_cut(QLineEdit * edit) {
	edit->cut();
}


void bmx_qt_qlineedit_paste(QLineEdit * edit) {
	edit->paste();
}


void bmx_qt_qlineedit_redo(QLineEdit * edit) {
	edit->redo();
}


void bmx_qt_qlineedit_selectall(QLineEdit * edit) {
	edit->selectAll();
}


void bmx_qt_qlineedit_settext(QLineEdit * edit, BBString * text) {
	edit->setText(qStringFromBBString(text));
}


void bmx_qt_qlineedit_undo(QLineEdit * edit) {
	edit->undo();
}

BBString * bmx_qt_qlineedit_text(QLineEdit * edit) {
	return bbStringFromQString(edit->text());
}

int bmx_qt_qlineedit_alignment(QLineEdit * edit) {
	return edit->alignment();
}


void bmx_qt_qlineedit_backspace(QLineEdit * edit) {
	edit->backspace();
}


void bmx_qt_qlineedit_cursorbackward(QLineEdit * edit, int mark, int steps) {
	edit->cursorBackward(static_cast<bool>(mark), steps);
}


void bmx_qt_qlineedit_cursorforward(QLineEdit * edit, int mark, int steps) {
	edit->cursorForward(static_cast<bool>(mark), steps);
}


int bmx_qt_qlineedit_cursorposition(QLineEdit * edit) {
	return edit->cursorPosition();
}


int bmx_qt_qlineedit_cursorpositionat(QLineEdit * edit, int x, int y) {
	return edit->cursorPositionAt(QPoint(x, y));
}


void bmx_qt_qlineedit_cursorwordbackward(QLineEdit * edit, int mark) {
	edit->cursorWordBackward(static_cast<bool>(mark));
}


void bmx_qt_qlineedit_cursorwordforward(QLineEdit * edit, int mark) {
	edit->cursorWordForward(static_cast<bool>(mark));
}


void bmx_qt_qlineedit_del(QLineEdit * edit) {
	edit->del();
}


void bmx_qt_qlineedit_deselect(QLineEdit * edit) {
	edit->deselect();
}


BBString *  bmx_qt_qlineedit_displaytext(QLineEdit * edit) {
	return bbStringFromQString(edit->displayText());
}


int bmx_qt_qlineedit_dragenabled(QLineEdit * edit) {
	return static_cast<int>(edit->dragEnabled());
}


int bmx_qt_qlineedit_echomode(QLineEdit * edit) {
	return edit->echoMode();
}


void bmx_qt_qlineedit_toend(QLineEdit * edit, int mark) {
	edit->end(static_cast<bool>(mark));
}


void bmx_qt_qlineedit_gettextmargins(QLineEdit * edit, int * _left, int * _top, int * _right, int * _bottom) {
	edit->getTextMargins(_left, _top, _right, _bottom);
}


int bmx_qt_qlineedit_hasacceptableinput(QLineEdit * edit) {
	return static_cast<int>(edit->hasAcceptableInput());
}


int bmx_qt_qlineedit_hasframe(QLineEdit * edit) {
	return static_cast<int>(edit->hasFrame());
}


int bmx_qt_qlineedit_hasselectedtext(QLineEdit * edit) {
	return static_cast<int>(edit->hasSelectedText());
}


void bmx_qt_qlineedit_home(QLineEdit * edit, int mark) {
	edit->home(static_cast<bool>(mark));
}


BBString * bmx_qt_qlineedit_inputmask(QLineEdit * edit) {
	return bbStringFromQString(edit->inputMask());
}


void bmx_qt_qlineedit_insert(QLineEdit * edit, BBString * newText) {
	edit->insert(qStringFromBBString(newText));
}


int bmx_qt_qlineedit_ismodified(QLineEdit * edit) {
	return static_cast<int>(edit->isModified());
}


int bmx_qt_qlineedit_isreadonly(QLineEdit * edit) {
	return static_cast<int>(edit->isReadOnly());
}


int bmx_qt_qlineedit_isredoavailable(QLineEdit * edit) {
	return static_cast<int>(edit->isRedoAvailable());
}


int bmx_qt_qlineedit_isundoavailable(QLineEdit * edit) {
	return static_cast<int>(edit->isUndoAvailable());
}


int bmx_qt_qlineedit_maxlength(QLineEdit * edit) {
	return edit->maxLength();
}


void bmx_qt_qlineedit_minimumsizehint(QLineEdit * edit, int * w, int * h) {
	QSize s(edit->minimumSizeHint());
	*w = s.width();
	*h = s.height();
}


BBString * bmx_qt_qlineedit_selectedtext(QLineEdit * edit) {
	return bbStringFromQString(edit->selectedText());
}


int bmx_qt_qlineedit_selectionstar(QLineEdit * edit) {
	return edit->selectionStart();
}


void bmx_qt_qlineedit_setalignment(QLineEdit * edit, int flag) {
	edit->setAlignment(bmx_qt_getalignment(flag));
}


void bmx_qt_qlineedit_setcursorposition(QLineEdit * edit, int pos) {
	edit->setCursorPosition(pos);
}


void bmx_qt_qlineedit_setdragenabled(QLineEdit * edit, int b) {
	edit->setDragEnabled(static_cast<bool>(b));
}


void bmx_qt_qlineedit_setechomode(QLineEdit * edit, int mode) {
	QLineEdit::EchoMode m;
	
	switch(mode) {
		case 0:
			m = QLineEdit::Normal;
			break;
		case 1:
			m = QLineEdit::NoEcho;
			break;
		case 2:
			m = QLineEdit::Password;
			break;
		case 3:
			m = QLineEdit::PasswordEchoOnEdit;
			break;
		default:
			m = QLineEdit::Normal;
	}
	
	edit->setEchoMode(m);
}


void bmx_qt_qlineedit_setframe(QLineEdit * edit, int frame) {
	edit->setFrame(static_cast<bool>(frame));
}


void bmx_qt_qlineedit_setinputmask(QLineEdit * edit, BBString * inputMask) {
	edit->setInputMask(qStringFromBBString(inputMask));
}


void bmx_qt_qlineedit_setmaxlength(QLineEdit * edit, int length) {
	edit->setMaxLength(length);
}


void bmx_qt_qlineedit_setmodified(QLineEdit * edit, int value) {
	edit->setModified(static_cast<bool>(value));
}


void bmx_qt_qlineedit_setselection(QLineEdit * edit, int start, int length) {
	edit->setSelection(start, length);
}


void bmx_qt_qlineedit_settextmargins(QLineEdit * edit, int _left, int _top, int _right, int _bottom) {
	edit->setTextMargins(_left, _top, _right, _bottom);
}


void bmx_qt_qlineedit_sizehint(QLineEdit * edit, int * w, int * h) {
	QSize s(edit->sizeHint());
	*w = s.width();
	*h = s.height();
}

void bmx_qt_qlineedit_setvalidator(QLineEdit * edit, QValidator * v) {
	edit->setValidator(v);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
