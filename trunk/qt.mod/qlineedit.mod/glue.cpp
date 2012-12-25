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

void MaxQLineEdit::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

void MaxQLineEdit::changeEvent(QEvent * ev) {
	_qt_qwidget_QWidget__OnChangeEvent(maxHandle, ev);
}

void MaxQLineEdit::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__OnContextMenuEvent(maxHandle, event);
}

void MaxQLineEdit::dragEnterEvent(QDragEnterEvent * e) {
	_qt_qwidget_QWidget__OnDragEnterEvent(maxHandle, e);
}

void MaxQLineEdit::dragLeaveEvent(QDragLeaveEvent * e) {
	_qt_qwidget_QWidget__OnDragLeaveEvent(maxHandle, e);
}

void MaxQLineEdit::dragMoveEvent(QDragMoveEvent * e) {
	_qt_qwidget_QWidget__OnDragMoveEvent(maxHandle, e);
}

void MaxQLineEdit::dropEvent(QDropEvent * e) {
	_qt_qwidget_QWidget__OnDropEvent(maxHandle, e);
}

void MaxQLineEdit::focusInEvent(QFocusEvent * e) {
	_qt_qwidget_QWidget__OnFocusInEvent(maxHandle, e);
}

void MaxQLineEdit::focusOutEvent(QFocusEvent * e) {
	_qt_qwidget_QWidget__OnFocusOutEvent(maxHandle, e);
}

void MaxQLineEdit::inputMethodEvent(QInputMethodEvent * e) {
	_qt_qwidget_QWidget__OnInputMethodEvent(maxHandle, e);
}

void MaxQLineEdit::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__OnKeyPressEvent(maxHandle, event);
}

void MaxQLineEdit::mouseDoubleClickEvent(QMouseEvent * e) {
	_qt_qwidget_QWidget__OnMouseDoubleClickEvent(maxHandle, e);
}

void MaxQLineEdit::mouseMoveEvent(QMouseEvent * e) {
	_qt_qwidget_QWidget__OnMouseMoveEvent(maxHandle, e);
}

void MaxQLineEdit::mousePressEvent(QMouseEvent * e) {
	_qt_qwidget_QWidget__OnMousePressEvent(maxHandle, e);
}

void MaxQLineEdit::mouseReleaseEvent(QMouseEvent * e) {
	_qt_qwidget_QWidget__OnMouseReleaseEvent(maxHandle, e);
}

void MaxQLineEdit::paintEvent(QPaintEvent * e) {
	_qt_qwidget_QWidget__OnPaintEvent(maxHandle, e);
}

void MaxQLineEdit::defaultChangeEvent(QEvent * event) {
	QLineEdit::changeEvent(event);
}

void MaxQLineEdit::defaultContextMenuEvent(QContextMenuEvent * event) {
	QLineEdit::contextMenuEvent(event);
}

void MaxQLineEdit::defaultDragEnterEvent(QDragEnterEvent * event) {
	QLineEdit::dragEnterEvent(event);
}

void MaxQLineEdit::defaultDragLeaveEvent(QDragLeaveEvent * event) {
	QLineEdit::dragLeaveEvent(event);
}

void MaxQLineEdit::defaultDragMoveEvent(QDragMoveEvent * event) {
	QLineEdit::dragMoveEvent(event);
}

void MaxQLineEdit::defaultDropEvent(QDropEvent * event) {
	QLineEdit::dropEvent(event);
}

void MaxQLineEdit::defaultFocusInEvent(QFocusEvent * event) {
	QLineEdit::focusInEvent(event);
}

void MaxQLineEdit::defaultFocusOutEvent(QFocusEvent * event) {
	QLineEdit::focusOutEvent(event);
}

void MaxQLineEdit::defaultInputMethodEvent(QInputMethodEvent * event) {
	QLineEdit::inputMethodEvent(event);
}

void MaxQLineEdit::defaultKeyPressEvent(QKeyEvent * event) {
	QLineEdit::keyPressEvent(event);
}

void MaxQLineEdit::defaultKeyReleaseEvent(QKeyEvent * event) {
	QLineEdit::keyReleaseEvent(event);
}

void MaxQLineEdit::defaultPaintEvent(QPaintEvent * event) {
	QLineEdit::paintEvent(event);
}

void MaxQLineEdit::defaultMouseDoubleClickEvent(QMouseEvent * event) {
	QLineEdit::mouseDoubleClickEvent(event);
}

void MaxQLineEdit::defaultMouseMoveEvent(QMouseEvent * event) {
	QLineEdit::mouseMoveEvent(event);
}

void MaxQLineEdit::defaultMousePressEvent(QMouseEvent * event) {
	QLineEdit::mousePressEvent(event);
}

void MaxQLineEdit::defaultMouseReleaseEvent(QMouseEvent * event) {
	QLineEdit::mouseReleaseEvent(event);
}

// *********************************************

void bmx_qt_qlineedit_default_mousedoubleclickevent(MaxQLineEdit * edit, QMouseEvent * event) {
	edit->defaultMouseDoubleClickEvent(event);
}

void bmx_qt_qlineedit_default_mousemoveevent(MaxQLineEdit * edit, QMouseEvent * event) {
	edit->defaultMouseMoveEvent(event);
}

void bmx_qt_qlineedit_default_mousepressevent(MaxQLineEdit * edit, QMouseEvent * event) {
	edit->defaultMousePressEvent(event);
}

void bmx_qt_qlineedit_default_mousereleaseevent(MaxQLineEdit * edit, QMouseEvent * event) {
	edit->defaultMouseReleaseEvent(event);
}

void bmx_qt_qlineedit_default_changeevent(MaxQLineEdit * edit, QEvent * event) {
	edit->defaultChangeEvent(event);
}

void bmx_qt_qlineedit_default_contextmenuevent(MaxQLineEdit * edit, QContextMenuEvent * event) {
	edit->defaultContextMenuEvent(event);
}

void bmx_qt_qlineedit_default_dragenterevent(MaxQLineEdit * edit, QDragEnterEvent * event) {
	edit->defaultDragEnterEvent(event);
}

void bmx_qt_qlineedit_default_dragleaveevent(MaxQLineEdit * edit, QDragLeaveEvent * event) {
	edit->defaultDragLeaveEvent(event);
}

void bmx_qt_qlineedit_default_dragmoveevent(MaxQLineEdit * edit, QDragMoveEvent * event) {
	edit->defaultDragMoveEvent(event);
}

void bmx_qt_qlineedit_default_dropevent(MaxQLineEdit * edit, QDropEvent * event) {
	edit->defaultDropEvent(event);
}

void bmx_qt_qlineedit_default_focusinevent(MaxQLineEdit * edit, QFocusEvent * event) {
	edit->defaultFocusInEvent(event);
}

void bmx_qt_qlineedit_default_focusoutevent(MaxQLineEdit * edit, QFocusEvent * event) {
	edit->defaultFocusOutEvent(event);
}

void bmx_qt_qlineedit_default_inputmethodevent(MaxQLineEdit * edit, QInputMethodEvent * event) {
	edit->defaultInputMethodEvent(event);
}

void bmx_qt_qlineedit_default_keypressevent(MaxQLineEdit * edit, QKeyEvent * event) {
	edit->defaultKeyPressEvent(event);
}

void bmx_qt_qlineedit_default_keyreleaseevent(MaxQLineEdit * edit, QKeyEvent * event) {
	edit->defaultKeyReleaseEvent(event);
}

void bmx_qt_qlineedit_default_paintevent(MaxQLineEdit * edit, QPaintEvent * event) {
	edit->defaultPaintEvent(event);
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
